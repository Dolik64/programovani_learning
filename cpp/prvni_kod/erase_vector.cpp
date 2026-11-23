#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    v.erase(v.begin() + 2); // smaže třetí prvek (30)

    for (int x : v) {
        cout << x << " ";
    }
    // Výstup: 10 20 40
}
