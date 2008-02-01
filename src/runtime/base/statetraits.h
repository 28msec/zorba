#ifndef XQP_STATETRAITS_H
#define XQP_STATETRAITS_H

#include "runtime/base/iterator.h"

namespace xqp {

template <class T>
class StateTraitsImpl
{
private:
  StateTraitsImpl() {} // prevent instantiation
public:
  static uint32_t getStateSize() 
  { 
    return sizeof(T); 
  }

  static void createState(PlanState& planState, uint32_t& stateOffset, uint32_t& offset)
  {
    stateOffset = offset;
    offset += StateTraitsImpl<T>::getStateSize();
    new (planState.theBlock + stateOffset)T();
  }

  static void destroyState(PlanState& planState, uint32_t stateOffset) 
  { 
    (reinterpret_cast<T*>(planState.theBlock + stateOffset))->~T(); 
  }

  static void reset(PlanState& planState, uint32_t stateOffset)
  {
    (reinterpret_cast<T*>(planState.theBlock+ stateOffset))->reset(planState);
  }
};

} /* namespace xqp */
#endif
