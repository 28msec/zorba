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
#ifndef XQP_STATIC_CONTEXT_IMPL_H
#define XQP_STATIC_CONTEXT_IMPL_H

#include <zorba/typeident.h> 
#include <zorba/static_context.h>
#include <zorba/api_shared_types.h>
#include <map>

#include "common/shared_types.h"


namespace zorba {

  class ErrorHandler;
  class static_context;
  class ModuleURIResolverWrapper;
  class SchemaURIResolverWrapper;

/*******************************************************************************

  theCtx               : rchandle to the internal static_context obj that is
                         wrapped by "this".
  theUserStaticContext : If true, "this" does not own the static_context obj
                         that is pointed to by theCtx, and so, during destruction,
                         "this" should not delete theCtx. If false, "this" owns
                         theCtx, and should delete it during destruction.

********************************************************************************/
class StaticContextImpl : public StaticContext
{
  friend class Unmarshaller; // needs to get the context out of this class
  friend class XQueryImpl;   // needed for accessing theSctxMap

 protected:
  static_context                    * theCtx;
  std::map<short, static_context_t>   theSctxMap;
  bool                                theUserStaticContext;

  ErrorHandler                      * theErrorHandler;
  bool                                theUserErrorHandler;

  // remeber all the resolver wrappers that this
  // context has created
  std::map<ModuleURIResolver*,
           ModuleURIResolverWrapper*> theModuleWrappers;
  std::map<SchemaURIResolver*,
           SchemaURIResolverWrapper*> theSchemaWrappers;

 private:
  StaticContextImpl(const StaticContextImpl&);

 public:
  StaticContextImpl(ErrorHandler*);
  StaticContextImpl(static_context*, ErrorHandler*);

  virtual ~StaticContextImpl();

  void
  loadProlog(const String&, const Zorba_CompilerHints_t &hints);

  virtual StaticContext_t
  createChildContext() const;
      
  virtual bool   
  addNamespace( const String& prefix, const String& URI );
      
  virtual String   
  getNamespaceURIByPrefix( const String& prefix ) const;

  virtual bool   
  setDefaultElementAndTypeNamespace( const String& URI );
      
  virtual String   
  getDefaultElementAndTypeNamespace( ) const;

  virtual bool   
  setDefaultFunctionNamespace( const String& URI );
      
  virtual String   
  getDefaultFunctionNamespace( ) const;

  virtual void   
  addCollation( const String& URI );

  virtual void   
  setDefaultCollation( const String& URI );

  virtual String 
  getDefaultCollation() const;

  virtual bool   
  setXQueryVersion(xquery_version_t mode);

  virtual xquery_version_t  
  getXQueryVersion() const;

  virtual bool   
  setXPath1_0CompatibMode( xpath1_0compatib_mode_t mode );

  virtual xpath1_0compatib_mode_t  
  getXPath1_0CompatibMode( ) const;

  virtual bool   
  setConstructionMode( construction_mode_t );

  virtual construction_mode_t  
  getConstructionMode( ) const;

  virtual bool   
  setOrderingMode( ordering_mode_t );

  virtual ordering_mode_t  
  getOrderingMode( ) const;

  virtual bool   
  setDefaultOrderForEmptySequences( order_empty_mode_t );

  virtual order_empty_mode_t   
  getDefaultOrderForEmptySequences( ) const;

  virtual bool   
  setBoundarySpacePolicy( boundary_space_mode_t );

  virtual boundary_space_mode_t  
  getBoundarySpacePolicy( ) const;

  virtual bool   
  setCopyNamespacesMode( preserve_mode_t preserve, 
                         inherit_mode_t inherit );

  virtual void   
  getCopyNamespacesMode( preserve_mode_t& preserve, 
                         inherit_mode_t& inherit ) const;

  virtual bool
  setBaseURI( const String& baseURI );

  virtual String   
  getBaseURI( ) const;

  virtual validation_mode_t
  getRevalidationMode() const;

  virtual void
  setRevalidationMode(validation_mode_t aMode);

  virtual bool 
  registerModule(ExternalModule* aModule);

  virtual void
  setDocumentType(const String& aDocUri, TypeIdentifier_t type);

  virtual TypeIdentifier_t
  getDocumentType(const String& aDocUri) const;

  virtual void
  setDocumentURIResolver(DocumentURIResolver* aDocumentURIResolver);

  virtual DocumentURIResolver*
  getDocumentURIResolver() const;

  virtual void
  setCollectionURIResolver(CollectionURIResolver* aCollectionUriResolver);

  virtual CollectionURIResolver*
  getCollectionURIResolver() const;

  virtual void
  setCollectionType(const String& aCollectionUri, TypeIdentifier_t type);

  virtual TypeIdentifier_t
  getCollectionType(const String& aCollectionUri) const;

  virtual void
  addSchemaURIResolver(SchemaURIResolver* aSchemaUriResolver);

  virtual void
  removeSchemaURIResolver(SchemaURIResolver* aSchemaUriResolver);

  virtual std::vector<SchemaURIResolver*>
  getSchemaURIResolvers() const;

  virtual void
  addModuleURIResolver(ModuleURIResolver* aModuleUriResolver);

  virtual std::vector<ModuleURIResolver*>
  getModuleURIResolvers() const;

  virtual void
  removeModuleURIResolver(ModuleURIResolver* aModuleUriResolver);

  virtual bool
  containsFunction(const String& aFnNameUri, const String& aFnNameLocal, int arity) const;

  virtual void
  findFunctions(const Item& aQName, std::vector<Function_t>& aFunctions) const;

  void
  disableFunction(const Function_t& aFunction);

  void
  disableFunction(const Item& aQName, int arity);

  virtual void
  setContextItemStaticType(TypeIdentifier_t type);

  virtual TypeIdentifier_t
  getContextItemStaticType() const;

  virtual void
  setTraceStream(std::ostream&);

  virtual void
  resetTraceStream();

  virtual bool
  getOption( const Item& aQName, String& aOptionValue) const;

  virtual void
  declareOption( const Item& aQName, const String& aOptionValue);

  virtual void
  setModulePaths( const std::vector<String>& aModulePaths );

  virtual void
  getModulePaths( std::vector<String>& aModulePaths ) const;

  virtual void
  getFullModulePaths( std::vector<String>& aFullModulePaths ) const;

  virtual String
  resolve( const String& aBaseUri, const String& aRelativeURI ) const;

  virtual void
  setDeclaredCollectionCallback ( CollectionCallback aCallbackFunction,
                                  void* aCallbackData );

  virtual void
  setDeclaredIndexCallback ( IndexCallback aCallbackFunction,
                             void* aCallbackData );

};

} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
