#include "avl_tree.h"


Node* AVLTree::right_rotation(Node* z) {
    Node* y = z->left, * x = y->left;
    z->left = y->right;
    y->right = z;

    height_renewal(z);
    height_renewal(y);
    return y;
}
