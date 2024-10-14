#define _CRT_SECURE_NO_WARNINGS
#define POW(x) (x)*(x) //������ �������� ����� �� ������ �������
#define X1 0
#define Y1 0
#define X2 0
#define Y2 0
#define X3 0
#define Y3 0
#define A sqrt(POW(X3 - X1) + POW(Y3 - Y1))
#define B sqrt(POW(X3 - X2) + POW(Y3 - Y2))
#define C sqrt(POW(X2 - X1) + POW(Y2 - Y1))
#include <stdio.h>
#include <math.h>
#include <locale.h> 

/// <summary>
/// ���������� ����� ������� �� ����������� ���� ��� �����
/// </summary>
/// <param name="x1"></param>
/// <param name="y1"></param>
/// <param name="x2"></param>
/// <param name="y2"></param>
/// <returns></returns>
float GetLengthSegment(float x1, float y1, float x2, float y2)
{
    return sqrt(POW((x2 - x1)) + POW((y2 - y1)));
}

/// <summary>
/// ���� ����������� ����������, �� ������� ��� �������� � �������
/// </summary>
/// <param name="x1"></param>
/// <param name="y1"></param>
/// <param name="x2"></param>
/// <param name="y2"></param>
void GetPerimeterAndSquare(float x1, float y1, float x2, float y2)
{
    float x3 = x2, y3 = y1;
    float a = GetLengthSegment(x1, y1, x3, y3);
    float b = GetLengthSegment(x2, y2, x3, y3);
    float c = GetLengthSegment(x1, y1, x2, y2);
    if ((a + b > c) && (b + c > a) && (a + c > b))
    {
        float P = a + b + c;
        float p = P / 2;
        float S = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("����������� ����������, ��������: %.2f, �������: %.2f\n", P, S);
    }
    else printf("����������� �� ����������");
}

void GetPerimeterAndSquare2()
{
#if ((X2 - X1) * (Y2 - Y1) == (X3 - X1)* (Y3 - Y1))
    printf("����������� �� ����������\n");
#else
    float P = A + B + C;
    float p = P / 2;
    float S = sqrt(p * (p - A) * (p - B) * (p - C));
    printf("����������� ����������, ��������: %.2f, �������: %.2f\n", P, S);
#endif
}

int main()
{
    system("chcp 1251>nul");
   //GetPerimeterAndSquare(1, 2, 3, 5);
    GetPerimeterAndSquare2();
    return 0;
}