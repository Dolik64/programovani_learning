
#include <bits/stdc++.h>
#include <vector>
using namespace std;


bool opakuji_se_fnc(vector<int>& nums);
int minimumOperations(vector<int>& nums);

int main(){
    vector<int> nums{4,5,6,4,4};
    cout<<minimumOperations(nums);

}
        
        bool opakuji_se_fnc(vector<int>& nums){
            bool opakuji_se = false;
            if (nums.size() == 0){
                return false;
            }
            for (int i = 0; i < nums.size(); i++){
                for (int j = i + 1; j < nums.size(); j++){
                    if (nums[i] == nums[j]){
                        opakuji_se = true;
                        return opakuji_se;
                    }
                }
            }
            return opakuji_se;

        }

        int minimumOperations(vector<int>& nums) {
            int minimum_number = 0;
            while (true){
                if (opakuji_se_fnc(nums) == false){
                    return minimum_number;
                } else {
                    minimum_number++;
                    if (nums.size() >= 3){
                        nums.erase(nums.begin() + 0);
                        nums.erase(nums.begin() + 0);
                        nums.erase(nums.begin() + 0);
                    }else if (nums.size() == 2){
                        nums.erase(nums.begin() + 0);
                        nums.erase(nums.begin() + 0);
    
                    } else{
                        nums.erase(nums.begin() + 0);
                    }
    
                    
                }
            }
    
        }
