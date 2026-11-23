#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//https://projecteuler.net/problem=18

// odkaz se pise pred nazev vektoru

//mohl bych si zkopirovat cele pole a u sebe ho upravovat

//potrebuji to pole postupne prepisovat
int dynamicke_secteni(vector<vector<int>> &troj, int troj_size);

int dynamicke_secteni(vector<vector<int>> &troj, int troj_size){
    vector<vector<int>> pomocne_data;
    pomocne_data = troj;
    for (int i = 1; i < troj_size; i++){
        for (int j = 0; j < (i + 1); j++){
            if (j == 0){
                pomocne_data[i][j] = pomocne_data[i][j] + pomocne_data[i - 1][j];
            } else if (j == i){
                pomocne_data[i][j] = pomocne_data[i][j] + pomocne_data[i - 1][j - 1];

            } else{

                if (pomocne_data[i][j] + pomocne_data[i - 1][j - 1] > pomocne_data[i][j] + pomocne_data[i - 1][j]){
                    pomocne_data[i][j] = pomocne_data[i][j] + pomocne_data[i - 1][j - 1];
                } else{
                    pomocne_data[i][j] = pomocne_data[i][j] + pomocne_data[i - 1][j];
                }
            }
            
        }
    }

    vector<int> finalni_vektor = pomocne_data[troj_size - 1];
    //finalni_vektor.sort();
    sort(finalni_vektor.begin(), finalni_vektor.end());

    return finalni_vektor[troj_size - 1];

}

int main() {
    ifstream file("pub02.in");
    if (!file.is_open()) {
        cerr << "Nepodarilo se otevrit soubor!" << endl;
        return 1;
    }

    vector<vector<int>> troj;

    string line;
    while (getline(file, line)) {         // čtení po řádcích
        stringstream ss(line);            // stream z řádku
        vector<int> row;                  // jeden řádek dat
        int value;

        while (ss >> value) {             // čtení čísel z řádku
            row.push_back(value);
        }

        troj.push_back(row);              // přidání řádku do 2D pole
    }

    // // výpis výsledku
    // for (const auto& row : troj) {
    //     for (int v : row) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    //cout << "Pocet prvku " << troj.size() << endl;

    int troj_size = troj.size();

    cout << dynamicke_secteni(troj, troj_size) << endl;

    file.close();  // zavření souboru (není nutné, volá se i v destruktoru)
    return 0;
}

