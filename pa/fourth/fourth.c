#include <stdio.h>
#include <stdlib.h>

int **Matrix1(int row, int col, int *key)
{
    int **matrix = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = malloc(col * sizeof(int));
    }
    int keyIndex = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = key[keyIndex++];
        }
    }
    return matrix;
}

int **Matrix2(int row, int col, int *key)
{
    int **matrix2 = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix2[i] = malloc(col * sizeof(int));
    }
    int keyIndex = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix2[i][j] = key[keyIndex++];
        }
    }
    return matrix2;
}

void result(int **matrix1, int **matrix2, int row, int col, int row2)
{
    int **result = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        result[i] = malloc(col * sizeof(int));
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = 0;
            for (int l = 0; l < row2; l++)
            {
                result[i][j] += matrix1[i][l] * matrix2[l][j];
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < row; i++)
    {
        free(result[i]);
    }
    free(result);
}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    int row = 0;
    int col = 0;
    int row2 = 0;
    int col2 = 0;
    int **matrix1 = NULL;
    int **matrix2 = NULL;
    if (fscanf(f, "%d\t%d", &row, &col) == 2)
    {
        int totalKeys = row * col;
        int *keys = malloc(totalKeys * sizeof(int));
        for (int i = 0; i < totalKeys; i++)
        {
            fscanf(f, "%d\t", &keys[i]);
        }
        matrix1 = Matrix1(row, col, keys);
        free(keys);
    }
    if (fscanf(f, "%d\t%d", &row2, &col2) == 2)
    {
        int totalKeys2 = row2 * col2;
        int *keys2 = malloc(totalKeys2 * sizeof(int));
        for (int i = 0; i < totalKeys2; i++)
        {
            fscanf(f, "%d\t", &keys2[i]);
        }
        matrix2 = Matrix2(row2, col2, keys2);
        free(keys2);
    }
    if (col != row2)
    {
        printf("bad-matrices\n");
        for (int i = 0; i < row; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);
    for (int i = 0; i < row2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);
        fclose(f);
        return 1; 
    }
    result(matrix1, matrix2, row, col2, row2);
    for (int i = 0; i < row; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);
    for (int i = 0; i < row2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);
    fclose(f);
    return 0;
}