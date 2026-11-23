#include <iostream>
#include <vector>
#include <queue>

//mali zaba rychlost R pak pak z pole F1 skoci a dopadne na F2R + 1
 
using namespace std;

struct Cell {
    int x; // Souřadnice X
    int y; // Souřadnice Y
    int R; // Údaj Rychlost
    int D; // Údaj Direction
};
 
void print_grid(const vector<vector<int>>& grid);
void bfs(queue<pair<int, int>>& fronta_BFS, const vector<vector<int>>& grid, int startX, int startY, int R, int S);

int main() {
    int R, S, Max_speed;
    cin >> R >> S >> Max_speed;

    // Vytvoření matice
    vector<vector<int>> grid(R, vector<int>(S));

    // Fronta pro BFS, začínáme na startovní pozici
    queue<pair<int, int>> fronta_BFS;
 
    // nacteni matice
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < S; ++j) {
            cin >> grid[i][j];
        }
    }

    // vypis matice
    //print_grid(grid);

    bfs(fronta_BFS, grid, 0, 0, R, S);

    cout << "" << endl;

    vector<vector<Cell>> pomocna_matice(R, vector<Cell>(S));
}    

void print_grid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void bfs(queue<pair<int, int>>& fronta_BFS, const vector<vector<int>>& grid, int startX, int startY, int R, int S) {
    
    // Pohyby nahoru, dolů, doleva, doprava (4 sousedi)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    fronta_BFS.push({startX, startY});
    
    // Navštívené buňky
    vector<vector<bool>> visited(R, vector<bool>(S, false));
    visited[startX][startY] = true;
    
    // BFS algoritmus
    while (!fronta_BFS.empty()) {
        int x = fronta_BFS.front().first;
        int y = fronta_BFS.front().second;
        fronta_BFS.pop();
        
        cout << "Navštívená buňka: (" << x << ", " << y << ") s hodnotou: " << grid[x][y] << endl;
        
        // Prozkoumej 4 sousedy
        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            
            // Zkontroluj, jestli je nová pozice v matici a nebyla navštívena
            if (newX >= 0 && newX < R && newY >= 0 && newY < S && !visited[newX][newY]) {
                visited[newX][newY] = true;
                fronta_BFS.push({newX, newY});
            }
        }
    }
}

