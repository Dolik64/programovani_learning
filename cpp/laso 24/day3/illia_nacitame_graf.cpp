#pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC target("avx2")

#include <iostream>
#include <vector>
#include <string>
#include <utility>   //tady je pair
#include <fstream>   //tady je ifstream
#include <limits.h>
#include <chrono>
#include <queue>

using namespace std;

int nacti_vazeny_graf(std::vector<std::vector<std::pair<int, int>>>& graf, int& pocet_vrcholu, int& pocet_hran);
void dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graf, int start, std::vector<int>& vzdalenosti, int pocet_vrcholu);
void uloz_vzdalenosti_do_souboru(const std::vector<int>& vzdalenosti, const std::string& nazev_souboru);

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("graphweighted.txt", "r", stdin);
    freopen("vzdalenosti.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
    int pocet_vrcholu, pocet_hran;
    
    //toto struktura grafu
    std::vector<std::vector<std::pair<int, int>>> graf;
    std::vector<int> vzdalenosti;

    nacti_vazeny_graf(graf, pocet_vrcholu, pocet_hran);
    dijkstra(graf, 0, vzdalenosti, pocet_vrcholu);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Doba trvání: " << duration.count() << " ms" << std::endl;

    uloz_vzdalenosti_do_souboru(vzdalenosti, "vzdalenosti.txt");
    //./tvuj_program < input.txt    to je k nicemu pouzivat std::ifstream
    return 0;
}

int nacti_vazeny_graf(std::vector<std::vector<std::pair<int, int>>>& graf, int& pocet_vrcholu, int& pocet_hran) {
    // std::ifstream inputFile("graphweighted.txt");  // Otevře soubor
    

    // if (!inputFile) {
    //     std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
    //     return 1;
    // }

    cin >> pocet_vrcholu >> pocet_hran;

    // Inicializace grafu (vektor o velikosti počtu vrcholů)
    graf.resize(pocet_vrcholu);

    for (int i = 0; i < pocet_hran; i++) {
        int vrchol1, vrchol2, vaha_hrany;
        cin >> vrchol1 >> vrchol2 >> vaha_hrany;
        // Přidání sousedů a jejich váhy k oběma vrcholům (graf je neorientovaný)
        graf[vrchol1].push_back({vrchol2, vaha_hrany});
        graf[vrchol2].push_back({vrchol1, vaha_hrany});
    }

    return 0;
}

void dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graf, int start, std::vector<int>& vzdalenosti, int pocet_vrcholu) {
    // Počet vrcholů v grafu
    
    // Inicializace vzdáleností na nekonečno
    vzdalenosti.resize(pocet_vrcholu, std::numeric_limits<int>::max());

    // Použijeme haldu pro efektivní výběr vrcholu s nejmenší vzdáleností
    // (minimální halda: páry {vzdálenost, vrchol})
    std::priority_queue<std::pair<int, int> > pq;

    // Vzdálenost k počátečnímu vrcholu je 0
    vzdalenosti[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        // Získejte vrchol s nejmenší vzdáleností
        auto [current_vzdalenost, current_vrchol] = pq.top();
        pq.pop();
        if (-current_vzdalenost != vzdalenosti[current_vrchol]) continue;

        // Pro každý soused aktuálního vrcholu zkontrolujte, zda neexistuje kratší cesta
        for (const auto& soused : graf[current_vrchol]) {
            int sousedni_vrchol = soused.first;
            int vaha_hrany = soused.second;

            // Nová vzdálenost do souseda
            int nova_vzdalenost = -current_vzdalenost + vaha_hrany;

            // Pokud je nalezena kratší cesta, aktualizujte vzdálenost a přidejte do haldy
            if (nova_vzdalenost < vzdalenosti[sousedni_vrchol]) {
                vzdalenosti[sousedni_vrchol] = nova_vzdalenost;
                pq.push({-nova_vzdalenost, sousedni_vrchol});
            }
        }
    }
}

// Funkce pro uložení vzdáleností do souboru
void uloz_vzdalenosti_do_souboru(const std::vector<int>& vzdalenosti, const std::string& nazev_souboru) {
    // std::ofstream outputFile(nazev_souboru);
    // if (!outputFile) {
    //     std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
    //     return;
    // }

    for (size_t i = 0; i < vzdalenosti.size(); ++i) {
        cout << vzdalenosti[i] << std::endl;
    }

    // outputFile.close();
}