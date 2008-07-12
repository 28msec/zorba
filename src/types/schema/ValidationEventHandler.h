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
 
#ifndef _VALIDATIONEVENTHANDLER_H
#define _VALIDATIONEVENTHANDLER_H

#include <xercesc/util/XMLString.hpp>
#include <list>
#include "store/api/item.h"
#include "common/shared_types.h"


namespace zorba
{

class AttributeValidationInfo
{
public:
    AttributeValidationInfo(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName, 
    const XMLCh *value, const XMLCh *typeURI, const XMLCh *typeName);
        
    virtual ~AttributeValidationInfo(){}

    xqpStringStore_t _prefix;
    xqpStringStore_t _uri;
    xqpStringStore_t _localName;
    xqpStringStore_t _value;
    xqpStringStore_t _typeURI;
    xqpStringStore_t _typeName;  
};

class TextValidationInfo
{
public:      
    const XMLCh *_chars;
    unsigned int _length;
};

/**
* The ValidationEventHandler receives events from the SchemaValidatorFilter.
* From these events it stores the attribute and text event info in order to 
* construct an Item_t tree result.
*
* Note: elementTypeEvent must be called only after all the attribute events and 
*       before any content events (text, elements etc) inside current element
*/
class ValidationEventHandler 
{

public:
    ValidationEventHandler() : _attributeList(), _textInfo() {}
    virtual ~ValidationEventHandler() {}

    void startDocumentEvent(const XMLCh *documentURI, const XMLCh *encoding);
    void endDocumentEvent();
    void startElementEvent(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName);
    void typeElementEvent(const XMLCh *typeURI, const XMLCh *typeName);
    void endElementEvent(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName,
        const XMLCh *typeURI, const XMLCh *typeName);
    void piEvent(const XMLCh *target, const XMLCh *value);
    //void textEvent(const XMLCh *value);
    void textEvent(const XMLCh *chars, unsigned int length);
    void commentEvent(const XMLCh *value);
    void attributeEvent(const XMLCh *prefix, const XMLCh *uri, const XMLCh *localName, 
        const XMLCh *value, const XMLCh *typeURI, const XMLCh *typeName);
    void namespaceEvent(const XMLCh *prefix, const XMLCh *uri);
    
    void reset();
    
    std::list<AttributeValidationInfo*>* getAttributeList()
    {
        return &_attributeList;
    }
    
    TextValidationInfo* getTextInfo()
    {
        return &_textInfo;
    }
    
private:
    std::list<AttributeValidationInfo*> _attributeList;
    TextValidationInfo _textInfo;
    
}; // class ValidationEventHandler

}  // namespace zorba
#endif
