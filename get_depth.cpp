#include "avl_tree.h"


void AVLTree::get_depth(int key) {
    int depth = 0;
    Node* tmp = root_;
    while (tmp != NULL && tmp->key != key) {
        if (tmp->key > key) tmp = tmp->left;
        else tmp = tmp->right;
        depth += 1;
    }

    cout << depth << "\n";
}