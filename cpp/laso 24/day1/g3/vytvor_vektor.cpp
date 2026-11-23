#include <iostream>
#include <vector>

int main() {
    // Definice vektoru obsahujícího celočíselné hodnoty
    std::vector<int> vektor;

    // Přidání prvků do vektoru
    vektor.push_back(10);
    vektor.push_back(20);
    vektor.push_back(30);

    // Výpis prvků vektoru
    for (int i = 0; i < vektor.size(); ++i) {
        std::cout << vektor[i] << " ";
    }

    return 0;
}
