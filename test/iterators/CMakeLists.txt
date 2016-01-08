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

# configure plan and profile test queries
CONFIGURE_FILE(plantest.xq.in ${CMAKE_CURRENT_BINARY_DIR}/plantest.xq)
CONFIGURE_FILE(profiletest.xq.in ${CMAKE_CURRENT_BINARY_DIR}/profiletest.xq)

MESSAGE (STATUS "Adding plan tests")
FILE (GLOB_RECURSE PLAN_TEST_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.plan.*)

MESSAGE (STATUS "Adding profile tests")
FILE (GLOB_RECURSE PROFILE_TEST_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.profile.*)

FOREACH (TESTFILE ${PLAN_TEST_FILES})
  ADD_TEST(
    "iterators/${TESTFILE}" 
    "${CMAKE_COMMAND}"
    -D "TESTFILE=${TESTFILE}"
    -D "CMAKE_ZORBA_BINARY_DIR=${CMAKE_BINARY_DIR}"
    -D "ZORBA_EXE=${ZORBA_EXE}"
    -D "CMAKE_ZORBA_SOURCE_DIR=${CMAKE_SOURCE_DIR}"    
    -P "${CMAKE_CURRENT_SOURCE_DIR}/planscript.cmake")
     
  SET_TESTS_PROPERTIES("iterators/${TESTFILE}" 
    PROPERTIES PASS_REGULAR_EXPRESSION "Passed! *")
ENDFOREACH(TESTFILE)

FOREACH (TESTFILE ${PROFILE_TEST_FILES})
  ADD_TEST(
    "iterators/${TESTFILE}" 
    "${CMAKE_COMMAND}"
    -D "TESTFILE=${TESTFILE}"    
    -D "CMAKE_ZORBA_BINARY_DIR=${CMAKE_BINARY_DIR}"
    -D "ZORBA_EXE=${ZORBA_EXE}"
    -D "CMAKE_ZORBA_SOURCE_DIR=${CMAKE_SOURCE_DIR}"
    -P "${CMAKE_CURRENT_SOURCE_DIR}/profilescript.cmake")
     
  SET_TESTS_PROPERTIES("iterators/${TESTFILE}" 
    PROPERTIES PASS_REGULAR_EXPRESSION "Passed! *")
ENDFOREACH(TESTFILE)

##
## LibXML2 failures
##
EXPECTED_FAILURE (iterators/zorba/flwor/flwor24.plan.xml libxml2)
EXPECTED_FAILURE (iterators/zorba/flwor/flwor25.plan.xml libxml2)
EXPECTED_FAILURE (iterators/zorba/flwor/flwor27.plan.xml libxml2)


# vim:set et sw=2 ts=2:
