//write topological ordering fnc cpp

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack, const vector<vector<int>> &adj) {
    visited[v] = true;

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, Stack, adj);
        }
    }

    Stack.push(v);
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v) where u -> v:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> Stack;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }

    cout << "Topological Sort: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;

    return 0;
}

// Example input:
// 6 6
// 5 2
// 5 0
// 4 0
// 4 1
// 2 3
// 3 1

// Example output:
// Topological Sort: 5 4 2 3 1 0


//compile with: g++ -std=c++17 topolgicke_ocislovani.cpp -o topological_sort
