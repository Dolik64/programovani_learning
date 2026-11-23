#include <iostream>
#include <vector>

int main() {
   
  std::vector<double> subway_adult = {800, 1200, 1500};
  std::vector<int> vec(2, 0); //tohle vytvori vektor kde jsou 2 nuly
  //vector<int> nums = {2, 0, 1, 5};

  //vec = {0, 0};
  
  // Give subway_child some values:
  
  std::vector<double> subway_child;
  int size = subway_adult.size();
  vec[0] = 3;
  vec[1] = 4;

  for (const int& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    
}