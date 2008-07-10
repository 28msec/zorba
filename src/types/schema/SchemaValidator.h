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
#ifndef ZORBA_SCHEMAVALIDATOR_H_
#define ZORBA_SCHEMAVALIDATOR_H_

#include "xercesIncludes.h"
#include "types/schema/SchemaValidatorFilter.h"
#include "types/schema/StrX.h"
#include "types/schema/ValidationEventHandler.h"
#include "store/api/item.h"
#include "common/shared_types.h"
#include "types/root_typemanager.h"

namespace zorba
{

class SchemaValidator;


class SchemaValidator
{
private:
    TypeManager *_typeManager;
    SchemaValidatorFilter *_schemaValidatorFilter;
    XERCES_CPP_NAMESPACE::GrammarResolver       *_grammarResolver;
    ValidationEventHandler _validationEventHandler;
    
public:
    SchemaValidator(TypeManager* typeManager, XERCES_CPP_NAMESPACE::XMLGrammarPool *grammarPool, bool isLax, 
        const QueryLoc& loc);
    virtual ~SchemaValidator();

    void startDoc();
    void endDoc();

    void startElem(store::Item_t elemName);
    void endElem(store::Item_t elemName);

    // Must be called only after all ns() have been send if any otherwise only after startElem()
    void attr(store::Item_t attrName, xqpStringStore_t textValue);
    void text(xqpStringStore_t textValue);
    
    // Must be called only after startElem()
    void ns(xqpStringStore_t prefix, xqpStringStore_t uri);

    // Must be called only after all attr() have been sent
    store::Item_t getTypeQName();
    xqtref_t      getType();
    
    // Must be called only after all attr() have been sent and after getTypeQName() has been called
    std::list<AttributeValidationInfo*>* getAttributeList()
    {
        return _validationEventHandler.getAttributeList();
    }
    
    // Must be called only after text() has been called
    TextValidationInfo* getTextInfo()
    {
        return _validationEventHandler.getTextInfo();
    }
};

} // namespace zorba

#endif /*ZORBA_SCHEMAVALIDATOR_H_*/

