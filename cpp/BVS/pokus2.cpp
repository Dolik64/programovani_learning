#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//uloha na alg opravdu pracuje s binarnim vyhledavacim stromem
using namespace std;

struct XNode {
    int key;
    bool deleted;
    XNode* left;
    XNode* right;
    XNode(int k) : key(k), deleted(false), left(nullptr), right(nullptr) {}
};

int main() {
    // Deklarace a inicializace horni jako ukazatele na Node
    //Node* horni = new Node(10);  // Příklad s hodnotou 10
    XNode* root;
    root = NULL;

    insert(root, 15);
    insert(root, 10);
    insert(root, 20);

    // Ukázkový výstup
    //std::cout << "Klíč uzlu horni: " << a->key << std::endl;

    // Uvolnění paměti po použití
    //delete a;

    return 0;
}

void insert(XNode* root, int data){

}

XNode* get_new_node(int data){
    XNode* newNode = new XNode();
    newNode->key = data;
    newNode->left = newNode-> right = NULL;
    return newNode;
}