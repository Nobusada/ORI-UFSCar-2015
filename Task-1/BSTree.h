//
// Created by nobusada on 17/09/15.
//

#ifndef ORI_UFSCAR_2015_BSTREE_H
#define ORI_UFSCAR_2015_BSTREE_H

typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

class BSTree{
private:
    Node *root;
    void print_rec(Node *node);
    void insert(Node *node, int value);
    Node* search(Node *node, int key, int& counter);

public:
    BSTree();
    ~BSTree();
    void insert(int value);
    void print();
    Node* search(int value, int& counter);
    void destroy_tree(Node *node);
};

#endif //ORI_UFSCAR_2015_BSTREE_H
