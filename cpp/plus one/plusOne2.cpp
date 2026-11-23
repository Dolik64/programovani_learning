#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int index_last = digits.size() - 1;
            bool enlarge = true;
    
            //vektor je zvetsen pouze ve chvili kdy to jsou 9
            for (int i = 0; i <= index_last; i++){
                if (digits[i] !=9){
                    enlarge = false;
                    break;
                }
            }
    
            if (enlarge){
                //enlarge = false;
                // vector<int> nuly(index_last + 2, 0);
                // nuly[0] = 1;
                // return nuly;
                //break;
                //uint8_t
                //implace
    
                digits.insert(digits.begin(), 1);
                for (int j = 1; j <= index_last +1; j++){
                    digits[j] = 0;
                }
                return digits;
    
            }
                    
    
            //pokud se vektor nebude zvetsovat
            while(true){
                if (digits[index_last] == 9){
                    digits[index_last] = 0;
                    index_last -= 1;
                } else {
                    digits[index_last] += 1;
                    return digits;
                }
            }
                    
    
    
            
        }
    };

    int main() {
        Solution sol;
        vector<int> nums = {2, 0, 1, 5};
        vector<int> nums_final = sol.plusOne(nums);
        //cout << plusOne(nums) << endl;
        for (const int& val : nums_final) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        return 0;
    }