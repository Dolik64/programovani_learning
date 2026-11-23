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
int compacted = 0; // Počet kompakcí

// Deklarace funkcí
void calculate_tree_depth(XNode* node, int depth);
void collect_keys_preorder(XNode* node, vector<int>& keys);
void delete_tree(XNode* node);
void insert(XNode*& root, int data, int edge_distance = 0);
void lazy_delete(XNode* root, int data);
void Compact(XNode*& root);
void print_info();

int main() {
    XNode* root = nullptr;

    insert(root, 4);
    print_info();

    insert(root, 2);
    print_info();
    insert(root, 1);
    print_info();
    insert(root, 3);
    print_info();
    insert(root, 6);
    print_info();
    insert(root, 5);
    print_info();

    cout << "oznacen delete uzel s klíčem: " << 4 << endl;
    lazy_delete(root, 4);
    print_info();

    cout << "oznacen delete uzel s klíčem: " << 6 << endl;
    lazy_delete(root, 6);
    print_info();

   

    return 0;
}

void print_node_data(XNode* node) {
    if (node == nullptr) {
        cout << "null";
    } else {
        cout << node->key << endl;
        cout << node->edge_distance << endl;
    }
}

void print_info(){
    cout << endl;
    cout << "Počet kompakcí: " << compacted << endl;
    cout << "Aktuální hloubka stromu: " << tree_depth << endl;
    cout << "Součet výšek nesmazaných uzlů: " << sum_undeleted_heights << endl;
    cout << "Součet výšek smazaných uzlů: " << sum_deleted_heights << endl;
    cout << endl;
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
        
        // Přepočítáme tree_depth pro nový uzel
        tree_depth = max(tree_depth, edge_distance);
        
        sum_undeleted_heights += tree_depth - edge_distance; // Aktualizujeme součet výšek nesmazaných uzlů
        cout << "Vložen uzel s klíčem: " << data << endl;
        print_node_data(root);
        cout << endl;
    } else if (data < root->key) {
        insert(root->left, data, edge_distance + 1);
    } else if (data > root->key) {
        insert(root->right, data, edge_distance + 1);
    } else {
        // Pokud klíč existuje a je smazaný, obnovíme ho
        if (root->deleted) {
            root->deleted = false;
            int restore_height = tree_depth - edge_distance;
            sum_deleted_heights -= restore_height;
            sum_undeleted_heights += restore_height;
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
    compacted += 1;
    vector<int> keys; // Pro uložení klíčů nesmazaných uzlů
    collect_keys_preorder(root, keys); // Získáme všechny nesmazané klíče
    delete_tree(root); // Uvolníme paměť starého stromu
    root = nullptr; // Obnovíme kořen stromu na prázdný strom

    // Reset globálních proměnných
    tree_depth = 0;
    sum_deleted_heights = 0;
    sum_undeleted_heights = 0;

    // Vložíme všechny nesmazané klíče zpět do stromu a postupně nastavujeme hloubky a výšky
    for (int key : keys) {
        insert(root, key, 0); // Vkládáme s přepočtem hloubky a výšek
    }

    // Po vložení všech klíčů znovu přepočítáme hloubku stromu
    tree_depth = 0;
    calculate_tree_depth(root, 0);
}
