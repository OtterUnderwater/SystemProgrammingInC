#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <locale.h> 
#include <stdlib.h>

/// <summary>
/// ���������� ��������� �� ���������� ��������
/// </summary>
/// <param name="pointer"></param>
/// <returns></returns>
int* EditingValue(int* pointer)
{
	int new_value;
	printf("������� ����� ��������: ");
	scanf("%d", &new_value);
	*pointer = new_value; // �������� �������� �� ���������
	return pointer;
}

/// <summary>
/// �������������� � ����� �������� ������������� ��� ��������� � ��� �� ����������� ����
/// </summary>
void Task1()
{
	int num = 10;
	int* pointer = &num;
	printf("������� ��������: %d\n", *pointer);
	pointer = EditingValue(pointer); // �������� ������� ��� ��������������
	printf("����� ��������: %d\n", *pointer);
}

/// <summary>
/// ������������ �������� � �������� ������� �� ������ �������� ��������� ���� int. 
/// </summary>
void Task2()
{
	int size = 1000000;
	int* array = malloc(size * sizeof(int)); //������ �� ������ �������� ���������
	int* head = array; //���������� ������
	for (int i = 0; i < size; i++) {
		*array++ = i;
	}
	array = head;//����������� ������
	printf("�������� ����� ������ 300 ���������:\n");
	PrintfArray(array, 300);
	free(array); // ��������
}

/// <summary>
/// Task3: ������� ��� ������ �� ����� ������� ������� ������������ �����
/// </summary>
/// <param name="array"></param>
/// <param name="size"></param>
/// <returns></returns>
int PrintfArray(int* array, int size)
{
	for (int i = 0; i < size; i++) printf("%d ", *array++);
}

/// <summary>
/// ��������� ���������, ������������ ����������� �������
/// </summary>
void Task4()
{
	int size;
	printf("������� ������: ");
	scanf("%d", &size);
	int** matrix = (int**) malloc(size * sizeof(int*));
	int num = 0;
	int* headMain = matrix;
	for (int i = 0; i < size; i++) {
		*matrix = (int*) malloc((i + 1) * sizeof(int));
		int* pointer = *matrix++; // ��������� matrix[i]
		for (int j = 0; j <= i; j++) {
			*pointer++ = num++;
		}
	}
	matrix = headMain;
	//����� �������
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
	//�������
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

// �������, ����������� ��������� �� ������� � �������� ���������
int calculate(int (*operation)(int, int), int a, int b) {
	return operation(a, b);
}

/// <summary>
/// �������� ��������� � �������������� ��������� �� ������� � � �������������� ��������� �� ������� � �������� ���������
/// </summary>
void Task5()
{
	int (*operation)(int, int) = add; // ��������� �� �������
	int a, b, n;
	printf("������� a: ");
	scanf("%d", &a);
	printf("������� b: ");
	scanf("%d", &b);
	printf("������� ����� ���������:\n");
	printf("1. ��������\n");
	printf("2. ���������\n");
	scanf("%d", &n);
	switch (n)
	{
	case 1: operation = add; break;
	case 2: operation = subtract; break;
	default: printf("������ ��������� ���, ����� �����\n"); break;
	}
	printf("�����: %d\n", calculate(operation, a, b));
}

int main()
{
	system("chcp 1251>nul");
	int n, end;
	do
	{
		printf("\n�������� ������:");
		printf("\n1. �������������� � ����� �������� ������������� ��� ��������� � ��� �� ����������� ����");
		printf("\n2. ������������ �������� � �������� ������� �� ������ �������� ��������� ���� int.\n�������� ��������� ������� ������ ���� ����� �������� �� ��������");
		printf("\n3. ������� ��� ������ �� ����� ������� ������� ������������ �����");
		printf("\n4. ��������� ���������, ������������ ����������� �������");
		printf("\n5. �������� ��������� � �������������� ��������� �� ������� � � �������������� ��������� �� ������� � �������� ���������\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: Task1(); break;
		case 2: Task2(); break;
		case 3: Task2(); break;
		case 4: Task4(); break;
		case 5: Task5(); break;
		default: printf("����� ������ ���\n"); break;
		}
		printf("\n�� ������ ������� ������ �������? (1 - ��, 0 - ���).\n");
		scanf_s("%d", &end);
	} while (end > 0);
	return 0;
}