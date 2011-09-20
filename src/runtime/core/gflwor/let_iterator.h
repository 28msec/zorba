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
#ifndef ZORBA_RUNTIME_FLWOR_LET_ITERATOR
#define ZORBA_RUNTIME_FLWOR_LET_ITERATOR

#include <vector>

#include "runtime/base/binarybase.h"

namespace zorba 
{
namespace flwor 
{


/***************************************************************************//**

  theChild0    : The input tuple iterator.

  theChild1    : The domain expr iterator.

  theVarName   :

  theVarRefs   : Vector of LetVarIters representing all references to this LET
                 var. Each LetVarIter holds the current value of the var as an
                 iterator. The iterator iterates over a temp sequence, whose
                 input is theChild1. Each temp seq iterator is created and stored
                 in its associated LetVarIter by the bindVariable() method.
  theNeedsMat  :
********************************************************************************/
class LetIterator : public BinaryBaseIterator<LetIterator, PlanIteratorState> 
{
private:
  store::Item_t           theVarName;
  std::vector<PlanIter_t> theLetVars;
  bool                    theLazyEval;
  bool                    theNeedsMat;
  
public:
  SERIALIZABLE_CLASS(LetIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  LetIterator,
  BinaryBaseIterator<LetIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  LetIterator( 
        static_context* sctx,
        const QueryLoc& aLoc,  
        store::Item* aVarName, 
        PlanIter_t aTupleIter, 
        PlanIter_t aInputIter, 
        const std::vector<PlanIter_t>& aLetVars,
        bool lazyEval,
        bool aNeedsMaterialization);

  ~LetIterator();

  store::Item* getVarName() const { return theVarName.getp(); }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};

}
}


#endif  /* ZORBA_RUNTIME_FLWOR_TUPLESTREAM_ITERATOR */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
