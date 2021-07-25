#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include<string>
#include <iostream>
#include"user.h"
using namespace std ;
class Node;
class user;
class BST
{
private:
    int length  ;
    void removeThis(Node* &p );
public:
    Node *root ;

    void clear(Node * & ptr);
    int getLength();
    Node getRoot();
    BST();
    BST(BST &source);
    void copyTree(Node *thisRoot, Node *sourceRoot);

    ~BST();

    bool isEmpty();
    void clearTree();
    user find(string userName) ;
    void insert(user p);
    void remove(string userName) ;
    void insertBack(user p);
    void printBreadthFirst();
    void loadFile();

};

#endif // BST_H_INCLUDED
