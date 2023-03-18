#ifndef doubleLL_HPP
#define doubleLL_HPP
#include <iostream>

using namespace std;

struct Node{
    int key;
    Node *next ;
    Node *prev ;
};


class doubleLL {

    private:
        Node *head;
        Node *tail;
    public:
        doubleLL();
        ~doubleLL();
        void insertEnd(int key);
        void search(int key);
        void display();

};


#endif