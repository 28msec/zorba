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
#ifndef ZORBA_COMPILER_VALUE_IC
#define ZORBA_COMPILER_VALUE_IC

#include "common/shared_types.h"

#include "compiler/expression/expr_utils.h"
#include "store/api/ic.h"


namespace zorba 
{

/******************************************************************************
 ValueIC is the class representing the integrity constraint
 declaration.

 It represents an IC and it's collection dependecies.
 Contains one of the two kinds of info, either:
   1) - IC name
      - and 1 collection name
   or 2) - IC name
      - and 2 collection names (to and from) for the foreign key ic kind

*******************************************************************************/
class ValueIC : public SimpleRCObject 
{
public:

private:
  static_context                * theSctx;

  store::Item_t                   theName;
  store::IC::ICKind               theICKind;          
  store::Item_t                   theCollectionName;
  store::Item_t                   theToCollectionName;
  store::Item_t                   theFromCollectionName;

public:
  SERIALIZABLE_CLASS(ValueIC)
  ValueIC(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ValueIC(static_context* sctx, const QueryLoc& loc, const store::Item_t& name);

  ~ValueIC();

  static_context* getSctx() const { return theSctx; }

  const store::Item_t& getName() const;
  const store::Item_t& getCollectionName() const;
  const store::Item_t& getToCollectionName() const;
  const store::Item_t& getFromCollectionName() const;

  store::IC::ICKind getICKind() const { return theICKind; }

  //void analyze();

  std::string toString();

private:
};


typedef rchandle<ValueIC> ValueIC_t;


}

#endif

/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
