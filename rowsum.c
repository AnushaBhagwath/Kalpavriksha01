#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int **matrix, int rows, int cols) 
{
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", *(matrix + i) + j);
        }
    }
}

void sumOfRows(int **matrix, int rows, int cols) 
{
    printf("Sum of elements in each row:\n");
    for (int i = 0; i < rows; i++) 
    {
        int sum = 0;
        for (int j = 0; j < cols; j++) 
        {
            sum += *(*(matrix + i) + j);
        }
        printf("Sum of row %d: %d\n", i + 1, sum);
    }
}

int main() 
{
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) 
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    inputMatrix(matrix, rows, cols);
    sumOfRows(matrix, rows, cols);

    for (int i = 0; i < rows; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
