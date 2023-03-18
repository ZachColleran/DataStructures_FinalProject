#ifndef HASHBST_HPP
#define HASHBST_HPP

#include <string>
#include "BST.hpp"

using namespace std;


class HashTable{

    private:
        int tableSize;  // No. of buckets (BST)

        // Pointer to an array containing buckets
        BST *table;
        int numOfcolision = 0;

    public:
        HashTable(int bsize);  // Constructor
        ~HashTable();

        // inserts a key into hash table
        bool insertItem(int key);

        // hash function to map values to key
        unsigned int hashFunction(int key);

        void printTable();
        int getNumOfCollision();

        Node* searchItem(int key);
};


#endif

