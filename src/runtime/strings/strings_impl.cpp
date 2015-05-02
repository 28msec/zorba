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
#include "stdafx.h"

#include <iostream>
#include <sstream>

#include "common/common.h"

#include "zorbamisc/ns_consts.h"
#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "zorbatypes/integer.h"
#include "zorbatypes/numconversions.h"

#include "system/globalenv.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/strings/strings.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "zorbautils/string_util.h"

#include "util/ascii_util.h"
#include "util/oseparator.h"
#include "util/regex.h"
#include "util/string_util.h"
#include "util/uri_util.h"
#include "util/utf8_string.h"
#include "util/utf8_util.h"
#include "util/xml_util.h"


using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

static int count_capturing_groups( zstring const &regex ) {
  bool got_backslash = false;
  int n = 0;
  FOR_EACH( zstring, c, regex ) {
    if ( got_backslash )
      got_backslash = false;
    else
      switch ( *c ) {
        case '\\':
          got_backslash = true;
          break;
        case '(':
          if ( ztd::peek( regex, c ) != '?' )
            ++n;
          break;
      } // switch
  } // for
  return n;
}

///////////////////////////////////////////////////////////////////////////////

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
        try
        {
          xs_unsignedInt lCode = ztd::aton<xs_unsignedInt>(lUtf8Code.c_str());
          if (!xml::is_valid(lCode))
            throw std::invalid_argument( lUtf8Code.str() );
          utf8::encode( lCode, &resStr );
        }
        catch ( std::exception const& )
        {
          throw XQUERY_EXCEPTION(
            err::FOCH0001, ERROR_PARAMS( lUtf8Code ), ERROR_LOC( loc )
          );
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
    if(!item->isStreamable())
    {
      item->getStringValue2(inputStr);
    }
    else
    {
      state->theStreamItem = item;
      state->theStream = &item->getStream();
    }
  }

  if ( state->theStream )
  {
    while ( true )
    {
      utf8::encoded_char_type ec;
      memset( ec, 0, sizeof( ec ) );

      try {
        if ( !utf8::read( *state->theStream, ec ) ) {
          if ( !state->theStream->eof() && !state->theStream->good() )
            throw XQUERY_EXCEPTION(
              zerr::ZOSE0003_STREAM_READ_FAILURE, ERROR_LOC( loc )
            );
          break;
        }
      }
      catch ( utf8::invalid_byte const& ) {
        ostringstream oss;
        oseparator comma( ',' );
        for ( utf8::storage_type const *c = ec; *c; ++c )
          oss << comma << ascii::printable_char( *c );
        throw XQUERY_EXCEPTION(
          zerr::ZXQD0006_INVALID_UTF8_BYTE_SEQUENCE,
          ERROR_PARAMS( oss.str() ),
          ERROR_LOC( loc )
        );
      }
      GENV_ITEMFACTORY->createInteger(
        result, xs_integer( utf8::decode( ec ) )
      );
      STACK_PUSH( true, state );
      ++(state->theIterator);
    }
  }
  else if (!inputStr.empty())
  {
    utf8::to_codepoints(inputStr, &state->theResult);

    while (state->theIterator < state->theResult.size())
    {
      GENV_ITEMFACTORY->createInteger(
        result,
        xs_integer(state->theResult[state->theIterator])
      );

      STACK_PUSH(true, state );
      state->theIterator = state->theIterator + 1;
    }
  }
  STACK_END (state);
}


void StringToCodepointsIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theIterator = 0;
  theStream   = 0;
  theResult.clear();
}


void StringToCodepointsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theIterator = 0;
  theResult.clear();
  theStreamItem = 0;
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

      res  = utf8::compare(n0->getStringValue(), n1->getStringValue(), coll);

      res = (res < 0 ? -1 : (res > 0 ? 1 : 0));

      GENV_ITEMFACTORY->createInteger(result, xs_integer(res));

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

  for (; iter != end;  ++iter)
  {
    if (consumeNext(lItem, *iter, planState))
    {
      lResStream << lItem->getStringValue();

      if (consumeNext(lItem, *iter, planState))
      {
        RAISE_ERROR(err::XPTY0004, loc, ERROR_PARAMS(ZED(NoSeqForConcat)));
      }
    }
  }

  tmp = lResStream.str();
  STACK_PUSH(GENV_ITEMFACTORY->createString(result, tmp), state);

  STACK_END(state);
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

  if(theChildren.size() > 1)
  {
    consumeNext(item, theChildren[1].getp(), planState);
    item->getStringValue2(separator);
  }

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
          try
          {
            istart = to_xs_int(start.round());
          }
          catch ( std::range_error const& )
          {
            throw XQUERY_EXCEPTION(
              zerr::ZXQD0004_INVALID_PARAMETER,
              ERROR_PARAMS(ZED(ZXQD0004_NOT_WITHIN_RANGE),
                          start),
              ERROR_LOC( loc )
            );
          }
        }
        else
        {
          istart = (xs_int)utf8_string<zstring>(strval).length();
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
              try
              {
                ilen = to_xs_int(len.round());
              }
              catch ( std::range_error const& )
              {
                throw XQUERY_EXCEPTION(
                  zerr::ZXQD0004_INVALID_PARAMETER,
                  ERROR_PARAMS(ZED(ZXQD0004_NOT_WITHIN_RANGE),
                              len),
                  ERROR_LOC( loc )
                );
              }
            }
            else
            {
              ilen = (xs_int)(utf8_string<zstring>(strval).length() - istart + 1);
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
  *  7.4.3.1  fn:substring optimized for int arguments
  *
  *fn:substring($sourceString   as xs:string?,
  *             $startingLoc    as xs:integer) as xs:string
  *fn:substring($sourceString as xs:string?,
  *             $startingLoc  as xs:integer,
  *             $length       as xs:integer)   as xs:string
  *_______________________________________________________________________*/
bool SubstringIntOptIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t stringItem;
  store::Item_t startItem;
  store::Item_t lenItem;
  zstring strval;
  zstring resStr;
  xs_int start;
  xs_int len;

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

      try
      {
        start = to_xs_int(startItem->getIntegerValue());
      }
      catch ( std::range_error const& )
      {
        throw XQUERY_EXCEPTION(
          zerr::ZXQD0004_INVALID_PARAMETER,
          ERROR_PARAMS(ZED(ZXQD0004_NOT_WITHIN_RANGE),
                      lenItem->getIntegerValue()),
          ERROR_LOC( loc )
        );
      }

      if( theChildren.size() == 2)
      {
        if (start <= 0)
        {
          resStr = strval;
        }
        else
        {
          try
          {
            resStr = utf8_string<zstring>(strval).substr(start-1);
          }
          catch (...)
          {
            zstring::size_type numChars = utf8_string<zstring>(strval).length();
            if (static_cast<zstring::size_type>(start) > numChars)
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

        try
        {
          len = to_xs_int(lenItem->getIntegerValue());
        }
        catch ( std::range_error const& )
        {
          throw XQUERY_EXCEPTION(
            zerr::ZXQD0004_INVALID_PARAMETER,
            ERROR_PARAMS(ZED(ZXQD0004_NOT_WITHIN_RANGE),
                        lenItem->getIntegerValue()),
            ERROR_LOC( loc )
          );
        }

        if (len >= 0)
        {
          if (start <= 0)
          {
            if ((len + start - 1) >= 0)
              resStr = utf8_string<zstring>(strval).substr(0,  start - 1 + len);
          }
          else
          {
            try
            {
              resStr = utf8_string<zstring>(strval).substr(start-1, len);
            }
            catch (...)
            {
              zstring::size_type numChars = utf8_string<zstring>(strval).length();
              if (static_cast<zstring::size_type>(start) > numChars)
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
    STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, xs_integer(utf8::length(strval))), state);
  }
  else
  {
    STACK_PUSH(
      GENV_ITEMFACTORY->createInteger(
        result, numeric_consts<xs_integer>::zero()
      ),
      state
    );
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
    ascii::normalize_space(resStr);
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
#ifndef ZORBA_NO_ICU
  bool success;
#endif /* ZORBA_NO_ICU */

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item0, theChildren[0], planState ))
  {
    if(theChildren.size() == 2)
    {
      if (!consumeNext(item1, theChildren[1].getp(), planState ))
        ZORBA_ASSERT(false);

      item1->getStringValue2(normForm);
      ascii::trim_space(normForm);
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
    else if (ZSTREQ(normForm, "NFC"))
    {
      normType = unicode::normalization::NFC;
    }
    else if (ZSTREQ(normForm, "NFKC"))
    {
      normType = unicode::normalization::NFKC;
    }
    else if (ZSTREQ(normForm, "NFD"))
    {
      normType = unicode::normalization::NFD;
    }
    else if (ZSTREQ(normForm, "NFKD"))
    {
      normType = unicode::normalization::NFKD;
    }
    else
    {
      throw XQUERY_EXCEPTION(
        err::FOCH0003, ERROR_PARAMS( normForm ), ERROR_LOC( loc )
      );
    }

    item0->getStringValue2(resStr);
#ifndef ZORBA_NO_ICU
    success = utf8::normalize(resStr, normType, &resStr);
    ZORBA_ASSERT(success);
#endif//#ifndef ZORBA_NO_ICU
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state );
  }
  else
  {
    // must push empty string due to return type of function
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resStr), state);
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
        trans_map[ *map_i ] = static_cast<unicode::code_point>( ~0 );
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
        if ( cp == static_cast<unicode::code_point>( ~0 ) )
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
    uri::encode(strval, &resStr, true);
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
  zstring lStrIri;
  zstring lStrRes;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState))
  {
    item->getStringValue2(lStrIri);

    utf8::iri_to_uri(lStrIri, &lStrRes);

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, lStrRes), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, lStrRes), state);
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
  zstring lStrUri;
  zstring lStrRes;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState))
  {
    item->getStringValue2(lStrUri);

    utf8::to_html_uri(lStrUri, &lStrRes);

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, lStrRes), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, lStrRes), state);
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
        resBool = (utf8::find(arg1, arg2, coll) != zstring::npos);
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
          resBool = (utf8::find(arg1, arg2, coll) == 0);
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

        resBool = utf8::ends_with(arg1, arg2, coll);
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
  zstring::size_type index = zstring::npos;
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
          index = utf8::find(arg1, arg2, coll);
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
  zstring::size_type startPos = zstring::npos;
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
          startPos = utf8::find(arg1, arg2, coll);
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
  zstring xquery_pattern;
  zstring flags;
  store::Item_t item;
  bool res = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
    item->getStringValue2(input);

  if (!consumeNext(item, theChildren[1].getp(), planState))
    ZORBA_ASSERT (false);

  item->getStringValue2(xquery_pattern);

  if(theChildren.size() == 3)
  {
    if (!consumeNext(item, theChildren[2].getp(), planState))
      ZORBA_ASSERT (false);

    item->getStringValue2(flags);
  }

  try
  {
    zstring lib_pattern;
    convert_xquery_re( xquery_pattern, &lib_pattern, flags.c_str() );
    res = utf8::match_part(input, lib_pattern, flags.c_str());
  }
  catch(XQueryException& ex)
  {
    set_source( ex, loc );
    throw;
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
    tmp = utf8::match_part(zstring(), pattern, flags.c_str());
  }
  catch(XQueryException& ex)
  {
    set_source( ex, loc );
    throw;
  }

  if (tmp)
    throw XQUERY_EXCEPTION(
      err::FORX0003, ERROR_PARAMS( pattern ), ERROR_LOC( loc )
    );

  if ( flags.find( 'q' ) == zstring::npos ) {
    bool got_backslash = false;
    bool got_dollar = false;
    int const num_capturing_groups = count_capturing_groups( pattern );
    zstring temp_replacement;
    FOR_EACH( zstring, c, replacement ) {
      if ( got_backslash ) {
        switch ( *c ) {
          case '\\':
          case '$':
            temp_replacement += '\\';
            temp_replacement += *c;
            got_backslash = false;
            continue;
          default:
            throw XQUERY_EXCEPTION(
              err::FORX0004,
              ERROR_PARAMS( replacement, ZED( BadCharAfter_34 ), *c, '\\' ),
              ERROR_LOC( loc )
            );
        }
      }
      if ( got_dollar ) {
        if ( !ascii::is_digit( *c ) )
          throw XQUERY_EXCEPTION(
            err::FORX0004,
            ERROR_PARAMS( replacement, ZED( BadCharAfter_34 ), *c, '$' ),
            ERROR_LOC( loc )
          );

        int group = *c - '0';
        char const c2 = ztd::peek( replacement, c );
        if ( ascii::is_digit( c2 ) )
          group = group * 10 + c2 - '0';

        if ( group <= num_capturing_groups ) {
          temp_replacement += '$';
          temp_replacement += *c;
        } else if ( num_capturing_groups && group > 9 ) {
          temp_replacement += '$';
          temp_replacement += *c;
          temp_replacement += '\\';
        }

        got_dollar = false;
        continue;
      }
      switch ( *c ) {
        case '\\':
          got_backslash = true;
          break;
        case '$':
          got_dollar = true;
          break;
        default:
          temp_replacement += *c;
          break;
      }
    } // FOR_EACH
    if ( got_backslash )
      throw XQUERY_EXCEPTION(
        err::FORX0004,
        ERROR_PARAMS( replacement, ZED( TrailingChar_3 ), '\\' ),
        ERROR_LOC( loc )
      );
    if ( got_dollar )
      throw XQUERY_EXCEPTION(
        err::FORX0004,
        ERROR_PARAMS( replacement, ZED( TrailingChar_3 ), '$' ),
        ERROR_LOC( loc )
      );
    replacement = temp_replacement;
  }

  try
  {
    zstring lib_pattern;
    convert_xquery_re( pattern, &lib_pattern, flags.c_str() );
    utf8::replace_all(input, lib_pattern, flags.c_str(), replacement, &resStr);
  }
  catch(XQueryException& ex)
  {
    set_source( ex, loc );
    throw;
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
  zstring pattern, token;
  store::Item_t item;
  bool tmp;
  unicode::string u_string;

  FnTokenizeIteratorState* state;
  DEFAULT_STACK_INIT(FnTokenizeIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    item->getStringValue2(state->theString);
  }

  if (!consumeNext(item, theChildren[1].getp(), planState))
    ZORBA_ASSERT(false);

  item->getStringValue2(pattern);

  if(theChildren.size() == 3)
  {
    if (!consumeNext(item, theChildren[2].getp(), planState))
      ZORBA_ASSERT (false);
    item->getStringValue2(state->theFlags);
  }

  try
  {
    convert_xquery_re( pattern, &state->thePattern, state->theFlags.c_str() );
    static zstring const empty;
    tmp = utf8::match_part( empty, state->thePattern, state->theFlags );
  }
  catch(XQueryException& ex)
  {
    set_source( ex, loc );
    throw;
  }

  if(tmp)
    throw XQUERY_EXCEPTION(
      err::FORX0003, ERROR_PARAMS( pattern ), ERROR_LOC( loc )
    );


  while ((xs_unsignedInt)state->start_pos < state->theString.length ())
  {
    try
    {
      unicode::regex re;
      //
      // The RE needs to be compiled every time due to the weird stack macros.
      //
      re.compile( state->thePattern, state->theFlags );
      unicode::string u_token;
      bool const got_next = re.next_token(
        state->theString, &state->start_pos, &u_token, &state->hasmatched
      );
      utf8::to_string( u_token, &token );
      if ( !got_next )
        break;
    }
    catch(XQueryException& ex)
    {
      set_source( ex, loc );
      throw;
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

/**
  *______________________________________________________________________
  *
  *  5.6.5 fn:analyze-string
  *
  *fn:analyze-string( $input   as xs:string?,
  *                   $pattern as xs:string) as element(fn:analyze-string-result)
  *fn:analyze-string( $input   as xs:string?,
  *                   $pattern as xs:string,
  *                   $flags   as xs:string) as element(fn:analyze-string-result)
  *_______________________________________________________________________*/

static void copyUtf8Chars(const char *&sin,
                          int &utf8start,
                          unsigned int &bytestart,
                          int utf8end,
                          unsigned int byteend,
                          zstring &out)
{
#ifndef ZORBA_NO_ICU
  utf8::size_type clen;
  if(utf8end)
  {
    while(utf8start < utf8end)
    {
      try {
        clen = utf8::char_length(*sin);
      }
      catch ( utf8::invalid_byte const& ) {
        clen = 1;
      }
      out.append(sin, clen);
      utf8start++;
      bytestart += clen;
      sin += clen;
    }
  }
  else
#endif
  {
    if(!utf8end)
      utf8end = byteend;
    out.append(sin, utf8end-bytestart);
    sin += utf8end-bytestart;
    utf8start = utf8end;
    bytestart = utf8end;
  }
}

static void addNonMatchElement(store::Item_t &parent,
                               int &match_end1,
                               unsigned int &match_end1_bytes,
                               int match_start2,
                               unsigned int match_start2_bytes,
                               const char *&strin)
{
  store::Item_t non_match_elem;
  store::Item_t non_match_element_name;
  store::Item_t untyped_type_name;
  store::NsBindings   ns_binding;
  zstring baseURI;
  GENV_ITEMFACTORY->createQName(untyped_type_name,
                                static_context::W3C_XML_SCHEMA_NS, "", "untyped");
  GENV_ITEMFACTORY->createQName(non_match_element_name,
                                static_context::W3C_FN_NS, "fn", "non-match");
  GENV_ITEMFACTORY->createElementNode(non_match_elem, parent, non_match_element_name, untyped_type_name, false, false, ns_binding, baseURI);
  //utf8_it += (match_start2 - match_end1);
  zstring                non_match_str;
  //utf8_string<zstring>   non_match_utf8(non_match_str);
  //while(match_end1 < match_start2)
  //{
  //  non_match_utf8 += *utf8_it;
  //  utf8_it++;
  //  match_end1++;
  //}
  copyUtf8Chars(strin, match_end1, match_end1_bytes, match_start2, match_start2_bytes, non_match_str);
  store::Item_t non_match_text_item;
  GENV_ITEMFACTORY->createTextNode(non_match_text_item, non_match_elem, non_match_str);
}

static void addGroupElement(store::Item_t &parent,
                            store::Item_t &untyped_type_name,
                            store::NsBindings   &ns_binding,
                            zstring &baseURI,
                            int match_start2,
                            int match_end2,
                            unsigned int &match_end1_bytes,
                            const char *&sin,
                            unicode::regex &rx,
                            int gparent,
                            std::vector<int> const &group_parent,
                            int nr_pattern_groups,
                            int &i)
{
  int    match_startg = match_start2;
  int    match_endg = match_start2;
  int    match_endgood = match_start2;
  store::Item_t group_element_name;
  store::Item_t nr_attrib_name;
  for(i=i+1;i<nr_pattern_groups;i++)
  {
    if(group_parent[i] < gparent)
    {
      i--;
      break;
    }
#ifndef ZORBA_NO_ICU
    match_startg = rx.get_group_start(i+1);
    if((match_startg < 0) && (gparent < 0))
      continue;
#else
    int temp_endg;
    match_startg = -1;
    temp_endg = -1;
    if(!rx.get_group_start_end(&match_startg, &temp_endg, i+1) && (gparent < 0))
      continue;
#endif
    if(match_endgood < match_startg)
    {
      //add non-group match text
      zstring                non_group_str;

      copyUtf8Chars(sin, match_endgood, match_end1_bytes, match_startg, 0, non_group_str);
      store::Item_t non_group_text_item;
      GENV_ITEMFACTORY->createTextNode(non_group_text_item, parent.getp(), non_group_str);
    }
#ifndef ZORBA_NO_ICU
    match_endg = rx.get_group_end(i+1);
#else
    match_endg = temp_endg;
#endif
    //add group match text
    GENV_ITEMFACTORY->createQName(group_element_name,
                                  static_context::W3C_FN_NS, "fn", "group");
    GENV_ITEMFACTORY->createQName(nr_attrib_name,
                                  "", "", "nr");
    store::Item_t group_elem;
    GENV_ITEMFACTORY->createElementNode(group_elem, parent, group_element_name, untyped_type_name, false, false, ns_binding, baseURI);
    char strid[40];
    sprintf(strid, "%d", i+1);
    zstring zstrid(strid);
    store::Item_t strid_item;
    GENV_ITEMFACTORY->createString(strid_item, zstrid);
    store::Item_t id_attrib_item;
    GENV_ITEMFACTORY->createAttributeNode(id_attrib_item, group_elem.getp(), nr_attrib_name, untyped_type_name, strid_item);
    if((match_startg < 0) || (match_startg < match_endgood))
      continue;
    match_endgood = match_endg;
    if((i+1)<nr_pattern_groups)
    {
      if(group_parent[i+1] > gparent)
      {
        addGroupElement(group_elem, untyped_type_name, ns_binding, baseURI,
                        match_startg, match_endg, match_end1_bytes,
                        sin, rx,
                        i, group_parent, nr_pattern_groups, i);
        continue;
      }
    }
    zstring                group_str;

    copyUtf8Chars(sin, match_startg, match_end1_bytes, match_endg, 0, group_str);
    store::Item_t group_text_item;
    GENV_ITEMFACTORY->createTextNode(group_text_item, group_elem.getp(), group_str);
  }
  //add last non-group match
  if(match_endgood < match_end2)
  {
    zstring                non_group_str;

    copyUtf8Chars(sin, match_endgood, match_end1_bytes, match_end2, 0, non_group_str);
    store::Item_t non_group_text_item;
    GENV_ITEMFACTORY->createTextNode(non_group_text_item, parent, non_group_str);
  }
}

static void addMatchElement(store::Item_t &parent,
                    int match_start2,
                    unsigned int &match_end1_bytes,
                    int match_end2,
                    //utf8_string<zstring_p>::const_iterator& utf8_it,
                    const char *&sin,
                    unicode::regex &rx,
                    std::vector<int> &group_parent,
                    int nr_pattern_groups)
{
  store::Item_t match_element_name;
  store::Item_t untyped_type_name;
  store::NsBindings   ns_binding;
  zstring baseURI;
  GENV_ITEMFACTORY->createQName(untyped_type_name,
                                static_context::W3C_XML_SCHEMA_NS, "", "untyped");
  GENV_ITEMFACTORY->createQName(match_element_name,
                                static_context::W3C_FN_NS, "fn", "match");
  store::Item_t match_elem;
  GENV_ITEMFACTORY->createElementNode(match_elem, parent, match_element_name, untyped_type_name, false, false, ns_binding, baseURI);
  int i = -1;
  addGroupElement(match_elem, untyped_type_name, ns_binding, baseURI, match_start2, match_end2, match_end1_bytes, sin, rx, -1, group_parent, nr_pattern_groups, i);
}

static void calc_group_parents( zstring const &regex,
                                std::vector<int> *group_parents ) {
  bool got_backslash = false;
  int group = 0;
  std::stack<bool> is_capturing;
  std::stack<int> parents;

  FOR_EACH( zstring, c, regex ) { 
    if ( got_backslash )
      got_backslash = false;
    else
      switch ( *c ) {
        case '\\':
          got_backslash = true;
          break;
        case '(':
          if ( ztd::peek( regex, c ) != '?' ) {
            is_capturing.push( true );
            group_parents->push_back( parents.empty() ? -1 : parents.top() );
            parents.push( group++ );
          } else
            is_capturing.push( false );
          break;
        case ')':
          if ( is_capturing.top() && !parents.empty() )
            parents.pop();
          is_capturing.pop();
          break;
      } // switch
  } // for
}

bool FnAnalyzeStringIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  bool is_input_stream = false;
  zstring input;
  std::istream *instream = NULL;
#define STREAMBUF_CHUNK_SIZE    4*1024
  class SmartCharPtr
  {
  public:
    char *ptr;
    SmartCharPtr() : ptr(NULL) {}
    ~SmartCharPtr() {if(ptr) ::free(ptr);}
  };
  SmartCharPtr    streambuf;
  zstring::size_type   streambuf_allocated_size = 0;
  zstring::size_type   streambuf_read = 0;
  //zstring::size_type   streambuf_beg = 0;
  zstring xquery_pattern;
  zstring flags;
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    if(!item->isStreamable())
    {
      item->getStringValue2(input);
    }
    else
    {
      instream = &item->getStream();
      is_input_stream = true;
    }
  }

  if (!consumeNext(item, theChildren[1].getp(), planState))
    ZORBA_ASSERT (false);

  item->getStringValue2(xquery_pattern);

  if(theChildren.size() == 3)
  {
    if (!consumeNext(item, theChildren[2].getp(), planState))
      ZORBA_ASSERT (false);

    item->getStringValue2(flags);
  }

  try
  {
    zstring lib_pattern;
    convert_xquery_re( xquery_pattern, &lib_pattern, flags.c_str() );

    if(is_input_stream)
    {
      streambuf.ptr = (char*)malloc(STREAMBUF_CHUNK_SIZE);
      streambuf_allocated_size = STREAMBUF_CHUNK_SIZE;
      instream->read(streambuf.ptr, streambuf_allocated_size);
      streambuf_read = (unsigned int)instream->gcount();
      if(streambuf_read == STREAMBUF_CHUNK_SIZE)
      {
	// Note: const_reverse_iterator would work here, but does not
	// compile with gcc 4.0.1 (which is the version in Xcode on MacOS 10.5).
        zstring::reverse_iterator xqit = xquery_pattern.rbegin();
        if((xqit != xquery_pattern.rend()) && (flags.find('m') == std::string::npos))
        {
          if(*xqit == '$')
          {
            xqit++;
            int bslashes = 0;
            while(xqit != xquery_pattern.rend())
            {
              if(*xqit == '\\')
                bslashes++;
              else
                break;
            }
            if(bslashes%2 == 0)
            {
              //better read all instream
              do{
                streambuf.ptr = (char*)realloc(streambuf.ptr, streambuf_allocated_size+STREAMBUF_CHUNK_SIZE);
                streambuf_allocated_size += STREAMBUF_CHUNK_SIZE;
                instream->read(streambuf.ptr + streambuf_read, STREAMBUF_CHUNK_SIZE);
                streambuf_read += (unsigned int)instream->gcount();
              }while(instream->gcount() == STREAMBUF_CHUNK_SIZE);
            }
          }
        }
      }
    }

    unicode::regex    rx;
    rx.compile(lib_pattern, flags.c_str());
    int   nr_pattern_groups = rx.get_group_count();
    std::vector<int>    group_parent;
    calc_group_parents(xquery_pattern, &group_parent);

    //see if regex can match empty strings
    bool   reachedEnd = false;
    rx.set_string("", 0);
    if (rx.next_match(&reachedEnd))
    {
      throw XQUERY_EXCEPTION(err::FORX0003, ERROR_PARAMS(lib_pattern));
    }

    store::Item_t null_parent;
    store::Item_t result_element_name;
    store::Item_t untyped_type_name;
    store::NsBindings   ns_binding;
    zstring baseURI;
    GENV_ITEMFACTORY->createQName(untyped_type_name,
                                  static_context::W3C_XML_SCHEMA_NS, "", "untyped");
    GENV_ITEMFACTORY->createQName(result_element_name,
                                  static_context::W3C_FN_NS, "fn", "analyze-string-result");
    GENV_ITEMFACTORY->createElementNode(result, NULL, result_element_name, untyped_type_name, false, false, ns_binding, baseURI);

    int nr_retry = 0;
    reachedEnd = false;
    do
    {
      const char *instr;
      if (!is_input_stream)
      {
        rx.set_string(input.data(), input.size());
        instr = input.c_str();
        streambuf_read = input.size();
      }
      else
      {
        unsigned int reducebytes = 0;
        if (!instream->eof())
        {
          //check the last bytes, maybe it is a truncated utf8 char
          unsigned int maxbytes = 6;
          if (maxbytes > streambuf_read)
            maxbytes = streambuf_read;
          for (reducebytes=1;reducebytes<=maxbytes;reducebytes++)
          {
            try {
              utf8::size_type clen =
                utf8::char_length(streambuf.ptr[streambuf_read-reducebytes]);
              if((clen > 1) && (clen > reducebytes))
                break;
            }
            catch ( utf8::invalid_byte const& ) {
              // do nothing?
            }
          }
          if(reducebytes == (maxbytes+1))
            reducebytes = 0;
        }
        rx.set_string(streambuf.ptr, streambuf_read-reducebytes);
        instr = streambuf.ptr;
      }
      //zstring_p zinstr(instr);
      //utf8_string<zstring_p>  utf8_instr(zinstr);
      //utf8_string<zstring_p>::const_iterator    utf8_it = utf8_instr.begin();

      //int    match_start1 = 0;
      int    match_end1 = 0;
      unsigned int    match_end1_bytes = 0;
      reachedEnd = false;
      while(rx.next_match(&reachedEnd))
      {
        int    match_start2;
        int    match_end2;

        rx.get_group_start_end(&match_start2, &match_end2);
        ZORBA_ASSERT(match_start2 >= 0);

        if(is_input_stream && reachedEnd && !instream->eof())
        {
          //load some more data, maybe the match will be different
          break;
        }

        //construct the fn:non-match
        if(match_start2 > match_end1)
        {
          addNonMatchElement(result, match_end1, match_end1_bytes, match_start2, 0, instr);
        }

        //construct the fn:match
        addMatchElement(result, match_start2, match_end1_bytes, match_end2, instr, rx, group_parent, nr_pattern_groups);
        match_end1 = match_end2;
      }

      if(is_input_stream && !instream->eof())
      {
        //load some more data, maybe the match will be different
        if(match_end1_bytes)
        {
          memmove(streambuf.ptr, streambuf.ptr+match_end1_bytes, streambuf_read-match_end1_bytes);
          streambuf_read -= match_end1_bytes;
          nr_retry = 0;
        }
        else
          nr_retry++;
        if(!match_end1_bytes && (nr_retry == 2))
        {
          if(streambuf_allocated_size > streambuf_read)
          {
            instream->read(streambuf.ptr + streambuf_read, streambuf_allocated_size - streambuf_read);
            streambuf_read += (unsigned int)instream->gcount();
          }
          //better read all instream
          while(!instream->eof())
          {
            streambuf.ptr = (char*)realloc(streambuf.ptr, streambuf_allocated_size+STREAMBUF_CHUNK_SIZE);
            instream->read(streambuf.ptr + streambuf_read, STREAMBUF_CHUNK_SIZE);
            streambuf_read += (unsigned int)instream->gcount();
            streambuf_allocated_size += STREAMBUF_CHUNK_SIZE;
          }
        }
        else
        {
          //read some more data from instream
          if(streambuf_allocated_size > streambuf_read)
          {
            instream->read(streambuf.ptr + streambuf_read, streambuf_allocated_size - streambuf_read);
            streambuf_read += (unsigned int)instream->gcount();
          }
          else
          {
            streambuf.ptr = (char*)realloc(streambuf.ptr, streambuf_allocated_size+STREAMBUF_CHUNK_SIZE);
            instream->read(streambuf.ptr + streambuf_read, STREAMBUF_CHUNK_SIZE);
            streambuf_read += (unsigned int)instream->gcount();
            streambuf_allocated_size += STREAMBUF_CHUNK_SIZE;
          }
        }
        reachedEnd = false;
      }
      else
      {
        if(match_end1_bytes < streambuf_read)
          addNonMatchElement(result, match_end1, match_end1_bytes, 0, streambuf_read, instr);
        if(is_input_stream && instream->eof())
          reachedEnd = true;
      }

    }while(is_input_stream && !reachedEnd);
  }
  catch(XQueryException& ex)
  {
    set_source( ex, loc );
    throw;
  }

  STACK_PUSH(true, state);

  STACK_END(state);
}

/**
 *______________________________________________________________________
 *
 * http://zorba.io/modules/string
 * string:analyze-string
 */

#define STREAM_ANALYZE_STRING 0

static void add_json_substring( utf8_string<zstring const> const &u_input,
                                int *start, int end,
                                vector<store::Item_t> *items ) {
  zstring temp( u_input.substr( *start, end - *start ) );
  *start = end;
  store::Item_t item;
  GENV_ITEMFACTORY->createString( item, temp );
  items->push_back( item );
}

static void add_json_group_match( utf8_string<zstring const> const &u_input,
                                  int m_start, int m_end,
                                  unicode::regex const &regex, int g_count,
                                  int g_parent, vector<int> const &g_parents,
                                  int *p_group, int *p_g_end_prev,
                                  vector<store::Item_t> *array_items ) {
  int &group = *p_group;
  int &g_end_prev = *p_g_end_prev;
  store::Item_t item;

  for ( ++group; group < g_count; ++group ) {
    if ( g_parents[ group ] < g_parent ) {
      --group;
      break;
    }

    int const group_1 = group + 1;
    int g_start, g_end;
    regex.get_group_start_end( &g_start, &g_end, group_1 );
    if ( g_start > m_start && g_start > g_end_prev ) {
      //
      // Add the substring between the end of the previous capturing group
      // match and this one.
      //
      add_json_substring( u_input, &g_end_prev, g_start, array_items );
    }

    vector<store::Item_t> array_items2;
    GENV_ITEMFACTORY->createInteger( item, xs_integer( group_1 ) );
    array_items2.push_back( item );

    if ( group_1 < g_count && g_parents[ group_1 ] > g_parent ) {
      //
      // The next capturing group is nested within this one.
      //
      add_json_group_match(
        u_input, m_start, m_end, regex, g_count, group, g_parents, &group,
        &g_end_prev, &array_items2
      );
      if ( g_end > g_end_prev ) {
        //
        // Add the substring between the end of the nested capturing group
        // match and this one.
        //
        add_json_substring( u_input, &g_end_prev, g_end, &array_items2 );
      }
    } else {
      //
      // Add the substring for this capturing group match.
      //
      add_json_substring( u_input, &g_start, g_end, &array_items2 );
      g_end_prev = g_start;
    }

    GENV_ITEMFACTORY->createJSONArray( item, array_items2 );
    array_items->push_back( item );
  } // for
}

static bool add_json_group_match( utf8_string<zstring const> const &u_input,
                                  int m_start, int m_end,
                                  unicode::regex const &regex, int g_count,
                                  vector<int> const &g_parents,
                                  store::Item_t *result ) {
  vector<store::Item_t> array_items;
  int group = -1, g_end_prev = 0;
  add_json_group_match(
    u_input, m_start, m_end, regex, g_count, -1, g_parents, &group, &g_end_prev,
    &array_items
  );
  if ( array_items.empty() )
    return false;

  //
  // Add the substring between the end of the last capturing group and the end
  // of the match (if any).
  //
  int g_end_max = 0;
  for ( int group = 1; group <= g_count; ++group ) {
    int g_start, g_end;
    regex.get_group_start_end( &g_start, &g_end, group );
    if ( g_end > g_end_max )
      g_end_max = g_end;
  }
  if ( g_end_max && m_end > g_end_max )
    add_json_substring( u_input, &g_end_max, m_end, &array_items );

  GENV_ITEMFACTORY->createJSONArray( *result, array_items );
  return true;
}

static void add_json_match( utf8_string<zstring const> const &u_input,
                            int m_start, int m_end,
                            unicode::regex const &regex, int g_count,
                            vector<int> const &g_parents,
                            store::Item_t *result ) {
  store::Item_t item;
  vector<store::Item_t> keys, values;

  zstring temp( "match" );
  GENV_ITEMFACTORY->createString( item, temp );
  keys.push_back( item );

  if ( !add_json_group_match( u_input, m_start, m_end, regex, g_count,
                              g_parents, &item ) ) {
    temp = u_input.substr( m_start, m_end - m_start );
    GENV_ITEMFACTORY->createString( item, temp );
  }
  values.push_back( item );

  GENV_ITEMFACTORY->createJSONObject( *result, keys, values );
}

static void add_json_non_match( utf8_string<zstring const> const &u_input,
                                int m_start, int m_end,
                                store::Item_t *result ) {
  store::Item_t item;
  vector<store::Item_t> keys, values;

  zstring temp( "non-match" );
  GENV_ITEMFACTORY->createString( item, temp );
  keys.push_back( item );

  temp = u_input.substr( m_start, m_end - m_start );
  GENV_ITEMFACTORY->createString( item, temp );
  values.push_back( item );

  GENV_ITEMFACTORY->createJSONObject( *result, keys, values );
}

bool StringAnalyzeStringIterator::nextImpl( store::Item_t& result,
                                            PlanState& planState ) const {  
  vector<store::Item_t> array_items;
  int g_count;
  vector<int> g_parents;
  store::Item_t item;
  zstring input, pattern, lib_pattern, flags;
#if STREAM_ANALYZE_STRING
  istream *is;
  istringstream iss;
  mem_streambuf mbuf;
#endif
  int m_start, m_end = 0, m_end_prev = 0;
  unicode::regex regex;
  utf8_string<zstring const> u_input;
  utf8_string<zstring const>::size_type u_size;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext( item, theChildren[0].getp(), planState );
#if STREAM_ANALYZE_STRING
  if ( item->isStreamable() ) {
    is = &item->getStream();
  } else {
#endif
    item->getStringValue2( input );
    u_input.wrap( input );
    u_size = u_input.size();
#if STREAM_ANALYZE_STRING
    mbuf.set( input.data(), input.size() );
    iss.ios::rdbuf( &mbuf );
    is = &iss;
  }
#endif
  consumeNext( item, theChildren[1].getp(), planState );
  item->getStringValue2( pattern );
  if ( theChildren.size() > 2 ) {
    consumeNext( item, theChildren[2].getp(), planState );
    item->getStringValue2( flags );
  }

  try {
    convert_xquery_re( pattern, &lib_pattern, flags.c_str() );
    regex.compile( lib_pattern, flags );
  }
  catch ( XQueryException &xe ) {
    set_source( xe, loc );
    throw;
  }
  if ( regex.match_part( "" ) )         // matching the empty string is illegal
    throw XQUERY_EXCEPTION(
      err::FORX0003,
      ERROR_PARAMS( pattern ),
      ERROR_LOC( loc )
    );
  g_count = regex.get_group_count();
  calc_group_parents( pattern, &g_parents );

  regex.set_string( input.data(), input.size() );
  while ( regex.next_match() ) {
    regex.get_group_start_end( &m_start, &m_end );
    if ( m_start > m_end_prev ) {
      add_json_non_match( u_input, m_end_prev, m_start, &item );
      array_items.push_back( item );
    }
    add_json_match( u_input, m_start, m_end, regex, g_count, g_parents, &item );
    array_items.push_back( item );
    m_end_prev = m_end;
  }
  if ( (utf8_string<zstring const>::size_type)m_end < u_size ) {
    add_json_non_match( u_input, m_end, u_size, &item );
    array_items.push_back( item );
  }
  GENV_ITEMFACTORY->createJSONArray( result, array_items );

  STACK_PUSH( true, state );
  STACK_END( state );
}

/**
 *______________________________________________________________________
 *
 * http://zorba.io/modules/string
 * string:materialize
 */
bool StringMaterializeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  zstring       lString;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

#ifndef NDEBUG
  assert(consumeNext(item, theChildren[0].getp(), planState));
#else
  consumeNext(item, theChildren[0].getp(), planState);
#endif
  if (item->isStreamable()) {
    lString = item->getString();
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, lString), state);
  } else {
    result = item;
    STACK_PUSH(result != 0 , state);
  }

  STACK_END(state);
}

/**
 *______________________________________________________________________
 *
 * http://zorba.io/modules/string
 * string:materialize
 */
bool StringIsStreamableIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

#ifndef NDEBUG
  assert(consumeNext(item, theChildren[0].getp(), planState));
#else
  consumeNext(item, theChildren[0].getp(), planState);
#endif
  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, item->isStreamable()), state);

  STACK_END(state);
}

/**
 *______________________________________________________________________
 *
 * http://zorba.io/modules/string
 * string:is-seekable
 */
bool StringIsSeekableIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

#ifndef NDEBUG
  assert(consumeNext(item, theChildren[0].getp(), planState));
#else
  consumeNext(item, theChildren[0].getp(), planState);
#endif
  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, item->isSeekable()), state);

  STACK_END(state);
}

/**
 *______________________________________________________________________
 *
 * http://zorba.io/modules/string
 * string:split
 */
bool StringSplitIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  bool read;
  store::Item_t item;
  size_t lNewPos = 0;
  zstring lToken;
  zstring lPartialMatch;

  StringSplitIteratorState* state;
  DEFAULT_STACK_INIT(StringSplitIteratorState, state, planState);

  // init phase, get input string and tokens
  consumeNext(item, theChildren[0].getp(), planState);

  if (item->isStreamable())
  {
    state->theIStream = &item->getStream();
  }
  else
  {
    state->theIStream = 0;
    item->getStringValue2(state->theInput);
  }

  consumeNext(item, theChildren[1].getp(), planState);

  item->getStringValue2(state->theSeparator);

  // working phase, do the tokenization
  if (state->theIStream)
  {
    while ( !state->theIStream->eof() )
    {
      utf8::encoded_char_type ec;
      memset( ec, 0 , sizeof(ec) );

      try {
        read = !!utf8::read( *state->theIStream, ec );
      }
      catch ( utf8::invalid_byte const& ) {
        ostringstream oss;
        oseparator comma( ',' );
        for ( utf8::storage_type const *c = ec; *c; ++c )
          oss << comma << ascii::printable_char( *c );
        throw XQUERY_EXCEPTION(
          zerr::ZXQD0006_INVALID_UTF8_BYTE_SEQUENCE,
          ERROR_PARAMS( oss.str() ),
          ERROR_LOC( loc )
        );
      }

      if ( read )
      {
        if (state->theSeparator.compare(lNewPos, 1, ec) == 0)
        {
          if (++lNewPos == state->theSeparator.length())
          {
            GENV_ITEMFACTORY->createString(result, lToken);
            STACK_PUSH(true, state);
          }
          else
          {
            lPartialMatch.append(ec);
          }
        }
        else
        {
          lToken.append(lPartialMatch);
          lToken.append(ec);
        }
      }
      else
      {
        if ( !state->theIStream->eof() && !state->theIStream->good() )
          throw XQUERY_EXCEPTION(
            zerr::ZOSE0003_STREAM_READ_FAILURE, ERROR_LOC( loc )
          );
        if (!lToken.empty())
        {
          GENV_ITEMFACTORY->createString(result, lToken);
          STACK_PUSH(true, state);
        }
        break;
      }
    } // while
  }
  else
  {
    while (true)
    {
      if (state->theNextStartPos == zstring::npos)
      {
        break;
      }

      lNewPos =
        state->theInput.find(state->theSeparator, state->theNextStartPos);
      if (lNewPos != zstring::npos)
      {
        zstring lSubStr = state->theInput.substr(
            state->theNextStartPos,
            lNewPos - state->theNextStartPos);
        GENV_ITEMFACTORY->createString(result, lSubStr);
        state->theNextStartPos =
          lNewPos==state->theInput.length() - state->theSeparator.length()
          ? zstring::npos
          : lNewPos + state->theSeparator.length();
      }
      else
      {
        zstring lSubStr = state->theInput.substr(state->theNextStartPos);
        GENV_ITEMFACTORY->createString(result, lSubStr);
        state->theNextStartPos = zstring::npos;
      }
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}
} // namespace zorba
/* vim:set et sw=2 ts=2: */
