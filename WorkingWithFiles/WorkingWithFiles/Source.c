#include "Libraries.h"

//Проверка на корректность числа и возврат указателя на него или возврат NULL
double* getCoeff(int start, int end, char* arr)
{
	double coeff = 0;
	int znak = 1, drob = 0, step = 0;
	if (arr[start] == '-')
	{
		znak = -1; start++;
	}
	for (int k = start; k < end; k++)
	{
		if ((arr[k] >= '0' && arr[k] <= '9') || arr[k] == '.')
		{
			if (drob == 0 && arr[k] == '.') drob = 1;
			else if (arr[k] >= '0' && arr[k] <= '9')
			{
				if (drob == 0)
				{
					coeff = (coeff * pow(10, step)) + (arr[k] - '0');
					step++;
				}
				else
				{
					coeff += (arr[k] - '0') / pow(10, drob); drob++;
				}
			}
			else return NULL;
		}
		else return NULL;
	}
	coeff = coeff * znak;
	return &coeff;
}

//Считывание данных из файла и конвертация в массив double
double* readFile(char* name)
{
	FILE* file = fopen(name, "rt");
	int size = 0;
	char c;
	char* arr = malloc(size * sizeof(char));
	double* coeff = malloc(3 * sizeof(double));
	for (int i = 0; fscanf(file, "%c", &c) == 1; i++)
	{
		size++;
		arr = realloc(arr, size * sizeof(char));
		arr[i] = c;
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
	if (countSpace > 2) return NULL;
	int startIndex = 0; //начинается с 0, далее - все ячейки после пробела
	double* pointer;
	for (int i = 0; i < countSpace; i++)
	{
		pointer = getCoeff(startIndex, index[i], arr);
		startIndex = index[i] + 1;
		if (pointer) coeff[i] = *pointer;
		else return NULL;
	}
	pointer = getCoeff(startIndex, size2, arr);
	if (pointer) coeff[countSpace] = *pointer;
	else return NULL;
	return coeff;
}

//Запись ошибки в файл
int error(char* name)
{
	FILE* file = fopen(name, "w+t");
	fprintf(file, "Файл содержит символы или другие некорректные данные");
	fclose(file);
	return 0;
}

//Поиск корней уравнения
int getRoots(char* name, double a, double b, double c)
{
	FILE* file = fopen(name, "w+t"); //открываем для записи формат t текстовый
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
		else fprintf(file, "Корней нет");
	}
	fclose(file);
	return 0;
}

int main()
{
	system("chcp 1251>nul");
	char* fileResult = "result.txt";
	double* arr = readFile("coefficients.txt");
	if (arr) getRoots(fileResult, arr[0], arr[1], arr[2]);
	else error(fileResult);
	return 0;
}