#include "avl_tree.h"
/**
임의의 노드 top이 루트인 부분트리에서 최대 key(최댓값)를
갖는 노드를 찾고, key 값과, depth를 출력하는 함수
*/
void AVLTree::find_maximum(int top) {
  Node* temp_node = find_node(top); //노드를 찾아서 temp_node가 해당 노드를 가리키도록 함  
  
  while (temp_node->right != NULL) { //오른쪽 자식 노드가 NULL이 될때까지 내려감
    temp_node = temp_node->right; //오른쪽 자식이 존재하면, temp_node가 오른쪽 자식을 가리키도록 함
  }

  std::cout << temp_node->key << ' '; //최대 key값을 갖는 노드의 key값 출력
    get_depth(temp_node->key); //최대 key값을 갖는 노드의 depth값 출력
}