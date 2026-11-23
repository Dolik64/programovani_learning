#include <iostream>
#include <vector>
#include <utility> // Pro std::pair

int main() {
    int N = 5;  // Velikost vektoru

    // Inicializace vektoru velikosti N s výchozí hodnotou (0, 0)
    std::vector<std::pair<int, int>> hrany(N);

    // Výpis obsahu vektoru
    for (int i = 0; i < N; ++i) {
        std::cout << "Hrana " << i << ": (" << hrany[i].first << ", " << hrany[i].second << ")" << std::endl;
    }

    // Možnost změny hodnot
    for (int i = 0; i < N; ++i) {
        hrany[i] = std::make_pair(i, i + 1);
    }

    // Výpis aktualizovaného obsahu vektoru
    std::cout << "Po aktualizaci:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "Hrana " << i << ": (" << hrany[i].first << ", " << hrany[i].second << ")" << std::endl;
    }

    return 0;
}
