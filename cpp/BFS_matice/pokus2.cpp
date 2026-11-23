#include <vector>

using namespace std;

int main() {
    int M = 5;  // Počet řádků mřížky
    int N = 7;  // Počet sloupců mřížky
    int Rmax = 2;  // Maximální rychlost
    int directions = 4;  // Počet směrů (nahoru, dolů, doleva, doprava)

    // Vytvoření 4D matice: M x N x (Rmax+1) x 4
    vector<vector<vector<vector<bool>>>> visited(M, vector<vector<vector<bool>>>(N, vector<vector<bool>>(Rmax + 1, vector<bool>(directions, false))));

    // Zde budeš ukládat, zda byla pozice (i, j) navštívena s danou rychlostí a směrem
    // Např. pro pozici (2, 3) rychlostí 1 směrem doprava (index 1):
    visited[2][3][1][1] = true;

    return 0;
}
