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
#include "stdafx.h"

#include "common/common.h"
#include "common/shared_types.h"

#include <zorbatypes/xerces_xmlcharray.h>

#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/pul.h"

#include "compiler/parser/query_loc.h"

#include "types/casting.h"
#include "types/schema/schema.h"

#include "types/schema/revalidateUtils.h"
#include "types/schema/validate.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"


//using namespace std;

namespace zorba
{


/**
 *   Given a vector of root nodes, this method validates all of them and
 *   fills out pul with a list of changes that will be applied later, if
 *   the validation succeds. This should be called after an update.
 */
void SchemaValidatorImpl::validate(
    const std::set<store::Item*>& nodes,
    store::PUL& pul)
{
#ifndef ZORBA_NO_XMLSCHEMA  
  std::set<zorba::store::Item*>::const_iterator it = nodes.begin();
  std::set<zorba::store::Item*>::const_iterator end = nodes.end();
  for (; it != end; it++)
  {
    validateAfterUpdate(*it, &pul, QueryLoc::null);
  }
#endif
}


#ifndef ZORBA_NO_XMLSCHEMA
void SchemaValidatorImpl::validateAfterUpdate(
    store::Item* item,
    zorba::store::PUL* pul,
    const QueryLoc& loc)
{
  ZORBA_ASSERT(item->isNode());

  TypeManager* typeManager = theSctx->get_typemanager();

  StaticContextConsts::validation_mode_t mode = theSctx->validation_mode();

  if (mode == StaticContextConsts::skip_validation)
    return;

  bool isLax = (mode == StaticContextConsts::lax_validation);

  Schema* schema = typeManager->getSchema();
  if ( !schema )
  {
    // no schema available no change to pul
    return;
  }

  EventSchemaValidator schemaValidator =
      EventSchemaValidator(typeManager,
                           schema->getGrammarPool(),
                           isLax,
                           theLoc);

  switch ( item->getNodeKind() )
  {
  case store::StoreConsts::documentNode:
  {
    //cout << "Validate after update document" << "\n"; cout.flush();

    schemaValidator.startDoc();

    store::NsBindings bindings;
    namespace_context nsCtx = namespace_context(theSctx, bindings);

    std::vector<store::Item_t> typedValues;
    processChildren(pul,
                    nsCtx,
                    typeManager,
                    schemaValidator,
                    item->getChildren(),
                    typedValues,
                    loc);
    
    schemaValidator.endDoc();
    
    //cout << "End Validate after update doc" << "\n"; cout.flush();
    return;
  }
  case store::StoreConsts::elementNode:
  {
    //cout << "Validate after update element" << "\n"; cout.flush();
      
    schemaValidator.startDoc();

    processElement(pul,
                   typeManager,
                   schemaValidator,
                   item,
                   loc);

    schemaValidator.endDoc();

    //cout << "End Validate after update elem" << "\n"; cout.flush();
    return;
  }
  default:
    throw XQUERY_EXCEPTION(
      err::XQDY0061,
      ERROR_PARAMS( ZED( NotDocOrElementNode ) ),
      ERROR_LOC( theLoc )
    );
  }
}


void SchemaValidatorImpl::processElement(
    store::PUL* pul,
    TypeManager* typeManager,
    EventSchemaValidator& schemaValidator,
    store::Item_t element,
    const QueryLoc& loc)
{
  ZORBA_ASSERT(element->isNode());
  ZORBA_ASSERT(element->getNodeKind() == store::StoreConsts::elementNode);

  store::Item_t nodeName = element->getNodeName();
  zstring baseUri;
  element->getBaseURI(baseUri);

  //cout << " vup    - processElement: " << nodeName->getLocalName()->c_str()
  //    << " @ " << nodeName->getNamespace()->c_str() << "\n"; cout.flush();

  schemaValidator.startElem(nodeName);

  // namespace declarations must go first
  processNamespaces( schemaValidator, element);

  // since the type of an element is determined only after the validator
  // receives all of it's attributes, and an attribute node needs it's
  // parent when created we need to go through the attributes twice: once
  // for validation and once for creation
  validateAttributes(schemaValidator, element->getAttributes());

  store::Item_t typeQName = schemaValidator.getTypeQName();
  store::Item_t substitutedElemQName = schemaValidator.getSubstitutedElemQName();

  //cout << " vup      - elemType old: "
  //    << element->getType()->getLocalName()->c_str() << " @ "
  //    << element->getType()->getNamespace()->c_str() << "\n"; cout.flush();
  //cout << " vup      - elemType new: " << typeQName->getLocalName()->c_str()
  //    << " @ " << typeQName->getNamespace()->c_str() << "\n"; cout.flush();

  bool isInSubstitutionElement = false;
  if (substitutedElemQName)
  {
    isInSubstitutionElement = true;
    //    cout << " vup        - substitutes: " << substitutedElemQName->g
    //  etLocalName()->c_str() << " @ " << substitutedElemQName->getNamespace()->
    // c_str() << "\n"; cout.flush();
  }

  bool isNewType = false;
  xqtref_t newType;
  store::Item_t elm;

  if ( !typeQName->equals(element->getType()) )
  {
    isNewType = true;
    newType = typeManager->create_named_type(typeQName, SequenceType::QUANT_ONE, loc);

    elm = element;
  }

  store::NsBindings bindings;
  element->getNamespaceBindings(bindings);
  namespace_context nsCtx = namespace_context(theSctx, bindings);

  processAttributes(pul, nsCtx, typeManager, schemaValidator, element, 
                    element->getAttributes(), loc);

  std::vector<store::Item_t> typedValues;
  int noOfChildren = processChildren(pul,
                                     nsCtx,
                                     typeManager, 
                                     schemaValidator,
                                     element->getChildren(),
                                     typedValues,
                                     loc);

  if ( isNewType )
  {
    bool tHasValue      = Validator::typeHasValue(newType);
    bool tHasTypedValue = Validator::typeHasTypedValue(typeManager, newType, loc);
    bool tHasEmptyValue = Validator::typeHasEmptyValue(newType);

    if ( noOfChildren==0 )
    {
      // workaround for elem of type xsd:string with no text child
      if ( newType->is_builtin() && 
          newType->getQName()->equals(GENV_TYPESYSTEM.STRING_TYPE_ONE->getQName()) )
      {
        /*store::Item_t result;
         zstring emptyStr = "";
         GENV_ITEMFACTORY->createString( result, emptyStr);
         typedValues.push_back(result);*/
        tHasEmptyValue = true;
        tHasTypedValue = false;
        tHasValue = false;
      }
      else if ( newType->type_kind()==XQType::USER_DEFINED_KIND )
      {
        const UserDefinedXQType udXQType = static_cast<const UserDefinedXQType&>(*newType);
        if ( udXQType.isSubTypeOf(typeManager, *GENV_TYPESYSTEM.STRING_TYPE_ONE) )
        {
          tHasEmptyValue = true;
          tHasTypedValue = false;
          tHasValue = false;
        }
      }
    }

    //cout << " vup        - addSetElementType: " << elm->getNodeName()->
    //  getLocalName()->str() << "   " << newType->get_qname()->getLocalName() 
    //  << " @ " << newType->get_qname()->getNamespace() << "\n"; cout.flush();
    //cout << " vup             - " << ( tHasTypedValue ? "hasTypedValue" : "" )
    //  << " values.size: " << typedValues.size() << (typedValues.size()>0 ? 
    // " [0]=" + typedValues[0]->getStringValue()->str() : "" ) << ( tHasValue ?
    // " hasValue" : "" ) << ( tHasEmptyValue ? " hasEmptyValue" : "" ) << "\n";
    //  cout.flush();

    if ( typedValues.size()==1 )
      pul->addSetElementType(&loc,
                             elm,
                             typeQName,
                             typedValues[0],
                             tHasValue,
                             tHasEmptyValue,
                             tHasTypedValue,
                             isInSubstitutionElement);
    else
      pul->addSetElementType(&loc,
                             elm,
                             typeQName,
                             (std::vector<store::Item_t>&)typedValues,
                             tHasValue,
                             tHasEmptyValue,
                             tHasTypedValue,
                             isInSubstitutionElement);
  }

  schemaValidator.endElem(nodeName);
}


void SchemaValidatorImpl::validateAttributes(
    EventSchemaValidator& schemaValidator,
    store::Iterator_t attributes)
{
  store::Item_t attribute;

  while ( attributes->next(attribute) )
  {
    ZORBA_ASSERT(attribute->isNode());
    ZORBA_ASSERT(attribute->getNodeKind() == store::StoreConsts::attributeNode);

    //cout << " vup    - attr: " << attribute->getNodeName()->getLocalName()->
    //  c_str() << "\n"; cout.flush();

    store::Item_t attName = attribute->getNodeName();
    schemaValidator.attr(attName, attribute->getStringValue());
  }
}


void SchemaValidatorImpl::processAttributes(
    store::PUL* pul,
    namespace_context& nsCtx,
    TypeManager* typeManager,
    EventSchemaValidator& schemaValidator,
    store::Item* parent,
    store::Iterator_t attributes,
    const QueryLoc& loc)
{
  std::list<AttributeValidationInfo*>* attList = schemaValidator.getAttributeList();
  std::list<AttributeValidationInfo*>::iterator curAtt;
  std::vector<store::Item_t> defaultAtts;

  for( curAtt = attList->begin() ; curAtt != attList->end(); ++curAtt )
  {
    AttributeValidationInfo* att = *curAtt;
    //cout << " vup        - processATT2: " << att->theLocalName << " T: " << 
    //  att->theTypeName << "\n";

    store::Item_t attQName;
    GENV_ITEMFACTORY->createQName(attQName,
                                  att->theUri,
                                  att->thePrefix,
                                  att->theLocalName);

    store::Item_t attrib = findAttributeItem(parent, attQName);

    zstring typePrefix;
    if ( att->theTypeURI == Schema::XSD_NAMESPACE) 
      // hack around typeManager bug for comparing QNames
      typePrefix = "xs";
    else
      typePrefix = "";

    store::Item_t typeQName;
    GENV_ITEMFACTORY->createQName(typeQName,
                                  att->theTypeURI,
                                  typePrefix,
                                  att->theTypeName);

    std::vector<store::Item_t> typedValues;
    processTextValue(pul, typeManager, nsCtx, typeQName, att->theValue, attrib, 
                     typedValues, loc);

    if ( attrib==NULL )
    {
      // this is an attibute filled in by the validator
      store::Item_t defaultAttNode;
      if ( typedValues.size()==1 ) // hack around serialization bug
        GENV_ITEMFACTORY->createAttributeNode( defaultAttNode,
                                               NULL,
                                               attQName,
                                               typeQName,
                                               typedValues[0]);
      else
        GENV_ITEMFACTORY->createAttributeNode( defaultAttNode,
                                               NULL,
                                               attQName,
                                               typeQName,
                                               typedValues);

      defaultAtts.push_back(defaultAttNode);
    }
    else if ( !typeQName->equals(attrib->getType()) )
    {
      store::Item_t atr = store::Item_t(attrib);
      if ( typedValues.size()==1 )        // optimize when only one item is available
        pul->addSetAttributeType( &loc, atr, typeQName, (store::Item_t&)(typedValues[0]) );
      else
        pul->addSetAttributeType( &loc, atr, typeQName, typedValues );
    }
  }

  if ( defaultAtts.size()>0 )
  {
    store::Item_t parentElem = store::Item_t(parent);
    pul->addInsertAttributes(&loc, parentElem, defaultAtts);
  }
}


int SchemaValidatorImpl::processChildren(
    store::PUL* pul,
    namespace_context& nsCtx,
    TypeManager* typeManager,
    EventSchemaValidator& schemaValidator,
    store::Iterator_t children,
    std::vector<store::Item_t>& typedValues,
    const QueryLoc& loc)
{
  store::Item_t child;

  store::Item_t typeName;

  int noOfChildren = 0;
  while ( children->next(child) )
  {
    noOfChildren++;

    if ( child->isNode() )
    {
      //cout << " vup  - processChildren: " << child->getType()->getLocalName()
      //  ->c_str() << "\n"; cout.flush();

      switch ( child->getNodeKind() )
      {
      case store::StoreConsts::elementNode:
        processElement(pul, typeManager, schemaValidator, child, loc);
        break;

      case store::StoreConsts::attributeNode:
        ZORBA_ASSERT(false);
        break;

      case store::StoreConsts::documentNode:
        ZORBA_ASSERT(false);
        break;

      case store::StoreConsts::textNode:
      {
        //cout << " vup        - pC text: '" << child->getStringValue()->
        //  normalizeSpace()->str() << "'\n"; cout.flush();

        zstring childStringValue;
        child->getStringValue2(childStringValue);

        schemaValidator.text(childStringValue);

        store::Item_t typeQName = schemaValidator.getTypeQName();
        
        processTextValue(pul,
                         typeManager,
                         nsCtx,
                         typeQName,
                         childStringValue,
                         child,
                         typedValues,
                         loc);
      }
      break;

      case store::StoreConsts::piNode:
        //cout << " vup        - pi: " << child->getStringValue() << "\n"; cout.flush();
        // do nothing
        break;

      case store::StoreConsts::commentNode:
        //cout << " vup        - comment: " << child->getStringValue() << "\n"; cout.flush();
        // do nothing
        break;

      case store::StoreConsts::anyNode:
        //cout << " vup        - any: " << child->getStringValue() << "\n"; cout.flush();
        ZORBA_ASSERT(false);
        break;

      default:
        ZORBA_ASSERT(false);
      }
    }
  }
  return noOfChildren;
}


void SchemaValidatorImpl::processNamespaces ( 
    EventSchemaValidator& schemaValidator, 
    const store::Item *item)
{
  store::NsBindings bindings;
  item->getNamespaceBindings(bindings, store::StoreConsts::ONLY_LOCAL_BINDINGS);

  for (csize i = 0; i < bindings.size(); i++)
  {
    schemaValidator.ns(bindings[i].first, bindings[i].second);
  }
}


void SchemaValidatorImpl::processTextValue (
    store::PUL* pul,
    TypeManager* typeManager,
    namespace_context &nsCtx,
    store::Item_t typeQName,
    zstring& textValue,
    store::Item_t& originalChild,
    std::vector<store::Item_t>& resultList,
    const QueryLoc& loc)
{
  xqtref_t type = typeManager->create_named_simple_type(typeQName);

  //cout << " vup        - processTextValue: '" << textValue->c_str() << "'\n";
  //cout << " vup        - processTextValue: " << typeQName->getPrefix()->str()
  // << ":" << typeQName->getLocalName()->str() << "@"
  // << typeQName->getNamespace()->str() ; cout.flush();
  //cout << "           type: " << ( type==NULL ? "NULL" : type->toString())
  // << "\n"; cout.flush();

  store::Item_t result;
  if (type != NULL)
  {
    if (type->type_kind() == XQType::ANY_SIMPLE_TYPE_KIND)
    {
      if (GENV_ITEMFACTORY->createUntypedAtomic(result, textValue))
        resultList.push_back(result);

      return;
    }

    if (type->type_kind() == XQType::USER_DEFINED_KIND)
    {
      const UserDefinedXQType udXQType = static_cast<const UserDefinedXQType&>(*type);
      
      if ( udXQType.isList() || udXQType.isUnion() )
      {
        typeManager->getSchema()->parseUserSimpleTypes(textValue, type, resultList,
                                                       &nsCtx, loc, false);
        return;
      }
      else if ( udXQType.isComplex() )
      { // text in mixed content,
        //  - if invalid there will be a validation exception thrown before this code
        //  - if xmlspace or mixed content it's fine to have the same node

        if ( udXQType.contentKind()==XQType::SIMPLE_CONTENT_KIND )
        {
          typeManager->getSchema()->parseUserSimpleTypes(textValue,
                                                         type,
                                                         resultList,
                                                         &nsCtx,
                                                         loc, false);
          return;
        }
        else
        {
          resultList.push_back(originalChild);
          return;
        }
      }
      // else isAtomic
    }

    bool isResult = GenericCast::castStringToAtomic(result,
                                                    textValue,
                                                    type.getp(),
                                                    typeManager,
                                                    &nsCtx,
                                                    loc);
    if ( isResult )
      resultList.push_back(result);
  }
  else
  {
    if (GENV_ITEMFACTORY->createUntypedAtomic(result, textValue))
      resultList.push_back(result);
  }
}


store::Item_t SchemaValidatorImpl::findAttributeItem(const store::Item *parent, 
                                                     store::Item_t &attQName)
{
  store::Iterator_t attributes = parent->getAttributes();

  store::Item_t attribute;

  while ( attributes->next(attribute) )
  {
    ZORBA_ASSERT(attribute->isNode());
    ZORBA_ASSERT(attribute->getNodeKind() == store::StoreConsts::attributeNode);

    store::Item_t currentAttName = attribute->getNodeName();

    if (attQName->equals(currentAttName))
    {
      return attribute.getp();
    }
  }
  //ZORBA_ASSERT(false);
  return NULL;
}
  
bool SchemaValidatorImpl::isPossibleSimpleContentRevalidation(
    store::Item* typeQName)
{
  TypeManager* typeManager = theSctx->get_typemanager();
  
  //StaticContextConsts::validation_mode_t mode = theSctx->validation_mode();
  Schema* schema = typeManager->getSchema();
  if ( !schema )
  {
    // no schema available no change to pul
    return false;
  }

  xqtref_t schemaType = schema->createXQTypeFromTypeName(typeManager, typeQName);  
  if ( schemaType.getp() )
    return isPossibleSimpleContentRevalImpl(schemaType);
  else
    return false;
}

bool SchemaValidatorImpl::isPossibleSimpleContentRevalImpl(
    xqtref_t schemaType)
{
  if ( schemaType->contentKind() == XQType::SIMPLE_CONTENT_KIND )
  {
    if (schemaType->type_kind() == XQType::ATOMIC_TYPE_KIND)
    {
      store::SchemaTypeCode schemaTypeCode = 
          TypeOps::get_atomic_type_code(*schemaType);

      if ( schemaTypeCode == store::XS_ID ||
          schemaTypeCode == store::XS_IDREF )
        return false;
      else
        return false; //true;
    }
    
    if ( schemaType->type_kind()==XQType::USER_DEFINED_KIND )
    {
      const UserDefinedXQType* udType = 
          static_cast<const UserDefinedXQType*>(schemaType.getp());
      
      if ( udType->isList() )
        return isPossibleSimpleContentRevalImpl(udType->getListItemType());
      
      if ( udType->isUnion() )
      {
        std::vector<xqtref_t> unionTypes = udType->getUnionItemTypes();
        for (unsigned int i=0; i<unionTypes.size(); i++) 
        {
          if ( !isPossibleSimpleContentRevalImpl(unionTypes[i]) )
              return false;
        }
        return true;
      }
      
      if ( udType->isAtomicAny() ) 
      {
        xqtref_t baseBIType = udType->getBaseBuiltinType();
        return isPossibleSimpleContentRevalImpl(baseBIType);
      }
    }
  }

  return false;
}

void SchemaValidatorImpl::validateSimpleContent(
    store::Item *typeQName, 
    zstring newValue, 
    std::vector<store::Item_t>& resultList)
{
  TypeManager* typeManager = theSctx->get_typemanager();
  Schema* schema = typeManager->getSchema();
  namespace_context nsCtx = namespace_context(theSctx);
  ZORBA_ASSERT( schema );

  const xqtref_t& targetType =
      schema->createXQTypeFromTypeName(typeManager, typeQName);

  schema->parseUserSimpleTypes(newValue, targetType, resultList,
                               &nsCtx, QueryLoc::null, false);
}

#endif //ZORBA_NO_XMLSCHEMA

}// namespace zorba
/* vim:set et sw=2 ts=2: */
