#include <iostream>
#include <tuple>
#include <vector>
#include <string>
//using namespace std;

int main() {
    // Vytvoření tuple s třemi hodnotami
    std::tuple<int, double, std::string> tento_tupl(1, 3.14, "Hello");

    // Přístup k hodnotám tuple pomocí std::get
    std::cout << "Tuple obsahuje: " << std::endl;
    std::cout << "Integer: " << std::get<0>(tento_tupl) << std::endl;
    std::cout << "Double: " << std::get<1>(tento_tupl) << std::endl;
    std::cout << "String: " << std::get<2>(tento_tupl) << std::endl;

    // Vektor tuple
    std::vector<std::tuple<int, double, std::string>> vec;
    vec.push_back(std::make_tuple(2, 2.71, "World"));
    vec.push_back(std::make_tuple(3, 1.61, "C++"));

    // Iterace přes vektor a výpis hodnot
    std::cout << "\nObsah vektoru tuple: " << std::endl;
    for (const auto& t : vec) {
        std::cout << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << std::endl;
    }

    return 0;
}
