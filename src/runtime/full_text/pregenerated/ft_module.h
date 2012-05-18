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
#include "runtime/full_text/ft_token_seq_iterator.h"
#include "runtime/full_text/thesaurus.h"


namespace zorba {

#ifndef ZORBA_NO_FULL_TEXT
/**
 * 
 * Author: 
 */
class CurrentCompareOptionsIterator : public NaryBaseIterator<CurrentCompareOptionsIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CurrentCompareOptionsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CurrentCompareOptionsIterator,
    NaryBaseIterator<CurrentCompareOptionsIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<CurrentCompareOptionsIterator, PlanIteratorState>*)this);
  }

  CurrentCompareOptionsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CurrentCompareOptionsIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CurrentCompareOptionsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifndef ZORBA_NO_FULL_TEXT
/**
 * 
 * Author: 
 */
class CurrentLangIterator : public NaryBaseIterator<CurrentLangIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CurrentLangIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CurrentLangIterator,
    NaryBaseIterator<CurrentLangIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<CurrentLangIterator, PlanIteratorState>*)this);
  }

  CurrentLangIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CurrentLangIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CurrentLangIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifndef ZORBA_NO_FULL_TEXT
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

#endif

#ifndef ZORBA_NO_FULL_TEXT
/**
 * 
 * Author: 
 */
class IsStemLangSupportedIterator : public NaryBaseIterator<IsStemLangSupportedIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsStemLangSupportedIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsStemLangSupportedIterator,
    NaryBaseIterator<IsStemLangSupportedIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsStemLangSupportedIterator, PlanIteratorState>*)this);
  }

  IsStemLangSupportedIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsStemLangSupportedIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsStemLangSupportedIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifndef ZORBA_NO_FULL_TEXT
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

#endif

#ifndef ZORBA_NO_FULL_TEXT
/**
 * 
 * Author: 
 */
class IsStopWordLangSupportedIterator : public NaryBaseIterator<IsStopWordLangSupportedIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsStopWordLangSupportedIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsStopWordLangSupportedIterator,
    NaryBaseIterator<IsStopWordLangSupportedIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsStopWordLangSupportedIterator, PlanIteratorState>*)this);
  }

  IsStopWordLangSupportedIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsStopWordLangSupportedIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsStopWordLangSupportedIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifndef ZORBA_NO_FULL_TEXT
/**
 * 
 * Author: 
 */
class IsThesaurusLangSupportedIterator : public NaryBaseIterator<IsThesaurusLangSupportedIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsThesaurusLangSupportedIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsThesaurusLangSupportedIterator,
    NaryBaseIterator<IsThesaurusLangSupportedIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsThesaurusLangSupportedIterator, PlanIteratorState>*)this);
  }

  IsThesaurusLangSupportedIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsThesaurusLangSupportedIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsThesaurusLangSupportedIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifndef ZORBA_NO_FULL_TEXT
/**
 * 
 * Author: 
 */
class IsTokenizerLangSupportedIterator : public NaryBaseIterator<IsTokenizerLangSupportedIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsTokenizerLangSupportedIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsTokenizerLangSupportedIterator,
    NaryBaseIterator<IsTokenizerLangSupportedIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsTokenizerLangSupportedIterator, PlanIteratorState>*)this);
  }

  IsTokenizerLangSupportedIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsTokenizerLangSupportedIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsTokenizerLangSupportedIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifndef ZORBA_NO_FULL_TEXT
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

#endif

#ifndef ZORBA_NO_FULL_TEXT
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

#endif

#ifndef ZORBA_NO_FULL_TEXT
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

#endif

#ifndef ZORBA_NO_FULL_TEXT
/**
 * 
 * Author: 
 */
class TokenizeIteratorState : public PlanIteratorState
{
public:
  store::Item_t doc_item_; //
  FTTokenIterator_t doc_tokens_; //

  TokenizeIteratorState();

  ~TokenizeIteratorState();

  void reset(PlanState&);
};

class TokenizeIterator : public NaryBaseIterator<TokenizeIterator, TokenizeIteratorState>
{ 
protected:
  store::Item_t token_qname_; //
  store::Item_t lang_qname_; //
  store::Item_t para_qname_; //
  store::Item_t sent_qname_; //
  store::Item_t value_qname_; //
  store::Item_t ref_qname_; //
public:
  SERIALIZABLE_CLASS(TokenizeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TokenizeIterator,
    NaryBaseIterator<TokenizeIterator, TokenizeIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  TokenizeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    ;

  virtual ~TokenizeIterator();

public:
  void initMembers();
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void resetImpl(PlanState&) const;
};

#endif

#ifndef ZORBA_NO_FULL_TEXT
/**
 * 
 * Author: 
 */
class TokenizeNodesIteratorState : public PlanIteratorState
{
public:
  store::Item_t doc_item_; //
  FTTokenIterator_t doc_tokens_; //

  TokenizeNodesIteratorState();

  ~TokenizeNodesIteratorState();

  void reset(PlanState&);
};

class TokenizeNodesIterator : public NaryBaseIterator<TokenizeNodesIterator, TokenizeNodesIteratorState>
{ 
protected:
  store::Item_t token_qname_; //
  store::Item_t lang_qname_; //
  store::Item_t para_qname_; //
  store::Item_t sent_qname_; //
  store::Item_t value_qname_; //
  store::Item_t ref_qname_; //
public:
  SERIALIZABLE_CLASS(TokenizeNodesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TokenizeNodesIterator,
    NaryBaseIterator<TokenizeNodesIterator, TokenizeNodesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  TokenizeNodesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    ;

  virtual ~TokenizeNodesIterator();

public:
  void initMembers();
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void resetImpl(PlanState&) const;
};

#endif

#ifndef ZORBA_NO_FULL_TEXT
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
};

#endif

#ifndef ZORBA_NO_FULL_TEXT
/**
 * 
 * Author: 
 */
class TokenizeStringIteratorState : public PlanIteratorState
{
public:
  FTTokenSeqIterator string_tokens_; //

  TokenizeStringIteratorState();

  ~TokenizeStringIteratorState();

  void reset(PlanState&);
};

class TokenizeStringIterator : public NaryBaseIterator<TokenizeStringIterator, TokenizeStringIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(TokenizeStringIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TokenizeStringIterator,
    NaryBaseIterator<TokenizeStringIterator, TokenizeStringIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<TokenizeStringIterator, TokenizeStringIteratorState>*)this);
  }

  TokenizeStringIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<TokenizeStringIterator, TokenizeStringIteratorState>(sctx, loc, children)
  {}

  virtual ~TokenizeStringIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void resetImpl(PlanState&) const;
};

#endif

}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
