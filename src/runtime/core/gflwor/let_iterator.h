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

class LetIterator : public BinaryBaseIterator<LetIterator, PlanIteratorState> 
{
private:
  store::Item_t theVarName;
  std::vector<LetVarIter_t> theLetVars;
  bool theNeedsMat;
  
public:
  SERIALIZABLE_CLASS(LetIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  LetIterator,
  BinaryBaseIterator<LetIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<LetIterator, PlanIteratorState>*)this);

    ar & theVarName;
    ar & theLetVars;
    ar & theNeedsMat;
  }

public:
  LetIterator ( 
        static_context* sctx,
        const QueryLoc& aLoc,  
        store::Item_t aVarName, 
        PlanIter_t aTupleIter, 
        PlanIter_t aInputIter, 
        const std::vector<PlanIter_t>& aLetVars, 
        bool aNeedsMaterialization);

  ~LetIterator();

  store::Item* getVarName() const { return theVarName.getp(); }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl ( store::Item_t& result, PlanState& planState ) const;
};

}
}


#endif  /* ZORBA_RUNTIME_FLWOR_TUPLESTREAM_ITERATOR */
/*
 * Local variables:
 * mode: c++
 * End:
 */
