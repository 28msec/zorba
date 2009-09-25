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


class StaticContext 
{
  friend class Zorba;
private:
  zorba::StaticContext_t theStaticContext;
public:
  StaticContext() {}
  StaticContext(const StaticContext& aStaticContext) : 
    theStaticContext(aStaticContext.theStaticContext) {}
  StaticContext(zorba::StaticContext_t aStaticContext) : 
    theStaticContext(aStaticContext) {}

  virtual bool addColation(const std::string& aURI)
  { return theStaticContext->addCollation(aURI); }

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

  //virtual boundary_space_mode_t 	getBoundarySpacePolicy () const =0;
  //virtual TypeIdentifier_t 	getCollectionType (const std::string &aCollectionUri) const =0;
  //virtual CollectionURIResolver * 	getCollectionURIResolver () const =0;
  //virtual construction_mode_t 	getConstructionMode () const =0
 	//virtual TypeIdentifier_t 	getContextItemStaticType () const =0
  //virtual void 	getCopyNamespacesMode (preserve_mode_t &aPreserve, inherit_mode_t &aInherit) const =0;
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

  //virtual order_empty_mode_t 	getDefaultOrderForEmptySequences () const =0;
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

  //virtual ordering_mode_t 	getOrderingMode () const =0
  long 	getRefCount () const
  { return theStaticContext->getRefCount(); }

  virtual bool 	getRevalidationEnabled () const
  { return theStaticContext->getRevalidationEnabled(); }

  //virtual validation_mode_t 	getRevalidationMode ()=0;
  //virtual SchemaURIResolver * 	getSchemaURIResolver () const =0;
  //virtual xpath1_0compatib_mode_t 	getXPath1_0CompatibMode () const =0
  //virtual xquery_version_t 	getXqueryVersion () const =0;
 	virtual void 	loadProlog (const std::string & aProlog, 
                            const CompilerHints &hints)
  { theStaticContext->loadProlog( aProlog, hints.theCompilerHints); }

  //virtual bool 	registerStatelessExternalFunction (StatelessExternalFunction *aExternalFunction)=0
  void 	removeReference ()
  { theStaticContext->removeReference(); }

  virtual void 	resetTraceStream ()
  { theStaticContext->resetTraceStream(); }

  virtual bool 	setBaseURI (const std::string &aBaseURI)
  { return theStaticContext->setBaseURI(aBaseURI); }

  //virtual bool 	setBoundarySpacePolicy (boundary_space_mode_t aMode)=0
  //virtual void 	setCollectionType (const std::string &aCollectionUri, TypeIdentifier_t type)=0
 	//virtual void 	setCollectionURIResolver (CollectionURIResolver *aCollectionUriResolver)=0
  //virtual bool 	setConstructionMode (construction_mode_t aMode)=0
  //virtual void 	setContextItemStaticType (TypeIdentifier_t type)=0
  //virtual bool 	setCopyNamespacesMode (preserve_mode_t aPreserve, inherit_mode_t aInherit)=0
  virtual bool 	setDefaultCollation (const std::string &aURI)
  { return theStaticContext->setDefaultCollation(aURI); }

  virtual bool 	setDefaultElementAndTypeNamespace (const std::string &aURI)
  { return theStaticContext->setDefaultElementAndTypeNamespace(aURI); }

  virtual bool 	setDefaultFunctionNamespace (const std::string &aURI)
  { return theStaticContext->setDefaultFunctionNamespace(aURI); }

  //virtual bool 	setDefaultOrderForEmptySequences (order_empty_mode_t aMode)=0
  //virtual void 	setDocumentType (const std::string &aDocUri, TypeIdentifier_t type)=0
  //virtual void 	setDocumentURIResolver (DocumentURIResolver *aDocumentURIResolver)=0
  //virtual void 	setModuleURIResolver (ModuleURIResolver *aModuleUriResolver)=0
  //virtual bool 	setOrderingMode (ordering_mode_t aMode)=0
 	virtual bool 	setRevalidationEnabled (bool enabled)
  { return theStaticContext->setRevalidationEnabled(enabled); }

  //virtual void 	setRevalidationMode (validation_mode_t aMode)=0
 	//virtual void 	setSchemaURIResolver (SchemaURIResolver *aSchemaUriResolver)=0
  //virtual void 	setTraceStream (std::ostream &)=0
 	//virtual bool 	setXPath1_0CompatibMode (xpath1_0compatib_mode_t aMode)=0
 	//virtual bool 	setXqueryVersion (xquery_version_t aMode)=0

  void destroy() { theStaticContext = 0; }
   
}; // class StaticContext




%}  // end Implementation


    // Interface


class StaticContext 
{
 public:
  virtual bool addColation(const std::string& aURI);  
  virtual bool addNamespace(const std::string& aPrefix, 
                            const std::string& aURI);
  void addReference() const;
  virtual bool containsFunction(const std::string &aFnNameUri, 
                                const std::string &aFnNameLocal, 
                                int arity) const =0;

  virtual StaticContext	createChildContext() const =0;
  virtual void declareOption(const Item &aQName, 
                             const std::string &aOptionVal)=0;
  virtual void disableFunction(const Item &aQName, int arity)=0;

  //virtual void 	disableFunction (const Function_t &aFunction)=0;
  //virtual void 	findFunctions (const Item &aQName, std::vector< Function_t > &aFunctions) const =0
  virtual void 	free ();
  virtual std::string 	getBaseURI () const =0;
  //virtual boundary_space_mode_t 	getBoundarySpacePolicy () const =0;
  //virtual TypeIdentifier_t 	getCollectionType (const std::string &aCollectionUri) const =0;
  //virtual CollectionURIResolver * 	getCollectionURIResolver () const =0;
  //virtual construction_mode_t 	getConstructionMode () const =0
 	//virtual TypeIdentifier_t 	getContextItemStaticType () const =0
  //virtual void 	getCopyNamespacesMode (preserve_mode_t &aPreserve, inherit_mode_t &aInherit) const =0;
  virtual std::string 	getDefaultCollation () const =0;
  virtual std::string 	getDefaultElementAndTypeNamespace () const =0;
  virtual std::string 	getDefaultFunctionNamespace () const =0;
  //virtual order_empty_mode_t 	getDefaultOrderForEmptySequences () const =0;
  //virtual TypeIdentifier_t 	getDocumentType (const std::string &aDocUri) const =0;
  //virtual DocumentURIResolver * 	getDocumentURIResolver ()=0;
  //virtual ModuleURIResolver * 	getModuleURIResolver () const =0;
  virtual std::string 	getNamespaceURIByPrefix (const std::string &aPrefix) const =0;
  virtual bool 	getOption (const Item &aQName, std::string &aOptionValue) const =0;
  //virtual ordering_mode_t 	getOrderingMode () const =0
  long 	getRefCount () const;
  virtual bool 	getRevalidationEnabled () const =0;
  //virtual validation_mode_t 	getRevalidationMode ()=0;
  //virtual SchemaURIResolver * 	getSchemaURIResolver () const =0;
  //virtual xpath1_0compatib_mode_t 	getXPath1_0CompatibMode () const =0
  //virtual xquery_version_t 	getXqueryVersion () const =0;
 	virtual void 	loadProlog (const std::string &, const Zorba_CompilerHints_t &hints)=0;
  //virtual bool 	registerStatelessExternalFunction (StatelessExternalFunction *aExternalFunction)=0
  void 	removeReference ();
  virtual void 	resetTraceStream ()=0;
  virtual bool 	setBaseURI (const std::string &aBaseURI)=0;
  //virtual bool 	setBoundarySpacePolicy (boundary_space_mode_t aMode)=0
  //virtual void 	setCollectionType (const std::string &aCollectionUri, TypeIdentifier_t type)=0
 	//virtual void 	setCollectionURIResolver (CollectionURIResolver *aCollectionUriResolver)=0
  //virtual bool 	setConstructionMode (construction_mode_t aMode)=0
  //virtual void 	setContextItemStaticType (TypeIdentifier_t type)=0
  //virtual bool 	setCopyNamespacesMode (preserve_mode_t aPreserve, inherit_mode_t aInherit)=0
  virtual bool 	setDefaultCollation (const std::string &aURI)=0;
  virtual bool 	setDefaultElementAndTypeNamespace (const std::string &aURI)=0;
  virtual bool 	setDefaultFunctionNamespace (const std::string &aURI)=0;
  //virtual bool 	setDefaultOrderForEmptySequences (order_empty_mode_t aMode)=0
  //virtual void 	setDocumentType (const std::string &aDocUri, TypeIdentifier_t type)=0
  //virtual void 	setDocumentURIResolver (DocumentURIResolver *aDocumentURIResolver)=0
  //virtual void 	setModuleURIResolver (ModuleURIResolver *aModuleUriResolver)=0
  //virtual bool 	setOrderingMode (ordering_mode_t aMode)=0
 	virtual bool 	setRevalidationEnabled (bool enabled)=0;
  //virtual void 	setRevalidationMode (validation_mode_t aMode)=0
 	//virtual void 	setSchemaURIResolver (SchemaURIResolver *aSchemaUriResolver)=0
  //virtual void 	setTraceStream (std::ostream &)=0
 	//virtual bool 	setXPath1_0CompatibMode (xpath1_0compatib_mode_t aMode)=0
 	//virtual bool 	setXqueryVersion (xquery_version_t aMode)=0
 	
  void destroy();
}; // class StaticContext
