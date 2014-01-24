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

  void serialize( ::zorba::serialization::Archiver& ar);

  FnZorbaParseXmlFragmentIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnZorbaParseXmlFragmentIterator, FnZorbaParseXmlFragmentIteratorState>(sctx, loc, children)
  {}

  virtual ~FnZorbaParseXmlFragmentIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn-zorba-xml:canonicalize
 * Author: Zorba Team
 */
class FnZorbaCanonicalizeIteratorState : public PlanIteratorState
{
public:
  store::LoadProperties theProperties; //loader properties

  FnZorbaCanonicalizeIteratorState();

  ~FnZorbaCanonicalizeIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnZorbaCanonicalizeIterator : public NaryBaseIterator<FnZorbaCanonicalizeIterator, FnZorbaCanonicalizeIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnZorbaCanonicalizeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnZorbaCanonicalizeIterator,
    NaryBaseIterator<FnZorbaCanonicalizeIterator, FnZorbaCanonicalizeIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnZorbaCanonicalizeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnZorbaCanonicalizeIterator, FnZorbaCanonicalizeIteratorState>(sctx, loc, children)
  {}

  virtual ~FnZorbaCanonicalizeIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:parse-xml-fragment
 * Author: Zorba Team
 */
class FnParseXmlFragmentIteratorState : public PlanIteratorState
{
public:
  FragmentIStream theFragmentStream; //the input fragment
  store::LoadProperties theProperties; //loader properties
  zstring baseUri; //
  zstring docUri; //

  FnParseXmlFragmentIteratorState();

  ~FnParseXmlFragmentIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnParseXmlFragmentIterator : public NaryBaseIterator<FnParseXmlFragmentIterator, FnParseXmlFragmentIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnParseXmlFragmentIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnParseXmlFragmentIterator,
    NaryBaseIterator<FnParseXmlFragmentIterator, FnParseXmlFragmentIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnParseXmlFragmentIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnParseXmlFragmentIterator, FnParseXmlFragmentIteratorState>(sctx, loc, children)
  {}

  virtual ~FnParseXmlFragmentIterator();

  zstring getNameAsString() const;

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
