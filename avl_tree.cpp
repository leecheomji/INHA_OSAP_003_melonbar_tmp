#include "avl_tree.h"

struct Node {
public:
    Node* left;
    Node* right;
    int height;
    int key;

    Node() : left(NULL), right(NULL), height(0), key(0) {}
    Node(int key) : left(NULL), right(NULL), height(1), key(key) {}
};

class AVLTree {
public:
    AVLTree() : root_(NULL), size_(0) {}
    AVLTree(Node* root) : root_(root), size_(0) {}

    Node* right_rotation(Node* z) {
        Node* y = z->left, * x = y->left;
        z->left = y->right;
        y->right = z;

        return y;
    }

    Node* left_rotation(Node* z) {
        Node* y = z->right, * x = y->right;
        z->right = y->left;
        y->left = z;

        return y;
    }

    int get_height(Node* node) {
        return (node == NULL) ? 0 : node->height;
    }

    Node* relocation(Node* node, int key) {
        int balance = get_height(node->left) - get_height(node->right);
        Node* tmp = NULL;

        if (balance > 1 && key < node->left->key) tmp = right_rotation(node);
        else if (balance < -1 && key > node->right->key) tmp = left_rotation(node);
        else if (balance > 1 && key > node->left->key) {
            node->left = left_rotation(node->left);
            tmp = right_rotation(node);
        }
        else if (balance < -1 && key < node->right->key) {
            node->right = right_rotation(node->right);
            tmp = left_rotation(node);
        }
        else tmp = node;

        node->height = max(get_height(node->left), get_height(node->right)) + 1;
        return tmp;
    }

    void get_depth(int key) {
        int depth = 0;
        Node* tmp = root_;
        while (tmp != NULL && tmp->key != key) {
            if (tmp->key > key) tmp = tmp->left;
            else tmp = tmp->right;
            depth += 1;
        }

        cout << depth << "\n";
    }

    Node* insert(Node* node, int key) {
        if (node == NULL) {
            size_++;
            return new Node(key);
        }

        if (key < node->key) node->left = insert(node->left, key);
        else if (key > node->key) node->right = insert(node->right, key);

        return relocation(node, key);
    }

    Node* find_node(int key) {
        Node* tmp = root_;
        while (tmp != NULL && tmp->key != key) {
            if (tmp->key > key) tmp = tmp->left;
            else tmp = tmp->right;
        }

        return tmp;
    }

    void find_minimum(int top) {
        Node* tmp = find_node(top);
        while (tmp->left != NULL) {
            tmp = tmp->left;
        }

        cout << tmp->key << ' ';
        get_depth(tmp->key);
    }

    void find_maximum(int top) {
        Node* tmp = find_node(top);
        while (tmp->right != NULL) {
            tmp = tmp->right;
        }

        cout << tmp->key << ' ';
        get_depth(tmp->key);
    }

    void find(int key) {
        Node* tmp = find_node(key);
        if (tmp == NULL) cout << "0\n";
        else get_depth(tmp->key);
    }

    void is_empty() {
        if (size_ == 0) cout << "1\n";
        else cout << "0\n";
    }

    void size() {
        cout << size_ << "\n";
    }

    void set_root(Node* node) {
        root_ = node;
    }

    Node* root() {
        return root_;
    }

private:
    Node* root_;
    int size_;
};