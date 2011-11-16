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

#include "runtime/parsing_and_serializing/parse_fragment.h"

#include <iostream>

#include "zorbatypes/URI.h"
#include "context/static_context.h"

#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/load_properties.h"

#include "system/globalenv.h"

#include "types/schema/schema.h"
#include "types/schema/validate.h"


namespace zorba
{

/*******************************************************************************
  14.9.1 fn-zorba-xml:parse-xml-fragment
********************************************************************************/

store::Item_t getFirstAttribute(store::Item_t node)
{
  store::Item_t attr;
  store::Iterator_t attributes = node->getAttributes();
  attributes->open();
  attributes->next(attr);
  attributes->close();
  return attr;
}

void processOptions(store::Item_t item, store::LoadProperties& props, static_context* theSctx, const QueryLoc& loc)
{
  URI lValidatedBaseUri;
  store::Item_t child, tempItem;

  if (item.getp() == NULL)
    return;

  tempItem = NULL; // used as the effectiveValidationValue()'s typeName
  Validator::effectiveValidationValue(
      item,
      item,
      tempItem,
      theSctx->get_typemanager(),
      ParseConstants::val_strict,
      theSctx,
      loc);

  store::Iterator_t children = item->getChildren();
  children->open();

  while (children->next(child))
  {
    if (child->getNodeKind() != store::StoreConsts::elementNode)
      continue;

    if (child->getNodeName()->getLocalName() == "base-uri")
    {
      store::Item_t attr = getFirstAttribute(child);

      try {
        lValidatedBaseUri = URI(attr->getStringValue());
      } catch (ZorbaException const& /* e */) {
        throw XQUERY_EXCEPTION(
          err::FODC0007,
          ERROR_PARAMS( attr->getStringValue() ),
          ERROR_LOC( loc )
        );
      }

      if (!lValidatedBaseUri.is_absolute()) {
        throw XQUERY_EXCEPTION(
          err::FODC0007,
          ERROR_PARAMS( lValidatedBaseUri.toString() ),
          ERROR_LOC( loc )
        );
      }

      props.setBaseUri(attr->getStringValue());
    }
    else if (child->getNodeName()->getLocalName() == "noError")
      props.setNoError(true);
    else if (child->getNodeName()->getLocalName() == "stripWhitespace")
      props.setStripWhitespace(true);
    else if (child->getNodeName()->getLocalName() == "schemaValidate")
    {
      store::Item_t attr = getFirstAttribute(child);
      if (attr->getStringValue() == "strict")
        props.setSchemaStrictValidate(true);
      else
        props.setSchemaLaxValidate(true);
    }
    else if (child->getNodeName()->getLocalName() == "DTDValidate")
      props.setDTDValidate(true);
    else if (child->getNodeName()->getLocalName() == "DTDLoad")
      props.setDTDLoad(true);
    else if (child->getNodeName()->getLocalName() == "defaultDTDAttributes")
      props.setDefaultDTDAttributes(true);
    else if (child->getNodeName()->getLocalName() == "parseExternalParsedEntity")
    {
      props.setParseExternalParsedEntity(true);
      store::Item_t attr;
      store::Iterator_t attribs = child->getAttributes();
      attribs->open();
      while (attribs->next(attr))
      {
        if (attr->getNodeName()->getLocalName() == "skipRootNodes")
          props.setSkipRootNodes(ztd::aton<xs_int>(attr->getStringValue().c_str()));
        else if (attr->getNodeName()->getLocalName() == "skipTopLevelTextNodes")
          props.setSkipTopLevelTextNodes(true);
      }
      attribs->close();
    }
    else if (child->getNodeName()->getLocalName() == "substituteEntities")
      props.setSubstituteEntities(true);
    else if (child->getNodeName()->getLocalName() == "xincludeSubstitutions")
      props.setXincludeSubstitutions(true);
    else if (child->getNodeName()->getLocalName() == "removeRedundantNS")
      props.setRemoveRedundantNS(true);
    else if (child->getNodeName()->getLocalName() == "noCDATA")
      props.setNoCDATA(true);
    else if (child->getNodeName()->getLocalName() == "noXIncludeNodes")
      props.setNoXIncludeNodes(true);
  }

  children->close();
}

/*******************************************************************************

********************************************************************************/

void FnParseXmlFragmentIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theFragmentStream.reset();
  theProperties.reset();
  theProperties.setStoreDocument(false);
  baseUri = "";
  docUri = "";
}


/*******************************************************************************

********************************************************************************/

bool FnParseXmlFragmentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Store& lStore = GENV.getStore();
  zstring docString;
  store::Item_t tempItem;
  bool validated = true;

  FnParseXmlFragmentIteratorState* state;
  DEFAULT_STACK_INIT(FnParseXmlFragmentIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    if (result->isStreamable())
    {
      state->theFragmentStream.theStream = &result->getStream();
    }
    else
    {
      result->getStringValue2(docString);
      state->theFragmentStream.theIss = new std::istringstream(docString.c_str());
      state->theFragmentStream.theStream = state->theFragmentStream.theIss;
    }

    // read options
    consumeNext(tempItem, theChildren[1].getp(), planState);
    state->theProperties.setBaseUri(theSctx->get_base_uri());
    state->theProperties.setStoreDocument(false);
    processOptions(tempItem, state->theProperties, theSctx, loc);

    // baseURI serves both as the base URI used by the XML parser
    // to resolve relative entity references within the document,
    // and as the base URI of the document node that is returned.
    state->baseUri = state->theProperties.getBaseUri();
    state->docUri = state->theProperties.getBaseUri();


    ////////////////////////////////////////////////////////////////////////
    // External parsed entity processing
    ////////////////////////////////////////////////////////////////////////
    if (state->theProperties.getParseExternalParsedEntity())
    {
      state->theFragmentStream.root_elements_to_skip = state->theProperties.getSkipRootNodes();

      while (state->theFragmentStream.theBuffer == NULL
             ||
             state->theFragmentStream.current_offset < state->theFragmentStream.buffer_size)
      {
        try {
          result = lStore.loadDocument(state->baseUri, state->docUri, state->theFragmentStream, state->theProperties);
        } catch (ZorbaException const& e) {
          if ( ! state->theProperties.getNoError())
            throw XQUERY_EXCEPTION( err::FODC0006, ERROR_PARAMS("parse-xml:parse-xml()", e.what()), ERROR_LOC( loc ));
          else
            result = NULL;
        }

        if (result == NULL)
          continue;

        // Return the children of document node
        state->theFragmentStream.children = result->getChildren();
        while (state->theFragmentStream.children->next(result) && result != NULL)
        {
          if (state->theProperties.getSkipTopLevelTextNodes() && result->getNodeKind() == store::StoreConsts::textNode)
            continue;

          STACK_PUSH(true, state);
        }
      }
    }
    ////////////////////////////////////////////////////////////////////////
    // XML document processing
    ////////////////////////////////////////////////////////////////////////
    else  // if (!state->theProperties.getEnableExtParsedEntity())
    {
      try {
        result = lStore.loadDocument(state->baseUri, state->docUri, *state->theFragmentStream.theStream, state->theProperties);
      } catch (ZorbaException const& e) {
        if ( ! state->theProperties.getNoError())
          throw XQUERY_EXCEPTION( err::FODC0006, ERROR_PARAMS("parse-xml:parse-xml()", e.what()), ERROR_LOC( loc ));
        else
          result = NULL;
      }

      if (result != NULL)
      {
#ifndef ZORBA_NO_XMLSCHEMA
        if (state->theProperties.getSchemaLaxValidate() || state->theProperties.getSchemaStrictValidate())
        {
          try
          {
            tempItem = NULL; // used as the effectiveValidationValue()'s typeName
            validated = Validator::effectiveValidationValue(
                          result,
                          result,
                          tempItem,
                          theSctx->get_typemanager(),
                          state->theProperties.getSchemaLaxValidate() ? ParseConstants::val_lax : ParseConstants::val_strict,
                          theSctx,
                          this->loc);
          }
          catch (ZorbaException& /*e*/)
          {
            if ( ! state->theProperties.getNoError())
              throw;
            else
            {
              result = NULL;
              validated = false;
            }
          }
        }
#endif
        // Ignore the schema validation options if Zorba is built without schema support

        STACK_PUSH(validated, state);
      } // if (result != NULL)
    } // if (state->theProperties.getEnableExtParsedEntity())
  } // if (consumeNext(result, theChildren[0].getp(), planState))

  STACK_END(state);
}



} /* namespace zorba */
