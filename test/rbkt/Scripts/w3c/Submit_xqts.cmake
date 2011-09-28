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
# Generate an XQTS test submission from a recent CTest run.

get_filename_component (cwd ${CMAKE_CURRENT_LIST_FILE} PATH)
if (ZORBA_BUILD_DIR)
  set (builddir "${ZORBA_BUILD_DIR}")
else ()
  set (builddir "${cwd}/../../../../build")
endif ()
find_program(zorba NAMES zorba zorba.exe PATHS "${builddir}" "${builddir}/release" PATH_SUFFIXES bin)
if (NOT zorba)
  message (FATAL_ERROR "Zorba is required; not found. Specify -DZORBA_BUILD_DIR to point to your build directory if necessary.")
endif ()

# Read most recent CTest tag
file (STRINGS "${builddir}/Testing/TAG" _tag_content)
list (GET _tag_content 0 ctest_tag)
set (testfile "${builddir}/Testing/${ctest_tag}/Test.xml")

# Execute Zorba
execute_process (COMMAND "${zorba}" --omit-xml-declaration --indent
                 --query "${cwd}/generate-submission-xqts.xq" --as-files
                 -e "ctests=${testfile}")
