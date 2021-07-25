#include <iostream>
#include"user.h"
#include"BST.h"
#include<fstream>
using namespace std;
user::user()
{
    username = "no User";
    name = "no name";
    email = "no email";
    FriendBST = new BST() ;
}

user::user(string username, string name, string email)
{
    FriendBST = new BST() ;
    this->email = email;
    this->username = username;
    this->name = name;
    string fName;
    string secName;
    ifstream read ("all-users-relations.in.txt");
    while(getline(read,fName,',') && getline(read,secName,','))
    {
        if(fName == this->username)
        {
            user myFriend;
            Node* n;
            myFriend.setUsername(secName);
            this->FriendBST->insert(myFriend);
            string x,y,z;
        }
        else if (secName == this->username)
        {
            user myFriend;
            Node* n1;
            myFriend.setUsername(fName);
            this->FriendBST->insert(myFriend);
        }
    }
}

void user::listFriends()
{

    if( this->FriendBST->isEmpty() ){
        cout << "friends list of "<< this->getUsername() <<" is empty\n" ;
        return ;
    }else{
        cout << "friends list of "<< this->getUsername() <<" is\n" ;
        this->FriendBST->printBreadthFirst();
    }

}

void user::print(){
    cout << "userName is\t" << getUsername() << "\nname is" << " \t" << getName() << "\nemail is" << "\t" << getEmail() << endl;
}

void user::search(string userName){
    user u= FriendBST->find(userName) ;
    if ( u.getUsername() != "no User"){
        cout << "\nuser " << userName << " founded and it's data is\n"  ;
        u.print();
        cout << "\n-------------------------\n";
        return ;
    }
    else
        cout << userName<< " not Found in " << this->getUsername() << " friend List !\n"  ;
}


void user::addFriend(user u2){
    this->FriendBST->insert(u2) ;
    u2.FriendBST->insertBack(*this) ;
}

void user::deleteFriend(user u2){
    this->FriendBST->remove(u2.getUsername()) ;
    u2.FriendBST->remove((*this).getUsername()) ;
}

