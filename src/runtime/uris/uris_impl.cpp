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
#include "stdafx.h"

#include <algorithm>

#include <zorba/util/transcode_stream.h>
#include <zorba/diagnostic_list.h>

#include "common/common.h"

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "runtime/uris/uris.h"

#include "system/globalenv.h"
#include "store/api/item_factory.h"

#include "util/uri_util.h"

#include "zorbatypes/URI.h"

#define SCHEME_NAME      "scheme"
#define OPAQUE_PART_NAME "opaque-part"
#define AUTHORITY_NAME   "authority"
#define USER_INFO_NAME   "user-info"
#define HOST_NAME        "host"
#define PORT_NAME        "port"
#define PATH_NAME        "path"
#define QUERY_NAME       "query"
#define FRAGMENT_NAME    "fragment"

#ifdef _MSC_VER
#pragma warning ( disable: 4800 )
#endif

using namespace std;

namespace zorba {

/******************************************************************************
*******************************************************************************/
bool
DecodeURIIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lString, lDecodePlus, lEncoding;
  zstring       lDecodedString, lCharset;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lString, theChildren[0].getp(), planState);
  consumeNext(lDecodePlus, theChildren[1].getp(), planState);
  consumeNext(lEncoding, theChildren[2].getp(), planState);

  lString->getStringValue2(lDecodedString);
  lEncoding->getStringValue2(lCharset);

  if (lDecodePlus->getBooleanValue())
  {
    std::replace( lDecodedString.begin(), lDecodedString.end(), '+', ' ' );
  }

  uri::decode(lDecodedString);

  if (transcode::is_necessary(lCharset.c_str()))
  {
    if (!transcode::is_supported(lCharset.c_str()))
    {
      throw XQUERY_EXCEPTION(
        zuri::CHARSET_UNKNOWN,
        ERROR_PARAMS( lCharset ),
        ERROR_LOC( loc )
      );
    }

    try
    {
      transcode::stream<istringstream> lTranscoder(
          lCharset.c_str(),
          lDecodedString.c_str()
        );

      lDecodedString.clear();
      char buf[1024];
      while (lTranscoder.good())
      {
        lTranscoder.read(buf, 1024);
        lDecodedString.append(buf, static_cast<zstring::size_type>(lTranscoder.gcount()));
      }
    }
    catch (ZorbaException& e)
    {
      throw XQUERY_EXCEPTION(
        zerr::ZOSE0006_TRANSCODING_ERROR,
        ERROR_PARAMS( e.what() ),
        ERROR_LOC( loc )
      );
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createString(result, lDecodedString), state );

  STACK_END (state);
}

/******************************************************************************
*******************************************************************************/
bool
ParseURIIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t              lItemURI, lName, lValue;
  std::vector<store::Item_t> lNames;
  std::vector<store::Item_t> lValues;
  zorba::zstring             lStrURI, lZKey, lZVal;
  PlanIteratorState* state;
  URI uri;
  
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lItemURI, theChildren[0].getp(), planState);
  lItemURI->getStringValue2(lStrURI);
  uri = URI(lStrURI);

  lZVal = uri.get_scheme();
  if(!lZVal.empty())
  {
    lZKey = zorba::zstring(SCHEME_NAME);
    GENV_ITEMFACTORY->createString(lName, lZKey);
    GENV_ITEMFACTORY->createString(lValue, lZVal);
    lNames.push_back(lName);
    lValues.push_back(lValue);
  }

  lZVal = uri.get_opaque_part();
  if(!lZVal.empty())
  {
    lZKey = zorba::zstring(OPAQUE_PART_NAME);
    GENV_ITEMFACTORY->createString(lName, lZKey);
    GENV_ITEMFACTORY->createString(lValue, lZVal);
    lNames.push_back(lName);
    lValues.push_back(lValue);
  }

  lZVal = uri.get_encoded_reg_based_authority();
  if(!lZVal.empty())
  {
    lZKey = zorba::zstring(AUTHORITY_NAME);
    GENV_ITEMFACTORY->createString(lName, lZKey);
    GENV_ITEMFACTORY->createString(lValue, lZVal);
    lNames.push_back(lName);
    lValues.push_back(lValue);
  }

  lZVal = uri.get_encoded_user_info();
  if(!lZVal.empty())
  {
    lZKey = zorba::zstring(USER_INFO_NAME);
    GENV_ITEMFACTORY->createString(lName, lZKey);
    GENV_ITEMFACTORY->createString(lValue, lZVal);
    lNames.push_back(lName);
    lValues.push_back(lValue);
  }
  
  lZVal = uri.get_host();
  if(!lZVal.empty())
  {
    lZKey = zorba::zstring(HOST_NAME);
    GENV_ITEMFACTORY->createString(lName, lZKey);
    GENV_ITEMFACTORY->createString(lValue, lZVal);
    lNames.push_back(lName);
    lValues.push_back(lValue);
  }
  
  if(uri.get_port() != 0)
  {
    lZKey = zorba::zstring(PORT_NAME);
    GENV_ITEMFACTORY->createString(lName, lZKey);
    GENV_ITEMFACTORY->createInt(lValue, uri.get_port());
    lNames.push_back(lName);
    lValues.push_back(lValue);
  }
  
  lZVal = uri.get_encoded_path();
  if(!lZVal.empty())
  {
    lZKey = zorba::zstring(PATH_NAME);
    GENV_ITEMFACTORY->createString(lName, lZKey);
    GENV_ITEMFACTORY->createString(lValue, lZVal);
    lNames.push_back(lName);
    lValues.push_back(lValue);
  }
  
  lZVal = uri.get_encoded_query();
  if(uri.is_set(URI::QueryString))
  {
    lZKey = zorba::zstring(QUERY_NAME);
    GENV_ITEMFACTORY->createString(lName, lZKey);
    GENV_ITEMFACTORY->createString(lValue, lZVal);
    lNames.push_back(lName);
    lValues.push_back(lValue);
  }
  
  lZVal = uri.get_encoded_fragment();
  if(!lZVal.empty())
  {
    lZKey = zorba::zstring(FRAGMENT_NAME);
    GENV_ITEMFACTORY->createString(lName, lZKey);
    GENV_ITEMFACTORY->createString(lValue, lZVal);
    lNames.push_back(lName);
    lValues.push_back(lValue);
  }

  GENV_ITEMFACTORY->createJSONObject(result, lNames, lValues);

  STACK_PUSH(result, state );

  STACK_END (state);
}

/******************************************************************************
*******************************************************************************/
bool
SerializeURIIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     lItemURI, lItemKey;
  zorba::zstring    lStrValue, lStrKey, lStrRes;
  store::Iterator_t lKeys;
  URI               uri = URI();
  int               lIntPort = 0;
  bool              lHasSchemeField, lHasOpaqueField, lHasNotOpaqueField;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lItemURI, theChildren[0].getp(), planState);

  lHasSchemeField = lHasOpaqueField = lHasNotOpaqueField = false;
  if(lItemURI->isObject()) {
    lKeys = lItemURI->getObjectKeys();
    if(!lKeys.isNull()){
      lKeys->open();
      while(lKeys->next(lItemKey)){
        lStrKey = lItemKey->getStringValue();
        lStrValue = lItemURI->getObjectValue(lItemKey)->getStringValue();
        if(lStrKey == SCHEME_NAME && !lStrValue.empty()){
          uri.set_scheme(lStrValue);
          lHasSchemeField = true;
        } else if(lStrKey == OPAQUE_PART_NAME && !lStrValue.empty()){
          uri.set_opaque_part(lStrValue);
          lHasOpaqueField = true;
        } else if(lStrKey == AUTHORITY_NAME && !lStrValue.empty()){
          uri.set_reg_based_authority(lStrValue);
          lHasNotOpaqueField = true;
        } else if(lStrKey == USER_INFO_NAME && !lStrValue.empty()){
          uri.set_user_info(lStrValue);
          lHasNotOpaqueField = true;
        } else if(lStrKey == HOST_NAME && !lStrValue.empty()){
          uri.set_host(lStrValue);
          lHasNotOpaqueField = true;
        } else if(lStrKey == PORT_NAME){
          sscanf(lStrValue.str().c_str(), "%d", &lIntPort);
          if(lIntPort != 0){
            uri.set_port(lIntPort);
            lHasNotOpaqueField = true;
          }
        } else if(lStrKey == PATH_NAME && !lStrValue.empty()){
          uri.set_path(lStrValue);
          lHasNotOpaqueField = true;
        } else if(lStrKey == QUERY_NAME){
          uri.set_query(lStrValue);
          lHasNotOpaqueField = true;
        } else if(lStrKey == FRAGMENT_NAME){
          uri.set_fragment(lStrValue);
        }
      }
      lKeys->close();
    }
  }

  // check for errors
  if(lHasOpaqueField && lHasNotOpaqueField)
  {
    throw XQUERY_EXCEPTION(
      zuri::OPAQUE_COMB_NOT_VALID,
      ERROR_LOC( loc )
    );
  }
  if(lHasOpaqueField && !lHasSchemeField)
  {
    throw XQUERY_EXCEPTION(
      zuri::OPAQUE_WITHOUT_SCHEME,
      ERROR_LOC( loc )
    );
  }
  if(lHasSchemeField && !uri.get_encoded_path().empty() && (uri.get_encoded_path().substr(0,1) != "/"))
  {
    throw XQUERY_EXCEPTION(
      zuri::INVALID_ABSOLUTE_PATH,
      ERROR_LOC( loc )
    );
  }
  
  lStrRes = zorba::zstring(uri.toString());
  STACK_PUSH(GENV_ITEMFACTORY->createString(result, lStrRes), state );

  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
