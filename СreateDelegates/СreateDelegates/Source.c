#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <locale.h> 
#include <stdlib.h>

typedef char* (*operation)(); //��������� �� �������
typedef operation* del; //������ ���������� �� ������� (�������)

char* �atSay() { return "Woof Woof Woof"; }
char* DogSay() { return "Meow Meow Meow"; }
char* FoxSay() { return "Fyr Fyr Fyr"; }
char* FrogSay() { return "Kva Kva Kva"; }

/// <summary>
/// ���������� ������� � �������
/// </summary>
/// <param name="delegate"></param>
/// <param name="fun"></param>
/// <returns></returns>
del AddFunToDelegate(del *delegate, operation fun)
{
	int size = _msize(delegate) / sizeof(operation);
	delegate = realloc(delegate, (size + 1) * sizeof(operation));
	delegate[size] = fun;
	return delegate;
}

/// <summary>
/// �������� ������� �� �������� �� �������
/// </summary>
/// <param name="delegate"></param>
/// <param name="fun"></param>
/// <param name="size"></param>
/// <returns></returns>
del RemoveFunFromDelegate(del delegate, int index)
{
	int size = _msize(delegate) / sizeof(operation);
	for (int i = index; i < size; i++)
	{
		delegate[i] = delegate[i + 1];
	}
	delegate = realloc(delegate, ((size) - 1) * sizeof(operation));
	return delegate;
}

/// <summary>
/// ������ ���� ������� �� ��������
/// </summary>
/// <param name="delegate"></param>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int StartFunFromDelegate(operation* delegate)
{
	int size = _msize(delegate) / sizeof(operation);
	for (int i = 0; i < size; i++) puts((*delegate++)()); //����, ��� delegate[i]()
}

/// <summary>
/// �������� ���� ������������� ������� � ��������
/// </summary>
/// <param name="delegate"></param>
/// <param name="fun"></param>
/// <param name="size"></param>
/// <returns></returns>
del RemoveDuplicateFunInDelegate(operation* delegate)
{
	int sizeOrig = 0;
	int orig = 0;
	del original = malloc(sizeOrig * sizeof(operation));
	int size = _msize(delegate) / sizeof(operation);
	for (int i = 0; i < size; i++)
	{
		orig = 0;
		for (int j = 0; j < sizeOrig; j++)
		{
			if (delegate[i] == original[j])
			{
				orig = 1;
			}
		}
		if (orig == 0)
		{
			sizeOrig++;
			original = realloc(original, sizeOrig * sizeof(operation));
			original[sizeOrig-1] = delegate[i];
		}
	}
	free(delegate); //�������� ������
	return original;
}

int main()
{
	system("chcp 1251>nul");
	int size = 3;
	del delegate = malloc(size * sizeof(operation));
	delegate[0] = �atSay;
	delegate[1] = DogSay;
	delegate[2] = FrogSay;
	StartFunFromDelegate(delegate);
	printf("\n");
	delegate = AddFunToDelegate(delegate, FoxSay);
	delegate = AddFunToDelegate(delegate, FoxSay);
	delegate = AddFunToDelegate(delegate, FoxSay);
	delegate = AddFunToDelegate(delegate, FrogSay);
	delegate = AddFunToDelegate(delegate, FrogSay);
	StartFunFromDelegate(delegate);
	printf("\n");
	delegate = RemoveFunFromDelegate(delegate, 2);
	StartFunFromDelegate(delegate);
	printf("\n");
	delegate = RemoveDuplicateFunInDelegate(delegate);
	StartFunFromDelegate(delegate);
	printf("\n");
	return 0;
}