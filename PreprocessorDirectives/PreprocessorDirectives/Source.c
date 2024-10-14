#define _CRT_SECURE_NO_WARNINGS
#define POW(x) (x)*(x) //макрос возводит число во вторую степень
#define X1 1
#define Y1 2
#define X2 3
#define Y2 4
#define X3 5
#define Y3 6
#define A sqrt(POW(X3 - X1) + POW(Y3 - Y1))
#define B sqrt(POW(X3 - X2) + POW(Y3 - Y2))
#define C sqrt(POW(X2 - X1) + POW(Y2 - Y1))
#include <stdio.h>
#include <math.h>
#include <locale.h> 

/// <summary>
/// Нахождение длины отрезка по координатам двух его точек
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
/// Если треугольник существует, то находит его периметр и площадь
/// </summary>
/// <param name="x1"></param>
/// <param name="y1"></param>
/// <param name="x2"></param>
/// <param name="y2"></param>
void GetPerimeterAndSquare(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float a = GetLengthSegment(x1, y1, x3, y3);
    float b = GetLengthSegment(x2, y2, x3, y3);
    float c = GetLengthSegment(x1, y1, x2, y2);
    if ((a + b > c) && (b + c > a) && (a + c > b))
    {
        float P = a + b + c;
        float p = P / 2;
        float S = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("Треугольник существует, периметр: %.2f, площадь: %.2f\n", P, S);
    }
    else printf("Треугольник не существует\n");
}

void GetPerimeterAndSquare2()
{
#if ((X2 - X1) / ((X3 - X1) == 0 ? 1:(X3 - X1))) == ((Y2 - Y1) / ((Y3 - Y1) == 0 ? 1:(Y3 - Y1)))
    printf("Треугольник не существует\n");
#else
    float P = A + B + C;
    float p = P / 2;
    float S = sqrt(p * (p - A) * (p - B) * (p - C));
    printf("Треугольник существует, периметр: %.2f, площадь: %.2f\n", P, S);
#endif
}

int main()
{
    system("chcp 1251>nul");
    GetPerimeterAndSquare(1, 2, 3, 4, 5, 6);
    GetPerimeterAndSquare2();
    return 0;
}