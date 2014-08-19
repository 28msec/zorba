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

#ifndef ZORBA_STORE_API_SHARED_TYPES
#define ZORBA_STORE_API_SHARED_TYPES

#include <vector>

#include "zorbamisc/config/platform.h"

#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"

#include "store/api/item_handle.h"

namespace zorba 
{ 

typedef std::vector<char>::size_type csize;


namespace store 
{

typedef std::vector<std::pair<zstring, zstring> > NsBindings;


class CopyMode;

class ItemFactory;

class Item;
typedef ItemHandle<Item> Item_t;

class AnyUriItem;
typedef ItemHandle<AnyUriItem> AnyUriItem_t;

class PUL;
typedef ItemHandle<PUL> PUL_t;

class IteratorFactory;

class Iterator;
typedef rchandle<Iterator> Iterator_t;

class ItemIterator;
typedef rchandle<ItemIterator> ItemIterator_t;

class TempSeq;
typedef rchandle<TempSeq> TempSeq_t;

class TempSeqIterator;
typedef rchandle<TempSeqIterator> TempSeqIterator_t;

class Collection;
typedef rchandle<Collection> Collection_t;

class Index;
typedef rchandle<Index> Index_t;

class IndexEntryReceiver;
typedef rchandle<IndexEntryReceiver> IndexEntryReceiver_t;

class IndexCondition;
typedef rchandle<IndexCondition> IndexCondition_t;

class IndexPointCondition;
typedef rchandle<IndexPointCondition> IndexPointCondition_t;

class IndexBoxCondition;
typedef rchandle<IndexBoxCondition> IndexBoxCondition_t;

class IndexKey;

class IndexProbeIterator;
typedef rchandle<IndexProbeIterator> IndexProbeIterator_t;

class Store;
class XmlDataManager_Impl;
class JsonDataManager_Impl;

class IC;
typedef rchandle<IC> IC_t;

class ICChecker;

class Annotation;
typedef rchandle<Annotation> Annotation_t;


} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_API_SHARED_TYPES */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
