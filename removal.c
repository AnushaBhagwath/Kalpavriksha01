#include <stdio.h>
#include <string.h>

void removeCharacter(char *str, char ch) 
{
    int i, j = 0;
    int len = strlen(str);
    char temp[len + 1];

    for (i = 0; i < len; i++) 
    {
        if (str[i] != ch) 
        {
            temp[j++] = str[i];
        }
    }

    temp[j] = '\0';
    strcpy(str, temp);
}

int main() 
{
    char str[100];
    char ch;

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; 

    printf("Enter the character to remove: ");
    scanf("%c", &ch);

    removeCharacter(str, ch);
    printf("Resultant string: %s\n", str);

    return 0;
}