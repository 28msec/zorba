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
#include "compiler/parser/location.hh"
#include "runtime/core/batching.h"
#include "runtime/iterators.h"

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
class EmptyIterator : public Batcher<EmptyIterator>
{
public:
	EmptyIterator(yy::location loc) : Batcher<EmptyIterator>(loc) {}
	EmptyIterator(const EmptyIterator& it) : Batcher<EmptyIterator>(it) {}
	~EmptyIterator() {}
	
	Item_t nextImpl(IteratorTreeStateBlock& stateBlock) { return NULL; }
	void resetImpl(IteratorTreeStateBlock& stateBlock)  { }
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
	virtual void setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset);
};

// FIXME No expressions in iterators!!
class var_iterator : public SingletonIterator
{
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

	
	virtual int32_t getStateSize();
	virtual int32_t getStateSizeOfSubtree();
	virtual void setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset);
	
	std::ostream&  _show(std::ostream& os) const;

};


/**
 	* Used to make the casting and concatenation of 
 	* atomic values in the sequences of an enclosed expression.
 	*/
class EnclosedIterator : public UnaryBaseIterator<EnclosedIterator>
{
protected:
  class EnclosedState : public BasicIteratorState
  {
  public:
    xqp_string theString;
    Item_t theContextItem;

    void init();
  };

public:
  EnclosedIterator(const yy::location& loc, Iterator_t& childIter);

  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  int32_t getStateSize() { return sizeof(EnclosedState); }

  void setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset);
}; /* class EnclosedIterator */

	
/**
  * Used to make e.g. the concatenation of text nodes
	* in the content of an element constructor.
	*/
class ElementContentIterator : public UnaryBaseIterator<ElementContentIterator>
{
protected:
  class ElementContentState : public BasicIteratorState
  {
  public:
    xqp_string theString;
    Item_t theContextItem;

    void init();
  };

public:
  ElementContentIterator(const yy::location& loc, Iterator_t& childIter);

  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  int32_t getStateSize() { return sizeof(ElementContentState); }

  void setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset);
}; /* class TextNodeConnector */


class ElementIterator : public Batcher<ElementIterator>
{
private:
  Item_t theQName;
  Iterator_t theChildren;
  Iterator_t theAttributes;
  Iterator_t theNamespaceBindings;
	
public:
  ElementIterator(
        const yy::location& loc, 
        const Item_t& qname,
        Iterator_t& children,
        Iterator_t& attributes);
	
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

	std::ostream& _show(std::ostream& os) const;

  virtual int32_t getStateSize();
  virtual int32_t getStateSizeOfSubtree();
  virtual void setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset);
}; /* class ElementIterator */
	

class AttributeIterator : public UnaryBaseIterator<AttributeIterator>
{
private:
  Item_t theQName;
		
public:
  AttributeIterator(
        const yy::location& loc,
        const Item_t& qname,
        Iterator_t& value);
		
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
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
        bool condIsBooleanIter_arg = false);
		
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
}; /* class IfThenElseIterator */


}	/* namespace xqp */
#endif	/* XQP_ITEM_ITERATOR_H */

