#include "avl_tree.h"


Node* AVLTree::relocation(Node* node, int key) {
    int balance = get_height(node->left) - get_height(node->right);
    Node* tmp = NULL;

    if (balance > 1 && key < node->left->key) tmp = right_rotation(node);
    else if (balance < -1 && key > node->right->key) tmp = left_rotation(node);
    else if (balance > 1 && key > node->left->key) {
        node->left = left_rotation(node->left);
        tmp = right_rotation(node);
    }
    else if (balance < -1 && key < node->right->key) {
        node->right = right_rotation(node->right);
        tmp = left_rotation(node);
    }
    else tmp = node;

    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    return tmp;
}