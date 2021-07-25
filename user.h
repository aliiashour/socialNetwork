#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include "BST.h"
using namespace std;
class Treap;
class BST;
struct Node;
class user
{
private:
    string username;
    string name;
    string email;

public:
    BST* FriendBST;

    user();
    user(string username, string name, string email);
    void setFriends(BST *friends){
        FriendBST = friends ; //coppy constractor
    }
    BST *getFriends(){
        return FriendBST ;
    }
    string getUsername()
    {
        return username;
    }

    string getName()
    {
        return name;
    }

    string getEmail()
    {
        return email;
    }
    void setUsername(string username)
    {
        this->username = username;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void listFriends();
    void print();
    void search(string userName) ;

    void addFriend(user u2);
    void deleteFriend(user u2);

};

struct Node
{

    user p ;
    Node* left ;
    Node* right ;
    Node(){
        left = right = NULL ;
    }
    Node(user p){

        this->p = p ;
        left = right = NULL;
    }
};






/*class Node {
  public:
  user key;
  Node* left;
  Node* right;

  Node() {
    left = NULL;
    right = NULL;
  }

    Node(user& x, Node* l=0, Node* r=0)
    {
        this->key = x;
        this->left = l;
        this->right = r;
    }
};*/


#endif // USER_H_INCLUDED
