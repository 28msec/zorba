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

#include "common/common.h"

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "runtime/uris/uris.h"

#include "system/globalenv.h"
#include "store/api/item_factory.h"

#include "zorba/transcode_stream.h"

#include "util/uri_util.h"

#include "zorbatypes/URI.h"

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
        zerr::ZXQP0006_UNKNOWN_ENCODING,
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
        lDecodedString.append(buf, lTranscoder.gcount());
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
  store::Item_t     lItemURI, lElementURI, lQName,
                    lElementScheme, lElementSchemeSpecific,
                    lElementAuthority, lElementUserInfo,
                    lElementHost, lElementPort, lElementPath,
                    lElementQuery, lElementFragment,
                    lQNameUntyped, lQNameString, lQNameInt;
  store::Item_t     lTextScheme, lTextSchemeSpecific, lTextAuthority,
                    lTextUserInfo, lTextHost, lTextPort, lTextPath,
                    lTextQuery, lTextFragment;
  zstring           lStrURI, lStrHolder, lZNamespace;
  const char        *lNamespace, *lXmlSchema;
  char              lCharHost[11];
  store::NsBindings lNsBindings;
  PlanIteratorState* state;
  URI uri;
  lNamespace = "http://www.zorba-xquery.com/modules/uri-format";
  lZNamespace = zstring(lNamespace);
  lXmlSchema = "http://www.w3.org/2001/XMLSchema";
  
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lItemURI, theChildren[0].getp(), planState);
  lItemURI->getStringValue2(lStrURI);
  uri = URI(lStrURI);
  
  GENV_ITEMFACTORY->createQName(
    lQName,
    lNamespace,
    "uri-format",
    "uri");
    
  GENV_ITEMFACTORY->createQName(
    lQNameUntyped,
    lXmlSchema,
    "xsd",
    "untyped");
    
  GENV_ITEMFACTORY->createQName(
    lQNameString,
    lXmlSchema,
    "xs",
    "string");
    
  GENV_ITEMFACTORY->createQName(
    lQNameInt,
    lXmlSchema,
    "xs",
    "int");
  
  GENV_ITEMFACTORY->createElementNode(
    result,
    nullptr,
    lQName,
    lQNameUntyped,
    false,
    false,
    lNsBindings,
    lZNamespace);
  
  lStrHolder = uri.get_scheme();  
  if(lStrHolder.str() != ""){
    GENV_ITEMFACTORY->createQName(
      lQName,
      lNamespace,
      "uri-format",
      "scheme");
    
    GENV_ITEMFACTORY->createElementNode(
      lElementScheme,
      result.getp(),
      lQName,
      lQNameUntyped,
      false,
      false,
      lNsBindings,
      lZNamespace);
    
    GENV_ITEMFACTORY->createTextNode(
      lTextScheme,
      lElementScheme.getp(),
      lStrHolder);
  }
    
  /* GENV_ITEMFACTORY->createQName(
    lQName,
    lNamespace,
    "uri",
    "scheme-specific-part");
  
  GENV_ITEMFACTORY->createElementNode(
    lElementSchemeSpecific,
    result.getp(),
    lQName,
    lQNameString,
    true,
    false,
    lNsBindings,
    lZNamespace);
    
  // Once we have schema-specific data we will add it here
  */  
  
  lStrHolder = uri.get_encoded_reg_based_authority();
  if(lStrHolder.str() != ""){
    GENV_ITEMFACTORY->createQName(
      lQName,
      lNamespace,
      "uri-format",
      "authority");
    
    GENV_ITEMFACTORY->createElementNode(
      lElementAuthority,
      result.getp(),
      lQName,
      lQNameString,
      true,
      false,
      lNsBindings,
      lZNamespace);
      
    GENV_ITEMFACTORY->createTextNode(
      lTextAuthority,
      lElementAuthority.getp(),
      lStrHolder);
  }

  lStrHolder = uri.get_encoded_user_info();
  if(lStrHolder.str() != ""){
    GENV_ITEMFACTORY->createQName(
      lQName,
      lNamespace,
      "uri-format",
      "user-info");
    
    GENV_ITEMFACTORY->createElementNode(
      lElementUserInfo,
      result.getp(),
      lQName,
      lQNameString,
      true,
      false,
      lNsBindings,
      lZNamespace);
      
    GENV_ITEMFACTORY->createTextNode(
      lTextUserInfo,
      lElementUserInfo.getp(),
      lStrHolder);
  }
  
  lStrHolder = uri.get_host();
  if(lStrHolder.str() != ""){
    GENV_ITEMFACTORY->createQName(
      lQName,
      lNamespace,
      "uri",
      "host");
    
    GENV_ITEMFACTORY->createElementNode(
      lElementHost,
      result.getp(),
      lQName,
      lQNameString,
      true,
      false,
      lNsBindings,
      lZNamespace);
    
    GENV_ITEMFACTORY->createTextNode(
      lTextHost,
      lElementHost.getp(),
      lStrHolder);
  }
  
  sprintf(lCharHost,"%d", uri.get_port());
  lStrHolder = zstring(lCharHost);
  if(uri.get_port() != 0){
    GENV_ITEMFACTORY->createQName(
      lQName,
      lNamespace,
      "uri-format",
      "port");
    
    GENV_ITEMFACTORY->createElementNode(
      lElementPort,
      result.getp(),
      lQName,
      lQNameInt,
      true,
      false,
      lNsBindings,
      lZNamespace);
      
    GENV_ITEMFACTORY->createTextNode(
      lTextPort,
      lElementPort.getp(),
      lStrHolder);
  }
  
  lStrHolder = uri.get_encoded_path();
  if(lStrHolder.str() != ""){  
    GENV_ITEMFACTORY->createQName(
      lQName,
      lNamespace,
      "uri-format",
      "path");
    
    GENV_ITEMFACTORY->createElementNode(
      lElementPath,
      result.getp(),
      lQName,
      lQNameString,
      true,
      false,
      lNsBindings,
      lZNamespace);
      
    GENV_ITEMFACTORY->createTextNode(
      lTextPath,
      lElementPath.getp(),
      lStrHolder);
  }
  
  lStrHolder = uri.get_encoded_query();
  if(lStrHolder.str() != ""){
    GENV_ITEMFACTORY->createQName(
      lQName,
      lNamespace,
      "uri-format",
      "query");
    
    GENV_ITEMFACTORY->createElementNode(
      lElementQuery,
      result.getp(),
      lQName,
      lQNameString,
      true,
      false,
      lNsBindings,
      lZNamespace);
      
    GENV_ITEMFACTORY->createTextNode(
      lTextQuery,
      lElementQuery.getp(),
      lStrHolder);
  }
  
  lStrHolder = uri.get_encoded_fragment();
  if(lStrHolder.str() != ""){
    GENV_ITEMFACTORY->createQName(
      lQName,
      lNamespace,
      "uri-format",
      "fragment");
    
    GENV_ITEMFACTORY->createElementNode(
      lElementFragment,
      result.getp(),
      lQName,
      lQNameString,
      true,
      false,
      lNsBindings,
      lZNamespace);
      
    GENV_ITEMFACTORY->createTextNode(
      lTextFragment,
      lElementFragment.getp(),
      lStrHolder);
  }
    
  STACK_PUSH( result, state );

  STACK_END (state);
}

/******************************************************************************
*******************************************************************************/
bool
SerializeURIIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItemURI, lItem, lItem2;
  zstring       lStrVal, lTextVal;
  store::Iterator_t    lChildren, lGrandChildren;
  URI           uri = URI();
  int           lIntPort = 0;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lItemURI, theChildren[0].getp(), planState);

  lStrVal = lItemURI->getNodeName()->getLocalName();
  if(lStrVal == "uri") {
    lChildren = lItemURI->getChildren();
    if(!lChildren.isNull()){
      lChildren->open();
      while(lChildren->next(lItem)){
        lGrandChildren = lItem->getChildren();
        if(!lGrandChildren.isNull()){
          lGrandChildren->open();
          if(lGrandChildren->next(lItem2)){
            //if(lItem->getNodeName()->getLocalName() != "port")
              lTextVal = lItem2->getStringValue();
            //else
              //lIntPort = lItem2->getIntValue();
          } else
            lTextVal = "";
          lGrandChildren->close();
        }
        if(lItem->getNodeName()->getLocalName() == "scheme"){
          uri.set_scheme(lTextVal);
        } else if(lItem->getNodeName()->getLocalName() == "scheme-specific"){
          // we still have to define what we are going to with this
        } else if(lItem->getNodeName()->getLocalName() == "authority"){
          uri.set_reg_based_authority(lTextVal);
        } else if(lItem->getNodeName()->getLocalName() == "user-info"){
          uri.set_user_info(lTextVal);
        } else if(lItem->getNodeName()->getLocalName() == "host"){
          uri.set_host(lTextVal);
        } else if(lItem->getNodeName()->getLocalName() == "port"){
          sscanf(lTextVal.str().c_str(), "%d", &lIntPort);
          uri.set_port(lIntPort);
        } else if(lItem->getNodeName()->getLocalName() == "path"){
          uri.set_path(lTextVal);
        } else if(lItem->getNodeName()->getLocalName() == "query"){
          uri.set_query(lTextVal);
        } else if(lItem->getNodeName()->getLocalName() == "fragment"){
          uri.set_fragment(lTextVal);
        }
      }
      lChildren->close();
    }
  }
  
  lStrVal = zstring(uri.toString());
  STACK_PUSH(GENV_ITEMFACTORY->createString(result, lStrVal), state );

  STACK_END (state);
}
} // namespace zorba
/* vim:set et sw=2 ts=2: */
