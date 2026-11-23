#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    // Příklad pole s hodnotami od 1 do 100
    std::vector<int> data(100);
    for (int i = 0; i < 100; ++i) {
        data[i] = i + 1;
    }
    
    int sum = 0;
    // Paralelizovaný for cyklus se sčítáním
    #pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < data.size(); ++i) {
        sum += data[i];
    }
    
    std::cout << "Celkový součet: " << sum << std::endl;
    return 0;
}
//g++ -std=c++17 -fopenmp openmp3.cpp -o openmp3