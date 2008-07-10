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
#include <xercesc/util/XMLString.hpp>

#include <iostream>


namespace zorba
{

using namespace std;
using namespace XERCES_CPP_NAMESPACE;

void ValidationEventHandler::startDocumentEvent(const XMLCh *documentURI, const XMLCh *encoding)
{
    cout << "   vh SDoc \n";    
}

void ValidationEventHandler::endDocumentEvent()
{
    cout << "   vh EDoc \n";
}

void ValidationEventHandler::startElementEvent(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName)
{
    cout << "   vh SElm: " << StrX(localName) << "\n";    
    while ( !_attributeList.empty() )
    {
        AttributeValidationInfo* attInfo = _attributeList.front();
        _attributeList.pop_front();
        delete attInfo;
    }
}

void ValidationEventHandler::typeElementEvent(const XMLCh *typeURI, const XMLCh *typeName)
{
    cout << "   vh --TElm: " << StrX(typeName) << " : " << StrX(typeURI) << "\n";
}

void ValidationEventHandler::endElementEvent(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName,
    const XMLCh *typeURI, const XMLCh *typeName)
{
    cout << "   vh EElm: " << StrX(localName) << "  T:" << StrX(typeName) << "\n";
}

void ValidationEventHandler::piEvent(const XMLCh *target, const XMLCh *value)
{
}

//void ValidationEventHandler::textEvent(const XMLCh *value);
void ValidationEventHandler::textEvent(const XMLCh *chars, unsigned int length)
{
    cout << "   vh Text: " << StrX(chars) << "  length:" << length << "\n";
    _textInfo._chars = chars;
    _textInfo._length = length;
}

void ValidationEventHandler::commentEvent(const XMLCh *value)
{
}

void ValidationEventHandler::attributeEvent(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName, 
    const XMLCh *value, const XMLCh *typeURI, const XMLCh *typeName)
{
    cout << "   vh Atr: " << StrX(localName) << " val: " << 
        StrX(value) << "  T:" << StrX(typeName) << "\n";
        
    _attributeList.push_back(new AttributeValidationInfo(prefix, uri, localName, value, typeURI, typeName));
}

void ValidationEventHandler::namespaceEvent(const XMLCh *prefix, const XMLCh *uri)
{
    cout << "   vh   NS: " << StrX(prefix) << " : " << StrX(uri) << "\n";    
}

void ValidationEventHandler::reset()
{
    _attributeList.clear();
    _textInfo._chars = NULL;
    _textInfo._length = 0;
}
               
} // end namespace zorba
