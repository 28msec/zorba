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

SET(storeRequiredLibs ${storeRequiredLibs} ${BOOST_PROGRAM_OPTIONS})
#####################################################  LibXml2
FIND_PACKAGE(LibXml2)
IF(LIBXML2_FOUND)
    MESSAGE(STATUS "Found  LIBXML2 library -- " ${LIBXML2_LIBRARIES})
    INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
    SET(storeRequiredLibs ${storeRequiredLibs} ${LIBXML2_LIBRARIES})
    SET(CXXFLAGS ${CXXFLAGS} ${LIBXML2_DEFINITONS})
ELSE(LIBXML2_FOUND)
    MESSAGE(FATAL_ERROR "The libxml2 library is required in order to build simple store.")
ENDIF(LIBXML2_FOUND)


SET(SIMPLE_STORE_SRCS
    basic_item_factory.cpp
    simple_collection.cpp
    simple_temp_seq.cpp
    atomic_items.cpp
    item.cpp
    node_items.cpp
    node_vector.cpp
    node_updates.cpp
    node_iterators.cpp
    qname_pool.cpp
    simple_store.cpp
    simple_storec.cpp
    simple_loader.cpp
    simple_pul.cpp
    ordpath.cpp
    nsbindings.cpp
    item_iterator.cpp
    query_context.cpp
    string_pool.cpp
    properties.cpp
    )

ADD_LIBRARY(simplestore ${SIMPLE_STORE_SRCS})

TARGET_LINK_LIBRARIES(simplestore ${storeRequiredLibs})


SET(ZORBA_LIBRARY_INSTALL_LIST ${ZORBA_LIBRARY_INSTALL_LIST} simplestore)
