#include "avl_tree.h"
/**
set이 비어있는지 확인하는 함수
*/
void AVLTree::is_empty() {
  if (size_ == 0) std::cout << "1\n"; //set이 비어있을 경우 1을 출력
  else std::cout << "0\n"; //set이 비어있지 않을 경우 0을 출력
}