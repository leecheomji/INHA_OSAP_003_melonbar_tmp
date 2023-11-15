#include "avl_tree.h"
/**
해당 key값을 갖고 있는 노드를 찾고, 
해당 key값을 갖고 있는 노드가 존재하지 않으면 0을 출력하고,
존재하면 해당 노드의 depth를 알려주는 함수
*/
void AVLTree::find(int key) {
  Node* temp_node = find_node(key); //find_node(int key)함수를 이용하여 해당 key값을 갖는 노드 찾기 
  if (temp_node == NULL) cout << "0\n"; //해당 key값을 갖는 노드가 없으면 0을 출력
  else get_depth(temp_node->key);//get_depth(int key)함수를 이용하여 해당 key값을 갖는 노드의 depth 출력
}