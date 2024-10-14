#include "Header.h"
#include "Header2.h"

int main()
{
	system("chcp 1251>nul");
	printf("stdio.h подключена и работает\n");
	float n1 = 10.5, n2 = 5;
	printf("%f\n", Add(n1, n2));
	printf("%f\n", Subtract(n1, n2));
	printf("%f\n", Myltiply(n1, n2));
	printf("%f\n", Divide(n1, n2));

	char* str1 = "Hello, ";
	char* str2 = "world!";
	char* combinedString = StringConcatenation(str1, str2);
	printf("%s\n", combinedString);

    int accuracy = 4;
    double fnumber = 1234567.44;
    char* str = DoubleToString(fnumber, accuracy);
    printf("%s\n", str);

    float num = StringToFloat("-50555.44");
    printf("%f\n", num);

	return 0;
}

/// <summary>
/// Конвертация числа в строку
/// </summary>
/// <param name="number"></param>
/// <param name="accuracy">округлять до скольки знаков после запятой</param>
/// <returns></returns>
char* DoubleToString(double number, int accuracy)
{
    int size = 0;
    int intBuffer = (int) number;
    int intBuffer2 = (int) number;
    while (intBuffer2 > 0)
    {
        intBuffer2 = intBuffer2 / 10;
        size++;
    }
    char* buffer = malloc(size * sizeof(char));
    snprintf(buffer, size, "%d", intBuffer);
    char* buffer2 = malloc(0 * sizeof(char));
    int size2 = 0;
    double ostdouble = number - intBuffer;
    if (ostdouble > 0)
    {
        int ost = ostdouble * pow(10, accuracy);
        buffer2 = realloc(buffer2, accuracy * sizeof(char));
        snprintf(buffer2, accuracy, "%d", ost);
        size2 = accuracy + 1; //для знака .
    }
    int sizeAnswer = size + size2;
    char* answer = malloc(sizeAnswer * sizeof(char));
    int i = 0;
    if (number < 0)
    {
        sizeAnswer++;
        answer = realloc(answer, sizeAnswer * sizeof(char));
        answer[i] = '-';
        i++;
    }
    else
    {
        while (i < sizeAnswer)
        {
            for (int j = 0; j < size; j++)
            {
                answer[i] = '0' + buffer[j];
                i++;
            }
            if (size2 > 0)
            {
                answer[i] = '.'; i++;
                for (int j = 0; j < size2; j++)
                {
                    answer[i] = '0' + buffer2[j];
                    i++;
                }
            }
        }
    }
    return answer;
}


float StringToFloat(char* str)
{
    float number = 0;
    float sign = 1;
    int i = 0;
    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.'))
        {
            if (str[i] == '.')
            {
                i++; 
                int d = 1;
                while (str[i] != '\0') {
                    float del = pow(10, d);
                    float f = (str[i] - '0') / del;
                    number = number + f;
                    i++;
                    d++;
                }
                break;
            }
            else
            {
                number = number * 10 + (str[i] - '0');
                i++;
            }
        }
        else
        {
            printf("Некорректный формат строки!\n");
            return 0;
        }
    }
    return number * sign;
}