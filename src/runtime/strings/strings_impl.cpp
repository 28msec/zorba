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
#include <iostream>

#include "common/common.h"

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_messages.h"

#include "zorbatypes/zorbatypesError.h"
#include "zorbatypes/numconversions.h"

#include "system/globalenv.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/strings/strings.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "zorbautils/string_util.h"

#include "util/utf8_util.h"
#include "util/utf8_string.h"
#include "util/string_util.h"


using namespace std;

namespace zorba {


/**
  *______________________________________________________________________
  *
  *  7.2.1 fn:codepoints-to-string
  *
  *  fn:codepoints-to-string($arg as xs:integer*) as xs:string
  *_______________________________________________________________________*/
bool
CodepointsToStringIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t item;
  zstring resStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while(true)
  {
    if (consumeNext(item, theChildren [0].getp(), planState ))
    {
      {
        zstring lUtf8Code = item->getIntegerValue().toString();
        xs_uint lCode;
        if (NumConversions::strToUInt(lUtf8Code.c_str(), lCode)) 
        {
          try
          {
            utf8::encode( lCode, &resStr );
          }
          catch(zorbatypesException& ex)
          {
            ZORBA_ERROR_LOC_DESC(error::DecodeZorbatypesError(ex.ErrorCode()),
                                 loc, lUtf8Code);
          }
        }
        else
        {
          ZORBA_ERROR_LOC_DESC(FOCH0001, loc, lUtf8Code);
        }
      }
    }
    else
    {
      STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state );
      break;
    }
  }
  STACK_END (state);
}

/**
 *______________________________________________________________________
 *
 *  7.2.2 fn:string-to-codepoints
 *
 *  fn:string-to-codepoints($arg as xs:string?) as xs:integer*
 *_______________________________________________________________________
 */
bool StringToCodepointsIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const 
{
  // TODO Optimization for large strings: large strings mean that a large
  // integer vector should be stored in the state that is not good.
  store::Item_t item;
  zstring inputStr;

  StringToCodepointsIteratorState* state;
  DEFAULT_STACK_INIT(StringToCodepointsIteratorState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState )) 
  {
    item->getStringValue2(inputStr);

    if (!inputStr.empty())
    {
      utf8::to_codepoints(inputStr, &state->theResult);
  
      while (state->theIterator < state->theResult.size())
      {
        GENV_ITEMFACTORY->createInteger( 
          result,
          Integer::parseInt(state->theResult[state->theIterator]) 
        );

        STACK_PUSH(true, state );
        state->theIterator = state->theIterator + 1;
      }
    }
  }
  STACK_END (state);
}


void StringToCodepointsIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theIterator = 0;
  theResult.clear();
}


void StringToCodepointsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theIterator = 0;
  theResult.clear();
}


/**
  *______________________________________________________________________
  *
  *  7.3.2 fn:compare
  *
  * fn:compare($comparand1 as xs:string?,
  *            $comparand2 as xs:string?) as xs:integer
  * fn:compare($comparand1 as xs:string?,
  *            $comparand2 as xs:string?,
  *            $collation  as xs:string) as xs:integer?
  *_______________________________________________________________________*/
bool CompareStrIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const 
{
  store::Item_t n0;
  store::Item_t n1;
  store::Item_t n2;
  int res;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(n0, theChildren[0].getp(), planState )) 
  {
    if (consumeNext(n1, theChildren[1].getp(), planState ))
    {
      XQPCollator* coll;

      if (theChildren.size() == 3)
      {
        consumeNext(n2, theChildren[2].getp(), planState);

        coll = theSctx->get_collator(n2->getStringValue().str(), loc);
      }
      else
      {
        coll = theSctx->get_default_collator(loc);
      }

      res = utf8::compare(n0->getStringValue(), n1->getStringValue(), coll);

      GENV_ITEMFACTORY->createInteger(result, Integer::parseInt(res));

      STACK_PUSH(true, state);
    }
  }

  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.3.3 fn:codepoint-equal
  *
  *  fn:codepoint-equal($comparand1 as xs:string?,
  *                     $comparand2 as xs:string?) as xs:boolean?
  *_______________________________________________________________________*/
bool CodepointEqualIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const 
{
  store::Item_t item0;
  store::Item_t item1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item0, theChildren [0].getp(), planState )) 
  {
    if (consumeNext(item1, theChildren [1].getp(), planState )) 
    {
      GENV_ITEMFACTORY->createBoolean(result,
                                      item0->getStringValue() == item1->getStringValue());
      STACK_PUSH(true, state);
    }
  }
  STACK_END(state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.1 fn:concat
  *
  * fn:concat($arg1 as xs:anyAtomicType?,
  *           $arg2    as xs:anyAtomicType?,
  *           ...                          ) as xs:string
  *_______________________________________________________________________*/
bool ConcatStrIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const 
{
  store::Item_t lItem;
  std::stringstream lResStream;
  zstring tmp;

  checked_vector<PlanIter_t>::const_iterator iter = theChildren.begin();
  checked_vector<PlanIter_t>::const_iterator end  = theChildren.end();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  for(; iter != end;  ++iter )
  {
    if (consumeNext(lItem, *iter, planState))
    {
      lResStream << lItem->getStringValue();

      if (consumeNext(lItem, *iter, planState))
      {
        ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
          "A sequence with more than one item is not allowed as argument to fn:concat");
        break;
      }
    }
  }

  tmp = lResStream.str();
  STACK_PUSH(GENV_ITEMFACTORY->createString(result, tmp), state);

  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.2 fn:string-join
  *
  * fn:string-join($arg1 as xs:string*,
  *                $arg2 as xs:string) as xs:string
  *_______________________________________________________________________*/
bool StringJoinIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  zstring resStr;
  zstring separator;
  bool lFirst;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(item, theChildren[1].getp(), planState);

  item->getStringValue2(separator);

  if (separator.empty())
  {
    while(true)
    {
      if (consumeNext(item, theChildren[0].getp(), planState))
      {
        item->appendStringValue(resStr);
      }
      else
      {
        GENV_ITEMFACTORY->createString(result, resStr);
        STACK_PUSH(true, state);
        break;
      }
    }
  }
  else
  {
    lFirst = true;

    while(true)
    {
      if (consumeNext(item, theChildren[0].getp(), planState))
      {
        if (!lFirst)
        {
          resStr += separator;
          item->appendStringValue(resStr);
        }
        else
        {
          item->getStringValue2(resStr);
          lFirst = false;
        }
      }
      else
      {
        GENV_ITEMFACTORY->createString(result, resStr);
        STACK_PUSH(true, state);
        break;
      }
    }
  }

  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.3 fn:substring
  *
  *fn:substring($sourceString   as xs:string?,
  *             $startingLoc    as xs:double) as xs:string
  *fn:substring($sourceString as xs:string?,
  *             $startingLoc  as xs:double,
  *             $length       as xs:double)   as xs:string
  *_______________________________________________________________________*/
bool SubstringIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t stringItem;
  store::Item_t startItem;
  store::Item_t lenItem;
  zstring strval;
  zstring resStr;
  xs_double start;
  xs_double len;
  xs_int istart;
  xs_int ilen;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(stringItem, theChildren[0].getp(), planState ))
  {
    stringItem->getStringValue2(strval);

    if (!strval.empty())
    {
      bool startExists = consumeNext(startItem, theChildren[1], planState);

      ZORBA_ASSERT(startExists);

      // note: The first character of a string is located at position 1,
      // not position 0.

      start = startItem->getDoubleValue();

      if (!start.isNaN())
      {
        if (start.isFinite())
        {
          xs_int lInt;
          if (NumConversions::doubleToInt(start.round(), lInt))
          {
            istart = lInt;
          }
          else
          {
            istart = utf8_string<zstring>(strval).length();
          }
        }
        else
        {
          istart = utf8_string<zstring>(strval).length();
        }

        if( theChildren.size() == 2)
        {
          if (istart <= 0)
          {
            resStr = strval;
          }
          else
          {
            try
            {
              resStr = utf8_string<zstring>(strval).substr(istart-1);
            }
            catch (...)
            {
              zstring::size_type numChars = utf8_string<zstring>(strval).length();
              if (static_cast<zstring::size_type>(istart) > numChars)
              {
                // result is the empty string
              }
              else
              {
                throw;
              }
            }
          }
        }
        else
        {
          bool lenItemExists = consumeNext(lenItem, theChildren[2], planState);

          ZORBA_ASSERT(lenItemExists);
          
          len = lenItem->getDoubleValue();

          if (!len.isNaN())
          {
            if (len.isFinite())
            {
              xs_int lInt;
              if (NumConversions::doubleToInt(len.round(), lInt))
              {
                ilen = lInt;
              }
              else
              {
                ilen = utf8_string<zstring>(strval).length() - istart + 1;
              }
            }
            else
            {
              ilen = utf8_string<zstring>(strval).length() - istart + 1;
            }
    
            if( !(start + len).isNaN())
            {
              if (ilen >= 0)
              {
                if (istart <= 0)
                {
                  if ((ilen + istart - 1) >= 0)
                    resStr = utf8_string<zstring>(strval).substr(0,  istart - 1 + ilen);
                }
                else
                {
                  try
                  {
                    resStr = utf8_string<zstring>(strval).substr(istart-1, ilen);
                  }
                  catch (...)
                  {
                    zstring::size_type numChars = utf8_string<zstring>(strval).length();
                    if (static_cast<zstring::size_type>(istart) > numChars)
                    {
                      // result is the empty string
                    }
                    else
                    {
                      throw;
                    }
                  }
                }
              }
            }
          }
        }
      } // non NaN start arg
    } // non empty string arg
  } // non NULL string arg

  STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);

  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.4 fn:string-length
  *
  *fn:string-length()                   as xs:integer
  *fn:string-length($arg as xs:string?) as xs:integer
  *_______________________________________________________________________*/
bool StringLengthIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  zstring strval;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState))
  {
    item->getStringValue2(strval);

    STACK_PUSH(GENV_ITEMFACTORY->createInteger(
                            result,
                            Integer::parseSizeT(utf8_string<zstring>(strval).length())),
               state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, Integer::parseInt(0)),
               state);
  }
  STACK_END(state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.5 fn:normalize-space
  *
  *fn:normalize-space()                   as xs:string
  *fn:normalize-space($arg as xs:string?) as xs:string
  *_______________________________________________________________________*/
bool NormalizeSpaceIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t item;
  zstring resStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState))
  {
    item->getStringValue2(resStr);
    ascii::normalize_whitespace(resStr);
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.6 fn:normalize-unicode
  *
  *fn:normalize-unicode($arg as xs:string?)              as xs:string
  *fn:normalize-unicode($arg as xs:string?,
  *                     $normalizationForm as xs:string) as xs:string
  *_______________________________________________________________________*/
bool NormalizeUnicodeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;
  zstring normForm;
  zstring resStr;
  unicode::normalization::type normType;
  bool success;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item0, theChildren[0], planState ))
  {
    if(theChildren.size() == 2)
    {
      if (!consumeNext(item1, theChildren[1].getp(), planState ))
        ZORBA_ASSERT(false);

      item1->getStringValue2(normForm);
      ascii::trim_whitespace(normForm);
      zstring tmp(normForm);
      utf8::to_upper(tmp, &normForm);
    }
    else
    {
      normForm = "NFC";
    }

    if(normForm.empty())
    {
      normType = unicode::normalization::none;
    }
    else if (equals(normForm, "NFC", 3))
    {
      normType = unicode::normalization::NFC;
    }
    else if (equals(normForm, "NFKC", 4))
    {
      normType = unicode::normalization::NFKC;
    }
    else if (equals(normForm, "NFD", 3))
    {
      normType = unicode::normalization::NFD;
    }
    else if (equals(normForm, "NFKD", 4))
    {
      normType = unicode::normalization::NFKD;
    }
    else
    {
      ZORBA_ERROR_LOC_DESC_OSS(FOCH0003, loc,
                               "Unsupported normalization form : " << normForm);
    }

    item0->getStringValue2(resStr);
#ifndef ZORBA_NO_UNICODE
    success = utf8::normalize(resStr, normType, &resStr);
    ZORBA_ASSERT(success);
#endif//#ifndef ZORBA_NO_UNICODE
    STACK_PUSH( GENV_ITEMFACTORY->createString(result, resStr), state );
  }
  else
  {
    // must push empty string due to return type of function
    STACK_PUSH( GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.7 fn:upper-case
  *
  *fn:upper-case($arg as xs:string?) as xs:string
  *_______________________________________________________________________*/
bool UpperCaseIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  zstring resStr;
  zstring strval;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState))
  {
    item->getStringValue2(strval);

    utf8::to_upper(strval, &resStr);

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.8 fn:lower-case
  *
  *fn:lower-case($arg as xs:string?) as xs:string
  *_______________________________________________________________________*/
bool LowerCaseIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const 
{
  store::Item_t item;
  zstring resStr;
  zstring strval;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState))
  {
    item->getStringValue2(strval);

    utf8::to_lower(strval, &resStr);

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.9 fn:translate
  *
  *fn:translate($arg          as xs:string?,
  *             $mapString    as xs:string,
  *             $transString  as xs:string) as xs:string
  *_______________________________________________________________________*/
bool TranslateIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t arg_item, map_item, trans_item;
  bool res = false;
  zstring arg_string;
  zstring map_string;
  zstring trans_string;
  zstring result_string;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ( consumeNext( arg_item  , theChildren[0].getp(), planState ) &&
       consumeNext( map_item  , theChildren[1].getp(), planState ) &&
       consumeNext( trans_item, theChildren[2].getp(), planState ) ) {

    arg_string   = arg_item  ->getStringValue().str();
    map_string   = map_item  ->getStringValue().str();
    trans_string = trans_item->getStringValue().str();

    typedef std::map<unicode::code_point,unicode::code_point> cp_map_type;
    cp_map_type trans_map;

    if ( !map_string.empty() ) {
      utf8_string<zstring const> const u_map_string  ( map_string   );
      utf8_string<zstring const> const u_trans_string( trans_string );

      utf8_string<zstring const>::const_iterator
        map_i     = u_map_string  .begin(),
        map_end   = u_map_string  .end  (),
        trans_i   = u_trans_string.begin(),
        trans_end = u_trans_string.end  ();

      for ( ; map_i != map_end && trans_i != trans_end; ++map_i, ++trans_i )
        trans_map[ *map_i ] = *trans_i;

      for ( ; map_i != map_end; ++map_i )
        trans_map[ *map_i ] = ~0;
    }

    utf8_string<zstring> u_result_string( result_string );
    utf8_string<zstring const> const u_arg_string( arg_string );

    utf8_string<zstring const>::const_iterator
      arg_i   = u_arg_string.begin(),
      arg_end = u_arg_string.end  ();

    for ( ; arg_i != arg_end; ++arg_i ) {
      unicode::code_point cp = *arg_i;
      cp_map_type::const_iterator const found_i = trans_map.find( cp );
      if ( found_i != trans_map.end() ) {
        cp = found_i->second;
        if ( cp == ~0 )
          continue;
      }
      u_result_string += cp;
    }

    res = GENV_ITEMFACTORY->createString(result, result_string);
  }
  
  if (!res)
  {
    res = GENV_ITEMFACTORY->createString(result, result_string);
  }

  STACK_PUSH( res, state );
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.10 fn:encode-for-uri
  *
  *fn:encode-for-uri($uri-part as xs:string?) as xs:string
  *_______________________________________________________________________*/
bool EncodeForUriIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const 
{
  store::Item_t item;
  zstring resStr;
  zstring strval;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState)) 
  {
    item->getStringValue2(strval);
    ascii::uri_encode(strval, &resStr, true);
  }

  STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.11 fn:iri-to-uri
  *
  *fn:iri-to-uri($iri as xs:string?) as xs:string
  *_______________________________________________________________________*/
bool IriToUriIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const 
{
  store::Item_t item;
  zstring resStr;
  zstring strval;
  xqpStringStore_t tmp;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState))
  {
    item->getStringValue2(strval);

    tmp = new xqpStringStore(strval.str());

    resStr = tmp->iriToUri()->str();

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.4.12 fn:escape-html-uri
  *
  *fn:escape-html-uri($uri as xs:string?) as xs:string
  *_______________________________________________________________________*/
bool EscapeHtmlUriIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const 
{
  store::Item_t item;
  zstring resStr;
  zstring strval;
  xqpStringStore_t tmp;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState))
  {
    item->getStringValue2(strval);

    tmp = new xqpStringStore(strval.str());

    resStr = tmp->escapeHtmlUri()->str();

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  }
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.5.1 fn:contains
  *
  *fn:contains( $arg1       as xs:string?,
  *             $arg2       as xs:string?) as xs:boolean
  *fn:contains( $arg1       as xs:string?,
  *             $arg2       as xs:string?,
  *             $collation  as xs:string) as xs:boolean
  *_______________________________________________________________________*/
bool ContainsIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const 
{
  store::Item_t item0;
  store::Item_t item1;
  store::Item_t itemColl;
  bool resBool = false;
  zstring arg1;
  zstring arg2;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item0, theChildren[0].getp(), planState ))
  {
    item0->getStringValue2(arg1);
  }

  if (consumeNext(item1, theChildren[1].getp(), planState ))
  {
    item1->getStringValue2(arg2);
  }
    
  if (arg2.empty())
  {
    STACK_PUSH( GENV_ITEMFACTORY->createBoolean(result, true), state );
  }
  else if (arg1.empty())
  {
    STACK_PUSH( GENV_ITEMFACTORY->createBoolean(result, false), state );
  }
  else
  {
    if (theChildren.size() == 2)
    {
      resBool = (arg1.find(arg2) != zstring::npos);
    }
    else
    {
      if (consumeNext(itemColl, theChildren[2].getp(), planState ))
      {
        XQPCollator* coll = theSctx->get_collator(itemColl->getStringValue().str(), loc);
        resBool = (zorba::find(arg1, arg2, coll) != zstring::npos);
      }
    }
    STACK_PUSH( GENV_ITEMFACTORY->createBoolean(result, resBool), state );
  }
  
  STACK_END (state);
}
/*end class ContainsIterator*/

/**
  *______________________________________________________________________
  *
  *  7.5.2 fn:starts-with
  *
  *fn:starts-with($arg1       as xs:string?,
  *               $arg2       as xs:string?) as xs:boolean
  *fn:starts-with($arg1       as xs:string?,
  *               $arg2       as xs:string?,
  *               $collation  as xs:string) as xs:boolean
  *_______________________________________________________________________*/
bool StartsWithIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const 
{
  store::Item_t item0;
  store::Item_t item1;
  store::Item_t itemColl;
  bool resBool = false;
  zstring arg1;
  zstring arg2;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size() == 2 || theChildren.size()==3)
  {
    if (consumeNext(item0, theChildren[0].getp(), planState ))
    {
      item0->getStringValue2(arg1);
    }

    if (consumeNext(item1, theChildren[1].getp(), planState ))
    {
      item1->getStringValue2(arg2);
    }

    if (arg2.empty())
    {
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(result, true), state );
    }
    else if (arg1.empty())
    {
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(result, false), state );
    }
    else
    {
      if (theChildren.size() == 2)
      {
        resBool = (arg1.find(arg2) == 0);
      }
      else
      {
        if (consumeNext(itemColl, theChildren[2].getp(), planState ))
        {
          XQPCollator* coll = theSctx->get_collator(itemColl->getStringValue().str(), loc);
          resBool = (zorba::find(arg1, arg2, coll) == 0);
        }
      }
      STACK_PUSH( GENV_ITEMFACTORY->createBoolean(result, resBool), state );
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
  *fn:ends-with($arg1       as xs:string?,
  *             $arg2       as xs:string?)  as xs:boolean
  *fn:ends-with($arg1       as xs:string?,
  *             $arg2       as xs:string?,
  *             $collation  as xs:string)   as xs:boolean
  *_______________________________________________________________________*/
bool EndsWithIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const 
{
  store::Item_t item0;
  store::Item_t item1;
  store::Item_t itemColl;
  bool resBool = false;
  zstring arg1;
  zstring arg2;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item0, theChildren[0].getp(), planState ))
  {
    item0->getStringValue2(arg1);
  }
  
  if (consumeNext(item1, theChildren[1].getp(), planState ))
  {
    item1->getStringValue2(arg2);
  }

  if (arg2.empty())
  {
    STACK_PUSH( GENV_ITEMFACTORY->createBoolean(result, true), state );
  }
  else if (arg1.empty())
  {
    STACK_PUSH( GENV_ITEMFACTORY->createBoolean(result, false), state );
  }
  else
  {
    if (theChildren.size() == 2)
    {
      resBool = utf8::ends_with(arg1, arg2);
    }
    else
    {
      if (consumeNext(itemColl, theChildren[2].getp(), planState ))
      {
        XQPCollator* coll = theSctx->get_collator(itemColl->getStringValue().str(), loc);

        resBool = zorba::ends_with(arg1, arg2, coll);
      }
    }
    STACK_PUSH( GENV_ITEMFACTORY->createBoolean(result, resBool), state );
  }
  
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.5.4 fn:substring-before
  *
  *fn:substring-before( $arg1       as xs:string?,
  *                     $arg2       as xs:string?)  as xs:string
  *fn:substring-before( $arg1       as xs:string?,
  *                     $arg2       as xs:string?,
  *                     $collation  as xs:string)   as xs:string
  *_______________________________________________________________________*/
bool SubstringBeforeIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const 
{
  store::Item_t item0;
  store::Item_t item1;
  store::Item_t itemColl;
  ulong index = zstring::npos;
  zstring arg1;
  zstring arg2;
  zstring resStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() == 2 || theChildren.size()==3)
  {
    if (consumeNext(item0, theChildren[0].getp(), planState ))
    {
      item0->getStringValue2(arg1);
    }

    if (consumeNext(item1, theChildren[1].getp(), planState ))
    {
      item1->getStringValue2(arg2);
    }

    if (arg1.empty() || arg2.empty())
    {
      STACK_PUSH( GENV_ITEMFACTORY->createString(result, resStr), state );
    }
    else
    {
      if (theChildren.size() == 2)
      {
        index = arg1.find(arg2);
      }
      else
      {
        if (consumeNext(itemColl, theChildren[2].getp(), planState ))
        {
          XQPCollator* coll = 0;
          coll = theSctx->get_collator(itemColl->getStringValue().str(), loc);
          index = zorba::find(arg1, arg2, coll);
        }
      }

      if (index != zstring::npos)
        resStr = arg1.substr(0, index);

      STACK_PUSH( GENV_ITEMFACTORY->createString(result, resStr), state );
    }
  }
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.5.5 fn:substring-after
  *
  *fn:substring-after($arg1       as xs:string?,
  *                   $arg2       as xs:string?)  as xs:string
  *fn:substring-after($arg1       as xs:string?,
  *                   $arg2       as xs:string?,
  *                   $collation  as xs:string)   as xs:string
  *_______________________________________________________________________*/
bool SubstringAfterIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const 
{
  store::Item_t item0;
  store::Item_t item1;
  store::Item_t itemColl;
  ulong startPos = zstring::npos;
  zstring arg1;
  zstring arg2;
  zstring resStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size() == 2 || theChildren.size() == 3)
  {
    if (consumeNext(item0, theChildren[0].getp(), planState ))
    {
      item0->getStringValue2(arg1);
    }

    if (consumeNext(item1, theChildren[1].getp(), planState ))
    {
      item1->getStringValue2(arg2);
    }

    if (arg1.empty())
    {
      STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
    }
    else if (arg2.empty())
    {
      resStr = arg1;
      STACK_PUSH( GENV_ITEMFACTORY->createString(result, resStr), state );
    }
    else
    {
      if (theChildren.size() == 2)
      {
        startPos = arg1.find(arg2);
      }
      else
      {
        if (consumeNext(itemColl, theChildren[2].getp(), planState))
        {
          XQPCollator* coll = theSctx->get_collator(itemColl->getStringValue().str(), loc);
          startPos = zorba::find(arg1, arg2, coll);
        }
      }

      if (startPos != zstring::npos)
      {
        startPos += arg2.size();
        resStr = arg1.substr(startPos, arg1.size() - startPos);
      }

      STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
    }
  }
  STACK_END (state);
}


/**
  *______________________________________________________________________
  *
  *  7.6.2 fn:matches
  *
  *fn:matches($input   as xs:string?,
  *           $pattern as xs:string) as xs:boolean
  *fn:matches($input   as xs:string?,
  *           $pattern as xs:string,
  *           $flags   as xs:string) as xs:boolean
  *_______________________________________________________________________*/
bool FnMatchesIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  zstring input;
  zstring pattern;
  zstring flags;
  store::Item_t item;
  bool res = false;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
    item->getStringValue2(input);

  if (!consumeNext(item, theChildren[1].getp(), planState))
    ZORBA_ASSERT (false);

  item->getStringValue2(pattern);

  if(theChildren.size() == 3) 
  {
    if (!consumeNext(item, theChildren[2].getp(), planState))
      ZORBA_ASSERT (false);

    item->getStringValue2(flags);
  }

  try 
  {
    res = zorba::match_part(input, pattern, flags.c_str());
  }
  catch(zorbatypesException& ex) 
  {
    ZORBA_ERROR_LOC_PARAM(error::DecodeZorbatypesError(ex.ErrorCode()),
                          loc, ex.what(), "");
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, res), state); 
  
  STACK_END(state);
}


/**
  *______________________________________________________________________
  *
  *  7.6.3 fn:replace
  *
  *fn:replace($input       as xs:string?,
  *           $pattern     as xs:string,
  *           $replacement as xs:string) as xs:string
  *fn:replace($input       as xs:string?,
  *           $pattern     as xs:string,
  *           $replacement as xs:string,
  *           $flags       as xs:string) as xs:string
  *_______________________________________________________________________*/
bool FnReplaceIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  zstring input;
  zstring flags;
  zstring pattern;
  zstring replacement;
  zstring resStr;
  store::Item_t item;
  bool tmp;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
    item->getStringValue2(input);

  if (!consumeNext(item, theChildren[1].getp(), planState))
    ZORBA_ASSERT (false);

  item->getStringValue2(pattern);

  if (!consumeNext(item, theChildren[2].getp(), planState))
    ZORBA_ASSERT (false);

  item->getStringValue2(replacement);

  if(theChildren.size() == 4) 
  {
    if (!consumeNext(item, theChildren[3].getp(), planState))
      ZORBA_ASSERT (false);

    item->getStringValue2(flags);
  }

  try 
  {
    tmp = zorba::match_part(zstring(), pattern, flags.c_str());
  }
  catch(zorbatypesException& ex) 
  {
    ZORBA_ERROR_LOC_PARAM(error::DecodeZorbatypesError(ex.ErrorCode()),
                          loc, ex.what(), "");
  }
  
  if (tmp)
    ZORBA_ERROR_LOC_DESC(FORX0003, loc,
                         "Regular expression matches zero-length string.");

  try 
  {
    utf8::replace_all(input, pattern, flags.c_str(), replacement, &resStr);
  }
  catch(zorbatypesException& ex) 
  {
    ZORBA_ERROR_LOC_PARAM(error::DecodeZorbatypesError(ex.ErrorCode()),
                          loc, ex.what(), "");
  }
  
  STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
  
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 *  7.6.4 fn:tokenize
 *
 *fn:tokenize($input    as xs:string?,
 *            $pattern  as xs:string) as xs:string*
 *fn:tokenize($input    as xs:string?,
 *            $pattern  as xs:string,
 *            $flags    as xs:string) as xs:string*
 *_______________________________________________________________________
 */
void FnTokenizeIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theString.clear();
  start_pos = 0;
  hasmatched = false;
  thePattern.clear();
  theFlags.clear();
}


bool FnTokenizeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  zstring token;
  store::Item_t item;
  bool tmp;
  zstring strval;
  unicode::string u_string;

  FnTokenizeIteratorState* state;
  DEFAULT_STACK_INIT(FnTokenizeIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    item->getStringValue2(strval);
    state->theString = strval.str();
  }

  if (!consumeNext(item, theChildren[1].getp(), planState))
    ZORBA_ASSERT(false);

  item->getStringValue2(strval);
  state->thePattern = strval.str();

  if(theChildren.size() == 3) 
  {
    if (!consumeNext(item, theChildren[2].getp(), planState))
      ZORBA_ASSERT (false);

    item->getStringValue2(strval);

    state->theFlags = strval.str();
  }

  try
  {
    static zstring const empty;
    tmp = match_part( empty, state->thePattern, state->theFlags );
  }
  catch(zorbatypesException& ex)
  {
    ZORBA_ERROR_LOC_PARAM(error::DecodeZorbatypesError(ex.ErrorCode()),
                          loc, ex.what(), "");
  }

  if(tmp)
    ZORBA_ERROR_LOC_DESC(FORX0003, loc,
                         "Regular expression matches zero-length string.");


  while ((xs_uint)state->start_pos < state->theString.length ())
  {
    try 
    {
      unicode::regex re;
      //
      // The RE needs to be compiled every time due to the weird stack macros.
      //
      if ( !re.compile( state->thePattern, state->theFlags ) )
        throw zorbatypesException(
          state->thePattern, ZorbatypesError::FORX0002
        );
      unicode::string u_token;
      bool const got_next = re.next_token(
        state->theString, &state->start_pos, &u_token, &state->hasmatched
      );
      utf8::to_string( u_token, &token );
      if ( !got_next )
        break;
    }
    catch(zorbatypesException& ex) 
    {
      ZORBA_ERROR_LOC_PARAM(error::DecodeZorbatypesError(ex.ErrorCode()),
                            loc, ex.what(), "");
    }

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, token), state);
  }

  if(state->hasmatched)
  {
    //the last token is empty (is after the last match)
    token.clear();
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, token), state);
  }
  STACK_END(state);
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
