#include <iostream>
#include <stack>  // Pro použití std::stack
#include <vector>
#include <map>     //co je to mapa
#include <set>     //co je to set
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <utility>   //tady je pair
#include <fstream>   //tady je ifstream

int main() {
    // Definice zásobníku, který bude obsahovat celočíselné hodnoty
    std::stack<int> zasobnik;
    std::pair<std::string, int> pair;  //tady je pair

    std::ifstream inputFile("seq.txt");  // Otevře soubor input.txt
    if (!inputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return 1;
    }

    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return 1;
    }

    while (inputFile >> pair.first) {
        //inputFile >> pair.first >> pair.second;

        if (pair.first == "insert"){
            inputFile >> pair.second;
            zasobnik.push(pair.second);
            outputFile << pair.first << " " << pair.second << std::endl;
        }
        else{
            zasobnik.pop();
            outputFile << pair.first << std::endl;
        }
        
        if (inputFile.fail()) {
            std::cerr << "Chyba: Nepodařilo se načíst data ze souboru!" << std::endl;
            return 1;
        }
    }


    

    return 0;
}
