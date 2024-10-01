#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <locale.h> 
#include <stdlib.h>

/// <summary>
/// Возвращаем указатель на измененное значение
/// </summary>
/// <param name="pointer"></param>
/// <returns></returns>
int* EditingValue(int* pointer)
{
	int new_value;
	printf("Введите новое значение: ");
	scanf("%d", &new_value);
	*pointer = new_value; // Изменяем значение по указателю
	return pointer;
}

/// <summary>
/// Редактирование и вывод значения целочисленной при обращении к ней из консольного окна
/// </summary>
void Task1()
{
	int num = 10;
	int* pointer = &num;
	printf("Текущее значение: %d\n", *pointer);
	pointer = EditingValue(pointer); // Вызываем функцию для редактирования
	printf("Новое значение: %d\n", *pointer);
}

/// <summary>
/// Динамическое создание и удаление массива из одного миллиона элементов типа int. 
/// </summary>
void Task2()
{
	int size = 1000000;
	int* array = malloc(size * sizeof(int)); //массив из одного миллиона элементов
	int* head = array; //сохранение головы
	for (int i = 0; i < size; i++) {
		*array++ = i;
	}
	array = head;//возвращение головы
	printf("Тестовый вывод первых 300 элементов:\n");
	PrintfArray(array, 300);
	free(array); // удаление
}

/// <summary>
/// Task3: Функция для вывода на экран консоли массива произвольной длины
/// </summary>
/// <param name="array"></param>
/// <param name="size"></param>
/// <returns></returns>
int PrintfArray(int* array, int size)
{
	for (int i = 0; i < size; i++) printf("%d ", *array++);
}

/// <summary>
/// Используя указатели, сформировать треугольную матрицу
/// </summary>
void Task4()
{
	int size;
	printf("Введите размер: ");
	scanf("%d", &size);
	int** matrix = (int**) malloc(size * sizeof(int*));
	int num = 0;
	int* headMain = matrix;
	for (int i = 0; i < size; i++) {
		*matrix = (int*) malloc((i + 1) * sizeof(int));
		int* pointer = *matrix++; // равняется matrix[i]
		for (int j = 0; j <= i; j++) {
			*pointer++ = num++;
		}
	}
	matrix = headMain;
	//Вывод матрицы
	headMain = matrix;
	for (int i = 0; i < size; i++)
	{
		int* pointer = *matrix++;
		for (int j = 0; j <= i; j++)
		{
			printf("%d\t", *pointer++);
		}
		printf("\n");
	}
	matrix = headMain;
	//Очистка
	headMain = matrix;
	for (int i = 0; i < size; i++) {
		free(*matrix++);
	}
	matrix = headMain;
	free(matrix);
}

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

// Функция, принимающая указатель на функцию в качестве аргумента
int calculate(int (*operation)(int, int), int a, int b) {
	return operation(a, b);
}

/// <summary>
/// Написать программу с использованием указателя на функцию и с использованием указателя на функцию в качестве аргумента
/// </summary>
void Task5()
{
	int (*operation)(int, int) = add; // Указатель на функцию
	int a, b, n;
	printf("Введите a: ");
	scanf("%d", &a);
	printf("Введите b: ");
	scanf("%d", &b);
	printf("Введите номер оператора:\n");
	printf("1. Сложение\n");
	printf("2. Вычитание\n");
	scanf("%d", &n);
	switch (n)
	{
	case 1: operation = add; break;
	case 2: operation = subtract; break;
	default: printf("Такого оператора нет, будет сумма\n"); break;
	}
	printf("Ответ: %d\n", calculate(operation, a, b));
}

int main()
{
	system("chcp 1251>nul");
	int n, end;
	do
	{
		printf("\nВыберите задачу:");
		printf("\n1. Редактирование и вывод значения целочисленной при обращении к ней из консольного окна");
		printf("\n2. Динамическое создание и удаление массива из одного миллиона элементов типа int.\nЗначения элементов массива должны быть равны значению их индексов");
		printf("\n3. Функция для вывода на экран консоли массива произвольной длины");
		printf("\n4. Используя указатели, сформировать треугольную матрицу");
		printf("\n5. Написать программу с использованием указателя на функцию и с использованием указателя на функцию в качестве аргумента\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: Task1(); break;
		case 2: Task2(); break;
		case 3: Task2(); break;
		case 4: Task4(); break;
		case 5: Task5(); break;
		default: printf("Такой задачи нет\n"); break;
		}
		printf("\nВы хотите выбрать другое задание? (1 - да, 0 - нет).\n");
		scanf_s("%d", &end);
	} while (end > 0);
	return 0;
}