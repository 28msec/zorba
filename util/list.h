/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: list.h,v 1.1 2006/10/09 07:07:57 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 *	Author: Paul Pedersen
 *
 */

#ifndef XQP_LIST_H
#define XQP_LIST_H

#include "xqp_exception.h"

namespace xqp {

template <class T>
class list_node
{
public:
  T data;
  list_node* next;
  list_node* prev;
  list_node() : data(T()), next(0), prev(0) {}
  list_node(T d, list_node* n, list_node* p) : data(d), next(n), prev(p) {}
	~list_node() {}
};


template <class T>
class list_iterator
{
protected:
  list_node<T>* curr;
public:
  list_iterator& operator++() { curr = curr->next; return *this; }
  T& operator*() { return curr->data; }
	list_node<T>* get_curr() { return curr; }
  list_iterator(list_node<T>* n) : curr(n) {}
	~list_iterator() {}
	bool operator!=(const list_iterator& a) { return curr!=a.curr; }
	bool operator==(const list_iterator& a) { return curr==a.curr; }
};


template<class T> class list;
template<class T> list<T> operator*(const list<T>&, const list<T>&);		// intersection
template<class T> list<T> operator+(const list<T>&, const list<T>&);		// union


template <class T>
class list
{ 
protected:
  list_node<T>* head;	// dummy node points to first element
  list_node<T>* tail;	// dummy node	pointed to by last element
	uint32_t sz;

/*....................................................................
:                                                                
:         _______                                      _______
:   .--->|___0___|<--head                      tail-->|___0___|<-.
:   | .--|_______|                                    |_/_/_/_|  |
:   | |  |_/_/_/_|                                    |___.___|  |
:   | |next                                               |prev  |
:   | |                                                   |      |next
:   | |   _______        _______        _______        ___v___   |
:   | `->|___T___| next |___T___| next |___T___| next |___T___|  |
:   |    |_______|----->|_______|----->|_______|----->|_______|--'
:   `----|_______|<-----|_______|<-----|_______|<-----|_______| 
:    prev          prev           prev           prev
:
:......................................................................*/

public:
  list();
	~list();

public:	// list value interface
  void push_back(const T&);
  T pop_front();

public: // listnode interface
	void insert_after(list_node<T>* oldlist_node, list_node<T>* newlist_node);
	void remove(list_node<T>* node);
	list_node<T>* get_head() const { return head->next; }
	list_node<T>* get_tail() const { return tail->prev; }
	uint32_t size() { return sz; }

public:
  list_iterator<T> begin() const { return list_iterator<T>(head->next); }
  list_iterator<T> end() const { return list_iterator<T>(tail); }

public:
	friend list operator*<>(const list&, const list&);		// intersection
	friend list operator+<>(const list&, const list&);		// union
};


template<class T>
list<T>::list()
: head(new list_node<T>()),
	tail(new list_node<T>()),
	sz(0)
{
	head->next = tail;
	head->prev = NULL;
	tail->prev = head;
	tail->next = NULL;
}


template<class T>
list<T>::~list()
{
}


template<class T>
void list<T>::push_back(const T& d)
{
	list_node<T>* n = new list_node<T>(d,tail,tail->prev);
	tail->prev->next = n;
  tail->prev = n;
	sz++;
}


template<class T>
T list<T>::pop_front()
{
	if (sz==0) {
		throw xqp_exception("list::pop_front", "list empty");
	}
	list_node<T>* front_node = head->next;
	T result = front_node->data;
	head->next = front_node->next;
	front_node->next->prev = head;
	sz--;
	delete front_node;
	return result;
}


template<class T>
void list<T>::insert_after(list_node<T>* oldnode, list_node<T>* newnode)
{
	newnode->next = oldnode->next;
	newnode->prev = oldnode;
	oldnode->next->prev = newnode;
	oldnode->next = newnode;
	sz++;
}


template<class T>
void list<T>::remove(list_node<T>* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	sz--;
}


// intersection
template<class T>
list<T> operator*(const list<T>& a, const list<T>& b)
{
	list<T> result;
	list_iterator<T> i1 = a.begin();
	list_iterator<T> i2 = b.begin();
	while (i1!=a.end() && i2!=b.end())
	{
		if (*i1 < *i2) {
			++i1;
		}
		else if (*i2 < *i1) {
			++i2;
		}
		else {
			result.push_back(*i1);
			++i1;
			++i2;
		}
	}
	return result;
}


// union
template<class T>
list<T> operator+(const list<T>& a, const list<T>& b)
{
	list<T> result;
	list_iterator<T> i1 = a.begin();
	list_iterator<T> i2 = b.begin();
	while (i1!=a.end() || i2!=b.end())
	{
		if (i2==b.end() || *i1 < *i2) {
			result.push_back(*i1);
			++i1;
		}
		else if (i1==a.end() || *i2 < *i1) {
			result.push_back(*i2);
			++i2;
		}
		else {
			result.push_back(*i1);
			++i1;
			++i2;
		}
	}
	return result;
}

}	/* namespace xqp */
#endif	/* XQP_LIST_H */
