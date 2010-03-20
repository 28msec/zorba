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
#      commit = set to "no" to prevent remote queue from committing changes
#               (default "yes")


# We'll need Subversion.
find_program(SVN_EXECUTABLE svn
  DOC "subversion command line client")
if(NOT SVN_EXECUTABLE)
  message (FATAL_ERROR "Subversion is required; not found")
endif(NOT SVN_EXECUTABLE)
set (svn "${SVN_EXECUTABLE}")

# SVN path for submissions
set (svn_path "svn://zorbatest.lambda.nu/zorbatest/remotequeue")

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

# Package up local changes
include ("${cwd}/SvnPackage.cmake")
svn_package ("${srcdir}" "${CMAKE_ZORBA_BUILD_DIR}/remotequeue"
             "${changelist}" changefile)

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
