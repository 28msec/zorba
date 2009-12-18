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
#include <algorithm>

#include "types/typeops.h"

#include "functions/function.h"

#include "compiler/indexing/value_ic.h"
#include "compiler/api/compilercb.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/expr.h"
#include "compiler/codegen/plan_visitor.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/indexing/doc_indexer.h"

#include "store/api/item_factory.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(ValueIC)
END_SERIALIZABLE_CLASS_VERSIONS(ValueIC)

/*******************************************************************************

*******************************************************************************/
ValueIC::ValueIC(
    static_context* sctx,
    const QueryLoc& loc,
    const store::Item_t& name)
  :
  theSctx(sctx),
  theName(name)
{ 
}
  

/*******************************************************************************

*******************************************************************************/
ValueIC::ValueIC(::zorba::serialization::Archiver& ar)
  :
  SimpleRCObject(ar)
{
}


/*******************************************************************************

*******************************************************************************/
void ValueIC::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theSctx;
  ar & theName;
}


/*******************************************************************************

*******************************************************************************/
ValueIC::~ValueIC()
{
}


/*******************************************************************************
*******************************************************************************/
const store::Item_t& ValueIC::getName() const
{
  return theName;
}


/*******************************************************************************
*******************************************************************************/
const store::Item_t& ValueIC::getCollectionName() const
{
  return theCollectionName;
}


/*******************************************************************************
*******************************************************************************/
const store::Item_t& ValueIC::getToCollectionName() const
{
  return theToCollectionName;
}


/*******************************************************************************
*******************************************************************************/
const store::Item_t& ValueIC::getFromCollectionName() const
{
  return theFromCollectionName;
}




/*******************************************************************************
  Check that the pathexpr 
  (a) is deterministic,
  (b) does not have any free variables,
  (c) does not reference any input functions other than dc:collection()
  (d) the arg to each dc:collection is a const qname 
********************************************************************************/
//void ValueIC::analyze()
//{
//}



std::string ValueIC::toString()
{
  std::ostringstream os;

  os << "IC : " << theName->getStringValue()->c_str() << std::endl;

  return os.str();
}


}
/* vim:set ts=2 sw=2: */
