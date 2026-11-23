#include <bits/stdc++.h>
using namespace std;

/*
  Tarjanův algoritmus (O(N + M))
  --------------------------------
  Vstup: orientovaný graf v podobě adjacency listu (0-index).
  Výstup: seznam silně souvislých komponent; každá komponenta je vektor vrcholů.

  Poznámky:
  - vrcholy uvnitř jedné SCC vracíme v pořadí nalezení (pop ze zásobníku),
    případně si je setřiďte dle potřeby.
  - Pokud chcete 1-indexovaný vstup, odečtěte při načítání hrany 1.
*/

struct TarjanSCC {
    int n;
    const vector<vector<int>>& g;
    vector<int> indexOf, lowlink;
    vector<char> onstack;
    vector<int> st;
    int timer = 0;
    vector<vector<int>> comps;

    TarjanSCC(const vector<vector<int>>& graph)
        : n((int)graph.size()), g(graph),
          indexOf(n, -1), lowlink(n, -1), onstack(n, 0) {}

    void dfs(int v) {
        indexOf[v] = lowlink[v] = timer++;
        st.push_back(v);
        onstack[v] = 1;

        for (int to : g[v]) {
            if (indexOf[to] == -1) {
                dfs(to);
                lowlink[v] = min(lowlink[v], lowlink[to]);
            } else if (onstack[to]) {
                lowlink[v] = min(lowlink[v], indexOf[to]);
            }
        }

        // kořen SCC
        if (lowlink[v] == indexOf[v]) {
            vector<int> comp;
            while (true) {
                int w = st.back(); st.pop_back();
                onstack[w] = 0;
                comp.push_back(w);
                if (w == v) break;
            }
            comps.push_back(move(comp));
        }
    }

    vector<vector<int>> run() {
        for (int v = 0; v < n; ++v)
            if (indexOf[v] == -1)
                dfs(v);
        return comps;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Příklad načtení: N vrcholů, M hran, poté M řádků "u v" pro hranu u->v (0-index).
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    TarjanSCC tarjan(adj);
    auto sccs = tarjan.run();

    // Výpis: počet komponent a jejich obsah
    cout << sccs.size() << "\n";
    for (const auto& comp : sccs) {
        // volitelně: setřídit pro deterministický výstup
        // auto c = comp; sort(c.begin(), c.end());
        for (size_t i = 0; i < comp.size(); ++i) {
            cout << comp[i] << (i + 1 == comp.size() ? '\n' : ' ');
        }
    }
    return 0;
}
// input example:
// 8 10
// 0 1
// 1 2
// 2 0
// 3 1
// 3 2
// 3 4
// 4 5
// 5 3
// 6 5
// 6 7
// 7 6
// output example:
// 3
// 6 7
// 3 5 4
// 0 2 1    


//chyba inputu je tam kravina


// input example:
// 8 11
// 0 1
// 1 2
// 2 0
// 3 1
// 3 2
// 3 4
// 4 5
// 5 3
// 6 5
// 6 7
// 7 6