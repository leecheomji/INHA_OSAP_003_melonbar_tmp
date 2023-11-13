#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <string>
using namespace std;

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
    Node* right_rotation(Node* z);
    Node* left_rotation(Node* z);
    int get_height(Node* node);
    Node* relocation(Node* node, int key);
    void get_depth(int key);
    Node* insert(Node* node, int key);
    Node* find_node(int key);
    void find_minimum(int top);
    void find_maximum(int top);
    void find(int key);
    void is_empty();
    void size();
    void set_root(Node* node);
    Node* root();

private:
    Node* root_;
    int size_;
};


#endif