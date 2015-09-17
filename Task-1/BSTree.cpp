//
// Created by nobusada on 17/09/15.
//

#include "BSTree.h"
#include <iostream>

using namespace std;

void BSTree::insert(int value){
    if (this->root != NULL)
        BSTree::insert(root, value);
    else{
        this->root = new Node;
        this->root->value = value;
        this->root->right = NULL;
        this->root->left = NULL;
    }
}

void BSTree::insert(Node *node, int value)
{
    if (value <= node->value) {
        if (node->left != NULL)
            BSTree::insert(node->left, value);
        else{
            node->left = new Node();
            node->left->value = value;
            node->left->left = NULL;
            node->left->right = NULL;
        }
    }
    else {
        if (node->right != NULL)
            BSTree::insert(node->right, value);
        else{
            node->right = new Node();
            node->right->value = value;
            node->right->left = NULL;
            node->right->right = NULL;
        }
    }
}

void BSTree::print(){

    if (this->root == NULL){
        cout << "This Tree has no nodes." << endl;
        return;
    }
    else this->print_rec(this->root);
}

void BSTree::print_rec(Node *node){

    if (node != NULL) {
        if (node->right != NULL)
            print_rec(node->right);
        if (node->left != NULL)
            print_rec(node->left);
        cout << "   " << node->value << "\n";
    }
}

Node* BSTree::search(int value, int& counter) {
    return this->search(this->root, value, counter);
}

Node* BSTree::search(Node *node, int key, int& counter){

    if(node == NULL){
        cout << "Tree does not exist" << endl;
        return NULL;
    }

    counter++;
    cout << "Comparing " << node->value << " with the key " << key << endl;

    if (node->value == key){
        cout << "MATCH!" << endl;
        cout << "Iteractions: " << counter;
        return node;
    }
    else if (node->value < key){
        cout << "Key is bigger than this node value. Advancing further."
        << endl;
        this->search(node->right, key, counter);
    }
    else if (node->value < key){
        cout << "Key is smaller than this node value. Advancing further"
        << endl;
        this->search(node->left, key, counter);
    }
    return NULL;
}

BSTree::BSTree(){
    this->root = NULL;
}

BSTree::~BSTree(){
    this->destroy_tree(this->root);
}

void BSTree::destroy_tree(Node *node) {
    if (node != NULL){
        destroy_tree(node->right);
        destroy_tree(node->left);
        delete node;
    }
}