//
// Daniel Nobusada e Fábio Gunkel
// ori2015.cpp
// TODO: Put all classes, funcs and procs into a lib
// TODO: Add sorting methods
// TODO: BSTree Pretty-Print

#include "main.h"

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

void initValues(vector <int>& v, BSTree& root, HashTable& ht) {
    int i, randomValue;
    bool hashTableFull;

    for (i = 0; i < size; i++) {
        randomValue = 1 + rand() % 99;
        v.push_back(randomValue);
        root.insert(randomValue);
        hashTableFull = ht.insert(randomValue);
        if (!hashTableFull) cout << "Hash Table is now full." << endl;
    }
}

bool sequentialSearch (vector <int> v, int key, int& counter){
    int i;
    for (i = 0; i < size-1 ; i++){
        counter ++;
        if (v[i] == key)
            return true;
    }
    return false;
};

void binarySearch(vector <int>& v, int key, int &counter, int start, int end){
    counter++;
    int i = (start + end)/2;

    cout << "Comparing " << v[i] << " and the key " << key << endl;

    if(v[i] == key){
        cout << "Found it!" << endl;
    }
    else if (start == end){
        cout << "This number does not exist in this vector." << endl;
        return;
    }
    else if (v[i] < key){
        cout << "Key is bigger than the actual value." << endl;
        binarySearch(v, key, counter, i+1, end);
    }
    else{
        cout << "Key is smaller than the actual value" << endl;
        binarySearch(v, key, counter, start, i-1);
    }
}

void printVector(vector <int>& v){
    int i;
    for(i = 0; i < size; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** arvg){
    srand(time(NULL));
    vector <int> v;
    BSTree* root = new BSTree();
    HashTable *ht = new HashTable();
    int key, counter = 0;

    initValues(v, *root, *ht);

    cout << "Vector: " << endl;
    sort(v.begin(), v.end());
    printVector(v);

    cout << "Binary Search Tree: " << endl;
    root->print();

    cout << "Hash table: " << endl;
    ht->printHashTable();

    cout << "Insert a key to search for: ";
    cin >> key;

    cout << endl << endl << "-------------Sequential Search-------------"
    << endl << endl;

    sequentialSearch(v, key, counter);
    std::string seq = "Number of iteractions from the Sequential Search: ";
    seq += std::to_string(counter);
    cout << seq << endl;

    cout << endl << endl << "-------------Binary Search-------------"
    << endl << endl;

    counter = 0;
    binarySearch(v, key, counter, 0, size-1);
    std::string bin = "Number of iteractions from the Binary Search: ";
    bin += std::to_string(counter);
    cout << bin << endl;

    cout << endl << endl << "-------------Binary Search Tree-------------"
    << endl << endl;

    counter = 0;
    root->search(key, counter);

    cout << endl << endl << "-------------Hash Table-------------"
    << endl << endl;

    counter = 0;
    ht->get(key, counter);
    std::string hash = "Number of iteractions from the Hash Table: ";
    hash += std::to_string(counter);
    cout << hash << endl;

    cout << endl << endl << "-------------Destroying Structures-------------"
    << endl << endl;

    delete ht;
    delete root;

    getchar();
    return 0;
}
