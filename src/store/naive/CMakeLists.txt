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
    item.cpp
    item_vector.cpp
    node_items.cpp
    node_factory.cpp
    node_updates.cpp
    simple_pul.cpp
    pul_primitives.cpp
    pul_primitive_factory.cpp
    atomic_items.cpp
    item_iterator.cpp
    node_iterators.cpp
    simple_item_factory.cpp
    simple_store.cpp
    simple_iterator_factory.cpp
    simple_collection.cpp
    simple_collection_set.cpp
    simple_index.cpp
    simple_index_value.cpp
    simple_index_general.cpp
    simple_temp_seq.cpp
    simple_lazy_temp_seq.cpp
    loader_fast.cpp
    loader_dtd.cpp
    qname_pool.cpp
    string_pool.cpp
    ordpath.cpp
    nsbindings.cpp
    properties.cpp
    inmemorystore.cpp
    inmemorystorec.cpp
    dataguide.cpp
)

IF (NOT ZORBA_NO_FULL_TEXT)
  LIST(APPEND ZORBA_STORE_IMPL_SRCS
    ft_token_store.cpp naive_ft_token_iterator.cpp)
ENDIF (NOT ZORBA_NO_FULL_TEXT)
