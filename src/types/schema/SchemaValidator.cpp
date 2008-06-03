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
#include "types/schema/SchemaValidator.h"


using namespace std;
XERCES_CPP_NAMESPACE_USE;

namespace zorba
{

SchemaValidator::SchemaValidator(XERCES_CPP_NAMESPACE::XMLGrammarPool *grammarPool)
{
    XERCES_CPP_NAMESPACE::MemoryManager* memoryManager = XERCES_CPP_NAMESPACE::XMLPlatformUtils::fgMemoryManager;

    _grammarResolver = new (memoryManager) XERCES_CPP_NAMESPACE::GrammarResolver(grammarPool, memoryManager);
    _grammarResolver->useCachedGrammarInParse(true);

    _schemaValidatorFilter = new SchemaValidatorFilter(false, _grammarResolver, memoryManager, NULL);
}

SchemaValidator::~SchemaValidator()
{
    delete _schemaValidatorFilter;
    delete _grammarResolver;
}

void SchemaValidator::startDoc()
{
    cout << "   SDoc \n";
    _schemaValidatorFilter->startDocumentEvent(NULL, NULL);
}

void SchemaValidator::endDoc()
{
    cout << "   EDoc \n";
    _schemaValidatorFilter->endDocumentEvent();
}

void SchemaValidator::startElem(store::Item_t elemName)
{   
    cout << "   SElem: " << elemName->getLocalName()->c_str() << "\n";
    const XMLCh *prefix = XMLString::transcode(elemName->getPrefix()->c_str()); 
    const XMLCh *uri = XMLString::transcode(elemName->getNamespace()->c_str());
    const XMLCh *localname = XMLString::transcode(elemName->getLocalName()->c_str()); 
    _schemaValidatorFilter->startElementEvent(prefix, uri, localname);
}

void SchemaValidator::endElem(store::Item_t elemName)
{
    cout << "   EElem: " << elemName->getLocalName()->c_str() << "\n";
    const XMLCh *prefix = XMLString::transcode(elemName->getPrefix()->c_str()); 
    const XMLCh *uri = XMLString::transcode(elemName->getNamespace()->c_str());
    const XMLCh *localname = XMLString::transcode(elemName->getLocalName()->c_str()); 
    const XMLCh *typeURI = NULL;
    const XMLCh *typeName = NULL;
    _schemaValidatorFilter->endElementEvent(prefix, uri, localname, typeURI, typeName);
}

void SchemaValidator::attr(store::Item_t attrName, xqpStringStore_t textValue)
{
    cout << "     Attr: " << attrName->getLocalName()->c_str() << "\n";
    const XMLCh *prefix = XMLString::transcode(attrName->getPrefix()->c_str()); 
    const XMLCh *uri = XMLString::transcode(attrName->getNamespace()->c_str());
    const XMLCh *localname = XMLString::transcode(attrName->getLocalName()->c_str()); 
    const XMLCh *value = XMLString::transcode(textValue->c_str());
    const XMLCh *typeURI = NULL; 
    const XMLCh *typeName = NULL;
    _schemaValidatorFilter->attributeEvent(prefix, uri, localname, value, typeURI, typeName);
}

void SchemaValidator::text(xqpStringStore_t textValue)
{
    cout << "     Text: " << textValue->c_str() << "\n";
    const XMLCh *value = XMLString::transcode(textValue->c_str());
    _schemaValidatorFilter->textEvent(value);
}

} // namespace zorba