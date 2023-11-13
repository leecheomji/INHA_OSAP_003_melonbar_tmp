#include "avl_tree.h"


void AVLTree::find_maximum(int top) {
    Node* tmp = find_node(top);
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }

    cout << tmp->key << ' ';
    get_depth(tmp->key);
}