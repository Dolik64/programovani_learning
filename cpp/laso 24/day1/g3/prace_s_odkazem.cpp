#include <iostream>

// Funkce, která pracuje s odkazem
void zvys_hodnotu(int& cislo) {
    cislo += 10;  // Zvyšuje hodnotu o 10
}

int main() {
    int hodnota = 5;

    std::cout << "Původní hodnota: " << hodnota << std::endl;

    // Předáme proměnnou odkazem, takže se změní přímo v 'main'
    zvys_hodnotu(hodnota);

    std::cout << "Hodnota po volání funkce: " << hodnota << std::endl;

    return 0;
}
