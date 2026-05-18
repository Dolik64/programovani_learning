#include <iostream>
#include <vector>
#include <sstream>
#include <queue>  
#include <set>    

int jedna_instance(int pocet_hodu);

int main(){
    int soucet_cisel = 0;
    //vypis do terminalu s pouzitim funkce jedna_instance

    std::cout << "Soucet cisel: " << jedna_instance(10) << std::endl;
    std::cout << "Soucet cisel: " << jedna_instance(10000) << std::endl;
    std::cout << "Soucet cisel: " << jedna_instance(1000000) << std::endl;
}

int jedna_instance(int pocet_hodu){
    int soucet_cisel = 0;
    //random cislo od 1 do 6
    srand(time(0));
    for(int i = 0; i < pocet_hodu; i++){
        int cislo = rand() % 6 + 1;
        soucet_cisel += cislo;
    }
    return soucet_cisel;
}
