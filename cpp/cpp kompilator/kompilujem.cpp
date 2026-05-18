//chci kod v cpp ktery vezme vektor a vypise ho
//kompilujem.cpp
#include <iostream>
#include <vector>
using namespace std;

void vypis(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    vypis(v);
    return 0;
}