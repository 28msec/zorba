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

# This script will either generate a source file from a spec XML file
# (if Zorba is available to process it), or copy a pre-generated
# version from svn.

# Arguments - all are required: 
#  query: Full path to .xq to execute for generation
#  extvars: List of external variables to bind (-e args to zorba)
#  files: List of files to bind to $files in query
#  gen_file: Full path to generated file (in binary dir)
#  ZORBA_EXE: Full path of ZORBA_EXE
#  binary_dir: Full path of CMAKE_BINARY_DIR
#  source_dir: Full path of CMAKE_SOURCE_DIR

# Optional arguments:
#  test_only: If true, we are testing the generation. Generate to a
#  temp location and fail if the generated file is different than the
#  pre-generated form. Note: gen_file must be provided as normal!


# Check if zorbacmd exists and works. We need the ZORBA_EXE and the
# file API for the generation of the runtime and codegen. Zorba will
# fail running the test query if the file API dll is not found in the
# correct location.
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
      "does not work properly and cannot generate the runtime source files. "
      "This will cause the repository version of these files to be used. "
      "(Output from Zorba test command: ${ZORBA_WORKS_OUTPUT}")
  ELSE (NOT ZORBA_WORKS_RES EQUAL 0)
    SET (ZORBA_WORKS TRUE)
  ENDIF (NOT ZORBA_WORKS_RES EQUAL 0)
ELSE (EXISTS ${ZORBA_EXE})
  SET (ZORBA_WORKS FALSE)
ENDIF (EXISTS ${ZORBA_EXE})

# Compute the relative path to the generated file
FILE(RELATIVE_PATH gen_relfile "${binary_dir}" "${gen_file}")
GET_FILENAME_COMPONENT(gen_relfiledir "${gen_relfile}" PATH)
GET_FILENAME_COMPONENT(gen_relfilename "${gen_relfile}" NAME)

# Compute path to pre-generated file.
SET(pregen_file "${source_dir}/${gen_relfiledir}/pregenerated/${gen_relfilename}")

# If we are testing the generation, overwrite gen_file with a dummy location.
IF(test_only)
  STRING(REGEX REPLACE "[/\\]" "_" gen_file "${gen_relfilename}")
  SET(gen_file "${binary_dir}/gen_test.tmp.${gen_file}")
  MESSAGE("  dobbbling: ${gen_file}")
ENDIF(test_only)


IF(ZORBA_WORKS)
  MESSAGE(STATUS "Generating: ${gen_file}")
  SET(extvarargs)
  FOREACH(extvar ${extvars})
    LIST(APPEND extvarargs "-e" "${extvar}")
  ENDFOREACH(extvar)
  IF(files)
    # Because semicolons in CMake arguments end up being lists, we
    # change the delimiter to a comma before passing to Zorba.
    STRING(REPLACE ";" "," files "${files}")
    LIST(APPEND extvarargs "-e" "files:=${files}")
  ENDIF(files)
  GET_FILENAME_COMPONENT(gen_file_dir "${gen_file}" PATH)
  FILE(MAKE_DIRECTORY "${gen_file_dir}")
  EXECUTE_PROCESS(COMMAND "${ZORBA_EXE}"
    -q "${query}"
    -f
    -o "${gen_file}"
    ${extvarargs}
    --serialize-text
    WORKING_DIRECTORY "${source_dir}/src/runtime/spec"
    RESULT_VARIABLE RESULT)
  IF(RESULT)
    # Zorba may have created an empty file first, which will mess up dependency checking
    FILE(REMOVE "${gen_file}")
    MESSAGE(FATAL_ERROR "Error during generation!")
  ENDIF(RESULT)

  IF(test_only)
    # Compare the resulting file with the existing pre-generated file.
    # This SHOULD be the same, because either:

    # A. Zorba existed before this bulid, in which case the
    # pre-generated files would have been generated and overwritten if
    # there were any spec file changes.

    # B. Zorba did not exist before thie build, in which case the
    # pre-generated files should match the results of generating now
    # as they should be in sync in svn with the spec files.

    # If they DON'T match, either somebody checked in a spec file that
    # is no longer in sync with the pre-generated source; or somebody
    # checked in something that affected the generation process
    # without performing a re-generation. In either case, we want this
    # test to fail!
    EXECUTE_PROCESS(COMMAND "${CMAKE_COMMAND}" "-E" "compare_files"
      "${pregen_file}" "${gen_file}" RESULT_VARIABLE COMPARE_RES)
    IF(COMPARE_RES)
      MESSAGE(FATAL_ERROR "Runtime generation produced different file! "
        "Result was: ${COMPARE_RES} for ${pregen_file}")
    ENDIF(COMPARE_RES)
  ELSE(test_only)
    # Overwrite the pregenerated file, so svn will pick it up.  Use
    # copy_if_different so we don't mess with the timestamps if there
    # was no difference.
    EXECUTE_PROCESS(COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
      "${gen_file}" "${pregen_file}")
  ENDIF(test_only)

ELSE(ZORBA_WORKS)

  IF(test_only)
    MESSAGE(FATAL_ERROR "Attempt to test runtime generation with "
      "non-functional or missing Zorba executable ${ZORBA_EXE}!")
  ELSE(test_only)
    MESSAGE(STATUS "Copying pregenerated file for ${gen_file}")
    EXECUTE_PROCESS(COMMAND "${CMAKE_COMMAND}" "-E" "copy"
      "${pregen_file}" "${gen_file}")
  ENDIF(test_only)

ENDIF(ZORBA_WORKS)

# Clean up testing file if we got this far
IF(test_only)
  FILE(REMOVE "${gen_file}")
ENDIF(test_only)
