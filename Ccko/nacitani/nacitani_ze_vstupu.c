//nacitani_ze_vstupu
#include <stdio.h>
int main() {

    int cislo_a;
    int cislo_b;

    scanf("%d", &cislo_a);
    scanf("%d", &cislo_b);
    if (cislo_a < -10000 || cislo_a > 10000){
        fprintf(stderr,"Error: Vstup je mimo interval!\n");
        return 100;
    }
    if (cislo_b < -10000 || cislo_b > 10000){
        fprintf(stderr,"Error: Vstup je mimo interval!\n");
        return 100;
    }
    int soucet = (int) cislo_a + cislo_b;
    int rozdil = (int) cislo_a - cislo_b;
    int soucin = (int) cislo_a * cislo_b;
    if (cislo_b == 0) {
        printf("Desitkova soustava: %d %d\n",cislo_a,cislo_b);
        printf("Sestnactkova soustava: %x %x\n",cislo_a,cislo_b);
        printf("Soucet: %d + %d = %d\n",cislo_a,cislo_b,soucet);
        printf("Rozdil: %d + %d = %d\n",cislo_a,cislo_b,rozdil);
    }
    else {
        int podil = (int) cislo_a/cislo_b;
        printf("Desitkova soustava: %d %d\n",cislo_a,cislo_b);
        printf("Sestnactkova soustava: %x %x\n",cislo_a,cislo_b);
        printf("Soucet: %d + %d = %d\n",cislo_a,cislo_b,soucet);
        printf("Rozdil: %d + %d = %d\n",cislo_a,cislo_b,rozdil);
        return 0;
    }
    
}