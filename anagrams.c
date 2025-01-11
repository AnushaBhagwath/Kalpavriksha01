#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool areAnagrams(const char *str1, const char *str2) 
{
    int count[256] = {0};

    if (strlen(str1) != strlen(str2)) 
    {
        return false;
    }

    while (*str1) 
    {
        count[(unsigned char)(*str1)]++;
        count[(unsigned char)(*str2)]--;
        str1++;
        str2++;
    }

    for (int i = 0; i < 256; i++) 
    {
        if (count[i] != 0) 
        {
            return false;
        }
    }

    return true;
}

int main() 
{
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2)) 
    {
        printf("true\n");
    } 
    else 
    {
        printf("false\n");
    }

    return 0;
}
