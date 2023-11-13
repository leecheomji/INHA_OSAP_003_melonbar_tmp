#include "avl_tree.h"

Node* AVLTree::relocation(Node* node, int key) {
    int balance = get_height(node->left) - get_height(node->right);

    if (balance > 1 && key < node->left->key) node = right_rotation(node);
    else if (balance < -1 && key > node->right->key) node = left_rotation(node);
    else if (balance > 1 && key > node->left->key) {
        node->left = left_rotation(node->left);
        node = right_rotation(node);
    }
    else if (balance < -1 && key < node->right->key) {
        node->right = right_rotation(node->right);
        node = left_rotation(node);
    }

    height_renewal(node);
    return node;
}
