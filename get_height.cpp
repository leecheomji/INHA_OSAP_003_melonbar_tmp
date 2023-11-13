#include "avl_tree.h"


int AVLTree::get_height(Node* node) {
    return (node == NULL) ? 0 : node->height;
}