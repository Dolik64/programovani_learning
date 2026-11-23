//pole1
//neumim zatim nacist hodnoty z souboru in
#include <stdio.h>

int main() {
    int values[1000]; // Předpokládáme maximálně 1000 hodnot
    int num_values = 0;
    int first_value = 1; // Proměnná pro sledování prvního vypsání

    printf("Zadejte hodnoty a potvrďte Ctrl+D pro ukončení:\n");

    while (scanf("%d", &values[num_values]) != EOF) {
        num_values++;
    }

    printf("Načtené hodnoty:\n");
    for (int i = 0; i < num_values; i++) {
        if (!first_value) {
            printf(", ");
        } else {
            first_value = 0; // Nastavíme na 0 po prvním vypsání
        }
        printf("%d", values[i]);
    }
    printf("\n");

    return 0;
}

/*printf("%d\n", pozice_v_poli);*/
    /*printf("%d\n", i);*/

    /*printf("%d", values[pozice_v_poli]);*/
    //int prodentualni_podil = 0;
    // nula neni kladna
    //#define PROCENTO_KLADNYCH (int procento_kladnych = )
    //if (POSLEDNI_VSTUP)

  /*  maximalni_hodnota = pole[0];
        if (POSLEDNI_VSTUP > maximalni_hodnota) {
            maximalni_hodnota = POSLEDNI_VSTUP;
        }*/
