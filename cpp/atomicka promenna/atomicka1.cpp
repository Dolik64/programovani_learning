#include <iostream>
#include <thread>
#include <atomic>

// Sdílená atomická proměnná
std::atomic<int> counter(0);

// Funkce, kterou spouští každé vlákno
void incrementCounter(int increments) {
    for (int i = 0; i < increments; ++i) {
        counter++; // atomická operace
    }
}

int main() {
    std::thread t1(incrementCounter, 10000); //musim pridelit funkci kterou chci spustit
    std::thread t2(incrementCounter, 10000);

    t1.join();
    t2.join();

    // Výsledek by měl být přesně 20000
    std::cout << "Konečná hodnota counteru: " << counter.load() << std::endl;

    return 0;
}

//g++ -std=c++17 -pthread atomicka1.cpp -o atomicka1
