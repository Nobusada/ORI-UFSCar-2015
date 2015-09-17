//
// Created by nobusada on 17/09/15.
//

#ifndef ORI_UFSCAR_2015_HASHTABLE_H
#define ORI_UFSCAR_2015_HASHTABLE_H

#include "HashLinkedList.h"

static int tableLength = 10;

class HashTable
{
private:
    HashLinkedList *list;
    int length;
    int hash(int key);

public:
    HashTable();
    bool insert(int key);
    bool remove(int entry);
    HashEntry* get(int key, int &counter);
    void printHashTable();
    int getLength();
    ~HashTable();
};


#endif //ORI_UFSCAR_2015_HASHTABLE_H
