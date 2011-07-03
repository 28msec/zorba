# Copyright 2006-2008 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License")
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

# Build and install any test modules.  (Parameters are scrambled about
# as a test for DECLARE_ZORBA_MODULE parsing them.)
DECLARE_ZORBA_MODULE(FILE "ver2.xq"
  URI "http://www.zorba-xquery.com/modules/ver" VERSION 2.3
  OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TEST_URI_PATH")
DECLARE_ZORBA_MODULE(URI "http://www.zorba-xquery.com/modules/ver" VERSION 1.4
  FILE "${CMAKE_CURRENT_SOURCE_DIR}/ver.xq"
  OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TEST_URI_PATH")

DECLARE_ZORBA_MODULE(URI "http://www.zorba-xquery.com/modules/bad-ver"
  FILE "bad-ver.xq" VERSION 1.4
  OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TEST_URI_PATH")

DECLARE_ZORBA_MODULE(URI "http://www.zorba-xquery.com/modules/A" VERSION 1.0
  FILE "module-A.xq"
  OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TEST_URI_PATH")
DECLARE_ZORBA_MODULE(URI "http://www.zorba-xquery.com/modules/B" VERSION 1.0
  FILE "${CMAKE_CURRENT_SOURCE_DIR}/module-B.xq"
  OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TEST_URI_PATH")

DECLARE_ZORBA_MODULE(URI "http://www.zorba-xquery.com/modules/ext"
  VERSION 2.0 FILE "ext2.xq"
  OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TEST_URI_PATH")
DECLARE_ZORBA_MODULE(URI "http://www.zorba-xquery.com/modules/ext"
  VERSION 1.0 FILE "ext.xq"
  OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TEST_URI_PATH")

ADD_SUBDIRECTORY(ourlib)

DECLARE_ZORBA_MODULE(URI "http://www.zorba-xquery.com/modules/link" VERSION 1.0
  LINK_LIBRARIES "ourlib" FILE "link.xq"
  OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TEST_URI_PATH")

DECLARE_ZORBA_SCHEMA(URI "http://www.zorba-xquery.com/modules/theschema"
  FILE "schema.xsd"
  OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TEST_URI_PATH")
DECLARE_ZORBA_MODULE(URI "http://www.zorba-xquery.com/modules/myschema"
  VERSION 1.0 FILE "schema.xq"
  OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TEST_URI_PATH")
