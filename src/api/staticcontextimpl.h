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

#include "common/shared_types.h"


namespace zorba {

  class ErrorHandler;
  class static_context;

/*******************************************************************************

  theCtx               : Pointer to the internal static_context obj that is
                         wrapped by "this".
  theUserStaticContext : If true, "this" does not own the static_context obj
                         that is pointed to by theCtx, and so, during destruction,
                         "this" should not delete theCtx. If false, "this" owns
                         theCtx, and should delete it during destruction.

********************************************************************************/
class StaticContextImpl : public StaticContext
{
  friend class Unmarshaller; // needs to get the context out of this class

 protected:
  static_context*  theCtx;
  bool             theUserStaticContext;

  ErrorHandler*    theErrorHandler;
  bool             theUserErrorHandler;

 private:
  StaticContextImpl(const StaticContextImpl&);

 public:
  StaticContextImpl(ErrorHandler*);
  StaticContextImpl(static_context*, ErrorHandler*);

  virtual ~StaticContextImpl();

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

  virtual bool   
  addCollation( const String& URI );

  virtual bool   
  setDefaultCollation( const String& URI );

  virtual String 
  getDefaultCollation() const;

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

  virtual bool 
  registerStatelessExternalFunction(StatelessExternalFunction* aExternalFunction);

  virtual void
  setDocumentURIResolver(DocumentURIResolver* aDocumentURIResolver);

  virtual DocumentURIResolver*
  getDocumentURIResolver();

  virtual void
  setCollectionURIResolver(CollectionURIResolver* aCollectionUriResolver);

  virtual CollectionURIResolver*
  getCollectionURIResolver();

  virtual void
  setSchemaURIResolver(SchemaURIResolver* aSchemaUriResolver);

  virtual SchemaURIResolver*
  getSchemaURIResolver();

  virtual void
  setModuleURIResolver(ModuleURIResolver* aModuleUriResolver);

  virtual ModuleURIResolver*
  getModuleURIResolver();

  virtual bool
  containsFunction(const String& aFnNameUri, const String& aFnNameLocal, int arity) const;
};

} /* namespace zorba */
#endif
