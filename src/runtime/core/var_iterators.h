#ifndef XQP_RUNTIME_VAR_ITERATORS
#define XQP_RUNTIME_VAR_ITERATORS

#include "context/common.h"
#include "util/tracer.h"
#include "compiler/parser/location.hh"
#include "runtime/base/iterator.h"
#include "runtime/base/noarybase.h"
#include "system/zorba_engine.h"

namespace xqp
{

class Item;


/*******************************************************************************

  FOR variables

********************************************************************************/
class ForVarIterator : public NoaryBaseIterator<ForVarIterator>
{
protected:
  class ForVarState : public PlanIteratorState 
  {
  public:
    Item_t theValue;
  };

protected:
  xqpString     theVarName;
  const void  * theOrigin;  ///< origin expr, used as a kind of ID
  
public:
  ForVarIterator(xqpString vn, yy::location loc, const void* origin);

  ~ForVarIterator() { }
  
  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(ForVarState); }

  void accept(PlanIterVisitor&) const;
  
public:
  xqp_string getVarName() const { return theVarName; }

  void bind(Item_t value, PlanState& planState);
};


/*******************************************************************************

  If a variable can hold more than one item, use this ref-holder
  
********************************************************************************/
class LetVarIterator : public NoaryBaseIterator<LetVarIterator>
{
protected:
  class LetVarState : public PlanIteratorState 
  {
  public:
    Iterator_t theSourceIter;
  };

private:
  xqpString    theVarName;
  const void  * theOrigin;  ///< like origin in var_iterator
  
public:
  LetVarIterator(xqpString vn, yy::location loc, const void *origin);

  ~LetVarIterator() {}
  
  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(LetVarState); }
  
  void accept(PlanIterVisitor&) const;

public:
  xqp_string getVarName() const { return theVarName; }

  void bind(Iterator_t it, PlanState& planState);
};


} 
#endif

