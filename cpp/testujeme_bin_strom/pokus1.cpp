#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Struktura pro uzel
struct Node {
    int color; // 0: bílá, 1: červená, 2: modrá
    Node* left;
    Node* right;

    Node(int c) : color(c), left(nullptr), right(nullptr) {}
};

// Funkce pro získání maximální délky řetězce
pair<int, int> get_ans(Node* v) {
    if (!v) return {0, 0}; // pokud je uzel null, vrátíme délku 0

    // Rekurzivní volání pro levého a pravého potomka
    pair<int, int> left = get_ans(v->left);
    pair<int, int> right = get_ans(v->right);

    // Inicializace délek pro stejnou a jinou barvu
    int same_color_length = 0;
    int different_color_length = 0;

    // Kontrola pro stejnou barvu
    if (v->left && v->left->color == v->color) {
        same_color_length = left.second + 1; // Přidáme délku z levého podstromu
    }
    if (v->right && v->right->color == v->color) {
        same_color_length = max(same_color_length, right.second + 1); // Přidáme délku z pravého podstromu
    }

    // Kontrola pro jinou barvu
    if (v->left && v->left->color != v->color) {
        different_color_length = left.first + 1; // Přidáme délku z levého podstromu
    }
    if (v->right && v->right->color != v->color) {
        different_color_length = max(different_color_length, right.first + 1); // Přidáme délku z pravého podstromu
    }

    return {different_color_length, same_color_length}; // Vrať délku cesty pro jinou a stejnou barvu
}

int main() {
    int N; // počet korálků
    cin >> N;

    vector<int> color(N + 1); // barevné kódy korálků (1-indexed)
    for (int i = 1; i <= N; ++i) {
        cin >> color[i];
    }

    vector<Node*> nodes(N + 1); // uzly stromu
    for (int i = 1; i <= N; ++i) {
        nodes[i] = new Node(color[i]);
    }

    // Vektory pro levé a pravé potomky
    vector<int> left(N + 1);
    vector<int> right(N + 1);

    // BFS pro konstrukci binárního stromu
    queue<int> q;
    q.push(1); // počínáme od kořene
    int ptr = 2; // ukazatel na další uzel
    while (!q.empty() && ptr <= N) {
        int v = q.front();
        q.pop();

        // Přiřazení levého a pravého potomka
        left[v] = ptr;
        right[v] = ptr + 1;

        // Přidání potomků do fronty, pokud existují
        if (ptr <= N) {
            q.push(left[v]);
            ptr++;
        }
        if (ptr <= N) {
            q.push(right[v]);
            ptr++;
        }
    }

    // Přiřazení ukazatelů levých a pravých potomků
    for (int i = 1; i <= N; ++i) {
        if (left[i] <= N) nodes[i]->left = nodes[left[i]];
        if (right[i] <= N) nodes[i]->right = nodes[right[i]];
    }

    // Zavolání funkce a získání výsledku
    pair<int, int> result = get_ans(nodes[1]); // kořen stromu
    int max_length = max(result.first, result.second); // maximální délka

    // Výstup
    cout << max_length << endl;

    // Uvolnění paměti
    for (int i = 1; i <= N; ++i) {
        delete nodes[i];
    }

    return 0;
}
