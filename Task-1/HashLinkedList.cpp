//
// Created by nobusada on 17/09/15.
//

#include "HashLinkedList.h"

using namespace std;

HashLinkedList::HashLinkedList()
{
    head = new HashEntry;
    head->next = NULL;
    head->isEmpty = true;
    length = 0;
}

bool HashLinkedList::insert(HashEntry *entry){
    if (this->getHead()->isEmpty == true)
    {
        this->head = entry;
        this->head->next = NULL;
        this->head->isEmpty = false;
        this->incrementLenght();
        return false;
    }

    HashEntry *ptr1;
    HashEntry *ptr2 = this->getHead();

    while (ptr2 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr1->next;
    }

    if (this->getLength() < LIST_SIZE) {
        ptr2->next = entry;
        ptr1->next = ptr2;
        ptr2->next = NULL;
        length++;
        return false;
    }
    else return true;
}

bool HashLinkedList::remove(int key){
    if (this->getHead()->next == NULL)
        return false;

    HashEntry *ptr1 = this->getHead();
    HashEntry *ptr2 = this->getHead();

    while (ptr2 != NULL){
        if (ptr2->key == key){
            ptr1->next = ptr2->next;
            delete ptr2;
            this->decrementLenght();
            return true;
        }
        ptr1 = ptr2;
        ptr2 = ptr1->next;
    }
    return false;
}

HashEntry* HashLinkedList::get(int key, int &counter){
    HashEntry *ptr1;
    HashEntry *ptr2 = head;

    while (ptr2 != NULL)
    {
        ptr1 = ptr2;
        counter ++;

        cout << "Checking if the key: " << key <<
                " is the same as the actual key (" << ptr1->key
                << ") on the list" << endl;

        if ((ptr1 != this->getHead()) && (ptr1->key == key))
            return ptr1;
        ptr2 = ptr1->next;
    }
    return NULL;
}

void HashLinkedList::print()
{
    if (this->getLength() == 0)
    {
        cout << "\n{ }\n";
        return;
    }

    HashEntry *ptr1;
    HashEntry *ptr2 = this->getHead();
    cout << "\n{ ";

    while (ptr2)
    {
        ptr1 = ptr2;
        if (ptr1 != this->getHead())
        {
            cout << ptr1->key;
            if (ptr1->next) cout << ", ";
            else cout << " ";
        }
        ptr2 = ptr1->next;
    }
    cout << "}\n";
}

int HashLinkedList::getLength()
{
    return length;
}

HashLinkedList::~HashLinkedList()
{
    HashEntry *ptr1;
    HashEntry *ptr2 = this->getHead();

    while (ptr2 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr1->next;
        if (ptr2 != NULL) delete ptr1;
    }
}

HashEntry* HashLinkedList::getHead() {
    return this->head;
}

void HashLinkedList::incrementLenght() {
    this->length++;
}

void HashLinkedList::decrementLenght() {
    this->length--;
}