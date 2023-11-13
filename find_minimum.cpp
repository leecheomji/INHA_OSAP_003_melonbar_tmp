#include "avl_tree.h"



void AVLTree::find_minimum(int top) {
    Node* tmp = find_node(top);
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }

    cout << tmp->key << ' ';
    get_depth(tmp->key);
}