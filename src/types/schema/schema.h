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
#pragma once
#ifndef ZORBA_SCHEMA_H_
#define ZORBA_SCHEMA_H_

#include "common/common.h"

#ifndef ZORBA_NO_XMLSCHEMA
#include <xercesc/sax/EntityResolver.hpp>
#ifdef CYGWIN
#undef WIN32
#endif
#include <iostream>
#endif // ZORBA_NO_XMLSCHEMA

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"

#include "zorbatypes/schema_types.h"


#define ZORBA_HASHMAP_WITH_SERIALIZATION
#include "zorbautils/hashmap_zstring.h"
#undef ZORBA_HASHMAP_WITH_SERIALIZATION

#include "zorbaserialization/class_serializer.h"


namespace XERCES_CPP_NAMESPACE {
  class InputSource;
  class XSTypeDefinition;
  class XSElementDeclaration;
  class XSParticle;
  class XMLGrammarPool;
}

namespace zorba
{

// Forward reference
namespace internal
{
  class StreamResource;
}

/*******************************************************************************

*******************************************************************************/
class Schema : public ::zorba::serialization::SerializeBaseClass
{
  ZSTRING_HASH_MAP(xqtref_t, UdTypesCache);

public:
  static const char* XSD_NAMESPACE;

private:
  TypeManager                              * theTypeManager;

  bool                                       theHasXSD;
#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE::XMLGrammarPool     * theGrammarPool;

  UdTypesCache                             * theUdTypesCache;
#endif // ZORBA_NO_XMLSCHEMA

public:
  SERIALIZABLE_CLASS(Schema)
  Schema(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  Schema(TypeManager* tm);

  virtual ~Schema();

  void printXSDInfo(bool excludeBuiltIn = true);

  bool hasXSD() const { return theHasXSD; }

#ifndef ZORBA_NO_XMLSCHEMA

  XERCES_CPP_NAMESPACE::XMLGrammarPool* getGrammarPool() const
  {
    return theGrammarPool;
  }

  void registerXSD(
      const char* xsdURL,
      static_context* sctx,
      internal::StreamResource* streamResource,
      const QueryLoc& loc);

  void getInfoFromGlobalElementDecl(
      const store::Item* qname,
      store::Item_t& typeName,
      bool& nillable,
      const QueryLoc& loc);

  xqtref_t createXQTypeFromGlobalElementDecl(
      const TypeManager* typeManager,
      const store::Item* qname,
      const bool raiseErrors,
      bool& nillable,
      const QueryLoc& loc);

  void getInfoFromGlobalAttributeDecl(
      const store::Item* qname,
      store::Item_t& typeName,
      const QueryLoc& loc);

  xqtref_t createXQTypeFromGlobalAttributeDecl(
      const TypeManager* typeManager,
      const store::Item* qname,
      const bool riseErrors,
      const QueryLoc& loc);

  xqtref_t createXQTypeFromTypeName(
      const TypeManager* manager,
      const store::Item* qname);

  void getSubstitutionHeadForElement(
      const store::Item* qname,
      store::Item_t& result);

#endif // ZORBA_NO_XMLSCHEMA

  bool parseUserSimpleTypes(
      zstring& textValue,
      const xqtref_t& aTargetType,
      std::vector<store::Item_t>& resultList,
      const namespace_context* nsCtx,
      const QueryLoc& loc,
      bool isCasting);

  bool parseUserAtomicTypes(
      zstring& textValue,
      const xqtref_t& aTargetType,
      store::Item_t& result,
      const namespace_context* nsCtx,
      const QueryLoc& loc,
      bool isCasting);

  bool parseUserListTypes(
      const zstring& textValue,
      const xqtref_t& aTargetType,
      std::vector<store::Item_t>& resultList,
      const namespace_context* nsCtx,
      const QueryLoc& loc,
      bool isCasting);

  bool parseUserUnionTypes(
      zstring& textValue,
      const xqtref_t& aTargetType,
      std::vector<store::Item_t>& resultList,
      const namespace_context* nsCtx,
      const QueryLoc& loc,
      bool isCasting);

private:

#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE::XSElementDeclaration* getDeclForElement(
      const store::Item* qname);

  XERCES_CPP_NAMESPACE::XSTypeDefinition* getTypeDefForAttribute(
      const store::Item* qname);

  xqtref_t createXQTypeFromTypeDefinition(
      const TypeManager* typeManager,
      XERCES_CPP_NAMESPACE::XSTypeDefinition* xsTypeDef);

  xqtref_t createXQTypeFromTypeDefForBuiltinTypes(
      const TypeManager* typeManager,
      zstring& strUri,
      const XMLCh* local);

  void checkForAnonymousTypes(const TypeManager* typeManager);

  void checkForAnonymousTypesInType(
      const TypeManager* typeManager,
      XERCES_CPP_NAMESPACE::XSTypeDefinition* typeDef);

  void checkForAnonymousTypesInParticle(
      const TypeManager* typeManager,
      XERCES_CPP_NAMESPACE::XSParticle *xsParticle);

  void addAnonymousTypeToCache(
      const TypeManager* typeManager,
      XERCES_CPP_NAMESPACE::XSTypeDefinition* typeDef);

  void addTypeToCache(xqtref_t itemXQType);
#endif // ZORBA_NO_XMLSCHEMA
};

} // namespace zorba

#endif /*ZORBA_SCHEMA_H_*/
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
