#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

void findLongestWord(const char *sentence, char *longestWord) 
{
    int maxLength = 0;
    int currentLength = 0;
    const char *wordStart = sentence;
    const char *temp = sentence;

    while (*temp) 
    {
        if (*temp == ' ') 
        {
            if (currentLength > maxLength) 
            {
                maxLength = currentLength;
                strncpy(longestWord, wordStart, currentLength);
                longestWord[currentLength] = '\0';
            }
            currentLength = 0;
            wordStart = temp + 1;
        } 
        else 
        {
            currentLength++;
        }
        temp++;
    }

    if (currentLength > maxLength) 
    {
        strncpy(longestWord, wordStart, currentLength);
        longestWord[currentLength] = '\0';
    }
}

int main() 
{
    char sentence[MAX_LENGTH];
    char longestWord[MAX_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; 

    findLongestWord(sentence, longestWord);

    printf("Longest word: %s\n", longestWord);

    return 0;
}
