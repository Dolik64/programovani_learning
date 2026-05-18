//double
#include <stdio.h>
int main() {
   int cislo_a = 5;
   int cislo_b = 2;
   int presnost  = 1;
   int soucet = (int) cislo_a + cislo_b;
   //float vysledek = (float)cislo_a/cislo_b;
   //printf( "%f\n", vysledek);
   double prumer = (double) soucet / 2;
   float prumer_2 = (float) soucet / 2;
   //int podil = (int)cislo_a/cislo_b;
   printf("%f\n", prumer);
   printf("%.*f\n", presnost, prumer_2);
   return 0;
}
//