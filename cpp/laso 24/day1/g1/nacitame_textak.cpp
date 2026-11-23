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
    int prvni_radek, druhy_radek, treti_radek, ctvrty_radek;


    std::ifstream inputFile("nacitame.in");  // Otevře soubor input.txt
    if (!inputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return 1;
    }

    inputFile >> prvni_radek >> druhy_radek >> treti_radek >> ctvrty_radek;
    std::cout << prvni_radek << " " << druhy_radek << " " << treti_radek << " " << ctvrty_radek << std::endl;

    /*
    Ano, chápeš to správně. Když použiješ inputFile >> pro načtení dat ze souboru, návratový bod čtečky souboru se automaticky
     posune na začátek dalšího řádku (nebo k další položce). To znamená, že každé
      další použití >> pokračuje v čtení od místa, kde se zastavil předchozí příkaz.
    */
}