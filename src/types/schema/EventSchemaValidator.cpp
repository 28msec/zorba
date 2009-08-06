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

using namespace std;
using namespace XERCES_CPP_NAMESPACE;

namespace zorba
{

EventSchemaValidator::EventSchemaValidator(
    TypeManager* typeManager,
    XERCES_CPP_NAMESPACE::XMLGrammarPool* grammarPool,
    bool isLax,
    const QueryLoc& loc)
  :
  _typeManager(typeManager),
  _validationEventHandler()
{
  XERCES_CPP_NAMESPACE::MemoryManager* memoryManager =
  XERCES_CPP_NAMESPACE::XMLPlatformUtils::fgMemoryManager;

  _grammarResolver = new (memoryManager)
                     XERCES_CPP_NAMESPACE::GrammarResolver(grammarPool, memoryManager);
  _grammarResolver->useCachedGrammarInParse(true);

#if 0 // enable this to debug registered user defined schema types
  PrintSchema::printInfo(true, grammarPool);
#endif 

  _schemaValidatorFilter = new SchemaValidatorFilter(!isLax,
                                                     &_validationEventHandler,
                                                     _grammarResolver,
                                                     memoryManager,
                                                     loc);
}


EventSchemaValidator::~EventSchemaValidator()
{
  delete _schemaValidatorFilter;
  delete _grammarResolver;
}


void EventSchemaValidator::startDoc()
{
  //cout << "   SDoc \n";

  _schemaValidatorFilter->startDocumentEvent(NULL, NULL);
}


void EventSchemaValidator::endDoc()
{
  //cout << "   EDoc \n";
    
  _schemaValidatorFilter->endDocumentEvent();
}


void EventSchemaValidator::startElem(store::Item_t elemName)
{   
  //cout << "  sv SElem: " << elemName->getLocalName()->c_str() << "\n";

  XMLChArray prefix(elemName->getPrefix()->c_str()); 
  XMLChArray uri(elemName->getNamespace()->c_str());
  XMLChArray localname(elemName->getLocalName()->c_str()); 
  _schemaValidatorFilter->startElementEvent(prefix, uri, localname);
}


void EventSchemaValidator::endElem(store::Item_t elemName)
{
  //cout << "  sv EElem: " << elemName->getLocalName()->c_str() << "\n";

  XMLChArray prefix(elemName->getPrefix()->c_str()); 
  XMLChArray uri(elemName->getNamespace()->c_str());
  XMLChArray localname(elemName->getLocalName()->c_str()); 
  XMLCh *typeURI = NULL;
  XMLCh *typeName = NULL;
  _schemaValidatorFilter->endElementEvent(prefix, uri, localname, typeURI, typeName);
}


void EventSchemaValidator::attr(store::Item_t attrName, xqpStringStore_t textValue)
{
  //cout << "  sv   Attr: " << attrName->getPrefix()->c_str() << ":"
  //     << attrName->getLocalName()->c_str() << " = '" << textValue->c_str() << "'\n";

  XMLChArray prefix(attrName->getPrefix()->c_str()); 
  XMLChArray uri(attrName->getNamespace()->c_str());
  XMLChArray localname(attrName->getLocalName()->c_str()); 
  XMLChArray value(textValue->c_str());
  XMLCh *typeURI = NULL; 
  XMLCh *typeName = NULL;
  _schemaValidatorFilter->attributeEvent(prefix, uri, localname, value, typeURI, typeName);
}


void EventSchemaValidator::endAttrs()
{
  //cout << "  sv   endAttrs \n";
  _schemaValidatorFilter->endAttributesEvent();
}


void EventSchemaValidator::text(xqpStringStore_t textValue)
{
  cout << "  sv   Text: " << textValue->c_str() << "\n";

  XMLChArray value(textValue->c_str());
  _schemaValidatorFilter->textEvent(value);
  //_validationEventHandler.resetAttList();
}


void EventSchemaValidator::ns(xqpStringStore_t prefix, xqpStringStore_t uri)
{
  //cout << "     Ns  : " << prefix->c_str() << " = '" << uri->c_str() << "'\n";

  XMLChArray prefixVal(prefix->c_str());
  XMLChArray uriVal(uri->c_str());
  _schemaValidatorFilter->namespaceEvent(prefixVal, uriVal);
}


store::Item_t EventSchemaValidator::getTypeQName()
{
  StrX typeName(_schemaValidatorFilter->getTypeName());
  StrX typeUri(_schemaValidatorFilter->getTypeUri());

  //cout << "  - getTypeQName: " << typeName << "@" << typeUri <<" ";

  store::Item_t typeQName;
  GENV_ITEMFACTORY->createQName(typeQName, 
                                typeUri.localFormOrDefault (Schema::XSD_NAMESPACE), 
                                "", 
                                typeName.localFormOrDefault ("untyped"));
  
  //cout << " : " << typeQName->getLocalName()->c_str() << " @ "
  //     << typeQName->getNamespace()->c_str() <<"\n";
  
  return typeQName;
}


xqtref_t EventSchemaValidator::getType()
{
  StrX typeName(_schemaValidatorFilter->getTypeName());
  StrX typeUri(_schemaValidatorFilter->getTypeUri());

  //cout << "  - getType: " << typeName << "@" << typeUri <<"\n";
    
  store::Item_t typeQName;
  GENV_ITEMFACTORY->createQName(typeQName, 
                                typeUri.localFormOrDefault (Schema::XSD_NAMESPACE), 
                                "", 
                                typeName.localFormOrDefault ("untyped"));
  
  xqtref_t type = _typeManager->create_named_type(typeQName);
  return type;
}


store::Item_t EventSchemaValidator::getSubstitutedElemQName()
{
  if (_schemaValidatorFilter->getSubstitutedElemName())
  {
    StrX substElemName(_schemaValidatorFilter->getSubstitutedElemName());
    StrX substElemUri (_schemaValidatorFilter->getSubstitutedElemUri ());
        
    //cout << "  - getSubstitutedElemQName: " << substElemName << "@" << substElemUri <<" ";
        
    store::Item_t substElemQName;
    GENV_ITEMFACTORY->createQName(substElemQName, 
                                  substElemUri.localForm(), 
                                  "", 
                                  substElemName.localForm());
        
    //cout << " : " << substElemQName->getLocalName()->c_str() << " @ "
    //     << substElemQName->getNamespace()->c_str() <<"\n";
  
    return substElemQName;
  }
  else
    return NULL;
}


void EventSchemaValidator::startType(store::Item_t typeQName)
{
  XMLChArray uri(typeQName->getNamespace()->c_str());
  XMLChArray localname(typeQName->getLocalName()->c_str());
    
  //cout << "   SType: " << typeQName->getLocalName()->c_str() << " @ "
  //     << typeQName->getNamespace()->c_str() << "\n";

  _schemaValidatorFilter->startTypeEvent(uri, localname);
}


void EventSchemaValidator::endType()
{
  //cout << "   EType \n";
    
  _schemaValidatorFilter->endTypeEvent();
}

}  // namespace zorba

#endif // ZORBA_NO_XMLSCHEMA

