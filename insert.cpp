#include "avl_tree.h"

Node* AVLTree::insert(Node* node, int key) {
    if (node == NULL) {
        size_++;
        return new Node(key);
    }

    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);

    return relocation(node, key);
}