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

SchemaValidator::SchemaValidator(XERCES_CPP_NAMESPACE::XMLGrammarPool *grammarPool, bool isLax, 
    const QueryLoc& loc)
{
    XERCES_CPP_NAMESPACE::MemoryManager* memoryManager = XERCES_CPP_NAMESPACE::XMLPlatformUtils::fgMemoryManager;

    _grammarResolver = new (memoryManager) XERCES_CPP_NAMESPACE::GrammarResolver(grammarPool, memoryManager);
    _grammarResolver->useCachedGrammarInParse(true);

    _schemaValidatorFilter = new SchemaValidatorFilter(!isLax, _grammarResolver, memoryManager, NULL, loc);
}

SchemaValidator::~SchemaValidator()
{
    delete _schemaValidatorFilter;
    delete _grammarResolver;
}

void SchemaValidator::startDoc()
{
    //cout << "   SDoc \n";

    _schemaValidatorFilter->startDocumentEvent(NULL, NULL);
}

void SchemaValidator::endDoc()
{
    //cout << "   EDoc \n";
    
    _schemaValidatorFilter->endDocumentEvent();
}

void SchemaValidator::startElem(store::Item_t elemName)
{   
    //cout << "   SElem: " << elemName->getLocalName()->c_str() << "\n";

    XMLCh *prefix = XMLString::transcode(elemName->getPrefix()->c_str()); 
    XMLCh *uri = XMLString::transcode(elemName->getNamespace()->c_str());
    XMLCh *localname = XMLString::transcode(elemName->getLocalName()->c_str()); 
    _schemaValidatorFilter->startElementEvent(prefix, uri, localname);
    XMLString::release(&prefix);
    XMLString::release(&uri);
    XMLString::release(&localname);
}

void SchemaValidator::endElem(store::Item_t elemName)
{
    //cout << "   EElem: " << elemName->getLocalName()->c_str() << "\n";

    XMLCh *prefix = XMLString::transcode(elemName->getPrefix()->c_str()); 
    XMLCh *uri = XMLString::transcode(elemName->getNamespace()->c_str());
    XMLCh *localname = XMLString::transcode(elemName->getLocalName()->c_str()); 
    XMLCh *typeURI = NULL;
    XMLCh *typeName = NULL;
    _schemaValidatorFilter->endElementEvent(prefix, uri, localname, typeURI, typeName);
    XMLString::release(&prefix);
    XMLString::release(&uri);
    XMLString::release(&localname);
}

void SchemaValidator::attr(store::Item_t attrName, xqpStringStore_t textValue)
{
    //cout << "     Attr: " << attrName->getPrefix()->c_str() << ":" << 
    //    attrName->getLocalName()->c_str() << " = '" << textValue->c_str() << "'\n";

    XMLCh *prefix = XMLString::transcode(attrName->getPrefix()->c_str()); 
    XMLCh *uri = XMLString::transcode(attrName->getNamespace()->c_str());
    XMLCh *localname = XMLString::transcode(attrName->getLocalName()->c_str()); 
    XMLCh *value = XMLString::transcode(textValue->c_str());
    XMLCh *typeURI = NULL; 
    XMLCh *typeName = NULL;
    _schemaValidatorFilter->attributeEvent(prefix, uri, localname, value, typeURI, typeName);
    XMLString::release(&prefix);
    XMLString::release(&uri);
    XMLString::release(&localname);
    XMLString::release(&value);
}

void SchemaValidator::text(xqpStringStore_t textValue)
{
    //cout << "     Text: " << textValue->c_str() << "\n";

    XMLCh *value = XMLString::transcode(textValue->c_str());
    _schemaValidatorFilter->textEvent(value);
    XMLString::release(&value);
}

void SchemaValidator::ns(xqpStringStore_t prefix, xqpStringStore_t uri)
{
    //cout << "     Ns  : " << prefix->c_str() << " = '" << uri->c_str() << "'\n";

    XMLCh *prefixVal = XMLString::transcode(prefix->c_str());
    XMLCh *uriVal    = XMLString::transcode(uri->c_str());
    _schemaValidatorFilter->namespaceEvent(prefixVal, uriVal);
    XMLString::release(&prefixVal);
    XMLString::release(&uriVal);
}


}// namespace zorba
