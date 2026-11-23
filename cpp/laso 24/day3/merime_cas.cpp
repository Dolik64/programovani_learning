#include <iostream>
#include <chrono>

int main() {
    // Uložení začátku měření
    auto start = std::chrono::high_resolution_clock::now();

    // Váš kód zde (např. nějaký časově náročný algoritmus)
    for (int i = 0; i < 1000000; i++);

    // Uložení konce měření
    auto end = std::chrono::high_resolution_clock::now();

    // Výpočet rozdílu času v mikrosekundách
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Doba trvání: " << duration.count() << " ms" << std::endl;

    return 0;
}
