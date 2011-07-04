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
  bool enableDTDValidation;
  bool enableStrictSchemaValidation;
  bool enableLaxSchemaValidation;
  bool enableWhitespaceStripping;
  bool enableFatelErrorProcessing;

public:
  ParseXmlFragmentOptions() :
    enableExternalEntitiesProcessing(false),
    enableDTDValidation(false),
    enableStrictSchemaValidation(false),
    enableLaxSchemaValidation(false),
    enableWhitespaceStripping(false),
    enableFatelErrorProcessing(true)   // only enableFatelErrorProcessing is set to true
  {
  }

  static ParseXmlFragmentOptions parseOptions(const zstring& options, const QueryLoc& loc)
  {
    ParseXmlFragmentOptions opt;

    if ((options.find("e") != zstring::npos && options.find("E") != zstring::npos)
        ||
        (options.find("d") != zstring::npos && options.find("D") != zstring::npos)
        ||
        (options.find("s") != zstring::npos && options.find("S") != zstring::npos)
        ||
        (options.find("l") != zstring::npos && options.find("L") != zstring::npos)
        ||
        (options.find("w") != zstring::npos && options.find("W") != zstring::npos)
        ||
        (options.find("f") != zstring::npos && options.find("F") != zstring::npos))
    {
      throw XQUERY_EXCEPTION(err::FODC0006, ERROR_PARAMS( "inconsistent options to the parse-xml-fragment() function" ), ERROR_LOC( loc ));
    }

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

    if (opt.enableExternalEntitiesProcessing
        &&
        (opt.enableDTDValidation || opt.enableStrictSchemaValidation || opt.enableLaxSchemaValidation))
    {
      throw XQUERY_EXCEPTION(err::FODC0006, ERROR_PARAMS( "inconsistent options to the parse-xml-fragment() function" ), ERROR_LOC( loc ));
    }

    return opt;
  }
};

bool FnParseXmlFragmentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Store& lStore = GENV.getStore();
  zstring docString;
  zstring baseUri;
  zstring docUri;
  std::auto_ptr<std::istringstream> iss;
  std::istream *is;
  store::Item_t tempItem;
  ParseXmlFragmentOptions parseOptions;
  bool validated = true;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    if (result->isStreamable())
    {
      // The "iss" auto_ptr can NOT be used since it will delete the stream that,
      // in this case, is a data member inside another object and not dynamically
      // allocated.
      //
      // We can't replace "iss" with "is" since we still need the auto_ptr for
      // the case when the result is not streamable.
      is = &result->getStream();
    }
    else
    {
      result->getStringValue2(docString);
      iss.reset (new std::istringstream(docString.c_str()));
      is = iss.get();
    }

    // read options
    consumeNext(tempItem, theChildren[1].getp(), planState);
    parseOptions = ParseXmlFragmentOptions::parseOptions(tempItem->getStringValue(), loc);

    try
    {
      store::LoadProperties loadProps;

      // These options/props cannot both be true at the same time
      if (parseOptions.enableDTDValidation)
        loadProps.setEnableDtd(true);
      if (parseOptions.enableExternalEntitiesProcessing)
        loadProps.setEnableExtParsedEntity(true);

      loadProps.setStoreDocument(false);
      result = lStore.loadDocument(baseUri, docUri, *is, loadProps);
    }
    catch (ZorbaException const& e)
    {
      if (parseOptions.enableFatelErrorProcessing)
        throw XQUERY_EXCEPTION( err::FODC0006, ERROR_PARAMS( e.what() ), ERROR_LOC( loc ));
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
    }
  }
  STACK_END (state);
}


} /* namespace zorba */
