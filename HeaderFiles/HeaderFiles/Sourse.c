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

    char* str = IntToString(1000000000);
    printf("%s\n", str);

    int num = StringToInt("-505400");
    printf("%d\n", num);

	return 0;
}

char* IntToString(int number)
{
   char* buffer = malloc(100 * sizeof(char));
   snprintf(buffer, 100, "%d", number);
   return buffer;
}

int StringToInt(char* str)
{
    /*int number = 0;
    int sign = 1;
    int i = 0;
    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            printf("Некорректный формат строки!\n");
            return 0;
        }
        number = number * 10 + (str[i] - '0');
        i++;
    }
    //return number * sign;
    */
    return atof(str);
}