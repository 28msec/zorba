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

INCLUDE_DIRECTORIES(AFTER ${CMAKE_SOURCE_DIR}/src/)


SET (CAPI_EXAMPLES
	csimple.c
  ccontext.c
  cdatamanager.c
  cerror.c
  cexternal_functions.c 
  cserialization.c
)

CREATE_TEST_SOURCELIST(cexamples
	cexamples.c
  ${CAPI_EXAMPLES}
)
 
# add the executable
ADD_EXECUTABLE(cexamples ${cexamples})
TARGET_LINK_LIBRARIES(cexamples zorba simplestore)

# remove the test driver source file
SET (TestsToRun ${cexamples})
REMOVE (TestsToRun cexamples.c)

STRING (LENGTH "${CMAKE_SOURCE_DIR}/" SOURCE_DIR_LENGTH)

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
	GET_FILENAME_COMPONENT(NAME_WITHOUT_EXT ${test} NAME_WE)
  SET(FULL_TEST_NAME "${CMAKE_CURRENT_SOURCE_DIR}/${test}")
  STRING(LENGTH ${FULL_TEST_NAME} FULL_TEST_NAME_LENGTH)
  MATH(EXPR TEST_NAME_LENGTH "${FULL_TEST_NAME_LENGTH}-${SOURCE_DIR_LENGTH}")
  
  STRING(SUBSTRING ${FULL_TEST_NAME} ${SOURCE_DIR_LENGTH} ${TEST_NAME_LENGTH} TName)
	MESSAGE(STATUS "Adding test for the C API's documentation: ${TName}")
	ADD_TEST(${TName} cexamples ${NAME_WITHOUT_EXT})
ENDFOREACH(test)

INSTALL(FILES ${CAPI_EXAMPLES} ${CMAKE_CURRENT_BINARY_DIR}/cexamples.c
        DESTINATION
        share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/c/examples)
