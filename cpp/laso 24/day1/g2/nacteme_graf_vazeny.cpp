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
#include <tuple>

int main(){
    int pocet_vrcholu, pocet_hran;
    
    
    //chci udelat vektor, ktery bude obsahovat vsechny hrany
    std::vector<std::tuple<int, int, int>> hrany_vektor;


    std::ifstream inputFile("g2_1.in");  // Otevře soubor input.txt
    if (!inputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return 1;
    }
    //nactu prvni radek
    inputFile >> pocet_vrcholu >> pocet_hran;
    //nactu zbytek radku
    for (int i = 0; i < pocet_hran; i++){
        int vrchol1, vrchol2, vaha;
        inputFile >> vrchol1 >> vrchol2 >> vaha;
        hrany_vektor.push_back(std::make_tuple(vrchol1, vrchol2, vaha));
    }

    /*
    //chci vypsat do jedne slozene zavorky mensi zavorky, kdy kazda z mensich zavorek bude obsahovat hranu tvorenou dvema vrcholy
    //tedy chci vypsat vsechny hrany
    std::cout << "{"; 
    for (int i = 0; i < hrany.size(); i++){
        std::cout << "(" << hrany[i].first << ", " << hrany[i].second << ")";
        if (i != hrany.size() - 1){
            std::cout << ", ";
        }
    }
    */

   
    //nyni mam vektor a v nem pairy vsech hran
    //chci vypsat cely vektor


    /*
    for (const auto& hrana : hrany){
        std::cout << hrana.first << " " << hrana.second << std::endl;
    }
    */


    //./tvuj_program < input.txt    to je k nicemu pouzivat std::ifstream

    // nyni chci ke kazdemu uzlu napsat jeho seznam hran
    // tedy ja mam pocet uzlu to je cislo
    // kazdy uzel chci napsat cislem, potom dve podtrzitka a potom vrcholy, ktere jsou s nim spojeny
    // pojdme nyni nepouzivat mapu ani set, ale budeme prochazet ten vektor poporade
    for (int i = 0; i < pocet_vrcholu; i++){
        std::cout << i << "__  ";
        for (const auto& hrana : hrany_vektor){
            if (std::get<0>(hrana) == i){
                std::cout << std::get<1>(hrana)<< "  ";
            }
            if (std::get<1>(hrana) == i){
                std::cout << std::get<0>(hrana) << "  ";
            }
        }
        std::cout << std::endl;
    }


} 