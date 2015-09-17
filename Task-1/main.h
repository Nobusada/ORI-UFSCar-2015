//
// Created by azathoth on 12/09/15.
//

#ifndef ORI_UFSCAR_2015_ORI2015_H
#define ORI_UFSCAR_2015_ORI2015_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "HashLinkedList.h"
#include "HashTable.h"

static int size = 10;

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


#endif //ORI_UFSCAR_2015_ORI2015_H
