#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <locale.h> 
#include <stdlib.h>

struct LinearList
{
	char* id; //������������
	struct LinearList* next;
};
typedef struct LinearList L;

/// <summary>
/// �������� ������
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
L* Create(int size)
{
	L* start = malloc(sizeof(L)); //������, ������ �������
	start->id = "�������0";
	start->next = NULL;
	//��������� �� ������� � ��������� �������, � �� ������� �������� ��������
	L* previousEl, *nextEl;
	previousEl = start;
	for (int i = 0; i < size - 1; i++)
	{
		printf("������� %d �������: ", i+1);
		char* name = malloc(sizeof(char));
		gets(name);
		nextEl = malloc(sizeof(L));
		nextEl->id = name;
		previousEl->next = nextEl;
		previousEl = nextEl;
	}
	previousEl->next = NULL; //����� ������
	return start;
}

/// <summary>
/// ������� ���
/// </summary>
/// <param name="list"></param>
void Show(L* list)
{
	printf("����: ");
	L* nextEl = list;
	while (nextEl)
	{
		printf("%s ", nextEl->id);
		nextEl = nextEl->next;
	}
	printf("\n\n");
}

/// <summary>
/// ������� �������� ������ ������
/// </summary>
/// <param name="list"></param>
/// <param name="item"></param>
/// <param name="index"></param>
/// <returns></returns>
L* Insert(L* list, L item, int index)
{
	L* start = list; //���������� ������ ������
	if (index == 0) //������ ������
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
				printf("������ ��������� ������� ������. ������� �������� � �����.\n");
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
/// �������� �������� ������ �� �������
/// </summary>
/// <param name="list"></param>
/// <param name="indexItem"></param>
/// <returns></returns>
L* DeleteItem(L* list, int indexItem)
{
	L* start = list; //���������� ������ ������
	if (indexItem == 0) //������ ������
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
				printf("������ ��������� ������� ������. �������� �� ���� �������.\n");
				return start;
			}
		}
		L* deletedItem = list->next;
		list->next = list->next->next;
		free(deletedItem); //�������� ������
	}
	return start;
}

L* SwapItem(L* list, int indexItem1, int indexItem2)
{
	int index1 = min(indexItem1, indexItem2);
	int index2 = max(indexItem1, indexItem2);
	L* start = list; //���������� ������ ������
	if (index1 == 0) //������ ������
	{
		L* element1 = list;
		L* nextEl1 = list->next;
		int i = 0;
		while (i < index2 - 1)
		{
			list = list->next;
			if (!(list->next))
			{
				printf("������ ��������� ������� ������. �������� �� ���� ��������.\n");
				return start;
			}
			i++;
		}
		L* previousEl2 = list;
		L* element2 = list->next;
		L* nextEl2 = element2->next;
		//������
		element1->next = nextEl2;
		if (nextEl1 == element2)  //��������, ���� �������� ����� �����
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
				printf("������ ��������� ������� ������. �������� �� ���� ��������.\n");
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
				printf("������ ��������� ������� ������. �������� �� ���� ��������.\n");
				return start;
			}
			i++;
		}
		L* previousEl2 = list;
		L* element2 = list->next;
		L* nextEl2 = element2->next;
		//������
		previousEl1->next = element2;
		if (nextEl1 == element2) //��������, ���� �������� ����� �����
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
/// �������� ������
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
	L item = { "���", NULL };
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