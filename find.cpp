#include "avl_tree.h"


void AVLTree::find(int key) {
    Node* tmp = find_node(key);
    if (tmp == NULL) cout << "0\n";
    else get_depth(tmp->key);
}