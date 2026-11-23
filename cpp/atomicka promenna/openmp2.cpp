#include <iostream>
#include <omp.h>

int main() {
    // Vytvoření paralelní oblasti
    #pragma omp parallel
    {
        // Získání čísla vlákna a počtu vláken
        int thread_id = omp_get_thread_num();    //
        int total_threads = omp_get_num_threads();
        std::cout << "Hello from thread " << thread_id 
                  << " out of " << total_threads << std::endl;
    }
    return 0;
}
//g++ -std=c++17 -fopenmp openmp2.cpp -o openmp2