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
#include "common/shared_types.h"
#include <zorbatypes/xerces_xmlcharray.h>
#include "store/api/item_factory.h"
#include "store/api/pul.h"

#include "types/casting.h"
#include "types/delegating_typemanager.h"
#include "types/typeimpl.h"
#include "types/schema/schema.h"
#include "types/schema/SchemaValidator.h"
#include "types/schema/StrX.h"

#include "context/static_context.h"
#include "context/collation_cache.h"
#include "context/namespace_context.h"
#include "compiler/parser/query_loc.h"
//#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/error_messages.h"
#include "zorbaerrors/errors.h"

using namespace std;

namespace zorba
{

void validateAfterUpdate(zorba::store::Item* item, zorba::store::Item_t& pul,
    DelegatingTypeManager* delegatingTypeManager, static_context* staticContext, 
    const QueryLoc& loc, bool isLax);

void processElement( store::Item_t& pul, static_context* staticContext, 
    DelegatingTypeManager* delegatingTypeManager, SchemaValidator& schemaValidator, 
    store::Item_t element);
    
void validateAttributes( SchemaValidator& schemaValidator, store::Iterator_t attributes);
    
void processAttributes( store::Item_t& pul, namespace_context& nsCtx, 
    DelegatingTypeManager* delegatingTypeManager, SchemaValidator& schemaValidator, 
    const store::Item* parent, store::Iterator_t attributes);
        
void processChildren( store::Item_t& pul, static_context* staticContext, 
    namespace_context& nsCtx, DelegatingTypeManager* delegatingTypeManager, 
    SchemaValidator& schemaValidator, store::Iterator_t children);
    
void processNamespaces ( SchemaValidator& schemaValidator, const store::Item *item);

void processTextValue (store::Item_t& pul, DelegatingTypeManager* delegatingTypeManager, 
    namespace_context &nsCtx, store::Item_t typeQName, xqpStringStore_t& textValue, 
    std::vector<store::Item_t> &resultList);

store::Item_t findAttributeItem(const store::Item *parent, store::Item_t &attQName);    
    
/**
 *   Given a vector of root nodes, this method validates all of them and 
 *   fills out pul with a list of changes that will be applied later, if
 *   the validation succeds. This should be called after an update.
 */
void validateAfterUpdate(const vector<zorba::store::Item*>& nodes, zorba::store::Item_t& pul,
    DelegatingTypeManager* delegatingTypeManager, static_context* staticContext, 
    const QueryLoc& loc, bool isLax)
{
#ifndef ZORBA_NO_XMLSCHEMA
    for ( unsigned int i = 0; i<nodes.size() ; i++)
    {
        validateAfterUpdate(nodes[i], pul, delegatingTypeManager, staticContext, loc, isLax);
    }
#endif //ZORBA_NO_XMLSCHEMA
}

#ifndef ZORBA_NO_XMLSCHEMA
void validateAfterUpdate(store::Item* item, zorba::store::Item_t& pul,
    DelegatingTypeManager* delegatingTypeManager, static_context* staticContext, 
    const QueryLoc& loc, bool isLax)
{
    ZORBA_ASSERT(item->isNode());

    Schema* schema = delegatingTypeManager->getSchema();
    if ( !schema )
    {
        // no schema available no change to pul
        return;
    }

    //xqpStringStore_t baseUri = planState.theRuntimeCB->theStaticContext->
    //    final_baseuri().getStore();
    
    SchemaValidator schemaValidator = SchemaValidator(delegatingTypeManager, 
        schema->getGrammarPool(), isLax, loc);
    

    switch ( item->getNodeKind() )
    {
    case store::StoreConsts::documentNode:
    {
        //std::cout << "Validate document" << "\n"; std::cout.flush();

        schemaValidator.startDoc();

        store::NsBindings bindings;
        item->getNamespaceBindings(bindings);
        namespace_context nsCtx = namespace_context(staticContext, bindings);
        
        processChildren( pul, staticContext, nsCtx, delegatingTypeManager, schemaValidator, 
            item->getChildren() );

        schemaValidator.endDoc();

        //std::cout << "End Validate doc" << "\n"; std::cout.flush();
        return;
    }
    case store::StoreConsts::elementNode: 
    {
        //std::cout << "Validate element" << "\n"; std::cout.flush();

        schemaValidator.startDoc();

        processElement(pul, staticContext, delegatingTypeManager, schemaValidator, item);

        schemaValidator.endDoc();
        
        //std::cout << "End Validate elem" << "\n"; std::cout.flush();
        return;
    }
    default:
        ZORBA_ERROR_LOC_DESC( XQDY0061, loc, 
            "Argument in validate expression not a document or element node.");
        return;
    }
}

void processElement( store::Item_t& pul, static_context* staticContext, 
    DelegatingTypeManager* delegatingTypeManager, SchemaValidator& schemaValidator, 
    store::Item_t element)
{
    ZORBA_ASSERT(element->isNode());
    ZORBA_ASSERT(element->getNodeKind() == store::StoreConsts::elementNode);

    
    store::Item_t nodeName = element->getNodeName();
    xqpStringStore_t baseUri = element->getBaseURI();

    schemaValidator.startElem(nodeName);


    // namespace declarations must go first
    processNamespaces( schemaValidator, element);

    // since the type of an element is determined only after the validator receives all 
    // of it's attributes, and an attribute node needs it's parent when created 
    // we need to go through the attributes twice: once for validation and once for creation
    validateAttributes(schemaValidator, element->getAttributes());
    
    store::Item_t typeName = schemaValidator.getTypeQName();

    // check if type has changed
    //if ( typeName != element->getType() )
    {
        vector<store::Item_t> typedValues;
        bool hasTypedValue = true;
        bool hasEmptyValue = false;
        store::PUL *p = static_cast<store::PUL *>(pul.getp());
        p->addSetElementType(element,
                             typeName,
                             (vector<store::Item_t>&)typedValues,
                             true, // TODO: check this
                             hasEmptyValue,
                             hasTypedValue,
                             element->isId(),
                             element->isIdRefs());
    }

    store::NsBindings bindings;
    element->getNamespaceBindings(bindings);
    namespace_context nsCtx = namespace_context(staticContext, bindings);
        
    processAttributes( pul, nsCtx, delegatingTypeManager, schemaValidator, element, element->getAttributes());
    
    processChildren( pul, staticContext, nsCtx, delegatingTypeManager, schemaValidator, element->getChildren());


    schemaValidator.endElem(nodeName);
}

void validateAttributes( SchemaValidator& schemaValidator, store::Iterator_t attributes)
{
    store::Item_t attribute;
    
    while ( attributes->next(attribute) )
    {
        ZORBA_ASSERT(attribute->isNode());
        ZORBA_ASSERT(attribute->getNodeKind() == store::StoreConsts::attributeNode);

        //std::cout << " v    - attr: " << attribute->getNodeName()->getLocalName()->c_str() << "\n"; std::cout.flush();
                    
        store::Item_t attName = attribute->getNodeName();
        schemaValidator.attr(attName, attribute->getStringValue());
    }
}

void processAttributes( store::Item_t& pul, namespace_context& nsCtx, 
    DelegatingTypeManager* delegatingTypeManager, SchemaValidator& schemaValidator, 
    const store::Item* parent, store::Iterator_t attributes)
{
    std::list<AttributeValidationInfo*>* attList = schemaValidator.getAttributeList();
    std::list<AttributeValidationInfo*>::iterator curAtt;
        
    for( curAtt = attList->begin() ; curAtt != attList->end(); ++curAtt )
    {
        AttributeValidationInfo* att = *curAtt;
        //std::cout << " v    proccessATT2: " << att->_localName << " T: " << att->_typeName << "\n";
            
        store::Item_t attQName;
        GENV_ITEMFACTORY->createQName( attQName, att->_uri, att->_prefix, att->_localName);
        
        store::Item_t attrib = findAttributeItem(parent, attQName);
        
        std::string typePrefix;
        if ( std::strcmp(Schema::XSD_NAMESPACE, att->_typeURI->c_str() )==0 ) // hack around typeManager bug for comparing QNames
            typePrefix = "xs";
        else
            typePrefix = "";
        
        store::Item_t typeQName;
        GENV_ITEMFACTORY->createQName(typeQName, att->_typeURI, new xqpStringStore(typePrefix), att->_typeName);
     
     
        std::vector<store::Item_t> typedValues;        
        processTextValue(pul, delegatingTypeManager, nsCtx, typeQName, att->_value, typedValues);
        
        //todo check in attributes if the type is different
        {
            store::PUL *p = static_cast<store::PUL *>(pul.getp());
            if ( typedValues.size()==1 )        // optimize when only one item is available 
                p->addSetAttributeType( attrib, typeQName, (store::Item_t&)(typedValues[0]), attrib->isId(), attrib->isIdRefs() );
            else            
                p->addSetAttributeType( attrib, typeQName, typedValues, attrib->isId(), attrib->isIdRefs() );
        }
    }
}

void processChildren( store::Item_t& pul, static_context* staticContext, namespace_context& nsCtx, DelegatingTypeManager* delegatingTypeManager, 
    SchemaValidator& schemaValidator, store::Iterator_t children)
{
    store::Item_t child;

    store::Item_t typeName;
    
    while ( children->next(child) )
    {
        if ( child->isNode() )
        {
            //std::cout << "  > child: " << child->getNodeKind() << " " << child->getType()->getLocalName()->c_str() << "\n";
            //std::cout.flush();
            
            switch ( child->getNodeKind() )
            { 
            case store::StoreConsts::elementNode:                                     
                processElement( pul, staticContext, delegatingTypeManager, schemaValidator, child);
                break;
                
            case store::StoreConsts::attributeNode:
                ZORBA_ASSERT(false);
                break;
            
            case store::StoreConsts::documentNode:
                ZORBA_ASSERT(false);                    
                break;
            
            case store::StoreConsts::textNode:
                {
                    //std::cout << "     - text: " << child->getStringValue() << "\n"; std::cout.flush();                    
                    xqpStringStore_t childStringValue = child->getStringValue();
                    schemaValidator.text(childStringValue);

                    store::Item_t type = schemaValidator.getTypeQName();
                  
                    
                    std::vector<store::Item_t> typedValues;
                    processTextValue(pul, delegatingTypeManager, nsCtx, type, childStringValue, typedValues );
                    
                    //todo check in attributes if the type is different
                    {
                        bool hasTypedValue = true;
                        bool hasEmptyValue = false;
                        store::PUL *p = static_cast<store::PUL *>(pul.getp());
                        
                        if ( typedValues.size()==1 ) // hack around serialization bug
                            p->addSetElementType(child,
                                                 type,
                                                 typedValues[0],
                                                 true, // TODO: check this
                                                 hasEmptyValue,
                                                 hasTypedValue,
                                                 child->isId(),
                                                 child->isIdRefs());
                        else
                            p->addSetElementType(child,
                                                 type,
                                                 typedValues,
                                                 true, // TODO: check this
                                                 hasEmptyValue,
                                                 hasTypedValue,
                                                 child->isId(),
                                                 child->isIdRefs());
                    }
                }
                break;
            
            case store::StoreConsts::piNode:
                {
                    //std::cout << "     - pi: " << child->getStringValue() << "\n"; std::cout.flush();
                    // do nothing
                }
                break;
            
            case store::StoreConsts::commentNode:
                {
                    //std::cout << "     - comment: " << child->getStringValue() << "\n"; std::cout.flush();
                    // do nothing
                }
                break;
            
            case store::StoreConsts::anyNode:
                //std::cout << "     - any: " << child->getStringValue() << "\n"; std::cout.flush();
                ZORBA_ASSERT(false);                    
                break;
                                
            default:
                ZORBA_ASSERT(false);
            }
        }
    }
}

void processNamespaces ( SchemaValidator& schemaValidator, const store::Item *item)
{
    store::NsBindings bindings;
    item->getNamespaceBindings(bindings, store::StoreConsts::ONLY_LOCAL_NAMESPACES);

    for (unsigned long i = 0; i < bindings.size(); i++)
    {
        schemaValidator.ns( bindings[i].first.getStore(), bindings[i].second.getStore() );
    }
}

void processTextValue (store::Item_t& pul, DelegatingTypeManager* delegatingTypeManager, 
    namespace_context &nsCtx, store::Item_t typeQName, xqpStringStore_t& textValue, 
    std::vector<store::Item_t> &resultList)
{
    xqtref_t type = delegatingTypeManager->create_named_atomic_type(typeQName, TypeConstants::QUANT_ONE);
    //std::cout << "     - processTextValue: " << typeQName->getPrefix()->str() << ":" << typeQName->getLocalName()->str() << "@" << 
    //    typeQName->getNamespace()->str() ; std::cout.flush();
    //std::cout << " type: " << ( type==NULL ? "NULL" : type->toString()) << "\n"; std::cout.flush();                    
            
    store::Item_t result;                    
    if (type!=NULL)
    {
        bool listOrUnion = false;
        if ( type->type_kind() == XQType::USER_DEFINED_KIND )
        {
            const UserDefinedXQType udXQType = static_cast<const UserDefinedXQType&>(*type);
            if ( udXQType.isList() || udXQType.isUnion() )
            {
                listOrUnion = true;
            }
        }

        if ( listOrUnion )
        {
            xqp_string str(textValue);
            delegatingTypeManager->getSchema()->
                parseUserSimpleTypes(str, type, resultList);
        }
        else
        {
            bool isResult = GenericCast::instance()->castToAtomic(result, textValue, type.getp(), &nsCtx);
            if ( isResult )
                resultList.push_back(result);
        }
    }
    else
    {
        if ( GENV_ITEMFACTORY->createUntypedAtomic( result, textValue) )
            resultList.push_back(result);
    }
}

store::Item_t findAttributeItem(const store::Item *parent, store::Item_t &attQName)
{
    store::Iterator_t attributes = parent->getAttributes();
    
    store::Item_t attribute;
    
    while ( attributes->next(attribute) )
    {
        ZORBA_ASSERT(attribute->isNode());
        ZORBA_ASSERT(attribute->getNodeKind() == store::StoreConsts::attributeNode);
                  
        store::Item_t currentAttName = attribute->getNodeName();
        
        if ( attQName->getLocalName()->
                compare(currentAttName->getLocalName())==0 && 
             attQName->getNamespace()->
                compare(currentAttName->getNamespace())==0 )
        {
            return attribute.getp();
        }
    }
    ZORBA_ASSERT(false);
    return NULL;
}
#endif //ZORBA_NO_XMLSCHEMA

}// namespace zorba
