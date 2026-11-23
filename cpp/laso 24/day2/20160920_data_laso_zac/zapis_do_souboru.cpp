#include <iostream>
#include <fstream>

int main() {
    // Vytvoření objektu ofstream pro zápis do souboru
    std::ofstream outputFile("output.txt");

    // Zkontroluj, jestli se soubor otevřel správně
    if (!outputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return 1;
    }

    // Zápis textu do souboru
    outputFile << "První řádek textu" << std::endl;
    outputFile << "Druhý řádek textu" << std::endl;

    // Zavření souboru
    outputFile.close();

    std::cout << "Zápis do souboru byl úspěšný!" << std::endl;
    
    return 0;
}
