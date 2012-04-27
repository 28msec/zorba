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


%{  // start Implementation

#include <zorba/static_context_consts.h>


StaticContext::StaticContext(const StaticContext& aStaticContext) : 
    theStaticContext(aStaticContext.theStaticContext) {}
    
StaticContext::StaticContext(zorba::StaticContext_t aStaticContext) : 
    theStaticContext(aStaticContext) {}

void StaticContext::addColation(const std::string& aURI)
  { theStaticContext->addCollation(aURI); }

bool StaticContext::addNamespace(const std::string& aPrefix, const std::string& aURI)
  { return theStaticContext->addNamespace(aPrefix, aURI); }

bool StaticContext::containsFunction(const std::string &aFnNameUri, const std::string &aFnNameLocal, int arity) const 
  { return theStaticContext->containsFunction(aFnNameUri, aFnNameLocal, arity); }

StaticContext	StaticContext::createChildContext() const
  { return StaticContext(theStaticContext->createChildContext()); }
  
void 	StaticContext::declareOption (const Item &aQName, const std::string &aOptionVal)
  { return theStaticContext->declareOption(aQName.theItem, aOptionVal); }

void 	StaticContext::disableFunction (const Item &aQName, int arity)
  { theStaticContext->disableFunction( aQName.theItem, arity); }

std::string StaticContext::getBaseURI () const
  { return std::string(theStaticContext->getBaseURI().c_str()); }

ZorbaConstants::BoundarySpaceMode StaticContext::getBoundarySpacePolicy()
  { 
    ZorbaConstants::BoundarySpaceMode result = ZorbaConstants::PRESERVE_SPACE;
    zorba::boundary_space_mode_t boundary = theStaticContext->getBoundarySpacePolicy();
    if (boundary == zorba::strip_space) {
      result = ZorbaConstants::STRIP_SPACE;
    }
    return result;
  }

ZorbaConstants::ConstructionMode StaticContext::getConstructionMode() 
  { 
    ZorbaConstants::ConstructionMode result = ZorbaConstants::STRIP_CONSTRUCTION;
    zorba::construction_mode_t construction = theStaticContext->getConstructionMode();
    if (construction == zorba::preserve_cons) {
      result = ZorbaConstants::PRESERVE_CONSTRUCTION;
    }
    return result;
  }		

ZorbaConstants::PreserveMode StaticContext::getCopyNamespacesModePreserve()
  { 
    zorba::preserve_mode_t lPreserve;
    zorba::inherit_mode_t lInherit;
    ZorbaConstants::PreserveMode aPreserve = ZorbaConstants::NO_PRESERVE;
    theStaticContext->getCopyNamespacesMode(lPreserve, lInherit); 
    if (lPreserve==zorba::preserve_ns) {
      aPreserve = ZorbaConstants::PRESERVE;
    }
    return aPreserve;
  }

ZorbaConstants::InheritMode StaticContext::getCopyNamespacesModeInherit()
  { 
    zorba::preserve_mode_t lPreserve;
    zorba::inherit_mode_t lInherit;
    ZorbaConstants::InheritMode aInherit = ZorbaConstants::NO_INHERIT;
    theStaticContext->getCopyNamespacesMode(lPreserve, lInherit); 
    if (lInherit==zorba::inherit_ns) {
      aInherit = ZorbaConstants::INHERIT;
    }
    return aInherit;
  }

std::string StaticContext::getDefaultCollation () const 
  { return std::string(theStaticContext->getDefaultCollation().c_str()); }

std::string StaticContext::getDefaultElementAndTypeNamespace () const 
  { 
    return std::string( theStaticContext->getDefaultElementAndTypeNamespace().c_str() ); 
  }

std::string StaticContext::getDefaultFunctionNamespace () const 
  { 
    return std::string( theStaticContext->getDefaultFunctionNamespace().c_str() );
  }

ZorbaConstants::OrderEmptyMode StaticContext::getDefaultOrderForEmptySequences()
  { 
    ZorbaConstants::OrderEmptyMode result = ZorbaConstants::EMPTY_GREATEST;
    zorba::order_empty_mode_t order = theStaticContext->getDefaultOrderForEmptySequences();
    if (order == zorba::empty_least) {
      result = ZorbaConstants::EMPTY_LEAST;
    }
    return result;
  }

std::string StaticContext::getNamespaceURIByPrefix(const std::string &aPrefix) const
  {
    return std::string( theStaticContext->getNamespaceURIByPrefix(aPrefix).c_str() );
  }

bool StaticContext::getOption(const Item &aQName, std::string &aOptionValue) const
  { 
    zorba::String optVal = zorba::String(aOptionValue.c_str());
    return theStaticContext->getOption(aQName.theItem, optVal); 
  }

ZorbaConstants::OrderingMode StaticContext::getOrderingMode ()
  { 
    ZorbaConstants::OrderingMode result = ZorbaConstants::ORDERED;
    zorba::ordering_mode_t order = theStaticContext->getOrderingMode();
    if (order == zorba::unordered) {
      result = ZorbaConstants::UNORDERED;
    }
    return result;
  }

ZorbaConstants::RevalidationMode StaticContext::getRevalidationMode ()
  { 
    ZorbaConstants::RevalidationMode result = ZorbaConstants::VALIDATE_SKIP;
    zorba::validation_mode_t revalidation = theStaticContext->getRevalidationMode();
    if (revalidation == zorba::validate_lax) {
      result = ZorbaConstants::VALIDATE_LAX;
    } else if (revalidation == zorba::validate_strict) {
      result = ZorbaConstants::VALIDATE_STRICT;
    }
    return result;
  }

ZorbaConstants::XPath1_0CompatibleMode StaticContext::getXPath1_0CompatibMode ()
  { 
    ZorbaConstants::XPath1_0CompatibleMode result = ZorbaConstants::XPATH2_0;
    zorba::xpath1_0compatib_mode_t comp = theStaticContext->getXPath1_0CompatibMode();
    if (comp == zorba::xpath1_0) {
      result = ZorbaConstants::XPATH1_0;
    }
    return result;
  }

void StaticContext::loadProlog (const std::string & aProlog, const CompilerHints &hints)
  { theStaticContext->loadProlog( aProlog, hints.theCompilerHints); }

void StaticContext::getExternalVariables(Iterator vars) const 
  { theStaticContext->getExternalVariables( vars.theIterator ); }

  StaticCollectionManager StaticContext::getStaticCollectionManager()
  {
    return StaticCollectionManager( theStaticContext->getStaticCollectionManager() );
  }

TypeIdentifier StaticContext::getCollectionType(const std::string & aCollectionUri)
  { return TypeIdentifier(theStaticContext->getCollectionType(aCollectionUri)); }
  
TypeIdentifier StaticContext::getDocumentType(const std::string &aDocUri)
  { return TypeIdentifier(theStaticContext->getDocumentType(aDocUri)); }
  
TypeIdentifier StaticContext::getContextItemStaticType()
  { return TypeIdentifier(theStaticContext->getContextItemStaticType()); }

std::vector< std::pair< std::string, std::string > > StaticContext::getNamespaceBindings () {
  std::vector< std::pair< zorba::String, zorba::String > > items;
  std::vector< std::pair< std::string, std::string > > result;
  theStaticContext->getNamespaceBindings(items);
  std::vector< std::pair< zorba::String, zorba::String > >::iterator iter;
  for(iter = items.begin(); iter != items.end(); iter++) {
    std::pair< std::string, std::string > pair;
    pair.first = (*iter).first.c_str();
    pair.second = (*iter).second.c_str();
    result.push_back(pair);
  }
  return result;
}
  
  
  
void StaticContext::setContextItemStaticType(const TypeIdentifier &aType)
  { theStaticContext->setContextItemStaticType(aType.theTypeIdentifier); }
  
void StaticContext::resetTraceStream ()
  { theStaticContext->resetTraceStream(); }

bool StaticContext::setBaseURI (const std::string &aBaseURI)
  { return theStaticContext->setBaseURI(aBaseURI); }

bool StaticContext::setBoundarySpacePolicy (ZorbaConstants::BoundarySpaceMode aMode)
  {
    zorba::boundary_space_mode_t lMode = zorba::strip_space;
    if (aMode == ZorbaConstants::PRESERVE_SPACE) {
      lMode = zorba::preserve_space;
    }
    return theStaticContext->setBoundarySpacePolicy(lMode);
  }

bool StaticContext::setConstructionMode (ZorbaConstants::ConstructionMode aMode)
  {
    zorba::construction_mode_t lMode = zorba::preserve_cons;
    if (aMode == ZorbaConstants::STRIP_CONSTRUCTION) {
      lMode = zorba::strip_cons;
    }
    return theStaticContext->setConstructionMode(lMode);
  }

bool StaticContext::setCopyNamespacesMode (ZorbaConstants::PreserveMode aPreserve, ZorbaConstants::InheritMode aInherit)
  {
    zorba::preserve_mode_t lPreserve = zorba::no_preserve_ns;
    zorba::inherit_mode_t lInherit = zorba::no_inherit_ns;
    if (aPreserve == ZorbaConstants::PRESERVE) {
      lPreserve = zorba::preserve_ns;
    }
    if (aInherit == ZorbaConstants::INHERIT) {
      lInherit = zorba::inherit_ns;
    }
    return theStaticContext->setCopyNamespacesMode(lPreserve, lInherit);
  }   

void StaticContext::setDefaultCollation (const std::string &aURI)
  { theStaticContext->setDefaultCollation(aURI); }

bool StaticContext::setDefaultElementAndTypeNamespace (const std::string &aURI)
  { return theStaticContext->setDefaultElementAndTypeNamespace(aURI); }

bool StaticContext::setDefaultFunctionNamespace (const std::string &aURI)
  { return theStaticContext->setDefaultFunctionNamespace(aURI); }

bool StaticContext::setDefaultOrderForEmptySequences (ZorbaConstants::OrderEmptyMode aMode)
  {
    zorba::order_empty_mode_t lMode = zorba::empty_greatest;
    if (aMode == ZorbaConstants::EMPTY_LEAST) {
      lMode = zorba::empty_least;
    }
    return theStaticContext->setDefaultOrderForEmptySequences(lMode);
  }

bool StaticContext::setOrderingMode (ZorbaConstants::OrderingMode aMode)
  {
    zorba::ordering_mode_t lMode = zorba::ordered;
    if (aMode == ZorbaConstants::UNORDERED) {
      lMode = zorba::unordered;
    }
    return theStaticContext->setOrderingMode(lMode);
  }

void StaticContext::setRevalidationMode (ZorbaConstants::RevalidationMode aMode)
  {
    zorba::validation_mode_t lMode = zorba::validate_skip;
    if (aMode == ZorbaConstants::VALIDATE_LAX) {
      lMode = zorba::validate_lax;
    } else if (aMode == ZorbaConstants::VALIDATE_STRICT) {
      lMode = zorba::validate_strict;
    }
    return theStaticContext->setRevalidationMode(lMode);
  }

void StaticContext::setURIPath(std::vector< std::string > &aURIPath )
  {
    std::vector< zorba::String > lURIPath;
    lURIPath.reserve(aURIPath.size());
    std::vector< std::string >::iterator iter;
    for(iter = aURIPath.begin(); iter != aURIPath.end(); iter++) {
      lURIPath.push_back((*iter));
    }    
    theStaticContext->setURIPath(lURIPath);
  }

void StaticContext::setLIBPath(std::vector< std::string > &aLIBPath )
  {
    std::vector< zorba::String > lLIBPath;
    lLIBPath.reserve(aLIBPath.size());
    std::vector< std::string >::iterator iter;
    for(iter = aLIBPath.begin(); iter != aLIBPath.end(); iter++) {
      lLIBPath.push_back((*iter));
    }    
    theStaticContext->setLibPath(lLIBPath);
  }

void StaticContext::setModulePath(std::vector< std::string > &aModulePath )
  {
    std::vector< zorba::String > lModulePath;
    lModulePath.reserve(aModulePath.size());
    std::vector< std::string >::iterator iter;
    for(iter = aModulePath.begin(); iter != aModulePath.end(); iter++) {
      lModulePath.push_back((*iter));
    }    
    theStaticContext->setModulePaths(lModulePath);
  }

bool StaticContext::setXPath1_0CompatibMode (ZorbaConstants::XPath1_0CompatibleMode aMode)
  {
    zorba::xpath1_0compatib_mode_t lMode = zorba::xpath2_0;
    if (aMode == ZorbaConstants::XPATH1_0) {
      lMode = zorba::xpath1_0;
    }
    return theStaticContext->setXPath1_0CompatibMode(lMode);
  }

void StaticContext::destroy() 
  { theStaticContext = 0; }
   
 // class StaticContext




%}  // end Implementation


// Interface

%rename(XPath1_0CompatibModeEnum) zorba::xpath1_0compatib_mode_t;
%rename(XPATH2_0) xpath2_0;
%rename(XPATH1_0) xpath1_0;

%rename(OrderingModeEnum) zorba::ordering_mode_t;
%rename(ORDERED) ordered;
%rename(UNORDERED) unordered;

%rename(OrderEmptyModeEnum) zorba::order_empty_mode_t;
%rename(EMPTY_GREATEST) empty_greatest;
%rename(EMPTY_LEAST) empty_least;

%rename(InheritModeEnum) zorba::inherit_mode_t;
%rename(INHERIT_NS) inherit_ns;
%rename(NO_INHERIT_NS) no_inherit_ns;

%rename(PreserveModeEnum) zorba::preserve_mode_t;
%rename(PRESERVE_NS) preserve_ns;
%rename(NO_PRESERVE_NS) no_preserve_ns;

%rename(BoundarySpaceModeEnum) zorba::boundary_space_mode_t;
%rename(PRESERVE_SPACE) preserve_space;
%rename(STRIP_SPACE) strip_space;

%rename(ConstructionModeEnum) zorba::construction_mode_t;
%rename(PRESERVE_CONS) preserve_cons;
%rename(STRIP_CONS) strip_cons;

%rename(XQueryVersionEnum) zorba::xquery_version_t;
%rename(XQUERY_VERSION_1_0) xquery_version_1_0;
%rename(XQUERY_VERSION_3_0) xquery_version_3_0;

%rename(ValidationModeEnum) zorba::validation_mode_t;
%rename(VALIDATE_SKIP) validate_skip;
%rename(VALIDATE_LAX) validate_lax;
%rename(VALIDATE_STRICT) validate_strict;

%include "StaticContext.h"
