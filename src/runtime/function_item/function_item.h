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
#ifndef ZORBA_RUNTIME_FUNCTION_ITEM_H
#define ZORBA_RUNTIME_FUNCTION_ITEM_H

#include "store/api/item.h"

#include "functions/signature.h"

#include "store/api/iterator.h"

namespace zorba
{

class signature;

namespace simplestore 
{

/*******************************************************************************

********************************************************************************/
class FunctionItem : public store::Item
{
private:
    const store::Item_t theName;
    std::vector<store::Item_t> theVariableNames;
    std::vector<store::Iterator_t> theVariableValues;
    const signature theSignature;
    const store::Iterator_t theImplementation;

public:
  FunctionItem(const std::vector<store::Iterator_t>& aVariableValues,
          const signature& aSignature,
          const store::Iterator_t& aImplementation);
    
  FunctionItem(const store::Item_t& aName,
          const signature& aSignature,
          const store::Iterator_t& aImplementation);

#ifndef ZORBA_FOR_ONE_THREAD_ONLY 
protected:
  SYNC_CODE(RCLock  theRCLock;)
#endif

  ~FunctionItem() {}

  bool isNode() const     { return false; }
  bool isAtomic() const   { return false; }
  bool isPul() const      { return false; }
  bool isTuple() const    { return false; }
  bool isError() const    { return false; }
  bool isFunction() const { return true; }

  //store::Item_t getAtomizationValue() const;

  //void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  const store::Item_t getFunctionName() const
  {
    return theName;
  }

  void getFunctionVariables(std::vector<store::Iterator_t>&) const;

  const store::Iterator_t getFunctionImplementation() const;

  const signature getFunctionSignature() const;
};

}//end of simplestore namespace
}//end of zorba namespace

#endif
