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
  ADD_CUSTOM_COMMAND(OUTPUT "${OUTPUT}"
    COMMAND "${CMAKE_COMMAND}"
    "-Dsource_dir=\"${CMAKE_SOURCE_DIR}\""
    "-Dbinary_dir=\"${CMAKE_BINARY_DIR}\""
    "-Dzorba_exe=\"${ZORBA_EXE_SCRIPT}\"" 
    "-Dquery=\"${GEN_QUERY}\"" 
    "-Dgen_file=\"${OUTPUT}\""
    "-Dextvars:STRING=\"${EXTVARS}\""
    "-Dfiles:STRING=\"${SPEC_FILES}\""
    "-P" "${GEN_SCRIPT}"
    DEPENDS ${GEN_QUERY} ${ABSOLUTE_SPEC_FILES} ${EXTRA_DEPS})
ENDMACRO(ZORBA_RUNTIME_GENERATOR)
