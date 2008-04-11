/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/StringsImpl.h
 *
 */

#ifndef ZORBA_STRINGS_IMPL_H
#define ZORBA_STRINGS_IMPL_H

#include "common/common.h"

#include "common/shared_types.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"


namespace zorba {


/*______________________________________________________________________
 *
 * 7.2 Functions to Assemble and Disassemble Strings
 *_______________________________________________________________________*/

 /*
 * 7.2.1 fn:codepoints-to-string
 * -------------------- */
/* begin class CodepointsToStringIterator */
class CodepointsToStringIterator : public UnaryBaseIterator<CodepointsToStringIterator, PlanIteratorState>{
public:
    CodepointsToStringIterator ( const QueryLoc& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<CodepointsToStringIterator, PlanIteratorState>( loc, arg ){};

    ~CodepointsToStringIterator(){};

    store::Item_t nextImpl(PlanState& planState) const;
    
    virtual void accept(PlanIterVisitor&) const;
};
/* end class CodepointsToStringIterator */


/*
 * 7.2.2 fn:string-to-codepoints
 * --------------------*/
/*begin class StringToCodepointsIterator*/
class StringToCodepointsState : public PlanIteratorState
{
private:
  checked_vector<uint32_t> resVector;
  uint32_t iter;
public:
  void init(PlanState&);
  void reset(PlanState&);

  // TODO for performance reasons we should inline these functions or provide direct access to the members
  void setIterator(uint32_t);
  void setVector(checked_vector<uint32_t> vect);
  
  uint32_t getItem(uint32_t iter);
  uint32_t getVectSize();
  uint32_t getIterator();
};

class StringToCodepointsIterator : public UnaryBaseIterator<StringToCodepointsIterator, 
                                                            StringToCodepointsState>
{
public:
  StringToCodepointsIterator ( const QueryLoc& loc, PlanIter_t& arg )
  :
  UnaryBaseIterator<StringToCodepointsIterator, StringToCodepointsState>( loc, arg ){}

  ~StringToCodepointsIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class StringToCodepointsIterator*/

/*______________________________________________________________________
 *
 * 7.3 Equality and Comparison of Strings
 *_______________________________________________________________________*/

/*
 * 7.3.2 fn:compare
 * --------------------*/
/* begin class CompareStrIterator */
class CompareStrIterator: public NaryBaseIterator<CompareStrIterator, PlanIteratorState> {
public:
  CompareStrIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<CompareStrIterator, PlanIteratorState>( loc, args ){}

  ~CompareStrIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/* end class CompareStrIterator */

/*
 * 7.3.3 fn:codepoint-equal
 * --------------------*/
/*begin class CodepointEqualIterator */
class CodepointEqualIterator : public BinaryBaseIterator<CodepointEqualIterator, PlanIteratorState>{
public:
  CodepointEqualIterator( const QueryLoc& loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
  BinaryBaseIterator<CodepointEqualIterator, PlanIteratorState>(loc, arg0, arg1){}

  ~CodepointEqualIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class CodepointEqualIterator */

/*______________________________________________________________________
 *
 * 7.4 Functions on String Values
 *_______________________________________________________________________*/

/*
 * 7.4.1 fn:concat
 * --------------------*/
/*begin class ConcatStrIterator */
class ConcatStrIterator: public NaryBaseIterator<ConcatStrIterator, PlanIteratorState> {
public:
  ConcatStrIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<ConcatStrIterator, PlanIteratorState>( loc, args ){}

  ~ConcatStrIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class ConcatStrIterator */


/*
 * 7.4.2 fn:string-join
 * --------------------*/
/*begin class StringJoinIterator*/
class StringJoinIterator : public BinaryBaseIterator<StringJoinIterator, PlanIteratorState>{
public:
  StringJoinIterator( const QueryLoc& loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
  BinaryBaseIterator<StringJoinIterator, PlanIteratorState>(loc, arg0, arg1){}

  ~StringJoinIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class StringJoinIterator*/

/*
 * 7.4.3 fn:substring
 * --------------------*/
/*begin class SubstringIterator*/
class SubstringIterator : public NaryBaseIterator<SubstringIterator, PlanIteratorState>{
public:
  SubstringIterator( const QueryLoc& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<SubstringIterator, PlanIteratorState>( loc, args ){}

  ~SubstringIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class SubstringIterator*/

/*
 * 7.4.4 fn:string-length
 * --------------------*/
/*begin class StringLengthIterator*/
class StringLengthIterator : public UnaryBaseIterator<StringLengthIterator, PlanIteratorState>{
public:
  StringLengthIterator(const QueryLoc& loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<StringLengthIterator, PlanIteratorState>(loc, arg0){}

  ~StringLengthIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class StringLengthIterator*/

/*
 * 7.4.5 fn:normalize-space
 * --------------------*/
/*begin class NormalizeSpaceIterator*/
class NormalizeSpaceIterator : public UnaryBaseIterator<NormalizeSpaceIterator, PlanIteratorState>{
public:
  NormalizeSpaceIterator(const QueryLoc& loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<NormalizeSpaceIterator, PlanIteratorState>(loc, arg0){}

  ~NormalizeSpaceIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class NormalizeSpaceIterator*/

/*
 * 7.4.6 fn:normalize-unicode
 * --------------------*/
/*begin class NormalizeUnicodeIterator*/
class NormalizeUnicodeIterator : public NaryBaseIterator<NormalizeUnicodeIterator, PlanIteratorState>{
public:
  NormalizeUnicodeIterator( const QueryLoc& loc,  std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<NormalizeUnicodeIterator, PlanIteratorState>(loc, args){}

  ~NormalizeUnicodeIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class NormalizeUnicodeIterator*/

/*
 * 7.4.7 fn:upper-case
 * --------------------*/
/*begin class UpperCaseIterator*/
class UpperCaseIterator : public UnaryBaseIterator<UpperCaseIterator, PlanIteratorState>{
public:
  UpperCaseIterator(const QueryLoc& loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<UpperCaseIterator, PlanIteratorState>(loc, arg0){}

  ~UpperCaseIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class UpperCaseIterator*/

/*
 * 7.4.8 fn:lower-case
 * --------------------*/
/*begin class LowerCaseIterator*/
class LowerCaseIterator : public UnaryBaseIterator<LowerCaseIterator, PlanIteratorState>{
public:
  LowerCaseIterator(const QueryLoc& loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<LowerCaseIterator, PlanIteratorState>(loc, arg0){}

  ~LowerCaseIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class LowerCaseIterator*/

 /*
 * 7.4.9 fn:translate
 * -------------------- */
/*begin class TranslateIterator*/
class TranslateIterator: public NaryBaseIterator<TranslateIterator, PlanIteratorState> {
public:
  TranslateIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<TranslateIterator, PlanIteratorState>( loc, args ){}

  ~TranslateIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class TranslateIterator*/

 /*
 * 7.4.10 fn:encode-for-uri
 * -------------------- */
/*begin class EncodeForUriIterator*/
class EncodeForUriIterator : public UnaryBaseIterator<EncodeForUriIterator, PlanIteratorState>{
public:
  EncodeForUriIterator(const QueryLoc& loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<EncodeForUriIterator, PlanIteratorState>(loc, arg0){}

  ~EncodeForUriIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class EncodeForUriIterator*/

 /*
 * 7.4.11 fn:iri-to-uri
 * -------------------- */
/*begin class IriToUriIterator*/
class IriToUriIterator : public UnaryBaseIterator<IriToUriIterator, PlanIteratorState>{
public:
  IriToUriIterator(const QueryLoc& loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<IriToUriIterator, PlanIteratorState>(loc, arg0){}

  ~IriToUriIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class IriToUriIterator*/

 /*
 * 7.4.12 fn:escape-html-uri
 * -------------------- */
/*begin class EscapeHtmlUriIterator*/
class EscapeHtmlUriIterator : public UnaryBaseIterator<EscapeHtmlUriIterator, PlanIteratorState>{
public:
  EscapeHtmlUriIterator(const QueryLoc& loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<EscapeHtmlUriIterator, PlanIteratorState>(loc, arg0){}

  ~EscapeHtmlUriIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class EscapeHtmlUriIterator*/

/*______________________________________________________________________
 *
 * 7.5 Functions Based on Substring Matching
 *_______________________________________________________________________*/

 /*
 * 7.5.1 fn:contains
 * -------------------- */
/*begin class ContainsIterator*/
class ContainsIterator: public NaryBaseIterator<ContainsIterator, PlanIteratorState> {
public:
  ContainsIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<ContainsIterator, PlanIteratorState>( loc, args ){}

  ~ContainsIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class ContainsIterator*/

 /*
 * 7.5.2 fn:starts-with
 * -------------------- */
/*begin class StartsWithIterator*/
class StartsWithIterator: public NaryBaseIterator<StartsWithIterator, PlanIteratorState> {
public:
  StartsWithIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<StartsWithIterator, PlanIteratorState>( loc, args ){}

  ~StartsWithIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class StartsWithIterator*/

 /*
 * 7.5.3 fn:ends-with
 * -------------------- */
/*begin class EndsWithIterator*/
class EndsWithIterator: public NaryBaseIterator<EndsWithIterator, PlanIteratorState> {
public:
  EndsWithIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<EndsWithIterator, PlanIteratorState>( loc, args ){}

  ~EndsWithIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class EndsWithIterator*/

 /*
 * 7.5.4 fn:substring-before
 * -------------------- */
/*begin class SubstringBeforeIterator*/
class SubstringBeforeIterator: public NaryBaseIterator<SubstringBeforeIterator, PlanIteratorState> {
public:
  SubstringBeforeIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<SubstringBeforeIterator, PlanIteratorState>( loc, args ){}

  ~SubstringBeforeIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class SubstringBeforeIterator*/

 /*
 * 7.5.5 fn:substring-after
 * -------------------- */
/*begin class SubstringAfterIterator*/
class SubstringAfterIterator: public NaryBaseIterator<SubstringAfterIterator, PlanIteratorState> {
public:
  SubstringAfterIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<SubstringAfterIterator, PlanIteratorState>( loc, args ){}

  ~SubstringAfterIterator() {};
public:
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class SubstringAfterIterator*/

// 7.6.2 fn:matches
NARY_ITER(FnMatchesIterator);

// 7.6.3 fn:replace
NARY_ITER(FnReplaceIterator);

// 7.6.4 fn:tokenize
class FnTokenizeIteratorState : public PlanIteratorState {
  public:
    xqp_string theString; // the remaining string
    xqp_string thePattern, theFlags;

    void init(PlanState&);
    void reset(PlanState&);
};

NARY_ITER_STATE(FnTokenizeIterator, FnTokenizeIteratorState);

}/*namespace zorba*/
#endif /* ZORBA_STRINGS_IMPL_H */
