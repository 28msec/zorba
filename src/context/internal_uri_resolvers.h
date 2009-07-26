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
#ifndef ZORBA_URI_RESOLVERS_H
#define ZORBA_URI_RESOLVERS_H

#include <istream>
#include <vector>

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"
#include "store/api/item.h"

#include "zorbaserialization/serialization_engine.h"

namespace zorba {

  class InternalDocumentURIResolver : public ::zorba::serialization::SerializeBaseClass
  {
    public:
      virtual ~InternalDocumentURIResolver() {}

      virtual store::Item_t
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext,
              bool validate,
              bool tidying,
              const store::Item_t& tidyUserOpt = NULL) = 0;
    public:
      SERIALIZABLE_ABSTRACT_CLASS(InternalDocumentURIResolver)
      SERIALIZABLE_CLASS_CONSTRUCTOR(InternalDocumentURIResolver)
      InternalDocumentURIResolver() {}
      void serialize(::zorba::serialization::Archiver &ar)
      {
      }
  };

  class InternalCollectionURIResolver : public ::zorba::serialization::SerializeBaseClass
  {
    public:
      virtual ~InternalCollectionURIResolver() {}

      virtual store::Collection_t 
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext) = 0;
    public:
      SERIALIZABLE_ABSTRACT_CLASS(InternalCollectionURIResolver)
      SERIALIZABLE_CLASS_CONSTRUCTOR(InternalCollectionURIResolver)
      InternalCollectionURIResolver() {}
      void serialize(::zorba::serialization::Archiver &ar)
      {
      }
  };

  class InternalSchemaURIResolver : public ::zorba::serialization::SerializeBaseClass
  {
    public:
      virtual ~InternalSchemaURIResolver() {}
      
      virtual store::Item_t
      resolve(const store::Item_t& aURI,
              const std::vector<store::Item_t>& aLocationHints,
              static_context* aStaticContext) = 0;
    public:
      SERIALIZABLE_ABSTRACT_CLASS(InternalSchemaURIResolver)
      SERIALIZABLE_CLASS_CONSTRUCTOR(InternalSchemaURIResolver)
      InternalSchemaURIResolver() {}
      void serialize(::zorba::serialization::Archiver &ar)
      {
      }
  };

  class InternalModuleURIResolver : public ::zorba::serialization::SerializeBaseClass
  {
    public:
      virtual ~InternalModuleURIResolver() {}

      virtual std::istream*
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext,
              xqpStringStore* aFileUri = 0) = 0;
    public:
      SERIALIZABLE_ABSTRACT_CLASS(InternalModuleURIResolver)
      SERIALIZABLE_CLASS_CONSTRUCTOR(InternalModuleURIResolver)
      InternalModuleURIResolver() {}
      void serialize(::zorba::serialization::Archiver &ar)
      {
      }
  };

} /* namespace zorba */

#endif
