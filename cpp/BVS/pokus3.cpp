#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct XNode {
    int key;
    bool deleted;
    XNode* left;
    XNode* right;
    XNode(int k) : key(k), deleted(false), left(nullptr), right(nullptr) {}
};

void insert(XNode*& root, int data) {
    if (root == nullptr) {
        root = new XNode(data);
    } else if (data < root->key) {
        insert(root->left, data);
    } else if (data > root->key) {
        insert(root->right, data);
    }
    // If the data is equal to root->key, you might want to handle duplicates.
    // Currently, this code ignores duplicate values.
}

void lazy_delete(XNode* root, int data) {
    if (root == nullptr) {
        return;
    } else if (data < root->key) {
        lazy_delete(root->left, data);
    } else if (data > root->key) {
        lazy_delete(root->right, data);
    } else {
        root->deleted = true;
    }
}

int main() {
    XNode* root = nullptr;

    insert(root, 15);
    insert(root, 10);
    insert(root, 20);

    // Example output
    cout << "Root key: " << root->key << endl;
    if (root->left) cout << "Left child key: " << root->left->key << endl;
    if (root->right) cout << "Right child key: " << root->right->key << endl;

    // Remember to add code to free memory if needed.
    // delete_tree(root); // Example for cleaning up, if you create a delete function

    return 0;
}
