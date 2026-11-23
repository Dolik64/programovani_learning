#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Node {
    int key;
    bool deleted;
    Node* left;
    Node* right;
    Node(int k) : key(k), deleted(false), left(nullptr), right(nullptr) {}
};

int main() {
    // Deklarace a inicializace horni jako ukazatele na Node
    //Node* horni = new Node(10);  // Příklad s hodnotou 10
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(4);
    Node* f = new Node(4);

    a->left = b;
    a->right = c;
    c->right = d;

    // Ukázkový výstup
    std::cout << "Klíč uzlu horni: " << a->key << std::endl;

    // Uvolnění paměti po použití
    delete a;

    return 0;
}