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

SET(ZORBA_STORE_MSDOM OFF CACHE BOOL "select the MS DOM store")
SET(ZORBA_MSDOM_IN_NATIVE_STORE_CACHING ON CACHE BOOL "select if all info in msdom should be cached into native store node items style")

# define an extension to the name of the library that is greated with this store
SET(ZORBA_STORE_LIB_EXTENSION "simplestore" CACHE STRING "store name" FORCE)

#
# Source Files
#
SET(ZORBA_STORE_IMPL_SRCS
    item.cpp
    item_vector.cpp
    node_vector.cpp
    node_items.cpp
    node_updates.cpp
    simple_pul.cpp
    pul_primitives.cpp
    atomic_items.cpp
    item_iterator.cpp
    node_iterators.cpp
    simple_item_factory.cpp
    simple_store.cpp
    simple_iterator_factory.cpp
    simple_collection.cpp
    simple_index.cpp
    simple_temp_seq.cpp
    simple_lazy_temp_seq.cpp
    loader_fast.cpp
    qname_pool.cpp
    string_pool.cpp
    ordpath.cpp
    nsbindings.cpp
    properties.cpp
    inmemorystore.cpp
    inmemorystorec.cpp
    dataguide.cpp
    tupleimpl.cpp
)

IF(ZORBA_STORE_MSDOM)
	LIST(APPEND ZORBA_STORE_IMPL_SRCS		msdom_addon/msdom_node_items.cpp)
	LIST(APPEND ZORBA_STORE_IMPL_SRCS		msdom_addon/import_msdom.cpp)
	LIST(APPEND ZORBA_STORE_IMPL_SRCS		msdom_addon/import_impl.cpp)
ELSE(ZORBA_STORE_MSDOM)
#	LIST(APPEND ZORBA_STORE_IMPL_SRCS		node_items.cpp)
ENDIF(ZORBA_STORE_MSDOM)

CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/src/store/naive/store_config.h.cmake ${CMAKE_BINARY_DIR}/src/store/naive/store_config.h)
