/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#ifndef ZORBA_RUNTIME_PARSING_AND_SERIALIZING_PARSING_AND_SERIALIZING_H
#define ZORBA_RUNTIME_PARSING_AND_SERIALIZING_PARSING_AND_SERIALIZING_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * fn:parse-xml
 * Author: Zorba Team
 */
class FnParseXmlIterator : public NaryBaseIterator<FnParseXmlIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnParseXmlIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnParseXmlIterator,
    NaryBaseIterator<FnParseXmlIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnParseXmlIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnParseXmlIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnParseXmlIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:serialize
 * Author: Zorba Team
 */
class FnSerializeIterator : public NaryBaseIterator<FnSerializeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnSerializeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSerializeIterator,
    NaryBaseIterator<FnSerializeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnSerializeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnSerializeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnSerializeIterator();

public:
  static void streamReleaser(std::istream* stream);
  static void setSerializationParams(zorba::serializer& aSerializer, store::Item_t& aParamElem, static_context* aSctx, const QueryLoc& aLoc);
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
