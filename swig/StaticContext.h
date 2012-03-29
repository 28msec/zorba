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
#ifndef API_STATIC_CONTEXT_H
#define API_STATIC_CONTEXT_H

#include <zorba/static_context_consts.h>

class ZorbaConstants
{
public:
  typedef enum {
    PRESERVE,
    NO_PRESERVE
  } PreserveMode;

  typedef enum {
    INHERIT,
    NO_INHERIT
  } InheritMode;

  typedef enum {
    PRESERVE_SPACE,
    STRIP_SPACE
  } BoundarySpaceMode;

  typedef enum {
    PRESERVE_CONSTRUCTION,
    STRIP_CONSTRUCTION
  } ConstructionMode;

  typedef enum {
    EMPTY_GREATEST,
    EMPTY_LEAST
  } OrderEmptyMode;

  typedef enum {
    ORDERED,
    UNORDERED
  } OrderingMode;

  typedef enum {
    VALIDATE_SKIP,
    VALIDATE_LAX,
    VALIDATE_STRICT
  } RevalidationMode;

  typedef enum {
    XPATH2_0,
    XPATH1_0
  } XPath1_0CompatibleMode;

}; // ZorbaConstants

class StaticContext 
{
friend class Zorba;
friend class XQuery;

private:
  zorba::StaticContext_t theStaticContext;
public:

  StaticContext(const StaticContext& aStaticContext);
  StaticContext(zorba::StaticContext_t aStaticContext);
  
  void addColation(const std::string& aURI); 
  bool addNamespace(const std::string& aPrefix,
                            const std::string& aURI);

  bool containsFunction(const std::string &aFnNameUri, 
                                const std::string &aFnNameLocal, 
                                int arity) const;

  StaticContext createChildContext() const;
  void declareOption(const Item &aQName, 
                             const std::string &aOptionVal);
  void disableFunction(const Item &aQName, int arity);

  std::string getBaseURI () const;

  ZorbaConstants::BoundarySpaceMode getBoundarySpacePolicy ();
  ZorbaConstants::ConstructionMode  getConstructionMode();
  ZorbaConstants::PreserveMode getCopyNamespacesModePreserve();
  ZorbaConstants::InheritMode  getCopyNamespacesModeInherit();
  ZorbaConstants::OrderEmptyMode getDefaultOrderForEmptySequences();
  ZorbaConstants::OrderingMode getOrderingMode();
  ZorbaConstants::RevalidationMode getRevalidationMode();
  ZorbaConstants::XPath1_0CompatibleMode getXPath1_0CompatibMode();

  std::string getDefaultCollation () const;
  std::string getDefaultElementAndTypeNamespace () const;
  std::string getDefaultFunctionNamespace () const;
  
  std::vector< std::pair< std::string, std::string > > getNamespaceBindings ();

  std::string getNamespaceURIByPrefix(const std::string &aPrefix) const;
  bool getOption(const Item &aQName, std::string &aOptionValue) const;
  void loadProlog (const std::string & aProlog, const CompilerHints &hints);

  void getExternalVariables(Iterator& vars) const;
  
  TypeIdentifier getCollectionType(const std::string &aCollectionUri);
  TypeIdentifier getDocumentType(const std::string &aDocUri);
  TypeIdentifier getContextItemStaticType();

  void setContextItemStaticType(const TypeIdentifier &aType);
  
  void resetTraceStream ();
  bool setBaseURI (const std::string &aBaseURI);

  bool setBoundarySpacePolicy (ZorbaConstants::BoundarySpaceMode aMode);
  bool setConstructionMode (ZorbaConstants::ConstructionMode aMode);
  bool setCopyNamespacesMode (ZorbaConstants::PreserveMode aPreserve, ZorbaConstants::InheritMode aInherit);
  bool setDefaultOrderForEmptySequences (ZorbaConstants::OrderEmptyMode aMode);
  bool setOrderingMode (ZorbaConstants::OrderingMode aMode);
  void setRevalidationMode (ZorbaConstants::RevalidationMode aMode);

  void setURIPath(std::vector< std::string > &aURIPath );
  void setLIBPath(std::vector< std::string > &aLIBPath );
  void setModulePath(std::vector< std::string > &aModulePath );

  bool setXPath1_0CompatibMode (ZorbaConstants::XPath1_0CompatibleMode aMode);
  
  void setDefaultCollation (const std::string &aURI);
  bool setDefaultElementAndTypeNamespace (const std::string &aURI);
  bool setDefaultFunctionNamespace (const std::string &aURI);

  void destroy();
}; // class StaticContext

#endif