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
#include <zorba/config.h>


#include <sstream>

#include "system/globalenv.h"

#include "api/serialization/serializer.h"

#include "compiler/api/compilercb.h"

#include "runtime/json/jsoniq_functions.h"
#include "runtime/parsing_and_serializing/parsing_and_serializing.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/item_iterator.h"

#include "diagnostics/diagnostic.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "zorba/internal/diagnostic.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "types/casting.h"
#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/root_typemanager.h"
#include "zorbatypes/integer.h"

#include <runtime/util/doc_uri_heuristics.h>

#include "store/api/pul.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/copymode.h"

#include "util/uri_util.h"
#include "util/stream_util.h"

#include <zorba/store_consts.h>
#include <zorbatypes/URI.h>
#include <zorba/internal/unique_ptr.h>

#include "json_loader.h"


namespace zorba {

const zstring XS_URI("http://www.w3.org/2001/XMLSchema");

const zstring ENCODE_DECODE_DEFAULT_PREFIX("Q{http://jsoniq.org/roundtrip}");

const zstring NS_PREFIX_KEY("prefix");
const zstring TYPE_KEY("type");
const zstring VALUE_KEY("value");

const char * OPTIONS_KEY_PREFIX = "prefix";
const char * OPTIONS_KEY_SER_PARAMS = "serialization-parameters";

const char * SEQTYPE_ANYNODE  = "node()";
const char * SEQTYPE_COMMENT  = "comment()";
const char * SEQTYPE_DOCUMENT = "document-node()";
const char * SEQTYPE_ELEMENT  = "element()";
const char * SEQTYPE_PROCINST = "processing-instruction()";
const char * SEQTYPE_TEXT     = "text()";

const char * kind2str(const store::NodeKind& aKind)
{
  // we do not support attibutes and namespaces as they cannot be serialized
  switch (aKind)
  {
  case store::StoreConsts::anyNode:      return SEQTYPE_ANYNODE;
  case store::StoreConsts::commentNode:  return SEQTYPE_COMMENT;
  case store::StoreConsts::documentNode: return SEQTYPE_DOCUMENT;
  case store::StoreConsts::elementNode:  return SEQTYPE_ELEMENT;
  case store::StoreConsts::piNode:       return SEQTYPE_PROCINST;
  case store::StoreConsts::textNode:     return SEQTYPE_TEXT;
  default: return "";
  }
}

bool str2kind(const zstring& aString, store::NodeKind& aKind)
{
  switch(aString.at(0))
  {
  case 'c':
    if (aString == SEQTYPE_COMMENT)
    {
      aKind = store::StoreConsts::commentNode;
      return true;
    }
    break;
  case 'd':
    if (aString == SEQTYPE_DOCUMENT)
    {
      aKind = store::StoreConsts::documentNode;
      return true;
    }
    break;
  case 'e':
  case 'n': // "node()" maps to element for backwards compatibility
    if (aString == SEQTYPE_ELEMENT || aString == SEQTYPE_ANYNODE)
    {
      aKind = store::StoreConsts::elementNode;
      return true;
    }
    break;
  case 'p':
    if (aString == SEQTYPE_PROCINST)
    {
      aKind = store::StoreConsts::piNode;
      return true;
    }
    break;
  case 't':
    if (aString == SEQTYPE_TEXT)
    {
      aKind = store::StoreConsts::textNode;
      return true;
    }
    break;
  }
  return false;
}

/*******************************************************************************
  json:decode-from-roundtrip($items as json-item()*,
                             $options as object()) as structured-item()*
********************************************************************************/

void
parseQName(store::Item_t& aResult,
           const zstring& aQNameString,
           const zstring& aPrefix,
           store::ItemFactory* aFactory)
{
  // TODO there probably is a better solution somewhere
  if (aQNameString.substr(0, 3) == "xs:")
  {
    aFactory->createQName(aResult, XS_URI, "xs", aQNameString.substr(3));
  }
  else if (aQNameString.substr(0, 2) == "Q{")
  {
    zstring::size_type lPos = aQNameString.find('}');
    aFactory->createQName(aResult,
                          aQNameString.substr(2, lPos - 2),
                          aPrefix,
                          aQNameString.substr(lPos + 1));
  }
  else
  {
    aFactory->createQName(aResult, "", "", aQNameString);
  }
}

void
JSONDecodeFromRoundtripIterator::extractChildOfKind(
  const store::Item_t& aParent,
  const store::NodeKind& aKind,
  store::Item_t& aChild)
{
  store::Iterator_t lIt = aParent->getChildren();
  bool lFound = false;
  lIt->open();
  while (! lFound && lIt->next(aChild))
  {
    lFound = aChild->getNodeKind() == aKind;
  }
  lIt->close();
  ZORBA_ASSERT(lFound);
}

bool
JSONDecodeFromRoundtripIterator::decodeNode(
  const store::Item_t& aSerializedNode,
  const store::NodeKind& aKind,
  store::Item_t& aResult) const
{
  store::LoadProperties lProperties;
  lProperties.setStoreDocument(false);
  store::Item_t lDoc;
  zstring lXmlString;
  switch (aKind)
  {
  case store::StoreConsts::commentNode:
  case store::StoreConsts::piNode:
  case store::StoreConsts::textNode:
    {
      // we have to wrap these 3 node kinds, so we cannot care about streams
      aSerializedNode->getStringValue2(lXmlString);
      lXmlString = "<a>" + lXmlString + "</a>";
      std::istringstream lStream(lXmlString.c_str());
      lDoc = GENV.getStore().loadDocument("", "", lStream, lProperties);
    }
    break;
  default:
    if (aSerializedNode->isStreamable())
    {
      lDoc = GENV.getStore().loadDocument(
            "", "", aSerializedNode->getStream(), lProperties);
    }
    else
    {
      aSerializedNode->getStringValue2(lXmlString);
      std::istringstream lStream(lXmlString.c_str());
      lDoc = GENV.getStore().loadDocument("", "", lStream, lProperties);
    }
    break;
  }
  if (aKind == store::StoreConsts::documentNode)
  {
    aResult = lDoc;
  }
  else
  {
    store::Item_t lRootElem;
    extractChildOfKind(lDoc, store::StoreConsts::elementNode, lRootElem);
    if (aKind == store::StoreConsts::elementNode)
    {
      // if we needed an element we're done
      aResult = lRootElem;
    }
    else
    {
      // otherwise we have to pass through the wrapper that we've created
      extractChildOfKind(lRootElem, aKind, aResult);
    }
  }
  return true;
}


bool
JSONDecodeFromRoundtripIterator::decodeXDM(
  const store::Item_t& anObj,
  store::Item_t& aResult,
  JSONDecodeFromRoundtripIteratorState* aState) const
{
  store::Item_t lItem;

  zstring lTypeKey = aState->thePrefix + TYPE_KEY;
  GENV_ITEMFACTORY->createString(lItem, lTypeKey);
  store::Item_t lTypeValueItem = anObj->getObjectValue(lItem);
  if (lTypeValueItem.isNull())
  {
    // nothing to change, aResult is not set, the caller needs to use anObj
    return false;
  }

  zstring lValueKey = aState->thePrefix + VALUE_KEY;
  GENV_ITEMFACTORY->createString(lItem, lValueKey);
  store::Item_t lValueValueItem = anObj->getObjectValue(lItem);
  if (lValueValueItem.isNull())
  {
    // nothing to change, aResult is not set, the caller needs to use anObj
    return false;
  }

  zstring lTypeNameString;
  lTypeValueItem->getStringValue2(lTypeNameString);
  store::NodeKind lNodeKind;
  if (str2kind(lTypeNameString, lNodeKind))
  {
    return decodeNode(lValueValueItem, lNodeKind, aResult);
  }
  else
  {
    store::Item_t lTypeQName;
    parseQName(lTypeQName, lTypeNameString, "", GENV_ITEMFACTORY);
    if (lTypeQName->getLocalName() == "QName"
        && lTypeQName->getNamespace() == XS_URI)
    {
      zstring lPrefixKey = aState->thePrefix + NS_PREFIX_KEY;
      GENV_ITEMFACTORY->createString(lItem, lPrefixKey);
      store::Item_t lPrefixValue = anObj->getObjectValue(lItem);
      zstring lPrefixString;
      if (! lPrefixValue.isNull())
      {
        lPrefixValue->getStringValue2(lPrefixString);
      }
      zstring lValueValue;
      lValueValueItem->getStringValue2(lValueValue);
      parseQName(aResult, lValueValue, lPrefixString, GENV_ITEMFACTORY);
    }
    else
    {
      TypeManager* lTypeMgr = theSctx->get_typemanager();
      xqtref_t lTargetType = lTypeMgr->create_named_type(
            lTypeQName.getp(), SequenceType::QUANT_ONE, loc);
      namespace_context lTmpNsCtx(theSctx);
      GenericCast::castToAtomic(aResult,
                                lValueValueItem,
                                lTargetType.getp(),
                                lTypeMgr,
                                &lTmpNsCtx,
                                loc);
    }
    return true;
  }
}


bool
JSONDecodeFromRoundtripIterator::decodeObject(
  const store::Item_t& anObj,
  store::Item_t& aResult,
  JSONDecodeFromRoundtripIteratorState* aState) const
{
  if (decodeXDM(anObj, aResult, aState))
  {
    return true;
  }

  std::vector<store::Item_t> newNames;
  std::vector<store::Item_t> newValues;
  bool modified = false;

  store::Item_t key;
  store::Item_t value;
  store::Item_t newValue;
  store::Iterator_t it = anObj->getObjectKeys();
  it->open();
  while (it->next(key))
  {
    newNames.push_back(key);
    value = anObj->getObjectValue(key);
    const bool gotNew = decodeItem(value, newValue, aState);
    newValues.push_back(gotNew ? newValue : value);
    modified = modified || gotNew;
  }
  it->close();
  if (modified)
  {
    GENV_ITEMFACTORY->createJSONObject(aResult, newNames, newValues);
    return true;
  }
  // nothing to change, aResult is not set, the caller needs to use anObj
  return false;
}


bool
JSONDecodeFromRoundtripIterator::decodeArray(
  const store::Item_t& anArray,
  store::Item_t& aResult,
  JSONDecodeFromRoundtripIteratorState* aState) const
{
  std::vector<store::Item_t> newItems;
  bool modified = false;

  store::Item_t item, newItem;
  store::Iterator_t it = anArray->getArrayValues();
  it->open();
  while (it->next(item))
  {
    const bool gotNew = decodeItem(item, newItem, aState);
    newItems.push_back(gotNew ? newItem : item);
    modified = modified || gotNew;
  }
  it->close();
  if (modified)
  {
    GENV_ITEMFACTORY->createJSONArray(aResult, newItems);
    return true;
  }
  // nothing to change, aResult is not set, the caller needs to use anArray
  return false;
}


bool
JSONDecodeFromRoundtripIterator::decodeItem(
  const store::Item_t& anItem,
  store::Item_t& aResult,
  JSONDecodeFromRoundtripIteratorState* aState) const
{
  if (anItem->isObject())
  {
    return decodeObject(anItem, aResult, aState);
  }
  else if (anItem->isArray())
  {
    return decodeArray(anItem, aResult, aState);
  }
  else
  {
    // nothing to change, aResult is not set, the caller needs to use anItem
    return false;
  }
}


bool
JSONDecodeFromRoundtripIterator::nextImpl(
  store::Item_t& aResult,
  PlanState& aPlanState) const
{
  store::Item_t lInput;
  store::Item_t lDecParams;

  JSONDecodeFromRoundtripIteratorState* lState;
  DEFAULT_STACK_INIT(JSONDecodeFromRoundtripIteratorState, lState, aPlanState);

  // get decoding parameters
  if (theChildren.size() == 2)
  {
    // the signature says that the second parameter has to be exactly one object
    consumeNext(lDecParams, theChildren.at(1), aPlanState);
    store::Item_t lPrefixKey;
    zstring lPrefixNameStr = OPTIONS_KEY_PREFIX;
    GENV_ITEMFACTORY->createString(lPrefixKey, lPrefixNameStr);
    store::Item_t lPrefixValue = lDecParams->getObjectValue(lPrefixKey);
    if (! lPrefixValue.isNull())
    {
      if (lPrefixValue->getTypeCode() != store::XS_STRING)
      {
        RAISE_ERROR(jerr::JNTY0023, loc,
                    ERROR_PARAMS(lPrefixValue->getStringValue(),
                                 OPTIONS_KEY_PREFIX,
                                 "string"));
      }
      lPrefixValue->getStringValue2(lState->thePrefix);
    }
  }
  else
  {
    lState->thePrefix = ENCODE_DECODE_DEFAULT_PREFIX;
  }

  while (consumeNext(lInput, theChildren.at(0), aPlanState))
  {
    if (! decodeItem(lInput, aResult, lState))
    {
      aResult = lInput;
    }
    STACK_PUSH (true, lState);
  }

  STACK_END(lState);
}


/*******************************************************************************
  jn:encode-for-roundtrip($items as structured-item()*,
                          $options as object()) as json-item()*
********************************************************************************/
bool
JSONEncodeForRoundtripIterator::encodeObject(
  const store::Item_t& anObj,
  store::Item_t& aResult,
  JSONEncodeForRoundtripIteratorState* aState) const
{
  std::vector<store::Item_t> newNames;
  std::vector<store::Item_t> newValues;
  bool modified = false;

  store::Item_t key;
  store::Item_t value;
  store::Item_t newValue;
  store::Iterator_t it = anObj->getObjectKeys();
  it->open();
  while (it->next(key))
  {
    newNames.push_back(key);
    value = anObj->getObjectValue(key);
    const bool gotNew = encodeItem(value, newValue, aState);
    newValues.push_back(gotNew ? newValue : value);
    modified = modified || gotNew;
  }
  it->close();
  if (modified)
  {
    GENV_ITEMFACTORY->createJSONObject(aResult, newNames, newValues);
    return true;
  }
  // nothing to change, aResult is not set, the caller needs to use anObj
  return false;
}


bool
JSONEncodeForRoundtripIterator::encodeArray(
  const store::Item_t& anArray,
  store::Item_t& aResult,
  JSONEncodeForRoundtripIteratorState* aState) const
{
  std::vector<store::Item_t> newItems;
  bool modified = false;

  store::Item_t item, newItem;
  store::Iterator_t it = anArray->getArrayValues();
  it->open();
  while (it->next(item))
  {
    const bool gotNew = encodeItem(item, newItem, aState);
    newItems.push_back(gotNew ? newItem : item);
    modified = modified || gotNew;
  }
  it->close();
  if (modified)
  {
    GENV_ITEMFACTORY->createJSONArray(aResult, newItems);
    return true;
  }
  // nothing to change, aResult is not set, the caller needs to use anArray
  return false;
}


bool
JSONEncodeForRoundtripIterator::encodeAtomic(
  const store::Item_t& aValue,
  store::Item_t& aResult,
  JSONEncodeForRoundtripIteratorState* aState) const
{
  store::SchemaTypeCode typeCode = aValue->getTypeCode();
  switch (typeCode)
  {
  case store::XS_DOUBLE:
  case store::XS_FLOAT:
  {
    if (aValue->getBaseItem() == NULL
        && ! aValue->isNaN() && ! aValue->isPosOrNegInf())
    {
      // nothing to change, aResult is not set, the caller needs to use aValue
      return false;
    }
    break;
  }
  case store::XS_STRING:
  case store::XS_INTEGER:
  case store::XS_DECIMAL:
  case store::XS_BOOLEAN:
  case store::JS_NULL:
  {
    if (aValue->getBaseItem() == NULL)
    {
      // nothing to change, aResult is not set, the caller needs to use aValue
      return false;
    }
    break;
  }
  default:
    break;
  }

  std::vector<store::Item_t> names(2);
  std::vector<store::Item_t> values(2);

  {
    const store::Item_t& typeName = aValue->getType();

    zstring typeKey = aState->thePrefix + TYPE_KEY;
    const zstring ns = typeName->getNamespace();
    const zstring local = typeName->getLocalName();
    zstring typeValue = ns.compare(XS_URI)
        ? "Q{" + ns + "}" + local : "xs:" + local;

    GENV_ITEMFACTORY->createString(names.at(0), typeKey);
    GENV_ITEMFACTORY->createString(values.at(0), typeValue);
  }

  {
    zstring valueKey = aState->thePrefix + VALUE_KEY;
    zstring valueValue;
    if (typeCode == store::XS_QNAME)
    {
      // QNames are a special case, as the prefix should be maintained as well
      // but it's not part of the EQName serialization
      zstring prefixValue = aValue->getPrefix();
      if (prefixValue.length() > 0)
      {
        zstring prefixKey = aState->thePrefix + NS_PREFIX_KEY;
        store::Item_t lItem;
        GENV_ITEMFACTORY->createString(lItem, prefixKey);
        names.push_back(lItem);
        GENV_ITEMFACTORY->createString(lItem, prefixValue);
        values.push_back(lItem);
      }

      const zstring ns = aValue->getNamespace();
      const zstring local = aValue->getLocalName();
      valueValue = ns.empty() ? local : "Q{" + ns + "}" + local;
    }
    else
    {
      aValue->getStringValue2(valueValue);
    }
    GENV_ITEMFACTORY->createString(names.at(1), valueKey);
    GENV_ITEMFACTORY->createString(values.at(1), valueValue);
  }

  GENV_ITEMFACTORY->createJSONObject(aResult, names, values);
  return true;
}


bool
JSONEncodeForRoundtripIterator::encodeNode(
    const store::Item_t& aNode,
    store::Item_t& aResult,
    JSONEncodeForRoundtripIteratorState* aState) const
{
  std::vector<store::Item_t> names(2);
  std::vector<store::Item_t> values(2);

  {
    zstring typeKey = aState->thePrefix + TYPE_KEY;
    zstring typeValue = kind2str(aNode->getNodeKind());
    GENV_ITEMFACTORY->createString(names.at(0), typeKey);
    GENV_ITEMFACTORY->createString(values.at(0), typeValue);
  }

  {
    zstring valueKey = aState->thePrefix + VALUE_KEY;

    store::Iterator_t lItemIt = new ItemIterator(aNode);
    zorba::serializer lSerializer(aState->theDiag);
    // TODO what do we set, if nothing is passed?
    lSerializer.setParameter("omit-xml-declaration", "yes");

    if (! aState->theSerParams.isNull())
    {
      FnSerializeIterator::setSerializationParams(
          lSerializer,
          aState->theSerParams,
          theSctx,
          loc);
    }

    // and now serialize
    std::unique_ptr<std::stringstream> lResultStream(new std::stringstream());
    lItemIt->open();
    lSerializer.serialize(lItemIt, *lResultStream.get());
    lItemIt->close();

    GENV_ITEMFACTORY->createString(names.at(1), valueKey);
    GENV_ITEMFACTORY->createStreamableString(
        values.at(1), *lResultStream.get(),
        FnSerializeIterator::streamReleaser, true);
    lResultStream.release();
  }

  GENV_ITEMFACTORY->createJSONObject(aResult, names, values);
  return true;
}


bool
JSONEncodeForRoundtripIterator::encodeItem(
  const store::Item_t& anItem,
  store::Item_t& aResult,
  JSONEncodeForRoundtripIteratorState* aState) const
{
  if (anItem->isObject())
  {
    return encodeObject(anItem, aResult, aState);
  }
  else if (anItem->isArray())
  {
    return encodeArray(anItem, aResult, aState);
  }
  else if (anItem->isAtomic())
  {
    return encodeAtomic(anItem, aResult, aState);
  }
  else
  {
    return encodeNode(anItem, aResult, aState);
  }
}


bool
JSONEncodeForRoundtripIterator::nextImpl(
  store::Item_t& aResult,
  PlanState& aPlanState) const
{
  store::Item_t lInput;

  JSONEncodeForRoundtripIteratorState* lState;
  DEFAULT_STACK_INIT(JSONEncodeForRoundtripIteratorState, lState, aPlanState);

  lState->thePrefix = ENCODE_DECODE_DEFAULT_PREFIX;
  lState->theDiag = aPlanState.theCompilerCB->theXQueryDiagnostics;

  // get encoding parameters
  if (theChildren.size() == 2)
  {
    // the signature says that the second parameter has to be exactly one object
    store::Item_t lEncParams;
    consumeNext(lEncParams, theChildren.at(1), aPlanState);
    store::Item_t lPrefixKey;
    zstring lPrefixNameStr = OPTIONS_KEY_PREFIX;
    GENV_ITEMFACTORY->createString(lPrefixKey, lPrefixNameStr);
    store::Item_t lPrefixValue = lEncParams->getObjectValue(lPrefixKey);
    if (! lPrefixValue.isNull())
    {
      if (lPrefixValue->getTypeCode() != store::XS_STRING)
      {
        RAISE_ERROR(jerr::JNTY0023, loc,
                    ERROR_PARAMS(lPrefixValue->getStringValue(),
                                 OPTIONS_KEY_PREFIX,
                                 "string"));
      }
      lPrefixValue->getStringValue2(lState->thePrefix);
    }

    store::Item_t lSerParamKey;
    zstring lSerParamNameStr = OPTIONS_KEY_SER_PARAMS;
    GENV_ITEMFACTORY->createString(lSerParamKey, lSerParamNameStr);
    store::Item_t lSerParamValue = lEncParams->getObjectValue(lSerParamKey);
    if (! lSerParamValue.isNull())
    {
      if (! lSerParamValue->isNode()
          || lSerParamValue->getNodeKind() != store::StoreConsts::elementNode)
      {
        RAISE_ERROR(jerr::JNTY0023, loc,
                    ERROR_PARAMS(lSerParamValue->getStringValue(),
                                 OPTIONS_KEY_SER_PARAMS,
                                 ZED(ElementNode)));
      }
      lState->theSerParams = lSerParamValue;
    }
  }

  while(consumeNext(lInput, theChildren.at(0), aPlanState))
  {
    if (! encodeItem(lInput, aResult, lState))
    {
      aResult = lInput;
    }
    STACK_PUSH (true, lState);
  }
  STACK_END(lState);
}


/*******************************************************************************
  fn-jsoniq:parse-json(source as xs:string?) as json-item()*

  fn-jsoniq:parse-json(source as xs:string?, $options as $object()) as json-item()*
********************************************************************************/
void JSONParseIteratorState::init(PlanState& aState)
{
  PlanIteratorState::init(aState);
  theAllowMultiple = true; // default
  theInputStream = nullptr;
  theGotOne = false;
  loader_ = nullptr;
}


void JSONParseIteratorState::reset(PlanState& aState)
{
  PlanIteratorState::reset(aState);
  if (theInput == NULL)
  {
    delete theInputStream;
    theInputStream = nullptr;
  }
  theGotOne = false;
  delete loader_;
  loader_ = nullptr;
}


JSONParseIteratorState::~JSONParseIteratorState()
{
  if (theInput == NULL)
    delete theInputStream;

  delete loader_;
}


bool JSONParseIterator::processBooleanOption(
    const store::Item_t& options,
    char const *option_name,
    bool* option_value) const
{
  store::Item_t i_option_name;
  zstring z_option_name( option_name );

  GENV_ITEMFACTORY->createString( i_option_name, z_option_name );

  store::Item_t i_option_value = options->getObjectValue( i_option_name );

  if ( i_option_value )
  {
    store::SchemaTypeCode const option_type = i_option_value->getTypeCode();

    if ( !TypeOps::is_subtype( option_type, store::XS_BOOLEAN ) )
    {
      TypeManager const *const tm = theSctx->get_typemanager();
      xqtref_t const option_type = tm->create_value_type( i_option_value, loc );

      RAISE_ERROR(jerr::JNTY0020, loc,
      ERROR_PARAMS(option_type->toSchemaString(), z_option_name, "xs:boolean"));
    }
    *option_value = i_option_value->getBooleanValue();
    return true;
  }
  return false;
}


bool JSONParseIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t lInput;
  bool lStripTopLevelArray = false;
  char const *stream_uri;

  JSONParseIteratorState* state;
  DEFAULT_STACK_INIT(JSONParseIteratorState, state, planState);

  if (consumeNext(lInput, theChildren[0].getp(), planState))
  {
    if (theChildren.size() == 2)
    {
      store::Item_t lOptions;
      consumeNext(lOptions, theChildren[1].getp(), planState);
      processBooleanOption(
        lOptions, "jsoniq-multiple-top-level-items", &state->theAllowMultiple
      );
      processBooleanOption(
        lOptions, "jsoniq-strip-top-level-array", &lStripTopLevelArray
      );
    }

    if (lInput->isStreamable())
    {
      state->theInput = lInput;
      state->theInputStream = &lInput->getStream();
      stream_uri = get_uri( *state->theInputStream );
    }
    else
    {
      // will be deleted in the state
      state->theInputStream =
        new std::stringstream( lInput->getStringValue().c_str() );
      stream_uri = nullptr;
    }

    state->loader_ = new json::loader(
      *state->theInputStream, true, lStripTopLevelArray
    );

    if ( state->theInput == NULL && theRelativeLocation )
    {
      // pass the query location of the StringLiteral to the JSON
      // parser such that it can give better error locations.
      state->loader_->set_loc(
        theRelativeLocation.getFilename().c_str(),
        theRelativeLocation.getLineBegin(),
        theRelativeLocation.getColumnBegin()
      );
    }

    if ( stream_uri )
      state->loader_->set_loc( stream_uri, 1, 1 );

    while ( state->loader_->next( &result ) )
    {
      if ( !state->theAllowMultiple && state->theGotOne )
      {
        throw XQUERY_EXCEPTION(
          jerr::JNDY0021,
          ERROR_PARAMS( ZED( JNDY0021_UnexpectedExtraContent ) ),
          ERROR_LOC( loc )
        );
      }
      state->theGotOne = true;
      STACK_PUSH( true, state );
    }
  }
  STACK_END(state);
}


/*******************************************************************************
  jn:keys($o as item()*) as xs:string*
********************************************************************************/
void MultiObjectKeysIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theUniqueKeys.reset(new HashSet<zstring, HashMapZStringCmp>(64, false));
}


void MultiObjectKeysIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theUniqueKeys->clear();
}


bool MultiObjectKeysIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  store::Item_t obj1;
  store::Item_t obj2;
  zstring key;

  MultiObjectKeysIteratorState* state;
  DEFAULT_STACK_INIT(MultiObjectKeysIteratorState, state, planState);

  // skip non-objects
  while (consumeNext(item, theChild.getp(), planState))
  {
    if (item->isObject())
    {
      obj1.transfer(item);
      break;
    }
  }

  if (obj1)
  {
    // skip non-objects
    while (consumeNext(item, theChild.getp(), planState))
    {
      if (item->isObject())
      {
        obj2.transfer(item);
        break;
      }
    }

    if (obj2)
    {
      state->theSecondObj.transfer(obj2);

      // Return and record the keys of the 1st obj
      state->theObjKeysIte = obj1->getObjectKeys();
      state->theObjKeysIte->open();
          
      while (state->theObjKeysIte->next(result))
      {
        key = result->getStringValue();
        state->theUniqueKeys->insert(key);
        STACK_PUSH(true, state);
      }

      // Conditionally return and record the keys of the 2nd obj
      state->theObjKeysIte = state->theSecondObj->getObjectKeys();
      state->theObjKeysIte->open();
          
      while (state->theObjKeysIte->next(result))
      {
        key = result->getStringValue();
            
        if (!state->theUniqueKeys->exists(key))
        {
          state->theUniqueKeys->insert(key);
          STACK_PUSH(true, state);
        }
      }

      state->theObjKeysIte = NULL;

      // Conditionally return and record the keys of the subsequent objs, if any
      while (consumeNext(item, theChild.getp(), planState))
      {
        if (item->isObject())
        {
          state->theObjKeysIte = item->getObjectKeys();
          state->theObjKeysIte->open();
          
          while (state->theObjKeysIte->next(result))
          {
            key = result->getStringValue();
            
            if (!state->theUniqueKeys->exists(key))
            {
              state->theUniqueKeys->insert(key);
              STACK_PUSH(true, state);
            }
          }
          
          state->theObjKeysIte = NULL;
        }
      }
    }
    else
    {
      state->theObjKeysIte = obj1->getObjectKeys();
      state->theObjKeysIte->open();
          
      while (state->theObjKeysIte->next(result))
      {
        STACK_PUSH(true, state);
      }
      
      state->theObjKeysIte = NULL;
    }
  }

  STACK_END(state);
}


/*******************************************************************************
  op-zorba:keys($o as item()?) as xs:string*
********************************************************************************/
bool SingleObjectKeysIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t input;

  SingleObjectKeysIteratorState* state;
  DEFAULT_STACK_INIT(SingleObjectKeysIteratorState, state, planState);

  if (consumeNext(input, theChild.getp(), planState))
  {
    if (input->isObject())
    {
      state->theObjKeysIte = input->getObjectKeys();
      state->theObjKeysIte->open();

      while (state->theObjKeysIte->next(result))
      {
        STACK_PUSH (true, state);
      }
      state->theObjKeysIte = NULL;
    }
  }

  STACK_END(state);
}


bool SingleObjectKeysIterator::count(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t obj;
  xs_integer count(0);

  SingleObjectKeysIteratorState* state;
  DEFAULT_STACK_INIT(SingleObjectKeysIteratorState, state, planState);

  if (consumeNext(obj, theChild.getp(), planState))
  {
    if (obj->isObject())
    {
      count = obj->getNumObjectPairs();
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, count), state);
  STACK_END(state);
}


/*******************************************************************************
  op-zorba:multi-object-lookup($o as item()*, $name as item()?) as item()*

  Note: the translator always wraps the $name param to a [cast as xs:string?]
  expr, so we don's have to check the type of the selector item here.
********************************************************************************/
bool MultiObjectLookupIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t input;

  MultiObjectLookupIteratorState* state;
  DEFAULT_STACK_INIT(MultiObjectLookupIteratorState, state, planState);

  if (consumeNext(state->theKey, theChild1.getp(), planState))
  {
    while (consumeNext(input, theChild0.getp(), planState))
    {
      if (input->isObject())
      {
        result = input->getObjectValue(state->theKey);
        
        if (result)
          STACK_PUSH(true, state);
      }
    }
  }

  STACK_END(state);
}


/*******************************************************************************
  op-zorba:single-object-lookup($o as item()?, $name as item()?) as item()?

  Note: the translator always wraps the $name param to a [cast as xs:string?]
  expr, so we don's have to check the type of the selector item here.
********************************************************************************/
bool SingleObjectLookupIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t input;
  store::Item_t name;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(input, theChild0.getp(), planState))
  {
    if (input->isObject())
    {
      if (consumeNext(name, theChild1.getp(), planState))
      {
        result = input->getObjectValue(name);
        
        STACK_PUSH(result != NULL, state);
      }
    }
  }

  STACK_END(state);
}


/*******************************************************************************
  jn:project($items as item()*, $names as xs:string*) as item()*
********************************************************************************/
bool JSONObjectProjectIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t key;
  store::Iterator_t keysIte;
  store::Item_t value;
  csize numKeys = 0;
  store::CopyMode copymode;
  std::vector<store::Item_t> newKeys;
  std::vector<store::Item_t> newValues;
  csize i;

  JSONObjectProjectIteratorState* state;
  DEFAULT_STACK_INIT(JSONObjectProjectIteratorState, state, planState);

  state->theFilterKeys.clear();

  while (consumeNext(key, theChild1.getp(), planState))
  {
    ++numKeys;
    state->theFilterKeys.resize(numKeys);
    state->theFilterKeys[numKeys - 1].transfer(key);
  }

  while (consumeNext(result, theChild0.getp(), planState))
  {
    if (result->isObject())
    {
      numKeys = state->theFilterKeys.size();

      keysIte = result->getObjectKeys();
      keysIte->open();

      while (keysIte->next(key))
      {
        for (i = 0; i < numKeys; ++i)
        {
          if (state->theFilterKeys[i]->getStringValue() == key->getStringValue())
            break;
        }
        
        if (i < numKeys)
        {
          value = result->getObjectValue(key);
          
          if (value->isStructuredItem())
            value = value->copy(NULL, copymode);
          
          newValues.push_back(value);
          newKeys.push_back(key);
        }
      }

      keysIte->close();

      GENV_ITEMFACTORY->createJSONObject(result, newKeys, newValues);
    }

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


/*******************************************************************************
  jn:trim($items as item()*, $names as xs:string*) as item()*
********************************************************************************/
bool JSONObjectTrimIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t key;
  store::Iterator_t keysIte;
  store::Item_t value;
  csize numKeys = 0;
  store::CopyMode copymode;
  std::vector<store::Item_t> newKeys;
  std::vector<store::Item_t> newValues;
  csize i;

  JSONObjectTrimIteratorState* state;
  DEFAULT_STACK_INIT(JSONObjectTrimIteratorState, state, planState);

  state->theFilterKeys.clear();

  while (consumeNext(key, theChild1.getp(), planState))
  {
    ++numKeys;
    state->theFilterKeys.resize(numKeys);
    state->theFilterKeys[numKeys - 1].transfer(key);
  }

  while (consumeNext(result, theChild0.getp(), planState))
  {
    if (result->isObject())
    {
      numKeys = state->theFilterKeys.size();

      keysIte = result->getObjectKeys();
      keysIte->open();

      while (keysIte->next(key))
      {
        for (i = 0; i < numKeys; ++i)
        {
          if (state->theFilterKeys[i]->getStringValue() == key->getStringValue())
            break;
        }
        
        if (i >= numKeys)
        {
          value = result->getObjectValue(key);
          
          if (value->isStructuredItem())
            value = value->copy(NULL, copymode);
          
          newValues.push_back(value);
          newKeys.push_back(key);
        }
      }

      keysIte->close();

      GENV_ITEMFACTORY->createJSONObject(result, newKeys, newValues);
    }

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}



/*******************************************************************************
  jn:members($a as item()*) as item()*
********************************************************************************/
bool MultiArrayMembersIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t array;

  MultiArrayMembersIteratorState* state;
  DEFAULT_STACK_INIT(MultiArrayMembersIteratorState, state, planState);

  while (consumeNext(array, theChild.getp(), planState))
  {
    if (array->isArray())
    {
      state->theMembers = array->getArrayValues();

      state->theMembers->open();
      while (state->theMembers->next(result))
      {
        STACK_PUSH(true, state);
      }
      state->theMembers->close();
    }
  }

  STACK_END(state);
}


bool MultiArrayMembersIterator::count(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t array;
  xs_integer count(0);

  MultiArrayMembersIteratorState* state;
  DEFAULT_STACK_INIT(MultiArrayMembersIteratorState, state, planState);

  while (consumeNext(array, theChild.getp(), planState))
  {
    if (array->isArray())
    {
      count += array->getArraySize();
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, count), state);
  STACK_END(state);
}


/*******************************************************************************
  op-zorba:members($a as item()?) as item()*
********************************************************************************/
bool SingleArrayMembersIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t array;

  SingleArrayMembersIteratorState* state;
  DEFAULT_STACK_INIT(SingleArrayMembersIteratorState, state, planState);

  if (consumeNext(array, theChild.getp(), planState))
  {
    if (array->isArray())
    {
      state->theMembers = array->getArrayValues();

      state->theMembers->open();
      while (state->theMembers->next(result))
      {
        STACK_PUSH(true, state);
      }
      state->theMembers->close();
    }
  }

  STACK_END(state);
}


bool SingleArrayMembersIterator::count(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t array;
  xs_integer count(0);

  SingleArrayMembersIteratorState* state;
  DEFAULT_STACK_INIT(SingleArrayMembersIteratorState, state, planState);

  if (consumeNext(array, theChild.getp(), planState))
  {
    if (array->isArray())
    {
      count = array->getArraySize();
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, count), state);

  STACK_END(state);
}


/*******************************************************************************
  op-zorba:mutli-array-lookup($a as item()*, $pos as item()?) as item()*

  Note: the translator always wraps the $pos param to a [cast as xs:integer?]
  expr, so we don's have to check the type of the selector item here.
********************************************************************************/
bool MultiArrayLookupIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t input;

  MultiArrayLookupIteratorState* state;
  DEFAULT_STACK_INIT(MultiArrayLookupIteratorState, state, planState);

  if (consumeNext(state->thePosition, theChild1.getp(), planState))
  {
    while (consumeNext(input, theChild0.getp(), planState))
    {
      if (input->isArray())
      {
        result = input->getArrayValue(state->thePosition->getIntegerValue());

        if (result)
          STACK_PUSH(true, state);
      }
    }
  }

  STACK_END(state);
}


/*******************************************************************************
  op-zorba:single-array-lookup($a as item()?, $pos as item()?) as item()?

  Note: the translator always wraps the $pos param to a [cast as xs:integer?]
  expr, so we don's have to check the type of the selector item here.
********************************************************************************/
bool SingleArrayLookupIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t input;
  store::Item_t position;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(input, theChild0.getp(), planState))
  {
    if (input->isArray())
    {
      if (consumeNext(position, theChild1.getp(), planState))
      {
        result = input->getArrayValue(position->getIntegerValue());
        
        STACK_PUSH(result != 0, state);
      }
    }
  }

  STACK_END(state);
}


/*******************************************************************************
  jn:size($i as array()?) as xs:integer?
********************************************************************************/
bool JSONArraySizeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  xs_integer size;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChild.getp(), planState))
  {
    size = item->getArraySize();

    STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, size), state);
  }

  STACK_END(state);
}


/*******************************************************************************
  jn:flatten($items as item()*) as item()*
********************************************************************************/
void JSONArrayFlattenIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  while (!theStack.empty())
  {
    theStack.pop();
  }
}


bool JSONArrayFlattenIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  bool foundArray = false;

  JSONArrayFlattenIteratorState* state;
  DEFAULT_STACK_INIT(JSONArrayFlattenIteratorState, state, planState);

  while (consumeNext(result, theChild.getp(), planState))
  {
    if (result->isArray())
    {
      state->theStack.push(result->getArrayValues());

      state->theStack.top()->open();

      while (!state->theStack.empty())
      {
        while (state->theStack.top()->next(result))
        {
          if (result->isArray())
          {
            state->theStack.push(result->getArrayValues());
            state->theStack.top()->open();

            foundArray = true;
            break;
          }
      
          STACK_PUSH(true, state);
        }
    
        if (foundArray)
        {
          foundArray = false;
          continue;
        }
    
        state->theStack.top()->close();
        state->theStack.pop();
      }
    }
    else
    {
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


/*******************************************************************************
  jn:null() as jn:null
********************************************************************************/
bool JSONNullIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  STACK_PUSH(GENV_ITEMFACTORY->createJSONNull(result), state);

  STACK_END(state);
}


#if 0
/*******************************************************************************
  jn:is-null(xs:anyAtomicType) as xs:boolean
********************************************************************************/
bool JSONIsNullIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  PlanIteratorState* state;
  store::Item_t lItem;
  bool lIsNull;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lItem, theChild.getp(), planState);

  lIsNull = (lItem->getTypeCode() == store::JS_NULL);

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, lIsNull), state);

  STACK_END(state);
}
#endif


/*******************************************************************************
  updating function op-zorba:object-insert(
      $o as object(),
      $c as object())
********************************************************************************/
bool JSONObjectInsertIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t target;
  store::Item_t content;
  store::PUL_t pul;
  store::CopyMode copymode;
  PlanIteratorState* state;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(target, theChildren[0].getp(), planState);

  consumeNext(content, theChildren[1].getp(), planState);

  copymode.set(true,
               theSctx->construction_mode() == StaticContextConsts::cons_preserve,
               theSctx->preserve_ns(),
               theSctx->inherit_ns());

  if (content->isStructuredItem())
  {
    content = content->copy(NULL, copymode);
  }

  pul = GENV_ITEMFACTORY->createPendingUpdateList();

  pul->addJSONObjectInsert(&loc, target, content);

  result.transfer(pul);

  STACK_PUSH(true, state);

  STACK_END(state);
}


/*******************************************************************************
  updating function op-zorba:array-insert(
      $o as array(),
      $pos as xs:integer, 
      $values as item()*, 
********************************************************************************/
bool JSONArrayInsertIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t array;
  store::Item_t member;
  store::Item_t pos;
  std::vector<store::Item_t> members;
  store::PUL_t pul;
  store::CopyMode copymode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(array, theChildren[0].getp(), planState);
  consumeNext(pos, theChildren[1].getp(), planState);

  copymode.set(true, 
               theSctx->construction_mode() == StaticContextConsts::cons_preserve,
               theSctx->preserve_ns(),
               theSctx->inherit_ns());

  while (consumeNext(member, theChildren[2].getp(), planState))
  {
    if (member->isStructuredItem())
    {
      member = member->copy(NULL, copymode);
    }

    members.resize(members.size() + 1);
    members.back().transfer(member);
  }

  pul = GENV_ITEMFACTORY->createPendingUpdateList();

  pul->addJSONArrayInsert(&loc, array, pos, members);

  result.transfer(pul);

  STACK_PUSH(true, state);

  STACK_END (state);
}


/*******************************************************************************
  updating function op-zorba:array-append(
      $o as array(),
      $values as item()*) 
********************************************************************************/
bool JSONArrayAppendIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t array;
  store::Item_t member;
  std::vector<store::Item_t> members;
  store::PUL_t pul;
  store::CopyMode copymode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(array, theChildren[0].getp(), planState);

  copymode.set(true, 
               theSctx->construction_mode() == StaticContextConsts::cons_preserve,
               theSctx->preserve_ns(),
               theSctx->inherit_ns());

  while (consumeNext(member, theChildren[1].getp(), planState))
  {
    if (member->isStructuredItem())
    {
      member = member->copy(NULL, copymode);
    }

    members.resize(members.size() + 1);
    members.back().transfer(member);
  }

  pul = GENV_ITEMFACTORY->createPendingUpdateList();

  pul->addJSONArrayAppend(&loc, array, members);

  result.transfer(pul);

  STACK_PUSH(true, state);

  STACK_END (state);
}


/*******************************************************************************
  updating function op-zorba:json-delete(
      $target as item()*,
      $selector as xs:anyAtomicType?) 
********************************************************************************/
bool JSONDeleteIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t target;
  store::Item_t selector;
  store::PUL_t pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(selector, theChild1.getp(), planState))
  {
    pul = GENV_ITEMFACTORY->createPendingUpdateList();

    while (consumeNext(target, theChild0.getp(), planState))
    {
      if (target->isObject())
      {
        pul->addJSONObjectDelete(&loc, target, selector);
      }
      else if (target->isArray())
      {
        store::SchemaTypeCode selectorType = selector->getTypeCode();

        if (!TypeOps::is_subtype(selectorType, store::XS_INTEGER))
        {
          GenericCast::castToBuiltinAtomic(selector,
                                           selector,
                                           store::XS_INTEGER,
                                           NULL,
                                           loc);
        }

        pul->addJSONArrayDelete(&loc, target, selector);
      }
    }
     
    result.transfer(pul);

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


/*******************************************************************************
  updating function op-zorba:replace-value(
      $target as item()*,
      $selector as xs:anyAtomicType?, 
      $newValue as item()) 
********************************************************************************/
JSONReplaceValueIterator::JSONReplaceValueIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    bool copyInput)
  :
  NaryBaseIterator<JSONReplaceValueIterator, PlanIteratorState>(sctx, loc, args)
{
  if (theChildren[2]->isConstructor())
  {
    theCopyInput = false;
  }
  else
  {
    theCopyInput = copyInput;
  }
}


bool JSONReplaceValueIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t target;
  store::Item_t selector;
  store::Item_t newValue;
  store::PUL_t pul;
  store::CopyMode copymode;
  bool copyInput = theCopyInput;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(selector, theChildren[1].getp(), planState))
  {
    pul = GENV_ITEMFACTORY->createPendingUpdateList();

    consumeNext(newValue, theChildren[2].getp(), planState);

    while (consumeNext(target, theChildren[0].getp(), planState))
    {
      if (copyInput && (newValue->isStructuredItem()))
      {
        copymode.set(true,
                     theSctx->construction_mode() == StaticContextConsts::cons_preserve,
                     theSctx->preserve_ns(),
                     theSctx->inherit_ns());
        
        newValue = newValue->copy(NULL, copymode);
      }

      copyInput = true;

      if (target->isObject())
      {
        pul->addJSONObjectReplaceValue(&loc, target, selector, newValue);
      }
      else if (target->isArray())
      {
        store::SchemaTypeCode selectorType = selector->getTypeCode();

        if (!TypeOps::is_subtype(selectorType, store::XS_INTEGER))
        {
          GenericCast::castToBuiltinAtomic(selector,
                                           selector,
                                           store::XS_INTEGER,
                                           NULL,
                                           loc);
        }

        pul->addJSONArrayReplaceValue(&loc, target, selector, newValue);
      }
    }

    result.transfer(pul);

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


/*******************************************************************************
  updating function op-zorba:object-rename(
      $o as item()*,
      $name as xs:string?, 
      $newName as xs:string) 
********************************************************************************/
bool JSONRenameIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t target;
  store::Item_t name;
  store::Item_t newName;
  store::PUL_t pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(name, theChildren[1].getp(), planState))
  {
    consumeNext(newName, theChildren[2].getp(), planState);

    pul = GENV_ITEMFACTORY->createPendingUpdateList();

    while(consumeNext(target, theChildren[0].getp(), planState))
    {
      if (target->isObject())
        pul->addJSONObjectRename(&loc, target, name, newName);
    }

    result.transfer(pul);

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool JSONBoxIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t value1;
  store::Item_t value2;
  store::Item_t value;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(value1, theChild, planState))
  {
    GENV_STORE.getItemFactory()->createJSONNull(result);
  }
  else if (!consumeNext(value2, theChild, planState))
  {
    result.transfer(value1);
  }
  else
  {
    store::CopyMode copymode;
    copymode.set(false, true, true, true);

    store::Iterator_t wrapper = new PlanIteratorWrapper(theChild, planState);

    GENV_STORE.getItemFactory()->
    createJSONArray(result, value1, value2, wrapper, copymode);
  }

  STACK_PUSH(true, state);
  STACK_END(state);
}



} /* namespace zorba */

/* vim:set et sw=2 ts=2: */
