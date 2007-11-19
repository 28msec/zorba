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
  const void *origin;  ///< origin expr, used as a kind of ID
	
public:
	var_iterator(string s_p, yy::location loc, const void *origin_) : 
							SingletonIterator(loc,NULL), 
							s_h(s_p), origin (origin_)
  {}
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
	Iterator_t it;
	const void *origin;  ///< like origin in var_iterator
	
public:
	RefIterator(string s_p, yy::location loc, const void *origin_)
    : Batcher<RefIterator> (loc), origin (origin_)
  {}
	~RefIterator() {}  // TODO
	
public:		// variable binding
	void bind(Iterator_t _it) { it = _it;}
	Item_t nextImpl(PlanState& planState) { return it->next(); }  // TODO
	void resetImpl(PlanState& planState) { it->reset(); }  // TODO
	void releaseResourcesImpl(PlanState& planState) {  }  // TODO
	virtual int32_t getStateSize() { return 0; }  // TODO
	virtual int32_t getStateSizeOfSubtree() { return 0; }  // TODO
	virtual void setOffset(PlanState& planState, int32_t& offset) {}  // TODO
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
    friend class FLWORIterator;
	  
	  protected:
      enum ForLetType {FOR, LET};   
		   ForLetType type;
		   std::vector<var_iter_t> forVars;
		   std::vector<var_iter_t> posVars;
		   std::vector<ref_iter_t> letVars;
		   PlanIter_t input;
		   bool needsMaterialization; 
		   
	  public:
		  /**
	   * Creates a new ForClause
	   * 
	   */
	  ForLetClause(std::vector<var_iter_t> forVars, PlanIter_t& input);
	  ForLetClause(std::vector<var_iter_t> forVars, std::vector<var_iter_t> posVars, PlanIter_t& input);
   
  public:
    
    std::ostream& show(  std::ostream& os) const;
	  
	  /**
	   * Creates a new LetClause
	   * needsMaterialization indicates if it is necassary to materialize the LET-Binding:
	   * E.g. "let $x := (1,2,3) return ($x, $x)" needs materialization. 
	   * but "let $x := (1,2,3) return if(test()) then $x else $x" doesn't
	  */
	  ForLetClause(std::vector<ref_iter_t> letVars, PlanIter_t& input,bool needsMaterialization);
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
  bool whereClauseReturnsBooleanPlus;    
  const int bindingsNb;
  //State
  int* varBindingState;
  Store* store;
  
protected:
    class ElementContentState : public PlanIteratorState
    {
      public:
        xqp_string theString;
        Item_t     theContextItem;

        void init();
    };   
  
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
  		  std::vector<FLWORIterator::ForLetClause> &forLetClauses,
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
  std::ostream& _show ( std::ostream& os ) const;
  
private:
	void resetInput(int varNb, PlanState& planState);
	bool bindVariable(int varNb, PlanState& planState);
};

}	/* namespace xqp */
#endif	/* XQP_ITEM_ITERATOR_H */

