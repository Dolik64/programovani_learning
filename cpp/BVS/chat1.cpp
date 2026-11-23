#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

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
void recalculate_tree_depth(XNode* node);
void recalculate_sums(XNode* node);
void collect_keys_preorder(XNode* node, vector<int>& keys);
void delete_tree(XNode* node);
void insert(XNode*& root, int data, int edge_distance);
void lazy_delete(XNode* root, int data);
void Compact(XNode*& root);
void print_info();
void perform_insert(XNode*& root, int data);
void perform_delete(XNode*& root, int data);
XNode* build_tree_from_preorder(vector<int>& preorder, int& index, int min_val, int max_val, int edge_distance);

int main() {
    XNode* root = nullptr;

    perform_insert(root, 4);
    print_info();

    perform_insert(root, 2);
    print_info();
    perform_insert(root, 1);
    print_info();
    perform_insert(root, 3);
    print_info();
    perform_insert(root, 6);
    print_info();
    perform_insert(root, 5);
    print_info();

    cout << "Označen delete uzel s klíčem: " << 4 << endl;
    perform_delete(root, 4);
    print_info();

    cout << "Označen delete uzel s klíčem: " << 6 << endl;
    perform_delete(root, 6);
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
void recalculate_tree_depth(XNode* node) {
    tree_depth = 0;
    if (node == nullptr) return;
    vector<XNode*> stack;
    stack.push_back(node);
    while (!stack.empty()) {
        XNode* current = stack.back();
        stack.pop_back();
        if (!current->deleted && current->edge_distance > tree_depth) {
            tree_depth = current->edge_distance;
        }
        if (current->left) stack.push_back(current->left);
        if (current->right) stack.push_back(current->right);
    }
}

// Funkce pro přepočet součtů výšek
void recalculate_sums(XNode* node) {
    sum_deleted_heights = 0;
    sum_undeleted_heights = 0;
    if (node == nullptr) return;
    vector<XNode*> stack;
    stack.push_back(node);
    while (!stack.empty()) {
        XNode* current = stack.back();
        stack.pop_back();
        int node_height = tree_depth - current->edge_distance;
        if (!current->deleted) {
            sum_undeleted_heights += node_height;
        } else {
            sum_deleted_heights += node_height;
        }
        if (current->left) stack.push_back(current->left);
        if (current->right) stack.push_back(current->right);
    }
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
    if (root == nullptr) {
        root = new XNode(data, edge_distance);
    } else if (data < root->key) {
        insert(root->left, data, edge_distance + 1);
    } else if (data > root->key) {
        insert(root->right, data, edge_distance + 1);
    } else {
        // Pokud klíč existuje a je smazaný, obnovíme ho
        if (root->deleted) {
            root->deleted = false;
        }
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
        root->deleted = true;
    }
}

// Funkce pro vložení s kontrolou kompakce
void perform_insert(XNode*& root, int data) {
    insert(root, data, 0);
    recalculate_tree_depth(root);
    recalculate_sums(root);
    if (sum_deleted_heights > sum_undeleted_heights) {
        Compact(root);
    }
    cout << "Vložen uzel s klíčem: " << data << endl;
}

// Funkce pro smazání s kontrolou kompakce
void perform_delete(XNode*& root, int data) {
    lazy_delete(root, data);
    recalculate_tree_depth(root);
    recalculate_sums(root);
    if (sum_deleted_heights > sum_undeleted_heights) {
        Compact(root);
    }
}

// Funkce pro rekonstrukci stromu z preorder
XNode* build_tree_from_preorder(vector<int>& preorder, int& index, int min_val, int max_val, int edge_distance) {
    if (index >= preorder.size()) {
        return nullptr;
    }

    int key = preorder[index];

    if (key < min_val || key > max_val) {
        return nullptr;
    }

    XNode* node = new XNode(key, edge_distance);
    index++;

    node->left = build_tree_from_preorder(preorder, index, min_val, key - 1, edge_distance + 1);
    node->right = build_tree_from_preorder(preorder, index, key + 1, max_val, edge_distance + 1);

    return node;
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

    // Vytvoříme strom z preorder posloupnosti
    int index = 0;
    root = build_tree_from_preorder(keys, index, INT_MIN, INT_MAX, 0);

    // Po vložení všech klíčů znovu přepočítáme hloubku stromu a součty výšek
    recalculate_tree_depth(root);
    recalculate_sums(root);
}
