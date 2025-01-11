#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isRotation(const char *str1, const char *str2) 
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) 
    {
        return false;
    }

    char temp[2 * len1 + 1];
    strcpy(temp, str1);
    strcat(temp, str1);

    return strstr(temp, str2) != NULL;
}

int main() 
{
    char string1[100], string2[100];

    printf("Enter the first string: ");
    scanf("%s", string1);

    printf("Enter the second string: ");
    scanf("%s", string2);

    if (isRotation(string1, string2)) 
    {
        printf("true\n");
    } 
    else 
    {
        printf("false\n");
    }

    return 0;
}
