/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/StringsImpl.cpp
 *
 */

#include <iostream>
#include <math.h>
#include "runtime/strings/StringsImpl.h"
#include "util/zorba.h"
#include "util/utf8/utf8.h"
#include "util/math_helper.h"

using namespace std;
namespace xqp {
/**
 *______________________________________________________________________
 *
 *  7.2.1 fn:codepoints-to-string
 *
 *  fn:codepoints-to-string($arg as xs:integer*) as xs:string
 *
 *  Summary:Creates an xs:string from a sequence of code points.
 *Returns the zero-length string if $arg is the empty sequence.
 *If any of the code points in $arg is not a legal XML character,
 *an error is raised [err:FOCH0001] ("Code point not valid.").
 *_______________________________________________________________________*/
/* begin class CodepointsToStringIterator */
Item_t
CodepointsToStringIterator::nextImpl(PlanState& planState){
  Item_t item;
  Item_t resItem;
  xqp_string resStr;

  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  while(true){
    item = consumeNext ( theChild, planState );
    if ( item != NULL ){
      item = item->getAtomizationValue();
      resStr += (uint32_t)item->getIntegerValue();
    }
    else{
      resItem = zorba::getItemFactory()->createString(resStr);
      STACK_PUSH2( resItem, state );
      break;
    }
  }
  STACK_END2();
}
/* end class CodepointsToStringIterator */

/**
 *______________________________________________________________________
 *
 *  7.2.2 fn:string-to-codepoints
 *
 *  fn:string-to-codepoints($arg as xs:string?) as xs:integer*
 *
 *  Summary: Returns the sequence of code points that constitute an xs:string.
 *If $arg is a zero-length string or the empty sequence,
 *the empty sequence is returned.
 *_______________________________________________________________________*/
/* begin class StringToCodepointsIterator */
  Item_t
StringToCodepointsIterator::nextImpl(PlanState& planState){
  // TODO Optimization for large strings: large strings mean that a large integer vector should be store in the state that is not good.
  Item_t item;
  Item_t resItem;
  xqp_string inputStr;

  StringToCodepointsState* state;
  STACK_INIT2(StringToCodepointsState, state, planState);

  item = consumeNext ( theChild, planState );
  if ( item != NULL ){
    inputStr = item->getStringValue();
    state->setVector(inputStr.getCodepoints());

    while (state->getIterator() < state->getVectSize()){
      resItem = zorba::getItemFactory()->createInteger( state->getItem( state->getIterator() ) );
      STACK_PUSH2( resItem, state );
      state->setIterator( state->getIterator() + 1 );
    }
  }
  STACK_END2();
}

void
StringToCodepointsIterator::resetImpl(PlanState& planState) {
  StringToCodepointsState* state;
  GET_STATE(StringToCodepointsState, state, planState);
  state->reset();
}

void
StringToCodepointsIterator::releaseResourcesImpl(PlanState& planState) {
}

int32_t
StringToCodepointsIterator::getStateSize() {
  return sizeof(StringToCodepointsState);
}

int32_t
StringToCodepointsIterator::getStateSizeOfSubtree() {
  return this->getStateSize() + theChild->getStateSizeOfSubtree();
}

void
StringToCodepointsIterator::setOffset(PlanState& planState, int32_t& offset) {
  this->stateOffset = offset;
  offset += getStateSize();
  theChild->setOffset(planState, offset);
}

void
StringToCodepointsIterator::StringToCodepointsState::init() {
  PlanIterator::PlanIteratorState::init();
  iter= 0;
  resVector.clear();
}

void
StringToCodepointsIterator::StringToCodepointsState::reset() {
  PlanIterator::PlanIteratorState::reset();
  iter = 0;
  resVector.clear();
}

void
StringToCodepointsIterator::StringToCodepointsState::setIterator(uint32_t value) {
  iter = value;
}

uint32_t
StringToCodepointsIterator::StringToCodepointsState::getIterator() {
  return iter;
}

void
StringToCodepointsIterator::StringToCodepointsState::setVector(std::vector<uint32_t> vect) {
  resVector = vect;
}

uint32_t
StringToCodepointsIterator::StringToCodepointsState::getItem(uint32_t iter) {
  return resVector[iter];
}

uint32_t
StringToCodepointsIterator::StringToCodepointsState::getVectSize(){
  return resVector.size();
}
/* end class StringToCodepointsIterator */

/**
 *______________________________________________________________________
 *  7.3.2 fn:compare
 * fn:compare($comparand1 as xs:string?,
 *                   $comparand2 as xs:string?) as xs:integer
 *
 * fn:compare(   $comparand1  as xs:string?,
 *                     $comparand2  as xs:string?,
 *                     $collation  as xs:string) as xs:integer?
 *
 * Summary: Returns -1, 0, or 1, depending on whether the value of
 * the $comparand1 is respectively less than, equal to, or greater
 * than the value of $comparand2, according to the rules of
 * the collation that is used.
 *
 * If either argument is the empty sequence, the result is the empty sequence.
 *_______________________________________________________________________*/
/* begin class CompareStrIterator */
Item_t
CompareStrIterator::nextImpl(PlanState& planState) {
  Item_t n0;
  Item_t n1;
  Item_t n2;
  Item_t res;

  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  n0 = consumeNext ( theChildren[0], planState );
  if ( n0 != NULL )  {
    n1 = consumeNext ( theChildren[1], planState );
    if ( n1 != NULL )  {
      n0 = n0->getAtomizationValue();
      n1 = n1->getAtomizationValue();
      if(theChildren.size() == 3)  {
        n2 = consumeNext ( theChildren[2], planState );
        if ( n2 != NULL )  {
          //TODO solve track issue no.26
          res = zorba::getItemFactory()->createInteger(
                  n0->getStringValue().compare(n1->getStringValue(), n2->getStringValue().c_str()));
        }
      }
      else{
        res = zorba::getItemFactory()->createInteger(
                n0->getStringValue().compare(n1->getStringValue()));
      }
      STACK_PUSH2( res, state );
    }
  }

  STACK_END2();
}
/* end class CompareStrIterator */

/**
 *______________________________________________________________________
 *
 *  7.3.3 fn:codepoint-equal
 *
 *  fn:codepoint-equal(   $comparand1    as xs:string?,
 *                                $comparand2    as xs:string?) as xs:boolean?
 *
 *  Summary: Returns true or false depending on whether the value
 * of $comparand1 is equal to the value of $comparand2, according to
 * the Unicode code point collation
 * (http://www.w3.org/2005/xpath-functions/collation/codepoint).
 *
 * If either argument is the empty sequence, the result is the empty sequence.
 * 
 * Note: This function allows xs:anyURI values to be compared
 * without having to specify the Unicode code point collation.
 *_______________________________________________________________________*/
/* begin class CodepointEqualIterator */
Item_t
CodepointEqualIterator::nextImpl(PlanState& planState){
    Item_t item0;
    Item_t item1;
    Item_t res;

    PlanIterator::PlanIteratorState* state;
    STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

    item0 = consumeNext ( theChild0, planState );
    if ( item0 != NULL )  {
      item1 = consumeNext ( theChild1, planState );
      if ( item1 != NULL )  {
        item0 = item0->getAtomizationValue();
        item1 = item1->getAtomizationValue();
        res = zorba::getItemFactory()->createBoolean(
                  item0->getStringValue() == item1->getStringValue());
        STACK_PUSH2( res, state );
      }
    }
    STACK_END2();
}
/* end class CodepointEqualIterator */

/**
 *______________________________________________________________________
 *
 *  7.4.1 fn:concat
 *
 * fn:concat(   $arg1    as xs:anyAtomicType?,
 *                   $arg2    as xs:anyAtomicType?,
 *                   ...                                          ) as xs:string
 * 
 * Summary:
 * Accepts two or more xs:anyAtomicType arguments and casts them to xs:string.
 * Returns the xs:string that is the concatenation of the values of its
 * arguments after conversion.
 * If any of the arguments is the empty sequence, the argument is treated
 * as the zero-length string.
 *
 * The fn:concat function is specified to allow an two or more arguments
 * that are concatenated together.
 *
 * Note:
 * Unicode normalization is not automatically applied to the result
 * of fn:concat. If a normalized result is required, fn:normalize-unicode
 * can be applied to the xs:string returned by fn:concat.
 *_______________________________________________________________________*/
/* begin class ConcatStrIterator */
Item_t
ConcatStrIterator::nextImpl(PlanState& planState) {
  Item_t item;
  Item_t resItem;
  xqp_string resStr;
  std::vector<PlanIter_t>::iterator iter = theChildren.begin();

  int argsNo = theChildren.size();
  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  for(; iter !=  theChildren.end(); iter ++ ){
    item = consumeNext (*iter, planState );
      item = item->getAtomizationValue();
      resStr += item->getStringValue();
  }

  if(theChildren.size()>0){
    resItem = zorba::getItemFactory()->createString(resStr);
    STACK_PUSH2( resItem, state );
  }

  STACK_END2();
}
/* end class ConcatStrIterator */

/**
 *______________________________________________________________________
 *
 *  7.4.2 fn:string-join
 *
 * fn:string-join($arg1 as xs:string*,
 *                     $arg2 as xs:string) as xs:string
 *
 * Summary: Returns a xs:string created by concatenating the members
 * of the $arg1 sequence using $arg2 as a separator.
 *
 * If the value of $arg2 is the zero-length string,
 * then the members of $arg1 are concatenated without a separator.
 *
 * If the value of $arg1 is the empty sequence,
 * the zero-length string is returned.
 *_______________________________________________________________________*/
/* begin class StringJoinIterator */
Item_t
StringJoinIterator::nextImpl(PlanState& planState) {
  Item_t item;
  Item_t resItem;
  xqp_string resStr;
  xqp_string separator;

  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  item = consumeNext(theChild1, planState);
  separator = item->getStringValue();

  if(separator == ""){
    while(true){
      item = consumeNext ( theChild0, planState );
      if ( item != NULL ){
        item = item->getAtomizationValue();
        resStr += item->getStringValue();
      }
      else{
        resItem = zorba::getItemFactory()->createString(resStr);
        STACK_PUSH2( resItem, state );
        break;
      }
    }
  }
  else{
      while(true){
      item = consumeNext ( theChild0, planState );
      if ( item != NULL ){
        item = item->getAtomizationValue();
        resStr += item->getStringValue();
        resStr += separator;
      }
      else{
        resItem = zorba::getItemFactory()->createString(resStr);
        STACK_PUSH2( resItem, state );
        break;
      }
    }
  }
  STACK_END2();
}
/* end class StringJoinIterator */

/**
 *______________________________________________________________________
 *
 *  7.4.3 fn:substring
 *
 *fn:substring(   $sourceString    as xs:string?,
 *                    $startingLoc    as xs:double) as xs:string
 *fn:substring(   $sourceString    as xs:string?,
 *                    $startingLoc    as xs:double,
 *                    $length    as xs:double) as xs:string
 *
 *Summary: Returns the portion of the value of $sourceString beginning
 *at the position indicated by the value of $startingLoc and continuing for
 *the number of characters indicated by the value of $length.
 *The characters returned do not extend beyond $sourceString.
 *If $startingLoc is zero or negative, only those characters in positions
 *greater than zero are returned.
 *
 *More specifically, the three argument version of the function returns
 *the characters in $sourceString whose position $p obeys:
 *fn:round($startingLoc) <= p \< fn:round($startingLoc) + fn:round($length)
 *If the value of $sourceString is the empty sequence, the zero-length string is returned.
 *
 *Note:
 *The first character of a string is located at position 1, not position 0.
 *_______________________________________________________________________*/
/* begin class SubstringIterator */
Item_t
SubstringIterator::nextImpl(PlanState& planState) {
  Item_t item0;
  Item_t item1;
  Item_t item2;
  xqpString resStr;

  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3){
    item0 = consumeNext ( theChildren[0], planState );
    if ( item0 != NULL ){
      if(item0->getStringValue().length() == 0){
        STACK_PUSH2( zorba::getItemFactory()->createString(resStr), state );
      }
      else{
        item1 = consumeNext( theChildren[1], planState );
        if( item1 != NULL ){//note: The first character of a string is located at position 1, not position 0.
          if( theChildren.size() == 2 ){
            resStr = item0->getStringValue().substr((int32_t)round(item1->getDecimalValue())-1);
          }
          else{ //theChildren.size() ==3
            item2 = consumeNext ( theChildren[2], planState );
            if ( item2 != NULL ){
              resStr = item0->getStringValue().substr((int32_t)round(item1->getDecimalValue())-1,
                                                                         (int32_t)round(item2->getDecimalValue()));
            }
          }
          STACK_PUSH2( zorba::getItemFactory()->createString(resStr), state );
        }
      }
    }
  }
  STACK_END2();
}
/* end class SubstringIterator */

  /**
  *______________________________________________________________________
  *
  *  7.4.4 fn:string-length
  *
  *fn:string-length() as xs:integer
  *fn:string-length($arg as xs:string?) as xs:integer
  *
  *Summary: Returns an xs:integer equal to the length
  *in characters of the value of $arg.
  *
  *If the value of $arg is the empty sequence, the xs:integer 0 is returned.
  *If no argument is supplied, $arg defaults to the string value
  *(calculated using fn:string()) of the context item (.).
  *If no argument is supplied or if the argument is the context item and
  *the context item is undefined an error is raised:[err:XPDY0002].
  *_______________________________________________________________________*/
/* begin class StringLengthIterator */
Item_t
StringLengthIterator::nextImpl(PlanState& planState) {
  Item_t item;

  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  item = consumeNext (theChild, planState);
  if ( item != NULL )  {
    STACK_PUSH2(zorba::getItemFactory()->createInteger(
                            item->getStringValue().length()),
                            state);
  }
  else{
    STACK_PUSH2(zorba::getItemFactory()->createInteger(
                            0),
                            state);
  }
  STACK_END2();
}
/* end class StringLengthIterator */

  /**
  *______________________________________________________________________
  *
  *  7.4.5 fn:normalize-space
  *
  *fn:normalize-space() as xs:string
  *fn:normalize-space($arg as xs:string?) as xs:string
  *
  *Summary: Returns the value of $arg with whitespace normalized by
  *stripping leading and trailing whitespace and replacing sequences
  *of one or more than one whitespace character with a single space, #x20.
  *_______________________________________________________________________*/
/* begin class NormalizeSpaceIterator */
Item_t
NormalizeSpaceIterator::nextImpl(PlanState& planState)
{
  xqp_string str("NormalizeSpace: Not yet implemented.");
  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);
  STACK_PUSH2(zorba::getItemFactory()->createString(str),state);
  STACK_END2();
}
/* end class NormalizeSpaceIterator */

  /**
  *______________________________________________________________________
  *
  *  7.4.6 fn:normalize-unicode
  *
  *fn:normalize-unicode(  $arg as xs:string?) as xs:string
  *fn:normalize-unicode(   $arg    as xs:string?,
  *                                  $normalizationForm    as xs:string) as xs:string
  *
  *Summary: Returns the value of $arg normalized according to the
  *normalization criteria for a normalization form identified by the value
  *of $normalizationForm. The effective value of the $normalizationForm
  *is computed by removing leading and trailing blanks, if present,
  *and converting to upper case.
  *
  *If the value of $arg is the empty sequence, returns the zero-length string.
  *
  *If the $normalizationForm is absent, as in the first format above,
  *it shall be assumed to be "NFC"
  *
  *Conforming implementations ·must· support normalization form "NFC" and ·may·
  *support normalization forms "NFD", "NFKC", "NFKD", "FULLY-NORMALIZED".
  *_______________________________________________________________________*/
/* begin class NormalizeUnicodeIterator */
Item_t
NormalizeUnicodeIterator::nextImpl(PlanState& planState)
{
  xqp_string str("NormalizeUnicode: Not yet implemented.");
  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);
  STACK_PUSH2(zorba::getItemFactory()->createString(str),state);
  STACK_END2();
}
/* end class NormalizeUnicodeIterator */

  /**
  *______________________________________________________________________
  *
  *  7.4.7 fn:upper-case
  *
  *fn:upper-case($arg as xs:string?) as xs:string
  *
  *Summary: Returns the value of $arg after translating every character
  *to its upper-case correspondent as defined in the appropriate case
  *mappings section in the Unicode standard.
  *For versions of Unicode beginning with the 2.1.8 update,
  *only locale-insensitive case mappings should be applied. Every lower-case
  *character that does not have an upper-case correspondent, as well as every
  *upper-case character, is included in the returned value in its original form.
  *
  *If the value of $arg is the empty sequence, the zero-length string is returned.
  *_______________________________________________________________________*/
/* begin class UpperCaseIterator */
Item_t
UpperCaseIterator::nextImpl(PlanState& planState)
{
  Item_t item;
  xqp_string emptyStr("");
  
  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  item = consumeNext (theChild, planState);
  if ( item != NULL )  {
    STACK_PUSH2(zorba::getItemFactory()->createString(item->getStringValue().uppercase()),
                state);
  }
  else{
    STACK_PUSH2(zorba::getItemFactory()->createString(emptyStr), state);
  }
  STACK_END2();
}
/* end class UpperCaseIterator */

  /**
  *______________________________________________________________________
  *
  *  7.4.8 fn:lower-case
  *
  *fn:lower-case($arg as xs:string?) as xs:string
  *
  *Summary: Returns the value of $arg after translating every character
  *to its lower-case correspondent as defined in the appropriate case
  *mappings section in the Unicode standard.For versions of Unicode
  *beginning with the 2.1.8 update, only locale-insensitive case mappings
  *should be applied.
  *Every upper-case character that does not have a lower-case correspondent,
  *as well as every lower-case character, is included in the returned value in
  *its original form.
  *If the value of $arg is the empty sequence, the zero-length string is returned.
  *_______________________________________________________________________*/
/* begin class LowerCaseIterator */
Item_t
LowerCaseIterator::nextImpl(PlanState& planState) {
  Item_t item;
  xqp_string emptyStr("");
  
  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  item = consumeNext (theChild, planState);
  if ( item != NULL )  {
    STACK_PUSH2(zorba::getItemFactory()->createString(
        item->getStringValue().lowercase()),
    state);
  }
  else{
    STACK_PUSH2(zorba::getItemFactory()->createString(emptyStr), state);
  }
  STACK_END2();
}
/* end class LowerCaseIterator */

  /**
  *______________________________________________________________________
  *
  *  7.4.9 fn:translate
  *
  *fn:translate(   $arg    as xs:string?,
  *                    $mapString    as xs:string,
  *                    $transString    as xs:string) as xs:string
  *
  *Summary: Returns the value of $arg modified so that every character
  *in the value of $arg that occurs at some position N in the value of
  *$mapString has been replaced by the character that occurs at
  *position N in the value of $transString.
  *If the value of $arg is the empty sequence, the zero-length string is returned.
  *Every character in the value of $arg that does not appear
  *in the value of $mapString is unchanged.
  *
  *Every character in the value of $arg that appears at some position M
  *in the value of $mapString, where the value of $transString is less
  *than M characters in length, is omitted from the returned value.
  *If $mapString is the zero-length string $arg is returned.
  *
  *If a character occurs more than once in $mapString, then the first occurrence
  *determines the replacement character. If $transString is longer than $mapString,
  *the excess characters are ignored.
  *_______________________________________________________________________*/
/* begin class TranslateIterator */
Item_t
TranslateIterator::nextImpl(PlanState& planState) {
  xqp_string str("Translate: Not yet implemented.");
  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);
  STACK_PUSH2(zorba::getItemFactory()->createString(str),state);
  STACK_END2();
}
/* end class TranslateIterator */

  /**
  *______________________________________________________________________
  *
  *  7.5.1 fn:contains
  *
  *fn:contains(  $arg1 as xs:string?, $arg2 as xs:string?) as xs:boolean
  *fn:contains(   $arg1    as xs:string?,
  *                    $arg2    as xs:string?,
  *                    $collation    as xs:string) as xs:boolean
  *
  *Summary: Returns an xs:boolean indicating whether or not
  *the value of $arg1 contains (at the beginning, at the end,
  *or anywhere within) at least one sequence of collation units
  *that provides a minimal match to the collation units in the
  *value of $arg2, according to the collation that is used.
  *
  *Notes:If the value of $arg1 or $arg2 is the empty sequence,
  *or contains only ignorable collation units, it is interpreted as the zero-length string.
  *If the value of $arg2 is the zero-length string, then the function returns true.
  *If the value of $arg1 is the zero-length string, the function returns false.
  *If the specified collation does not support collation units
  *an error ·may· be raised [err:FOCH0004].
  *_______________________________________________________________________*/
/* begin class ContainsIterator */
Item_t
ContainsIterator::nextImpl(PlanState& planState) {
  Item_t item0;
  Item_t item1;
  Item_t itemColl;
  bool resBool;

  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3){
    item0 = consumeNext ( theChildren[0], planState );
    if ( item0 != NULL ){
      item1 = consumeNext( theChildren[1], planState );
      if( item1 != NULL ){
        if( item0->getStringValue().length() == 0 ){
          STACK_PUSH2( zorba::getItemFactory()->createBoolean(false), state );
        }
        else if( item1->getStringValue().length() == 0 ){
          STACK_PUSH2( zorba::getItemFactory()->createBoolean(true), state );
        }
        else{
          if( theChildren.size() == 2 ){
            resBool = (item0->getStringValue().indexOf(item1->getStringValue()) != -1);
          }
          else{ //theChildren.size() ==3
            itemColl = consumeNext ( theChildren[2], planState );
            if ( itemColl != NULL ){
              //TODO solve track issue no.26
              resBool = (item0->getStringValue().indexOf(item1->getStringValue(), itemColl->getStringValue().c_str()) != -1);
            }
          }
          STACK_PUSH2( zorba::getItemFactory()->createBoolean(resBool), state );
        }
      }
    }
  }
  STACK_END2();
}
/*end class ContainsIterator*/

  /**
  *______________________________________________________________________
  *
  *  7.5.2 fn:starts-with
  *
  *fn:starts-with(  $arg1 as xs:string?, $arg2 as xs:string?) as xs:boolean
  *fn:starts-with(   $arg1    as xs:string?,
  *                      $arg2    as xs:string?,
  *                      $collation    as xs:string) as xs:boolean
  *
  *Summary: Returns an xs:boolean indicating
  *whether or not the value of $arg1 starts with a sequence
  *of collation units that provides a minimal match to
  *the collation units of $arg2 according to the collation that is used.
  *
  *Notes:If the value of $arg1 or $arg2 is the empty sequence,or contains
  *only ignorable collation units, it is interpreted as the zero-length string.
  *If the value of $arg2 is the zero-length string, then the function
  *returns true. If the value of $arg1 is the zero-length string and the value
  *of $arg2 is not the zero-length string, then the function returns false.
  *If the specified collation does not support collation units
  *an error ·may· be raised [err:FOCH0004].
  *_______________________________________________________________________*/
/*begin class StartsWithIterator*/
Item_t
StartsWithIterator::nextImpl(PlanState& planState) {
  Item_t item0;
  Item_t item1;
  Item_t itemColl;
  bool resBool;

  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3){
    item0 = consumeNext ( theChildren[0], planState );
    if ( item0 != NULL ){
      item1 = consumeNext( theChildren[1], planState );
      if( item1 != NULL ){
        if( item0->getStringValue().length() == 0 ){
          STACK_PUSH2( zorba::getItemFactory()->createBoolean(false), state );
        }
        else if( item1->getStringValue().length() == 0 ){
          STACK_PUSH2( zorba::getItemFactory()->createBoolean(true), state );
        }
        else{
          if( theChildren.size() == 2 ){
            resBool = (item0->getStringValue().indexOf(item1->getStringValue()) == 0);
          }
          else{ //theChildren.size() ==3
            itemColl = consumeNext ( theChildren[2], planState );
            if ( itemColl != NULL ){
              //TODO solve track issue no.26
              resBool = (item0->getStringValue().indexOf(item1->getStringValue(), itemColl->getStringValue().c_str()) == 0);
            }
          }
          STACK_PUSH2( zorba::getItemFactory()->createBoolean(resBool), state );
        }
      }
    }
  }
  STACK_END2();
}
/*end class StartsWithIterator*/

  /**
  *______________________________________________________________________
  *
  *  7.5.3 fn:ends-with
  *
  *fn:ends-with(  $arg1 as xs:string?, $arg2 as xs:string?) as xs:boolean
  *fn:ends-with(   $arg1    as xs:string?,
  *                      $arg2    as xs:string?,
  *                      $collation    as xs:string) as xs:boolean
  *
  *Summary: Returns an xs:boolean indicating whether or not
  *the value of $arg1 ends with a sequence of collation units
  *that provides a minimal match to the collation units of $arg2
  *according to the collation that is used.
  *
  *Notes:If the value of $arg1 or $arg2 is the empty sequence,
  *or contains only ignorable collation units, it is interpreted as
  *the zero-length string.
  *If the value of $arg2 is the zero-length string, then the function
  *returns true. If the value of $arg1 is the zero-length string and
  *the value of $arg2 is not the zero-length string, then the function returns false.
  *If the specified collation does not support collation
  *units an error ·may· be raised [err:FOCH0004].
  *_______________________________________________________________________*/
/*begin class EndsWithIterator*/
Item_t
EndsWithIterator::nextImpl(PlanState& planState) {
  Item_t item0;
  Item_t item1;
  Item_t itemColl;
  bool resBool;

  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3){
    item0 = consumeNext ( theChildren[0], planState );
    if ( item0 != NULL ){
      item1 = consumeNext( theChildren[1], planState );
      if( item1 != NULL ){
        if( item0->getStringValue().length() == 0 ){
          STACK_PUSH2( zorba::getItemFactory()->createBoolean(false), state );
        }
        else if( item1->getStringValue().length() == 0 ){
          STACK_PUSH2( zorba::getItemFactory()->createBoolean(true), state );
        }
        else{
          if( theChildren.size() == 2 ){
            resBool = item0->getStringValue().endsWith(item1->getStringValue());
          }
          else{ //theChildren.size() ==3
            itemColl = consumeNext ( theChildren[2], planState );
            if ( itemColl != NULL ){
              //TODO solve track issue no.26
              resBool = item0->getStringValue().endsWith(item1->getStringValue(), itemColl->getStringValue().c_str());
            }
          }
          STACK_PUSH2( zorba::getItemFactory()->createBoolean(resBool), state );
        }
      }
    }
  }
  STACK_END2();
}
/*end class EndsWithIterator*/

  /**
  *______________________________________________________________________
  *
  *  7.5.4 fn:substring-before
  *
  *fn:substring-before(  $arg1 as xs:string?, $arg2 as xs:string?) as xs:string
  *fn:substring-before(   $arg1    as xs:string?,
  *                                $arg2    as xs:string?,
  *                                $collation    as xs:string) as xs:string
  *
  *Summary: Returns the substring of the value of
  *$arg1 that precedes in the value of $arg1 the first occurrence
  *of a sequence of collation units that provides a minimal match
  *to the collation units of $arg2 according to the collation that is used.
  *
  *Notes:If the value of $arg1 or $arg2 is the empty sequence,
  *or contains only ignorable collation units, it is interpreted
  *as the zero-length string.
  *If the value of $arg2 is the zero-length string, then the function
  *returns the zero-length string.
  *If the value of $arg1 does not contain a string that is equal to
  *the value of $arg2, then the function returns the zero-length string.
  *If the specified collation does not support collation units
  *an error ·may· be raised [err:FOCH0004].
  *_______________________________________________________________________*/
/*begin class SubstringBeforeIterator*/
Item_t
SubstringBeforeIterator::nextImpl(PlanState& planState) {
  Item_t item0;
  Item_t item1;
  Item_t itemColl;
  xqp_string resStr;
  int32_t index;

  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3){
    item0 = consumeNext ( theChildren[0], planState );
    if ( item0 != NULL ){
      item1 = consumeNext( theChildren[1], planState );
      if( item1 != NULL ){
        if( item0->getStringValue().length() == 0  || item1->getStringValue().length() == 0){
          STACK_PUSH2( zorba::getItemFactory()->createString(resStr), state );
        }
        else{
          if( theChildren.size() == 2 ){
            index = item0->getStringValue().indexOf(item1->getStringValue());
          }
          else{ //theChildren.size() ==3
            itemColl = consumeNext ( theChildren[2], planState );
            if ( itemColl != NULL ){
              //TODO solve track issue no.26
              index = item0->getStringValue().indexOf(item1->getStringValue(), itemColl->getStringValue().c_str());
            }
          }
          if(index != -1){
            resStr = item0->getStringValue().substr(0,index);
          }
          STACK_PUSH2( zorba::getItemFactory()->createString(resStr), state );
        }
      }
    }
  }
  STACK_END2();
}
/*end class SubstringBeforeIterator*/

  /**
  *______________________________________________________________________
  *
  *  7.5.5 fn:substring-after
  *
  *fn:substring-after(    $arg1 as xs:string?, $arg2 as xs:string?) as xs:string
  *fn:substring-after(   $arg1    as xs:string?,
  *                              $arg2    as xs:string?,
  *                              $collation    as xs:string) as xs:string
  *
  *Summary: Returns the substring of the value of $arg1
  *that follows in the value of $arg1 the first occurrence of a
  *sequence of collation units that provides a minimal match to
  *the collation units of $arg2 according to the collation that is used.
  *
  *Notes: If the value of $arg1 or $arg2 is the empty sequence,
  *or contains only ignorable collation units, it is interpreted
  *as the zero-length string.
  *If the value of $arg2 is the zero-length string, then the function
  *returns the value of $arg1.
  *If the value of $arg1 does not contain a string that is equal to
  *the value of $arg2, then the function returns the zero-length string.
  *If the specified collation does not support collation units
  *an error ·may· be raised [err:FOCH0004].
  *_______________________________________________________________________*/
/*begin class SubstringAfterIterator*/
Item_t
SubstringAfterIterator::nextImpl(PlanState& planState) {
  Item_t item0;
  Item_t item1;
  Item_t itemColl;
  xqp_string resStr;
  int32_t startPos;

  PlanIterator::PlanIteratorState* state;
  STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3){
    item0 = consumeNext ( theChildren[0], planState );
    if ( item0 != NULL ){
      item1 = consumeNext( theChildren[1], planState );
      if( item1 != NULL ){
        if( item0->getStringValue().length() == 0  || item1->getStringValue().length() == 0){
          STACK_PUSH2( zorba::getItemFactory()->createString(resStr), state );
        }
        else{
          if( theChildren.size() == 2 ){
            startPos = item0->getStringValue().lastIndexOf(item1->getStringValue());
          }
          else{ //theChildren.size() ==3
            itemColl = consumeNext ( theChildren[2], planState );
            if ( itemColl != NULL ){
              //TODO solve track issue no.26
              startPos = item0->getStringValue().lastIndexOf(item1->getStringValue(),
                                                             itemColl->getStringValue().c_str());
            }
          }
          if(startPos != -1){
            startPos += item1->getStringValue().length();
            resStr = item0->getStringValue().substr( startPos,
                                                     item0->getStringValue().length() - startPos);
          }
          STACK_PUSH2( zorba::getItemFactory()->createString(resStr), state );
        }
      }
    }
  }
  STACK_END2();
}
/*end class SubstringAfterIterator*/
} /* namespace xqp */
