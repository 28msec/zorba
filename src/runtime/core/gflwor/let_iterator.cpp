/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "zorbaerrors/Assert.h"

#include "runtime/visitors/planitervisitor.h"
#include "runtime/core/gflwor/let_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/gflwor/common.h"

namespace zorba 
{
namespace flwor 
{

LetIterator::LetIterator (
    short sctx,
    const QueryLoc& aLoc,
    store::Item_t aVarName, 
    PlanIter_t aTupleIter,
    PlanIter_t aInput,
    const std::vector<PlanIter_t>& aLetVars,
    bool aNeedsMaterialization ) 
  :
  BinaryBaseIterator<LetIterator, PlanIteratorState> ( sctx, aLoc, aTupleIter, aInput),
  theVarName(aVarName), 
  theNeedsMat ( aNeedsMaterialization ) 
{
  castIterVector<LetVarIterator>(theLetVars, aLetVars);
}


LetIterator::~LetIterator() 
{
}


void LetIterator::accept(PlanIterVisitor& v) const 
{ 
  v.beginVisit(*this); 

  v.beginVisitFlworLetVariable(theNeedsMat, 
                               theVarName->getStringValue(),
                               theLetVars);
  v.endVisitFlworLetVariable();

  theChild0->accept(v); 
  theChild1->accept(v); 

  v.endVisit(*this);
}



//theChild0 == TupleIter
//theChild1 == InputIter
bool LetIterator::nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const 
{
  PlanIteratorState* lState;
  DEFAULT_STACK_INIT ( PlanIteratorState, lState, aPlanState );
  while ( consumeNext ( aResult, theChild0, aPlanState ) ) {
    bindVariables ( theChild1 ,theLetVars,aPlanState,theNeedsMat);
    STACK_PUSH ( true, lState );
    theChild1->reset ( aPlanState );
  }
  STACK_END ( lState );
}


} //Namespace flwor
}//Namespace zorba
