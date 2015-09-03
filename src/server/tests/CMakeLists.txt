# Copyright 2015 Federico Cavalieri.
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

# collect all the test queries (.jq) in all subdirectories of the tests dir
FILE(GLOB_RECURSE TESTFILES FOLLOW_SYMLINKS 
     RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/tests" FOLLOW_SYMLINKS "*.jq")

# create a list of folders containing test files
LIST(SORT TESTFILES)
FOREACH(TESTFILE ${TESTFILES})
  GET_FILENAME_COMPONENT(TF_PATH ${TESTFILE} PATH)
  IF(NOT ("${PARAM}" STREQUAL "${TF_PATH}") AND NOT (".." STREQUAL "${TF_PATH}"))    
    LIST(APPEND TESTLIST ${TF_PATH})
  ENDIF(NOT ("${PARAM}" STREQUAL "${TF_PATH}") AND NOT (".." STREQUAL "${TF_PATH}"))
  SET(PARAM ${TF_PATH})
ENDFOREACH(TESTFILE)

# add tests
FOREACH(TEST ${TESTLIST})
  SET(TEST_NAME "server_${TEST}")
  ADD_TEST(${TEST_NAME} "${ZORBA_EXE}"
                        -f -q ${CMAKE_CURRENT_SOURCE_DIR}/test-runner.jq
                        -etest-configuration-file:=${CMAKE_CURRENT_BINARY_DIR}/test-configuration.json
                        -etest-name:=${TEST})
  MESSAGE(STATUS "Added test: ${TEST}")  
ENDFOREACH(TEST)

# copy test configuration
CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/test-configuration.json.in
    ${CMAKE_CURRENT_BINARY_DIR}/test-configuration.json
    @ONLY
  )