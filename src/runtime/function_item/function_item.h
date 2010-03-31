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
#include "compiler/parser/query_loc.h"

#include "functions/signature.h"

#include "store/api/iterator.h"

namespace zorba
{

class signature;

namespace store 
{

/*******************************************************************************

********************************************************************************/
class FunctionItem : public store::Item
{
protected:
  // location of the function refered to by
  // this function item
  QueryLoc                theLocation;

  // the name of the function, if generated from an inline function item
  store::Item_t           theName;

  // the signature of the function
  signature               theSignature;

  // redundant information but necessary for variadic functions
  uint32_t                theArity;

  // the function itself
  // this is a wrapper which contains the function_item_expr
  // codegen is done lazily in the DynamicFunctionInvocationIterator
  store::Iterator_t       theImplementation;

  // (in-scope) variable values for inline function items
  std::vector<PlanIter_t> theVariableValues;

public:
  SERIALIZABLE_CLASS(FunctionItem)
  FunctionItem(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  FunctionItem(
      const QueryLoc&                aLocation,
      const std::vector<PlanIter_t>& aVariableValues,
      const signature&               aSignature,
      uint32_t                       aArity,
      const store::Iterator_t&       aImplementation);
    
  FunctionItem(
      const QueryLoc&          aLocation,
      const store::Item_t&     aName,
      const signature&         aSignature,
      uint32_t                 aArity,
      const store::Iterator_t& aImplementation);

  const store::Item_t
  getFunctionName() const
  {
    return theName;
  }

  uint32_t
  getFunctionArity() const
  {
    return theArity;
  }

  void
  getFunctionVariables(std::vector<PlanIter_t>&) const;

  const store::Iterator_t
  getFunctionImplementation() const;

  const signature&
  getFunctionSignature() const;

  xqp_string
  show() const;

  ~FunctionItem();

  bool isNode() const     { return false; }
  bool isAtomic() const   { return false; }
  bool isPul() const      { return false; }
  bool isTuple() const    { return false; }
  bool isError() const    { return false; }
  bool isFunction() const { return true; }

protected:
  SYNC_CODE(RCLock  theRCLock;)
};

}//end of store namespace
}//end of zorba namespace

#endif
