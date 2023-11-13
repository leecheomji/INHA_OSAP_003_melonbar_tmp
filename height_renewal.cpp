#include "avl_tree.h"

void AVLTree::height_renewal(Node* node) {
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
}
