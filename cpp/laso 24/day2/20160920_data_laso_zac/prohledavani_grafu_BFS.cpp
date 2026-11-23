#include <iostream>
#include <vector>
#include <map>     //co je to mapa
#include <set>     //co je to set
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <utility>   //tady je pair
#include <fstream>   //tady je ifstream
#include <queue>
using namespace std;

void nacti_sousedy(std::vector<std::vector<int>>& hlavni_vektor, int& pocet_hran, std::ifstream& inputFile);
void vypis_vektor_vektoru(std::vector<std::vector<int>>& hlavni_vektor);
void vypis_sousedu_jednoho_vrcholu(std::vector<std::vector<int>>& hlavni_vektor, int vrchol);
void BFS(std::vector<std::vector<int>>& hlavni_vektor, int vrchol);
void zapis_seznam_sousedu_do_souboru(std::vector<std::vector<int>>& hlavni_vektor);
void najdi_nejkratsi_cestu(std::vector<std::vector<int>>& hlavni_vektor, int vrchol1, int vrchol2);

int main(){
//budeme uzly nacitat do fronty
//prvni chceme naimplementovat seznam sousedu jako vektor, kde kazdy index bude predstavovat uzel a hodnota na tom indexu bude vektor sousedu
    int pocet_vrcholu, pocet_hran;
    int maximalni_stupen = 0;
    int minimalni_stupen = 0;
    

    std::ifstream inputFile("graph.txt");  // Otevře soubor input.txt
    if (!inputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return 1;
    }

    //nactu prvni radek
    inputFile >> pocet_vrcholu >> pocet_hran;
    
    std::vector<std::vector<int>> hlavni_vektor(pocet_vrcholu);
    nacti_sousedy(hlavni_vektor, pocet_hran, inputFile);

    

    //vypiseme si vektor
    //vypis_vektor_vektoru(hlavni_vektor);
    //vypis_sousedu_jednoho_vrcholu(hlavni_vektor, 0);
    BFS(hlavni_vektor, 0);
    BFS(hlavni_vektor, 1);
    BFS(hlavni_vektor, 2);
    BFS(hlavni_vektor, 3);
    BFS(hlavni_vektor, 4);
    BFS(hlavni_vektor, 5);
    zapis_seznam_sousedu_do_souboru(hlavni_vektor);
    najdi_nejkratsi_cestu(hlavni_vektor, 0, 7);
    return 0;

}

void nacti_sousedy(std::vector<std::vector<int>>& hlavni_vektor, int& pocet_hran, std::ifstream& inputFile){
        for (int i = 0; i < pocet_hran; i++){
            int vrchol1, vrchol2;
            inputFile >> vrchol1 >> vrchol2;
            hlavni_vektor[vrchol1].push_back(vrchol2);
            hlavni_vektor[vrchol2].push_back(vrchol1);
        }
    }

//vypiseme si vektor
void vypis_vektor_vektoru(std::vector<std::vector<int>>& hlavni_vektor){
    for (int i = 0; i < hlavni_vektor.size(); i++){
        std::cout << i << ": ";
        for (int j = 0; j < hlavni_vektor[i].size(); j++){
            std::cout << hlavni_vektor[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void vypis_sousedu_jednoho_vrcholu(std::vector<std::vector<int>>& hlavni_vektor, int vrchol){
    std::cout << vrchol << ": ";
    for (int i = 0; i < hlavni_vektor[vrchol].size(); i++){
        std::cout << hlavni_vektor[vrchol][i] << " ";
    }
    std::cout << std::endl;
}

void BFS(std::vector<std::vector<int>>& hlavni_vektor, int vrchol){
    std::vector<bool> navstiveno(hlavni_vektor.size(), false);
    std::queue<int> fronta;
    fronta.push(vrchol);
    navstiveno[vrchol] = true;
    while (!fronta.empty()){
        int aktualni_vrchol = fronta.front();
        fronta.pop();
        for (int i = 0; i < hlavni_vektor[aktualni_vrchol].size(); i++){
            if (!navstiveno[hlavni_vektor[aktualni_vrchol][i]]){
                fronta.push(hlavni_vektor[aktualni_vrchol][i]);
                navstiveno[hlavni_vektor[aktualni_vrchol][i]] = true;
            }
        }
    }

    /*
    //vypiseme si navstivene vrcholy
    for (int i = 0; i < navstiveno.size(); i++){
        if (navstiveno[i]){
            std::cout << i << " ";
        }
    }
    */
   // vypiseme si pocet navstivenych vrcholu
    int pocet_navstivenych = 0;
    for (int i = 0; i < navstiveno.size(); i++){
        if (navstiveno[i]){
            pocet_navstivenych++;
        }
    }
    std::cout << "Pocet navstivenych vrcholu z vrcholu " << vrchol << " je: " << pocet_navstivenych << std::endl;
}

void zapis_seznam_sousedu_do_souboru(std::vector<std::vector<int>>& hlavni_vektor){
    std::ofstream outputFile("seznam_sousedu.txt");
    for (int i = 0; i < hlavni_vektor.size(); i++){
        outputFile << i << ": ";
        for (int j = 0; j < hlavni_vektor[i].size(); j++){
            outputFile << hlavni_vektor[i][j] << " ";
        }
        outputFile << std::endl;
    }
    outputFile.close();
}

void najdi_nejkratsi_cestu(std::vector<std::vector<int>>& hlavni_vektor, int vrchol1, int vrchol2){
    //mame vektor sousedu
    //mame pocatecni vrchol a koncovy vrchol
    //chceme najit nejkratsi cestu
    //budeme pouzivat BFS
    std::vector<bool> navstiveno(hlavni_vektor.size(), false);  // Pro sledování navštívených uzlů
    std::vector<int> predchudci(hlavni_vektor.size(), -1);      // Pro uchování předchůdců na cestě
    std::queue<int> fronta;                                     // Fronta pro BFS

    // Inicializace BFS
    fronta.push(vrchol1);
    navstiveno[vrchol1] = true;

    bool nalezeno = false;

    // Spuštění BFS
    while (!fronta.empty()) {
        int aktualni_vrchol = fronta.front();
        fronta.pop();

        // Pokud jsme našli cílový vrchol, přerušíme cyklus
        if (aktualni_vrchol == vrchol2) {
            nalezeno = true;
            break;
        }

        // Procházení sousedů aktuálního vrcholu
        for (int soused : hlavni_vektor[aktualni_vrchol]) {
            if (!navstiveno[soused]) {
                fronta.push(soused);
                navstiveno[soused] = true;
                predchudci[soused] = aktualni_vrchol;  // Uložíme předchůdce
            }
        }
    }

    // Pokud jsme našli cestu
    if (nalezeno) {
        std::vector<int> cesta;
        int krok = vrchol2;

        // Rekonstrukce cesty od vrchol2 zpět k vrchol1 pomocí předchůdců
        while (krok != -1) {
            cesta.push_back(krok);
            krok = predchudci[krok];
        }

        // Otočení cesty, protože jsme ji získali od cíle k počátku
        std::reverse(cesta.begin(), cesta.end());

        // Výpis cesty
        std::cout << "Nejkratsi cesta mezi vrcholem " << vrchol1 << " a vrcholem " << vrchol2 << " je: ";
        for (int vrchol : cesta) {
            std::cout << vrchol << " ";
        }
        std::cout << std::endl;
        std::cout << "Delka cesty je: " << cesta.size() - 1 << std::endl;
    } else {
        std::cout << "Cesta mezi vrcholem " << vrchol1 << " a vrcholem " << vrchol2 << " neexistuje." << std::endl;
    }

}