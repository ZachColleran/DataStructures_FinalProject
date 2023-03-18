#include <iostream>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "doubleLL.hpp"
using namespace std;

int main() {

    // file
    ifstream in_file;
    ofstream out_file;
    int arr[10000];
    int arrIndex = 0;
    string line;

    // timing arrays
    float insert[50];
    float search[50];
    int random[200];
    srand(time(NULL));
    doubleLL LL;

    // read file
    in_file.open("dataSetA-updated.csv");
    out_file.open("results.csv");
    while(getline(in_file, line, ',')) {
        arr[arrIndex] = stoi(line);
        arrIndex++;
    }

    arrIndex = 0;
    for(int i = 0; i < 50; i++) { // Inserting into LL
    float totalTime = 0;
        for(int j = 0; j < 200; j++) {

            auto start = chrono::steady_clock::now(); // start time
            LL.insertEnd(arr[arrIndex]);
            auto end = chrono::steady_clock::now(); // end time

            totalTime += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            arrIndex++;
        }
        insert[i] = totalTime / 200;
    }

    arrIndex = 0;
    for(int i = 0; i < 50; i++) { // Inserting into LL

        for(int k = 0; k < 200; k++) { // create 200 random indexs based on the total number of items inserted. Used for Searching
            random[k] = rand() % ((i+1)*200);
        }

        float totalTime = 0;
        for(int j = 0; j < 200; j++) {

            auto start = chrono::steady_clock::now(); // start time
            LL.search(arr[random[j]]);
            auto end = chrono::steady_clock::now(); // end time

            totalTime += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            arrIndex++;
        }
        search[i] = totalTime / 200;
    }

    // output file
    out_file << "DLL Insert:" << endl;
    for(int i = 0; i < 50; i++) {
        out_file << insert[i] << endl;
    }

    out_file << "DLL Search:" << endl;
    for(int i = 0; i < 50; i++) {
        out_file << search[i] << endl;
    }

    out_file.close();
    LL.~doubleLL();
}