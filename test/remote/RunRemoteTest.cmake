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
# This script will queue your local working set of changes for
# execution on the remote testing queue.
#
# Usage:  cmake [ -Dopt=value ... ] -P RunRemoteTest.cmake
#   Be sure all -D options come before -P !
#   Valid options:
#      changelist = svn changelist to submit (defaults to default changelist)
#      ZORBA_BUILD_DIR = zorba build directory (defaults to src_dir/build)
#      message = the checkin message (defaults to opening user's editor)
#      commit = set to "no" to prevent remote queue from committing changes
#               (default "yes")


# SVN path for submissions
set (svn_path "http://zorbatest.lambda.nu:8080/svn/zorbatest/remotequeue")

# Figure out what directory we're running in
get_filename_component (cwd ${CMAKE_CURRENT_LIST_FILE} PATH)

# Compute top of Zorba source tree
get_filename_component (srcdir "${cwd}/../.." ABSOLUTE)
message (STATUS "Zorba source dir: ${srcdir}")

# Ensure build directory exists
if (NOT ZORBA_BUILD_DIR)
  set (ZORBA_BUILD_DIR "${srcdir}/build")
else (NOT ZORBA_BUILD_DIR)
  get_filename_component (ZORBA_BUILD_DIR_TEMP "${ZORBA_BUILD_DIR}" ABSOLUTE)
  set(ZORBA_BUILD_DIR "${ZORBA_BUILD_DIR_TEMP}")
endif (NOT ZORBA_BUILD_DIR)

file(TO_CMAKE_PATH "${ZORBA_BUILD_DIR}" CMAKE_ZORBA_BUILD_DIR)

if (NOT IS_DIRECTORY "${CMAKE_ZORBA_BUILD_DIR}")
  message (FATAL_ERROR "Build directory ${builddir} does not exist! Specify with -DZORBA_BUILD_DIR='build dir'")
endif (NOT IS_DIRECTORY "${CMAKE_ZORBA_BUILD_DIR}")

# Load utilities lib and find all required executables
include ("${cwd}/SvnPackage.cmake")
FIND_PREREQS ()

# Create a working directory named after the current time, to ensure
# first-come, first-serve and prevent collisions
execute_process (COMMAND "${ZORBA_EXE_SCRIPT}" --omit-xml-declaration
  --query "fn:adjust-dateTime-to-timezone(fn:current-dateTime(), xs:dayTimeDuration(\"PT0H\"))"
  OUTPUT_VARIABLE datetime)
string (REPLACE ":" "-" datetime "${datetime}")

# Package up local changes for Zorba
set (workdir "${CMAKE_ZORBA_BUILD_DIR}/remotequeue/changes-${datetime}")
svn_package ("${srcdir}" "${workdir}" "${changelist}" "${workdir}/zorba.tgz")

# Save the local "svn info" so the remote queue easily knows what branch
# we're working in
execute_process (COMMAND "${svn}" info --xml
  WORKING_DIRECTORY "${srcdir}" OUTPUT_FILE "${workdir}/zorba-info.xml")

# Extract ZORBA_MODULE_DIR. This seems like a kludgy approach, but
# unfortunately load_cache() can't be called in CMake scripts.
set (cache_regex "^ZORBA_MODULES_DIR:PATH=(.*)$")
file (STRINGS "${CMAKE_ZORBA_BUILD_DIR}/CMakeCache.txt" modules_dir_entry
  REGEX "${cache_regex}" LIMIT_COUNT 1)
if (modules_dir_entry MATCHES "${cache_regex}")
  set (modules_dir "${CMAKE_MATCH_1}")
endif (modules_dir_entry MATCHES "${cache_regex}")

# Package up local changes for all modules.
if (IS_DIRECTORY "${modules_dir}")
  set (mod_count 1)
  file (GLOB module_dirs "${modules_dir}/*")
  foreach (module_dir ${module_dirs})
    if (IS_DIRECTORY "${module_dir}")
      message (STATUS "Module ${mod_count}: ${module_dir}")
      svn_package ("${module_dir}" "${workdir}" "${changelist}"
        "${workdir}/module-${mod_count}.tgz")
      math (EXPR mod_count "${mod_count} + 1")
    endif (IS_DIRECTORY "${module_dir}")
  endforeach (module_dir)
endif (IS_DIRECTORY "${modules_dir}")

# Wrap up all packaged changes into single submission file.
set (changefile "${workdir}.tgz")
execute_process (COMMAND "${CMAKE_COMMAND}" -E tar czf "${changefile}" "."
  WORKING_DIRECTORY "${workdir}")
file (REMOVE_RECURSE "${workdir}")
get_filename_component (changefile "${changefile}" NAME)

# Testing option: Don't submit job at all if "packageonly" is set
if (packageonly)
  message (FATAL_ERROR "Not submitting job as requested!")
endif ()

# Copy the local changes to the remotequeue svn repository.  In
# future, we could pass data to the remote queue (such as test suites
# to run, etc.) with properties on the checkin. For now at least, if
# the "commit" argument is "no", then use a special checkin message to
# instruct the remote queue not to commit the job to svn. (Doing it
# this way also prevents this script for prompting for a checkin
# message, which is useful.)
message ("Submitting job ${changefile}....")
if (commit STREQUAL "no")
  set (commitargs -m "DO NOT COMMIT")
elseif (message)
  set (commitargs -m "${message}")
endif (commit STREQUAL "no")
execute_process (COMMAND
                 "${svn}" import ${commitargs}
                 "${CMAKE_ZORBA_BUILD_DIR}/remotequeue/${changefile}"
                 "${svn_path}/workingsets/${changefile}"
                 TIMEOUT 300 RESULT_VARIABLE result)

if (NOT result STREQUAL 0)
  message ("Job failed to submit!")
else (NOT result STREQUAL 0)
  message ("\nJob ${changefile} submitted to remote queue.")
  message ("You may follow the progress of this job at:")
  string (REGEX REPLACE "changes-(.*)\\.tgz" "\\1" changefile "${changefile}")
  message ("\n  http://zorbatest.lambda.nu:8080/remotequeue/${changefile}/log.html\n")
endif (NOT result STREQUAL 0)
