#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int a, char *b[]) {
    if (a != 2) {
        return 1;
    }

    FILE *c = fopen(b[1], "r");
    if (!c) {
        return 1;
    }

    double d;
    int e;
    while (fscanf(c, "%lf %d", &d, &e) == 2) {
        if (d < 0.0) d = -d;

        if (d == 0.0) {
            printf("0.");
            for (int i=0;i<e;i++) printf("0");
            printf(" 0\n");
            continue;
        }

        int g = 0;
        double h = d;
        if (d >= 1.0) {
            while (h >= 2.0) { h /= 2.0; g++; }
            while (h < 1.0) { h *= 2.0; g--; }
        } else {
            h = d;
            g = 0;
        }
        double i = (d >= 1.0) ? (h - 1.0) : h;
        char *j = (char*)malloc(e+1);
        if (!j) { fclose(c); return 1; }
        j[e]='\0';

        double k = i;
        for (int l=0; l<e; l++) {
            k *= 2.0;
            if (k >= 1.0) {
                j[l]='1';
                k -= 1.0;
            } else {
                j[l]='0';
            }
        }

        if (d >= 1.0) {
            printf("1.%s %d\n", j, g);
        } else {
            printf("0.%s %d\n", j, g);
        }

        free(j);
    }

    fclose(c);
    return 0;
}
