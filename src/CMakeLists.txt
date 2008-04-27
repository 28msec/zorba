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
INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/AddSrcSubfolder.cmake)

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_SOURCE_DIR}/external) # must be removed if pthread.h is removed from util/rwlock.h/cpp

# only platform headers and configuration stuff is in there
ADD_SUBDIRECTORY(common)

# generate the zorba library
SET(ZORBA_SRCS)

############################################################ Add files compiled into the library
ADD_SRC_SUBFOLDER(ZORBA_SRCS api API_SRCS )
FOREACH (SRCS ${API_BUILD_SRCS})
  LIST(APPEND ZORBA_SRCS ${SRCS})
ENDFOREACH (SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS compiler COMPILER_SRCS)
FOREACH (SRCS ${COMPILER_BUILD_SRCS})
  LIST(APPEND ZORBA_SRCS ${SRCS})
ENDFOREACH (SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS zorbatypes ZORBATYPES_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS system SYSTEM_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS context CONTEXT_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS errors	ERRORS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS functions FUNCTIONS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS runtime RUNTIME_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS store STORE_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS types TYPES_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS util UTIL_SRCS)

############################################################ Zorba library
IF (MSVC)
  ADD_LIBRARY(zorba ${ZORBA_SRCS})
ELSE (MSVC)
  ADD_LIBRARY(zorba SHARED ${ZORBA_SRCS})
ENDIF (MSVC)

TARGET_LINK_LIBRARIES(zorba ${requiredlibs})
SET_TARGET_PROPERTIES(zorba PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})
SET_TARGET_PROPERTIES(zorba PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET(ZORBA_LIBRARY_INSTALL_LIST ${ZORBA_LIBRARY_INSTALL_LIST} zorba)


############################################################ Zorba STATIC library
IF (ZORBA_BUILD_STATIC_LIBRARY)
  ADD_LIBRARY(zorba_static STATIC ${ZORBA_SRCS})
  TARGET_LINK_LIBRARIES(zorba_static ${requiredlibs})
  SET_TARGET_PROPERTIES(zorba_static PROPERTIES OUTPUT_NAME "zorba_static")  
  SET_TARGET_PROPERTIES(zorba_static PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})  
  SET_TARGET_PROPERTIES(zorba_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)  
  SET(ZORBA_LIBRARY_INSTALL_LIST ${ZORBA_LIBRARY_INSTALL_LIST} zorba_static)
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

INSTALL(TARGETS ${ZORBA_LIBRARY_INSTALL_LIST}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
