#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void removeDuplicates(char *str) 
{
    int len = strlen(str);
    char *result = (char *)malloc(len + 1); 
    int resultIndex = 0;

    if (result == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }

    
    for (int i = 0; i < len; i++) 
    {
        bool isDuplicate = false;

        // Check if str[i] is already present in result
        for (int j = 0; j < resultIndex; j++) 
        {
            if (str[i] == result[j]) 
            {
                isDuplicate = true;
                break;
            }
        }


        if (!isDuplicate) 
        {
            result[resultIndex++] = str[i];
        }
    }

    result[resultIndex] = '\0';

    printf("%s\n", result);
    free(result);
}

int main() {
    char *input = NULL;
    size_t length = 0;

    printf("Enter a string: ");
    getline(&input, &length, stdin); 

    input[strcspn(input, "\n")] = '\0';

    removeDuplicates(input); 

    free(input);

    return 0;
}
