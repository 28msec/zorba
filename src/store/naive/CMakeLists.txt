# Copyright 2006-2008 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#
# Source Files
#
SET(ZORBA_STORE_IMPL_SRCS
    atomic_items.h
    atomic_items.cpp
    collection.h
    collection.cpp
    collection_set.h
    dataguide.h
    dataguide.cpp
    document_name_iterator.h
    hashmap_nodep.h
    inmemorystore.cpp
    inmemorystorec.cpp
    item.cpp
    item_iterator.h
    item_iterator.cpp
    item_vector.h
    item_vector.cpp
    loader.h
    loader_fast.cpp
    loader_dtd.cpp
    name_iterator.h
    node_factory.h
    node_factory.cpp
    node_items.h
    node_items.cpp
    node_iterators.h
    node_iterators.cpp
    node_updates.h
    node_updates.cpp
    nsbindings.h
    nsbindings.cpp
    ordpath.h
    ordpath.cpp
    properties.h
    properties.cpp
    pul_primitive_factory.h
    pul_primitive_factory.cpp
    pul_primitives.h
    pul_primitives.cpp
    qname_pool.h
    qname_pool.cpp
    shared_types.h
    simple_collection.h
    simple_collection.cpp
    simple_collection_set.h
    simple_collection_set.cpp
    simple_ic.h
    simple_index.h
    simple_index.cpp
    simple_index_general.h
    simple_index_general.cpp
    simple_index_value.h
    simple_index_value.cpp
    simple_item_factory.h
    simple_item_factory.cpp
    simple_iterator_factory.h
    simple_iterator_factory.cpp
    simple_lazy_temp_seq.h
    simple_lazy_temp_seq.cpp
    simple_pul.h
    simple_pul.cpp
    simple_store.h
    simple_store.cpp
    simple_temp_seq.h
    simple_temp_seq.cpp
    store.cpp
    store_defs.h
    store_manager_impl.h
    store_properties.h
    string_pool.h
    string_pool.cpp
    structured_item.h
    structured_item.cpp
    text_node_content.h
    tree_id.h
    tree_id_generator.h
    tree_id_generator.cpp
)

IF (NOT ZORBA_NO_FULL_TEXT)
  LIST(APPEND ZORBA_STORE_IMPL_SRCS
    ft_token_store.h
    ft_token_store.cpp
    naive_ft_token_iterator.h
    naive_ft_token_iterator.cpp)
ENDIF (NOT ZORBA_NO_FULL_TEXT)

IF (ZORBA_WITH_JSON)
  LIST(APPEND ZORBA_STORE_IMPL_SRCS
    json_items.h
    json_items.cpp
    json_loader.h
    json_loader.cpp
  )
ENDIF (ZORBA_WITH_JSON)

