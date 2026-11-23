#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int nacti_graf_ze_souboru(std::vector<std::pair<int, int>>& hrany, int& pocet_vrcholu, int& pocet_hran);
int vytvor_seznam_sousedu(std::vector<std::vector<int>>& seznam_sousedu, const std::vector<std::pair<int, int>>& hrany, int pocet_vrcholu);
int nacti_graf_ze_vstupu(std::vector<std::pair<int, int>>& hrany, int& pocet_vrcholu, int& pocet_hran);
void vypis_2D_vektor(const std::vector<std::vector<int>>& vektor);
void bfs(int start, const std::vector<std::vector<int>>& seznam_sousedu, std::vector<bool>& navstiveno);
int spocti_komponenty(const std::vector<std::vector<int>>& seznam_sousedu, std::vector<bool>& navstiveno);
void vytvor_dot_soubor(const std::vector<std::vector<int>>& seznam_sousedu, const std::string& filename);
int najdi_nejdelsi_cestu(const std::vector<std::vector<int>>& seznam_sousedu);
pair<int, int> bfs_najdi_nejdelsi(int start, const std::vector<std::vector<int>>& seznam_sousedu, vector<int>& predchudci);

int main() {
    std::vector<std::pair<int, int>> hrany;
    int pocet_vrcholu, pocet_hran;
    
    std::vector<std::vector<int>> seznam_sousedu;

    //nacti_graf_ze_souboru(hrany, pocet_vrcholu, pocet_hran);
    nacti_graf_ze_vstupu(hrany, pocet_vrcholu, pocet_hran);
    std::vector<bool> navstiveno(pocet_vrcholu + 1, false);
    vytvor_seznam_sousedu(seznam_sousedu, hrany, pocet_vrcholu);
    vypis_2D_vektor(seznam_sousedu);

    int pocet_komponent = spocti_komponenty(seznam_sousedu, navstiveno);
    std::cout << std::endl << "Pocet komponent: " << pocet_komponent << std::endl;

    // Najdeme nejdelší cestu
    int delka_nejdelsi_cesty = najdi_nejdelsi_cestu(seznam_sousedu);
    std::cout << "Delka nejdelsi cesty je: " << delka_nejdelsi_cesty << std::endl;
    vytvor_dot_soubor(seznam_sousedu, "graf.dot");
    
    return 0;
}

int nacti_graf_ze_souboru(std::vector<std::pair<int, int>>& hrany, int& pocet_vrcholu, int& pocet_hran){
    std::ifstream inputFile("input1.txt");  // Otevře soubor input.txt
    if (!inputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return 1;
    }
    //nactu prvni radek
    
    inputFile >> pocet_vrcholu >> pocet_hran;
    //nactu zbytek radku
    for (int i = 0; i < pocet_hran; i++){
        int vrchol1, vrchol2;
        inputFile >> vrchol1 >> vrchol2;
        hrany.push_back(std::make_pair(vrchol1, vrchol2));
    }
    return 0;
}

int nacti_graf_ze_vstupu(std::vector<std::pair<int, int>>& hrany, int& pocet_vrcholu, int& pocet_hran){
    std::cin >> pocet_vrcholu >> pocet_hran;
    for (int i = 0; i < pocet_hran; i++){
        int vrchol1, vrchol2;
        std::cin >> vrchol1 >> vrchol2;
        hrany.push_back(std::make_pair(vrchol1, vrchol2));
    }
    return 0;
}

int vytvor_seznam_sousedu(std::vector<std::vector<int>>& seznam_sousedu, const std::vector<std::pair<int, int>>& hrany, int pocet_vrcholu){
    seznam_sousedu.resize(pocet_vrcholu + 1);
    for (const auto& hrana : hrany){
        seznam_sousedu[hrana.first].push_back(hrana.second);
        seznam_sousedu[hrana.second].push_back(hrana.first);
    }
    return 0;
}

void vypis_2D_vektor(const std::vector<std::vector<int>>& vektor){
    for (int i = 0; i < vektor.size(); i++){
        std::cout << i << ": ";
        for (const auto& prvek : vektor[i]){
            std::cout << prvek << " ";
        }
        std::cout << std::endl;
    }
}

void bfs(int start, const std::vector<std::vector<int>>& seznam_sousedu, std::vector<bool>& navstiveno) {
    std::queue<int> fronta;
    fronta.push(start);
    navstiveno[start] = true;
    
    while (!fronta.empty()) {
        int vrchol = fronta.front();
        fronta.pop();
        std::cout << vrchol << " ";  // Vypiš vrchol aktuální komponenty
        
        // Projdi sousedy aktuálního vrcholu
        for (int soused : seznam_sousedu[vrchol]) {
            if (!navstiveno[soused]) {
                navstiveno[soused] = true;
                fronta.push(soused);
            }
        }
    }
}

int spocti_komponenty(const std::vector<std::vector<int>>& seznam_sousedu, std::vector<bool>& navstiveno) {
    int pocet_komponent = 0;
    
    for (int i = 1; i < seznam_sousedu.size(); i++) {
        if (!navstiveno[i]) {
            bfs(i, seznam_sousedu, navstiveno);
            pocet_komponent++;
        }
    }
    
    return pocet_komponent;
}

void vytvor_dot_soubor(const std::vector<std::vector<int>>& seznam_sousedu, const std::string& filename) {
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return;
    }
    
    // Záhlaví DOT souboru
    outfile << "graph G {" << std::endl;
    
    // Přidáme hrany do souboru
    for (int i = 1; i < seznam_sousedu.size(); i++) {
        for (int soused : seznam_sousedu[i]) {
            if (i < soused) {  // Vyhneme se duplikaci hran (graf je neorientovaný)
                outfile << "    " << i << " -- " << soused << ";" << std::endl;
            }
        }
    }
    
    // Uzavření DOT souboru
    outfile << "}" << std::endl;
    
    outfile.close();
    std::cout << "DOT soubor '" << filename << "' byl úspěšně vytvořen." << std::endl;
    //dot -Tpng graf.dot -o graf.png

}

// Funkce pro nalezení nejvzdálenějšího vrcholu, jeho vzdálenosti a předchůdců
pair<int, int> bfs_najdi_nejdelsi(int start, const std::vector<std::vector<int>>& seznam_sousedu, vector<int>& predchudci) {
    int n = seznam_sousedu.size();
    vector<int> vzdalenost(n, -1); // -1 znamená, že vrchol nebyl navštíven
    queue<int> fronta;
    
    fronta.push(start);
    vzdalenost[start] = 0;
    predchudci[start] = -1;  // Startovací vrchol nemá předchůdce
    
    int nejvzdalenejsi_vrchol = start;
    
    while (!fronta.empty()) {
        int vrchol = fronta.front();
        fronta.pop();
        
        // Projdi všechny sousedy vrcholu
        for (int soused : seznam_sousedu[vrchol]) {
            if (vzdalenost[soused] == -1) { // Pokud soused nebyl navštíven
                vzdalenost[soused] = vzdalenost[vrchol] + 1;
                predchudci[soused] = vrchol;  // Uložíme předchůdce
                fronta.push(soused);
                
                // Aktualizuj nejvzdálenější vrchol
                if (vzdalenost[soused] > vzdalenost[nejvzdalenejsi_vrchol]) {
                    nejvzdalenejsi_vrchol = soused;
                }
            }
        }
    }
    
    // Vracíme nejvzdálenější vrchol a jeho vzdálenost
    return {nejvzdalenejsi_vrchol, vzdalenost[nejvzdalenejsi_vrchol]};
}

// Funkce pro nalezení a výpis nejdelší cesty v grafu
int najdi_nejdelsi_cestu(const std::vector<std::vector<int>>& seznam_sousedu) {
    vector<int> predchudci(seznam_sousedu.size(), -1);

    // 1. Spustíme BFS z libovolného vrcholu (například vrchol 1)
    auto [nejvzdalenejsi_vrchol, _] = bfs_najdi_nejdelsi(1, seznam_sousedu, predchudci);
    
    // 2. Spustíme BFS z nejvzdálenějšího vrcholu, který jsme našli
    auto [koncovy_vrchol, delka_nejdelsi_cesty] = bfs_najdi_nejdelsi(nejvzdalenejsi_vrchol, seznam_sousedu, predchudci);
    
    // 3. Rekonstruujeme cestu z koncového vrcholu pomocí predchůdců
    stack<int> cesta;
    int vrchol = koncovy_vrchol;
    while (vrchol != -1) {
        cesta.push(vrchol);
        vrchol = predchudci[vrchol];
    }

    // 4. Vypíšeme cestu
    std::cout << "Nejdelší cesta vede přes vrcholy: ";
    while (!cesta.empty()) {
        std::cout << cesta.top() << " ";
        cesta.pop();
    }
    std::cout << std::endl;

    return delka_nejdelsi_cesty;
}