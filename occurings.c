#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

char *compressString(const char *input) 
{
    int length = strlen(input);
    char *compressed = (char *)malloc(MAX_LENGTH);
    int count = 1;
    int j = 0;

    for (int i = 0; i < length; i++) 
    {
        if (i < length - 1 && input[i] == input[i + 1]) 
        {
            count++;
        } 
        else 
        {
            compressed[j++] = input[i];
            if (count > 1) 
            {
                j += sprintf(&compressed[j], "%d", count);
            }
            count = 1;
        }
    }
    compressed[j] = '\0';

    if (strlen(compressed) >= length) 
    {
        free(compressed);
        return strdup(input);
    }

    return compressed;
}

int main() 
{
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; 

    char *compressed = compressString(input);
    printf("Compressed string: %s\n", compressed);

    free(compressed);
    return 0;
}