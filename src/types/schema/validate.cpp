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

#include "validate.h"

#include "diagnostics/xquery_diagnostics.h"

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeops.h"

#ifndef ZORBA_NO_XMLSCHEMA

#include "types/schema/schema.h"
#include "types/schema/SchemaValidatorFilter.h"
#include "types/schema/EventSchemaValidator.h"
#include "types/schema/StrX.h"
#include "types/schema/revalidateUtils.h"

#include "zorbatypes/duration.h"
#include "zorbatypes/datetime.h"

#endif

#include "api/unmarshaller.h"

#include "compiler/parser/query_loc.h"

#include "store/api/copymode.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/store.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "context/namespace_context.h"

#include "diagnostics/assert.h"
#include "zorba/store_consts.h"

using namespace std;

namespace zorba
{


bool Validator::effectiveValidationValue(
    store::Item_t& result,
    const store::Item_t& sourceNode,
    const store::Item_t& typeName,
    TypeManager* typeManager,
    ParseConstants::validation_mode_t validationMode,
    const static_context* sctx,
    const QueryLoc& loc)
{
  //cout << "Starting Validation   typeManager: " << typeManager <<
  //endl; cout.flush();
  try
  {
    return realValidationValue(result, sourceNode, typeName,
                               typeManager, validationMode, sctx, loc);
  }
  catch (ZorbaException& e)
  {
    set_source( e, loc );
    
    if ( sourceNode->isNode() && 
        sourceNode->getNodeKind() == store::StoreConsts::documentNode )
    {
      zstring baseUri;
      sourceNode->getDocumentURI(baseUri);

      //e.theDescription += " while validating document '" + baseUri + "'";
    }
    throw;
  }
}


bool Validator::realValidationValue(
    store::Item_t& result,
    const store::Item_t& sourceNode,
    const store::Item_t& typeName,
    TypeManager* typeManager,
    ParseConstants::validation_mode_t validationMode,
    const static_context* sctx,
    const QueryLoc& loc)
{
  xqtref_t type;

  if (!sourceNode->isNode() ||
      !(sourceNode->getNodeKind()==store::StoreConsts::documentNode ||
        sourceNode->getNodeKind()==store::StoreConsts::elementNode
       ) )
  {
    throw XQUERY_EXCEPTION( err::XQTY0030, ERROR_LOC( loc ) );
  }

  // verify number of child elements when source is a document node
  if (sourceNode->getNodeKind() == store::StoreConsts::documentNode)
  {
    //don't allow more than one child element in documents
    store::Iterator_t child_it;
    child_it = sourceNode->getChildren();
    store::Item_t child;
    int nr_child_elements = 0;
    while ( child_it->next(child) )
    {
      if ( child->isNode() &&
           child->getNodeKind() == store::StoreConsts::elementNode)
      {
        if (nr_child_elements)
        {
          throw XQUERY_EXCEPTION(
            err::XQDY0061,
            ERROR_PARAMS( ZED( DocNodeMultipleElements ) ),
            ERROR_LOC( loc )
          );
        }
        nr_child_elements++;
      }
    }
  }

  Schema* schema = typeManager->getSchema();

  if ( !schema )
  {
    //cout << "No schema: isNode() " << sourceNode->isNode() << "  nodeKind: "<<
    // sourceNode->getNodeKind() << endl;

    // if we got here it basicaly means that there was no import but
    // validation is used so we need to set up schema in the typeManager anyway
    // validation has to work for xsiType and built-in types

    TypeManagerImpl *typeManagerImpl = static_cast<TypeManagerImpl*>(typeManager);
    typeManagerImpl->initializeSchema();
    schema = typeManager->getSchema();



//    if ( validationMode == ParseConstants::val_strict )
//    {
//      throw XQUERY_EXCEPTION( err::XQDY0084, ERROR_LOC( loc ) );
//    }
//    else
//    {
      // no schema available - items remain the same
//      result = sourceNode;
//      return true;
//    }
  }

#ifndef ZORBA_NO_XMLSCHEMA

  EventSchemaValidator schemaValidator =
    EventSchemaValidator(typeManager,
                         schema->getGrammarPool(),
                         validationMode == ParseConstants::val_lax,
                         loc);

  switch (sourceNode->getNodeKind())
  {
  case store::StoreConsts::documentNode:
  {
    //cout << "Validate document" << "\n"; cout.flush();

    if ( validationMode == ParseConstants::val_typename )
    {
      //cout << "Validate type: " << typeName->getLocalName()
      //     << " @ " << typeName->getNamespace() << "\n"; cout.flush();
      schemaValidator.startType(typeName);
    }
    else
    {
      schemaValidator.startDoc();
      
      // ask for the type of the root element to populate
      // the cache with anonymous types
      store::Iterator_t children = sourceNode->getChildren();
      store::Item_t child;
      while ( children->next(child) )
      {
        if ( child->isNode() &&
             child->getNodeKind()==store::StoreConsts::elementNode )
        {
          typeManager->getSchema()->
            createXQTypeFromElementName(typeManager,
                                        child->getNodeName(),
                                        false,
                                        loc);
          break;
        }
      }
    }
    
    zstring docBaseUri;
    zstring docUri;
    sourceNode->getBaseURI(docBaseUri);
    sourceNode->getDocumentURI(docUri);

    store::Item_t newDoc;
    GENV_ITEMFACTORY->createDocumentNode(newDoc, docBaseUri, docUri);

    processChildren(sctx,
                    typeManager,
                    schemaValidator,
                    newDoc,
                    sourceNode->getChildren(),
                    loc);
    
    if ( validationMode == ParseConstants::val_typename )
    {
      schemaValidator.endType();
      //cout << "End Validate type: " << typeName->getLocalName()
      //     << " @ " << typeName->getNamespace() << "\n";
      //cout.flush();
    }
    else
    {
      schemaValidator.endDoc();
    }
    
    //cout << "End Validate doc" << "\n"; cout.flush();
    
    result = newDoc;
    result->markValidated();
    return true;
  }
  case store::StoreConsts::elementNode:
  {
    if ( validationMode == ParseConstants::val_typename )
    {
      //cout << "Validate type: " << typeName->getLocalName() <<" @ "
      //     << typeName->getNamespace() << "\n"; cout.flush();
      
      schemaValidator.startType(typeName);
    }
    else
    {
      //cout << "Validate element" << "\n"; cout.flush();
      schemaValidator.startDoc();
      
      // ask for the type of the root element to populate the cache
      // with anonymous types
      typeManager->getSchema()->
        createXQTypeFromElementName(typeManager,
                                    sourceNode->getNodeName(),
                                    false,
                                    loc);
    }
    
    store::Item_t newElem = processElement(sctx,
                                           typeManager,
                                           schemaValidator,
                                           NULL,
                                           sourceNode,
                                           loc);
    
    if ( validationMode == ParseConstants::val_typename )
    {
      schemaValidator.endType();
      //cout << "End Validate type: " << typeName->getLocalName()
      //     <<" @ "<< typeName->getNamespace() << "\n";cout.flush();
    }
    else
    {
      schemaValidator.endDoc();
      //cout << "End Validate elem" << "\n"; cout.flush();
    }
    
    result = newElem;
    result->markValidated();
    return true;
  }
  default:
  {
    throw XQUERY_EXCEPTION( err::XQTY0030, ERROR_LOC( loc ) );
  }
  }
#endif // ZORBA_NO_XMLSCHEMA
}


#ifndef ZORBA_NO_XMLSCHEMA


store::Item_t Validator::processElement(
    const static_context* sctx,
    TypeManager* typeManager,
    EventSchemaValidator& schemaValidator,
    store::Item* parent,
    const store::Item_t& element,
    const QueryLoc& loc)
{
  ZORBA_ASSERT(element->isNode());
  ZORBA_ASSERT(element->getNodeKind() == store::StoreConsts::elementNode);


  store::Item_t nodeName = element->getNodeName();
  zstring baseUri;
  element->getBaseURI(baseUri);

  schemaValidator.startElem(nodeName);

  // namespace declarations must go first
  processNamespaces( schemaValidator, element);

  // since the type of an element is determined only after the validator
  // receives all of it's attributes, and an attribute node needs it's parent
  // when created we need to go through the attributes twice: once for
  // validation and once for creation
  validateAttributes(schemaValidator, element->getAttributes());

  // not required since getTypeQName will trigger processElement in validator
  //schemaValidator.endAttrs();

  store::Item_t typeName = schemaValidator.getTypeQName();

  bool isSubstitutionGroup = false;
  if ( schemaValidator.getSubstitutedElemQName() )
      isSubstitutionGroup = true;

  store::Item_t newElem;

  store::NsBindings bindings;
  element->getNamespaceBindings(bindings);

  bool haveTypedValue = true;
  bool haveEmptyValue = false;

  if ( typeName!=NULL && typeManager!=NULL )
  {
    xqtref_t schemaType = typeManager->create_named_type(typeName);

    if ( schemaType!=NULL )
    {
      haveTypedValue = typeHasValue(schemaType);
      haveEmptyValue = typeHasEmptyValue(schemaType);
    }
  }

  store::Item_t elemName = element->getNodeName();
  GENV_ITEMFACTORY->createElementNode(newElem, parent, elemName,
                                      typeName, haveTypedValue, haveEmptyValue,
                                      bindings, baseUri, isSubstitutionGroup);

  processAttributes(sctx,
                    typeManager,
                    schemaValidator,
                    (store::Item *)newElem,
                    element->getAttributes(),
                    loc);

  processChildren(sctx,
                  typeManager,
                  schemaValidator,
                  (store::Item *)newElem,
                  element->getChildren(),
                  loc);

  schemaValidator.endElem(nodeName);

  return newElem;
}


void Validator::validateAttributes(
    EventSchemaValidator& schemaValidator,
    store::Iterator_t attributes)
{
  store::Item_t attribute;

  while ( attributes->next(attribute) )
  {
    ZORBA_ASSERT(attribute->isNode());
    ZORBA_ASSERT(attribute->getNodeKind() == store::StoreConsts::attributeNode);

    //cout << " v    - attr: " << attribute->getNodeName()->getLocalName()->
    //  c_str() << "\n"; cout.flush();

    store::Item_t attName = attribute->getNodeName();
    schemaValidator.attr(attName, attribute->getStringValue());
  }
}


void Validator::processAttributes(
    const static_context* sctx,
    TypeManager* typeManager,
    EventSchemaValidator& schemaValidator,
    store::Item* parent,
    store::Iterator_t attributes,
    const QueryLoc& loc)
{
  std::list<AttributeValidationInfo*>* attList =
    schemaValidator.getAttributeList();
  std::list<AttributeValidationInfo*>::iterator curAtt;

  for( curAtt = attList->begin(); curAtt != attList->end(); ++curAtt )
  {
    AttributeValidationInfo* att = *curAtt;
    //cout << " v    proccessATT2: " << att->theLocalName << " T: " <<
    //  att->theTypeName << "\n";

    store::Item_t attQName;
    GENV_ITEMFACTORY->createQName(attQName,
                                  att->theUri,
                                  att->thePrefix,
                                  att->theLocalName);

    zstring typePrefix;

    // hack around typeManager bug for comparing QNames
    if (att->theTypeURI == Schema::XSD_NAMESPACE)
      typePrefix = "xs";
    else
      typePrefix = "";

    store::Item_t typeQName;
    GENV_ITEMFACTORY->createQName(typeQName,
                                  att->theTypeURI,
                                  typePrefix,
                                  att->theTypeName);

    store::NsBindings bindings;
    parent->getNamespaceBindings(bindings);

    std::vector<store::Item_t> typedValues;
    processTextValue(sctx,
                     typeManager,
                     bindings,
                     typeQName,
                     att->theValue,
                     typedValues,
                     loc);

    store::Item_t validatedAttNode;
    if ( typedValues.size()==1 ) // hack around serialization bug
      GENV_ITEMFACTORY->createAttributeNode(validatedAttNode,
                                            parent,
                                            attQName,
                                            typeQName,
                                            typedValues[0]);
    else
      GENV_ITEMFACTORY->createAttributeNode(validatedAttNode,
                                            parent,
                                            attQName,
                                            typeQName,
                                            typedValues);
  }
}


void Validator::processChildren(
    const static_context* sctx,
    TypeManager* typeManager,
    EventSchemaValidator& schemaValidator,
    store::Item* parent,
    store::Iterator_t children,
    const QueryLoc& loc)
{
  store::Item_t child;

  while ( children->next(child) )
  {
    if ( child->isNode() )
    {
      //cout << "  > child: " << child->getNodeKind() << " " <<
      // (child->getType() != NULL ? child->getType()->getLocalName()
      // : "type_NULL" ) << "\n"; cout.flush();

      switch ( child->getNodeKind() )
      {
      case store::StoreConsts::elementNode:
        processElement(sctx, typeManager, schemaValidator, parent, child, loc);
        break;

      case store::StoreConsts::attributeNode:
        ZORBA_ASSERT(false);
        break;

      case store::StoreConsts::documentNode:
        ZORBA_ASSERT(false);
        break;

      case store::StoreConsts::textNode:
      {
        zstring childStringValue;
        child->getStringValue2(childStringValue);
        schemaValidator.text(childStringValue);

        store::Item_t typeQName = schemaValidator.getTypeQName();

        store::Item_t validatedTextNode;

        TypeIdentifier_t typeIdentifier =
          TypeIdentifier::createNamedType(
            Unmarshaller::newString( typeQName->getNamespace() ),
            Unmarshaller::newString( typeQName->getLocalName() )
          );

        //xqType is NULL, create_type can't find it
        xqtref_t xqType = typeManager->create_type(*typeIdentifier);

#if 0   // enable this to debug children values
        if ( typeQName.getp() && xqType.getp() )
        {
          cout << "     - text: '" << childStringValue << "' T: " <<
            typeQName->getLocalName() << "\n"; cout.flush();
          cout << "        xqT: " << xqType->toString() << "  content_kind: " <<
            xqType->content_kind() << " tKind:" << xqType->type_kind() << " \n";
          cout.flush();
        }
        else
          cout << "     - text2: '" << childStringValue << "' tQN: " <<
            (typeQName ? typeQName->getStringValue() : "NULL") <<
            " xqT:" << ( xqType.getp() ? xqType.getp()->toString() : "NULL" )
               << "\n"; cout.flush();
#endif

        if ( xqType != NULL &&
             xqType->content_kind() == XQType::SIMPLE_CONTENT_KIND )
        {
          store::NsBindings nsBindings;
          parent->getNamespaceBindings(nsBindings);
          std::vector<store::Item_t> typedValues;
          
          processTextValue(sctx,
                           typeManager,
                           nsBindings,
                           typeQName,
                           childStringValue,
                           typedValues,
                           loc);

          if ( typedValues.size() == 1 ) // hack around serialization bug
            GENV_ITEMFACTORY->createTextNode(validatedTextNode, parent,
                                             typedValues[0]);
          else
            GENV_ITEMFACTORY->createTextNode(validatedTextNode, parent,
                                             typedValues);
        }
        else if ( xqType!=NULL &&
                  (xqType->content_kind()==XQType::ELEMENT_ONLY_CONTENT_KIND ||
                   xqType->content_kind()==XQType::EMPTY_CONTENT_KIND ))
        {
          // if text not valid the schemaValidator should have already
          // thrown an error

          // XQ XP Datamodel Spec: http://www.w3.org/TR/xpath-datamodel/
          // section 6.7.4 Construction from a PSVI
          if ( !utf8::is_whitespace(childStringValue) )
          {
            zstring empty;
            GENV_ITEMFACTORY->createTextNode(validatedTextNode,
                                             parent,
                                             empty);
            //cout << "      -- create empty text : ElementOnly || Empty" << endl;
          }
          else 
          {
            //cout << "      -- skip this text: (ElemOnly || Empty) && whitespace" << endl;
          }
        }
        else
          //if ( xqType!=NULL &&
          //     xqType->content_kind()==XQType::MIXED_CONTENT_KIND )
        {
          // if text not valid the schemaValidator should have already
          // thrown an error
          GENV_ITEMFACTORY->createTextNode(validatedTextNode,
                                           parent,
                                           childStringValue);
          //cout << "      -- create empty text: Mixed" << endl;
        }
      }
      break;

      case store::StoreConsts::piNode:
      {
        //cout << "     - pi: " << child->getStringValue() << "\n";cout.flush();
        store::Item_t piNode;
        zstring piTarget =child->getTarget();
        zstring childStringValue;
        child->getStringValue2(childStringValue);
        zstring childBaseUri;
        child->getBaseURI(childBaseUri);

        GENV_ITEMFACTORY->createPiNode(piNode, parent, piTarget,
                                       childStringValue, childBaseUri);
      }
      break;

      case store::StoreConsts::commentNode:
      {
        //cout << "     - comment: " << child->getStringValue() <<
        //"\n"; cout.flush();
        store::Item_t commentNode;
        zstring childStringValue;
        child->getStringValue2(childStringValue);
        GENV_ITEMFACTORY->createCommentNode(commentNode, parent, childStringValue);
      }
      break;

      case store::StoreConsts::anyNode:
        //cout << "     - any: " << child->getStringValue() <<"\n";cout.flush();
        ZORBA_ASSERT(false);
        break;

      default:
        ZORBA_ASSERT(false);
      }
    }
  }
}


void Validator::processNamespaces (
    EventSchemaValidator& schemaValidator,
    const store::Item_t& item)
{
  store::NsBindings bindings;
  item->getNamespaceBindings(bindings,
                             store::StoreConsts::ONLY_LOCAL_NAMESPACES);

  for (unsigned long i = 0; i < bindings.size(); i++)
  {
    schemaValidator.ns(bindings[i].first, bindings[i].second);
  }
}


void Validator::processTextValue(
    const static_context* sctx,
    TypeManager* typeManager,
    store::NsBindings& bindings,
    const store::Item_t& typeQName,
    zstring& textValue,
    std::vector<store::Item_t>& resultList,
    const QueryLoc& loc)
{
  xqtref_t type = typeManager->create_named_type(typeQName.getp(),
                                                 TypeConstants::QUANT_ONE);

  //cout << "     - processTextValue: " << typeQName->getPrefix()->str()
  //     << ":" << typeQName->getLocalName()->str() << "@"
  //     << typeQName->getNamespace()->str() ; cout.flush();
  //cout << " type: " << (type==NULL ? "NULL" : type->toString()) << "\n"; cout.flush();

  // TODO: we probably need the ns bindings from the static context
  // surrounding the original validate_expr, not planState.sctx()
  namespace_context nsCtx = namespace_context(sctx, bindings);

  store::Item_t result;
  if (type != NULL)
  {
    if ( type->type_kind() == XQType::USER_DEFINED_KIND )
    {
      const UserDefinedXQType udt = static_cast<const UserDefinedXQType&>(*type);
      
      if ( udt.isList() || udt.isUnion() )
      {
        typeManager->getSchema()->parseUserSimpleTypes(textValue, type, resultList, loc);
      }
      else if (udt.isAtomic())
      {
        bool res = typeManager->getSchema()->
          parseUserAtomicTypes(textValue, type.getp(), result, &nsCtx, loc);

        ZORBA_ASSERT(res);
        resultList.push_back(result);
      }
      else if (udt.isComplex() &&
               udt.content_kind() == XQType::SIMPLE_CONTENT_KIND)
      {
        try
        {
          // if complex type with simple content parse text by the base
          // type which has to be simple
          xqtref_t baseType = udt.getBaseType();
          
          while ( baseType->type_kind() == XQType::USER_DEFINED_KIND &&
			      static_cast<const UserDefinedXQType&>(*baseType).isComplex() )
          {
            const UserDefinedXQType udBaseType = static_cast<const UserDefinedXQType&>(*baseType);
            baseType = udBaseType.getBaseType();
          }
          bool res = GenericCast::castToSimple(textValue, baseType.getp(),
                                               resultList, typeManager, loc);

          // if this assert fails it means the validator and zorba casting code
          // don't follow the same rules
          ZORBA_ASSERT(res);
        }
        catch(ZorbaException const& /*err*/)
        {
          // do nothing here, the validator will throw the right error at end
          // elemet event call
          //std::cout << "validate.cpp: processTextValue1 '" << textValue << "' err:" << err.toString() << std::endl; std::cout.flush();
        }
      }
    }
    else if (type->type_kind() == XQType::ATOMIC_TYPE_KIND)
    {
      try
      {
        bool res = GenericCast::castToAtomic(result, textValue, type.getp(),
                                             typeManager, &nsCtx, loc);
        ZORBA_ASSERT(res);
        resultList.push_back(result);
      }
      catch(ZorbaException const& /*err*/)
      {
        // do nothing here, the validator will throw the right error at end elemet event call
        //std::cout << "validate.cpp: processTextValue2 '" << textValue << "' err:" << err.toString() << std::endl; std::cout.flush();
      } 
    }
    else
    {
      if ( GENV_ITEMFACTORY->createUntypedAtomic( result, textValue) )
        resultList.push_back(result);
    }
  }
  else
  {
    if ( GENV_ITEMFACTORY->createUntypedAtomic( result, textValue) )
      resultList.push_back(result);
  }
}

} // namespace zorba

#endif // ifndef ZORBA_NO_XMLSCHEMA
/* vim:set et sw=2 ts=2: */
