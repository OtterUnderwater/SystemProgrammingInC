#include "Header.h"
#include "Header2.h"

int main()
{
	system("chcp 1251>nul");
	printf("stdio.h ���������� � ��������\n");
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
    double fnumber = -123456.44;
    char* str = DoubleToString(fnumber, accuracy);
    printf("%s\n", str);

    float num = StringToDouble("-50555.44");
    printf("%f\n", num);

	return 0;
}

/// <summary>
/// ����������� ����� � ������
/// </summary>
/// <param name="number"></param>
/// <param name="accuracy">��������� �� ������� ������ ����� �������</param>
/// <returns></returns>
char* DoubleToString(double number, int accuracy)
{
    int sizeAnswer = 0;
    int size = 0;
    char* answer = malloc(sizeAnswer * sizeof(char));
    int i = 0;
    if (number < 0)
    {
        sizeAnswer++;
        answer = realloc(answer, sizeAnswer * sizeof(char));
        answer[i] = '-'; i++;
        number = number * -1;
    }
    int intBuffer = (int)number;
    int intBuffer2 = (int)number;
    while (intBuffer2 > 0)
    {
        intBuffer2 = intBuffer2 / 10;
        size++;
    }
    char* buffer = malloc(size * sizeof(char));
    snprintf(buffer, size + 1, "%d", intBuffer);
    char* buffer2 = malloc(0 * sizeof(char));
    int size2 = 0;
    double ostdouble = number - intBuffer;
    if (ostdouble > 0)
    {
        int ost = ostdouble * pow(10, accuracy);
        buffer2 = realloc(buffer2, accuracy * sizeof(char));
        snprintf(buffer2, accuracy + 1, "%d", ost);
        size2 = accuracy + 1; //��� �����
    }
    sizeAnswer += size + size2;
    while (i < sizeAnswer)
    {
        for (int j = 0; j < size; j++)
        {
            answer[i] = buffer[j];
            i++;
        }
        if (size2 > 0)
        {
            answer[i] = '.'; i++;
            for (int j = 0; j < size2; j++)
            {
                answer[i] = buffer2[j];
                i++;
            }
        }
    }
    return answer;
}

/// <summary>
/// ��������� ������ � �����
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
double StringToDouble(char* str)
{
    double number = 0;
    int sign = 1;
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
                    double del = pow(10, d);
                    double f = (str[i] - '0') / del;
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
            printf("������������ ������ ������!\n");
            return 0;
        }
    }
    return number * sign;
}