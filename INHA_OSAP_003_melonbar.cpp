#include "avl_tree.h"

int main() {
  //입출력 속도 개선을 위한 코드
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string command;  //명령어
  int test_case, num_command, x;  //테스트 케이스 수, 명령어 개수, key 값
  cin >> test_case;  //테스트 케이스 수를 입력 받는다

  //테스트 케이스의 수만큼 AVL Tree를 만들고 기능을 수행한다
  while (test_case != 0) {
    Node* root = NULL;  //NULL 값으로 초기화한 root 노드를 정의한다
    AVLTree avl_tree = AVLTree(root);  //root 노드가 루트인 AVL Tree를 만든다
    cin >> num_command;  //명령어의 수를 입력 받는다

    //입력 받은 명령어의 수만큼 반복한다
    for (int i = 0; i < num_command; i++) {
      cin >> command;  //명령어를 입력 받는다
      if (command == "empty") {  //set이 비어 있는지 확인하여 1 또는 0을 출력한다
        avl_tree.is_empty();
      }
      else if (command == "size") {  //set에 저장된 원소의 수를 출력한다
        avl_tree.size();
      }
      else {  //변수 x를 사용하는 기능들
        cin >> x;  //x 값을 입력 받는다
        if (command == "minimum") {  //노드 x가 루트인 subtree에서 key값이 가장 작은 노드의 key와 depth를 출력한다
          avl_tree.find_minimum(x);
        }
        else if (command == "maximum") {  //노드 x가 루트인 subtree에서 key값이 가장 큰 노드의 key와 depth를 출력한다
          avl_tree.find_maximum(x);
        }
        else if (command == "find") {  //노드 x의 depth를 출력한다  
          avl_tree.find(x);
        }
        else if (command == "insert") {  //노드 x를 set에 삽입하고, 노드 x의 depth를 출력한다
          avl_tree.set_root(avl_tree.insert(avl_tree.root(), x));
          avl_tree.find(x);
        }
      }
    }

    test_case--;  //수행할 테스트 케이스의 수를 업데이트한다
  }
}
