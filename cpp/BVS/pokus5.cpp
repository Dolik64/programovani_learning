#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct XNode {
    int key;
    bool deleted;
    int edge_distance; // Hranová vzdálenost od kořene
    XNode* left;
    XNode* right;
    XNode(int k, int dist) : key(k), deleted(false), edge_distance(dist), left(nullptr), right(nullptr) {}
};

int tree_depth = 0; // Globální proměnná pro maximální hloubku stromu
int sum_deleted_heights = 0; // Součet výšek smazaných uzlů
int sum_undeleted_heights = 0; // Součet výšek nesmazaných uzlů

void update_tree_depth(int new_depth) {
    if (new_depth > tree_depth) {
        int depth_increase = new_depth - tree_depth;
        sum_deleted_heights += depth_increase * sum_deleted_heights;
        sum_undeleted_heights += depth_increase * sum_undeleted_heights;
        tree_depth = new_depth;
    }
}

void insert(XNode*& root, int data, int edge_distance = 0) {
    int node_height = tree_depth - edge_distance; // Výška uzlu
    
    if (root == nullptr) {
        // Vytvoříme nový uzel, pokud strom tuto hodnotu neobsahuje
        root = new XNode(data, edge_distance);
        update_tree_depth(edge_distance); 
        sum_undeleted_heights += node_height; // Aktualizujeme součet výšek nesmazaných uzlů
    } else if (data < root->key) {
        insert(root->left, data, edge_distance + 1);
    } else if (data > root->key) {
        insert(root->right, data, edge_distance + 1);
    } else {
        // Pokud klíč existuje a je smazaný, obnovíme ho
        if (root->deleted) {
            root->deleted = false; // Obnovíme uzel
            sum_deleted_heights -= node_height; // Odečteme jeho výšku ze smazaných
            sum_undeleted_heights += node_height; // Přidáme jeho výšku do nesmazaných
        }
        // Pokud klíč existuje a není smazaný, neprovádíme žádnou změnu
    }

    // Kontrola, zda volat Compact
    if (sum_deleted_heights > sum_undeleted_heights) {
        Compact(root);
    }
}

void lazy_delete(XNode* root, int data) {
    if (root == nullptr) {
        return;
    } else if (data < root->key) {
        lazy_delete(root->left, data);
    } else if (data > root->key) {
        lazy_delete(root->right, data);
    } else if (!root->deleted) {
        int node_height = tree_depth - root->edge_distance; // Výška uzlu
        root->deleted = true;
        sum_undeleted_heights -= node_height; // Odečteme výšku z nesmazaných
        sum_deleted_heights += node_height;   // Přičteme výšku ke smazaným
    }

    // Kontrola, zda volat Compact
    if (sum_deleted_heights > sum_undeleted_heights) {
        Compact(root);
    }
}

// Deklarace funkce Compact
void Compact(XNode*& root) {
    // Implementaci přidáme později
    cout << "Volá se funkce Compact k přebudování stromu.\n";
}

int main() {
    XNode* root = nullptr;

    insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 10); // Tento insert by měl jen obnovit uzel s hodnotou 10, pokud byl smazaný

    cout << "Aktuální hloubka stromu: " << tree_depth << endl;
    cout << "Součet výšek nesmazaných uzlů: " << sum_undeleted_heights << endl;
    cout << "Součet výšek smazaných uzlů: " << sum_deleted_heights << endl;

    return 0;
}
