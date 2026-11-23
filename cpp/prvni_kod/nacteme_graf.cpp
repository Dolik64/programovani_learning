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

int main(){
    int pocet_vrcholu, pocet_hran;
    
    
    //chci udelat vektor, ktery bude obsahovat vsechny hrany
    std::vector<std::pair<int, int>> hrany;


    std::ifstream inputFile("g1_1.in");  // Otevře soubor input.txt
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