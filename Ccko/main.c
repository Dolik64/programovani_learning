//nacitani_ze_vstupu22

#include <stdio.h>
#include <stdlib.h>
int main() {

    int cislo_a;
    int cislo_b;
    int presnost  = 1;

    scanf("%d", &cislo_a);
    scanf("%d", &cislo_b);
    if (cislo_a < -10000 || cislo_a > 10000){
        fprintf(stderr,"Error: Vstup je mimo interval!\n");
        return 100;
        exit;
    }
    if (cislo_b < -10000 || cislo_b > 10000){
        fprintf(stderr,"Error: Vstup je mimo interval!\n");
        return 100;
        exit;
    }
    int soucet = (int) cislo_a + cislo_b;
    int rozdil = (int) cislo_a - cislo_b;
    int soucin = (int) cislo_a * cislo_b;
    float prumer = (float) soucet / 2;
    fprintf(stdout,"Desitkova soustava: %d %d\n",cislo_a,cislo_b);
    fprintf(stdout,"Sestnactkova soustava: %x %x\n",cislo_a,cislo_b);
    fprintf(stdout,"Soucet: %d + %d = %d\n",cislo_a,cislo_b,soucet);
    fprintf(stdout,"Rozdil: %d - %d = %d\n",cislo_a,cislo_b,rozdil);
    fprintf(stdout,"Soucin: %d * %d = %d\n",cislo_a,cislo_b,soucin);
    if (cislo_b == 0) {
        fprintf(stdout,"Podil: %d / %d = Nan\n",cislo_a,cislo_b);
        fprintf(stdout,"Prumer: %.*f\n",presnost,prumer);
        fprintf(stderr,"Error: Nedefinovany vysledek!\n");
        return 101;
        exit;
    }
    else {
        int podil = (int) cislo_a/cislo_b;
        fprintf(stdout,"Podil: %d / %d = %d\n",cislo_a,cislo_b,podil);
        fprintf(stdout,"Prumer: %.*f\n",presnost,prumer);
        return 0;
    }
    
}
//