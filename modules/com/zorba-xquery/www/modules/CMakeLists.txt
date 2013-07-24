# Copyright 2006-2012 The FLWOR Foundation.
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
# cURL
#
SET (CURL_FOUND)
IF(ZORBA_SUPPRESS_CURL)
  MESSAGE(STATUS "ZORBA_SUPPRESS_CURL is true - not searching for cURL library")
ELSE(ZORBA_SUPPRESS_CURL)
  MESSAGE(STATUS "Looking for cURL")
  FIND_PACKAGE(CURL)

  IF(CURL_FOUND)
    MESSAGE(STATUS "Found cURL library -- " ${CURL_LIBRARIES})
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
    DECLARE_ZORBA_MODULE(FILE http-client-error.xq
      URI "http://expath.org/ns/error")
    DECLARE_ZORBA_SCHEMA(FILE http-client.xsd
      URI "http://expath.org/ns/http-client")
    DECLARE_ZORBA_MODULE(FILE http-client.xq VERSION 2.0
      URI "http://www.zorba-xquery.com/modules/http-client"
      LINK_LIBRARIES ${CURL_LIBRARIES})
    
    IF (WIN32) # Copy certificates for windows only
      IF (MSVC_IDE)
        SET(CACERT_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/../../../../../bin/${CMAKE_BUILD_TYPE}/cacert.pem")
      ELSE (MSVC_IDE)
        SET(CACERT_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/../../../../../bin/cacert.pem")       
      ENDIF (MSVC_IDE)
      CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/cacert.pem" ${CACERT_DESTINATION} COPYONLY)
      INSTALL(FILES ${CACERT_DESTINATION} DESTINATION bin)
    ENDIF (WIN32) 
    
  ELSE(CURL_FOUND)
    MESSAGE(STATUS "The cURL library was not found - http-client will not be built")
  ENDIF(CURL_FOUND)
ENDIF(ZORBA_SUPPRESS_CURL)
SET(ZORBA_HAVE_CURL ${CURL_FOUND} CACHE BOOL "Whether Zorba found cURL" FORCE)
MARK_AS_ADVANCED(ZORBA_HAVE_CURL)

DECLARE_ZORBA_SCHEMA(FILE xqdoc.xsd URI "http://www.xqdoc.org/1.0")
DECLARE_ZORBA_MODULE(FILE datetime.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/datetime")
DECLARE_ZORBA_MODULE(FILE fetch.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/fetch")
DECLARE_ZORBA_MODULE(FILE node-reference.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/node-reference")
DECLARE_ZORBA_MODULE(FILE reference.xq VERSION 1.0
  URI "http://www.zorba-xquery.com/modules/reference")
DECLARE_ZORBA_MODULE(FILE node.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/node")
DECLARE_ZORBA_MODULE(FILE item.xq VERSION 1.0
  URI "http://www.zorba-xquery.com/modules/item")
DECLARE_ZORBA_MODULE(FILE reflection.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/reflection")
DECLARE_ZORBA_MODULE(FILE schema.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/schema")
DECLARE_ZORBA_MODULE(FILE string.xq VERSION 2.1
  URI "http://www.zorba-xquery.com/modules/string")
DECLARE_ZORBA_MODULE(FILE uri.xq VERSION 1.0
  URI "http://www.zorba-xquery.com/modules/uri")
DECLARE_ZORBA_MODULE(FILE xqdoc.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc")
DECLARE_ZORBA_SCHEMA(FILE xqdoc-options.xsd 
  URI "http://www.zorba-xquery.com/modules/xqdoc-options") 

# Subdirectories
DECLARE_ZORBA_MODULE(FILE introspection/sctx.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/introspection/sctx")

DECLARE_ZORBA_MODULE(FILE store/data-structures/unordered-map.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map")
DECLARE_ZORBA_MODULE(FILE store/documents/dynamic.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/dynamic/documents")
DECLARE_ZORBA_MODULE(FILE store/dynamic/collections/ddl.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl")
DECLARE_ZORBA_MODULE(FILE store/dynamic/collections/dml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml")
DECLARE_ZORBA_MODULE(FILE store/dynamic/collections/w3c/ddl.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl")
DECLARE_ZORBA_MODULE(FILE store/dynamic/collections/w3c/dml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/dml")
DECLARE_ZORBA_MODULE(FILE store/static/collections/ddl.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/collections/ddl")
DECLARE_ZORBA_MODULE(FILE store/static/collections/dml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/collections/dml")
DECLARE_ZORBA_MODULE(FILE store/static/indexes/ddl.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/indexes/ddl")
DECLARE_ZORBA_MODULE(FILE store/static/indexes/dml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/indexes/dml")
DECLARE_ZORBA_MODULE(FILE store/static/integrity_constraints/ddl.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl")
DECLARE_ZORBA_MODULE(FILE store/static/integrity_constraints/dml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/dml")
DECLARE_ZORBA_MODULE(FILE xqdoc/batch.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc/batch")
DECLARE_ZORBA_MODULE(FILE xqdoc/html.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc/html")
DECLARE_ZORBA_MODULE(FILE xqdoc/menu.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc/menu")

# debugger client DBGP message handler module
IF (ZORBA_WITH_DEBUGGER)
  DECLARE_ZORBA_MODULE (FILE debugger/dbgp-message-handler.xq VERSION 1.0
    URI "http://www.zorba-xquery.com/modules/debugger/dbgp-message-handler")
ENDIF (ZORBA_WITH_DEBUGGER)
