# This script will queue your local working set of changes for
# execution on the remote testing queue.
#
# Usage:  cmake [ -Dopt=value ... ] -P RunRemoteTest.cmake
#   Be sure all -D options come before -P !
#   Valid options:
#      changelist = svn changelist to submit (defaults to default changelist)
#      ZORBA_BUILD_DIR = zorba build directory (defaults to src_dir/build)


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
endif (NOT ZORBA_BUILD_DIR)
if (NOT IS_DIRECTORY "${ZORBA_BUILD_DIR}")
  message (FATAL_ERROR "Build directory ${builddir} does not exist! Specify with -DZORBA_BUILD_DIR='build dir'")
endif (NOT IS_DIRECTORY "${ZORBA_BUILD_DIR}")

# Package up local changes
include ("${cwd}/SvnPackage.cmake")
svn_package ("${srcdir}" "${ZORBA_BUILD_DIR}/remotequeue"
             "${changelist}" changefile)

# Copy the local changes to the remotequeue svn repository.  In
# future, we could pass data to the remote queue (such as test suites
# to run, etc.) with properties on the checkin.
message ("Submitting job ${changefile}....")
execute_process (COMMAND
                 "${svn}" import "${ZORBA_BUILD_DIR}/remotequeue/${changefile}"
                 "${svn_path}/workingsets/${changefile}"
                 TIMEOUT 300 RESULT_VARIABLE result)

if (NOT result STREQUAL 0)
  message ("Job failed to submit!")
else (NOT result STREQUAL 0)
  message ("Job ${changefile} submitted to remote queue.")
endif (NOT result STREQUAL 0)
