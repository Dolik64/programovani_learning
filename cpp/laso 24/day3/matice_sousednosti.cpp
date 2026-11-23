//prvni radek vstupu obsahuje dve cela cisla oddelena mezerou - pocet vrcholu a pocet hran grafu
//kazdy radek reprezentuje jednu hranu grafu

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


void vypis_graf_vektorem(std::vector<std::pair<int, int>> hrany);
void vypis_graf_do_radku(std::vector<std::pair<int, int>> hrany);
void ke_kazdemu_uzlu_vypis_hrany(std::vector<std::pair<int, int>> hrany, int pocet_vrcholu);
int nacti_graf_nevazeny(std::vector<std::pair<int, int>>& hrany, int& pocet_vrcholu, int& pocet_hran);
void kazdy_stupen_pocet_hran_s_koncovymi_stupni(std::vector<std::pair<int, int>> hrany, std::map<int, int>& mapa_vrcholu_a_stupnu, std::map<int, int>& mapa_stupnu_a_hrany_kde_oba_konce_maji_stupen, int pocet_vrcholu);
void vypis_mapu(std::map<int, int> mapa);
int nacti_vazeny_graf(std::vector<std::vector<int>>& hrany_s_vahou, int& pocet_vrcholu, int& pocet_hran);
//nacti graf je jedina fce ktera meni hodnotu vektoru hrany, proto ji musim predat referenci, take meni pocet vrcholu a pocet hran, proto je predavam referenci

int main(){
    int pocet_vrcholu, pocet_hran;
    int maximalni_stupen = 0;
    int minimalni_stupen = 0;
    
    //chci udelat vektor, ktery bude obsahovat vsechny hrany
    std::vector<std::pair<int, int>> hrany;

    //toto je matice sousednosti
    std::vector<std::vector<int>> matice_sousednosti;

    //toto bude vektor, obsahujici dalse vektory, ktere budou obsahovat hrany, reprezentovane jako dvojice cisel a vaha hrany
    //kazdy podvektor tedy bude obsahovat tri cisla
    std::vector<std::vector<int>> hrany_s_vahou;

    //chci udelat mapu, ktera bude obsahovat stupen kazdeho vrcholu klic je cislo vrcholu a hodnota je stupen tohoto vrcholu
    std::map<int, int> mapa_vrcholu_a_stupnu;

    //chci udelat mapu, ktera bude obsahovat pocet hran, ktere maji oba konce s danym stupnem, klicem je stupen a hodnotou pocet hran
    std::map<int, int> mapa_stupnu_a_hrany_kde_oba_konce_maji_stupen;


    nacti_graf_nevazeny(hrany, pocet_vrcholu, pocet_hran);

    vypis_graf_vektorem(hrany);
    
    //ke_kazdemu_uzlu_vypis_hrany(hrany, pocet_vrcholu);

    kazdy_stupen_pocet_hran_s_koncovymi_stupni(hrany, mapa_vrcholu_a_stupnu, mapa_stupnu_a_hrany_kde_oba_konce_maji_stupen, pocet_vrcholu);
    
    //./tvuj_program < input.txt    to je k nicemu pouzivat std::ifstream
    return 0;
}

int nacti_vazeny_graf(std::vector<std::vector<int>>& hrany_s_vahou, int& pocet_vrcholu, int& pocet_hran){
    std::ifstream inputFile("g3_3.in");  // Otevře soubor input.txt
    if (!inputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return 1;
    }
    //nactu prvni radek
    
    inputFile >> pocet_vrcholu >> pocet_hran;
    //nactu zbytek radku
    for (int i = 0; i < pocet_hran; i++){
        int vrchol1, vrchol2, vaha_hrany;
        inputFile >> vrchol1 >> vrchol2 >> vaha_hrany;
        hrany_s_vahou.push_back({vrchol1, vrchol2, vaha_hrany});
    }
    return 0;
}

int vytvor_matici_sousednosti_vazeneho_grafu(std::vector<std::vector<int>> hrany_s_vahou, std::vector<std::vector<int>>& matice_sousednosti, int pocet_vrcholu, int pocet_hran){
    //nyni chci vytvorit matici sousednosti pro vazeny graf
    // kde hrana neni bude 0
    // kde hrana je bude vaha hrany

}

void vypis_graf_vektorem(std::vector<std::pair<int, int>> hrany){

    //chci vypsat do jedne slozene zavorky mensi zavorky, kdy kazda z mensich zavorek bude obsahovat hranu tvorenou dvema vrcholy
    //tedy chci vypsat vsechny hrany
    //nyni mam vektor a v nem pairy vsech hran
    //chci vypsat cely vektor

    std::cout << "{"; 
    for (int i = 0; i < hrany.size(); i++){
        std::cout << "(" << hrany[i].first << ", " << hrany[i].second << ")";
        if (i != hrany.size() - 1){
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}

void vypis_graf_do_radku(std::vector<std::pair<int, int>> hrany){

    //vypis_graf_do_radku(hrany);
    for (const auto& hrana : hrany){
        std::cout << hrana.first << " " << hrana.second << std::endl;
    }
}

void ke_kazdemu_uzlu_vypis_hrany(std::vector<std::pair<int, int>> hrany, int pocet_vrcholu){

    // nyni chci ke kazdemu uzlu napsat jeho seznam hran
    // tedy ja mam pocet uzlu to je cislo
    // kazdy uzel chci napsat cislem, potom dve podtrzitka a potom vrcholy, ktere jsou s nim spojeny
    // pojdme nyni nepouzivat mapu ani set, ale budeme prochazet ten vektor poporade

    for (int i = 0; i < pocet_vrcholu; i++){
        std::cout << i << "__  ";
        for (const auto& hrana : hrany){
            if (hrana.first == i){
                std::cout << hrana.second << "  ";
            }
            if (hrana.second == i){
                std::cout << hrana.first << "  ";
            }
        }
        std::cout << std::endl;
    }
}

int nacti_graf_nevazeny(std::vector<std::pair<int, int>>& hrany, int& pocet_vrcholu, int& pocet_hran){
    std::ifstream inputFile("g3_3.in");  // Otevře soubor input.txt
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

void vypis_mapu(std::map<int, int> mapa){
    std::cout << "Vypis mapy" << std::endl;
    for (const auto& par : mapa) {
        std::cout << "Klíč: " << par.first << ", Hodnota: " << par.second << std::endl;
    }
}

void kazdy_stupen_pocet_hran_s_koncovymi_stupni(std::vector<std::pair<int, int>> hrany, std::map<int, int>& mapa_vrcholu_a_stupnu, std::map<int, int>& mapa_stupnu_a_hrany_kde_oba_konce_maji_stupen, int pocet_vrcholu){

     //nyni potrebuji pro kazdy mozny stupen v grafu zjistit, kolik existuje v grafu hran, kdy oba koncove vrcholy dane hrany ma presne tento stupen
    //tedy chci pro kazdy stupen od 0 do maximalniho stupne zjistit, kolik hran v grafu ma oba konce s timto stupnem
    //ted chci udelat mapu, kde klicem cislo vrcholu a hodnotou bude stupen tohoto vrcholu

    for (int i = 0; i < pocet_vrcholu; i++){
        mapa_vrcholu_a_stupnu[i] = 0;
        for (const auto& hrana : hrany){
            if (hrana.first == i){
                mapa_vrcholu_a_stupnu[i]++;
            }
            if (hrana.second == i){
                mapa_vrcholu_a_stupnu[i]++;
            }
        }
    }
    vypis_mapu(mapa_vrcholu_a_stupnu);
    
    //nyni chci mapu, kde bude klicem stupen a hodnotou pocet hran, ktere maji oba konce s timto stupnem
    //nyni budu ve vektoru prochazet hrany a pokud oba konce hrany maji stejny stupen, tak zvetsim hodnotu v mape o 1
    
    for (const auto& hrana : hrany){
        if (mapa_vrcholu_a_stupnu[hrana.first] == mapa_vrcholu_a_stupnu[hrana.second]){
            mapa_stupnu_a_hrany_kde_oba_konce_maji_stupen[mapa_vrcholu_a_stupnu[hrana.first]]++;
        }
    }
    vypis_mapu(mapa_stupnu_a_hrany_kde_oba_konce_maji_stupen);

    //nyni chci vypsat po radcich stupen a pocet hran, kde oba konce maji tento stupen
    for (int i = 0; i < pocet_vrcholu; i++){
        if (mapa_stupnu_a_hrany_kde_oba_konce_maji_stupen[i] != 0){
            std::cout << i << " " << mapa_stupnu_a_hrany_kde_oba_konce_maji_stupen[i] << std::endl;
        } else {
            std::cout << i << " " << 0 << std::endl;
        }
    }
}