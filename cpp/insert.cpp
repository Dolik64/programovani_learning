#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {2, 3, 4};

    v.insert(v.begin(), 1); // vloží 1 na začátek

    for (int x : v) {
        cout << x << " ";
    }
    // Výstup: 1 2 3 4
}
