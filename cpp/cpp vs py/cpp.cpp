#include <iostream>
#include <chrono>
using namespace std;

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    unsigned int n = 20;  // Note: Adjust to a smaller number to prevent overflow
    auto start = chrono::high_resolution_clock::now();
    unsigned long long result = factorial(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Factorial computed in " << duration.count() << " seconds" << endl;
    return 0;
}