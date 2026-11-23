#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    //n = 12343;
    int counter = 0;
    cin>>n;
    while (n != 0){
        counter++;
        n = n / 10;
    };
    cout<<counter;


    //jsem
}
