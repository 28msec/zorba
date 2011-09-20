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

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/context/root_static_context_init.cpp.in
               ${CMAKE_CURRENT_BINARY_DIR}/context/root_static_context_init.cpp)
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/context/root_static_context_init.cpp.in =>
               ${CMAKE_CURRENT_BINARY_DIR}/context/root_static_context_init.cpp")

SET(CONTEXT_SRCS
    decimal_format.cpp
    dynamic_context.cpp
    static_context.cpp
    static_context_consts.cpp
    namespace_context.cpp
    root_static_context.cpp
    dynamic_loader.cpp
    sctx_map_iterator.cpp
    uri_resolver.cpp
    default_url_resolvers.cpp
    default_uri_mappers.cpp
    features.cpp
    )

IF (NOT ZORBA_NO_FULL_TEXT)
  LIST(APPEND CONTEXT_SRCS
    thesaurus_wrappers.cpp)
ENDIF (NOT ZORBA_NO_FULL_TEXT)

SET(CONTEXT_BUILD_SRCS
  ${CMAKE_CURRENT_BINARY_DIR}/context/root_static_context_init.cpp
  )

# vim:set et sw=2 ts=2:
