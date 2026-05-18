#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    bool deleted;
    Node* left;
    Node* right;
    Node(int k) : key(k), deleted(false), left(nullptr), right(nullptr) {}
};

// Prototypy funkcí
void insert(Node*& root, int key);
void deleteNode(Node* root, int key);
Node* compact(Node* root);
Node* spojuju_dva_podstromy(Node* left, Node* right);
int pocitej_hloubku(Node* root);
int soucet_vysek(Node* root, bool deleted, int hloubka, int maximalni_hloubka);
void deleteTree(Node* root);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  // Odpojení cout od cin pro zvýšení rychlosti výstupu

    int N;
    cin >> N;

    Node* root = nullptr;
    int pocet_volani = 0;

    // Načítání a provádění operací přímo ze standardního vstupu
    for (int i = 0; i < N; ++i) {
        string operace_str;
        int hodnota;
        
        // Přečteme celý řetězec operace a hodnotu
        cin >> operace_str >> hodnota;

        // Kontrola prvního znaku řetězce operace
        if (operace_str[0] == 'i') {
            insert(root, hodnota);
        } else {
            deleteNode(root, hodnota);
        }

        // Výpočet hloubky stromu pro podmínku volání Compact
        int maximalni_hloubka = pocitej_hloubku(root);
        if (soucet_vysek(root, true, 0, maximalni_hloubka) > soucet_vysek(root, false, 0, maximalni_hloubka)) {
            root = compact(root);
            pocet_volani++;
        }
    }

    // Výpočet hloubky výsledného stromu
    int final_hloubka = pocitej_hloubku(root);

    // Výstup výsledků
    cout << pocet_volani << " " << final_hloubka << endl;

    // Uvolnění paměti
    deleteTree(root);

    return 0;
}

// Funkce pro vložení do stromu
void insert(Node*& root, int key) {
    if (root == nullptr) {
        root = new Node(key);
        return;
    }
    if (key < root->key) {
        insert(root->left, key);
    } else if (key > root->key) {
        insert(root->right, key);
    } else {
        if (root->deleted) {
            root->deleted = false; // Obnovení smazaného uzlu
        }
    }
}

// Funkce pro označení uzlu jako smazaného
void deleteNode(Node* root, int key) {
    if (root == nullptr) return;
    if (key < root->key) {
        deleteNode(root->left, key);
    } else if (key > root->key) {
        deleteNode(root->right, key);
    } else {
        if (!root->deleted) {
            root->deleted = true; // Označení uzlu jako smazaného
        }
    }
}

// Funkce pro přebudování stromu (Compact)
Node* compact(Node* root) {
    if (root == nullptr) return nullptr;
    if (root->deleted) {
        Node* left = compact(root->left);
        Node* right = compact(root->right);
        delete root;
        return spojuju_dva_podstromy(left, right);
    } else {
        Node* newNode = new Node(root->key);
        newNode->left = compact(root->left);
        newNode->right = compact(root->right);
        return newNode;
    }
}

// Funkce pro spojení dvou podstromů (spojuju_dva_podstromy)
Node* spojuju_dva_podstromy(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* current = left;
    while (current->right != nullptr) {
        current = current->right;
    }
    current->right = right;

    return left;
}

// Výpočet hloubky stromu
int pocitej_hloubku(Node* root) {
    if (root == nullptr) return -1;
    int leftDepth = pocitej_hloubku(root->left);
    int rightDepth = pocitej_hloubku(root->right);
    return max(leftDepth, rightDepth) + 1;
}

// Výpočet součtu výšek uzlů pro danou podmínku
int soucet_vysek(Node* root, bool deleted, int hloubka, int maximalni_hloubka) {
    if (root == nullptr) return 0;
    int vyska = maximalni_hloubka - hloubka;
    int soucet = (root->deleted == deleted ? vyska : 0);
    return soucet + soucet_vysek(root->left, deleted, hloubka + 1, maximalni_hloubka) + soucet_vysek(root->right, deleted, hloubka + 1, maximalni_hloubka);
}

// Uvolnění paměti stromu
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
