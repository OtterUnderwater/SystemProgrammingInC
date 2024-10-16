#pragma once
#include "Header.h"

//Сигнатуры
float Add(float, float);
float Subtract(float, float);
float Myltiply(float, float);
float Divide(float, float);
char* StringConcatenation(char*, char*);
char* DoubleToString(double number, int accuracy);
double StringToDouble(char*);

//Функции
float Add(float n1, float n2)
{
	return n1 + n2;
}
float Subtract(float n1, float n2)
{
	return n1 - n2;
}
float Myltiply(float n1, float n2)
{
	return n1 * n2;
}
float Divide(float n1, float n2)
{
	if (n2 == 0) return 0;
	return (float) n1 / n2;
}

char* StringConcatenation(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int newLength = len1 + len2;
	char* combinedString = (char*) malloc((newLength + 1) * sizeof(char));
	combinedString[newLength] = '\0';
	strcpy(combinedString, str1);
	for (int i = 0; i < len2; i++) {
		combinedString[len1 + i] = str2[i];
	}
 	combinedString[newLength] = '\0';
	return combinedString;
}

