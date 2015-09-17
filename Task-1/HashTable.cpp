//
// Created by nobusada on 17/09/15.
//

#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    list = new HashLinkedList[tableLength];
    length = tableLength;
}

int HashTable::hash(int key)
{
    return key % tableLength;
}

bool HashTable::insert(int key)
{
    HashEntry *newEntry = new HashEntry();
    newEntry->key = key;
    newEntry->next = NULL;

    int index = hash(newEntry->key);
    int baseIndex = index;

    while(list[index].insert(newEntry)){ //this is bugging
        index = (index + 1) % tableLength;
        if (index == baseIndex) return false; // is full
    }
    return true;
}

bool HashTable::remove(int itemKey)
{
    int index = hash(itemKey);
    return list[index].remove(itemKey);
}

HashEntry* HashTable::get(int key, int &counter)
{
    int index = hash(key);
    return list[index].get(key, counter);
}

void HashTable::printHashTable()
{
    int i;
    cout << "\n\nHash Table:\n";
    for (i = 0; i < length; i++)
    {
        cout << "List " << i + 1 << ": ";
        list[i].print();
    }
}

HashTable::~HashTable()
{
    int i;
    for (i = 0; i < tableLength; i++){
        delete this->list;
    }
    delete [] this->list;
}
