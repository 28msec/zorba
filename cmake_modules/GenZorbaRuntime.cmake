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

file(RELATIVE_PATH gen_relfile "${binary_dir}" "${gen_file}")
get_filename_component(gen_relfiledir "${gen_relfile}" PATH)
get_filename_component(gen_relfilename "${gen_relfile}" NAME)
set(pregen_file
  "${source_dir}/${gen_relfiledir}/pregenerated/${gen_relfilename}")
if (ZORBA_WORKS)
  message(STATUS "Generating: ${gen_file}")
  set (extvarargs)
  foreach(extvar ${extvars})
    list(APPEND extvarargs "-e" "${extvar}")
  endforeach(extvar)
  if(files)
    # Convert all spec filepaths to relative. Necessary on Windows
    # because these will sometimes be passed to Zorba which in turn
    # passes them to fn:doc(), and "c:/foo/bar" isn't a valid URI.
    # Oddly, Zorba seems to evaluate paths relative to the query file,
    # so use that as that base.  Also, because semicolons in CMake
    # arguments end up being lists, we change the delimiter to a comma
    # before passing to Zorba.
    get_filename_component(query_dir "${query}" PATH)
    set(relfiles)
    foreach(file ${files})
      file(RELATIVE_PATH relfile "${query_dir}" "${file}")
      list(APPEND relfiles "${relfile}")
    endforeach(file)
    string(REPLACE ";" "," relfiles "${relfiles}")
    list(APPEND extvarargs "-e" "files:=${relfiles}")
  endif(files)
  execute_process(COMMAND "${zorba_exe}"
    "-q" "${query}" "-f" 
    "-o" "${gen_file}"
    ${extvarargs}
    "--serialize-text"
    RESULT_VARIABLE result)
  if(result)
    # Zorba may have created an empty file first, which will mess up
    # dependency checking
    file (REMOVE "${gen_file}")
    message(FATAL_ERROR "Error during generation!")
  endif(result)
  # Overwrite the pregenerated file as well, so svn will pick it up.
  execute_process(COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
    "${gen_file}" "${pregen_file}")
else (ZORBA_WORKS)
  message(STATUS "Copying pregenerated file for ${gen_file}")
  execute_process(COMMAND "${CMAKE_COMMAND}" "-E" "copy"
    "${pregen_file}" "${gen_file}")
endif (ZORBA_WORKS)
