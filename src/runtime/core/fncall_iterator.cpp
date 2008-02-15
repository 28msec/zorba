#include "errors/error_factory.h"
#include "runtime/item_sequence.h"
#include "functions/stateless_function.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/fncall_iterator.h"
#include "functions/function.h"
#include "runtime/base/plan_iterator_wrapper.h"

namespace xqp {

Item_t UDFunctionCallIterator::nextImpl(PlanState& planState)
{
  Item_t lSequenceItem;
  UDFunctionCallIteratorState *state;

  DEFAULT_STACK_INIT(UDFunctionCallIteratorState, state, planState);

  // TODO maybe this can be done in open
  state->thePlan = theUDF->get_plan().getp();
  state->theFnBodyStateBlock = theUDF->create_plan_state();

  // Bind the args.
  {
    std::vector<ref_iter_t>& iters = theUDF->get_param_iters();
    for(uint32_t i = 0; i < iters.size (); ++i) {
      ref_iter_t& ref = iters[i];
      if (ref != NULL) {
        ref->bind(new PlanIteratorWrapper(theChildren[i], planState), *state->theFnBodyStateBlock);
      }
    }
  }

  while((lSequenceItem = consumeNext(state->thePlan, *state->theFnBodyStateBlock)) != NULL) {
    STACK_PUSH(lSequenceItem, state);
  }

  STACK_END();
}

UDFunctionCallIteratorState::UDFunctionCallIteratorState()
  : theFnBodyStateBlock(NULL),
    thePlan(NULL) { }

UDFunctionCallIteratorState::~UDFunctionCallIteratorState()
{
  if (theFnBodyStateBlock != NULL) {
    delete theFnBodyStateBlock;
  }
}

void UDFunctionCallIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  reset(planState);
}

void UDFunctionCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if (theFnBodyStateBlock != NULL) {
    delete theFnBodyStateBlock;
  }

  theFnBodyStateBlock = NULL;
  thePlan = NULL;
}

class ExtFuncArgItemSequence : public ItemSequence {
  public:
    ExtFuncArgItemSequence(PlanIter_t child, PlanState& stateBlock)
      : m_child(child),
      m_stateBlock(stateBlock) { }

    Item_t next() { return m_child->consumeNext(m_child.getp(), m_stateBlock); }

  private:
    PlanIter_t m_child;
    PlanState& m_stateBlock;
};

StatelessExtFunctionCallIteratorState::StatelessExtFunctionCallIteratorState() { }

StatelessExtFunctionCallIteratorState::~StatelessExtFunctionCallIteratorState() { }

void StatelessExtFunctionCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  m_result = NULL;
}

StatelessExtFunctionCallIterator::StatelessExtFunctionCallIterator(const yy::location& loc,
    std::vector<PlanIter_t>& args,
    const StatelessExternalFunction *function)
  : NaryBaseIterator<StatelessExtFunctionCallIterator, StatelessExtFunctionCallIteratorState>(loc, args),
    m_function(function) { }

void StatelessExtFunctionCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<StatelessExtFunctionCallIterator, StatelessExtFunctionCallIteratorState>::openImpl(planState, offset);
  StatelessExtFunctionCallIteratorState *state = StateTraitsImpl<StatelessExtFunctionCallIteratorState>::getState(planState, this->stateOffset);
  int n = theChildren.size();
  state->m_extArgs.resize(n);
  for(int i = 0; i < n; ++i) {
    state->m_extArgs[i] = new ExtFuncArgItemSequence(theChildren[i], planState);
  }
}

Item_t StatelessExtFunctionCallIterator::nextImpl(PlanState& planState)
{
  StatelessExtFunctionCallIteratorState *state;
  Item_t lSequenceItem;
  DEFAULT_STACK_INIT(StatelessExtFunctionCallIteratorState, state, planState);

  state->m_result = m_function->evaluate(state->m_extArgs);
  while((lSequenceItem = state->m_result->next()) != NULL) {
    STACK_PUSH(lSequenceItem, state);
  }

  STACK_END();
}

}

/* vim:set ts=2 sw=2: */
