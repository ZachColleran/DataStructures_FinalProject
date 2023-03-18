#include "doubleLL.hpp"
#include <iostream>

using namespace std;


doubleLL::doubleLL() {
    head = nullptr;
    tail = nullptr;
}
doubleLL::~doubleLL() {
    Node *curr = tail;
    int i = 0;
    while(head != tail) {
        tail = curr->prev;
        tail->next = nullptr;
        delete curr;
        curr = tail;
        i++;
    }
    head = nullptr;
    tail = nullptr;
    delete curr;
}


void doubleLL::insertEnd(int key) {
    Node *nn = new Node;
    nn->key = key;
    if(head == nullptr) {
        head = nn;
        nn->prev = nullptr;
    }
    else {
        nn->prev = tail;
        tail->next = nn;
    }
    tail = nn;
    nn->next = nullptr;

}

void doubleLL::search(int key) {
    Node *curr = head;
    while(head != nullptr) {
        if(curr->key == key) {
            break;
        }
        curr = curr->next;
    }
}

void doubleLL::display() {
    Node *curr = head;
    if(head == nullptr) {
        cout << "Empty" << endl;
        return;
    }
    while(curr != nullptr) {
        cout << curr->key << endl;
        curr = curr->next;
    }
}