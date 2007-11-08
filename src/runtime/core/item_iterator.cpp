/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "runtime/core/item_iterator.h"
#include "util/Assert.h"
#include "util/zorba.h"
#include "errors/Error.h"
#include "store/api/item.h"
#include "store/api/temp_seq.h"
#include "compiler/expression/expr.h"
#include "runtime/booleans/BooleanImpl.h"

using namespace std;
namespace xqp {

/* begin class EmptyIterator */
void EmptyIterator::setOffset(PlanState& planState, int32_t& offset) {
	this->stateOffset = offset;
	offset += this->getStateSize();
}
/* end class EmptyIterator */

/* begin class SingletonIterator */
SingletonIterator::SingletonIterator(yy::location loc, Item_t _i_p) :
	Batcher<SingletonIterator>(loc), i_h(_i_p) {
}

SingletonIterator::~SingletonIterator() {
}

Item_t SingletonIterator::nextImpl(PlanState& planState) {
	PlanIteratorState* state;
	STACK_INIT2(PlanIteratorState, state, planState);
	STACK_PUSH2(i_h, state);
	STACK_END2();
}

void SingletonIterator::resetImpl(PlanState& planState) {
	PlanIterator::PlanIteratorState* state;
	GET_STATE(PlanIteratorState, state, planState);
	state->reset();
}

void SingletonIterator::releaseResourcesImpl(PlanState& planState) {
}

std::ostream& SingletonIterator::_show(std::ostream& os) const {
	return os;
}

int32_t SingletonIterator::getStateSize() {
	return sizeof(PlanIterator::PlanIteratorState);
}

int32_t SingletonIterator::getStateSizeOfSubtree() {
	return this->getStateSize();
}

void SingletonIterator::setOffset(PlanState& planState, int32_t& offset) {
	this->stateOffset = offset;
	offset += this->getStateSize();
}
/* end class SingletonIterator */

/* begin class MapIterator */
Item_t MapIterator::nextImpl(PlanState& planState) {
	Item_t item;
	vector<var_iter_t>::const_iterator itv;
	PlanIteratorState *state;
	STACK_INIT2(PlanIteratorState, state, planState);

	while ( true) {
		item = this->consumeNext(this->theInput, planState);
		if (item == NULL)
			break;

		itv = theVarRefs.begin();
		for (; itv != theVarRefs.end(); ++itv) {
			( *itv )->bind(item);
		}

		item = this->consumeNext(this->theExpr, planState);
		while (item != NULL) {
			STACK_PUSH2(item, state);
			item = this->consumeNext(this->theExpr, planState);
		}

		this->resetChild(this->theExpr, planState);
	}
	STACK_END2();
}

void MapIterator::resetImpl(PlanState& planState) {
	this->resetChild(this->theInput, planState);
	this->resetChild(this->theExpr, planState);
}

void MapIterator::releaseResourcesImpl(PlanState& planState) {
	this->releaseChildResources(this->theInput, planState);
	this->releaseChildResources(this->theExpr, planState);
}

int32_t MapIterator::getStateSize() {
	return sizeof(PlanIteratorState);
}

int32_t MapIterator::getStateSizeOfSubtree() {
	return theInput->getStateSizeOfSubtree() + theExpr->getStateSizeOfSubtree()
			+ this->getStateSize();
}

void MapIterator::setOffset(PlanState& planState, int32_t& offset) {
	this->stateOffset = offset;
	offset += this->getStateSize();

	theInput->setOffset(planState, offset);
	theExpr->setOffset(planState, offset);
}

std::ostream& MapIterator::_show(std::ostream& os) const {
	theInput->show(os);
	theExpr->show(os);
	return os;
}
/* end class MapIterator */

/* begin class EnclosedIterator */
EnclosedIterator::EnclosedIterator(const yy::location& loc,
		PlanIter_t& childIter) :
	UnaryBaseIterator<EnclosedIterator>(loc, childIter) {
}

Item_t EnclosedIterator::nextImpl(PlanState& planState) {
	EnclosedState* state;
	STACK_INIT2(EnclosedState, state, planState);

	while ( true) {
		state->theContextItem = consumeNext(theChild, planState);
		if (state->theContextItem == NULL) {
			if (state->theString != "") {
				STACK_PUSH2(zorba::getItemFactory()->createTextNode(state->theString), state);
				state->theString = "";
			}
			break;
		} else if (state->theContextItem->isNode() ) {
			if (state->theString != "") {
				STACK_PUSH2(zorba::getItemFactory()->createTextNode(state->theString), state);
				state->theString = "";
			}
			STACK_PUSH2(state->theContextItem, state);
		} else if (state->theString == "") {
			state->theString = state->theContextItem->getStringProperty();
		} else {
			state->theString += " "
					+ state->theContextItem->getStringProperty();
		}
	}
	STACK_END2();
}

void EnclosedIterator::resetImpl(PlanState& planState) {
	UnaryBaseIterator<EnclosedIterator>::resetImpl(planState);

	EnclosedState* state;
	GET_STATE(EnclosedState, state, planState);
	state->theString = "";
}

void EnclosedIterator::releaseResourcesImpl(PlanState& planState) {
	UnaryBaseIterator<EnclosedIterator>::releaseResourcesImpl(planState);

	EnclosedState* state;
	GET_STATE(EnclosedState, state, planState);
	state->theContextItem = NULL;
	state->theString.clear();
}

void EnclosedIterator::setOffset(PlanState& planState, int32_t& offset) {
	UnaryBaseIterator<EnclosedIterator>::setOffset(planState, offset);

	EnclosedState* state = new ( planState.block + stateOffset ) EnclosedState;
}

void EnclosedIterator::EnclosedState::init() {
	PlanIterator::PlanIteratorState::init();
	theString = "";
}

/* end class EnclosedIterator */

/* start class IfThenElseIterator */
IfThenElseIterator::IfThenElseIterator(const yy::location& loc,
		PlanIter_t& iterCond_arg, PlanIter_t& iterThen_arg,
		PlanIter_t& iterElse_arg, bool condIsBooleanIter_arg) :
	Batcher<IfThenElseIterator>(loc), iterCond(iterCond_arg),
			iterThen(iterThen_arg), iterElse(iterElse_arg),
			condIsBooleanIter(condIsBooleanIter_arg) {
}

Item_t IfThenElseIterator::nextImpl(PlanState& planState) {
	Item_t condResult;

	STACK_INIT();

	if (this->condIsBooleanIter)
		condResult = this->consumeNext(this->iterCond, planState);
	else
		condResult = FnBooleanIterator::effectiveBooleanValue(this->loc,
				planState, this->iterCond);

	if (condResult->getBooleanValue() )
		this->iterActive = this->iterThen;
	else
		this->iterActive = this->iterElse;

	while ( true) {
		STACK_PUSH(this->consumeNext(this->iterActive, planState) );
	}

	STACK_END();
}

void IfThenElseIterator::resetImpl(PlanState& planState) {
	this->resetChild(this->iterCond, planState);
	this->resetChild(this->iterThen, planState);
	this->resetChild(this->iterElse, planState);
}

void IfThenElseIterator::releaseResourcesImpl(PlanState& planState) {
	this->releaseChildResources(this->iterCond, planState);
	this->releaseChildResources(this->iterThen, planState);
	this->releaseChildResources(this->iterElse, planState);
}

FLWORIterator::ForLetClause::ForLetClause(std::vector<var_iter_t> aForVars,
		PlanIter_t& aInput) :
	type(FOR), forVars(aForVars), input(aInput) {
}
FLWORIterator::ForLetClause::ForLetClause(std::vector<var_iter_t> aForVars,
		std::vector<var_iter_t> aPosVars, PlanIter_t& aInput) :
	type(FOR), forVars(aForVars), posVars(aPosVars), input(aInput) {
}

FLWORIterator::ForLetClause::ForLetClause(std::vector<ref_iter_t> aLetVars,
		PlanIter_t& aInput, bool aNeedsMaterialization) :
	type(LET), letVars(aLetVars), input(aInput),
			needsMaterialization(aNeedsMaterialization) {
}

std::ostream& FLWORIterator::ForLetClause::show(std::ostream& os) const {
	switch (type) {
	case FOR:
		os << IT_DEPTH << "<for_clause varRefNB=\""<< forVars.size() << "\" posRefNb=\"" << posVars.size() << "\"" << std::endl;
		input->show(os);
		os << IT_DEPTH << "</for_clause>" << std::endl;
		break;
	case LET:
		os << IT_DEPTH << "<let_clause refNb=\"" << letVars.size() << "\">" << std::endl;
		input->show(os);
		os << IT_DEPTH << "</let_clause>" << std::endl;
		break;
	default:
		assert( false);

	}
	return os;
}

FLWORIterator::OrderSpec::OrderSpec(PlanIter_t orderByIter, bool empty_least,
		bool descending) {
}

FLWORIterator::OrderByClause::OrderByClause(
		std::vector<FLWORIterator::OrderSpec> orderSpecs, bool stable) {
}

FLWORIterator::FLWORIterator(const yy::location& loc,
		std::vector<FLWORIterator::ForLetClause> &aForLetClauses,
		PlanIter_t& aWhereClause, FLWORIterator::OrderByClause* aOrderByClause,
		PlanIter_t& aReturnClause, bool aWhereClauseReturnsBooleanPlus) :
	Batcher<FLWORIterator>(loc), forLetClauses(aForLetClauses),
			whereClause(aWhereClause), orderByClause(aOrderByClause),
			returnClause(aReturnClause),
			whereClauseReturnsBooleanPlus(aWhereClauseReturnsBooleanPlus),
			bindingsNb(aForLetClauses.size()) {
}

Item_t FLWORIterator::nextImpl(PlanState& planState) {
	int curVar = 0;
	PlanIteratorState* state;
	vector<string>::iterator iter;
	Item_t curItem;	
	STACK_INIT2(PlanIteratorState, state, planState);
	varBindingState = new int[forLetClauses.size()];
	for (xqp_unsignedInt i = 0; i < forLetClauses.size(); i++) {
		varBindingState[i] = 0;
	}
	while (true) {
		
		while (curVar != bindingsNb) {
			if(bindVariable(curVar, planState)){
				curVar++;
			}else{
				curVar--;
				//FINISHED
				if(curVar == -1){
					STACK_PUSH2(NULL, state);
					break;
					goto stop;
				}
			}
		}
		while(true){
			curItem = this->consumeNext(returnClause, planState);
			if(curItem == NULL){
				curVar = bindingsNb - 1;
				this->resetChild(returnClause, planState);
				break;
			}else{
				STACK_PUSH2(curItem, state);
			}
		}
	}
stop:
	STACK_PUSH2(NULL, state);
	STACK_END2();
}

bool FLWORIterator::bindVariable(int varNb, PlanState& planState) {
	FLWORIterator::ForLetClause lForLetClause = forLetClauses[varNb];
	switch (lForLetClause.type) {
	case ForLetClause::FOR :
		{
			Item_t lItem = this->consumeNext(lForLetClause.input, planState);
			if (lItem == NULL) {
				return false;
			}
			++varBindingState[varNb];
			std::vector<var_iter_t>::iterator forIter;
			std::cerr << "FOR_Bindings:" << lForLetClause.forVars.size() << std::endl;
			for (forIter = lForLetClause.forVars.begin(); forIter
					!= lForLetClause.forVars.end(); forIter++) {
				var_iter_t variable = (*forIter);
				variable->bind(lItem);
			}
			//TODO Pos Bindings
			return true;
		}
	case ForLetClause::LET :
		{
			//return false if the Var-Variable was already bound
			if (varBindingState[varNb] == 1) {
				return false;
			}
			std::cerr << "LET_Bindings:" << lForLetClause.forVars.size() << std::endl;
			std::vector<ref_iter_t>::iterator letIter;
			Iterator_t iterWrapper = new PlanIterWrapper(lForLetClause.input, planState);
			for (letIter = lForLetClause.letVars.begin(); letIter
					!= lForLetClause.letVars.end(); letIter++) {
				(*letIter)->bind(iterWrapper);
				
			}
			++varBindingState[varNb];
			return true;
		}
	default:
		assert(false);
	}
	return false;
}

void FLWORIterator::resetImpl(PlanState& planState) {
}

void FLWORIterator::releaseResourcesImpl(PlanState& planState) {
}

int32_t FLWORIterator::getStateSize() {
	return sizeof(PlanIterator::PlanIteratorState);
}

int32_t FLWORIterator::getStateSizeOfSubtree() {
	  int32_t size = 0;
	  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
	  for (iter = forLetClauses.begin() ; iter != forLetClauses.end(); iter++) {
		  size += iter->input->getStateSizeOfSubtree();
	  }
	  
	  size += returnClause->getStateSizeOfSubtree();
	  
	  if (whereClause != NULL)
		  size += whereClause->getStateSizeOfSubtree();

	  //TODO Add for orderby
	  
	  return this->getStateSize() + size;
}

void FLWORIterator::setOffset(PlanState& planState, int32_t& offset) {
	  this->stateOffset = offset;
	  offset += this->getStateSize();
    
    std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
    for (iter = forLetClauses.begin() ; iter != forLetClauses.end(); iter++) {
      iter->input->setOffset(planState, offset);
    }

	  returnClause->setOffset(planState, offset);
	 	  
	  if (whereClause != NULL)
		  whereClause->setOffset(planState, offset);
	 
}

std::ostream& FLWORIterator::_show(std::ostream& os) const {
	std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
	for (iter = forLetClauses.begin() ; iter != forLetClauses.end(); iter++) {
		iter->show(os);
	}

	return os;
}

} /* namespace xqp */

