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

    char* str = FloatToString(12345678.44);
    printf("%s\n", str);

    float num = StringToFloat("-50555.44");
    printf("%f\n", num);

	return 0;
}

//char* FloatToString(float number)
//{
//   char* buffer = malloc(100 * sizeof(char));
//   snprintf(buffer, 100, "%f", number);
//   return buffer;
//}

char* FloatToString(float number) {
   // char sign = (number < 0) ? '-' : '+';
    //number = fabs(number);

    char* buffer = malloc(0 * sizeof(char));
    int count = 0;
    int intBuffer = (int) number;
    int intBuffer2 = (int) number;
    while (intBuffer2 > 0) {
        intBuffer2 = intBuffer2 / 10;
        count++;
    }
    int i = 1;
    while (count > 0) {
        int n = intBuffer / pow(10, count-1);
        intBuffer = intBuffer - (n * pow(10, count-1));
        buffer = realloc(buffer, i * sizeof(char));
        buffer[i-1] = n;
        count--;
        i++;
    }
    return buffer;
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