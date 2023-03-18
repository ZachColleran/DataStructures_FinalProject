#include <iostream>
#include "BST.hpp"
#define COUNT 10

BST::BST() {
    root = nullptr;
}

BST::BST(int data)
{
    root = createNode(data);
}

BST::~BST() {
    destroyNode(root);
}

Node* BST::createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}


/**
This function will destroy the subtree rooted at currNode.
Think about in what order should you destroy. POSTORDER. or right-left-root
**/
void BST::destroyNode(Node *currNode){

    if(currNode!=nullptr)
    {  
        destroyNode(currNode->left);
        destroyNode(currNode->right);

        delete currNode;
        currNode = nullptr;

    }
}

Node* BST::addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}


void BST::addNode(int data)
{
    root = addNodeHelper(root, data);
    // cout<<data<<" has been added"<<endl;
}

Node* BST::searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}

bool BST::searchKey(int key){
    Node* tree = searchKeyHelper(root, key);
    if(tree != NULL) {
        return true;
    }
    //cout<<"Key not present in the tree"<<endl;
    return false;
}

void BST:: printTreeHelper(Node* currNode){
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }

void BST:: printTree(){
     printTreeHelper(root);
     cout<<endl;
}

void BST::print2DUtilHelper(Node *currNode, int space)
{
    // Base case
    if (currNode == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST::print2DUtil( int space)
{
  print2DUtilHelper(root, space);
}

bool BST::isEmpty() {
    if(root == nullptr) {
        return true;
    }
    return false;
}

Node* BST::getRoot() {
    return root;
}

Node* BST::getNode(int key) {
    return searchKeyHelper(root, key);
}
