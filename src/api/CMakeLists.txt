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
                                  
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/api/version.cpp.cmake ${CMAKE_CURRENT_BINARY_DIR}/api/version.cpp)

SET(API_SRCS
    base64_util.cpp
    external_function.cpp
    smart_ptr.cpp
    diagnostic_handler.cpp
    iterator.cpp
    zorba.cpp
    zorbaimpl.cpp
    xqueryimpl.cpp
    sax2impl.cpp
    staticcontextimpl.cpp
    dynamiccontextimpl.cpp
    zorba_string.cpp
    hexbinary_util.cpp
    hexbinary_streambuf.cpp
    itemfactoryimpl.cpp
    item.cpp
    sequencetype.cpp
    unmarshaller.cpp
    xmldatamanagerimpl.cpp
    jsondatamanagerimpl.cpp
    documentmanagerimpl.cpp
    collectionmanagerimpl.cpp
    staticcollectionmanagerimpl.cpp
    collectionimpl.cpp
    options.cpp
    functionimpl.cpp
    serialization_callback.cpp
    item_iter_singleton.cpp
    item_iter_vector.cpp
    item_iter_store.cpp
    item_iter_query_result.cpp
    item_seq_vector.cpp
    item_seq_singleton.cpp
    item_seq_invoke.cpp
    item_seq_chainer.cpp
    item_seq_empty.cpp
    serializerimpl.cpp
    base64_streambuf.cpp
    uriimpl.cpp
    uriresolverimpl.cpp
    uri_resolver_wrappers.cpp
    xquery_functions.cpp
    zorba_functions.cpp
    annotationimpl.cpp
    auditimpl.cpp
    store_consts.cpp
    streambuf.cpp
    mem_streambuf.cpp
    properties.cpp
    transcode_streambuf.cpp
    uuid.cpp
    module_info_impl.cpp
    )

IF (NOT ZORBA_NO_FULL_TEXT)
  LIST(APPEND API_SRCS
    stemmer.cpp
    stemmer_wrappers.cpp
    thesaurus.cpp
    thesaurus_wrappers.cpp)
ENDIF (NOT ZORBA_NO_FULL_TEXT)

ADD_SRC_SUBFOLDER(API_SRCS serialization API_SERIALIZATION_SRCS)

SET(API_BUILD_SRCS
  ${CMAKE_CURRENT_BINARY_DIR}/api/version.cpp
  )

SET(AUDIT_HEADER_GENERATOR "${CMAKE_SOURCE_DIR}/src/api/auditprops_h.xq")
SET(AUDIT_CPP_GENERATOR    "${CMAKE_SOURCE_DIR}/src/api/auditprops_cpp.xq")
SET(AUDIT_HEADER           "${CMAKE_BINARY_DIR}/src/api/auditprops.h")
SET(AUDIT_CPP              "${CMAKE_BINARY_DIR}/src/api/auditprops.cpp")
SET(AUDIT_PROPS_SPEC       "${CMAKE_SOURCE_DIR}/src/api/audit.xml")

ZORBA_AUDIT_GENERATOR(
    ${AUDIT_CPP_GENERATOR}
    "auditspecfile:=${AUDIT_PROPS_SPEC}"
    ${AUDIT_PROPS_SPEC}
    ${AUDIT_CPP})

ZORBA_AUDIT_GENERATOR(
    ${AUDIT_HEADER_GENERATOR}
    "auditspecfile:=${AUDIT_PROPS_SPEC}"
    ${AUDIT_PROPS_SPEC}
    ${AUDIT_HEADER})

SET_SOURCE_FILES_PROPERTIES("${CMAKE_SOURCE_DIR}/src/api/auditimpl.cpp"
                              PROPERTIES OBJECT_DEPENDS
                              "${CMAKE_BINARY_DIR}/src/api/auditprops.cpp;${CMAKE_BINARY_DIR}/src/api/auditprops.h")
SET_SOURCE_FILES_PROPERTIES("${CMAKE_SOURCE_DIR}/src/api/auditimpl.h"
                              PROPERTIES OBJECT_DEPENDS
                              "${CMAKE_BINARY_DIR}/src/api/auditprops.h")
# vim:set et sw=2 ts=2:
