//druhy_cyklus
//kontrola coding stylu

#include <stdio.h>

int main() {
    int cislo1, cislo2;
    int num_items_read;  // Pocet uspesne prectenych polozek

    num_items_read = scanf("%d", &cislo1);

    if (num_items_read != 1) {
        printf("Chyba při čtení prvního čísla.\n");
        return 1;
    }

    num_items_read = scanf("%d", &cislo2);

    if (num_items_read != 1) {
        printf("Chyba při čtení druhého čísla.\n");
        return 1;
    }
    if ((cislo1 < -10000 || cislo1 > 10000) || (cislo2 < -10000 || cislo2 > 10000)) {
        fprintf(stderr,"Error: Vstup je mimo interval!\n");
        return 100;
        
    }



    return 0;
    }
    