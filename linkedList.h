#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include"user.h"

struct node
{
    user data;
    node *next;
};

class linkedList
{
private:
    node *head;
    node *tail;
    int length ;
public:

	class iterator {
		node* cur;
		friend class LinkedList;
	public:
		iterator(node* n) : cur(n) {}
		iterator operator++() {
			cur = cur->next;
			return *this;
		}
		bool operator!=(iterator it) {
			return cur != it.cur;
		}
		user& operator*() {
			return cur->data ;
		}
	};
    linkedList();
    void insert (user insertUser);
    void print ();
    int getLength() ;
    user getFirst() ;
    user getUser(string userName) ;
    bool isEmpty() ;
    iterator begin();
    iterator end();
};


#endif // LINKEDLIST_H_INCLUDED
