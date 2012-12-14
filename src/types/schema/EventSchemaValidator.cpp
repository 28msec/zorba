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
#ifndef ZORBA_NO_XMLSCHEMA

#include "xercesIncludes.h"
#include "types/schema/SchemaValidatorFilter.h"

#include "system/globalenv.h"
#include "types/schema/EventSchemaValidator.h"
#include "types/schema/StrX.h"
#include "types/typeimpl.h"
#include <zorbatypes/xerces_xmlcharray.h>
#include "store/api/item_factory.h"
#include "types/schema/schema.h"
#include "types/root_typemanager.h"
#include "PrintSchema.h"

//using namespace std;
using namespace XERCES_CPP_NAMESPACE;

namespace zorba
{

EventSchemaValidator::EventSchemaValidator(
    TypeManager* typeManager,
    XERCES_CPP_NAMESPACE::XMLGrammarPool* grammarPool,
    bool isLax,
    const QueryLoc& loc)
  :
  theTypeManager(typeManager),
  theValidationEventHandler()
{
  XERCES_CPP_NAMESPACE::MemoryManager* memoryManager =
  XERCES_CPP_NAMESPACE::XMLPlatformUtils::fgMemoryManager;

  theGrammarResolver = new (memoryManager)
                     XERCES_CPP_NAMESPACE::GrammarResolver(grammarPool, memoryManager);
  theGrammarResolver->useCachedGrammarInParse(true);

#if 0 // enable this to debug registered user defined schema types
  PrintSchema::printInfo(true, grammarPool);
#endif

  theSchemaValidatorFilter = new SchemaValidatorFilter(!isLax,
                                                     &theValidationEventHandler,
                                                     theGrammarResolver,
                                                     memoryManager,
                                                     loc);
#if _XERCES_VERSION >= 30000
  // this will enable Integrity Constraint errors
  theSchemaValidatorFilter->setValidationScheme(XMLScanner::Val_Always);
#endif
}


EventSchemaValidator::~EventSchemaValidator()
{
  delete theSchemaValidatorFilter;
  delete theGrammarResolver;
}


void EventSchemaValidator::startDoc()
{
  //cout << "   SDoc \n";

  theSchemaValidatorFilter->startDocumentEvent(NULL, NULL);
}


void EventSchemaValidator::endDoc()
{
  //cout << "   EDoc \n";

  theSchemaValidatorFilter->endDocumentEvent();
}


void EventSchemaValidator::startElem(store::Item_t elemName)
{
  //cout << "  sv SElem: " << elemName->getLocalName() << "\n";

  XMLChArray prefix(elemName->getPrefix());
  XMLChArray uri(elemName->getNamespace());
  XMLChArray localname(elemName->getLocalName());
  theSchemaValidatorFilter->startElementEvent(prefix, uri, localname);
}


void EventSchemaValidator::endElem(store::Item_t elemName)
{
  //cout << "  sv EElem: " << elemName->getLocalName() << "\n";

  XMLChArray prefix(elemName->getPrefix());
  XMLChArray uri(elemName->getNamespace());
  XMLChArray localname(elemName->getLocalName());
  XMLCh *typeURI = NULL;
  XMLCh *typeName = NULL;
  theSchemaValidatorFilter->endElementEvent(prefix, uri, localname, typeURI, typeName);
}


void EventSchemaValidator::attr(store::Item_t attrName, const zstring& textValue)
{
  //cout << "  sv   Attr: " << attrName->getPrefix() << ":"
  //     << attrName->getLocalName() << " = '" << textValue << "'\n";

  XMLChArray prefix(attrName->getPrefix());
  XMLChArray uri(attrName->getNamespace());
  XMLChArray localname(attrName->getLocalName());
  XMLChArray value(textValue);
  XMLCh *typeURI = NULL;
  XMLCh *typeName = NULL;
  theSchemaValidatorFilter->attributeEvent(prefix, uri, localname, value, typeURI, typeName);
}


void EventSchemaValidator::endAttrs()
{
  //cout << "  sv   endAttrs \n";
  theSchemaValidatorFilter->endAttributesEvent();
}


void EventSchemaValidator::text(const zstring& textValue)
{
  //cout << "  sv   Text: '" << textValue << "'\n";

  XMLChArray value(textValue);
  theSchemaValidatorFilter->textEvent(value);
  //_validationEventHandler.resetAttList();
}


void EventSchemaValidator::ns(const zstring& prefix, const zstring& uri)
{
  //cout << "     Ns  : " << prefix << " = '" << uri << "'\n";

  XMLChArray prefixVal(prefix.c_str());
  XMLChArray uriVal(uri.c_str());
  theSchemaValidatorFilter->namespaceEvent(prefixVal, uriVal);
}


store::Item_t EventSchemaValidator::getTypeQName()
{
  StrX typeName(theSchemaValidatorFilter->getTypeName());
  StrX typeUri(theSchemaValidatorFilter->getTypeUri());

  //cout << "  - getTypeQName:  " << typeName << " @ " << typeUri <<" ";

  store::Item_t typeQName;
  GENV_ITEMFACTORY->createQName(typeQName,
                                typeUri.localFormOrDefault (Schema::XSD_NAMESPACE),
                                "",
                                typeName.localFormOrDefault ("untyped"));

  //cout << " : " << typeQName->getLocalName() << " @ "
  //     << typeQName->getNamespace() <<"\n"; std::cout.flush();

  return typeQName;
}


xqtref_t EventSchemaValidator::getType()
{
  StrX typeName(theSchemaValidatorFilter->getTypeName());
  StrX typeUri(theSchemaValidatorFilter->getTypeUri());

  //cout << "  - getType: " << typeName << "@" << typeUri <<"\n";

  store::Item_t typeQName;
  GENV_ITEMFACTORY->createQName(typeQName,
                                typeUri.localFormOrDefault (Schema::XSD_NAMESPACE),
                                "",
                                typeName.localFormOrDefault ("untyped"));

  xqtref_t type = theTypeManager->create_named_type(typeQName, 
                                                    TypeConstants::QUANT_ONE,
                                                    QueryLoc::null);
  return type;
}


store::Item_t EventSchemaValidator::getSubstitutedElemQName()
{
  if (theSchemaValidatorFilter->getSubstitutedElemName())
  {
    StrX substElemName(theSchemaValidatorFilter->getSubstitutedElemName());
    StrX substElemUri (theSchemaValidatorFilter->getSubstitutedElemUri ());

    //cout << "  - getSubstitutedElemQName: " << substElemName << "@" << substElemUri <<" ";

    store::Item_t substElemQName;
    GENV_ITEMFACTORY->createQName(substElemQName,
                                  substElemUri.localForm(),
                                  "",
                                  substElemName.localForm());

    //cout << " : " << substElemQName->getLocalName() << " @ "
    //     << substElemQName->getNamespace() <<"\n";

    return substElemQName;
  }
  else
    return NULL;
}


void EventSchemaValidator::startType(store::Item_t typeQName)
{
  XMLChArray uri(typeQName->getNamespace());
  XMLChArray localname(typeQName->getLocalName());

  //cout << "   SType: " << typeQName->getLocalName() << " @ "
  //     << typeQName->getNamespace() << "\n";

  theSchemaValidatorFilter->startTypeEvent(uri, localname);
}


void EventSchemaValidator::endType()
{
  //cout << "   EType \n";

  theSchemaValidatorFilter->endTypeEvent();
}

}  // namespace zorba

#endif // ZORBA_NO_XMLSCHEMA

/* vim:set et sw=2 ts=2: */
