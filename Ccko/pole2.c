//pole2

#include <stdio.h>

#define PREDPOSLEDNI_VSTUP (pole[pocet_hodnot - 2])
#define POSLEDNI_VSTUP (pole[pocet_hodnot - 1])
#define PROCENTO_KLADNYCH (((float)(100) / pocet_hodnot) * kladna_cisla)
#define PROCENTO_ZAPORNYCH (((float)(100) / pocet_hodnot) * zaporna_cisla)
#define PRUMER ((float)(soucet) / pocet_hodnot)
#define PROCENTO_SUDYCH (((float)(100) / pocet_hodnot) * pocet_sudych)
#define PROCENTO_LICHYCH (((float)(100) / pocet_hodnot) * pocet_lichych)

int main() {
    int pole[1000]; // Predpokladame maximalne 1000 hodnot
    int pocet_hodnot = 0; //udava pocet platnych hodnot v poli
    int kladna_cisla = 0;
    int zaporna_cisla = 0;
    int soucet = 0;
    int pocet_sudych = 0;
    int pocet_lichych = 0;
    int procento_sudych = 0;
    int procento_lichych = 0;
    int prumer = 0;
    int minimalni_hodnota = 0;
    int maximalni_hodnota = 0;


    while (scanf("%d", &pole[pocet_hodnot]) != EOF) {
        pocet_hodnot++;

        if (POSLEDNI_VSTUP < -10000 || POSLEDNI_VSTUP > 10000){
            for (int i = 0; i < (pocet_hodnot - 2); i++) {
                printf("%d, ", pole[i]);
            }
            printf("%d\n", PREDPOSLEDNI_VSTUP);
            fprintf(stdout,"Error: Vstup je mimo interval!\n");
            return 100;
        }
        if (POSLEDNI_VSTUP > 0) {
            kladna_cisla++;
        }
        if (POSLEDNI_VSTUP < 0) {
            zaporna_cisla++;
        }
        if (POSLEDNI_VSTUP %2 == 0) {
            pocet_sudych++;
        }
        else {
            pocet_lichych++;
        }
        soucet += POSLEDNI_VSTUP;
    } 


    

    
    for (int i = 0; i < (pocet_hodnot - 1); i++) { //vypisuje postupne hodnoty
        printf("%d, ", pole[i]);
    }

    maximalni_hodnota = pole[0]; // Predpokladame, ze prvni prvek je maximalni
    for (int i = 1; i < pocet_hodnot; i++) {
        if (pole[i] > maximalni_hodnota) {
            maximalni_hodnota = pole[i];
        }
    }
    
    minimalni_hodnota = pole[0]; 
    for (int i = 1; i < pocet_hodnot; i++) {
        if (pole[i] < minimalni_hodnota) {
            minimalni_hodnota = pole[i];
        }
    }

    printf("%d\n", POSLEDNI_VSTUP);
    printf("Pocet cisel: %d\n", pocet_hodnot);
    printf("Pocet kladnych: %d\n", kladna_cisla);
    printf("Pocet zapornych: %d\n", zaporna_cisla);
    printf("Procento kladnych: %.*f\n",2,PROCENTO_KLADNYCH);
    printf("Procento zapornych: %.*f\n",2,PROCENTO_ZAPORNYCH);
    printf("Pocet sudych: %d\n", pocet_sudych);
    printf("Pocet lichych: %d\n", pocet_lichych);
    printf("Procento sudych: %.*f\n",2,PROCENTO_SUDYCH);
    printf("Procento lichych: %.*f\n",2,PROCENTO_LICHYCH);
    printf("Prumer: %.*f\n",2,PRUMER);
    printf("Maximum: %d\n", maximalni_hodnota);
    printf("Minimum: %d\n", minimalni_hodnota);

    return 0;
}
