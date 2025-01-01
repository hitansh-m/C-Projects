#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **fill(int dim, int *key)
{
    int **arr = (int **)malloc(dim * sizeof(int *));
    for (int i = 0; i < dim; i++)
    {
        arr[i] = (int *)malloc(dim * sizeof(int));
    }
    int keyIndex = 0;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            arr[i][j] = key[keyIndex++];
        }
    }
    return arr;
}

void check(int **a, int dim)
{
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int count7 = 0;
    int count8 = 0;

    for (int i = 0; i < dim; i++)
    {
        count += a[0][i];
        count4 += a[i][0];
        if (dim > 1)
        {
            count2 += a[1][i];
            count5 += a[i][1];
        }
        if (dim > 2)
        {
            count3 += a[2][i];
            count6 += a[i][2];
        }
        count7 += a[i][i];
        count8 += a[i][dim - 1 - i];
    }

    if (dim > 2)
    {
        if (count == count2 && count2 == count3 && count3 == count4 &&
            count4 == count5 && count5 == count6 && count6 == count7 &&
            count7 == count8)
        {
            printf("magic\n");
        }
        else
        {
            printf("not-magic\n");
        }
    }
    else if (dim == 2)
    {
        if (count == count2 && count2 == count4 &&
            count4 == count5 && count5 == count7 &&
            count7 == count8)
        {
            printf("magic\n");
        }
        else
        {
            printf("not-magic\n");
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    int dim = 0;
    int **M1 = NULL;
    if (fscanf(f, "%d", &dim) == 1)
    {
        int totalKeys = dim * dim;
        int *keys = malloc(totalKeys * sizeof(int));
        for (int i = 0; i < totalKeys; i++)
        {
            fscanf(f, "%d\t", &keys[i]);
        }
        M1 = fill(dim, keys);
        free(keys);
    }
    for (int i = 1; i < dim; i++)
    {
        for (int j = 1; j < dim; j++)
        {
            if (M1[0][0] == M1[i][j])
            {
                printf("not-magic\n");
                for (int i = 0; i < dim; i++)
                {
                    free(M1[i]);
                }
                free(M1);
                fclose(f);
                return 0;
            }
        }
    }
    check(M1, dim);
    for (int i = 0; i < dim; i++)
    {
        free(M1[i]);
    }
    free(M1);
    fclose(f);
    return 0;
}