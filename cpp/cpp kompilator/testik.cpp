#include <vector>
#include <iostream>

int main() {
    // Tohle v C++98 (starý standard) nešlo! 
    // Vyžadovalo to právě ten flag -std=c++11
    std::vector<int> cisla = {1, 2, 3, 4, 5}; 

    for (auto n : cisla) { // Klíčové slovo 'auto' je taky z C++11
        std::cout << n << " ";
    }
    return 0;
}