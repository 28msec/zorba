/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file runtime/strings/StringsImpl.cpp
 *
 */
#include <iostream>

#include "zorbatypes/zorbatypesError.h"
#include "zorbatypes/numconversions.h"

#include "common/common.h"
#include "store/api/item.h"

#include "system/globalenv.h"
#include "runtime/strings/StringsImpl.h"
#include "runtime/api/runtimecb.h"
#include "util/Assert.h"
#include "store/api/item_factory.h"
#include "context/static_context.h"
#include "context/collation_cache.h"

#include "errors/error_messages.h"


using namespace std;

namespace zorba {
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
store::Item_t
CodepointsToStringIterator::nextImpl(PlanState& planState) const {
  store::Item_t item;
  store::Item_t resItem;
  xqp_string resStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while(true){
    item = consumeNext(theChild.getp(), planState );
    if ( item != NULL ){
      item = item->getAtomizationValue();
      {
        xqp_string lUtf8Code = item->getIntegerValue().toString();
        uint32_t lCode;
        if (NumConversions::strToUInt(lUtf8Code, lCode)) {
          try{
            resStr += lCode;
            }
            catch(zorbatypesException& ex){
              ZORBA_ERROR_LOC_DESC(error::DecodeZorbatypesError(ex.ErrorCode()), loc, lUtf8Code);
            }
        }
        else
          ZORBA_ERROR_LOC_DESC(ZorbaError::FOCH0001, loc, lUtf8Code);
      }
    }
    else{
      resItem = GENV_ITEMFACTORY->createString(resStr.getStore());
      STACK_PUSH( resItem, state );
      break;
    }
  }
  STACK_END (state);
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
store::Item_t
StringToCodepointsIterator::nextImpl(PlanState& planState) const {
  // TODO Optimization for large strings: large strings mean that a large integer vector should be store in the state that is not good.
  store::Item_t item;
  store::Item_t resItem;
  xqpStringStore_t inputStr;

  StringToCodepointsState* state;
  DEFAULT_STACK_INIT(StringToCodepointsState, state, planState);

  item = consumeNext(theChild.getp(), planState );
  if ( item != NULL ){
    inputStr = item->getStringValue();
    if(!inputStr->empty())
    {
      state->setVector(inputStr->getCodepoints());
  
      while (state->getIterator() < state->getVectSize())
      {
        resItem = GENV_ITEMFACTORY->createInteger( 
          Integer::parseInt(state->getItem( state->getIterator() )) 
        );
        STACK_PUSH( resItem, state );
        state->setIterator( state->getIterator() + 1 );
      }
    }
  }
  STACK_END (state);
}

void
StringToCodepointsState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  iter= 0;
  resVector.clear();
}

void
StringToCodepointsState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  iter = 0;
  resVector.clear();
}

void
StringToCodepointsState::setIterator(uint32_t value)
{
  iter = value;
}

uint32_t
StringToCodepointsState::getIterator() {
  return iter;
}

void
StringToCodepointsState::setVector(checked_vector<uint32_t> vect)
{
  resVector = vect;
}

uint32_t
StringToCodepointsState::getItem(uint32_t iter)
{
  return resVector[iter];
}

uint32_t
StringToCodepointsState::getVectSize()
{
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
store::Item_t
CompareStrIterator::nextImpl(PlanState& planState) const {
  store::Item_t n0;
  store::Item_t n1;
  store::Item_t n2;
  store::Item_t res;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  n0 = consumeNext(theChildren[0].getp(), planState );
  if ( n0 != NULL )  {
    n1 = consumeNext(theChildren[1].getp(), planState );
    if ( n1 != NULL )  
    {
      n0 = n0->getAtomizationValue();
      n1 = n1->getAtomizationValue();

      if(theChildren.size() == 3)
      {
        n2 = consumeNext(theChildren[2].getp(), planState );
        if ( n2 != NULL )  {
          n2 = n2->getAtomizationValue();
          XQPCollator* coll = 0;
          try {
            coll = planState.theRuntimeCB->theCollationCache->getCollator(n2->getStringValue());
          } catch (error::ZorbaError& e) {
            // rethrow the error with a location argument
            ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
          }
          res = GENV_ITEMFACTORY->createInteger(
                  Integer::parseInt((int32_t)n0->getStringValue()->compare(n1->getStringValue(), coll)));
        }
      }
      else {
        XQPCollator* coll = 0;
        try {
          coll = planState.theRuntimeCB->theCollationCache->getDefaultCollator();
        } catch (error::ZorbaError& e) {
          // rethrow the error with a location argument
          ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
        }
        res = GENV_ITEMFACTORY->createInteger(
                Integer::parseInt((int32_t)n0->getStringValue()->compare(n1->getStringValue(), coll)));
      }
      STACK_PUSH( res, state );
    }
  }

  STACK_END (state);
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
store::Item_t
CodepointEqualIterator::nextImpl(PlanState& planState) const {
    store::Item_t item0;
    store::Item_t item1;
    store::Item_t res;

    PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

    item0 = consumeNext(theChild0.getp(), planState );
    if ( item0 != NULL )  {
      item1 = consumeNext(theChild1.getp(), planState );
      if ( item1 != NULL )  {
        item0 = item0->getAtomizationValue();
        item1 = item1->getAtomizationValue();
        res = GENV_ITEMFACTORY->createBoolean(
                  item0->getStringValue()->equals(item1->getStringValue()));
        STACK_PUSH( res, state );
      }
    }
    STACK_END (state);
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
store::Item_t
ConcatStrIterator::nextImpl(PlanState& planState) const {
  store::Item_t lItem;
  std::stringstream lResStream;
  xqpStringStore_t tmp;

  checked_vector<PlanIter_t>::const_iterator iter = theChildren.begin();
  checked_vector<PlanIter_t>::const_iterator end  = theChildren.end();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  for(; iter != end;  ++iter )
  {
    if ( ( lItem = consumeNext(*iter, planState) ) != NULL )
    {
      lResStream << lItem->getStringValue()->str();

      if  ( ( lItem = consumeNext(*iter, planState) ) != NULL )
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc,
          "A sequence with more than one item is not allowed as argument to fn:concat");
          break;
      }
    }
  }

  tmp = new xqpStringStore(lResStream.str());
  STACK_PUSH(GENV_ITEMFACTORY->createString(tmp), state);

  STACK_END (state);
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
store::Item_t
StringJoinIterator::nextImpl(PlanState& planState) const {
  store::Item_t item;
  store::Item_t resItem;
  xqpStringStore_t resStr = new xqpStringStore("");
  xqpStringStore_t separator;
  bool lFirst;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChild1.getp(), planState);

  separator = item->getStringValue();

  if(separator->empty())
  {
    while(true)
    {
      item = consumeNext(theChild0.getp(), planState );
      if ( item != NULL )
      {
        item = item->getAtomizationValue();
        resStr->str() += item->getStringValue()->str();
      }
      else{
        resItem = GENV_ITEMFACTORY->createString(resStr);
        STACK_PUSH( resItem, state );
        break;
      }
    }
  }
  else
  {
    lFirst = true;
    while(true)
    {
      item = consumeNext(theChild0.getp(), planState );
      if ( item != NULL )
      {
        item = item->getAtomizationValue();
        if (!lFirst){
          resStr->str() += separator->str();
        } else {
          lFirst = false;
        }
        resStr->str() += item->getStringValue()->str();
      }
      else
      {
        resItem = GENV_ITEMFACTORY->createString(resStr);
        STACK_PUSH( resItem, state );
        break;
      }
    }
  }
  STACK_END (state);
}
/* end class StringJoinIterator */

/**
 *______________________________________________________________________
 *
 *  7.4.3 fn:substring
 *
 *fn:substring($sourceString   as xs:string?,
 *             $startingLoc    as xs:double) as xs:string
 *
 *fn:substring($sourceString as xs:string?,
 *             $startingLoc  as xs:double,
 *             $length       as xs:double) as xs:string
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
store::Item_t
SubstringIterator::nextImpl(PlanState& planState) const
{
  store::Item_t stringItem;
  store::Item_t startItem;
  store::Item_t lenItem;
  xqpString stringVal;
  xqpString resStr;
  int32_t tmpStart;
  int32_t tmpLen;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  stringItem = consumeNext(theChildren[0].getp(), planState );
  if (stringItem != NULL )
  {
    stringItem = stringItem->getAtomizationValue();

    if (!stringItem->getStringValue()->empty())
    {
      stringVal = stringItem->getStringValue().getp();

      startItem = consumeNext(theChildren[1].getp(), planState );

      ZORBA_ASSERT(startItem != NULL);

      // note: The first character of a string is located at position 1,
      // not position 0.
      startItem = startItem->getAtomizationValue();

      if(!startItem->getDoubleValue().isNaN())
      {
        tmpStart = stringVal.length();

        if (startItem->getDoubleValue().isFinite())
        {
          xqp_int lInt;
          if (NumConversions::doubleToInt(startItem->getDoubleValue().round(), lInt))
            tmpStart = lInt;
        }

        if( theChildren.size() == 2 )
        {
          resStr = new xqpStringStore(stringVal.substr(tmpStart-1));
        }
        else
        {
          //theChildren.size() ==3
          lenItem = consumeNext(theChildren[2].getp(), planState );

          ZORBA_ASSERT(startItem != NULL);

          lenItem = lenItem->getAtomizationValue();

          tmpLen = stringVal.length() - tmpStart + 1;
          
          if(!lenItem->getDoubleValue().isNaN())
          {
            if (lenItem->getDoubleValue().isFinite())
            {
              xqp_int lInt;
              if(NumConversions::doubleToInt(lenItem->getDoubleValue().round(), lInt))
                tmpLen = lInt;
            }
                
            if( !(startItem->getDoubleValue() + lenItem->getDoubleValue()).isNaN())
            {
              if(tmpLen >= 0)
              {
                if(tmpStart <= 0)
                {
                  if((tmpLen+tmpStart-1) >= 0)
                    resStr = stringVal.substr(0,  tmpStart-1 + tmpLen);
                //  else
                //    ZORBA_ERROR_ALERT();
                }
                else
                  resStr = stringVal.substr(tmpStart-1, tmpLen);
              }
              //else
              //  ZORBA_ERROR_ALERT();
            }
          }
        }
      } // non NaN start arg
    } // non empty string arg
  } // non NULL string arg

  if (!resStr.empty())
    resStr = resStr.formatAsXML(resStr.c_str());

  STACK_PUSH( GENV_ITEMFACTORY->createString(resStr.getStore()), state );

  STACK_END (state);
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
store::Item_t
StringLengthIterator::nextImpl(PlanState& planState) const {
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChild.getp(), planState);
  if ( item != NULL )
  {
    item = item->getAtomizationValue();
    STACK_PUSH(GENV_ITEMFACTORY->createInteger(
                            Integer::parseSizeT(item->getStringValue()->numChars())),
                            state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createInteger(
                            Integer::parseInt((int32_t)0)),
                            state);
  }
  STACK_END (state);
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
store::Item_t
NormalizeSpaceIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item;
  xqpStringStore_t empty;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChild.getp(), planState);
  if ( item != NULL )
  {
    item = item->getAtomizationValue();
    STACK_PUSH(GENV_ITEMFACTORY->createString(item->getStringValue()->normalizeSpace()),
               state);
  }
  else
  {
    empty = new xqpStringStore("");
    STACK_PUSH(GENV_ITEMFACTORY->createString(empty), state);
  }
  STACK_END (state);
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
store::Item_t
NormalizeUnicodeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;
  xqpStringStore_t tempStr = new xqpStringStore("NFC");
  xqpString res;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item0 = consumeNext(theChildren[0].getp(), planState );
  if(item0 != NULL)
  {
    if(theChildren.size() == 2)
    {
      item1 = consumeNext(theChildren[1].getp(), planState );
      if(item1 != NULL)
      {
        item1 = item1->getAtomizationValue();
        tempStr = item1->getStringValue()->uppercase()->trim();
      }
    }

    if(tempStr->empty() ||
       tempStr->str() == "NFC" ||
       tempStr->str() =="NFKC" ||
       tempStr->str() =="NFD" ||
       tempStr->str() == "NFKD")
    {
      res = item0->getStringValue().getp();
      res = res.normalize(tempStr.getp());
      STACK_PUSH( GENV_ITEMFACTORY->createString(res.getStore()), state );
    }
    else
    {
      ZORBA_ERROR_LOC_DESC(ZorbaError::FOCH0003, loc, "Unsupported normalization form.");
    }
  }
  else
  {
    // must push empty string due to return type of function
    STACK_PUSH( GENV_ITEMFACTORY->createString(res.getStore()), state);
  }
  
  STACK_END (state);
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
store::Item_t
UpperCaseIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item;
  xqpStringStore_t empty;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChild.getp(), planState);
  if ( item != NULL )
  {
    item = item->getAtomizationValue();
    STACK_PUSH(GENV_ITEMFACTORY->createString(item->getStringValue()->uppercase()),
               state);
  }
  else
  {
    empty = new xqpStringStore("");
    STACK_PUSH(GENV_ITEMFACTORY->createString(empty), state);
  }
  STACK_END (state);
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
store::Item_t
LowerCaseIterator::nextImpl(PlanState& planState) const {
  store::Item_t item;
  xqpStringStore_t empty;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChild.getp(), planState);
  if ( item != NULL )
  {
    item = item->getAtomizationValue();
    STACK_PUSH(GENV_ITEMFACTORY->createString(item->getStringValue()->lowercase()),
               state);
  }
  else
  {
    empty = new xqpStringStore("");
    STACK_PUSH(GENV_ITEMFACTORY->createString(empty), state);
  }
  STACK_END (state);
}
/* end class LowerCaseIterator */

  /**
  *______________________________________________________________________
  *
  *  7.4.9 fn:translate
  *
  *fn:translate($arg          as xs:string?,
  *             $mapString    as xs:string,
  *             $transString  as xs:string) as xs:string
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
store::Item_t
TranslateIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg, item0, item1;
  store::Item_t res;
  xqpString strvalarg;
  xqpString strval0;
  xqpString strval1;
  xqpStringStore* empty;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState );
  if ( itemArg != NULL )
  {
    item0 = consumeNext(theChildren[1].getp(), planState );
    if ( item0 != NULL )
    {
      item1 = consumeNext(theChildren[2].getp(), planState );
      if ( item1 != NULL )
      {
        item0 = item0->getAtomizationValue();
        item1 = item1->getAtomizationValue();

        strval0 = item0->getStringValue().getp();
        strval1 = item1->getStringValue().getp();

        strvalarg = itemArg->getStringValue().getp();

        res = GENV_ITEMFACTORY->createString(
                                 strvalarg.translate(strval0, strval1).getStore());
      }
    }
  }
  
  if (res == NULL)
  {
    empty = new xqpStringStore("");
    res = GENV_ITEMFACTORY->createString(empty);
  }

  STACK_PUSH( res, state );
  STACK_END (state);
}
/* end class TranslateIterator */

 /**
 *______________________________________________________________________
 *
 *  7.4.10 fn:encode-for-uri
 *
 *_______________________________________________________________________*/
/* begin class EncodeForUriIterator */
store::Item_t
EncodeForUriIterator::nextImpl(PlanState& planState) const {
  store::Item_t item;
  xqpStringStore_t empty;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChild.getp(), planState);
  if ( item != NULL )
  {
    item = item->getAtomizationValue();
    STACK_PUSH(GENV_ITEMFACTORY->createString(item->getStringValue()->encodeForUri()),
               state);
  }
  else
  {
    empty = new xqpStringStore("");
    STACK_PUSH(GENV_ITEMFACTORY->createString(empty), state);
  }
  STACK_END (state);
}
/* end class EncodeForUriIterator */
  /**
 *______________________________________________________________________
 *
 *  7.4.11 fn:iri-to-uri
 *
 *_______________________________________________________________________*/
/* begin class IriToUriIterator */
store::Item_t
IriToUriIterator::nextImpl(PlanState& planState) const {
  store::Item_t item;
  xqpStringStore_t empty;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChild.getp(), planState);
  if ( item != NULL )
  {
    item = item->getAtomizationValue();
    STACK_PUSH(GENV_ITEMFACTORY->createString(item->getStringValue()->iriToUri()),
               state);
  }
  else
  {
    empty = new xqpStringStore("");
    STACK_PUSH(GENV_ITEMFACTORY->createString(empty), state);
  }
  STACK_END (state);
}
/* end class IriToUriIterator */
  /**
 *______________________________________________________________________
 *
 *  7.4.12 fn:escape-html-uri
 *
 *_______________________________________________________________________*/
/* begin class EscapeHtmlUriIterator */
store::Item_t
EscapeHtmlUriIterator::nextImpl(PlanState& planState) const {
  store::Item_t item;
  xqpStringStore_t empty;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChild.getp(), planState);
  if ( item != NULL )
  {
    item = item->getAtomizationValue();
    STACK_PUSH(GENV_ITEMFACTORY->createString(item->getStringValue()->escapeHtmlUri()),
               state);
  }
  else
  {
    empty = new xqpStringStore("");
    STACK_PUSH(GENV_ITEMFACTORY->createString(empty), state);
  }
  STACK_END (state);
}
/* end class EscapeHtmlUriIterator */

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
store::Item_t
ContainsIterator::nextImpl(PlanState& planState) const {
  store::Item_t item0;
  store::Item_t item1;
  store::Item_t itemColl;
  bool resBool = false;
  xqpStringStore_t arg1;
  xqpStringStore_t arg2;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3)
  {
    item0 = consumeNext(theChildren[0].getp(), planState );
    if ( item0 != NULL )
    {
      item0 = item0->getAtomizationValue();
      arg1 = item0->getStringValue();
    }
    else
    {
      arg1 = new xqpStringStore("");
    }

    item1 = consumeNext(theChildren[1].getp(), planState );
    if( item1 != NULL )
    {
      item1 = item1->getAtomizationValue();
      arg2 = item1->getStringValue();
    }
    else
    {
      arg2 = new xqpStringStore("");
    }
    
    if( arg2->empty())
    {
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(true), state );
    }
    else if ( arg1->empty())
    {
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(false), state );
    }
    else
    {
      if( theChildren.size() == 2 )
      {
        resBool = (arg1->indexOf(arg2, NULL) != -1);
      }
      else
      {
        //theChildren.size() ==3
        itemColl = consumeNext(theChildren[2].getp(), planState );
        if ( itemColl != NULL )
        {
          itemColl = itemColl->getAtomizationValue();
          XQPCollator* coll = 0;
          try {
            coll = planState.theRuntimeCB->theCollationCache->getCollator(itemColl->getStringValue());
          } catch (error::ZorbaError& e) {
            // rethrow the error with a location argument
            ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
          }
          resBool = (arg1->indexOf(arg2, coll) != -1);
        }
      }
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(resBool), state );
    }
  }
  STACK_END (state);
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
store::Item_t
StartsWithIterator::nextImpl(PlanState& planState) const {
  store::Item_t item0;
  store::Item_t item1;
  store::Item_t itemColl;
  bool resBool = false;
  xqpStringStore_t arg1;
  xqpStringStore_t arg2;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3)
  {
    item0 = consumeNext(theChildren[0].getp(), planState );
    if ( item0 != NULL )
    {
      item0 = item0->getAtomizationValue();
      arg1 = item0->getStringValue();
    }
    else
    {
      arg1 = new xqpStringStore("");
    }

    item1 = consumeNext(theChildren[1].getp(), planState );
    if( item1 != NULL )
    {
      item1 = item1->getAtomizationValue();
      arg2 = item1->getStringValue();
    }
    else
    {
      arg2 = new xqpStringStore("");
    }

    if(arg2->empty())
    {
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(true), state );
    }
    else if (arg2->empty())
    {
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(false), state );
    }
    else
    {
      if( theChildren.size() == 2 )
      {
        resBool = (arg1->indexOf(arg2, NULL) == 0);
      }
      else
      { //theChildren.size() ==3
        itemColl = consumeNext(theChildren[2].getp(), planState );
        if ( itemColl != NULL )
        {
          itemColl = itemColl->getAtomizationValue();
          XQPCollator* coll = 0;
          try {
            coll = planState.theRuntimeCB->theCollationCache->getCollator(itemColl->getStringValue());
          } catch (error::ZorbaError& e) {
            // rethrow the error with a location argument
            ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
          }
          resBool = (arg1->indexOf(arg2, coll) == 0);
        }
      }
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(resBool), state );
    }
  }
  STACK_END (state);
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
store::Item_t
EndsWithIterator::nextImpl(PlanState& planState) const {
  store::Item_t item0;
  store::Item_t item1;
  store::Item_t itemColl;
  bool resBool = false;
  xqpStringStore_t arg1;
  xqpStringStore_t arg2;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3)
  {
    item0 = consumeNext(theChildren[0].getp(), planState );
    if ( item0 != NULL )
    {
      item0 = item0->getAtomizationValue();
      arg1 = item0->getStringValue();
    }
    else
    {
      arg1 = new xqpStringStore("");
    }

    item1 = consumeNext(theChildren[1].getp(), planState );
    if( item1 != NULL )
    {
      item1 = item1->getAtomizationValue();
      arg2 = item1->getStringValue();
    }
    else
    {
      arg2 = new xqpStringStore("");
    }

    if(arg2->empty())
    {
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(true), state );
    }
    else if (arg1->empty())
    {
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(false), state );
    }
    else
    {
      if( theChildren.size() == 2 )
      {
        resBool = (arg1->endsWith(arg2, NULL));
      }
      else
      { //theChildren.size() ==3
        itemColl = consumeNext(theChildren[2].getp(), planState );
        if ( itemColl != NULL )
        {
          itemColl = itemColl->getAtomizationValue();
          XQPCollator* coll = 0;
          try {
            coll = planState.theRuntimeCB->theCollationCache->getCollator(itemColl->getStringValue());
          } catch (error::ZorbaError& e) {
            // rethrow the error with a location argument
            ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
          }
          resBool = arg1->endsWith(arg2, coll);
        }
      }
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(resBool), state );
    }
  }
  STACK_END (state);
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
store::Item_t
SubstringBeforeIterator::nextImpl(PlanState& planState) const {
  store::Item_t item0;
  store::Item_t item1;
  store::Item_t itemColl;
  int32_t index = -1;
  xqpStringStore_t arg1;
  xqpStringStore_t arg2;
  xqpStringStore* resStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3)
  {
    item0 = consumeNext(theChildren[0].getp(), planState );
    if ( item0 != NULL )
    {
      item0 = item0->getAtomizationValue();
      arg1 = item0->getStringValue();
    }
    else
    {
      arg1 = new xqpStringStore("");
    }

    item1 = consumeNext(theChildren[1].getp(), planState );
    if( item1 != NULL )
    {
      item1 = item1->getAtomizationValue();
      arg2 = item1->getStringValue();
    }
    else
    {
      arg2 = new xqpStringStore("");
    }

    if( arg1->empty() || arg2->empty())
    {
      resStr = new xqpStringStore("");
      STACK_PUSH( GENV_ITEMFACTORY->createString(resStr), state );
    }
    else
    {
      if( theChildren.size() == 2 )
      {
        index = arg1->indexOf(arg2, NULL);
      }
      else
      {
        //theChildren.size() ==3
        itemColl = consumeNext(theChildren[2].getp(), planState );
        if ( itemColl != NULL )
        {
          itemColl = itemColl->getAtomizationValue();
          XQPCollator* coll = 0;
          try {
            coll = planState.theRuntimeCB->theCollationCache->getCollator(itemColl->getStringValue());
          } catch (error::ZorbaError& e) {
            // rethrow the error with a location argument
            ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
          }
          index = arg1->indexOf(arg2, coll);
        }
      }

      if(index != -1)
        resStr = new xqpStringStore(arg1->str().substr(0, index));
      else
        resStr = new xqpStringStore("");

      STACK_PUSH( GENV_ITEMFACTORY->createString(resStr), state );
    }
  }
  STACK_END (state);
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
store::Item_t
SubstringAfterIterator::nextImpl(PlanState& planState) const {
  store::Item_t item0;
  store::Item_t item1;
  store::Item_t itemColl;
  int32_t startPos = -1;
  xqpStringStore_t arg1;
  xqpStringStore_t arg2;
  xqpStringStore* resStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3)
  {
    item0 = consumeNext(theChildren[0].getp(), planState );
    if ( item0 != NULL )
    {
      item0 = item0->getAtomizationValue();
      arg1 = item0->getStringValue();
    }
    else
    {
      arg1 = new xqpStringStore("");
    }

    item1 = consumeNext(theChildren[1].getp(), planState );
    if( item1 != NULL )
    {
      item1 = item1->getAtomizationValue();
      arg2 = item1->getStringValue();
    }
    else
    {
      arg2 = new xqpStringStore("");
    }

    if( arg1->empty()  || arg2->empty())
    {
      resStr = new xqpStringStore("");
      STACK_PUSH( GENV_ITEMFACTORY->createString(resStr), state );
    }
    else
    {
      if( theChildren.size() == 2 )
      {
        startPos = arg1->indexOf(arg2, NULL);
      }
      else
      {
        //theChildren.size() ==3
        itemColl = consumeNext(theChildren[2].getp(), planState );
        if ( itemColl != NULL )
        {
          itemColl = itemColl->getAtomizationValue();
          XQPCollator* coll = 0;
          try {
            coll = planState.theRuntimeCB->theCollationCache->getCollator(itemColl->getStringValue());
          } catch (error::ZorbaError& e) {
            // rethrow the error with a location argument
            ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
          }
          startPos = arg1->indexOf( arg2, coll );
        }
      }

      if(startPos != -1)
      {
        startPos += arg2->bytes();
        resStr = new xqpStringStore(arg1->str().substr(startPos,
                                                       arg1->bytes() - startPos));
      }
      else
      {
        resStr = new xqpStringStore("");
      }
      STACK_PUSH( GENV_ITEMFACTORY->createString(resStr), state );
    }
  }
  STACK_END (state);
}
/*end class SubstringAfterIterator*/

/**
 *______________________________________________________________________
 *
 *  7.6.2 fn:matches
 *
 *fn:matches($input   as xs:string?,
 *           $pattern as xs:string) as xs:boolean
 *
 *fn:matches($input   as xs:string?,
 *           $pattern as xs:string,
 *           $flags   as xs:string) as xs:boolean
 *_______________________________________________________________________*/
 /*begin class FnMatchesIterator*/
store::Item_t
FnMatchesIterator::nextImpl(PlanState& planState) const
{
#ifndef ZORBA_NO_UNICODE
  xqp_string input;
  xqp_string pattern;
  xqp_string flags;
  store::Item_t item;
  bool res = false;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChildren[0].getp(), planState);
  if( item != NULL )
    input = item->getStringValue().getp();

  item = consumeNext(theChildren[1].getp(), planState);
  assert (item != NULL);
  pattern = item->getStringValue().getp();

  if(theChildren.size() == 3) 
  {
    item = consumeNext(theChildren[2].getp(), planState);
    assert (item != NULL);
    flags = item->getStringValue().getp();
  }
  try{
    res = input.matches(pattern, flags);
  }
  catch(zorbatypesException& ex){
    ZORBA_ERROR_LOC_DESC(error::DecodeZorbatypesError(ex.ErrorCode()), loc, "");
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(res), state); 
  
  STACK_END (state);
#else
  ZORBA_ERROR(ZorbaError::FORX0002);///invalid regular expression (no reg exp supported)
  return NULL;
#endif
}
/*end class FnMatchesIterator*/

/**
 *______________________________________________________________________
 *
 *  7.6.3 fn:replace
 *
 *fn:replace($input       as xs:string?,
 *           $pattern     as xs:string,
 *           $replacement as xs:string) as xs:string
 *
 *fn:replace($input       as xs:string?,
 *           $pattern     as xs:string,
 *           $replacement as xs:string,
 *           $flags       as xs:string) as xs:string
 *_______________________________________________________________________*/
 /*begin class FnReplaceIterator*/
store::Item_t
FnReplaceIterator::nextImpl(PlanState& planState) const
{
#ifndef ZORBA_NO_UNICODE
  xqp_string input, pattern, replacement, flags;
  xqp_string res;
  store::Item_t item;
  bool tmp;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChildren[0].getp(), planState);
  if( item != NULL )
    input = item->getStringValue().getp();

  item = consumeNext(theChildren[1].getp(), planState);
  assert (item != NULL);
  pattern = item->getStringValue().getp();

  item = consumeNext(theChildren[2].getp(), planState);
  assert (item != NULL);
  replacement = item->getStringValue().getp();

  if(theChildren.size() == 4) {
    item = consumeNext(theChildren[3].getp(), planState);
    assert (item != NULL);
    flags = item->getStringValue().getp();
  }

  try {
    tmp = xqp_string().matches(pattern, flags);
  }
  catch(zorbatypesException& ex){
    ZORBA_ERROR_LOC_DESC(error::DecodeZorbatypesError(ex.ErrorCode()), loc, "");
  }
  
  if(tmp)
    ZORBA_ERROR_LOC_DESC(ZorbaError::FORX0003, loc,
                         "Regular expression matches zero-length string.");

  try{
    res = input.replace(pattern, replacement, flags);
  }
  catch(zorbatypesException& ex){
    ZORBA_ERROR_LOC_DESC(error::DecodeZorbatypesError(ex.ErrorCode()), loc, "");
  }
  
  STACK_PUSH(GENV_ITEMFACTORY->createString(res.getStore ()), state);
  
  STACK_END (state);
#else
  ZORBA_ERROR(ZorbaError::FORX0002);///invalid regular expression (no reg exp supported)
  return NULL;
#endif
}
/*end class FnReplaceIterator*/

/**
 *______________________________________________________________________
 *
 *  7.6.4 fn:tokenize
 *
 *fn:tokenize($input    as xs:string?,
 *            $pattern  as xs:string) as xs:string*
 *
 *fn:tokenize($input    as xs:string?,
 *            $pattern  as xs:string,
 *            $flags    as xs:string) as xs:string*
 *_______________________________________________________________________*/
 /*begin class FnTokenizeIterator*/
void
FnTokenizeIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}

void
FnTokenizeIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theString = xqp_string();
  thePattern = xqp_string();
  theFlags = xqp_string();
}

store::Item_t
FnTokenizeIterator::nextImpl(PlanState& planState) const
{
#ifndef ZORBA_NO_UNICODE
  xqp_string remaining;
  xqp_string token;
  store::Item_t item;
  bool tmp;
  
  
  FnTokenizeIteratorState* state;
  DEFAULT_STACK_INIT(FnTokenizeIteratorState, state, planState);

  item = consumeNext(theChildren[0].getp(), planState);
  if( item != NULL )
    state->theString = item->getStringValue().getp();

  item = consumeNext(theChildren[1].getp(), planState);
  assert (item != NULL);
  state->thePattern = item->getStringValue().getp();

  if(theChildren.size() == 3) {
    item = consumeNext(theChildren[2].getp(), planState);
    assert (item != NULL);
    state->theFlags = item->getStringValue().getp();
  }

  try{
    tmp = xqp_string().matches(state->thePattern, state->theFlags);
  }
  catch(zorbatypesException& ex){
    ZORBA_ERROR_LOC_DESC(error::DecodeZorbatypesError(ex.ErrorCode()), loc, "");
  }
  
  if(tmp)
    ZORBA_ERROR_LOC_DESC(ZorbaError::FORX0003, loc,
                         "Regular expression matches zero-length string.");

  while (! state->theString.empty ()) {
    try{
      token = state->theString.tokenize(state->thePattern, state->theFlags, &remaining);
    }
    catch(zorbatypesException& ex){
      ZORBA_ERROR_LOC_DESC(error::DecodeZorbatypesError(ex.ErrorCode()), loc, "");
    }
    
    assert (remaining.length () < state->theString.length ());
    state->theString = remaining;
    STACK_PUSH(GENV_ITEMFACTORY->createString(token.getStore()), state);
  }

  STACK_END(state);
#else
  ZORBA_ERROR(ZorbaError::FORX0002);///invalid regular expression (no reg exp supported)
  return NULL;
#endif
}
/*end class FnTokenizeIterator*/
} /* namespace zorba */

