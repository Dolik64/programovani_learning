#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int counter;
    //jsi kokot
    cin>>n;
    if (n == 0){
        counter = 1;
    } else {
        while (n != 0){
        counter++;
        n = n / 10;
        };

    }
    
    
    cout<<counter;

}
