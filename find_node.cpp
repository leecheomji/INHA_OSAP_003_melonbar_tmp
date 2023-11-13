#include "avl_tree.h"


Node* AVLTree::find_node(int key) {
    Node* tmp = root_;
    while (tmp != NULL && tmp->key != key) {
        if (tmp->key > key) tmp = tmp->left;
        else tmp = tmp->right;
    }

    return tmp;
}