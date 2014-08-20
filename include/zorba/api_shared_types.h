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

#include <zorba/config.h>
#include <zorba/util/smart_ptr.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class Annotation;
class Collection;
class CollectionManager;
class DiagnosticHandler;
class DocumentManager;
class DynamicContext;
class ExternalFunctionParameter;
class ExternalModule;
class Function;
class ItemFactory;
class ItemSequence;
class Iterator;
class JsonDataManager;
class ModuleInfo;
class QueryLocation;
class SequenceType;
class SerializationCallback;
class Serializer;
class StatelessExternalFunction;
class StaticCollectionManager;
class StaticContext;
#ifndef ZORBA_NO_FULL_TEXT
class StemmerProvider;
class TokenizerProvider;
#endif /* ZORBA_NO_FULL_TEXT */
class XmlDataManager;
class XQuery;
class Zorba;

// smart pointers
typedef SmartPtr<Annotation>      Annotation_t;
typedef SmartPtr<Collection>      Collection_t;
typedef SmartPtr<Function>        Function_t;
typedef SmartPtr<ItemSequence>    ItemSequence_t;
typedef SmartPtr<Iterator>        Iterator_t;
typedef SmartPtr<JsonDataManager> JsonDataManager_t;
typedef SmartPtr<ModuleInfo>      ModuleInfo_t;
typedef SmartPtr<QueryLocation>   QueryLocation_t;
typedef SmartPtr<Serializer>      Serializer_t;
typedef SmartPtr<StaticContext>   StaticContext_t;
typedef SmartPtr<XmlDataManager>  XmlDataManager_t;
typedef SmartPtr<XQuery>          XQuery_t;

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

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_SHARED_TYPES_INCL_H */
/* vim:set et sw=2 ts=2: */
