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

# define an extension to the name of the library that is greated with this store
SET(ZORBA_STORE_LIB_EXTENSION "minimal")

#
# Source Files
#
SET(ZORBA_STORE_IMPL_SRCS
    min_atomic_items.cpp
    min_collection.cpp
    min_item.cpp
    min_item_factory.cpp
    min_item_iterator.cpp
    min_item_vector.cpp
    min_iterator_factory.cpp
    min_lazy_temp_seq.cpp
    min_loader.cpp
    min_node_items.cpp
    min_node_iterators.cpp
    min_node_updates.cpp
    min_node_vector.cpp
    min_nsbindings.cpp
    min_ordpath.cpp
    min_pul.cpp
    min_query_context.cpp
    min_store.cpp
    min_temp_seq.cpp
    qname_pool.cpp
    string_pool.cpp
    min_tupleimpl.cpp
)
