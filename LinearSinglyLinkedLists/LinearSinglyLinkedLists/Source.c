#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <locale.h> 
#include <stdlib.h>

struct LinearList
{
	char* id; //определитель
	struct LinearList* next;
};
typedef struct LinearList L;

/// <summary>
/// —оздание списка
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
L* Create(int size)
{
	L* start = malloc(sizeof(L)); //голова, первый элемент
	start->id = "Ёлемент0";
	start->next = NULL;
	//указатели на прошлый и следующий элемент, с их помощью измен€ем значени€
	L* previousEl, *nextEl;
	previousEl = start;
	for (int i = 0; i < size - 1; i++)
	{
		printf("¬ведите %d элемент: ", i+1);
		char* name = malloc(sizeof(char));
		gets(name);
		nextEl = malloc(sizeof(L));
		nextEl->id = name;
		previousEl->next = nextEl;
		previousEl = nextEl;
	}
	previousEl->next = NULL; //конец списка
	return start;
}

/// <summary>
/// ¬ыводит Ћќ—
/// </summary>
/// <param name="list"></param>
void Show(L* list)
{
	printf("Ћист: ");
	L* nextEl = list;
	while (nextEl)
	{
		printf("%s ", nextEl->id);
		nextEl = nextEl->next;
	}
	printf("\n\n");
}

/// <summary>
/// ¬ставка элемента внутрь списка
/// </summary>
/// <param name="list"></param>
/// <param name="item"></param>
/// <param name="index"></param>
/// <returns></returns>
L* Insert(L* list, L item, int index)
{
	L* start = list; //запоминаем голову списка
	if (index == 0) //начало списка
	{
		L* newItem = malloc(sizeof(L));
		int N = item.id;
		newItem->id = realloc(newItem->id, N * sizeof(char));
		newItem->id = item.id;
		newItem->next = start;
		start = newItem;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			list = list->next;
			if (!(list->next))
			{
				printf("»ндекс превышает размеры списка. Ёлемент вставлен в конец.\n");
				break;
			}
		}
		L* newItem = malloc(sizeof(L));
		int N = item.id;
		newItem->id = realloc(newItem->id, N * sizeof(char));
		newItem->id = item.id;
		newItem->next = list->next;
		list->next = newItem;
		list = list->next;
	}	
	return start;
}

/// <summary>
/// ”даление элемента списка по индексу
/// </summary>
/// <param name="list"></param>
/// <param name="indexItem"></param>
/// <returns></returns>
L* DeleteItem(L* list, int indexItem)
{
	L* start = list; //запоминаем голову списка
	if (indexItem == 0) //начало списка
	{
		L* deletedItem = start;
		start = start->next;
		free(deletedItem);
	}
	else
	{
		for (int i = 0; i < indexItem - 1; i++)
		{
			list = list->next;
			if (!(list->next))
			{
				printf("»ндекс превышает размеры списка. Ёлементы не были удалены.\n");
				return start;
			}
		}
		L* deletedItem = list->next;
		list->next = list->next->next;
		free(deletedItem); //очищение пам€ти
	}
	return start;
}

L* SwapItem(L* list, int indexItem1, int indexItem2)
{
	int index1 = min(indexItem1, indexItem2);
	int index2 = max(indexItem1, indexItem2);
	L* start = list; //запоминаем голову списка
	if (index1 == 0) //начало списка
	{
		L* element1 = list;
		L* nextEl1 = list->next;
		int i = 0;
		while (i < index2 - 1)
		{
			list = list->next;
			if (!(list->next))
			{
				printf("»ндекс превышает размеры списка. Ёлементы не были заменены.\n");
				return start;
			}
			i++;
		}
		L* previousEl2 = list;
		L* element2 = list->next;
		L* nextEl2 = element2->next;
		//замена
		element1->next = nextEl2;
		if (nextEl1 == element2)  //проверка, если элементы сто€т р€дом
		{
			element2->next = element1;
		}
		else
		{
			previousEl2->next = element1;
			element2->next = nextEl1;
		}
		start = element2;
	}
	else
	{
		int i = 0;
		while (i < index1 - 1)
		{
			list = list->next;
			if (!(list->next))
			{
				printf("»ндекс превышает размеры списка. Ёлементы не были заменены.\n");
				return start;
			}
			i++;
		}
		L* previousEl1 = list;
		L* element1 = list->next;
		L* nextEl1 = element1->next;
		while (i < index2 - 1)
		{
			list = list->next;
			if (!(list->next))
			{
				printf("»ндекс превышает размеры списка. Ёлементы не были заменены.\n");
				return start;
			}
			i++;
		}
		L* previousEl2 = list;
		L* element2 = list->next;
		L* nextEl2 = element2->next;
		//замена
		previousEl1->next = element2;
		if (nextEl1 == element2) //проверка, если элементы сто€т р€дом
		{
			element2->next = element1;
		}
		else
		{
			previousEl2->next = element1;
			element2->next = nextEl1;
		}
		element1->next = nextEl2;
	}
	return start;
}

/// <summary>
/// ”даление списка
/// </summary>
/// <param name="list"></param>
void Delete(L* list)
{
	L* nextEl = list;
	while (nextEl)
	{
		nextEl = list->next;
		free(list);
		list = nextEl;
	}
}

int main()
{	
	system("chcp 1251>nul");
	L* list = Create(5);
	Show(list);
	Delete(list);

	//list = Create(10);
	L item = { "ћ€у", NULL };
	list = Insert(list, item, 0);
	Show(list);
	//Delete(list);

	//list = Create(10);
	list = DeleteItem(list, 0);
	Show(list);
	//Delete(list);

	//list = Create(10);
	list = SwapItem(list, 0, 1);
	Show(list);
	//Delete(list);

	return 0;
}