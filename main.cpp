#include <iostream>
#include<fstream>
#include"user.h"
#include"linkedList.h"
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>
#include"Node.h"
#include"BST.h"
using namespace std;
class Treap
{
 struct tNode
 {
   user* key;
   int priority;
   tNode* left;
   tNode* right;
   tNode(user* k) {
      this->key = k;
      this->priority = rand() % 100;

      this->left= this->right = 0;
   }

 };

 void leftRot(tNode* &root) {
   tNode* x = root->right;
   tNode* y = root->right->left;
   x->left = root;
   root->right= y;
   root = x;
}
 void rightRot( tNode* &root)
{
     tNode* L = root->left;
     tNode* Y = root->left->right;

    L->right = root;
    root->left = Y;

    root = L;
}

 void insertNode(tNode* root, user* k) {
   if (root == 0) {
      root = new tNode(k);
      return;
   }
   if (k < root->key) {
      insertNode(root->left, k);
      if (root->left != 0 && root->left->priority > root->priority)
      rightRot(root);
   } else {
      insertNode(root->right, k);
      if (root->right!= 0 && root->right->priority > root->priority)
       leftRot(root);
}
 }

 bool searchNode(tNode* root, user* k) {
   if (root == 0)
      return false;
   if (root->key == k)
      return true;
   if (k < root->key)
      return searchNode(root->left, k);

    return searchNode(root->right,k);
}
};

void logInExitMenu(){
    cout << "\nLogin\nExit" ;
}
void loginUserMenu(){
    cout << "\n1-List all friends\n"<<
    "2-Search by username\n"<<
    "3-Add friend\n"<<
    "4-Remove friend\n"<<
    "5-People you may know\n"<<
    "6-logout\n" ;
}

int main()
{

    linkedList myList;
    string username, name, email;
    ifstream read ("all-users.in.txt");
    if(read.is_open())
    {
        while(getline(read,username,',') && getline(read, name, ',') && getline(read,email))
        {
            user myUser;
            myUser.setUsername(username);
            myUser.setName(name);
            myUser.setEmail(email);
            myList.insert(myUser);

        }
    }

    // Start Program

    while(true){
        string choose ;
        logInExitMenu() ;
        cout << "\nenter Your Choose: " ;
        cin >> choose ;
        if( choose == "Login" ){
            //continue using prgram
            cout << "\nEnter Your Username to be login: " ;
            string loginUsername ; cin >> loginUsername ;
            user loginUser = myList.getUser(loginUsername) ;
            //here i shoud go find for this user in linkedlist
            //if found continue program if not exit
            if( loginUser.getUsername() == "no User" ){
                cout << "\nSorry you are't in the users list\n" ;
                break;
            }else{
                //here i sure this user in list
                bool logout = false ;
                cout << "\nWelcome Back " << loginUser.getUsername() << " :)" ;
                while(true){
                    if( logout )
                        break ;
                    loginUserMenu() ;
                    cout << "\nenter your Choose " << loginUser.getUsername()<<": "  ;
                    int chooseNum ; cin >> chooseNum ;
                    switch( chooseNum ){
                        case 1:{
                            loginUser.listFriends() ;
                            break ;
                        }
                        case 2:{
                            string searchUser ;
                            cout << "\nEnter The User Username To Search for it : " ;
                            cin >> searchUser ;
                            loginUser.search(searchUser) ;
                            break ;
                        }
                        case 3:{
                            string add ;
                            cout << "\nEnter User Username to add him to your Friend List : " ;
                            cin >> add ;
                            user addUser = myList.getUser(add) ;
                            if( addUser.getUsername() == "no User" ){
                                cout << "\nSorry this User is't in the users list\n" ;
                                break;
                            }else{
                                loginUser.addFriend(addUser) ;
                            }
                            break ;
                        }
                        case 4:{
                            string del ;
                            cout << "\nEnter User Username to delete him from your Friend List : " ;
                            cin >> del ;
                            user delUser = myList.getUser(del) ;
                            //here i shoud go find for this user in linkedlist
                            //if found continue program if not exit
                            if( delUser.getUsername() == "no User" ){
                                cout << "\nSorry this User is't in the users list\n" ;
                                break;
                            }else{
                                loginUser.deleteFriend(delUser) ;
                            }
                            break ;
                        }
                        case 5:{
                            cout << "\nPeople you "<< loginUser.getUsername() <<" may know is/are\n" ;
                            user u = user() ;
                            int count = 5 ;
                            for (linkedList::iterator it = myList.begin(); it != myList.end(); ++it) {

                                u = loginUser.FriendBST->find((*it).getUsername()) ;
                                if( u.getUsername() == "no User" && loginUser.getUsername() != (*it).getUsername() ){
                                    (*it).print() ;
                                    cout << "\n---------------------\n"  ;
                                    if( !--count ){
                                        break ;
                                    }
                                }
                            }
                            break ;
                        }
                        case 6:{
                            cout << "\nGood Bye " << loginUser.getUsername() << " :D";
                            logout = true ;
                            break ;
                        }
                        default:{
                            cout << "\nMake Sure You Choose One of The List Numbers" ;
                        }
                    }
                }
            }

        }else if(choose == "Exit"){
            //exit from main function
            cout << "\nGood By :)" ;
            break ;
        }else{
            cout << "\nMake Sure That You are Choose One of" ;
            continue ;
        }

    }//end while

    // End Program

    return 0;
}
