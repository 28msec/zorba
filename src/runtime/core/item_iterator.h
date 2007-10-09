/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- *
 *  $Id: item_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ITEM_ITERATOR_H
#define XQP_ITEM_ITERATOR_H

#include "context/common.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "parser/location.hh"
#include "batching.h"

#include <assert.h>
#include <iostream>
#include <vector>

namespace xqp {

class Item;
class node;
class zorba;

class var_iterator;
typedef rchandle<var_iterator> var_iter_t;


/*
public:		// "treat as" operators
	string_iterator& treat_as_string();
	node
	document
	element
	attribute
	namespace
	pi
	comment
	text
	string
	numeric	
	boolean
	time
	binary
	qname
	sequence

*/

class SingletonIterator;
typedef rchandle<SingletonIterator> singleton_t;

/** Class represents an empty sequence.
	*/
class EmptyIterator : public Batcher<EmptyIterator> {
public:
	EmptyIterator(yy::location loc) : Batcher<EmptyIterator>(loc) {}
	EmptyIterator(const EmptyIterator& it) : Batcher<EmptyIterator>(it) {}
	~EmptyIterator() {}
	
	Item_t nextImpl(IteratorTreeStateBlock& stateBlock) {
		return NULL;
	}
	void resetImpl(IteratorTreeStateBlock& stateBlock) { }
	void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock){ }
}; /* class EmptyIterator */

/*_____________________________________________________________
|
|	literals and for_var bindings
|______________________________________________________________*/
class SingletonIterator : public Batcher<SingletonIterator>
{
protected:
	Item_t i_h;

public:
	SingletonIterator(yy::location loc, Item_t _i_p);
	~SingletonIterator();
	
public:
	Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
	void resetImpl(IteratorTreeStateBlock& stateBlock);
	void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
	
	std::ostream&  _show(std::ostream& os)	const;

	virtual int32_t getStateSize();
	virtual int32_t getStateSizeOfSubtree();
	virtual void setOffset(int32_t& offset);
};

// FIXME No expressions in iterators!!
class var_iterator : public SingletonIterator {
protected:
	string s_h;
	
public:
	var_iterator(string s_p, yy::location loc) : 
							SingletonIterator(loc,NULL), 
							s_h(s_p){}
	~var_iterator(){
		
	}
	
public:		// variable binding
	void bind(Item_t _i_h) { i_h = _i_h; }
};

/*
template<class T>
class SingletonIterator : public item_iterator
{
protected:
	const T* val;
	bool done_b;

public:
	SingletonIterator(T _val) : val(_val), done_b(false) { }
	SingletonIterator(const SingletonIterator& it) : val(it.val), done_b(false) { }
	~SingletonIterator() {}

public:	// iterator interface
	void open() {}
	void close() {}
	Item_t next(uint32_t delta = 1) { done_b = true; return val; }
	Item_t peek() const { return val; }
	bool done() const { return done_b; }

public:
	SingletonIterator& operator=(const SingletonIterator& it)
		{ val = it.val; done_b = it.done_b; }

};
*/



/*_____________________________________________________________
|
|	let_var bindings
|______________________________________________________________*/

// class RefIterator : public BasicIterator
// {
// private:
// 	Iterator_t it;
// 
// public:
// 	RefIterator(Iterator_t _it,yy::location loc) : 
// 										BasicIterator(loc),
// 										it(_it) {}
// 
// public:
// 	void _open() { it->open();  }
// 	Item_t _next() { return it->next(); }
// 	void _close() { it->close(); }
// 	std::ostream&  _show(std::ostream& os) const {return os;}
// 	bool done() const { return it->done(); }
// 	void bind(Iterator_t _it) { it = _it;}
// 
// };



/*_____________________________________________________________
|
|	for $x in  _input_  return  _expr_
|______________________________________________________________*/
class MapIterator : public Batcher<MapIterator>
{
private:
// 	enum state {
// 		outer,
// 		inner
// 	};

	Iterator_t theInput;
	Iterator_t theExpr;
	std::vector<var_iter_t> varv;
// 	enum state theState;

public:
	MapIterator(
		yy::location loc,
		Iterator_t _input,
		Iterator_t _expr,
		std::vector<var_iter_t> _varv)
	:
		Batcher<MapIterator>(loc),
		theInput(_input),
		theExpr(_expr),
		varv(_varv)
	{}

	~MapIterator() {}

public:
	Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
	void resetImpl(IteratorTreeStateBlock& stateBlock);
	void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
// 	void _open();
// 	void _close();
	std::ostream&  _show(std::ostream& os) const;
// 	bool done() const;

};

	/**
	 * class which can be used as superclass for an iterator 
	 * which does the filtering of the resulting items of one iterator.
	 */	
	class FilterIterator : public Batcher<FilterIterator>
	{
	protected:
		Iterator_t content;
		
	public:
		FilterIterator(
			const yy::location& loc,
			Iterator_t& iter_arg
		);
		virtual ~FilterIterator();
		
		virtual Item_t nextImpl(IteratorTreeStateBlock& stateBlock) = 0;
		void resetImpl(IteratorTreeStateBlock& stateBlock);
		void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
	}; /* class FilterIterator */
	
	/**
	 	* Used to make the casting and concatenation of 
	 	* atomic values in the sequences of an enclosed expression.
	 	*/
	class EnclosedIterator : public FilterIterator
	{
	private:
		xqp_string str;
		Item_t item;
		
	public:
		EnclosedIterator(
			const yy::location& loc,
			Iterator_t& iter_arg
		);
		Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
	}; /* class EnclosedIterator */
	
	/** Used to make e.g. the concatenation of text nodes
		* in the content of an element constructor.
		*/
	class ElementContentIterator : public FilterIterator
	{
	private:
		xqp_string str;
		Item_t item;
	public:
		ElementContentIterator(
			const yy::location& loc,
			Iterator_t& iter_arg
		);
		Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
	}; /* class TextNodeConnector */

	class ElementIterator : public Batcher<ElementIterator>
	{
	private:
		Item_t qname;
		Iterator_t children;
		Iterator_t attributes;
		Iterator_t namespaceBindings;
	
	public:
		ElementIterator(
			const yy::location& loc, 
			const Item_t& qname_arg,
			Iterator_t& children_arg,
			Iterator_t& attributes_arg
		);
	
		Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
		void resetImpl(IteratorTreeStateBlock& stateBlock);
		void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
	}; /* class ElementIterator */
	
	class AttributeIterator : public Batcher<AttributeIterator>
	{
	private:
		Item_t qname;
		Iterator_t value;
		
	public:
		AttributeIterator(
			const yy::location& loc,
			const Item_t& qname_arg,
			Iterator_t& value_arg
		);
		
		Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
		void resetImpl(IteratorTreeStateBlock& stateBlock);
		void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
	}; /* class AttributeIterator */
	
	class IfThenElseIterator : public Batcher<IfThenElseIterator>
	{
	private:
		Iterator_t iterCond;
		Iterator_t iterThen;
		Iterator_t iterElse;
		bool condIsBooleanIter;
		
		// helping member so save the active iterator (then or else)
		Iterator_t iterActive;
		
	public:
		/**
		 * Constructor
		 * @param loc location
		 * @param iterCond_arg represents condition
		 * @param iterThen_arg represents then expression
		 * @param iterElse_arg represents else expression
		 * @param condIsBooleanIter Optional flag. If true => condition is already an iterator 
		 * 															which return true or false => the conditional value
		 *															does not have to be evaluated with the effective
		 *															boolean value function
		 */
		IfThenElseIterator(
			const yy::location& loc,
			Iterator_t& iterCond_arg,
			Iterator_t& iterThen_arg,
			Iterator_t& iterElse_arg,
			bool condIsBooleanIter_arg = false
		);
		
		Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
		void resetImpl(IteratorTreeStateBlock& stateBlock);
		void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
	}; /* class IfThenElseIterator */


}	/* namespace xqp */
#endif	/* XQP_ITEM_ITERATOR_H */

