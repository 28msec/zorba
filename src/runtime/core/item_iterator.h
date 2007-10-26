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
#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h"

#include <assert.h>
#include <iostream>
#include <vector>

namespace xqp {

class Item;
class node;
class zorba;

class var_iterator;
typedef rchandle<var_iterator> var_iter_t;

class RefIterator;
typedef rchandle<RefIterator> ref_iter_t;


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
	
	Item_t nextImpl(PlanState& planState) { return NULL; }
	void resetImpl(PlanState& planState)  { }
	void releaseResourcesImpl(PlanState& planState){ }

	virtual int32_t getStateSize() { return 0; }
	virtual int32_t getStateSizeOfSubtree() { 
		return 0; 
}
	virtual void setOffset(PlanState& planState, int32_t& offset);
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
	Item_t nextImpl(PlanState& planState);
	void resetImpl(PlanState& planState);
	void releaseResourcesImpl(PlanState& planState);
	
	std::ostream&  _show(std::ostream& os)	const;

	virtual int32_t getStateSize();
	virtual int32_t getStateSizeOfSubtree();
	virtual void setOffset(PlanState& planState, int32_t& offset);
};


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

/**
 * If a variable can hold more than one item, use this ref-holder
 * 
 */
class RefIterator : public Batcher<RefIterator>
{
private:
	PlanIter_t it;
	
	
public:
	RefIterator(string s_p, yy::location loc);
	~RefIterator();
	
public:		// variable binding
	void bind(PlanIter_t _it) { it = _it;}
	Item_t nextImpl(PlanState& planState);
	void resetImpl(PlanState& planState);
    void releaseResourcesImpl(PlanState& planState);
	virtual int32_t getStateSize();
	virtual int32_t getStateSizeOfSubtree();
	virtual void setOffset(PlanState& planState, int32_t& offset);
};



/*_____________________________________________________________
|
|	let_var bindings
|______________________________________________________________*/

// class RefIterator : public PlanIterator
// {
// private:
// 	PlanIter_t it;
// 
// public:
// 	RefIterator(PlanIter_t _it,yy::location loc) : 
// 										PlanIterator(loc),
// 										it(_it) {}
// 
// public:
// 	void _open() { it->open();  }
// 	Item_t _next() { return it->next(); }
// 	void _close() { it->close(); }
// 	std::ostream&  _show(std::ostream& os) const {return os;}
// 	bool done() const { return it->done(); }
// 	void bind(PlanIter_t _it) { it = _it;}
// 
// };



/*******************************************************************************

	for $x in  _input_  return  _expr_

********************************************************************************/
class MapIterator : public Batcher<MapIterator>
{
private:
// 	enum state {
// 		outer,
// 		inner
// 	};

	PlanIter_t theInput;
	PlanIter_t theExpr;
	std::vector<var_iter_t> theVarRefs; // all references of $x inside theExpr
// 	enum state theState;

public:
	MapIterator(
		yy::location loc,
		PlanIter_t input,
		PlanIter_t expr,
		std::vector<var_iter_t> varv)
	:
		Batcher<MapIterator>(loc),
		theInput(input),
		theExpr(expr),
		theVarRefs(varv)
	{}

	~MapIterator() {}

public:
	Item_t nextImpl(PlanState& planState);
	void resetImpl(PlanState& planState);
	void releaseResourcesImpl(PlanState& planState);

	
	virtual int32_t getStateSize();
	virtual int32_t getStateSizeOfSubtree();
	virtual void setOffset(PlanState& planState, int32_t& offset);
	
	std::ostream&  _show(std::ostream& os) const;
};


/**
 	* Used to make the casting and concatenation of 
 	* atomic values in the sequences of an enclosed expression.
 	*/
class EnclosedIterator : public UnaryBaseIterator<EnclosedIterator>
{
protected:
  class EnclosedState : public PlanIteratorState
  {
  public:
    xqp_string theString;
    Item_t theContextItem;

    void init();
  };

public:
  EnclosedIterator(const yy::location& loc, PlanIter_t& childIter);

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  int32_t getStateSize() { return sizeof(EnclosedState); }

  void setOffset(PlanState& planState, int32_t& offset);
}; /* class EnclosedIterator */

	
/**
  * Used to make e.g. the concatenation of text nodes
	* in the content of an element constructor.
	*/
class ElementContentIterator : public UnaryBaseIterator<ElementContentIterator>
{
protected:
  class ElementContentState : public PlanIteratorState
  {
  public:
    xqp_string theString;
    Item_t theContextItem;

    void init();
  };

public:
  ElementContentIterator(const yy::location& loc, PlanIter_t& childIter);

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  int32_t getStateSize() { return sizeof(ElementContentState); }

  void setOffset(PlanState& planState, int32_t& offset);
}; /* class TextNodeConnector */


class ElementIterator : public Batcher<ElementIterator>
{
private:
  Item_t theQName;
  PlanIter_t theChildren;
  PlanIter_t theAttributes;
  PlanIter_t theNamespaceBindings;
	
public:
  ElementIterator(
        const yy::location& loc, 
        const Item_t& qname,
        PlanIter_t& children,
        PlanIter_t& attributes);
	
  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

	std::ostream& _show(std::ostream& os) const;

  virtual int32_t getStateSize();
  virtual int32_t getStateSizeOfSubtree();
  virtual void setOffset(PlanState& planState, int32_t& offset);
}; /* class ElementIterator */
	

class AttributeIterator : public UnaryBaseIterator<AttributeIterator>
{
private:
  Item_t theQName;
		
public:
  AttributeIterator(
        const yy::location& loc,
        const Item_t& qname,
        PlanIter_t& value);
		
  Item_t nextImpl(PlanState& planState);
}; /* class AttributeIterator */
	

class IfThenElseIterator : public Batcher<IfThenElseIterator>
{
private:
  PlanIter_t iterCond;
  PlanIter_t iterThen;
  PlanIter_t iterElse;
  bool condIsBooleanIter;
		
  // helping member so save the active iterator (then or else)
  PlanIter_t iterActive;
		
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
        PlanIter_t& iterCond_arg,
        PlanIter_t& iterThen_arg,
        PlanIter_t& iterElse_arg,
        bool condIsBooleanIter_arg = false);
		
  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);
}; /* class IfThenElseIterator */

class FLWORIterator : public Batcher<FLWORIterator>
{
	
public:
	class ForLetClause{ //Combines FOR and LET to avoid dynamic casts
	  private:
		   enum ForLetType {FOR, LET};
	  
	  private:
		   ForLetType type;
		   std::vector<var_iterator> forVars;
		   std::vector<ref_iter_t> letVars;
		   bool needsMaterialization; 
		   
	  public:
		  /**
	   * Creates a new ForClause
	   * 
	   */
	  ForLetClause(std::vector<var_iterator> forVars);
	  
	  /**
	   * Creates a new LetClause
	   * needsMaterialization indicates if it is necassary to materialize the LET-Binding:
	   * E.g. "let $x := (1,2,3) return ($x, $x)" needs materialization. 
	   * but "let $x := (1,2,3) return if(test()) then $x else $x" doesn't
	  */
	  ForLetClause(std::vector<ref_iter_t> letVars,  bool needsMaterialization);
	}; 

	  /**
	   * See http://www.w3.org/TR/xquery/#id-orderby-return
	   * Collation are skipped so far! We do that later...
	   */
	  class OrderSpec {
	  private:
	     PlanIter_t orderByIter;
	     bool empty_least;
	     bool descending;
	  public:
		  OrderSpec(PlanIter_t orderByIter, bool empty_least, bool descending);
	  };
	  
	  /**
	   * See http://www.w3.org/TR/xquery/#id-orderby-return
	   */
	  class OrderByClause{
	  private:
	     vector<OrderSpec> orderSpecs;
	     bool stable;
	  public:
		  OrderByClause(std::vector<OrderSpec> orderSpecs, bool stable);
	  };
	
private:
  std::vector<FLWORIterator::ForLetClause> forLetClauses; //
  PlanIter_t whereClause; //can be null
  FLWORIterator::OrderByClause* orderByClause;  //can be null
  PlanIter_t returnClause;
	
public:
	/**
	   * Constructor
	   * @param loc location
	   * @param forLetClauses For and Lets: Attention the order matters!
	   * @param whereClause The where-clause iterator. Can be null
	   * @param orderByClause The order by expressions. Can be null
	   * @param returnClause The return expressions
	   * @param whereClauseReturnsBooleanPlus Optional flag. 
	   * 	If true => The iterator has to return xs:boolean+
	   */ 
  FLWORIterator(const yy::location& loc, 
  		  std::vector<FLWORIterator::ForLetClause> forLetClauses, 
  		  PlanIter_t& whereClause, 
  		  FLWORIterator::OrderByClause* orderByClause,  
  		  PlanIter_t& returnClause, 
  		  bool whereClauseReturnsBooleanPlus = false);

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);
  virtual int32_t getStateSize();
  virtual int32_t getStateSizeOfSubtree();
  virtual void setOffset(PlanState& planState, int32_t& offset);
};

}	/* namespace xqp */
#endif	/* XQP_ITEM_ITERATOR_H */

