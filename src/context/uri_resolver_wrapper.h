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
#ifndef ZORBA_URI_RESOLVERS_WRAPPER_H
#define ZORBA_URI_RESOLVERS_WRAPPER_H

#include "context/internal_uri_resolvers.h"

namespace zorba {


/*******************************************************************************
  DocumentURIResolverWrapper wraps a user-provided DocumentURIResolver obj.
  DocumentURIResolver is a c++ API class that offers the same functionality as
  InternalDocumentURIResolver, but uses c++ API types for the perametes and the
  results of its methods. So, the purpose of this wrapper class is to do data
  marshaling and unmarshaling, so that invocations of InternalDocumentURIResolver
  methods are converted to invocations of the corresponding DocumentURIResolver
  methods 
********************************************************************************/
class DocumentURIResolverWrapper : public InternalDocumentURIResolver
{
public:
  DocumentURIResolverWrapper(DocumentURIResolver*);

  virtual ~DocumentURIResolverWrapper() {}

  virtual store::Item_t resolve(
        const store::Item_t& aURI,
        static_context* aStaticContext,
        bool validateUri,
        bool tidying,
        bool replaceDoc,
        const store::Item_t& tidyUserOpt = NULL);
  
protected:
  friend class StaticContextImpl;

  DocumentURIResolver* theDocResolver;
};


/*******************************************************************************

********************************************************************************/
class CollectionURIResolverWrapper : public InternalCollectionURIResolver
{
public:
  CollectionURIResolverWrapper(CollectionURIResolver*);
  
  virtual ~CollectionURIResolverWrapper() {}

  virtual store::Collection_t resolve(
        const store::Item_t& aURI,
        static_context* aStaticContext);

protected:
  friend class StaticContextImpl;

  CollectionURIResolver* theColResolver;
};


/*******************************************************************************

********************************************************************************/
class SchemaURIResolverWrapper : public InternalSchemaURIResolver
{
public:
  SchemaURIResolverWrapper(SchemaURIResolver*);
  
  virtual ~SchemaURIResolverWrapper() {}
      
  virtual std::string resolve(
        const store::Item_t& aURI,
        static_context* aStaticContext,
        std::vector<store::Item_t>& aAtList,
        zstring& aFileUri);

protected:
  friend class StaticContextImpl;

  SchemaURIResolver* theSchemaResolver;
};


#ifndef ZORBA_NO_FULL_TEXT
/*******************************************************************************

********************************************************************************/
class ThesaurusURIResolverWrapper : public InternalThesaurusURIResolver
{
public:
  ThesaurusURIResolverWrapper(ThesaurusURIResolver*);
  
  virtual ~ThesaurusURIResolverWrapper() {}
      
  virtual zstring
  resolve(const store::Item_t& aURI,
          static_context* aStaticContext);

protected:
  friend class StaticContextImpl;

  ThesaurusURIResolver* theThesaurusResolver;
};
#endif


/*******************************************************************************

********************************************************************************/
class ModuleURIResolverWrapper : public InternalModuleURIResolver
{
  friend class StaticContextImpl;

protected:
  ModuleURIResolver* theModuleResolver;

public:
  ModuleURIResolverWrapper(ModuleURIResolver*);
  
  virtual ~ModuleURIResolverWrapper() {}

  void resolveTargetNamespace(
        const std::string& nsURI,
        static_context& sctx,
        std::vector<std::string>& compURIs);

  std::istream* resolve(
        const std::string& uri,
        static_context& sctx,
        std::string& url);
};


} /* namespace zorba */

#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
