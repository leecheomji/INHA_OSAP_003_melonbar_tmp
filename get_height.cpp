#include "avl_tree.h"
/**
노드의 height를 반환하는 함수  
*/
int AVLTree::get_height(Node* node) {
    //해당 노드가 존재하면 노드의 height, 존재하지 않으면 0을 반환한다.
    return (node == NULL) ? 0 : node->height;
}
