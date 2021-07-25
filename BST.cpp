#include <iostream>
#include"BST.h"
#include<queue>
#include<fstream>

void BST:: clear(Node * & ptr) {
    if( ptr != NULL ){
        clear(ptr -> left) ;
        clear(ptr -> right) ;
        delete ptr ;
        ptr = NULL ;
        length = 0 ;
    }
}

int BST::getLength(){
    return length ;
}
BST::BST(){
    root = NULL ;
    length = 0 ;
}

BST::BST(BST &source)
{
    if(source.root == NULL)
        root = NULL;
    else
        copyTree(this->root, source.root);
}

void BST::copyTree(Node *thisRoot, Node *sourceRoot)
{
    if(sourceRoot == NULL)
    {
        thisRoot = NULL;
    }
    else
    {
        thisRoot = new Node();
        thisRoot->p = sourceRoot->p;
        copyTree(thisRoot->left, sourceRoot->left);
        copyTree(thisRoot->right, sourceRoot->right);
    }
}

BST::~BST(){
    clearTree() ;
}

bool BST::isEmpty(){
    return ( root == NULL ) ;
}

void BST::clearTree(){
    if( !isEmpty() ){
        clear(root) ;
    }

}

Node BST::getRoot() {
    return *root;
}


user BST::find(string userName){
    Node *ptr = root;
    user res = user();
    while(ptr != NULL){
        if( userName == ptr->p.getUsername() ) {
            res = ptr -> p ;
            return res;
        }
        else if( userName < ptr->p.getUsername() )
            ptr = ptr -> left ;
        else
            ptr = ptr -> right ;
    }
    return res ;
}


void BST::insert(user p){
    Node *newNode = new Node(p) ;
    if( isEmpty() ){
        root = newNode ;
        cout << "\nYou are now friends\n" <<endl;

        length++ ;
        return ;
    }else{
        Node * cur = root ;
        Node * prevCur;

        while( cur != NULL ){
            prevCur = cur ;
            if( p.getUsername() < cur -> p.getUsername() )
                cur = cur -> left ;
            else if(p.getUsername() > cur -> p.getUsername() )
                cur = cur -> right ;
            else{
                cout << "\nyou are already freinds\n" ;
                return ;
            }
        }

        if( p.getUsername() < prevCur -> p.getUsername()){
            prevCur -> left = newNode  ;
        }else{
            prevCur -> right = newNode ;
        }
        cout << "\nYou are now friends\n" <<endl;

        length++ ;
    }
}

void BST::insertBack(user p){
    Node *newNode = new Node(p) ;
    if( isEmpty() ){
        root = newNode ;
        length++ ;
        return ;
    }else{
        Node * cur = root ;
        Node * prevCur;

        while( cur != NULL ){
            prevCur = cur ;
            if( p.getUsername() < cur -> p.getUsername() )
                cur = cur -> left ;
            else if(p.getUsername() > cur -> p.getUsername() )
                cur = cur -> right ;
            else{
                return ;
            }
        }

        if( p.getUsername() < prevCur -> p.getUsername()){
            prevCur -> left = newNode  ;
        }else{
            prevCur -> right = newNode ;
        }

        length++ ;
    }
}

void BST::remove(string userName){

	Node *current;  //pointer to traverse the tree
	Node *prev; //pointer behind current
    if(!isEmpty()){

        if(root->p.getUsername() == userName)
        {
            removeThis(root);
            return;
        }

        prev = root;
        if(root->p.getUsername() > userName)
            current = root->left;
        else
            current = root->right;
        while(current != NULL)
        {
            if(current->p.getUsername() == userName)
                break;
            else
            {
                prev = current;
                if(current->p.getUsername() > userName)
                    current = current->left;
                else
                    current = current->right;
            }
        }
        if(current == NULL)
            cout<<"Do nothing"<<endl;
        else if(prev->p.getUsername() > userName)
            removeThis(prev->left);
        else
            removeThis(prev->right);
    }else{
        cout<<"Do nothing"<<endl;
		return;
    }
}

void BST::removeThis(Node* &removed){
        Node * prev;
        Node * temp = removed;
        if( removed -> left == NULL ){
            removed = removed -> right ;
        }
        else if( removed -> right == NULL ){
            removed = removed -> left ;
        }
        else{
            temp = removed -> left ;
            prev = removed ;
            while( temp -> right != NULL ){
                prev = temp ;
                temp = temp -> right ;
            }
            removed -> p.setUsername(temp->p.getUsername());
            removed -> p.setName(temp->p.getName());
            removed -> p.setEmail(temp->p.getEmail());
            removed -> p.FriendBST->clearTree() ;
            removed -> p.setFriends(temp->p.getFriends());

            if( prev == removed )
                prev -> left = temp -> left ;
            else
                prev -> right = temp -> left ;
        }
        cout << "\nDone\n" ;
        length-- ;
        delete temp ;
}

void BST::printBreadthFirst(){
    queue<Node *> q ;
    Node *ptr = root ;
    if(ptr != NULL){
        q.push(ptr) ;
        while( !q.empty() ){
            ptr = q.front() ;
            q.pop() ;
            ptr->p.print() ;
            if( ptr -> left )
                q.push(ptr -> left) ;
            if( ptr -> right )
                q.push(ptr -> right ) ;
            cout <<"\n--------------------\n";
        }
    }else{
        cout << "Tree is Empty\n" ;
    }
    cout<<endl ;
}


void BST::loadFile(){
     string data;
     ifstream file("all-users-relations.in.txt");
     Node*node;
     if(file.is_open()){
        while(getline(file,data))
        {
             user u1;
             BST b;

            b.insert(u1);

        }

    }

}
