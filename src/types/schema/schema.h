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
#include "xercesIncludes.h"
#include "XercesParseUtils.h"

#include <zorba/api_shared_types.h>

#include "common/shared_types.h"
#include "zorbatypes/xqpstring.h"
#include "util/hashmap.h"

#include "types/typeconstants.h"
#include "types/schema/EventSchemaValidator.h"

#include "store/api/item.h"

namespace zorba
{

#ifndef ZORBA_NO_XMLSCHEMA

/*******************************************************************************

********************************************************************************/
class SchemaLocationEntityResolver : public EntityResolver
{
protected:
  std::string   theLocation;
  const XMLCh * theLogicalURI;

public:
  SchemaLocationEntityResolver(
        const XMLCh* const logical_uri,
        std::string& location);

  InputSource* resolveEntity(
        const XMLCh* const publicId,
        const XMLCh* const systemId);
};        

#endif


/*******************************************************************************

********************************************************************************/
class Schema
{
public:
  static const char* XSD_NAMESPACE;

private:
  static bool                            _isInitialized;

#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE::XMLGrammarPool * _grammarPool;
  hashmap<xqtref_t>                    * _udTypesCache;
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
    return _grammarPool;
  }

  void registerXSD(
        const char* xsdFileName,
        std::string& loaction,
        const QueryLoc& loc);

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

  store::Item_t parseAtomicValue(xqtref_t type, xqp_string textValue);    

  // user defined simple types, i.e. Atomic, List or Union Types
  bool parseUserSimpleTypes(
        const xqp_string textValue,
        const xqtref_t& aTargetType,
        std::vector<store::Item_t> &resultList);    

  // user defined atomic types
  bool parseUserAtomicTypes(
        const xqp_string textValue,
        const xqtref_t& aTargetType, 
        store::Item_t &result);    

  // user defined list types
  bool parseUserListTypes(
        const xqp_string textValue,
        const xqtref_t& aTargetType, 
        std::vector<store::Item_t>& resultList);    

  // user defined union types
  bool parseUserUnionTypes(
        const xqp_string textValue,
        const xqtref_t& aTargetType, 
        std::vector<store::Item_t> &resultList);    
  
  // user defined simple types, i.e. Atomic, List or Union Types
  bool isCastableUserSimpleTypes(
        const xqp_string textValue,
        const xqtref_t& aTargetType);

  // user defined atomic types
  bool isCastableUserAtomicTypes(
        const xqp_string textValue,
        const xqtref_t& aTargetType);

  // user defined list types
  bool isCastableUserListTypes(
        const xqp_string textValue,
        const xqtref_t& aTargetType);

  // user defined union types
  bool isCastableUserUnionTypes(
        const xqp_string textValue,
        const xqtref_t& aTargetType);

private:

#ifndef ZORBA_NO_XMLSCHEMA

  XSTypeDefinition* getTypeDefForElement(const store::Item* qname);

  XSTypeDefinition* getTypeDefForAttribute(const store::Item* qname);

  xqtref_t createXQTypeFromTypeDefinition(
        const TypeManager* typeManager,
        XSTypeDefinition* xsTypeDef);

  void checkForAnonymousTypesInType(const TypeManager* typeManager, XSTypeDefinition* typeDef);
  void checkForAnonymousTypesInParticle(const TypeManager* typeManager, XSParticle *xsParticle);
  void addAnonymousTypeToCache(const TypeManager* typeManager, XSTypeDefinition* typeDef);
  void addTypeToCache(xqtref_t itemXQType);

#endif
};

} // namespace zorba

#endif /*ZORBA_SCHEMA_H_*/
/*
 * Local variables:
 * mode: c++
 * End:
 */
