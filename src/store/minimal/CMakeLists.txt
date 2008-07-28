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
SET(MIN_STORE_SRCS
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
)

#
# Internal common libraries
#
SET(requiredlibs-minimalstore ${requiredlibs-minimalstore} zorbautils)
SET(requiredlibs-minimalstore ${requiredlibs-minimalstore} zorbatypes)
SET(requiredlibs-minimalstore ${requiredlibs-minimalstore} zorbaerrors)


SET(MINIMALSTORE_INSTALL_LIST)

IF (ZORBA_BUILD_STATIC_LIBRARY)

  ADD_LIBRARY(minimalstore_static ${MIN_STORE_SRCS})
  TARGET_LINK_LIBRARIES(minimalstore_static ${requiredlibs-minimalstore})

  SET_TARGET_PROPERTIES(minimalstore_static PROPERTIES OUTPUT_NAME "minimalstore")  
  SET_TARGET_PROPERTIES(minimalstore_static PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})  
  SET_TARGET_PROPERTIES(minimalstore_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

  SET(MINIMALSTORE_INSTALL_LIST ${MINIMALSTORE_INSTALL_LIST} minimalstore_static)

ENDIF (ZORBA_BUILD_STATIC_LIBRARY)


IF (MSVC)
  ADD_LIBRARY(minimalstore ${MIN_STORE_SRCS})
ELSE (MSVC)
  ADD_LIBRARY(minimalstore SHARED ${MIN_STORE_SRCS})
ENDIF (MSVC)

TARGET_LINK_LIBRARIES(minimalstore ${requiredlibs-minimalstore})

SET_TARGET_PROPERTIES(minimalstore PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})

SET_TARGET_PROPERTIES(minimalstore PROPERTIES CLEAN_DIRECT_OUTPUT 1)

SET(MINIMALSTORE_INSTALL_LIST ${MINIMALSTORE_INSTALL_LIST} minimalstore)

INSTALL(TARGETS ${MINIMALSTORE_INSTALL_LIST}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

SET(STORE_LIB minimalstore CACHE INTERNAL "store used" FORCE)

