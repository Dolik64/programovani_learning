//end_of_transmission
//nejdriv nacitam dokud nenastane chyba
#include <stdio.h>

int main() {
    int cislo;
    int pocet_cisel = 0;
    


    while (scanf("%d", &cislo) != EOF) {
        pocet_cisel++;
        printf("Hodnota %d: %d\n", pocet_cisel, cislo);
    }

    printf("Konec vstupu.\n");
    
    return 0;
}