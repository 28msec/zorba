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
#include "store/api/item.h"
#include "store/api/item_iterator.h"
#include "common/shared_types.h"

namespace zorba
{

class SchemaValidator;


class SchemaValidator
{
private:
    SchemaValidatorFilter *_schemaValidatorFilter;
    XERCES_CPP_NAMESPACE::GrammarResolver       *_grammarResolver;

public:
    SchemaValidator(XERCES_CPP_NAMESPACE::XMLGrammarPool *grammarPool);
    virtual ~SchemaValidator();

    void startDoc();
    void endDoc();

    void startElem(store::Item_t elemName);
    void endElem(store::Item_t elemName);

    void attr(store::Item_t attrName, xqpStringStore_t textValue);
    void text(xqpStringStore_t textValue);
};

} // namespace zorba

#endif /*ZORBA_SCHEMAVALIDATOR_H_*/

