#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool checkPrime(int x)
{
    if (x < 2)
    {
        return false;
    }
    if (x == 2)
    {
        return true;
    }

    if (x % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i <= (int)sqrt(x); i += 2)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool check(int x)
{
    if (x<0){
        return false;
    }
    x = abs(x);
    if (x == 0 || x == 1) {
        return false;
    }

    while (x > 0)
    {
        if (!checkPrime(x))
        {
            return false;
        }
        x /= 10; 
    }

    return true;
}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    int val;
    fscanf(f, "%d", &val);

    for (int i = 0; i < val; i++)
    {
        int x;
        fscanf(f, "%d", &x);

        if (check(x))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }

    fclose(f);
    return 0;
}
