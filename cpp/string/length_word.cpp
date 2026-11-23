#include <bits/stdc++.h>
#include <string>
using namespace std;




class Solution {
    public:
        int lengthOfLastWord(string s) {
            int length = s.size() - 1;  //ukazatel na poslendi prvek
            int counter = 0;

            //chybi tam osetreni situace kdy 
            //odstranim znaky vzadu
            while (true){
                if (s[length] == ' '){
                    length -= 1;
                } else{
                    break;
                }
            }
            while (true){
                if (s[length] == ' ' || length == 0){
                    return counter;
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