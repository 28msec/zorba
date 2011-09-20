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

# This is the script that will be run to generate a file.
SET(GEN_SCRIPT "${CMAKE_SOURCE_DIR}/cmake_modules/GenZorbaRuntime.cmake")

# This macro adds a custom rule to generate a source file.
#
# Parameters:
#
#  GEN_QUERY: Full path to XQuery to run to generate source file. This
#    file will be a dependency for the generated file.
#
#  EXTVARS: semicolon-separated list of foo=bar or foo:=bar external
#    variable bindings.
#
#  SPEC_FILES: semicolon-separated list of spec files (relative to
#    src/runtime/spec). These will all be added as dependencies for
#    the generated file. The list will also be bound to the external
#    variable $files to the query as a comma-separated list.
#
# EXTRA_DEPS: semicolon-separated list of other files to add as
#    dependencies for the generated file.
#
# OUTPUT: Full path to output file (in binary directory).

MACRO(ZORBA_RUNTIME_GENERATOR GEN_QUERY EXTVARS SPEC_FILES EXTRA_DEPS OUTPUT)
  SET(ABSOLUTE_SPEC_FILES)
  FOREACH(SPEC_FILE ${SPEC_FILES})
    LIST(APPEND ABSOLUTE_SPEC_FILES "${SPEC_DIR}/${SPEC_FILE}")
  ENDFOREACH(SPEC_FILE)
  # CMake is annoyingly limited when it comes to lists. There's no way
  # (that I know of) to create a list where any item contains a
  # semicolon. Since some of our arguments contain semicolons, we
  # cannot create a variable to hold the arguments to CMake
  # here. Therefore, we must duplicate them. It is important for
  # testing purposes that the arguments to CMAKE_COMMAND in both
  # ADD_CUSTOM_COMMAND() and ADD_TEST() here be the same, except for
  # -Dtest_only.
  STRING(REPLACE " " "_" TEST_NAME "${OUTPUT}")
  ADD_CUSTOM_COMMAND(OUTPUT "${OUTPUT}"
    COMMAND "${CMAKE_COMMAND}"
    -D "source_dir=\"${CMAKE_SOURCE_DIR}\""
    -D "binary_dir=\"${CMAKE_BINARY_DIR}\""
    -D "ZORBA_EXE=\"${ZORBA_EXE}\"" 
    -D "query=\"${GEN_QUERY}\"" 
    -D "gen_file=\"${OUTPUT}\""
    -D "extvars:STRING=\"${EXTVARS}\""
    -D "files:STRING=\"${SPEC_FILES}\""
    -P "${GEN_SCRIPT}"
    MAIN_DEPENDENCY ${GEN_QUERY}
    DEPENDS ${ABSOLUTE_SPEC_FILES} ${EXTRA_DEPS}
    ${GEN_SCRIPT} ${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaRuntimeGenerator.cmake)
#MESSAGE(STATUS  "     ADD_CUSTOM_COMMAND(OUTPUT \"${OUTPUT}\" ")
#MESSAGE(STATUS  "       COMMAND \"${CMAKE_COMMAND}\" ")
#MESSAGE(STATUS  "       -D \"source_dir=${CMAKE_SOURCE_DIR}\" ")
#MESSAGE(STATUS  "       -D \"binary_dir=${CMAKE_BINARY_DIR}\" ")
#MESSAGE(STATUS  "       -D \"ZORBA_EXE=${ZORBA_EXE}\"  ")
#MESSAGE(STATUS  "       -D \"query=${GEN_QUERY}\"  ")
#MESSAGE(STATUS  "       -D \"gen_file=${OUTPUT}\" ")
#MESSAGE(STATUS  "       -D \"extvars:STRING=${EXTVARS}\" ")
#MESSAGE(STATUS  "       -D \"files:STRING=${SPEC_FILES}\" ")
#MESSAGE(STATUS  "       -P \"${GEN_SCRIPT}\" ")
#MESSAGE(STATUS  "       MAIN_DEPENDENCY ${GEN_QUERY} ")
#MESSAGE(STATUS  "       DEPENDS ${ABSOLUTE_SPEC_FILES} ${EXTRA_DEPS} ")
#MESSAGE(STATUS  "       ${GEN_SCRIPT} ${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaRuntimeGenerator.cmake) ")
#MESSAGE(STATUS  "***************************************************************************************** ")

ADD_TEST("RuntimeGeneratorTest-${TEST_NAME}" "${CMAKE_COMMAND}"
    -D "source_dir=${CMAKE_SOURCE_DIR}"
    -D "binary_dir=${CMAKE_BINARY_DIR}"
    -D "ZORBA_EXE=${ZORBA_EXE}"
    -D "query=${GEN_QUERY}" 
    -D "gen_file=${OUTPUT}"
    -D "extvars:STRING=${EXTVARS}"
    -D "files:STRING=${SPEC_FILES}"
    -D "test_only:BOOLEAN=TRUE"
    -P "${GEN_SCRIPT}")
ENDMACRO(ZORBA_RUNTIME_GENERATOR)

MACRO(ZORBA_DIAGNOSTIC_GENERATOR GEN_QUERY EXTVARS SPEC_FILES EXTRA_DEPS OUTPUT)
  SET(ABSOLUTE_SPEC_FILES)
  FOREACH(SPEC_FILE ${SPEC_FILES})
    LIST(APPEND ABSOLUTE_SPEC_FILES "${CMAKE_SOURCE_DIR}/src/diagnostics/${SPEC_FILE}")
  ENDFOREACH(SPEC_FILE)
  # CMake is annoyingly limited when it comes to lists. There's no way
  # (that I know of) to create a list where any item contains a
  # semicolon. Since some of our arguments contain semicolons, we
  # cannot create a variable to hold the arguments to CMake
  # here. Therefore, we must duplicate them. It is important for
  # testing purposes that the arguments to CMAKE_COMMAND in both
  # ADD_CUSTOM_COMMAND() and ADD_TEST() here be the same, except for
  # -Dtest_only.
  STRING(REPLACE " " "_" TEST_NAME "${OUTPUT}")
  ADD_CUSTOM_COMMAND(OUTPUT "${OUTPUT}"
    COMMAND "${CMAKE_COMMAND}"
    -D "source_dir=\"${CMAKE_SOURCE_DIR}\""
    -D "binary_dir=\"${CMAKE_BINARY_DIR}\""
    -D "ZORBA_EXE=\"${ZORBA_EXE}\"" 
    -D "query=\"${GEN_QUERY}\"" 
    -D "gen_file=\"${OUTPUT}\""
    -D "extvars:STRING=\"${EXTVARS}\""
    -D "files:STRING=\"${SPEC_FILES}\""
    -P "${GEN_SCRIPT}"
    MAIN_DEPENDENCY ${GEN_QUERY}
    DEPENDS ${ABSOLUTE_SPEC_FILES} ${EXTRA_DEPS}
    ${GEN_SCRIPT} ${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaRuntimeGenerator.cmake)
  ADD_TEST("RuntimeGeneratorTest-${TEST_NAME}" "${CMAKE_COMMAND}"
    -D "source_dir=${CMAKE_SOURCE_DIR}"
    -D "binary_dir=${CMAKE_BINARY_DIR}"
    -D "ZORBA_EXE=${ZORBA_EXE}"
    -D "query=${GEN_QUERY}" 
    -D "gen_file=${OUTPUT}"
    -D "extvars:STRING=${EXTVARS}"
    -D "files:STRING=${SPEC_FILES}"
    -D "test_only:BOOLEAN=TRUE"
    -P "${GEN_SCRIPT}")
ENDMACRO(ZORBA_DIAGNOSTIC_GENERATOR)
