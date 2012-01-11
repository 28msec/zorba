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


StaticContext::StaticContext() {}

StaticContext::StaticContext(const StaticContext& aStaticContext) : 
    theStaticContext(aStaticContext.theStaticContext) {}
    
StaticContext::StaticContext(zorba::StaticContext_t aStaticContext) : 
    theStaticContext(aStaticContext) {}

void StaticContext::addColation(const std::string& aURI)
  { theStaticContext->addCollation(aURI); }

bool StaticContext::addNamespace(const std::string& aPrefix, 
                            const std::string& aURI)
  { return theStaticContext->addNamespace(aPrefix, aURI); }

void StaticContext::addReference() const
  { theStaticContext->addReference(); }
  
bool StaticContext::containsFunction(const std::string &aFnNameUri, 
                                const std::string &aFnNameLocal, 
                                int arity) const 
  { return theStaticContext->containsFunction(aFnNameUri, aFnNameLocal,
                                              arity); }

StaticContext	StaticContext::createChildContext() const
  { return StaticContext(theStaticContext->createChildContext()); }
  
void 	StaticContext::declareOption (const Item &aQName, 
                               const std::string &aOptionVal)
  { return theStaticContext->declareOption(aQName.theItem, aOptionVal); }

void 	StaticContext::disableFunction (const Item &aQName, int arity)
  { theStaticContext->disableFunction( aQName.theItem, arity); }

void 	StaticContext::free ()
  { theStaticContext->free(); }

std::string StaticContext::getBaseURI () const
  { return std::string(theStaticContext->getBaseURI().c_str()); }

zorba::boundary_space_mode_t StaticContext::getBoundarySpacePolicy() const
  { return theStaticContext->getBoundarySpacePolicy(); }

zorba::construction_mode_t StaticContext::getConstructionMode () const 
  { return theStaticContext->getConstructionMode(); }		

void 	StaticContext::getCopyNamespacesMode (zorba::preserve_mode_t &aPreserve, zorba::inherit_mode_t &aInherit) const
  { return theStaticContext->getCopyNamespacesMode(aPreserve, aInherit); }		

std::string StaticContext::getDefaultCollation () const 
  { return std::string(theStaticContext->getDefaultCollation().c_str()); }

std::string StaticContext::getDefaultElementAndTypeNamespace () const 
  { 
    return std::string(theStaticContext->getDefaultElementAndTypeNamespace().
                       c_str()); 
  }

std::string StaticContext::getDefaultFunctionNamespace () const 
  { 
    return std::string(theStaticContext->getDefaultFunctionNamespace().c_str());
  }

zorba::order_empty_mode_t StaticContext::getDefaultOrderForEmptySequences() const
  { return theStaticContext->getDefaultOrderForEmptySequences(); }

std::string StaticContext::getNamespaceURIByPrefix(const std::string &aPrefix) const
  {
    return std::string(theStaticContext->getNamespaceURIByPrefix(aPrefix).
                       c_str());
  }

bool StaticContext::getOption(const Item &aQName, std::string &aOptionValue) const
  { 
    zorba::String optVal = zorba::String(aOptionValue.c_str());
    return theStaticContext->getOption(aQName.theItem, optVal); 
  }

zorba::ordering_mode_t StaticContext::getOrderingMode () const
  { return theStaticContext->getOrderingMode(); }

long StaticContext::getRefCount () const
  { return theStaticContext->getRefCount(); }

zorba::validation_mode_t StaticContext::getRevalidationMode ()
  { return theStaticContext->getRevalidationMode(); }

zorba::xpath1_0compatib_mode_t StaticContext::getXPath1_0CompatibMode () const
  { return theStaticContext->getXPath1_0CompatibMode(); } 

void StaticContext::loadProlog (const std::string & aProlog, 
                           const CompilerHints &hints)
  { theStaticContext->loadProlog( aProlog, hints.theCompilerHints); }

void StaticContext::removeReference ()
  { theStaticContext->removeReference(); }

void StaticContext::resetTraceStream ()
  { theStaticContext->resetTraceStream(); }

bool StaticContext::setBaseURI (const std::string &aBaseURI)
  { return theStaticContext->setBaseURI(aBaseURI); }

bool StaticContext::setBoundarySpacePolicy (zorba::boundary_space_mode_t aMode)
  { return theStaticContext->setBoundarySpacePolicy(aMode); } 

bool StaticContext::setConstructionMode (zorba::construction_mode_t aMode)
  { return theStaticContext->setConstructionMode(aMode); } 

bool StaticContext::setCopyNamespacesMode (zorba::preserve_mode_t aPreserve, 
    zorba::inherit_mode_t aInherit)
  { return theStaticContext->setCopyNamespacesMode(aPreserve, aInherit); }   

void StaticContext::setDefaultCollation (const std::string &aURI)
  { theStaticContext->setDefaultCollation(aURI); }

bool StaticContext::setDefaultElementAndTypeNamespace (const std::string &aURI)
  { return theStaticContext->setDefaultElementAndTypeNamespace(aURI); }

bool StaticContext::setDefaultFunctionNamespace (const std::string &aURI)
  { return theStaticContext->setDefaultFunctionNamespace(aURI); }

bool StaticContext::setDefaultOrderForEmptySequences (zorba::order_empty_mode_t aMode)
  { return theStaticContext->setDefaultOrderForEmptySequences(aMode); } 

bool StaticContext::setOrderingMode (zorba::ordering_mode_t aMode)
  { return theStaticContext->setOrderingMode(aMode); } 

void StaticContext::setRevalidationMode (zorba::validation_mode_t aMode)
  { return theStaticContext->setRevalidationMode(aMode); } 

bool StaticContext::setXPath1_0CompatibMode (zorba::xpath1_0compatib_mode_t aMode)
  { return theStaticContext->setXPath1_0CompatibMode(aMode); }

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
