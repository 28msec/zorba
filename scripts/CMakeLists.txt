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

IF (NOT WIN32)

  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/create-doc-tar.sh.in ${CMAKE_CURRENT_BINARY_DIR}/create-doc-tar.sh)
  MESSAGE (STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/create-doc-tar.sh.in -> ${CMAKE_CURRENT_BINARY_DIR}/create-doc-tar.sh") 

ENDIF(NOT WIN32)


CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/notice-generator.xq.in"
  "${CMAKE_CURRENT_BINARY_DIR}/notice-generator.xq"
)

SET (ZORBA_WORKS)
IF (EXISTS ${ZORBA_EXE})
  EXECUTE_PROCESS (
    COMMAND
      ${ZORBA_EXE}
      -q "import module namespace file = 'http://expath.org/ns/file'; file:exists( 'a non existant file' )"
    RESULT_VARIABLE ZORBA_WORKS_RES
    OUTPUT_VARIABLE ZORBA_WORKS_OUTPUT
  )
  IF (NOT ZORBA_WORKS_RES EQUAL 0)
    SET (ZORBA_WORKS FALSE)
    MESSAGE (STATUS "[WARNING] Zorba Command Line Utility at \"${ZORBA_EXE}\ "
      "does not work properly and cannot generate the NOTICE.txt file. "
      "(Output from Zorba test command: ${ZORBA_WORKS_OUTPUT}")
  ELSE (NOT ZORBA_WORKS_RES EQUAL 0)
    SET (ZORBA_WORKS TRUE)
  ENDIF (NOT ZORBA_WORKS_RES EQUAL 0)
ELSE (EXISTS ${ZORBA_EXE})
  SET (ZORBA_WORKS FALSE)
ENDIF (EXISTS ${ZORBA_EXE})

IF(ZORBA_WORKS)
  ADD_CUSTOM_COMMAND(OUTPUT "${CMAKE_SOURCE_DIR}/NOTICE.txt"
    COMMAND "${ZORBA_EXE}" "-q" "${CMAKE_CURRENT_BINARY_DIR}/notice-generator.xq" "-f" "--omit-xml-declaration"
    MAIN_DEPENDENCY "${CMAKE_CURRENT_BINARY_DIR}/notice-generator.xq" 
    DEPENDS "${CMAKE_SOURCE_DIR}/NOTICE.xml")

  ADD_CUSTOM_TARGET(NOTICE ALL
    DEPENDS "${CMAKE_SOURCE_DIR}/NOTICE.txt"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
ENDIF(ZORBA_WORKS)
