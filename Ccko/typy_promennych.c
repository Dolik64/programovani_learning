//typy_promennych
#include <stdio.h>
int main() {
   int cislo_a = 5;
   int cislo_b = 2;

   float vysledek = (float)cislo_a/cislo_b;
   //printf( "%f\n", vysledek);
   cislo_a = 212;
   cislo_b = -78;

   int podil = (int)cislo_a/cislo_b;
   printf("%d\n", podil);
   return 0;
}