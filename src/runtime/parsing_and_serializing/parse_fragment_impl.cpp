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

#include "system/globalenv.h"

#include "types/schema/schema.h"
#include "types/schema/validate.h"

namespace zorba
{

/*******************************************************************************
  14.9.1 fn-zorba-xml:parse-xml-fragment
********************************************************************************/

class ParseXmlFragmentOptions
{
public:
  // all options are false by default, except for enableFatelErrorProcessing which is true
  bool enableExternalEntitiesProcessing;
  bool enableRootNodesSkipping;
  unsigned int rootNodesToSkip;
  bool enableDTDValidation;
  bool enableStrictSchemaValidation;
  bool enableLaxSchemaValidation;
  bool enableWhitespaceStripping;
  bool enableFatelErrorProcessing;

public:
  ParseXmlFragmentOptions() :
    enableExternalEntitiesProcessing(false),
    enableRootNodesSkipping(false),
    rootNodesToSkip(0),
    enableDTDValidation(false),
    enableStrictSchemaValidation(false),
    enableLaxSchemaValidation(false),
    enableWhitespaceStripping(false),
    enableFatelErrorProcessing(true)   // only enableFatelErrorProcessing is set to true
  {
  }

  void reset()
  {
    enableExternalEntitiesProcessing = false;
    enableRootNodesSkipping = false;
    rootNodesToSkip = 0;
    enableDTDValidation = false;
    enableStrictSchemaValidation = false;
    enableLaxSchemaValidation = false;
    enableWhitespaceStripping = false;
    enableFatelErrorProcessing = true;    // only enableFatelErrorProcessing is set to true
  }

  static ParseXmlFragmentOptions parseOptions(const zstring& options, const QueryLoc& loc)
  {
    ParseXmlFragmentOptions opt;

    if (options.find("e") != zstring::npos && options.find("E") != zstring::npos)
      throw XQUERY_EXCEPTION(zerr::ZXQD0003_INCONSISTENT_PARSE_FRAGMENT_OPTIONS,
                ERROR_PARAMS(ZED(ParseFragmentOptionCombinationNotAllowed), "e", "E"), ERROR_LOC( loc ));

    if (options.find("d") != zstring::npos && options.find("D") != zstring::npos)
      throw XQUERY_EXCEPTION(zerr::ZXQD0003_INCONSISTENT_PARSE_FRAGMENT_OPTIONS,
                ERROR_PARAMS(ZED(ParseFragmentOptionCombinationNotAllowed), "d", "D"), ERROR_LOC( loc ));

    if (options.find("s") != zstring::npos && options.find("S") != zstring::npos)
      throw XQUERY_EXCEPTION(zerr::ZXQD0003_INCONSISTENT_PARSE_FRAGMENT_OPTIONS,
                ERROR_PARAMS(ZED(ParseFragmentOptionCombinationNotAllowed), "s", "S"), ERROR_LOC( loc ));

    if (options.find("l") != zstring::npos && options.find("L") != zstring::npos)
      throw XQUERY_EXCEPTION(zerr::ZXQD0003_INCONSISTENT_PARSE_FRAGMENT_OPTIONS,
                ERROR_PARAMS(ZED(ParseFragmentOptionCombinationNotAllowed), "l", "L"), ERROR_LOC( loc ));

    if (options.find("w") != zstring::npos && options.find("W") != zstring::npos)
      throw XQUERY_EXCEPTION(zerr::ZXQD0003_INCONSISTENT_PARSE_FRAGMENT_OPTIONS,
                ERROR_PARAMS(ZED(ParseFragmentOptionCombinationNotAllowed), "w", "W"), ERROR_LOC( loc ));

    if (options.find("f") != zstring::npos && options.find("F") != zstring::npos)
      throw XQUERY_EXCEPTION(zerr::ZXQD0003_INCONSISTENT_PARSE_FRAGMENT_OPTIONS,
                ERROR_PARAMS(ZED(ParseFragmentOptionCombinationNotAllowed), "f", "F"), ERROR_LOC( loc ));

    if (options.find("e") != zstring::npos)
      opt.enableExternalEntitiesProcessing = true;
    if (options.find("d") != zstring::npos)
      opt.enableDTDValidation = true;
    if (options.find("s") != zstring::npos)
      opt.enableStrictSchemaValidation = true;
    if (options.find("l") != zstring::npos)
      opt.enableLaxSchemaValidation = true;
    if (options.find("w") != zstring::npos)
      opt.enableWhitespaceStripping = true;
    if (options.find("f") != zstring::npos)
      opt.enableFatelErrorProcessing = true;

    if (options.find("E") != zstring::npos)
      opt.enableExternalEntitiesProcessing = false;
    if (options.find("D") != zstring::npos)
      opt.enableDTDValidation = false;
    if (options.find("S") != zstring::npos)
      opt.enableStrictSchemaValidation = false;
    if (options.find("L") != zstring::npos)
      opt.enableLaxSchemaValidation = false;
    if (options.find("W") != zstring::npos)
      opt.enableWhitespaceStripping = false;
    if (options.find("F") != zstring::npos)
      opt.enableFatelErrorProcessing = false;

    if (options.find("r") != zstring::npos)
    {
      opt.enableRootNodesSkipping = true;
      int pos = options.find("r") + 1;

      // TODO: catch range exception and add test for it
      opt.rootNodesToSkip = ztd::aton<unsigned int>(options.c_str() + pos);
    }

    // TODO: check that "r" option is enabled only if "e" is enabled

    if (opt.enableExternalEntitiesProcessing
        &&
        (opt.enableDTDValidation || opt.enableStrictSchemaValidation || opt.enableLaxSchemaValidation))
    {
      throw XQUERY_EXCEPTION(zerr::ZXQD0003_INCONSISTENT_PARSE_FRAGMENT_OPTIONS,
                ERROR_PARAMS(ZED(ParseFragmentOptionDSLNotAllowed)), ERROR_LOC( loc ));
    }

    return opt;
  }
};


/*******************************************************************************

********************************************************************************/

void FnParseXmlFragmentIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theFragmentStream.reset();
  theProperties.setEnableDtd(false);
  theProperties.setEnableExtParsedEntity(false);
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
  URI lValidatedBaseUri;
  store::Item_t tempItem;
  ParseXmlFragmentOptions parseOptions;
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

    // optional base URI argument
    if (theChildren.size() == 3)
    {
      consumeNext(result, theChildren[1].getp(), planState);
      ZORBA_ASSERT(result);

      try {
        lValidatedBaseUri = URI(result->getStringValue());
      } catch (ZorbaException const& /* e */) {
        throw XQUERY_EXCEPTION(
          err::FODC0007,
          ERROR_PARAMS( result->getStringValue() ),
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

      result->getStringValue2(state->baseUri);

      // read options
      consumeNext(tempItem, theChildren[2].getp(), planState);
      parseOptions = ParseXmlFragmentOptions::parseOptions(tempItem->getStringValue(), loc);

    } else {
      // read options
      consumeNext(tempItem, theChildren[1].getp(), planState);
      parseOptions = ParseXmlFragmentOptions::parseOptions(tempItem->getStringValue(), loc);

      state->baseUri = theSctx->get_base_uri();
    }

    // baseURI serves both as the base URI used by the XML parser
    // to resolve relative entity references within the document,
    // and as the base URI of the document node that is returned.
    state->docUri = state->baseUri;

    // The DTD and ExternalEntitiesProcessing options/props cannot both be true at the same time
    if (parseOptions.enableDTDValidation)
      state->theProperties.setEnableDtd(true);
    if (parseOptions.enableExternalEntitiesProcessing)
      state->theProperties.setEnableExtParsedEntity(true);
    state->theProperties.setStoreDocument(false);

    ////////////////////////////////////////////////////////////////////////
    // External parsed entity processing
    ////////////////////////////////////////////////////////////////////////
    if (state->theProperties.getEnableExtParsedEntity())
    {
      state->theFragmentStream.root_elements_to_skip = parseOptions.rootNodesToSkip;

      while (state->theFragmentStream.theBuffer == NULL
             ||
             state->theFragmentStream.current_offset < state->theFragmentStream.buffer_size)
      {
        try {
          result = lStore.loadDocument(state->baseUri, state->docUri, state->theFragmentStream, state->theProperties);
        } catch (ZorbaException const& e) {
          if (parseOptions.enableFatelErrorProcessing)
            throw XQUERY_EXCEPTION( err::FODC0006, ERROR_PARAMS("parse-xml:parse-xml-fragment()", e.what()), ERROR_LOC( loc ));
          else
            result = NULL;
        }

        if (result != NULL)
        {
          state->theFragmentStream.children = result->getChildren();
          while (state->theFragmentStream.children->next(result) && result != NULL)
          {
            STACK_PUSH(true, state);
          }
        }

        /*
        // Skip document node if present
        if (result != NULL)
          result->getChildren()->next(result);

        if (result != NULL)
          STACK_PUSH(true, state);
        */
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
        if (parseOptions.enableFatelErrorProcessing)
          throw XQUERY_EXCEPTION( err::FODC0006, ERROR_PARAMS("parse-xml:parse-xml-fragment()", e.what()), ERROR_LOC( loc ));
        else
          result = NULL;
      }

      if (result != NULL)
      {
#ifndef ZORBA_NO_XMLSCHEMA
        if (parseOptions.enableStrictSchemaValidation || parseOptions.enableLaxSchemaValidation)
        {
          try
          {
            tempItem = NULL; // used as the effectiveValidationValue()'s typeName
            validated = Validator::effectiveValidationValue(
                          result,
                          result,
                          tempItem,
                          theSctx->get_typemanager(),
                          parseOptions.enableLaxSchemaValidation ? ParseConstants::val_lax : ParseConstants::val_strict,
                          theSctx,
                          this->loc);
          }
          catch (ZorbaException& /*e*/)
          {
            if (parseOptions.enableFatelErrorProcessing)
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

        if (result != NULL && validated && parseOptions.enableWhitespaceStripping)
        {
          // TODO: whitespace stripping
        }

        STACK_PUSH(validated, state);
      } // if (result != NULL)
    } // if (state->theProperties.getEnableExtParsedEntity())
  } // if (consumeNext(result, theChildren[0].getp(), planState))

  STACK_END(state);
}



} /* namespace zorba */
