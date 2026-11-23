#include <iostream>
#include <map>
using namespace std;

int main() {
    // Deklarace mapy, kde klíčem je int a hodnotou string
    map<int, string> mojeMapa;

    // Přidání dvojic klíč-hodnota
    mojeMapa[1] = "Jedna";
    mojeMapa[2] = "Dva";
    mojeMapa[3] = "Tři";

    // Přístup k hodnotě přes klíč
    cout << "Klíč 2 má hodnotu: " << mojeMapa[2] << endl;

    // Iterace přes mapu a výpis všech klíčů a hodnot
    for (const auto& par : mojeMapa) {
        cout << "Klíč: " << par.first << ", Hodnota: " << par.second << endl;
    }

    //vypis mapy
    cout << "Obsah mapy: " << endl;
    for (const auto& par : mojeMapa) {
        cout << "Klíč: " << par.first << ", Hodnota: " << par.second << endl;
    }

    return 0;
}
