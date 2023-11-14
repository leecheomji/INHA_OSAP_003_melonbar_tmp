#include "avl_tree.h"

/**
루트에서부터 내려가며 주어진 key를 가지는 노드를 찾아
depth를 구하고 출력하는 함수
*/
void AVLTree::get_depth(int key) {
  int depth = 0;  //depth를 0으로 초기화한다
  Node* tmp = root_;  //tmp 노드를 루트로 설정한다

  //노드를 찾았거나 더 이상 내려갈 수 없는 경우 while문을 탈출한다
  while (tmp != NULL && tmp->key != key) {
    if (tmp->key > key) { //주어진 key가 tmp의 key보다 작을 때는 왼쪽으로 내려간다
      tmp = tmp->left;
    }
    else {  //주어진 key가 tmp의 key보다 클 때는 오른쪽으로 내려간다
      tmp = tmp->right;
    }
    depth += 1; //depth를 업데이트한다
  }

  //노드의 depth를 출력한다
  cout << depth << "\n";
}
