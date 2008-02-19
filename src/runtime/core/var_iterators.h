#ifndef XQP_RUNTIME_VAR_ITERATORS
#define XQP_RUNTIME_VAR_ITERATORS

#include "common/shared_types.h"
#include "util/utf8/xqpString.h"
#include "runtime/base/noarybase.h" // TODO remove after iterator refactoring

namespace xqp
{

class Item;


/*******************************************************************************

  FOR variables. A ForVarIterator represents a reference to a for variable.

********************************************************************************/
class ForVarState : public PlanIteratorState 
{
public:
  Item_t theValue;

  void init(PlanState& planState) { PlanIteratorState::init(planState); }
  void reset(PlanState& planState) { PlanIteratorState::reset(planState); }
};

class ForVarIterator : public NoaryBaseIterator<ForVarIterator, ForVarState>
{
protected:
  xqpString     theVarName;
  const void  * theOrigin;  ///< origin expr, used as a kind of ID
  
public:
  ForVarIterator(xqpString vn, yy::location loc, const void* origin);

  ~ForVarIterator() { }
  
  Item_t nextImpl(PlanState& planState) const;

  void accept(PlanIterVisitor&) const;
  
public:
  xqpString getVarName() const { return theVarName; }

  void bind(Item_t value, PlanState& planState);
};


/*******************************************************************************

  LET variables. A LetVarIterator represents a reference to a let variable.
  
  theSourceIter is a PlanIteratorWraper. The wrapper may wrap the actual
  expression that defines the var, or an iterator over a temp sequence, if
  the result of the defining expression has been materialized.
********************************************************************************/
class LetVarState : public PlanIteratorState 
{
public:
  Iterator_t theSourceIter;
  LetVarState();
  ~LetVarState();
  void init(PlanState& planState) { PlanIteratorState::init(planState); }
  void reset(PlanState& planState);
};

class LetVarIterator : public NoaryBaseIterator<LetVarIterator, LetVarState>
{
private:
  xqpString    theVarName;
  const void  * theOrigin;  ///< like origin in var_iterator
  
public:
  LetVarIterator(xqpString vn, yy::location loc, const void *origin);

  ~LetVarIterator() {}
  
  Item_t nextImpl(PlanState& planState) const;

  void accept(PlanIterVisitor&) const;

public:
  xqpString getVarName() const { return theVarName; }

  void bind(Iterator_t it, PlanState& planState);
};


} 
#endif

