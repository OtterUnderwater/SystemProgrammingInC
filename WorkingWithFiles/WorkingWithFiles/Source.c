#include "Libraries.h"

void getRoots(double a, double b, double c)
{
	FILE* file = fopen("result.txt", "w+t"); //открываем для записи формат t текстовый
	if (a == 0) //проверка корректности
	{
		if (b == 0)
		{
			if (c == 0) fprintf(file, "Уравнение имеет бесконечно много решений.");
			else fprintf(file, "Уравнение не имеет решений.");
		}
		else
		{
			double x = -c / b; // Линейное уравнение
			fprintf(file, "Уравнение имеет одно решение: x = %.2lf", x);
		}
	}
	else
	{
		double D = pow(b, 2) - (double)4 * a * c;
		if (D >= 0)
		{
			if (D == 0)
			{
				double x = (-b) / (2 * a);
				fprintf(file, "Корень один: %0.2lf", x);
			}
			else
			{
				double x1 = (-b + sqrt(D)) / (2 * a);
				double x2 = (-b - sqrt(D)) / (2 * a);
				fprintf(file, "Корни уравнения: %0.2lf, %0.2lf", x1, x2);
			}
		}
		else
		{
			fprintf(file, "Корней нет");
		}
	}
	fclose(file);
}

int main()
{
	int size = 0;
	int i = 0;
	char c;
	system("chcp 1251>nul");
	FILE* file = fopen("coefficients.txt", "rt");
	char* arr = malloc(size * sizeof(char));
	double* coeff = malloc(3 * sizeof(double));
	for (int i = 0; i < 3; i++) coeff[i] = 0;
	while (fscanf(file, "%c", &c) == 1)
	{
		size++;
		arr = realloc(arr, size * sizeof(char));
		arr[i] = c;
		i++;
	}
	fclose(file);
	int size2 = _msize(arr) / sizeof(char);
	int countSpace = 0;
	int* index = malloc(size * sizeof(int));
	for (int i = 0; i < size2; i++)
	{
		if (arr[i] == ' ')
		{
			countSpace++;
			index = realloc(index, countSpace * sizeof(int));
			index[countSpace - 1] = i;
		}
	}
	int startIndex = 0;
	int length = 0;
	for (int i = 0; i <= countSpace; i++)
	{
		length = index[i] - startIndex;
		for (int k = startIndex; k < index[i]; k++)
		{
			length--;
			coeff[i] += (arr[k] - '0') * pow(10, length);
		}
		startIndex = index[i] + 1;
	}
	length = size2 - startIndex;
	for (int k = startIndex; k < size2; k++)
	{
		length--;
		coeff[countSpace] += (arr[k] - '0') * pow(10, length);
	}
	int gfhfh = 0;
	getRoots(4, -12, 9);
	return 0;
}