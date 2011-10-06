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
#ifndef ZORBA_RUNTIME_FULL_TEXT_FT_MODULE_H
#define ZORBA_RUNTIME_FULL_TEXT_FT_MODULE_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "runtime/full_text/thesaurus.h"


namespace zorba {

/**
 * 
 * Author: 
 */
class HostLangIterator : public NaryBaseIterator<HostLangIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(HostLangIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(HostLangIterator,
    NaryBaseIterator<HostLangIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<HostLangIterator, PlanIteratorState>*)this);
  }

  HostLangIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<HostLangIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~HostLangIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class IsStopWordIterator : public NaryBaseIterator<IsStopWordIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsStopWordIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsStopWordIterator,
    NaryBaseIterator<IsStopWordIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsStopWordIterator, PlanIteratorState>*)this);
  }

  IsStopWordIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsStopWordIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsStopWordIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class StemIterator : public NaryBaseIterator<StemIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StemIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StemIterator,
    NaryBaseIterator<StemIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<StemIterator, PlanIteratorState>*)this);
  }

  StemIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StemIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StemIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class StripDiacriticsIterator : public NaryBaseIterator<StripDiacriticsIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StripDiacriticsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StripDiacriticsIterator,
    NaryBaseIterator<StripDiacriticsIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<StripDiacriticsIterator, PlanIteratorState>*)this);
  }

  StripDiacriticsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StripDiacriticsIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StripDiacriticsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ThesaurusLookupIteratorState : public PlanIteratorState
{
public:
  zstring phrase_; //
  zstring relationship_; //
  internal::Thesaurus::level_type at_least_; //
  internal::Thesaurus::level_type at_most_; //
  internal::Thesaurus::ptr thesaurus_; //
  internal::Thesaurus::iterator::ptr tresult_; //

  ThesaurusLookupIteratorState();

  ~ThesaurusLookupIteratorState();

  void reset(PlanState&);
};

class ThesaurusLookupIterator : public NaryBaseIterator<ThesaurusLookupIterator, ThesaurusLookupIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ThesaurusLookupIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ThesaurusLookupIterator,
    NaryBaseIterator<ThesaurusLookupIterator, ThesaurusLookupIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ThesaurusLookupIterator, ThesaurusLookupIteratorState>*)this);
  }

  ThesaurusLookupIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ThesaurusLookupIterator, ThesaurusLookupIteratorState>(sctx, loc, children)
  {}

  virtual ~ThesaurusLookupIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void resetImpl(PlanState&) const;
};


/**
 * 
 * Author: 
 */
class TokenizeIteratorState : public PlanIteratorState
{
public:
  store::Item_t doc_item_; //
  FTTokenIterator_t doc_tokens_; //
  store::Item_t token_qname_; //

  TokenizeIteratorState();

  ~TokenizeIteratorState();

  void reset(PlanState&);
};

class TokenizeIterator : public NaryBaseIterator<TokenizeIterator, TokenizeIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(TokenizeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TokenizeIterator,
    NaryBaseIterator<TokenizeIterator, TokenizeIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<TokenizeIterator, TokenizeIteratorState>*)this);
  }

  TokenizeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<TokenizeIterator, TokenizeIteratorState>(sctx, loc, children)
  {}

  virtual ~TokenizeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void resetImpl(PlanState&) const;
};


/**
 * 
 * Author: 
 */
class TokenizerPropertiesIterator : public NaryBaseIterator<TokenizerPropertiesIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(TokenizerPropertiesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TokenizerPropertiesIterator,
    NaryBaseIterator<TokenizerPropertiesIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<TokenizerPropertiesIterator, PlanIteratorState>*)this);
  }

  TokenizerPropertiesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<TokenizerPropertiesIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~TokenizerPropertiesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void resetImpl(PlanState&) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
