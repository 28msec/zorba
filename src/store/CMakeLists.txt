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

IF(ZORBA_MINIMAL_STORE)

SET(STORE_SRCS
    minimal/min_item_factory.cpp
    minimal/min_collection.cpp
    minimal/min_temp_seq.cpp
    minimal/min_atomic_items.cpp
    minimal/min_item.cpp
    minimal/min_node_items.cpp
    minimal/min_node_vector.cpp
    minimal/min_node_updates.cpp
    minimal/min_node_iterators.cpp
    minimal/min_store.cpp
    minimal/min_loader.cpp
    minimal/min_pul.cpp
    minimal/min_ordpath.cpp
    minimal/min_nsbindings.cpp
    minimal/min_item_iterator.cpp
    minimal/min_query_context.cpp
    minimal/qname_pool.cpp
    minimal/string_pool.cpp)

HEADER_GROUP_SUBFOLDER(STORE_SRCS api)
HEADER_GROUP_SUBFOLDER(STORE_SRCS util)
HEADER_GROUP_SUBFOLDER(STORE_SRCS update)

HEADER_GROUP_SUBFOLDER(STORE_SRCS minimal)


ELSE(ZORBA_MINIMAL_STORE)

ADD_SUBDIRECTORY(naive)

ENDIF(ZORBA_MINIMAL_STORE)

