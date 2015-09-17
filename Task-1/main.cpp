//
// Daniel Nobusada e Fabio Gunkel
// ori2015.cpp
// TODO: Add sorting methods
// TODO: BSTree Pretty-Print

#include "main.h"

using namespace std;

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

    delete root;
    delete ht;

    getchar();
    return 0;
}
