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

    long val;
    int w;
    char src, dst;
    while (fscanf(fp, "%ld %d %c %c", &val, &w, &src, &dst) == 4) {
        unsigned long mask = ((unsigned long)1 << w) - 1;
        unsigned long bits;
        if (src == 'u') {
            bits = (unsigned long)val & mask;
        } else {
            long signed_val = val;
            bits = (unsigned long)(signed_val & (long)mask);
        }

        long result;
        if (dst == 'u') {
            result = (long)(bits & mask);
        } else {
            unsigned long sign_bit = (unsigned long)1 << (w - 1);
            if (bits & sign_bit) {
                long temp = (long)bits;
                long shift = 64 - w; // assuming 64-bit long
                result = (temp << shift) >> shift;
            } else {
                result = (long)bits;
            }
        }

        printf("%ld\n", result);
    }

    fclose(fp);
    return 0;
}