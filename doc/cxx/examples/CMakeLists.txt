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
# create the testing file and list of tests

INCLUDE_DIRECTORIES(AFTER ${CMAKE_SOURCE_DIR}/src/)

SET(API_EXAMPLES
  simple.cpp
  sax2.cpp
  errors.cpp
  context.cpp
  serialization.cpp
  chaining.cpp
  external_functions.cpp
  xmldatamanager.cpp
  jsondatamanager.cpp
  uri_resolvers.cpp
  execution_plans.cpp
  item_handler.cpp
  callback.cpp
  binary.cpp
  module_import_check.cpp
  jsoniq.cpp
)

IF(ZORBA_WITH_DEBUGGER)
#  LIST(APPEND API_EXAMPLES debugger.cpp)
ENDIF(ZORBA_WITH_DEBUGGER)

CREATE_TEST_SOURCELIST(
  examples
  examples.cpp
  ${API_EXAMPLES}
)
 
# add the executable
ZORBA_GENERATE_EXE(examples "${examples}" "" "" "")

# remove the test driver source file
SET (TestsToRun ${examples})
REMOVE (TestsToRun examples.cpp)

STRING (LENGTH "${CMAKE_SOURCE_DIR}/" SOURCE_DIR_LENGTH)

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
  GET_FILENAME_COMPONENT(NAME_WITHOUT_EXT ${test} NAME_WE)
  SET(FULL_TEST_NAME "${CMAKE_CURRENT_SOURCE_DIR}/${test}")
  STRING(LENGTH ${FULL_TEST_NAME} FULL_TEST_NAME_LENGTH)
  MATH(EXPR TEST_NAME_LENGTH "${FULL_TEST_NAME_LENGTH}-${SOURCE_DIR_LENGTH}")
  
  STRING(SUBSTRING ${FULL_TEST_NAME} ${SOURCE_DIR_LENGTH} ${TEST_NAME_LENGTH} TName)
  MESSAGE(STATUS "Adding test for the C++ API's documentation: ${TName}")
  ZORBA_ADD_TEST(${TName} examples ${NAME_WITHOUT_EXT})
ENDFOREACH(test)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/Makefile.cmake ${CMAKE_CURRENT_BINARY_DIR}/Makefile.zorba)
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/Makefile.cmake ${CMAKE_CURRENT_BINARY_DIR}/Makefile.zorba") 

# install the examples
INSTALL(FILES ${API_EXAMPLES} ${CMAKE_CURRENT_BINARY_DIR}/examples.cpp
        COMPONENT "cxx_examples" 
        DESTINATION
        share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/cxx/examples)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/Makefile.zorba
        COMPONENT "cxx_examples" 
        DESTINATION
        share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/cxx/examples RENAME Makefile)
