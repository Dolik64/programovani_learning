//ctvrty_pokus

#include <stdio.h>

int main() {
    int number;
    int total = 0;
    int positive = 0;
    int negative = 0;
    int even = 0;
    int odd = 0;
    int max = -10001; // Initiate with a value out of range
    int min = 10001;  // Initiate with a value out of range
    double sum = 0;

    printf("Zadejte cisla [-10000; 10000], ukoncete s neplatnym vstupem:\n");

    while (scanf("%d", &number) == 1) {
        if (number >= -10000 && number <= 10000) {
            total++;
            if (number > 0) {
                positive++;
            } else if (number < 0) {
                negative++;
            }
            if (number % 2 == 0) {
                even++;
            } else {
                odd++;
            }
            if (number > max) {
                max = number;
            }
            if (number < min) {
                min = number;
            }
            sum += number;

            if (total > 1) {
                printf(", ");
            }
            printf("%d", number);
        } else {
            printf("\nError: Vstup je mimo interval!\n");
            return 100;
        }
    }

    printf("\n\nStatistika:\n");
    printf("Pocet nactenych cisel: %d\n", total);
    printf("Pocet kladnych cisel: %d\n", positive);
    printf("Pocet zapornych cisel: %d\n", negative);
    printf("Procentualni podil kladnych cisel: %.2f%%\n", (positive / (double)total) * 100);
    printf("Procentualni podil zapornych cisel: %.2f%%\n", (negative / (double)total) * 100);
    printf("Pocet sudych cisel: %d\n", even);
    printf("Pocet lichych cisel: %d\n", odd);
    printf("Procentualni podil sudych cisel: %.2f%%\n", (even / (double)total) * 100);
    printf("Procentualni podil lichych cisel: %.2f%%\n", (odd / (double)total) * 100);
    printf("Prumer cisel: %.2f\n", sum / total);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}
