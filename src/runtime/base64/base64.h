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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************
#ifndef ZORBA_RUNTIME_BASE64_BASE64_H
#define ZORBA_RUNTIME_BASE64_BASE64_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * base64:decode
 * Author: Zorba Team
 */
class Base64DecodeIterator : public NaryBaseIterator<Base64DecodeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(Base64DecodeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(Base64DecodeIterator,
    NaryBaseIterator<Base64DecodeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<Base64DecodeIterator, PlanIteratorState>*)this);
  }

  Base64DecodeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<Base64DecodeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~Base64DecodeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * base64:encode
 * Author: Zorba Team
 */
class Base64EncodeIterator : public NaryBaseIterator<Base64EncodeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(Base64EncodeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(Base64EncodeIterator,
    NaryBaseIterator<Base64EncodeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<Base64EncodeIterator, PlanIteratorState>*)this);
  }

  Base64EncodeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<Base64EncodeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~Base64EncodeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
