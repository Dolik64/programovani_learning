
#include <stdio.h>

int main() {
    int volba = 0;
    int a, b;

    while (volba != 5) {
        printf("\n--- KALKULACKA ---\n");
        printf("1 - Scitani\n");
        printf("2 - Odcitani\n");
        printf("3 - Nasobeni\n");
        printf("4 - Deleni\n");
        printf("5 - Konec\n");

        printf("Vyber operaci: ");
        scanf("%d", &volba);

        if (volba >= 1 && volba <= 4) {
            printf("Zadej dve cisla: ");
            scanf("%d %d", &a, &b);
        } else {
            if (volba != 5) {
                printf("Neplatna volba!\n");
            }
        }

        switch (volba) {
            case 1:
                printf("Vysledek: %d\n", a + b);
                break;

            case 2:
                printf("Vysledek: %d\n", a - b);
                break;

            case 3:
                printf("Vysledek: %d\n", a * b);
                break;

            case 4:
                if (b != 0) {
                    printf("Vysledek: %.2f\n", (float)a / b);
                } else {
                    printf("Chyba: Deleni nulou!\n");
                }
                break;

            case 5:
                printf("Ukoncuji program.\n");
                break;

            default:
                break;
        }
    }

    return 0;
}
