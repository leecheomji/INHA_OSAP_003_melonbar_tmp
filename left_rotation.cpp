#include "avl_tree.h"

Node* AVLTree::left_rotation(Node* z) {
    Node* y = z->right, * x = y->right;
    z->right = y->left;
    y->left = z;

    return y;
}