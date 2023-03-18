#include <iostream>
#include "hashBST.hpp"

HashTable::HashTable(int bsize) {
    tableSize = bsize;
    table = new BST[tableSize];

    for(int i = 0; i < tableSize; i++) { // set every root->key to -1
        table[i].addNode(-1);
    }
}

HashTable::~HashTable() {
    delete[] table;
}

// inserts a key into hash table
bool HashTable::insertItem(int key) {
    int hashIndex = hashFunction(key);

    if(table[hashIndex].searchKey(key)) { // check for duplicates; dont insert
        numOfcolision++;
        return false;
    }
    else {
        if(table[hashIndex].getRoot()->key != -1) { // if root node is not availible, add to collision
            numOfcolision++;
            table[hashIndex].addNode(key);
        }
        else { // replace root node key with value
            table[hashIndex].getRoot()->key = key;
        }
        return true;
    }
}

// hash function to map values to key
unsigned int HashTable::hashFunction(int key) {
    return key % tableSize;
}

void HashTable::printTable() {

}

int HashTable::getNumOfCollision() {
    return numOfcolision;
}

Node* HashTable::searchItem(int key) {
    int hashIndex = hashFunction(key);

    if(table[hashIndex].getRoot()->key != key) { // check for collision
        numOfcolision++;
    }

    return table[hashIndex].getNode(key); // look for ID in BST
}

