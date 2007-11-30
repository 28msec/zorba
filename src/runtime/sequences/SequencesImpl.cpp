/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: Sequences.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include <string>
#include <fstream>
#include <vector>

#include "runtime/sequences/SequencesImpl.h"
#include "store/naive/simple_loader.h"
#include "store/api/collection.h"
#include "store/naive/store_defs.h"
#include "errors/Error.h"
#include "runtime/visitors/planitervisitor.h"

using namespace std;
namespace xqp {


Item* op_concatenate_fname_p;
//Item* fn_doc_fname_p;
  

/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
|_______________________________________________________________________*/

//15.1.1 fn:boolean



//15.1.2 op:concatenate 
//---------------------
// DEFINE_LOGGER(ConcatIterator);

ConcatIterator::ConcatIterator(
	yy::location loc,
	const vector<PlanIter_t>& aChildren)
:
	Batcher<ConcatIterator>(loc),
	theChildren(aChildren)
{
// 	LOG_DEBUG("Hallo");
}

ConcatIterator::~ConcatIterator(){}

Item_t 
ConcatIterator::nextImpl(PlanState& planState) {
	Item_t item;
	
	ConcatIteratorState* state;
	STACK_INIT(ConcatIteratorState, state, planState);
	
  for (; state->getCurIter() < int32_t(theChildren.size()); state->incCurIter()) {;
		item = this->consumeNext(theChildren[state->getCurIter()], planState);
		while (item != NULL) {
			STACK_PUSH (item, state);
			item = this->consumeNext(theChildren[state->getCurIter()], planState);
		}
	}
	
	STACK_END();
}

void 
ConcatIterator::resetImpl(PlanState& planState) {
	ConcatIteratorState* state;
	GET_STATE(ConcatIteratorState, state, planState);
	state->reset();
	
	std::vector<PlanIter_t>::iterator iter = theChildren.begin();
	for(; iter != theChildren.end(); ++iter) {
		this->resetChild(*iter, planState);
	}
}

void 
ConcatIterator::releaseResourcesImpl(PlanState& planState) {
	std::vector<PlanIter_t>::iterator iter = theChildren.begin();
	for(; iter != theChildren.end(); ++iter) {
		this->releaseChildResources(*iter, planState);
	}
}

int32_t
ConcatIterator::getStateSize() {
	return sizeof(ConcatIteratorState);
}

int32_t
ConcatIterator::getStateSizeOfSubtree() {
	int32_t size = 0;
	
	std::vector<PlanIter_t>::const_iterator iter = theChildren.begin();
	for(; iter != theChildren.end(); ++iter) {
		size += (*iter)->getStateSizeOfSubtree();
	}
	
	return this->getStateSize() + size;
}

void
ConcatIterator::setOffset(PlanState& planState, int32_t& offset) {
	this->stateOffset = offset;
	offset += this->getStateSize();
	
	std::vector<PlanIter_t>::iterator iter = theChildren.begin();
	for(; iter != theChildren.end(); ++iter) {
		(*iter)->setOffset(planState, offset);
	}
}

void
ConcatIterator::ConcatIteratorState::init() {
	PlanIterator::PlanIteratorState::init();
	this->curIter = 0;
}

void
ConcatIterator::ConcatIteratorState::reset() {
	PlanIterator::PlanIteratorState::reset();
	this->curIter = 0;
}

void
ConcatIterator::ConcatIteratorState::incCurIter() {
	this->curIter++;
}

int32_t
ConcatIterator::ConcatIteratorState::getCurIter() {
	return this->curIter;
}


//15.1.3 fn:index-of

//15.1.4 fn:empty

//15.1.5 fn:exists

//15.1.6 fn:distinct-values

//15.1.7 fn:insert-before

//15.1.8 fn:remove

//15.1.9 fn:reverse

//15.1.10 fn:subsequence

//15.1.11 fn:unordered


/*______________________________________________________________________
|  
| 15.2 Functions That Test the Cardinality of Sequences
|_______________________________________________________________________*/

//15.2.1 fn:zero-or-one

//15.2.2 fn:one-or-more

//15.2.3 fn:exactly-one


/*______________________________________________________________________
|
| 15.3 Equals, Union, Intersection and Except
|_______________________________________________________________________*/

//15.3.1 fn:deep-equal

//15.3.2 op:union

//15.3.3 op:intersect

//15.3.4 op:except


/*______________________________________________________________________
|
| 15.4 Aggregate Functions
|_______________________________________________________________________*/

//15.4.1 fn:count

//15.4.2 fn:avg

//15.4.3 fn:max

//15.4.4 fn:min

//15.4.5 fn:sum


/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/

//15.5.1 op:to

//15.5.2 fn:id

//15.5.3 fn:idref



/*______________________________________________________________________
|	15.5.4 fn:doc
|
|		fn:doc($uri as xs:string?) as document-node()?
|	
|	Summary: Retrieves a document using an xs:anyURI, which may include a 
|	fragment identifier, supplied as an xs:string. If $uri is not a valid 
|	xs:anyURI, an error is raised [err:FODC0005]. If it is a relative URI 
|	Reference, it is resolved relative to the value of the base URI 
|	property from the static context. The resulting absolute URI Reference 
|	is promoted to an xs:string. If the Available documents discussed in 
|	Section 2.1.2 Dynamic ContextXP provides a mapping from this string to 
|	a document node, the function returns that document node. If the 
|	Available documents maps the string to an empty sequence, then the 
|	function returns an empty sequence. If the Available documents 
|	provides no mapping for the string, an error is raised [err:FODC0005]. 
|	
|	If $uri is the empty sequence, the result is an empty sequence.
|_______________________________________________________________________*/

DocIterator::DocIterator (
    yy::location loc, PlanIter_t& arg)
    :
    UnaryBaseIterator<DocIterator> ( loc, arg )
{
}

DocIterator::~DocIterator() {}

Item_t
DocIterator::nextImpl ( PlanState& planState )
{
  Item_t item, xml;

  DocIteratorState* state;
  STACK_INIT ( DocIteratorState, state, planState );

  item = consumeNext(theChild, planState);

  if (!state->got_doc || item->getStringValue() != state->uri)
  {
    state->uri = item->getStringValue();
    SimpleStore& store = GET_STORE();
    state->collection = store.getCollection(item);
    
    if (state->collection != NULL)
    {
      state->childrenIter = state->collection->getIterator(true);
      state->got_doc = 2;
    }
    else
    {
      // load file
      ifstream ifs(((string)state->uri).c_str());
      XmlLoader& loader = store.getXmlLoader();
      state->doc = loader.loadXml(ifs);
      state->childrenIter = state->doc->getChildren();
      state->got_doc = 1;
    }
  }

  do
  {
    item = state->childrenIter->next();
    if (item != NULL)
      STACK_PUSH(item, state);
  }
  while (item != NULL);
  
  STACK_END();
}

int32_t
DocIterator::getStateSize() {
  return sizeof(DocIteratorState);
}

DocIterator::DocIteratorState::DocIteratorState()
  :
  got_doc(0)
{
}

void
DocIterator::DocIteratorState::init()
{
  PlanIterator::PlanIteratorState::init();
  if (got_doc == 1)
    childrenIter = doc->getChildren();
  else if (got_doc == 2)
    childrenIter = collection->getIterator(true);
}

void
DocIterator::DocIteratorState::reset()
{
  PlanIterator::PlanIteratorState::reset();
  got_doc = 0;
}

//15.5.5 fn:doc-available

//15.5.6 fn:collection


} /* namespace xqp */

