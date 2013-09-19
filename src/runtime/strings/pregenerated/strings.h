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
#ifndef ZORBA_RUNTIME_STRINGS_STRINGS_H
#define ZORBA_RUNTIME_STRINGS_STRINGS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "zorbautils/checked_vector.h"
#include "zorbatypes/schema_types.h"


namespace zorba {

/**
 * 
 *    fn:codepoints-to-string
 *  
 * Author: Zorba Team
 */
class CodepointsToStringIterator : public NaryBaseIterator<CodepointsToStringIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CodepointsToStringIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CodepointsToStringIterator,
    NaryBaseIterator<CodepointsToStringIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CodepointsToStringIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CodepointsToStringIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CodepointsToStringIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    fn:string-to-codepoints
 *  
 * Author: Zorba Team
 */
class StringToCodepointsIteratorState : public PlanIteratorState
{
public:
  xs_unsignedInt theIterator; //the current iterator
  checked_vector<xs_unsignedInt> theResult; //the resulting vector
  std::istream* theStream; //
  store::Item_t theStreamItem; //

  StringToCodepointsIteratorState();

  ~StringToCodepointsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class StringToCodepointsIterator : public NaryBaseIterator<StringToCodepointsIterator, StringToCodepointsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StringToCodepointsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StringToCodepointsIterator,
    NaryBaseIterator<StringToCodepointsIterator, StringToCodepointsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  StringToCodepointsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StringToCodepointsIterator, StringToCodepointsIteratorState>(sctx, loc, children)
  {}

  virtual ~StringToCodepointsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:compare
 *  
 * Author: Zorba Team
 */
class CompareStrIterator : public NaryBaseIterator<CompareStrIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CompareStrIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CompareStrIterator,
    NaryBaseIterator<CompareStrIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CompareStrIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CompareStrIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CompareStrIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:codepoint-equal
 *  
 * Author: Zorba Team
 */
class CodepointEqualIterator : public NaryBaseIterator<CodepointEqualIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CodepointEqualIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CodepointEqualIterator,
    NaryBaseIterator<CodepointEqualIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CodepointEqualIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CodepointEqualIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CodepointEqualIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:concat
 *  
 * Author: Zorba Team
 */
class ConcatStrIterator : public NaryBaseIterator<ConcatStrIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ConcatStrIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ConcatStrIterator,
    NaryBaseIterator<ConcatStrIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ConcatStrIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ConcatStrIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ConcatStrIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:string-join
 *  
 * Author: Zorba Team
 */
class StringJoinIterator : public NaryBaseIterator<StringJoinIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StringJoinIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StringJoinIterator,
    NaryBaseIterator<StringJoinIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  StringJoinIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StringJoinIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StringJoinIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:substring
 *  
 * Author: Zorba Team
 */
class SubstringIterator : public NaryBaseIterator<SubstringIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SubstringIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SubstringIterator,
    NaryBaseIterator<SubstringIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SubstringIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SubstringIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SubstringIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:substring
 *  
 * Author: Zorba Team
 */
class SubstringIntOptIterator : public NaryBaseIterator<SubstringIntOptIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SubstringIntOptIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SubstringIntOptIterator,
    NaryBaseIterator<SubstringIntOptIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SubstringIntOptIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SubstringIntOptIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SubstringIntOptIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    fn:string-length
 *  
 * Author: Zorba Team
 */
class StringLengthIterator : public NaryBaseIterator<StringLengthIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StringLengthIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StringLengthIterator,
    NaryBaseIterator<StringLengthIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  StringLengthIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StringLengthIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StringLengthIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    fn:normalize-space
 *  
 * Author: Zorba Team
 */
class NormalizeSpaceIterator : public NaryBaseIterator<NormalizeSpaceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NormalizeSpaceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NormalizeSpaceIterator,
    NaryBaseIterator<NormalizeSpaceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  NormalizeSpaceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NormalizeSpaceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NormalizeSpaceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:normalize-unicode
 *  
 * Author: Zorba Team
 */
class NormalizeUnicodeIterator : public NaryBaseIterator<NormalizeUnicodeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NormalizeUnicodeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NormalizeUnicodeIterator,
    NaryBaseIterator<NormalizeUnicodeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  NormalizeUnicodeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NormalizeUnicodeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NormalizeUnicodeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:upper-case
 *  
 * Author: Zorba Team
 */
class UpperCaseIterator : public NaryBaseIterator<UpperCaseIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(UpperCaseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(UpperCaseIterator,
    NaryBaseIterator<UpperCaseIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  UpperCaseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<UpperCaseIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~UpperCaseIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:lower-case
 *  
 * Author: Zorba Team
 */
class LowerCaseIterator : public NaryBaseIterator<LowerCaseIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(LowerCaseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LowerCaseIterator,
    NaryBaseIterator<LowerCaseIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  LowerCaseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<LowerCaseIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~LowerCaseIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:translate
 *  
 * Author: Zorba Team
 */
class TranslateIterator : public NaryBaseIterator<TranslateIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(TranslateIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TranslateIterator,
    NaryBaseIterator<TranslateIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  TranslateIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<TranslateIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~TranslateIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:encode-for-uri
 *  
 * Author: Zorba Team
 */
class EncodeForUriIterator : public NaryBaseIterator<EncodeForUriIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(EncodeForUriIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(EncodeForUriIterator,
    NaryBaseIterator<EncodeForUriIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  EncodeForUriIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<EncodeForUriIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~EncodeForUriIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:iri-to-uri
 *  
 * Author: Zorba Team
 */
class IriToUriIterator : public NaryBaseIterator<IriToUriIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IriToUriIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IriToUriIterator,
    NaryBaseIterator<IriToUriIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IriToUriIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IriToUriIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IriToUriIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:escape-html-uri
 *  
 * Author: Zorba Team
 */
class EscapeHtmlUriIterator : public NaryBaseIterator<EscapeHtmlUriIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(EscapeHtmlUriIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(EscapeHtmlUriIterator,
    NaryBaseIterator<EscapeHtmlUriIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  EscapeHtmlUriIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<EscapeHtmlUriIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~EscapeHtmlUriIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:contains
 *  
 * Author: Zorba Team
 */
class ContainsIterator : public NaryBaseIterator<ContainsIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ContainsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ContainsIterator,
    NaryBaseIterator<ContainsIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ContainsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ContainsIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ContainsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:starts-with
 *  
 * Author: Zorba Team
 */
class StartsWithIterator : public NaryBaseIterator<StartsWithIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StartsWithIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StartsWithIterator,
    NaryBaseIterator<StartsWithIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  StartsWithIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StartsWithIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StartsWithIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:ends-with
 *  
 * Author: Zorba Team
 */
class EndsWithIterator : public NaryBaseIterator<EndsWithIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(EndsWithIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(EndsWithIterator,
    NaryBaseIterator<EndsWithIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  EndsWithIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<EndsWithIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~EndsWithIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:substring-before
 *  
 * Author: Zorba Team
 */
class SubstringBeforeIterator : public NaryBaseIterator<SubstringBeforeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SubstringBeforeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SubstringBeforeIterator,
    NaryBaseIterator<SubstringBeforeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SubstringBeforeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SubstringBeforeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SubstringBeforeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:substring-after
 *  
 * Author: Zorba Team
 */
class SubstringAfterIterator : public NaryBaseIterator<SubstringAfterIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SubstringAfterIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SubstringAfterIterator,
    NaryBaseIterator<SubstringAfterIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SubstringAfterIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SubstringAfterIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SubstringAfterIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:matches
 *  
 * Author: Zorba Team
 */
class FnMatchesIterator : public NaryBaseIterator<FnMatchesIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnMatchesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnMatchesIterator,
    NaryBaseIterator<FnMatchesIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnMatchesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnMatchesIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnMatchesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:replace
 *  
 * Author: Zorba Team
 */
class FnReplaceIterator : public NaryBaseIterator<FnReplaceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnReplaceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnReplaceIterator,
    NaryBaseIterator<FnReplaceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnReplaceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnReplaceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnReplaceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:tokenize
 *  
 * Author: Zorba Team
 */
class FnTokenizeIteratorState : public PlanIteratorState
{
public:
  zstring theString; //the remaining string
  zstring thePattern; //the pattern string
  zstring theFlags; //the tokenizing flags
  xs_int start_pos; //the start position
  xs_boolean hasmatched; //flag indicating whether a match was found

  FnTokenizeIteratorState();

  ~FnTokenizeIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnTokenizeIterator : public NaryBaseIterator<FnTokenizeIterator, FnTokenizeIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnTokenizeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnTokenizeIterator,
    NaryBaseIterator<FnTokenizeIterator, FnTokenizeIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnTokenizeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnTokenizeIterator, FnTokenizeIteratorState>(sctx, loc, children)
  {}

  virtual ~FnTokenizeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    fn:analyze-string
 *  
 * Author: Zorba Team
 */
class FnAnalyzeStringIterator : public NaryBaseIterator<FnAnalyzeStringIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnAnalyzeStringIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnAnalyzeStringIterator,
    NaryBaseIterator<FnAnalyzeStringIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnAnalyzeStringIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnAnalyzeStringIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnAnalyzeStringIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    string:analyse-string
 *  
 * Author: Zorba Team
 */
class StringAnalyzeStringIterator : public NaryBaseIterator<StringAnalyzeStringIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StringAnalyzeStringIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StringAnalyzeStringIterator,
    NaryBaseIterator<StringAnalyzeStringIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  StringAnalyzeStringIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StringAnalyzeStringIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StringAnalyzeStringIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    string:materialize
 *  
 * Author: Zorba Team
 */
class StringMaterializeIterator : public NaryBaseIterator<StringMaterializeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StringMaterializeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StringMaterializeIterator,
    NaryBaseIterator<StringMaterializeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  StringMaterializeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StringMaterializeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StringMaterializeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    string:is-streamable
 *  
 * Author: Zorba Team
 */
class StringIsStreamableIterator : public NaryBaseIterator<StringIsStreamableIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StringIsStreamableIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StringIsStreamableIterator,
    NaryBaseIterator<StringIsStreamableIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  StringIsStreamableIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StringIsStreamableIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StringIsStreamableIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    string:is-seekable
 *  
 * Author: Zorba Team
 */
class StringIsSeekableIterator : public NaryBaseIterator<StringIsSeekableIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StringIsSeekableIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StringIsSeekableIterator,
    NaryBaseIterator<StringIsSeekableIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  StringIsSeekableIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StringIsSeekableIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StringIsSeekableIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    string:split
 *  
 * Author: Matthias Brantner
 */
class StringSplitIteratorState : public PlanIteratorState
{
public:
  zstring theSeparator; //separator for the tokenization
  std::istream* theIStream; //the remaining string (if the input is streamable)
  zstring theInput; //the string to tokenize (if the input is not streamable)
  size_t theNextStartPos; //

  StringSplitIteratorState();

  ~StringSplitIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class StringSplitIterator : public NaryBaseIterator<StringSplitIterator, StringSplitIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StringSplitIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StringSplitIterator,
    NaryBaseIterator<StringSplitIterator, StringSplitIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  StringSplitIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StringSplitIterator, StringSplitIteratorState>(sctx, loc, children)
  {}

  virtual ~StringSplitIterator();

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
