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
#include "runtime/function_item/store_iterator.h"

#include "compiler/codegen/plan_visitor.h"
#include "compiler/api/compilercb.h"

#include "functions/udf.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/api/plan_wrapper.h"

namespace zorba {

namespace store {

SERIALIZABLE_CLASS_VERSIONS(FunctionItemIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FunctionItemIterator)
    

void FunctionItemIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (Iterator*)this);
  ar & theCCB;
  ar & theSctx;
  ar & theExpr;
  ar & isInline;
}
    

void FunctionItemIterator::open()
{
  PlanIter_t lIterator;
  const function* lFunction = theExpr.get_function();
  lIterator = lFunction->codegen(
                                 theCCB, theSctx,
                                 theExpr.get_loc(), theArguments,
                                 theExpr);
  theImplementation = new PlanWrapper(lIterator, theCCB, 0, 0);
  theImplementation->open();
}
  
  
bool FunctionItemIterator::next(Item_t& r)
{
  return theImplementation->next(r);
}
    

void FunctionItemIterator::reset()
{
  theImplementation->reset();
}
    
void FunctionItemIterator::close()
{
  theImplementation->close();
}


} //end of namespace store
} //end of namespace zorba
