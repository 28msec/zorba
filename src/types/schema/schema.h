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
#ifndef ZORBA_SCHEMA_H_
#define ZORBA_SCHEMA_H_

#include "common/common.h"

#include <xercesc/sax/EntityResolver.hpp>
#ifdef CYGWIN
#undef WIN32
#endif


#include <zorba/api_shared_types.h>
#include "common/shared_types.h"

#include "zorbatypes/representations.h" 


#define ZORBA_HASHMAP_WITH_SERIALIZATION
#include "util/hashmap.h"
#undef ZORBA_HASHMAP_WITH_SERIALIZATION

#include "zorbaserialization/serialization_engine.h"


namespace XERCES_CPP_NAMESPACE {
  class InputSource;
  class XSTypeDefinition;
  class XSParticle;
  class XMLGrammarPool;
}

namespace zorba
{

#ifndef ZORBA_NO_XMLSCHEMA

/*******************************************************************************

********************************************************************************/
class SchemaLocationEntityResolver : public XERCES_CPP_NAMESPACE::EntityResolver
{
protected:
    std::string theLocation;
  const XMLCh * theLogicalURI;

public:
  SchemaLocationEntityResolver(
        const XMLCh* const logical_uri,
        std::string& location);

  XERCES_CPP_NAMESPACE::InputSource* resolveEntity(
        const XMLCh* const publicId,
        const XMLCh* const systemId);
};        

#endif


/*******************************************************************************

********************************************************************************/
class Schema : public ::zorba::serialization::SerializeBaseClass
{
public:
    static const char* XSD_NAMESPACE;

private:
  static bool                            theIsInitialized;

#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE::XMLGrammarPool * theGrammarPool;
  serializable_hashmap<xqtref_t>       * theUdTypesCache;
#endif

public:
    static void initialize();

    static void terminate();

public:
    Schema();

    virtual ~Schema();

    void printXSDInfo(bool excludeBuiltIn = true);

#ifndef ZORBA_NO_XMLSCHEMA

  XERCES_CPP_NAMESPACE::XMLGrammarPool* getGrammarPool() const 
  {
    return theGrammarPool;
  }

  void registerXSD(
        const char* xsdFileName,
        std::string& loaction,
        const QueryLoc& loc);

  void getSubstitutionHeadForElement(
        const store::Item* qname,
        store::Item_t& result);

  void getTypeNameFromElementName(
        const store::Item* qname,
        store::Item_t& typeName);

  void getTypeNameFromAttributeName(
        const store::Item* qname,
        store::Item_t& typeName);

  xqtref_t createXQTypeFromElementName(
        const TypeManager* typeManager,
        const store::Item* qname,
        const bool riseErrors);

  xqtref_t createXQTypeFromAttributeName(
        const TypeManager* typeManager,
        const store::Item* qname);

  xqtref_t createXQTypeFromTypeName(
        const TypeManager* manager,
        const store::Item* qname);

#endif

    // user defined simple types, i.e. Atomic, List or Union Types
  bool parseUserSimpleTypes(
        xqpStringStore_t& textValue,
        const xqtref_t& aTargetType,
        std::vector<store::Item_t> &resultList);    

    // user defined atomic types
  bool parseUserAtomicTypes(
        xqpStringStore_t& textValue,
        const xqtref_t& aTargetType, 
        store::Item_t& result);    

    // user defined list types
  bool parseUserListTypes(
        const xqpStringStore_t& textValue,
        const xqtref_t& aTargetType, 
        std::vector<store::Item_t>& resultList);    

    // user defined union types
  bool parseUserUnionTypes(
        xqpStringStore_t& textValue,
        const xqtref_t& aTargetType, 
        std::vector<store::Item_t> &resultList);    
  
    // user defined simple types, i.e. Atomic, List or Union Types
  bool isCastableUserSimpleTypes(
        const xqpStringStore_t& textValue,
        const xqtref_t& aTargetType);

    // user defined atomic types
  bool isCastableUserAtomicTypes(
        const xqpStringStore_t& textValue,
        const xqtref_t& aTargetType);

    // user defined list types
  bool isCastableUserListTypes(
        const xqpStringStore_t& textValue,
        const xqtref_t& aTargetType);

    // user defined union types
  bool isCastableUserUnionTypes(
        const xqpStringStore_t& textValue,
        const xqtref_t& aTargetType);

private:

#ifndef ZORBA_NO_XMLSCHEMA

  XERCES_CPP_NAMESPACE::XSTypeDefinition* getTypeDefForElement(const store::Item* qname);

  XERCES_CPP_NAMESPACE::XSTypeDefinition* getTypeDefForAttribute(const store::Item* qname);

  xqtref_t createXQTypeFromTypeDefinition(
        const TypeManager* typeManager,
        XERCES_CPP_NAMESPACE::XSTypeDefinition* xsTypeDef);

  xqtref_t createXQTypeFromTypeDefForBuiltinTypes(
        const TypeManager* typeManager,
    xqpStringStore_t strUri, const XMLCh* local);

  void checkForAnonymousTypes(const TypeManager* typeManager);

  void checkForAnonymousTypesInType(const TypeManager* typeManager,
                                    XERCES_CPP_NAMESPACE::XSTypeDefinition* typeDef);
  void checkForAnonymousTypesInParticle(const TypeManager* typeManager,
                                        XERCES_CPP_NAMESPACE::XSParticle *xsParticle);
  void addAnonymousTypeToCache(const TypeManager* typeManager,
                               XERCES_CPP_NAMESPACE::XSTypeDefinition* typeDef);
  void addTypeToCache(xqtref_t itemXQType);

#endif
public:
  SERIALIZABLE_CLASS(Schema)
  Schema(::zorba::serialization::Archiver &ar);
  void serialize(::zorba::serialization::Archiver &ar);
};

} // namespace zorba

#endif /*ZORBA_SCHEMA_H_*/
/*
 * Local variables:
 * mode: c++
 * End:
 */
