#include "avl_tree.h"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int T, Q, x;
    cin >> T;
    while (T != 0) {
        Node* root = NULL;
        AVLTree avl_tree = AVLTree(root);
        cin >> Q;
        for (int i = 0;i < Q;i++) {
            cin >> s;
            if (s == "empty") avl_tree.is_empty();
            else if (s == "size") avl_tree.size();
            else {
                cin >> x;
                if (s == "minimum") avl_tree.find_minimum(x);
                else if (s == "maximum") avl_tree.find_maximum(x);
                else if (s == "find") avl_tree.find(x);
                else if (s == "insert") {
                    avl_tree.set_root(avl_tree.insert(avl_tree.root(), x));
                    avl_tree.find(x);
                }
            }
        }

        T--;
    }
}