#include <iostream>
#include <utility>  // Pro std::pair a std::make_pair

int main() {
    // Vytvoření páru pomocí make_pair
    std::pair<int, std::string> p = std::make_pair(1, "Ahoj");

    std::cout << "První prvek: " << p.first << '\n';
    std::cout << "Druhý prvek: " << p.second << '\n';

    return 0;
}
