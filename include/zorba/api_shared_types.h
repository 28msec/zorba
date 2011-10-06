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
#ifndef ZORBA_SHARED_TYPES_INCL_H
#define ZORBA_SHARED_TYPES_INCL_H

#include <memory>

#include <zorba/config.h>
#include <zorba/smart_ptr.h>

namespace zorba {

  class Zorba;
  class XQuery;
  class StaticContext;
  class DynamicContext;
  class XmlDataManager;
  class DocumentManager;
  class CollectionManager;
  class StaticCollectionManager;
  class ItemFactory;
  class Iterator;
  class StatelessExternalFunction;
  class ExternalFunctionParameter;
  class ExternalModule;
  class TypeIdentifier;
  class ItemSequence;
  class Collection;
  class Function;
  class Annotation;
  class SerializationCallback;
  class File;
  class DirectoryIterator;
  class Serializer;

  class DiagnosticHandler;
  class QueryLocation;
  typedef SmartPtr<QueryLocation> QueryLocation_t;

#ifndef ZORBA_NO_FULL_TEXT
  class StemmerProvider;
  class TokenizerProvider;
#endif /* ZORBA_NO_FULL_TEXT */

  // smart pointers
  typedef zorba::SmartPtr<XQuery>                  XQuery_t;
  typedef zorba::SmartPtr<StaticContext>           StaticContext_t;
  typedef zorba::SmartPtr<Iterator>                Iterator_t;
  typedef zorba::SmartPtr<TypeIdentifier>          TypeIdentifier_t;
  typedef zorba::SmartPtr<Collection>              Collection_t;
  typedef zorba::SmartPtr<Function>                Function_t;
  typedef zorba::SmartPtr<Annotation>              Annotation_t;
  typedef zorba::SmartPtr<File>                    File_t;
  typedef zorba::SmartPtr<DirectoryIterator>       DirectoryIterator_t;
  typedef zorba::SmartPtr<Serializer>              Serializer_t;
  typedef zorba::SmartPtr<ItemSequence>            ItemSequence_t;

  // data handlers
  class Item;
  class String;

  // uri resolvers
  class URIMapper;
  class Resource;
  class URLResolver;

  namespace audit {
    class Provider;
    class Event;
    class ScopedRecord;
  }

} /* namespace zorba */
#endif
/* vim:set et sw=2 ts=2: */
