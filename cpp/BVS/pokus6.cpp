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

// Globální proměnné
int tree_depth = 0; // Maximální hloubka stromu
int sum_deleted_heights = 0; // Součet výšek smazaných uzlů
int sum_undeleted_heights = 0; // Součet výšek nesmazaných uzlů

// Deklarace funkcí
void update_tree_depth(int new_depth);
void calculate_tree_depth(XNode* node, int depth);
void collect_keys_preorder(XNode* node, vector<int>& keys);
void delete_tree(XNode* node);
void insert(XNode*& root, int data, int edge_distance = 0);
void lazy_delete(XNode* root, int data);
void Compact(XNode*& root);

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

// Implementace funkcí

void update_tree_depth(int new_depth) {
    if (new_depth > tree_depth) {
        int depth_increase = new_depth - tree_depth;
        sum_deleted_heights += depth_increase * sum_deleted_heights;
        sum_undeleted_heights += depth_increase * sum_undeleted_heights;
        tree_depth = new_depth;
    }
}

// Funkce pro přepočet maximální hloubky stromu
void calculate_tree_depth(XNode* node, int depth) {
    if (node == nullptr) return;
    if (!node->deleted) {
        tree_depth = max(tree_depth, depth);
    }
    calculate_tree_depth(node->left, depth + 1);
    calculate_tree_depth(node->right, depth + 1);
}

// Preorder průchod pro shromáždění nesmazaných klíčů
void collect_keys_preorder(XNode* node, vector<int>& keys) {
    if (node == nullptr) return;
    if (!node->deleted) {
        keys.push_back(node->key);
    }
    collect_keys_preorder(node->left, keys);
    collect_keys_preorder(node->right, keys);
}

// Funkce pro odstranění stromu a uvolnění paměti
void delete_tree(XNode* node) {
    if (node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

// Funkce pro vložení uzlu
void insert(XNode*& root, int data, int edge_distance) {
    int node_height = tree_depth - edge_distance; // Výška uzlu
    
    if (root == nullptr) {
        root = new XNode(data, edge_distance);
        update_tree_depth(edge_distance); 
        sum_undeleted_heights += node_height; // Aktualizujeme součet výšek nesmazaných uzlů
    } else if (data < root->key) {
        insert(root->left, data, edge_distance + 1);
    } else if (data > root->key) {
        insert(root->right, data, edge_distance + 1);
    } else {
        if (root->deleted) {
            root->deleted = false;
            sum_deleted_heights -= node_height;
            sum_undeleted_heights += node_height;
        }
    }

    if (sum_deleted_heights > sum_undeleted_heights) {
        Compact(root);
    }
}

// Funkce pro smazání uzlu (lazy delete)
void lazy_delete(XNode* root, int data) {
    if (root == nullptr) {
        return;
    } else if (data < root->key) {
        lazy_delete(root->left, data);
    } else if (data > root->key) {
        lazy_delete(root->right, data);
    } else if (!root->deleted) {
        int node_height = tree_depth - root->edge_distance;
        root->deleted = true;
        sum_undeleted_heights -= node_height;
        sum_deleted_heights += node_height;
    }

    if (sum_deleted_heights > sum_undeleted_heights) {
        Compact(root);
    }
}

// Funkce Compact pro přebudování stromu
void Compact(XNode*& root) {
    vector<int> keys; // Pro uložení klíčů nesmazaných uzlů
    collect_keys_preorder(root, keys); // Získáme všechny nesmazané klíče
    delete_tree(root); // Uvolníme paměť starého stromu
    root = nullptr; // Obnovíme kořen stromu na prázdný strom

    // Reset globálních proměnných
    tree_depth = 0;
    sum_deleted_heights = 0;
    sum_undeleted_heights = 0;

    // Vložíme všechny nesmazané klíče zpět do stromu
    for (int key : keys) {
        insert(root, key, 0); // Vkládáme s přepočtem hloubky a výšek
    }

    // Po vložení všech klíčů znovu přepočítáme hloubku stromu
    tree_depth = 0;
    calculate_tree_depth(root, 0);
}
