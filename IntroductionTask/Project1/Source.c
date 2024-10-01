#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <locale.h> 
#include <stdlib.h>

#pragma region InputOutput
const int MinInt = -0;

double* InputParameters(char* message, int count)
{
	char str = "число";
	double mass[6];
	for (int i = 0; i < count; i++)
	{
		if (message != NULL) printf("Введите %c = ", message[i]);
		scanf("%lf", &mass[i]);
	}
	return mass;
}

void OutputParameters(char* message, long double num1, long double num2)
{
	if (num1 == MinInt) printf(message);
	else if (num2 == MinInt) printf(message, num1);
	else printf(message, num1, num2);
}

#pragma endregion

char* QuadraticEquation(double a, double b, double c)
{
	char* formattedString = malloc(100);
	double d, x1, x2;
	if (a == 0)
	{
		OutputParameters("Коэффициент a не может быть равен 0", MinInt, MinInt);
	}
	else
	{
		d = pow(b, 2) - 4 * a * c;
		if (d > 0)
		{
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			OutputParameters("Корни уравнения:\n x1 = %.2f\t x2 = %.2f\n", x1, x2);
		}
		else if (d == 0)
		{
			if (b == 0) OutputParameters("Корень x = %.2f\n", 0, MinInt);
			else
			{
				x1 = -b / (2 * a);
				OutputParameters("Корень x = %.2f\n", x1, MinInt);
			}
		}
		else
		{
			OutputParameters("Уравнение не имеет корней", MinInt, MinInt);
		}
	}
}

void LinearEquations(double a1, double b1, double c1, double a2, double b2, double c2)
{
	double del = a1 * b2 - a2 * b1;
	if (del == 0)
	{
		OutputParameters("Система уравнений либо не имеет решений, либо имеет бесконечно много решений.", MinInt, MinInt);
	}
	else
	{
		// Решение системы уравнений методом Крамера
		double x = (c1 * b2 - c2 * b1) / del;
		double y = (a1 * c2 - a2 * c1) / del;
		OutputParameters("Решение системы уравнений:\n x = %.2lf\t y = %.2lf\n", x, y);
	}
}

long double GetFactorial(int num)
{
	if (num > 1) return num * (GetFactorial(num - 1));
	else return 1; 
}

void Factorial(int num)
{
	if (num <= 170)
	{
		if (num > 0) OutputParameters("Факториал = %0.Lf", GetFactorial(num), MinInt);
		else OutputParameters("Введены неккоректные данные", MinInt, MinInt);
	}
	else OutputParameters("Факториал данного числа слишком велик", MinInt, MinInt);
}

int main()
{
	system("chcp 1251>nul"); //для работы с русским языком
	int n, end;
	do
	{
		printf("\nВыберите задачу:");
		printf("\n1. Квадратное уравнение");
		printf("\n2. Система двух линейных уравнений");
		printf("\n3. Перестановки (факториал)\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("Введите коэффициенты:\n");
			char message1[3] = { 'a', 'b', 'c' };
			double* data1 = InputParameters(message1, 3);
			QuadraticEquation(data1[0], data1[1], data1[2]);
			break;
		case 2:
			printf("Введите коэффициенты двух уравнений:\n");
			char message2[6] = { 'a', 'b', 'c', 'a', 'b', 'c' };
			double* data2 = InputParameters(message2, 6);
			LinearEquations(data2[0], data2[1], data2[2], data2[3], data2[4], data2[5]);
			break;
		case 3:
			printf("Введите положительное целое число: ");
			double* data3 = InputParameters(NULL, 1);
			Factorial(data3[0]);
			break;
		default:
			printf("Такой задачи нет\n");
			break;
		}
		printf("\nВы хотите выбрать другое задание? (1 - да, 0 - нет).\n");
		scanf_s("%d", &end);
	} while (end > 0);
	return 0;
}