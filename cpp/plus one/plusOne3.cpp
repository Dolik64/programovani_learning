#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int index_last = digits.size() - 1;
            int index_calloc = index_last;
    
            while(index_last != -1){
                if (digits[index_last] == 9){
                    digits[index_last] = 0;
                    index_last -= 1;
                } else {
                    digits[index_last] += 1;
                    return digits;
                }
            }
    
            digits.insert(digits.begin(), 1);
            for (int j = 1; j <= index_calloc +1; j++){
                digits[j] = 0;
            }
            return digits;
    
        
                
        }
    };

    int main() {
        Solution sol;
        vector<int> nums = {2, 0, 1, 5};
        vector<int> nums_final = sol.plusOne(nums);
        //cout << plusOne(nums) << endl;
        for (const int& val : nums_final) {
            cout << val << " ";
        }
        cout << endl;
        return 0;
    }