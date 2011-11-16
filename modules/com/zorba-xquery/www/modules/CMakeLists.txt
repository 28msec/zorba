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
# cURL
#
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
  ELSE(CURL_FOUND)
    MESSAGE(STATUS "The cURL library was not found - http-client will not be built")
  ENDIF(CURL_FOUND)
ENDIF(ZORBA_SUPPRESS_CURL)

DECLARE_ZORBA_SCHEMA(FILE xqdoc.xsd URI "http://www.xqdoc.org/1.0")
DECLARE_ZORBA_MODULE(FILE datetime.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/datetime")
DECLARE_ZORBA_MODULE(FILE fetch.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/fetch")
DECLARE_ZORBA_MODULE(FILE math.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/math")
DECLARE_ZORBA_MODULE(FILE node-reference.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/node-reference")
DECLARE_ZORBA_MODULE(FILE node-position.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/node-position")
DECLARE_ZORBA_MODULE(FILE node.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/node")
DECLARE_ZORBA_MODULE(FILE project_xqdoc.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/project_xqdoc")
DECLARE_ZORBA_MODULE(FILE random.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/random")
DECLARE_ZORBA_MODULE(FILE reflection.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/reflection")
DECLARE_ZORBA_MODULE(FILE schema.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/schema")
DECLARE_ZORBA_MODULE(FILE string.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/string")
DECLARE_ZORBA_SCHEMA(FILE xml-options.xsd URI "http://www.zorba-xquery.com/modules/xml-options") 
DECLARE_ZORBA_MODULE(FILE xml.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xml")
DECLARE_ZORBA_MODULE(FILE xqdoc.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc")

# Subdirectories
DECLARE_ZORBA_MODULE(FILE converters/base64.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/converters/base64")
DECLARE_ZORBA_MODULE(FILE introspection/sctx.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/introspection/sctx")
DECLARE_ZORBA_MODULE(FILE xqdoc2xhtml/error.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc2xhtml/error")
DECLARE_ZORBA_MODULE(FILE xqdoc2xhtml/index.xq VERSION 2.0
  URI "http://www.zorba-xquery.com/modules/xqdoc2xhtml/")

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

# error and warning modules
DECLARE_ZORBA_MODULE (FILE pregenerated/errors.xq
  URI "http://www.zorba-xquery.com/errors"
)
DECLARE_ZORBA_MODULE (FILE pregenerated/warnings.xq
  URI "http://www.zorba-xquery.com/warnings"
)
