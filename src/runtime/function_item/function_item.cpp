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

#include "runtime/function_item/function_item.h"

#include "functions/signature.h"

#include "store/api/iterator.h"
#include "runtime/function_item/store_iterator.h"
#include "runtime/base/plan_iterator.h"
#include "zorbaserialization/serialization_engine.h"

namespace zorba {

  namespace store {

    SERIALIZABLE_CLASS_VERSIONS(FunctionItem)
    END_SERIALIZABLE_CLASS_VERSIONS(FunctionItem)

    FunctionItem::FunctionItem(::zorba::serialization::Archiver& ar)
      : theSignature(ar) {}
    
    FunctionItem::FunctionItem(
      const QueryLoc&                aLocation,
      const std::vector<PlanIter_t>& aVariableValues,
      const signature&               aSignature,
      uint32_t                       aArity,
      const store::Iterator_t&       aImplementation)
      : theLocation(aLocation),
        theName(0),
        theSignature(aSignature),
        theArity(aArity),
        theImplementation(aImplementation),
        theVariableValues(aVariableValues)
    {  }
      
    FunctionItem::FunctionItem(
      const QueryLoc&          aLocation,
      const store::Item_t&     aName,
      const signature&         aSignature,
      uint32_t                       aArity,
      const store::Iterator_t& aImplementation)
      : theLocation(aLocation),
        theName(aName),
        theSignature(aSignature),
        theArity(aArity),
        theImplementation(aImplementation)
    {  }
    
    
    void FunctionItem::serialize(::zorba::serialization::Archiver& ar)
    {
      ar & theLocation;
      ar & theName;
      ar & theVariableValues;
      ar & theSignature;
      ar & theArity;
      ar & theImplementation;
    }
    
    void
    FunctionItem::getFunctionVariables(std::vector<PlanIter_t>& aResult) const
    {
      std::vector<PlanIter_t>::const_iterator lIt;
      for(lIt = theVariableValues.begin(); lIt != theVariableValues.end(); lIt++)
      {
        aResult.push_back(*lIt);
      }
    }
    
    const store::Iterator_t
    FunctionItem::getFunctionImplementation() const
    { 
      store::FunctionItemIterator* func_iter =
        dynamic_cast<store::FunctionItemIterator*>(theImplementation.getp());
      return new store::FunctionItemIterator(*func_iter);//make a copy for runtime use 
    }
    
    const signature&
    FunctionItem::getFunctionSignature() const
    {
      return theSignature;
    }
    
    xqp_string
    FunctionItem::show() const
    {
      std::ostringstream lRes;
      if (theName) {
        lRes << theName->getStringValue() << "#" << theSignature.arg_count();
      } else {
        lRes << "inline function";
      }
      lRes << " (" << theLocation << ")";
      return lRes.str().c_str();
    }

    FunctionItem::~FunctionItem()
    {
    }

  } //namespace store
} //namespace zorba
