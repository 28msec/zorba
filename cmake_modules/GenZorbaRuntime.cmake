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
#  zorba_exe: Full path of ZORBA_EXE_SCRIPT
#  binary_dir: Full path of CMAKE_BINARY_DIR
#  source_dir: Full path of CMAKE_SOURCE_DIR

# Optional arguments:
#  test_only: If true, we are testing the generation. Generate to a
#  temp location and fail if the generated file is different than the
#  pre-generated form. Note: gen_file must be provided as normal!


# Check if zorbacmd exists and works. We need the zorba_exe and the
# file API for the generation of the runtime and codegen. Zorba will
# fail running the test query if the file API dll is not found in the
# correct location.
set(ZORBA_WORKS)
if (EXISTS ${zorba_exe})
  execute_process(COMMAND ${zorba_exe}
    "-q" "import module namespace file = 'http://www.zorba-xquery.com/modules/file'; file:exists( 'a non existant file' )"
    RESULT_VARIABLE ZORBA_WORKS_RES
    OUTPUT_VARIABLE ZORBA_WORKS_OUTPUT)
  if (NOT ZORBA_WORKS_RES EQUAL 0)
    set(ZORBA_WORKS FALSE)
    message(STATUS "[WARNING] Zorba Command Line Utility at \"${zorba_exe}\ "
      "does not work properly and cannot generate the runtime source files. "
      "This will cause the repository version of thiese files to be used."
      "(Output from Zorba test command: ${ZORBA_WORKS_OUTPUT}")
  else (NOT ZORBA_WORKS_RES EQUAL 0)
    set(ZORBA_WORKS TRUE)
  endif (NOT ZORBA_WORKS_RES EQUAL 0)
else (EXISTS ${zorba_exe})
  set(ZORBA_WORKS FALSE)
endif (EXISTS ${zorba_exe})

# Compute the relative path to the generated file
file(RELATIVE_PATH gen_relfile "${binary_dir}" "${gen_file}")
get_filename_component(gen_relfiledir "${gen_relfile}" PATH)
get_filename_component(gen_relfilename "${gen_relfile}" NAME)

# Compute path to pre-generated file.
set(pregen_file
  "${source_dir}/${gen_relfiledir}/pregenerated/${gen_relfilename}")

# If we are testing the generation, overwrite gen_file with a dummy
# location.
if (test_only)
  set (gen_file "${binary_dir}/gen_test.tmp")
endif (test_only)


if (ZORBA_WORKS)

  message(STATUS "Generating: ${gen_file}")
  set (extvarargs)
  foreach(extvar ${extvars})
    list(APPEND extvarargs "-e" "${extvar}")
  endforeach(extvar)
  if(files)
    # Because semicolons in CMake arguments end up being lists, we
    # change the delimiter to a comma before passing to Zorba.
    string(REPLACE ";" "," files "${files}")
    list(APPEND extvarargs "-e" "files:=${files}")
  endif(files)
  execute_process(COMMAND "${zorba_exe}"
    "-q" "${query}" "-f" 
    "-o" "${gen_file}"
    ${extvarargs}
    "--serialize-text"
    WORKING_DIRECTORY "${source_dir}/src/runtime/spec"
    RESULT_VARIABLE result)
  if(result)
    # Zorba may have created an empty file first, which will mess up
    # dependency checking
    file (REMOVE "${gen_file}")
    message(FATAL_ERROR "Error during generation!")
  endif(result)

  if (test_only)
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
    execute_process(COMMAND "${CMAKE_COMMAND}" "-E" "compare_files"
      "${pregen_file}" "${gen_file}" RESULT_VARIABLE compare_res)
    if (compare_res)
      message (FATAL_ERROR "Runtime generation produced different file! "
        "Result was: ${compare_res} for ${pregen_file}")
    endif (compare_res)
  else (test_only)
    # Overwrite the pregenerated file, so svn will pick it up.  Use
    # copy_if_different so we don't mess with the timestamps if there
    # was no difference.
    execute_process(COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
      "${gen_file}" "${pregen_file}")
  endif (test_only)

else (ZORBA_WORKS)

  if (test_only)
    message(FATAL_ERROR "Attempt to test runtime generation with "
      "non-functional or missing Zorba executable ${zorba_exe}!")
  else (test_only)
    message(STATUS "Copying pregenerated file for ${gen_file}")
    execute_process(COMMAND "${CMAKE_COMMAND}" "-E" "copy"
      "${pregen_file}" "${gen_file}")
  endif (test_only)

endif (ZORBA_WORKS)

# Clean up testing file if we got this far
if (test_only)
  file (REMOVE "${gen_file}")
endif (test_only)
