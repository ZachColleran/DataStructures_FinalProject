#include <iostream>
#include "hashDH.hpp"
#define PRIME 9973

HashTable::HashTable(int bsize) {  // Constructor
    tableSize = bsize;

    table = new int[tableSize];
    for(int i = 0; i < tableSize; i++) {
        table[i] = -1;
    }
}

HashTable::~HashTable() {
    delete[] table;
}

// inserts a key into hash table
bool HashTable::insertItem(int key) {

    int i = 0;
    while(true) {
        int hashIndex = (hashFunction(key) + (i * hashFunctionDH(key))) % tableSize;

        if(table[hashIndex] == -1) { // if index is empty insert
            table[hashIndex] = key;
            return true;
        }
        else if(table[hashIndex] == key) { // duplicate
            return false;
        }
        i++;
        numOfcolision++;
    }

    return false;
}

// bool HashTable::insertItem(int key) {
//     int i = 0;
//     int hashIndex = hashFunction(key);

//     if(table[hashIndex] == -1) { // if no collision
//         table[hashIndex] = key;
//     }
//     else {
//         while(true) {
//             int hashIndex2 = (hashFunction(key) + (i * hashFunctionDH(key))) % tableSize;

//             if(table[hashIndex2] == -1) { // if index is empty insert
//                 table[hashIndex2] = key;
//                 return true;
//             }
//             else if(table[hashIndex2] == key) { // duplicate
//                 return false;
//             }
//             i++;
//             numOfcolision++;
//         }
//     }
//     return false;
// }

// hash function to map values to key
unsigned int HashTable::hashFunction(int key) {
    return key % tableSize;
}

// hash function for double hashing
unsigned int HashTable::hashFunctionDH(int key) {
    return PRIME - (key % PRIME);
}

void HashTable::printTable() {

}
int HashTable::getNumOfCollision() {
    return numOfcolision;
}

int HashTable::searchItem(int key) {
    int i = 0;

    while(true) {
        int hashIndex = (hashFunction(key) + (i * hashFunctionDH(key))) % tableSize;
        if(table[hashIndex] == key) { // if found
            return hashIndex;
        }
        if(i == tableSize) { // if not found
            return -2;
        }
        i++;
        numOfcolision++;
    }
}

