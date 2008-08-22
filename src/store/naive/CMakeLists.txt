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

#
# Source Files
#
SET(SIMPLE_STORE_SRCS
    simple_store.cpp
    basic_item_factory.cpp
    simple_iterator_factory.cpp
    simple_collection.cpp
    simple_temp_seq.cpp
    simple_lazy_temp_seq.cpp
    simple_pul.cpp
    simple_loader.cpp
    fast_loader.cpp
    qname_pool.cpp
    string_pool.cpp
    item.cpp
    item_vector.cpp
    item_iterator.cpp
    atomic_items.cpp
    node_vector.cpp
    node_updates.cpp
    node_iterators.cpp
    ordpath.cpp
    nsbindings.cpp
    properties.cpp
    inmemorystore.cpp
    inmemorystorec.cpp
    dataguide.cpp
    tupleimpl.cpp
)

IF(ZORBA_STORE_MSDOM)
	LIST(APPEND SIMPLE_STORE_SRCS		msdom_addon/msdom_node_items.cpp)
ELSE(ZORBA_STORE_MSDOM)
	LIST(APPEND SIMPLE_STORE_SRCS		node_items.cpp)
ENDIF(ZORBA_STORE_MSDOM)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/store_config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/store_config.h)


#
# Internal common libraries
#
SET(requiredlibs-simplestore ${requiredlibs-simplestore} zorbautils)
SET(requiredlibs-simplestore ${requiredlibs-simplestore} zorbatypes)
SET(requiredlibs-simplestore ${requiredlibs-simplestore} zorbaerrors)


SET(SIMPLESTORE_INSTALL_LIST)

IF (ZORBA_BUILD_STATIC_LIBRARY)

  ADD_LIBRARY(simplestore_static ${SIMPLE_STORE_SRCS})
  TARGET_LINK_LIBRARIES(simplestore_static ${requiredlibs-simplestore})

  SET_TARGET_PROPERTIES(simplestore_static PROPERTIES OUTPUT_NAME "simplestore")  
  SET_TARGET_PROPERTIES(simplestore_static PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})  
  SET_TARGET_PROPERTIES(simplestore_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

  SET(SIMPLESTORE_INSTALL_LIST ${SIMPLESTORE_INSTALL_LIST} simplestore_static)

ENDIF (ZORBA_BUILD_STATIC_LIBRARY)


IF (MSVC)
  ADD_LIBRARY(simplestore ${SIMPLE_STORE_SRCS})
ELSE (MSVC)
  ADD_LIBRARY(simplestore SHARED ${SIMPLE_STORE_SRCS})
ENDIF (MSVC)

TARGET_LINK_LIBRARIES(simplestore ${requiredlibs-simplestore})

SET_TARGET_PROPERTIES(simplestore PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})

SET_TARGET_PROPERTIES(simplestore PROPERTIES CLEAN_DIRECT_OUTPUT 1)

SET(SIMPLESTORE_INSTALL_LIST ${SIMPLESTORE_INSTALL_LIST} simplestore)

INSTALL(TARGETS ${SIMPLESTORE_INSTALL_LIST}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

SET(STORE_LIB simplestore CACHE INTERNAL "store used" FORCE)
