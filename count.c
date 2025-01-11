#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWords(const char *str)
 {
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (!isspace(str[i])) 
        {

            if (!inWord) {
                count++; 
                inWord = 1; 
            }
        } 
        else 
        {
            
            inWord = 0;
        }
    }

    return count;
}

int main()
 {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    int wordCount = countWords(input);
    printf("Number of words: %d\n", wordCount);
    return 0;
}
