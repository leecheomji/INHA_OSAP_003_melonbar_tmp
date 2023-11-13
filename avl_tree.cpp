#include "avl_tree.h"

int AVLTree::get_height(Node* node) {
    return (node == NULL) ? 0 : node->height;
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

void AVLTree::height_renewal(Node* node) {
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
}

Node* AVLTree::right_rotation(Node* z) {
    Node* y = z->left, * x = y->left;
    z->left = y->right;
    y->right = z;

    height_renewal(z);
    height_renewal(y);
    return y;
}

Node* AVLTree::left_rotation(Node* z) {
    Node* y = z->right, * x = y->right;
    z->right = y->left;
    y->left = z;

    height_renewal(z);
    height_renewal(y);
    return y;
}

Node* AVLTree::relocation(Node* node, int key) {
    int balance = get_height(node->left) - get_height(node->right);

    if (balance > 1 && key < node->left->key) node = right_rotation(node);
    else if (balance < -1 && key > node->right->key) node = left_rotation(node);
    else if (balance > 1 && key > node->left->key) {
        node->left = left_rotation(node->left);
        node = right_rotation(node);
    }
    else if (balance < -1 && key < node->right->key) {
        node->right = right_rotation(node->right);
        node = left_rotation(node);
    }

    height_renewal(node);
    return node;
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

void AVLTree::get_size() {
    cout << size_ << "\n";
}

void AVLTree::set_root(Node* node) {
    root_ = node;
}

Node* AVLTree::get_root() {
    return root_;
}