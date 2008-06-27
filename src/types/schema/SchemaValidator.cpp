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
#include "system/globalenv.h"
#include "types/schema/SchemaValidator.h"
#include "types/schema/StrX.h"
#include "types/typeimpl.h"
#include <zorbatypes/xerces_xmlcharray.h>
#include "store/api/item_factory.h"
#include "types/schema/schema.h"


using namespace std;
XERCES_CPP_NAMESPACE_USE;

namespace zorba
{

SchemaValidator::SchemaValidator(TypeManager *typeManager, 
    XERCES_CPP_NAMESPACE::XMLGrammarPool *grammarPool, bool isLax, const QueryLoc& loc)
    : _typeManager(typeManager)
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

    XMLChArray prefix(elemName->getPrefix()->c_str()); 
    XMLChArray uri(elemName->getNamespace()->c_str());
    XMLChArray localname(elemName->getLocalName()->c_str()); 
    _schemaValidatorFilter->startElementEvent(prefix, uri, localname);
}

void SchemaValidator::endElem(store::Item_t elemName)
{
    //cout << "   EElem: " << elemName->getLocalName()->c_str() << "\n";

    XMLChArray prefix(elemName->getPrefix()->c_str()); 
    XMLChArray uri(elemName->getNamespace()->c_str());
    XMLChArray localname(elemName->getLocalName()->c_str()); 
    XMLCh *typeURI = NULL;
    XMLCh *typeName = NULL;
    _schemaValidatorFilter->endElementEvent(prefix, uri, localname, typeURI, typeName);
}

void SchemaValidator::attr(store::Item_t attrName, xqpStringStore_t textValue)
{
    //cout << "     Attr: " << attrName->getPrefix()->c_str() << ":" << 
    //    attrName->getLocalName()->c_str() << " = '" << textValue->c_str() << "'\n";

    XMLChArray prefix(attrName->getPrefix()->c_str()); 
    XMLChArray uri(attrName->getNamespace()->c_str());
    XMLChArray localname(attrName->getLocalName()->c_str()); 
    XMLChArray value(textValue->c_str());
    XMLCh *typeURI = NULL; 
    XMLCh *typeName = NULL;
    _schemaValidatorFilter->attributeEvent(prefix, uri, localname, value, typeURI, typeName);
}

void SchemaValidator::text(xqpStringStore_t textValue)
{
    //cout << "     Text: " << textValue->c_str() << "\n";

    XMLChArray value(textValue->c_str());
    _schemaValidatorFilter->textEvent(value);
}

void SchemaValidator::ns(xqpStringStore_t prefix, xqpStringStore_t uri)
{
    //cout << "     Ns  : " << prefix->c_str() << " = '" << uri->c_str() << "'\n";

    XMLChArray prefixVal(prefix->c_str());
    XMLChArray uriVal(uri->c_str());
    _schemaValidatorFilter->namespaceEvent(prefixVal, uriVal);
}


store::Item_t SchemaValidator::getTypeQName()
{
    StrX typeName(_schemaValidatorFilter->getTypeName());
    StrX typeUri(_schemaValidatorFilter->getTypeUri());

    //cout << "  - getTypeQName: " << typeName << "@" << typeUri <<"\n"; 

    store::Item_t typeQName;
    GENV_ITEMFACTORY->createQName(typeQName, typeUri.localFormOrDefault (Schema::XSD_NAMESPACE), "", typeName.localFormOrDefault ("anyType"));

    return typeQName;
}

xqtref_t SchemaValidator::getType()
{
    StrX typeName(_schemaValidatorFilter->getTypeName());
    StrX typeUri(_schemaValidatorFilter->getTypeUri());

    //cout << "  - getType: " << typeName << "@" << typeUri <<"\n"; 
    
    store::Item_t typeQName;
    GENV_ITEMFACTORY->createQName(typeQName, typeUri.localFormOrDefault (Schema::XSD_NAMESPACE), "", typeName.localFormOrDefault ("anyType"));

    xqtref_t type = _typeManager->create_named_type(typeQName);
    return type;
}

}// namespace zorba
