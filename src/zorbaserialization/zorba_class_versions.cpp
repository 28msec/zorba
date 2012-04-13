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
#include "stdafx.h"

#include "store/api/iterator.h"

#include "compiler/xqddf/collection_decl.h"
#include "compiler/xqddf/value_index.h"
#include "compiler/xqddf/value_ic.h"
#include "compiler/expression/var_expr.h"

#include "context/static_context.h"

#include "types/typeimpl.h"

#include "functions/function.h"

#define ZORBA_HASHMAP_WITH_SERIALIZATION
#include "util/hashmap.h"
#undef ZORBA_HASHMAP_WITH_SERIALIZATION

#define ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION
#include "zorbautils/hashmap.h"
#include "zorbautils/hashmap_itemp.h"
#undef ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION

#include "zorbaserialization/class_serializer.h"

#include "zorbatypes/rchandle.h"

#include "common/shared_types.h"


namespace zorba{

SERIALIZABLE_CLASS_VERSIONS(RCObject)

SERIALIZABLE_CLASS_VERSIONS(SimpleRCObject)

SERIALIZABLE_CLASS_VERSIONS(store::Iterator)

// QQQ should be zstring?
typedef serializable_hashmap<std::string,xqtref_t> SER_HASHMAP_T;
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_hashmap, SER_HASHMAP_T, 3)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_hashmap_entry, SER_HASHMAP_T::entry, 3)


//
// HashMap serialization
//

// ItemPointerHashMapCmp
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(serializable_HashEntry, serializable_HashEntry<store::Item*, StaticallyKnownCollection_t>, 1)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(serializable_HashEntry, serializable_HashEntry<store::Item*, IndexDecl_t>, 2)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(serializable_HashEntry, serializable_HashEntry<store::Item*, ValueIC_t>, 3)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(serializable_HashEntry, serializable_HashEntry<store::Item*, FunctionInfo>, 4)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(serializable_HashEntry, serializable_HashEntry<store::Item*, std::vector<FunctionInfo>* >, 5)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(serializable_HashEntry, serializable_HashEntry<store::Item*, var_expr_t>, 7)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(serializable_HashEntry, serializable_HashEntry<store::Item*, PrologOption>, 8)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(serializable_HashMap, serializable_HashMap<store::Item*, StaticallyKnownCollection_t, ser_ItemPointerHashMapCmp>, 1)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(serializable_HashMap, serializable_HashMap<store::Item*, IndexDecl_t, ser_ItemPointerHashMapCmp>, 2)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(serializable_HashMap, serializable_HashMap<store::Item*, ValueIC_t, ser_ItemPointerHashMapCmp>, 3)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(serializable_HashMap, serializable_HashMap<store::Item*, FunctionInfo, ser_ItemPointerHashMapCmp>, 4)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(serializable_HashMap, serializable_HashMap<store::Item*, std::vector<FunctionInfo>*, ser_ItemPointerHashMapCmp>, 5)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(serializable_HashMap, serializable_HashMap<store::Item*, var_expr_t, ser_ItemPointerHashMapCmp>, 7)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(serializable_HashMap, serializable_HashMap<store::Item*, PrologOption, ser_ItemPointerHashMapCmp>, 8)

SERIALIZABLE_CLASS_VERSIONS(ser_ItemPointerHashMapCmp)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_ItemPointerHashMap, serializable_ItemPointerHashMap<StaticallyKnownCollection_t>, 1)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_ItemPointerHashMap, serializable_ItemPointerHashMap<IndexDecl_t>, 2)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_ItemPointerHashMap, serializable_ItemPointerHashMap<ValueIC_t>, 3)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_ItemPointerHashMap, serializable_ItemPointerHashMap<FunctionInfo>, 4)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_ItemPointerHashMap, serializable_ItemPointerHashMap<std::vector<FunctionInfo>* >, 5)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_ItemPointerHashMap, serializable_ItemPointerHashMap<var_expr_t>, 7)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_ItemPointerHashMap, serializable_ItemPointerHashMap<PrologOption>, 8)



// HashMapZString
SERIALIZABLE_CLASS_VERSIONS(serializable_HashMapZStringCmp)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(serializable_HashEntry, serializable_HashEntry<zstring, static_context::ctx_module_t>, 11)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(serializable_HashMap, serializable_HashMap<zstring, static_context::ctx_module_t, serializable_HashMapZStringCmp>, 11)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_HashMapZString, serializable_HashMapZString<static_context::ctx_module_t>, 1)


SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(serializable_HashEntry, serializable_HashEntry<zstring, zstring>, 12)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(serializable_HashMap, serializable_HashMap<zstring, zstring, serializable_HashMapZStringCmp>,12)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_HashMapZString, serializable_HashMapZString<zstring>, 2)


// Definitions for the serializable_HashMapZString<xqtref_t> type
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(serializable_HashEntry, serializable_HashEntry<zstring, xqtref_t>, 13)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(serializable_HashMapZString, serializable_HashMapZString<xqtref_t>, 3)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(serializable_HashMap, serializable_HashMap<zstring, xqtref_t, serializable_HashMapZStringCmp>,13)

}
/* vim:set et sw=2 ts=2: */
