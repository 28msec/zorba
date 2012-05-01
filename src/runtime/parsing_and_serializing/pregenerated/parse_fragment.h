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
#ifndef ZORBA_RUNTIME_PARSING_AND_SERIALIZING_PARSE_FRAGMENT_H
#define ZORBA_RUNTIME_PARSING_AND_SERIALIZING_PARSE_FRAGMENT_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "runtime/parsing_and_serializing/fragment_istream.h"
#include "store/api/store.h"


namespace zorba {

/**
 * fn-zorba-xml:parse
 * Author: Zorba Team
 */
class FnZorbaParseXmlFragmentIteratorState : public PlanIteratorState
{
public:
  FragmentIStream theFragmentStream; //the input fragment
  store::LoadProperties theProperties; //loader properties
  zstring baseUri; //
  zstring docUri; //

  FnZorbaParseXmlFragmentIteratorState();

  ~FnZorbaParseXmlFragmentIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnZorbaParseXmlFragmentIterator : public NaryBaseIterator<FnZorbaParseXmlFragmentIterator, FnZorbaParseXmlFragmentIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnZorbaParseXmlFragmentIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnZorbaParseXmlFragmentIterator,
    NaryBaseIterator<FnZorbaParseXmlFragmentIterator, FnZorbaParseXmlFragmentIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnZorbaParseXmlFragmentIterator, FnZorbaParseXmlFragmentIteratorState>*)this);
  }

  FnZorbaParseXmlFragmentIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnZorbaParseXmlFragmentIterator, FnZorbaParseXmlFragmentIteratorState>(sctx, loc, children)
  {}

  virtual ~FnZorbaParseXmlFragmentIterator();

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
