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
#ifndef ZORBA_RUNTIME_GFLWOR_FOR_ITERATOR
#define ZORBA_RUNTIME_GFLWOR_FOR_ITERATOR

#include <vector>

#include "runtime/base/binarybase.h"


namespace zorba {
 
namespace flwor 
{   
    
class ForState : public PlanIteratorState 
{
private:
  int thePosition;

public:
  void init(PlanState&);

  void reset(PlanState&);

  inline int incReturnPosition() {return ++thePosition;}

  inline void resetPosition() { thePosition = 0;}
};


/***************************************************************************//**

  theChild0     : The input tuple iterator.

  theChild1     : The domain expr iterator.

  theVarRefs    : Vector of ForVarIters representing all references to this FOR
                  var. Each ForVarIter holds the current value of the var (as an
                  Item_t) and its next() method simply returns that value. The
                  value is computed and stored in the ForVarIter by the 
                  bindVariable() method.

  thePosVarRefs : Vector of ForVarIters representing all references to the
                  positional var (if any) associated with this FOR var.
********************************************************************************/
class ForIterator : public BinaryBaseIterator<ForIterator, ForState> 
{
private:
  store::Item_t           theVarName;
  bool                    theHasPosVars;
  std::vector<PlanIter_t> theVarRefs;
  std::vector<PlanIter_t> thePosVarRefs;

public:
  SERIALIZABLE_CLASS(ForIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  ForIterator,
  BinaryBaseIterator<ForIterator, ForState>);

  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (BinaryBaseIterator<ForIterator, ForState>*)this);
    ar & theVarName;
    ar & theHasPosVars;
    ar & theVarRefs;
    ar & thePosVarRefs;
	}

public:
  ForIterator(
        static_context* sctx,
        const QueryLoc& loc,
        store::Item* varName,
        PlanIter_t tupleIter,
        PlanIter_t domainIter,
        const std::vector<PlanIter_t>& varRefs);

  ForIterator(
        static_context* sctx,
        const QueryLoc& loc,
        store::Item* varName,
        PlanIter_t tupleIter,
        PlanIter_t domainIter,
        const std::vector<PlanIter_t>& varRefs,
        const std::vector<PlanIter_t>& posRefs);

  ~ForIterator();
  
  store::Item* getVarName() const { return theVarName.getp(); }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


}
}


#endif  /* ZORBA_RUNTIME_GFLWOR_FOR_ITERATOR */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
