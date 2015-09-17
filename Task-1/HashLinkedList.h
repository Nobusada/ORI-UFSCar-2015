//
// Created by nobusada on 17/09/15.
//

#ifndef ORI_UFSCAR_2015_HashLinkedList_H
#define ORI_UFSCAR_2015_HashLinkedList_H

#include <iostream>

const int LIST_SIZE = 7;

struct HashEntry
{
    int key;
    HashEntry *next;
    bool isEmpty;
};

class HashLinkedList {
private:
    HashEntry *head;
    int length;

public:
    HashLinkedList();
    ~HashLinkedList();
    bool insert(HashEntry *newItem);
    bool remove(int key);
    HashEntry* get(int key, int &counter);
    void print();
    int getLength();
    HashEntry* getHead();
    void incrementLenght();
    void decrementLenght();
};


#endif //ORI_UFSCAR_2015_HashLinkedList_H
