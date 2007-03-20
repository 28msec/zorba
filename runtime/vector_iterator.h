/* -*- mode: c++; indent-tabs-mode: nil -*- *
 *  $Id: vector_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_VECTOR_ITERATOR_H
#define XQP_VECTOR_ITERATOR_H

#include "abstract_iterator.h"
#include "../util/rchandle.h"
#include <vector>

namespace xqp {

class context;
class item;

class node_vector_iterator :	public item_iterator
{
protected:
	std::vector<const node* >& nodev;
	std::vector<const node* >::const_iterator it;
	std::vector<const node* >::const_iterator end;

public:		// abstract iterator interface
	void open();
	void close();
	abstract_item* next(uint32_t delta = 1);
	abstract_item* peek() const;
	bool done() const;
	void rewind();

public:		// C++ interface
	item* operator*() const;
	node_vector_iterator& operator++();

public:
	node_vector_iterator(
		context *,
		const std::vector<const node*>&);

	node_vector_iterator(const node_vector_iterator&);
	node_vector_iterator& operator=(const node_vector_iterator&);
	~node_vector_iterator();

};


class attribute_vector_iterator :	public item_iterator
{
protected:
	std::vector<const node*>& nodev;
	std::vector<const node*>::const_iterator it;
	std::vector<const node*>::const_iterator end;

public:		// abstract iterator interface
	void open();
	void close();
	abstract_item* next(uint32_t delta = 1);
	abstract_item* peek() const;
	bool done() const;
	void rewind();

public:		// C++ interface
	item* operator*() const;
	attribute_vector_iterator& operator++();

public:
	attribute_vector_iterator(
		context *,
		const std::vector<const attribute_node*>&);

	attribute_vector_iterator(const attribute_vector_iterator&);
	attribute_vector_iterator& operator=(const attribute_vector_iterator&);
	~attribute_vector_iterator();

};


}	/* namespace xqp */
#endif	/* XQP_VECTOR_ITERATOR_H */

