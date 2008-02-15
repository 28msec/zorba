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

#ifndef XQP_STRINGS_IMPL_H
#define XQP_STRINGS_IMPL_H

#include "common/shared_types.h"

#include "runtime/base/binarybase.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"


#ifdef WIN32
#include "util/win32/compatib_defs.h"
#endif

namespace xqp {

class zorba;

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
    CodepointsToStringIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<CodepointsToStringIterator, PlanIteratorState>( loc, arg ){};

    ~CodepointsToStringIterator(){};

    Item_t nextImpl(PlanState& planState) const;
    
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
  std::vector<uint32_t> resVector;
  uint32_t iter;
public:
  void init(PlanState&);
  void reset(PlanState&);

  // TODO for performance reasons we should inline these functions or provide direct access to the members
  void setIterator(uint32_t);
  void setVector(std::vector<uint32_t> vect);
  
  uint32_t getItem(uint32_t iter);
  uint32_t getVectSize();
  uint32_t getIterator();
};

class StringToCodepointsIterator : public UnaryBaseIterator<StringToCodepointsIterator, 
                                                            StringToCodepointsState>
{
public:
  StringToCodepointsIterator ( const yy::location& loc, PlanIter_t& arg )
  :
  UnaryBaseIterator<StringToCodepointsIterator, StringToCodepointsState>( loc, arg ){}

  ~StringToCodepointsIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
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
  CompareStrIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<CompareStrIterator, PlanIteratorState>( loc, args ){}

  ~CompareStrIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/* end class CompareStrIterator */

/*
 * 7.3.3 fn:codepoint-equal
 * --------------------*/
/*begin class CodepointEqualIterator */
class CodepointEqualIterator : public BinaryBaseIterator<CodepointEqualIterator, PlanIteratorState>{
public:
  CodepointEqualIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
  BinaryBaseIterator<CodepointEqualIterator, PlanIteratorState>(loc, arg0, arg1){}

  ~CodepointEqualIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
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
  ConcatStrIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<ConcatStrIterator, PlanIteratorState>( loc, args ){}

  ~ConcatStrIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class ConcatStrIterator */


/*
 * 7.4.2 fn:string-join
 * --------------------*/
/*begin class StringJoinIterator*/
class StringJoinIterator : public BinaryBaseIterator<StringJoinIterator, PlanIteratorState>{
public:
  StringJoinIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
  BinaryBaseIterator<StringJoinIterator, PlanIteratorState>(loc, arg0, arg1){}

  ~StringJoinIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class StringJoinIterator*/

/*
 * 7.4.3 fn:substring
 * --------------------*/
/*begin class SubstringIterator*/
class SubstringIterator : public NaryBaseIterator<SubstringIterator, PlanIteratorState>{
public:
  SubstringIterator( const yy::location loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<SubstringIterator, PlanIteratorState>( loc, args ){}

  ~SubstringIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class SubstringIterator*/

/*
 * 7.4.4 fn:string-length
 * --------------------*/
/*begin class StringLengthIterator*/
class StringLengthIterator : public UnaryBaseIterator<StringLengthIterator, PlanIteratorState>{
public:
  StringLengthIterator(const yy::location loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<StringLengthIterator, PlanIteratorState>(loc, arg0){}

  ~StringLengthIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class StringLengthIterator*/

/*
 * 7.4.5 fn:normalize-space
 * --------------------*/
/*begin class NormalizeSpaceIterator*/
class NormalizeSpaceIterator : public UnaryBaseIterator<NormalizeSpaceIterator, PlanIteratorState>{
public:
  NormalizeSpaceIterator(const yy::location loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<NormalizeSpaceIterator, PlanIteratorState>(loc, arg0){}

  ~NormalizeSpaceIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class NormalizeSpaceIterator*/

/*
 * 7.4.6 fn:normalize-unicode
 * --------------------*/
/*begin class NormalizeUnicodeIterator*/
class NormalizeUnicodeIterator : public NaryBaseIterator<NormalizeUnicodeIterator, PlanIteratorState>{
public:
  NormalizeUnicodeIterator( const yy::location loc,  std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<NormalizeUnicodeIterator, PlanIteratorState>(loc, args){}

  ~NormalizeUnicodeIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class NormalizeUnicodeIterator*/

/*
 * 7.4.7 fn:upper-case
 * --------------------*/
/*begin class UpperCaseIterator*/
class UpperCaseIterator : public UnaryBaseIterator<UpperCaseIterator, PlanIteratorState>{
public:
  UpperCaseIterator(const yy::location loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<UpperCaseIterator, PlanIteratorState>(loc, arg0){}

  ~UpperCaseIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class UpperCaseIterator*/

/*
 * 7.4.8 fn:lower-case
 * --------------------*/
/*begin class LowerCaseIterator*/
class LowerCaseIterator : public UnaryBaseIterator<LowerCaseIterator, PlanIteratorState>{
public:
  LowerCaseIterator(const yy::location loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<LowerCaseIterator, PlanIteratorState>(loc, arg0){}

  ~LowerCaseIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class LowerCaseIterator*/

 /*
 * 7.4.9 fn:translate
 * -------------------- */
/*begin class TranslateIterator*/
class TranslateIterator: public NaryBaseIterator<TranslateIterator, PlanIteratorState> {
public:
  TranslateIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<TranslateIterator, PlanIteratorState>( loc, args ){}

  ~TranslateIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class TranslateIterator*/

 /*
 * 7.4.10 fn:encode-for-uri
 * -------------------- */
/*begin class EncodeForUriIterator*/
class EncodeForUriIterator : public UnaryBaseIterator<EncodeForUriIterator, PlanIteratorState>{
public:
  EncodeForUriIterator(const yy::location loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<EncodeForUriIterator, PlanIteratorState>(loc, arg0){}

  ~EncodeForUriIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class EncodeForUriIterator*/

 /*
 * 7.4.11 fn:iri-to-uri
 * -------------------- */
/*begin class IriToUriIterator*/
class IriToUriIterator : public UnaryBaseIterator<IriToUriIterator, PlanIteratorState>{
public:
  IriToUriIterator(const yy::location loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<IriToUriIterator, PlanIteratorState>(loc, arg0){}

  ~IriToUriIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class IriToUriIterator*/

 /*
 * 7.4.12 fn:escape-html-uri
 * -------------------- */
/*begin class EscapeHtmlUriIterator*/
class EscapeHtmlUriIterator : public UnaryBaseIterator<EscapeHtmlUriIterator, PlanIteratorState>{
public:
  EscapeHtmlUriIterator(const yy::location loc,  PlanIter_t& arg0)
  :
  UnaryBaseIterator<EscapeHtmlUriIterator, PlanIteratorState>(loc, arg0){}

  ~EscapeHtmlUriIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
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
  ContainsIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<ContainsIterator, PlanIteratorState>( loc, args ){}

  ~ContainsIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class ContainsIterator*/

 /*
 * 7.5.2 fn:starts-with
 * -------------------- */
/*begin class StartsWithIterator*/
class StartsWithIterator: public NaryBaseIterator<StartsWithIterator, PlanIteratorState> {
public:
  StartsWithIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<StartsWithIterator, PlanIteratorState>( loc, args ){}

  ~StartsWithIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class StartsWithIterator*/

 /*
 * 7.5.3 fn:ends-with
 * -------------------- */
/*begin class EndsWithIterator*/
class EndsWithIterator: public NaryBaseIterator<EndsWithIterator, PlanIteratorState> {
public:
  EndsWithIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<EndsWithIterator, PlanIteratorState>( loc, args ){}

  ~EndsWithIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class EndsWithIterator*/

 /*
 * 7.5.4 fn:substring-before
 * -------------------- */
/*begin class SubstringBeforeIterator*/
class SubstringBeforeIterator: public NaryBaseIterator<SubstringBeforeIterator, PlanIteratorState> {
public:
  SubstringBeforeIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<SubstringBeforeIterator, PlanIteratorState>( loc, args ){}

  ~SubstringBeforeIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class SubstringBeforeIterator*/

 /*
 * 7.5.5 fn:substring-after
 * -------------------- */
/*begin class SubstringAfterIterator*/
class SubstringAfterIterator: public NaryBaseIterator<SubstringAfterIterator, PlanIteratorState> {
public:
  SubstringAfterIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
  :
  NaryBaseIterator<SubstringAfterIterator, PlanIteratorState>( loc, args ){}

  ~SubstringAfterIterator() {};
public:
  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};
/*end class SubstringAfterIterator*/
}/*namespace xqp*/
#endif /* XQP_STRINGS_IMPL_H */
