#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void hex_to_decimal(int total_bits, int exp_bits, int frac_bits, unsigned int hex, int precision) {
    int sign = (hex >> (total_bits - 1)) & 1;
    int exponent = (hex >> frac_bits) & ((1 << exp_bits) - 1);
    unsigned int mantissa = hex & ((1 << frac_bits) - 1);

    int bias = (1 << (exp_bits - 1)) - 1;
    double value;

    if (exponent == 0) {
        value = mantissa / (double)(1 << frac_bits);
        exponent = 1 - bias;
    } else {
        value = 1.0 + mantissa / (double)(1 << frac_bits);
        exponent -= bias;
    }

    value *= pow(2, exponent);
    if (sign) value = -value;

    printf("%.*f\n", precision, value);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./eighth <input file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    int total_bits, exp_bits, frac_bits, precision;
    unsigned int hex;
    while (fscanf(file, "%d %d %d 0x%x %d", &total_bits, &exp_bits, &frac_bits, &hex, &precision) == 5) {
        hex_to_decimal(total_bits, exp_bits, frac_bits, hex, precision);
    }

    fclose(file);
    return 0;
}