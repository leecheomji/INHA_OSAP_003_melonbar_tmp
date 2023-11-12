#include "avl_tree.h"

Node* AVLTree::right_rotation(Node* z) {
    Node* y = z->left, * x = y->left;
    z->left = y->right;
    y->right = z;

    return y;
}

Node* AVLTree::left_rotation(Node* z) {
    Node* y = z->right, * x = y->right;
    z->right = y->left;
    y->left = z;

    return y;
}

int AVLTree::get_height(Node* node) {
    return (node == NULL) ? 0 : node->height;
}

Node* AVLTree::relocation(Node* node, int key) {
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

void AVLTree::get_depth(int key) {
    int depth = 0;
    Node* tmp = root_;
    while (tmp != NULL && tmp->key != key) {
        if (tmp->key > key) tmp = tmp->left;
        else tmp = tmp->right;
        depth += 1;
    }

    cout << depth << "\n";
}

Node* AVLTree::insert(Node* node, int key) {
    if (node == NULL) {
        size_++;
        return new Node(key);
    }

    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);

    return relocation(node, key);
}

Node* AVLTree::find_node(int key) {
    Node* tmp = root_;
    while (tmp != NULL && tmp->key != key) {
        if (tmp->key > key) tmp = tmp->left;
        else tmp = tmp->right;
    }

    return tmp;
}

void AVLTree::find_minimum(int top) {
    Node* tmp = find_node(top);
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }

    cout << tmp->key << ' ';
    get_depth(tmp->key);
}

void AVLTree::find_maximum(int top) {
    Node* tmp = find_node(top);
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }

    cout << tmp->key << ' ';
    get_depth(tmp->key);
}

void AVLTree::find(int key) {
    Node* tmp = find_node(key);
    if (tmp == NULL) cout << "0\n";
    else get_depth(tmp->key);
}

void AVLTree::is_empty() {
    if (size_ == 0) cout << "1\n";
    else cout << "0\n";
}

void AVLTree::size() {
    cout << size_ << "\n";
}

void AVLTree::set_root(Node* node) {
    root_ = node;
}

Node* AVLTree::root() {
    return root_;
}