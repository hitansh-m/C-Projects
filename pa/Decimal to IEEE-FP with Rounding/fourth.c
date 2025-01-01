#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

static unsigned long x(unsigned long a, int b, int c, int d, int e)
{
    if (c == 0)
        return a;
    int f = (int)(a & 1);
    if (c == 1)
    {
        if (d == 1 || e == 1)
        {
            a++;
        }
        else
        {
            if (f == 1)
                a++;
        }
    }
    return a;
}

int main(int a, char *b[])
{
    if (a != 2)
    {
        return 1;
    }
    FILE *c = fopen(b[1], "r");
    if (!c)
    {
        return 1;
    }

    double d;
    int e, f, g;
    while (fscanf(c, "%lf %d %d %d", &d, &e, &f, &g) == 4)
    {
        int h = 0;
        if (d < 0.0)
        {
            h = 1;
            d = -d;
        }

        if (d == 0.0)
        {
            int i;
            printf("%d", h);
            for (i = 1; i < e; i++)
                printf("0");
            printf("\n");
            continue;
        }
        int j = 0;
        double k = d;
        while (k >= 2.0)
        {
            k /= 2.0;
            j++;
        }
        while (k < 1.0)
        {
            k *= 2.0;
            j--;
        }

        int B = (1 << (f - 1)) - 1;
        int E_biased = j + B;

        if (E_biased <= 0)
        {
            double m = d * pow(2.0, (double)(B - 1));
            int extra = 3;
            int total = g + extra;
            unsigned long frac = 0UL;
            double tmp = m;
            for (int z = 0; z < total; z++)
            {
                tmp *= 2.0;
                if (tmp >= 1.0)
                {
                    frac = (frac << 1) | 1;
                    tmp -= 1.0;
                }
                else
                {
                    frac = (frac << 1) | 0;
                }
            }
            unsigned long M = frac >> 3;
            int G = (frac >> 2) & 1;
            int R = (frac >> 1) & 1;
            int S = frac & 1;
            M = x(M, g, G, R, S);
            if (M == (1UL << g))
            {
                M = (1UL << g) - 1;
            }
            unsigned long Rf = 0UL;
            Rf |= ((unsigned long)h << (f + g));
            Rf |= (0UL << g);
            Rf |= M;
            for (int bit = e - 1; bit >= 0; bit--)
            {
                printf("%d", (int)((Rf >> bit) & 1));
            }
            printf("\n");
        }
        else
        {
            double n = k - 1.0;
            int extra = 3;
            int total = g + extra;
            unsigned long frac = 0UL;
            double tmp = n;
            for (int z = 0; z < total; z++)
            {
                tmp *= 2.0;
                if (tmp >= 1.0)
                {
                    frac = (frac << 1) | 1;
                    tmp -= 1.0;
                }
                else
                {
                    frac = (frac << 1) | 0;
                }
            }
            unsigned long M = frac >> 3;
            int G = (frac >> 2) & 1;
            int R = (frac >> 1) & 1;
            int S = frac & 1;
            M = x(M, g, G, R, S);

            if (M == (1UL << g))
            {
                M = 0UL;
                E_biased++;
            }

            unsigned long Rf = 0UL;
            Rf |= ((unsigned long)h << (f + g));
            Rf |= ((unsigned long)E_biased << g);
            Rf |= M;

            for (int bit = e - 1; bit >= 0; bit--)
            {
                printf("%d", (int)((Rf >> bit) & 1));
            }
            printf("\n");
        }
    }

    fclose(c);
    return 0;
}