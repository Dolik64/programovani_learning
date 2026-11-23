//https://projecteuler.net/problem=15

//dulezita informace zaciname v levem hornim rohu a koncime v pravem dolnim
//dulezita informace, borec se muze pohybovat jen dolu a do prava

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define POCET_HRAN_20X20 840
#define POCET_HRAN_2X2 12

#define CTVERECKY_STRANA 2
#define VRCHOLY_STRANA (CTVERECKY_STRANA + 1)

#define POCET_VRCHOLU 9





int vypocet_hran_ze_ctverecku(int ctverecky_size);
void topological_sort_util(int v, vector<bool> &visited, stack<int> &Stack, const vector<vector<int>> &adj);

int vypocet_hran_ze_ctverecku(int ctverecky_size){
    int vrcholy_size = ctverecky_size + 1;

    int pocet_hran = (((vrcholy_size -1) * vrcholy_size) *2);

    return pocet_hran;
}

// int main(){
//     cout << vypocet_hran_ze_ctverecku(20) << endl;

//     return 0;
// }

///////////////////////////////////////////////////////////

void topological_sort_util(int v, vector<bool> &visited, stack<int> &Stack, const vector<vector<int>> &adj) {
    visited[v] = true;

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            topological_sort_util(neighbor, visited, Stack, adj);
        }
    }

    Stack.push(v);
}



int main(){

    // vrcholy indexuji od 0

    int n, m;

    //n = VRCHOLY_STRANA;  //3
    n = POCET_VRCHOLU; //9
    m = POCET_HRAN_2X2;
    

    vector<vector<int>> adj(n);
    
    //smer dolu
    for (int i = 0; i < POCET_VRCHOLU - VRCHOLY_STRANA; i++){
        adj[i].push_back(i + VRCHOLY_STRANA);
    }

    //smer doprava
    for (int j = 0; j < POCET_VRCHOLU; j++){
        if (((j + 1) % VRCHOLY_STRANA) == 0){
            //tady jsem mel chybu ze jsem to neuzavorkoval
            continue;
        } else {
            adj[j].push_back(j + 1);
        }
    }


    stack<int> Stack;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topological_sort_util(i, visited, Stack, adj);
        }
    }

    cout << "Topological Sort: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;

}

//Topological Sort: 0 1 2 3 4 5 6 7 8 