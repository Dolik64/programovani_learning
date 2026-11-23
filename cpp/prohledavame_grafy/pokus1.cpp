#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int nacti_graf_ze_souboru(std::vector<std::pair<int, int>>& hrany, int& pocet_vrcholu, int& pocet_hran);
int vytvor_seznam_sousedu(std::vector<std::vector<int>>& seznam_sousedu, const std::vector<std::pair<int, int>>& hrany, int pocet_vrcholu);
int nacti_graf_ze_vstupu(std::vector<std::pair<int, int>>& hrany, int& pocet_vrcholu, int& pocet_hran);
void vypis_2D_vektor(const std::vector<std::vector<int>>& vektor);
void bfs(int start, const std::vector<std::vector<int>>& seznam_sousedu, std::vector<bool>& navstiveno);
int spocti_komponenty(const std::vector<std::vector<int>>& seznam_sousedu, std::vector<bool>& navstiveno);
void vytvor_dot_soubor(const std::vector<std::vector<int>>& seznam_sousedu, const std::string& filename);

int main() {
    std::vector<std::pair<int, int>> hrany;
    int pocet_vrcholu, pocet_hran;
    
    std::vector<std::vector<int>> seznam_sousedu;

    std::vector<bool> navstiveno(pocet_vrcholu + 1, false);

    //nacti_graf_ze_souboru(hrany, pocet_vrcholu, pocet_hran);
    nacti_graf_ze_vstupu(hrany, pocet_vrcholu, pocet_hran);
    vytvor_seznam_sousedu(seznam_sousedu, hrany, pocet_vrcholu);
    vypis_2D_vektor(seznam_sousedu);

    int pocet_komponent = spocti_komponenty(seznam_sousedu, navstiveno);
    std::cout << std::endl << "Pocet komponent: " << pocet_komponent << std::endl;

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
