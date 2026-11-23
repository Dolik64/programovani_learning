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
    std::vector<int> vektor(10);
    vektor[5] = 59;
    
    for (int i = 0; i < vektor.size(); i++){
        std::cout << vektor[i] << " ";
    }
}