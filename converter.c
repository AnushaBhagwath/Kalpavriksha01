#include <stdio.h>
#include <ctype.h>

int myAtoi(const char *str) 
{
    int result = 0;
    int sign = 1;
    while (isspace(*str)) 
    {
        str++;
    }

    if (*str == '-') 
    {
        sign = -1;
        str++;
    } 
    else if (*str == '+') 
    {
        str++;
    }

    while (*str != '\0') 
    {
        if (!isdigit(*str)) 
        {
            return 0; 
        }
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

int main() 
{
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int result = myAtoi(input);
    printf("Converted integer: %d\n", result);

    return 0;
}
