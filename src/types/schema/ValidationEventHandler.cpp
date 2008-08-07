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

#include "types/schema/StrX.h"
#include "types/schema/ValidationEventHandler.h"
#include "types/schema/schema.h"
#include <xercesc/util/XMLString.hpp>

#include <iostream>


namespace zorba
{

using namespace std;
using namespace XERCES_CPP_NAMESPACE;

AttributeValidationInfo::AttributeValidationInfo(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName, 
const XMLCh *value, const XMLCh *typeURI, const XMLCh *typeName)
{
    //std::cout << "AttributeValidationInfo1: " << StrX(prefix) << ":" << StrX(localName) << "@" << StrX(uri) << " = " << StrX(value) << "  T: " << StrX(typeName) << "@" << StrX(typeURI) << "\n";
    _prefix    = new xqpStringStore(StrX(prefix)   .localForm());
    _uri       = new xqpStringStore(StrX(uri)      .localForm());
    _localName = new xqpStringStore(StrX(localName).localForm());
    _value     = new xqpStringStore(StrX(value)    .localForm());
    _typeURI   = new xqpStringStore(StrX(typeURI)  .localFormOrDefault (Schema::XSD_NAMESPACE));
    _typeName  = new xqpStringStore(StrX(typeName) .localFormOrDefault ("anyType"));
}

TextValidationInfo::TextValidationInfo(const XMLCh *chars, unsigned int length)
{
    _value = new xqpStringStore( StrX(chars, length).localForm() );
}

void ValidationEventHandler::startDocumentEvent(const XMLCh *documentURI, const XMLCh *encoding)
{
    //cout << "   veh SDoc \n";    
}

void ValidationEventHandler::endDocumentEvent()
{
    //cout << "   veh EDoc \n";
}

void ValidationEventHandler::startElementEvent(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName)
{
    //cout << "   veh SElm: " << StrX(localName) << "\n";    
    while ( !_attributeList.empty() )
    {
        AttributeValidationInfo* attInfo = _attributeList.front();
        _attributeList.pop_front();
        delete attInfo;
    }
}

void ValidationEventHandler::typeElementEvent(const XMLCh *typeURI, const XMLCh *typeName)
{
    //cout << "     veh TElm: " << StrX(typeName) << " : " << StrX(typeURI) << "\n";
}

void ValidationEventHandler::endElementEvent(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName,
    const XMLCh *typeURI, const XMLCh *typeName)
{
    //cout << "   veh EElm: " << StrX(localName) << "  T:" << StrX(typeName) << "\n";
    if ( _textInfo != NULL )
    {   
        delete _textInfo;
        _textInfo = NULL;
    }
}

void ValidationEventHandler::piEvent(const XMLCh *target, const XMLCh *value)
{
}

//void ValidationEventHandler::textEvent(const XMLCh *value);
void ValidationEventHandler::textEvent(const XMLCh *chars, unsigned int length)
{
    //cout << "     veh Text: " << StrX(chars) << "  length:" << length << "\n";
    resetTextInfo();
}

void ValidationEventHandler::commentEvent(const XMLCh *value)
{
}

void ValidationEventHandler::attributeEvent(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName, 
    const XMLCh *value, const XMLCh *typeURI, const XMLCh *typeName)
{
    //cout << "    veh Atr: " << StrX(localName) << " val: " << StrX(value) << "  T:" << StrX(typeName) << "\n";
        
    _attributeList.push_back(new AttributeValidationInfo(prefix, uri, localName, value, typeURI, typeName));
}

void ValidationEventHandler::namespaceEvent(const XMLCh *prefix, const XMLCh *uri)
{
    //cout << "     veh NS: " << StrX(prefix) << " : " << StrX(uri) << "\n";    
}

void ValidationEventHandler::reset()
{
    _attributeList.clear();
    resetTextInfo();
}
               
void ValidationEventHandler::resetTextInfo()
{
    if ( _textInfo != NULL )
    {   
        delete _textInfo;
        _textInfo = NULL;
    }
}

} // end namespace zorba
