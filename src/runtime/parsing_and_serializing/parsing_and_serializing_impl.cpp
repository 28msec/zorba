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

#include "runtime/parsing_and_serializing/parsing_and_serializing.h"

#include <iostream>

#include "zorbatypes/URI.h"
#include "diagnostics/xquery_diagnostics.h"
#include "context/static_context.h"
#include "api/serialization/serializer.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "compiler/api/compilercb.h"

#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "system/globalenv.h"

#include "types/schema/schema.h"
#include "types/schema/validate.h"

namespace zorba
{

/*******************************************************************************
  14.9.1 fn:parse-xml
********************************************************************************/
bool FnParseXmlIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Store& lStore = GENV.getStore();
  zstring docString;
  zstring baseUri;
  URI lValidatedBaseUri;
  zstring docUri;
  std::auto_ptr<std::istringstream> iss;
  std::istream *is;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(consumeNext (result, theChildren [0].getp (), planState))
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

    // optional base URI argument
    if (theChildren.size() == 2)
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

      result->getStringValue2(baseUri);
    } else {
      baseUri = theSctx->get_base_uri();
    }

    try {
      store::LoadProperties loadProps;
      loadProps.setStoreDocument(false);
      result = lStore.loadDocument(baseUri, docUri, *is, loadProps);
    } catch (ZorbaException const& e) {
      throw XQUERY_EXCEPTION(
        err::FODC0006, ERROR_PARAMS("fn:parse-xml()", e.what() ), ERROR_LOC( loc )
      );
    }

    STACK_PUSH(true, state);
  }
  STACK_END (state);
}


/*******************************************************************************
  14.9.2 fn:serialize
********************************************************************************/
bool
FnSerializeIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  store::Item_t lParams;
  std::stringstream lResultStream;
  zstring lResult;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  {
    store::Iterator_t lIterWrapper = new PlanIteratorWrapper(theChildren[0], aPlanState);
    zorba::serializer lSerializer(aPlanState.theCompilerCB->theXQueryDiagnostics);

    // defaults
    lSerializer.setParameter("omit-xml-declaration", "yes");

    // if have serialization parameters
    if (theChildren.size() == 2 && consumeNext(lParams, theChildren[1].getp(), aPlanState))
    {
      store::Item_t lElemName = lParams->getNodeName();

      // make sure the user does not pass children of the serialization-parameters
      // element which would pass the schema validation below but break the logic after
      if (lElemName->getLocalName() != "serialization-parameters")
      {
        ztd::string_builder lSb;
        lSb << "the serialization parameters element must have the name \"serialization parameters\". "
          << "\"" << lElemName->getLocalName() << "\" was found";
        throw XQUERY_EXCEPTION(
          err::XQDY0027,
          ERROR_PARAMS(lSb.str()),
          ERROR_LOC( loc ));
      }

      // the provided element must be in the correct namespace otherwise
      // the user can pass a validated element from another namespace
      // which would make the schema validation below fail
      if (lElemName->getNamespace() != "http://www.w3.org/2010/xslt-xquery-serialization")
      {
        ztd::string_builder lSb;
        zstring lFoundNs("No");
        if (lElemName->getNamespace().size() > 0)
        {
          lFoundNs = "<";
          lFoundNs += lElemName->getNamespace();
          lFoundNs += ">";
        }

        lSb << "the serialization-parameters element must be in the <http://www.w3.org/2010/xslt-xquery-serialization> namespace. "
          << lFoundNs << " namespace was found";
        throw XQUERY_EXCEPTION(
          err::XQDY0027,
          ERROR_PARAMS(lSb .str()),
          ERROR_LOC( loc ));
      }

#ifndef ZORBA_NO_XMLSCHEMA
      // this will throw an error if te validation fails
      theSctx->validate(lParams, lParams, StaticContextConsts::strict_validation);
#endif

      // get the children iterator
      store::Iterator_t lElemIter = lParams->getChildren();
      lElemIter->open();
      store::Item_t lChildElem;

      // iterate over the children
      while (lElemIter->next(lChildElem))
      {
#ifdef ZORBA_NO_XMLSCHEMA
        // if zorba is compiled without schema support
        // consider only the child elements
        if (lChildElem->isNode() && lChildElem->getNodeKind() == store::StoreConsts::elementNode)
        {
#endif
          store::Item_t lChildName = lChildElem->getNodeName();
          if (lChildName->getLocalName() == "use-character-maps")
          {
            // TODO: once zorba the serializer supports character maps
          }
          else
          {
            store::Iterator_t lAttrIter = lChildElem->getAttributes();
            lAttrIter->open();
            store::Item_t lAttribute;
            // iterate over the attributes
            while (lAttrIter->next(lAttribute))
            {
              store::Item_t lAttributeQName = lAttribute->getNodeName();

              // the attribute must have the local name "value" (this should be taken care of by the schema)
              if (lAttributeQName->getLocalName() == "value")
              {
                store::Item_t lChildElemQName = lChildElem->getNodeName();
                // the serializer throws an exception if the parameter name is not correct
                lSerializer.setParameter(lChildElemQName->getLocalName().c_str(), lAttribute->getStringValue().c_str());
                break;
              }
#ifdef ZORBA_NO_XMLSCHEMA
              // if zorba is compiled without schema support
              // consider only the child elements
              else
              {
                ztd::string_builder lSb;
                lSb << "serialization-parameters element has an invalid attribute: \""
                  << lAttributeQName->getLocalName() << "\"";
                throw XQUERY_EXCEPTION(
                  err::XQDY0027,
                  ERROR_PARAMS(lSb.str()),
                  ERROR_LOC( loc ));
              }
#endif
            }
            lAttrIter->close();
          }
#ifdef ZORBA_NO_XMLSCHEMA
        }
        else
        {
          ztd::string_builder lSb;
          lSb << "serialization-parameters element can only element child nodes";
          throw XQUERY_EXCEPTION(
            err::XQDY0027,
            ERROR_PARAMS(lSb.str()),
            ERROR_LOC( loc ));
        }
#endif
      }
      lElemIter->close();
    }

    // and now serialize
    lSerializer.serialize(lIterWrapper, lResultStream);
    lResult = lResultStream.str();
  }

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, lResult), lState);
  STACK_END (lState);
}

} /* namespace zorba */
