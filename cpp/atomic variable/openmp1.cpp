#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>

using namespace std;

// Typ definující matici (vektor vektorů)
typedef vector<vector<double>> Matrix;

// 1. Paralelizace vnitřní smyčky pomocí reduction
// Pouze pro sadu s malým počtem velmi dlouhých vektorů.
void vector_sum_internal(const Matrix& data, vector<double>& solution) {
    solution.resize(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        double sum = 0.0;
        // Paralelizace smyčky, která projde prvky jednoho vektoru
        #pragma omp parallel for reduction(+:sum)
        for (size_t j = 0; j < data[i].size(); ++j) {
            sum += data[i][j];
        }
        solution[i] = sum;
    }
}

// 2. Paralelizace vnější smyčky s dynamickým plánováním
// Vhodné, když délky jednotlivých vektorů značně kolísají.
void vector_sum_external_dynamic(const Matrix& data, vector<double>& solution) {
    solution.resize(data.size());
    #pragma omp parallel for schedule(dynamic)
    for (size_t i = 0; i < data.size(); ++i) {
        double sum = 0.0;
        for (size_t j = 0; j < data[i].size(); ++j) {
            sum += data[i][j];
        }
        solution[i] = sum;
    }
}

// 3. Paralelizace vnější smyčky se statickým plánováním
// Vhodné pro sadu s velkým počtem malých konstantně velkých vektorů.
void vector_sum_external_static(const Matrix& data, vector<double>& solution) {
    solution.resize(data.size());
    #pragma omp parallel for schedule(static)
    for (size_t i = 0; i < data.size(); ++i) {
        double sum = 0.0;
        for (size_t j = 0; j < data[i].size(); ++j) {
            sum += data[i][j];
        }
        solution[i] = sum;
    }
}

// 4. Podmíněná paralelizace pomocí klauzule if
// Pokud je počet vektorů nad danou hranicí (threshold), paralelizujeme,
// jinak se provádí sekvenční verze.
void vector_sum_conditional(const Matrix& data, vector<double>& solution, size_t threshold) {
    solution.resize(data.size());
    #pragma omp parallel for if(data.size() > threshold)
    for (size_t i = 0; i < data.size(); ++i) {
        double sum = 0.0;
        for (size_t j = 0; j < data[i].size(); ++j) {
            sum += data[i][j];
        }
        solution[i] = sum;
    }
}

// Hlavní funkce pro otestování implementací
int main() {
    // Vytvoření testovacích dat: 1000 vektorů o délce 10000, každý prvek má hodnotu 1.0
    Matrix data;
    const size_t numVectors = 1000;
    const size_t vectorSize = 10000;
    data.resize(numVectors, vector<double>(vectorSize, 1.0));

    vector<double> solution;

    // Měření času pomocí std::chrono
    auto start = chrono::high_resolution_clock::now();
    vector_sum_internal(data, solution);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Interní paralelizace s reduction trvala: " << duration.count() << " sekund." << endl;

    start = chrono::high_resolution_clock::now();
    vector_sum_external_dynamic(data, solution);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Externí paralelizace s dynamickým plánováním trvala: " << duration.count() << " sekund." << endl;

    start = chrono::high_resolution_clock::now();
    vector_sum_external_static(data, solution);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Externí paralelizace se statickým plánováním trvala: " << duration.count() << " sekund." << endl;

    // Nastavení prahu pro podmíněnou paralelizaci (např. 500 vektorů)
    start = chrono::high_resolution_clock::now();
    vector_sum_conditional(data, solution, 500);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Podmíněná paralelizace trvala: " << duration.count() << " sekund." << endl;

    return 0;
}

//clang++ -Xpreprocessor -fopenmp openmp1.cpp -lomp -o openmp1

//clang++ -std=c++11 -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include openmp1.cpp -L/opt/homebrew/opt/libomp/lib -lomp -o openmp1