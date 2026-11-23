#include <stdio.h>

// Funkce, která pracuje s ukazatelem
void zvys_hodnotu(int* cislo) {
    *cislo += 10;  // Zvyšuje hodnotu o 10 pomocí dereference ukazatele
}

int main() {
    int hodnota = 5;

    printf("Původní hodnota: %d\n", hodnota);

    // Předáme adresu proměnné, aby se změna projevila přímo v 'main'
    zvys_hodnotu(&hodnota);

    printf("Hodnota po volání funkce: %d\n", hodnota);

    return 0;
}
