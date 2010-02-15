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


class StaticContext 
{
  friend class Zorba;
  //friend class DocumentURIResolver;

private:
  zorba::StaticContext_t theStaticContext;
public:
  StaticContext() {}
  StaticContext(const StaticContext& aStaticContext) : 
    theStaticContext(aStaticContext.theStaticContext) {}
  StaticContext(zorba::StaticContext_t aStaticContext) : 
    theStaticContext(aStaticContext) {}

  virtual void addColation(const std::string& aURI)
  { theStaticContext->addCollation(aURI); }

  virtual bool addNamespace(const std::string& aPrefix, 
                            const std::string& aURI)
  { return theStaticContext->addNamespace(aPrefix, aURI); }

  void addReference() const
  { theStaticContext->addReference(); }
  
  virtual bool containsFunction(const std::string &aFnNameUri, 
                                const std::string &aFnNameLocal, 
                                int arity) const 
  { return theStaticContext->containsFunction(aFnNameUri, aFnNameLocal,
                                              arity); }

  virtual StaticContext	createChildContext() const
  { return StaticContext(theStaticContext->createChildContext()); }
  
  virtual void 	declareOption (const Item &aQName, 
                               const std::string &aOptionVal)
  { return theStaticContext->declareOption(aQName.theItem, aOptionVal); }

  virtual void 	disableFunction (const Item &aQName, int arity)
  { theStaticContext->disableFunction( aQName.theItem, arity); }

  //virtual void 	disableFunction (const Function_t &aFunction)=0;
  //virtual void 	findFunctions (const Item &aQName, std::vector< Function_t > &aFunctions) const =0

  virtual void 	free ()
  { theStaticContext->free(); }

  virtual std::string getBaseURI () const
  { return std::string(theStaticContext->getBaseURI().c_str()); }

  virtual boundary_space_mode_t getBoundarySpacePolicy() const
  { return theStaticContext->getBoundarySpacePolicy(); }

  //virtual TypeIdentifier_t getCollectionType (const std::string &aCollectionUri) const =0;
  //virtual CollectionURIResolver * getCollectionURIResolver () const =0;

  virtual construction_mode_t getConstructionMode () const 
  { return theStaticContext->getConstructionMode(); }		

  //virtual TypeIdentifier_t 	getContextItemStaticType () const =0
  virtual void 	getCopyNamespacesMode (preserve_mode_t &aPreserve, inherit_mode_t &aInherit) const
  { return theStaticContext->getCopyNamespacesMode(aPreserve, aInherit); }		

  virtual std::string getDefaultCollation () const 
  { return std::string(theStaticContext->getDefaultCollation().c_str()); }

  virtual std::string getDefaultElementAndTypeNamespace () const 
  { 
    return std::string(theStaticContext->getDefaultElementAndTypeNamespace().
                       c_str()); 
  }

  virtual std::string getDefaultFunctionNamespace () const 
  { 
    return std::string(theStaticContext->getDefaultFunctionNamespace().c_str());
  }

  virtual order_empty_mode_t getDefaultOrderForEmptySequences() const
  { return theStaticContext->getDefaultOrderForEmptySequences(); }		

  //virtual TypeIdentifier_t 	getDocumentType (const std::string &aDocUri) const =0;
  //virtual DocumentURIResolver * 	getDocumentURIResolver ()=0;
  //virtual ModuleURIResolver * 	getModuleURIResolver () const =0;

  virtual std::string getNamespaceURIByPrefix(const std::string &aPrefix) const
  {
    return std::string(theStaticContext->getNamespaceURIByPrefix(aPrefix).
                       c_str());
  }

  virtual bool getOption(const Item &aQName, std::string &aOptionValue) const
  { 
    zorba::String optVal = zorba::String(aOptionValue.c_str());
    return theStaticContext->getOption(aQName.theItem, optVal); 
  }

  virtual ordering_mode_t getOrderingMode () const
  { return theStaticContext->getOrderingMode(); }		

  long 	getRefCount () const
  { return theStaticContext->getRefCount(); }

  virtual validation_mode_t getRevalidationMode ()
  { return theStaticContext->getRevalidationMode(); }		

  //virtual SchemaURIResolver * getSchemaURIResolver () const =0;

  virtual xpath1_0compatib_mode_t getXPath1_0CompatibMode () const
  { return theStaticContext->getXPath1_0CompatibMode(); } 

  //virtual xquery_version_t 	getXqueryVersion () const 
  //{ return theStaticContext->getXqueryVersion(); } 

  virtual void loadProlog (const std::string & aProlog, 
                           const CompilerHints &hints)
  { theStaticContext->loadProlog( aProlog, hints.theCompilerHints); }

  //virtual bool 	registerStatelessExternalFunction (StatelessExternalFunction *aExternalFunction)=0

  void 	removeReference ()
  { theStaticContext->removeReference(); }

  virtual void 	resetTraceStream ()
  { theStaticContext->resetTraceStream(); }

  virtual bool 	setBaseURI (const std::string &aBaseURI)
  { return theStaticContext->setBaseURI(aBaseURI); }

  virtual bool 	setBoundarySpacePolicy (boundary_space_mode_t aMode)
  { return theStaticContext->setBoundarySpacePolicy(aMode); } 

  //virtual void 	setCollectionType (const std::string &aCollectionUri, TypeIdentifier_t type)=0
  //virtual void 	setCollectionURIResolver (CollectionURIResolver *aCollectionUriResolver)=0

  virtual bool 	setConstructionMode (construction_mode_t aMode)
  { return theStaticContext->setConstructionMode(aMode); } 

  //virtual void 	setContextItemStaticType (TypeIdentifier_t type)=0

  virtual bool 	setCopyNamespacesMode (preserve_mode_t aPreserve, 
    inherit_mode_t aInherit)
  { return theStaticContext->setCopyNamespacesMode(aPreserve, aInherit); }   

  virtual void setDefaultCollation (const std::string &aURI)
  { theStaticContext->setDefaultCollation(aURI); }

  virtual bool 	setDefaultElementAndTypeNamespace (const std::string &aURI)
  { return theStaticContext->setDefaultElementAndTypeNamespace(aURI); }

  virtual bool 	setDefaultFunctionNamespace (const std::string &aURI)
  { return theStaticContext->setDefaultFunctionNamespace(aURI); }

  virtual bool 	setDefaultOrderForEmptySequences (order_empty_mode_t aMode)
  { return theStaticContext->setDefaultOrderForEmptySequences(aMode); } 

  //virtual void 	setDocumentType (const std::string &aDocUri, TypeIdentifier_t type)=0
  //virtual void 	setDocumentURIResolver (DocumentURIResolver *aDocumentURIResolver)=0
  //virtual void 	setModuleURIResolver (ModuleURIResolver *aModuleUriResolver)=0

  virtual bool 	setOrderingMode (ordering_mode_t aMode)
  { return theStaticContext->setOrderingMode(aMode); } 

  virtual void 	setRevalidationMode (validation_mode_t aMode)
  { return theStaticContext->setRevalidationMode(aMode); } 

  //virtual void 	setSchemaURIResolver (SchemaURIResolver *aSchemaUriResolver)=0
  //virtual void 	setTraceStream (std::ostream &)=0

  virtual bool 	setXPath1_0CompatibMode (xpath1_0compatib_mode_t aMode)
  { return theStaticContext->setXPath1_0CompatibMode(aMode); }

  //virtual bool setXqueryVersion (xquery_version_t aMode)
  //{ return theStaticContext->setXqueryVersion(aMode); } 

  void destroy() 
  { theStaticContext = 0; }
   
}; // class StaticContext




%}  // end Implementation


    // Interface

%rename(XPath1_0CompatibModeEnum) xpath1_0compatib_mode_t;
%rename(XPATH2_0) xpath2_0;
%rename(XPATH1_0) xpath1_0;

%rename(OrderingModeEnum) ordering_mode_t;
%rename(ORDERED) ordered;
%rename(UNORDERED) unordered;

%rename(OrderEmptyModeEnum) order_empty_mode_t;
%rename(EMPTY_GREATEST) empty_greatest;
%rename(EMPTY_LEAST) empty_least;

%rename(InheritModeEnum) inherit_mode_t;
%rename(INHERIT_NS) inherit_ns;
%rename(NO_INHERIT_NS) no_inherit_ns;

%rename(PreserveModeEnum) preserve_mode_t;
%rename(PRESERVE_NS) preserve_ns;
%rename(NO_PRESERVE_NS) no_preserve_ns;

%rename(BoundarySpaceModeEnum) boundary_space_mode_t;
%rename(PRESERVE_SPACE) preserve_space;
%rename(STRIP_SPACE) strip_space;

%rename(ConstructionModeEnum) construction_mode_t;
%rename(PRESERVE_CONS) preserve_cons;
%rename(STRIP_CONS) strip_cons;

%rename(XQueryVersionEnum) xquery_version_t;
%rename(XQUERY_VERSION_1_0) xquery_version_1_0;
%rename(XQUERY_VERSION_1_1) xquery_version_1_1;

%rename(ValidationModeEnum) validation_mode_t;
%rename(VALIDATE_SKIP) validate_skip;
%rename(VALIDATE_LAX) validate_lax;
%rename(VALIDATE_STRICT) validate_strict;

#include <zorba/static_context_consts.h>


class StaticContext 
{
 public:
  virtual void addColation(const std::string& aURI);  
  virtual bool addNamespace(const std::string& aPrefix, 
                            const std::string& aURI);
  void addReference() const;
  virtual bool containsFunction(const std::string &aFnNameUri, 
                                const std::string &aFnNameLocal, 
                                int arity) const;

  virtual StaticContext	createChildContext() const;
  virtual void declareOption(const Item &aQName, 
                             const std::string &aOptionVal);
  virtual void disableFunction(const Item &aQName, int arity);

  //virtual void 	disableFunction (const Function_t &aFunction)=0;
  //virtual void 	findFunctions (const Item &aQName, std::vector< Function_t > &aFunctions) const =0

  virtual void 	free ();
  virtual std::string 	getBaseURI () const;
  virtual boundary_space_mode_t 	getBoundarySpacePolicy () const;

  //virtual TypeIdentifier_t 	getCollectionType (const std::string &aCollectionUri) const =0;
  //virtual CollectionURIResolver * 	getCollectionURIResolver () const =0;

  virtual construction_mode_t 	getConstructionMode () const;
  //virtual TypeIdentifier_t 	        getContextItemStaticType () const =0
  virtual void getCopyNamespacesMode (preserve_mode_t &aPreserve, inherit_mode_t &aInherit) const;
  virtual std::string 	getDefaultCollation () const;
  virtual std::string 	getDefaultElementAndTypeNamespace () const;
  virtual std::string 	getDefaultFunctionNamespace () const;
  virtual order_empty_mode_t 	getDefaultOrderForEmptySequences () const;

  //virtual TypeIdentifier_t 	getDocumentType (const std::string &aDocUri) const =0;
  //virtual DocumentURIResolver * 	getDocumentURIResolver ()=0;
  //virtual ModuleURIResolver * 	getModuleURIResolver () const =0;

  virtual std::string getNamespaceURIByPrefix(const std::string &aPrefix) const;
  virtual bool getOption(const Item &aQName, std::string &aOptionValue) const;
  virtual ordering_mode_t getOrderingMode() const;
  long 	getRefCount() const;
  virtual validation_mode_t getRevalidationMode();
  //virtual SchemaURIResolver * 	getSchemaURIResolver () const =0;
  virtual xpath1_0compatib_mode_t 	getXPath1_0CompatibMode () const;
  //virtual xquery_version_t 	getXqueryVersion () const;
 	virtual void 	loadProlog (const std::string &, 
                            const Zorba_CompilerHints_t &hints);

  //virtual bool 	registerStatelessExternalFunction (StatelessExternalFunction *aExternalFunction)=0

  void 	removeReference ();
  virtual void 	resetTraceStream ();
  virtual bool 	setBaseURI (const std::string &aBaseURI);
  virtual bool 	setBoundarySpacePolicy (boundary_space_mode_t aMode);

  //virtual void 	setCollectionType (const std::string &aCollectionUri, TypeIdentifier_t type)=0
  //virtual void 	setCollectionURIResolver (CollectionURIResolver *aCollectionUriResolver)=0
  virtual bool 	setConstructionMode (construction_mode_t aMode);

  //virtual void 	setContextItemStaticType (TypeIdentifier_t type)=0

  virtual bool 	setCopyNamespacesMode (preserve_mode_t aPreserve, 
                                       inherit_mode_t aInherit);
  virtual void 	setDefaultCollation (const std::string &aURI);
  virtual bool 	setDefaultElementAndTypeNamespace (const std::string &aURI);
  virtual bool 	setDefaultFunctionNamespace (const std::string &aURI);
  virtual bool 	setDefaultOrderForEmptySequences (order_empty_mode_t aMode);

  //virtual void 	setDocumentType (const std::string &aDocUri, TypeIdentifier_t type)=0
  //virtual void 	setDocumentURIResolver (DocumentURIResolver *aDocumentURIResolver)=0
  //virtual void 	setModuleURIResolver (ModuleURIResolver *aModuleUriResolver)=0

  virtual bool 	setOrderingMode (ordering_mode_t aMode);
  virtual void 	setRevalidationMode (validation_mode_t aMode);

  //virtual void 	setSchemaURIResolver (SchemaURIResolver *aSchemaUriResolver)=0
  //virtual void 	setTraceStream (std::ostream &)=0

  virtual bool 	setXPath1_0CompatibMode (xpath1_0compatib_mode_t aMode);
  //virtual bool setXqueryVersion (xquery_version_t aMode);
 	
  void destroy();
}; // class StaticContext
