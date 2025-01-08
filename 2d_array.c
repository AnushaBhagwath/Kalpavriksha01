#include <stdio.h>
#include <string.h>

// Function to check if a character is a vowel
int isVowel(char character) 
{
    character = (character >= 'A' && character <= 'Z') ? character + 32 : character;  // Convert to lowercase if uppercase
    return (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u');
}

int main() 
{
    int numberOfRows, numberOfColumns;
    char choice;

    do 
    {
        // Input validation for the number of rows
        do 
        {
            printf("Enter number of rows (1-10): ");
            scanf("%d", &numberOfRows);
        } while (numberOfRows < 1 || numberOfRows > 10);

        // Input validation for the number of columns
        do 
        {
            printf("Enter number of columns (1-10): ");
            scanf("%d", &numberOfColumns);
        } while (numberOfColumns < 1 || numberOfColumns > 10);

        char names[numberOfRows][numberOfColumns][51]; // 2D array of strings
        char longestName[51] = ""; // To store the longest name
        int vowelStartCount = 0;   // Count of names starting with a vowel

        printf("Enter the names:\n");

        // Reading names into the 2D array
        for (int row = 0; row < numberOfRows; row++)
         {
            for (int column = 0; column < numberOfColumns; column++) 
            {
                printf("Name at (%d,%d): ", row, column);
                scanf("%s", names[row][column]);

                // Check for exit condition
                if (strcmp(names[row][column], "exit") == 0) 
                {
                    row = numberOfRows; 
                    break;
                }

            
                if (isVowel(names[row][column][0]))
                 {
                    vowelStartCount++;
                }

                // Manually find the length and update longest name
                int currentLength = 0;
                while (names[row][column][currentLength] != '\0') 
                {
                    currentLength++;
                }

                int longestLength = 0;
                while (longestName[longestLength] != '\0')
                 {
                    longestLength++;
                }

                if (currentLength > longestLength) 
                {
                    for (int k = 0; k <= currentLength; k++) {
                        longestName[k] = names[row][column][k];
                    }
                }
            }
        }

        printf("\nThe 2D array of names is:\n");
        for (int row = 0; row < numberOfRows; row++) 
        {
            for (int column = 0; column < numberOfColumns; column++)
             {
                printf("%s ", names[row][column]);
            }
            printf("\n");
        }

    
        printf("\nNumber of names starting with a vowel: %d\n", vowelStartCount);
        printf("The longest name: %s\n", longestName);

        // Ask user if they want to continue
        printf("\nDo you want to enter another set of names? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
