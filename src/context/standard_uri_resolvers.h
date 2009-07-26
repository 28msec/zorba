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
#ifndef ZORBA_STANDARD_URI_RESOLVERS_H
#define ZORBA_STANDARD_URI_RESOLVERS_H

#include "context/internal_uri_resolvers.h"

namespace zorba {

  class StandardDocumentURIResolver : public InternalDocumentURIResolver
  {
    public:
      virtual ~StandardDocumentURIResolver() {}

      virtual store::Item_t
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext,
              bool validate,
              bool tidying,
              const store::Item_t& tidyUserOpt = NULL);
    public:
      SERIALIZABLE_CLASS(StandardDocumentURIResolver)
      SERIALIZABLE_CLASS_CONSTRUCTOR2(StandardDocumentURIResolver, InternalDocumentURIResolver)
      StandardDocumentURIResolver() {}
      void serialize(::zorba::serialization::Archiver &ar)
      {
        serialize_baseclass(ar, (InternalDocumentURIResolver*)this);
      }
  };

  class StandardCollectionURIResolver : public InternalCollectionURIResolver
  {
    public:
      virtual ~StandardCollectionURIResolver() {}

      virtual store::Collection_t 
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext);
    public:
      SERIALIZABLE_CLASS(StandardCollectionURIResolver)
      SERIALIZABLE_CLASS_CONSTRUCTOR2(StandardCollectionURIResolver, InternalCollectionURIResolver)
      StandardCollectionURIResolver() {}
      void serialize(::zorba::serialization::Archiver &ar)
      {
        serialize_baseclass(ar, (InternalCollectionURIResolver*)this);
      }
  };

  class StandardSchemaURIResolver : public InternalSchemaURIResolver
  {
    public:
      virtual ~StandardSchemaURIResolver() {}
      
      virtual store::Item_t
      resolve(const store::Item_t& aURI,
              const std::vector<store::Item_t>& aLocationHints,
              static_context* aStaticContext);
    public:
      SERIALIZABLE_CLASS(StandardSchemaURIResolver)
      SERIALIZABLE_CLASS_CONSTRUCTOR2(StandardSchemaURIResolver, InternalSchemaURIResolver)
      StandardSchemaURIResolver() {}
      void serialize(::zorba::serialization::Archiver &ar)
      {
        serialize_baseclass(ar, (InternalSchemaURIResolver*)this);
      }
  };

  class StandardModuleURIResolver : public InternalModuleURIResolver
  {
    public:
      virtual ~StandardModuleURIResolver() {}

      virtual std::istream*
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext,
              xqpStringStore* aFileUri = 0);
    public:
      SERIALIZABLE_CLASS(StandardModuleURIResolver)
      SERIALIZABLE_CLASS_CONSTRUCTOR2(StandardModuleURIResolver, InternalModuleURIResolver)
      StandardModuleURIResolver() {}
      void serialize(::zorba::serialization::Archiver &ar)
      {
        serialize_baseclass(ar, (InternalModuleURIResolver*)this);
      }
  };

  /*
    This is a small helper class used when the user whants to compile a library module.
    The ONLY place it is used (and should be used) is in the XQueryCompiler::createMainModule method
  */
  class StandardLibraryModuleURIResolver : public InternalModuleURIResolver
  {
    private:
      std::istream& theStream;
      std::string   theLibraryModuleNamespace;

    public:
      StandardLibraryModuleURIResolver (std::istream& aXQuery, std::string lib_namespace)
      : theStream (aXQuery), theLibraryModuleNamespace (lib_namespace) {}

      virtual ~StandardLibraryModuleURIResolver() {}

      virtual std::istream*
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext,
              xqpStringStore* = 0);
    public:
      SERIALIZABLE_CLASS(StandardLibraryModuleURIResolver)
      StandardLibraryModuleURIResolver(::zorba::serialization::Archiver &ar)  
              : InternalModuleURIResolver(ar) ,
               theStream(std::cin) {}
      StandardLibraryModuleURIResolver() : theStream(std::cin) {}
      void serialize(::zorba::serialization::Archiver &ar)
      {
        serialize_baseclass(ar, (InternalModuleURIResolver*)this);
        //ar & theStream;
        ar & theLibraryModuleNamespace;
      }
  };

} /* namespace zorba */

#endif

