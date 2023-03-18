#include <iostream>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "hashBST.hpp"
using namespace std;

int main() {
    // read from the file
    ifstream in_file;
    ofstream out_file;
    int arr[10000]; // data
    int arrIndex = 0;
    string line;

    // timing arrays
    float insert[50];
    float search[50];
    int insertCol[50];
    int searchCol[50];
    int random[200];
    srand(time(NULL));
    HashTable hashTable(10009);

    // get info from csv
    in_file.open("dataSetA-updated.csv");
    out_file.open("results.csv");
    while(getline(in_file, line, ',')) {
        arr[arrIndex] = stoi(line);
        arrIndex++;
    }

    arrIndex = 0;
    for(int i = 0; i < 50; i++) { // Inserting into Hash table with BST chaining
        float totalTime = 0;
        int colStart = hashTable.getNumOfCollision();
        for(int j = 0; j < 200; j++) {

            auto start = chrono::steady_clock::now(); // time start
            hashTable.insertItem(arr[arrIndex]);
            auto end = chrono::steady_clock::now(); // time end

            totalTime += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            arrIndex++;
        }
        int colEnd = hashTable.getNumOfCollision();
        insert[i] = totalTime / 200;
        insertCol[i] = colEnd - colStart;
        

        for(int k = 0; k < 200; k++) { // create 200 random indexes based on the total number of items inserted. Used for Searching
            random[k] = rand() % ((i+1)*200);
        }

        totalTime = 0;
        colStart = hashTable.getNumOfCollision();
        for(int j = 0; j < 200; j++) { // Searching 200 known indexes

            auto start = chrono::steady_clock::now(); // time start
            hashTable.searchItem(arr[random[j]]);
            auto end = chrono::steady_clock::now(); // time end

            totalTime += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        }
        colEnd = hashTable.getNumOfCollision();
        search[i] = totalTime / 200;
        searchCol[i] = colEnd - colStart;

    }

    for(int i = 0; i < 50; i++) {
        out_file << insert[i] << ',' << insertCol[i] << endl;
    }

    out_file << endl;
    for(int i = 0; i < 50; i++) {
        out_file << search[i] << ',' << searchCol[i] << endl;
    }

    out_file.close();
}