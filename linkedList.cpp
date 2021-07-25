#include"linkedList.h"
#include<iostream>
using namespace std;

linkedList::linkedList()
{
  head = tail = 0;
  length = 0;
}

void linkedList::insert (user insertUser)
{
    node*newNode=new node();
    newNode->data= insertUser;
    newNode->next= 0;
    if(head== 0)
    {
        head=newNode;
        tail=newNode;
        newNode= 0;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
    length++ ;
}

int linkedList::getLength(){
    return length ;
}

void linkedList::print()
{
    node *ptr=new node();
    ptr = head;
    if(ptr == 0){
        cout <<"list is empty\n" ;
    }else{

        while(ptr!= 0)
        {
            ptr->data.print() ;
            cout <<"\n---------------------------------------------------\n" ;
            ptr=ptr->next;
        }
        cout<<endl;
    }
}

user linkedList::getFirst(){
    user res = user() ;
    if( isEmpty() ){
        return res ;
    }else{
        res = head->data ;
        return res;
    }
}

user linkedList::getUser(string userName){
    user res = user() ;
    if( isEmpty() ){
        return res ;
    }else{
        node *ptr = head ;
        while( ptr != NULL ){
            if( ptr->data.getUsername() == userName){
                res =ptr->data ;
                return res ;
            }
            ptr = ptr->next ;
        }
        return res ;
    }

}

bool linkedList::isEmpty(){
    return ( length = 0 ) ;
}

linkedList::iterator linkedList::begin()
{
	return iterator(head);
}

linkedList::iterator linkedList::end()
{
	return iterator(tail->next);
}
