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
        // Pokud se zvyšuje hloubka, přičteme k oběma součtům za každý uzel
        int depth_increase = new_depth - tree_depth;
        sum_deleted_heights += depth_increase * sum_deleted_heights;
        sum_undeleted_heights += depth_increase * sum_undeleted_heights;
        tree_depth = new_depth;
    }
}

void insert(XNode*& root, int data, int edge_distance = 0) {
    int node_height = tree_depth - edge_distance; // Výška uzlu
    
    if (root == nullptr) {
        root = new XNode(data, edge_distance);
        update_tree_depth(edge_distance); 
        sum_undeleted_heights += node_height; // Aktualizujeme součet výšek nesmazaných uzlů
    } else if (data < root->key) {
        insert(root->left, data, edge_distance + 1);
    } else if (data > root->key) {
        insert(root->right, data, edge_distance + 1);
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
}

// Funkce Compact by zde musela přestavět strom a poté aktualizovat oba součty

int main() {
    XNode* root = nullptr;

    insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);
    lazy_delete(root, 4);
    lazy_delete(root, 6);

    cout << "Aktuální hloubka stromu: " << tree_depth << endl;
    cout << "Součet výšek nesmazaných uzlů: " << sum_undeleted_heights << endl;
    cout << "Součet výšek smazaných uzlů: " << sum_deleted_heights << endl;

    return 0;
}
