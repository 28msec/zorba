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
#ifndef ZORBA_API_STATIC_CONTEXT_IMPL_H
#define ZORBA_API_STATIC_CONTEXT_IMPL_H

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
#ifndef ZORBA_NO_FULL_TEXT
  class FullTextURIResolverWrapper;
#endif

/*******************************************************************************

  theCtx               : rchandle to the internal static_context obj that is
                         wrapped by "this".

  theSctxMap           :

  theErrorHandler      : Pointer to an error handle to handle any errors raised
                         by the methods of this class.
  theUserErrorHandler  : If true, theErrorHandler is owned by "this", and it
                         should be deleted when "this" is destroyed. Otherwise,
                         theErrorHandler is not owned by "this".
********************************************************************************/
class StaticContextImpl : public StaticContext
{
  friend class Unmarshaller; // needs to get the context out of this class
  friend class XQueryImpl;   // needed for accessing theSctxMap

protected:
  static_context_t                    theCtx;

  std::map<short, static_context_t>   theSctxMap;

  ErrorHandler                      * theErrorHandler;
  bool                                theUserErrorHandler;

  // remeber all the resolver wrappers that this context has created
  std::map<ModuleURIResolver*,
           ModuleURIResolverWrapper*> theModuleWrappers;
  std::map<SchemaURIResolver*,
           SchemaURIResolverWrapper*> theSchemaWrappers;
#ifndef ZORBA_NO_FULL_TEXT
  std::map<FullTextURIResolver*,
           FullTextURIResolverWrapper*> theStopWordsWrappers;
  std::map<FullTextURIResolver*,
           FullTextURIResolverWrapper*> theThesaurusWrappers;
#endif

private:
  StaticContextImpl(const StaticContextImpl&);

public:
  StaticContextImpl(ErrorHandler* = 0);

  StaticContextImpl(static_context*, ErrorHandler*);

  virtual ~StaticContextImpl();

  void loadProlog(const String&, const Zorba_CompilerHints_t &hints);

  StaticContext_t createChildContext() const;

  bool addNamespace( const String& prefix, const String& URI );

  String getNamespaceURIByPrefix( const String& prefix ) const;

  bool setDefaultElementAndTypeNamespace( const String& URI );

  String getDefaultElementAndTypeNamespace( ) const;

  bool setDefaultFunctionNamespace( const String& URI );

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

#ifndef ZORBA_NO_FULL_TEXT
  virtual void
  addThesaurusURIResolver(FullTextURIResolver* aFullTextUriResolver);

  virtual void
  removeThesaurusURIResolver(FullTextURIResolver* aFullTextUriResolver);

  virtual std::vector<FullTextURIResolver*>
  getThesaurusURIResolvers() const;

  virtual void
  addStopWordsURIResolver(FullTextURIResolver* aFullTextUriResolver);

  virtual void
  removeStopWordsURIResolver(FullTextURIResolver* aFullTextUriResolver);

  virtual std::vector<FullTextURIResolver*>
  getStopWordsURIResolvers() const;
#endif /* ZORBA_NO_FULL_TEXT */

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

  virtual void
  disableFunction(const Function_t& aFunction);

  virtual void
  disableFunction(const Item& aQName, int arity);

  virtual void
  getFunctionAnnotations(const Item& aQName, int arity, std::vector<Annotation_t>& aAnnotations) const;

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
  resolve(const String& aRelativeUri) const;

  virtual String
  resolve(const String& aRelativeUri, const String& aBaseUri) const;

  virtual void
  setDeclaredCollectionCallback ( CollectionCallback aCallbackFunction,
                                  void* aCallbackData );

  virtual void
  setDeclaredIndexCallback ( IndexCallback aCallbackFunction,
                             void* aCallbackData );

  virtual void
  addModuleImportChecker(ModuleImportChecker* aChecker);

  virtual void
  removeModuleImportChecker(ModuleImportChecker* aChecker);

  virtual bool
  validate(const Item& rootElement, Item& validatedResult,
           validation_mode_t validationMode = validate_strict);
  
  virtual bool 
  validate(const Item& rootElement, Item& validatedResult, 
           const String& targetNamespace,
           validation_mode_t validationMode = validate_strict);
  
  virtual bool 
  validateSimpleContent(const String& stringValue,
          const Item& typeQName, 
          std::vector<Item>& resultList);
};

} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
