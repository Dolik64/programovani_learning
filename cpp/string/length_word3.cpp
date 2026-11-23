#include <bits/stdc++.h>
#include <string>
using namespace std;




class Solution {
    public:
        int lengthOfLastWord(string s) {
            int length = s.size() - 1;  //ukazatel na poslendi prvek
            //int space_check = length;
            //bool spaces = false;
            int counter = 0;
    
            // if (s.size() == 1){
            //     return 1;
            // }
    
            //pokud cele slovo neobsahuje mezeru
            // for (int i = 0; i <= space_check; i++){
            //     if (s[i] == ' '){
            //         spaces = true;
            //         break;
            //     }
            // }
            // if (spaces == false){
            //     return space_check + 1;
            // }
    
            //odstranim znaky vzadu
            while (true){
                if (s[length] == ' '){
                    length -= 1;
                } else{
                    break;
                }
            }
            
    
    
            
            while (true){
                if (s[length] == ' '){
                    return counter;
                }    
                else if (length == 0){
                    return counter + 1;
                }else{
                    length -= 1;
                    counter += 1;
                }
            }
        }
    };


    int main() {
        Solution sol;
        string vstup = "Hello World   ";
        int delka = sol.lengthOfLastWord(vstup);
        cout << delka << endl;
        return 0;
    }