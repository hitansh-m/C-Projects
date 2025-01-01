#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    unsigned long num;
    int w;
    while (fscanf(fp, "%lu %d", &num, &w) == 2) {
        unsigned long mask = ((unsigned long)1 << w) - 1;
        unsigned long val = num & mask; 

        char *bin = (char *)malloc(w+1);
        if (!bin) {
            fprintf(stderr, "Memory error\n");
            fclose(fp);
            return 1;
        }
        bin[w] = '\0';

        for (int i = w - 1; i >= 0; i--) {
            bin[i] = (val & 1) ? '1' : '0';
            val >>= 1;
        }

        printf("%s\n", bin);
        free(bin);
    }

    fclose(fp);
    return 0;
}