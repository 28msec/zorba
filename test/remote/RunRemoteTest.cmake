# This script will queue your local working set of changes for
# execution on the remote testing queue.
#
# Usage:  cmake -Dopt=value -P RunRemoteTest.cmake
#   Be sure all -D options come before -P !
#   Valid options:
#      logmsg = checkin log message string
#      logmsgfile = file containing checking log message
#      ZORBA_BUILD_DIR = zorba build directory (defaults to src_dir/build)
#   Either logmsg or logmsgfile MUST be specified.


# We'll need Subversion.
find_package (Subversion)
if (NOT Subversion_FOUND)
  message (FATAL_ERROR "Subversion is required; not found")
endif ()
set (svn "${Subversion_SVN_EXECUTABLE}")

# QQQ Following macros copied from RemoteQueue.cmake in zorbatest repo;
# should combine

# Our current SVN path (to parent of trunk/).
set (svn_path "https://zorba.svn.sourceforge.net/svnroot/zorba")

# Sleep for N seconds
macro (sleep seconds)
  execute_process (COMMAND "${CMAKE_CTEST_COMMAND"
                   -S "${cwd}/Sleep.cmake,${seconds}")
endmacro ()

# Retrieve the value of a named remotequeue property from the svn repository.
# Sets the CMAKE variable of the same name to the value.
macro (get_queue_prop propname)
  execute_process (COMMAND
                   "${svn}" propget "remotequeue:${propname}"
                   --revprop -r 1 "${svn_path}"
                   OUTPUT_VARIABLE "${propname}"
                   OUTPUT_STRIP_TRAILING_WHITESPACE)
endmacro ()  

# Set the value of a named remotequeue property on the svn repository.
macro (set_queue_prop propname value)
  execute_process (COMMAND
                   "${svn}" propset "remotequeue:${propname}" "${value}"
                   --revprop -r 1 "${svn_path}"
                   OUTPUT_STRIP_TRAILING_WHITESPACE)
endmacro ()  

# Locks/unlocks access to a given remotequeue property.
macro (lock_or_unlock_queue_prop cmd propname)
  while (1)
    execute_process (COMMAND
                     "${svn}" ${cmd} "${svn_path}/remotequeue/locks/${propname}"
                     ERROR_VARIABLE stderr
                     OUTPUT_VARIABLE stdout)
    if (stderr)
      message ("Warning: error ${cmd}ing ${propname}; trying again in 5 seconds...")
      sleep (5)
    else ()
      message ("Successfully ${cmd}ed ${propname}")
      break ()
    endif ()
  endwhile (1)
endmacro ()

macro (lock_queue_prop propname)
  lock_or_unlock_queue_prop (lock ${propname})
endmacro ()

macro (unlock_queue_prop propname)
  lock_or_unlock_queue_prop (unlock ${propname})
endmacro ()

# Figure out what directory we're running in
get_filename_component (cwd ${CMAKE_CURRENT_LIST_FILE} PATH)

# We also want zorba itself (you HAVE built it, right?).
find_program(zorba NAMES zorba zorba.exe
             PATHS "${cwd}/../../build" "${ZORBA_BUILD_DIR}"
             PATH_SUFFIXES bin)
if (NOT zorba)
  message (FATAL_ERROR "Zorba is required; not found. Specify -DZORBA_BUILD_DIR to point to your build directory if necessary.")
endif ()

# Compute top of Zorba source tree
get_filename_component (srcdir "${cwd}/../.." ABSOLUTE)
message ("Zorba source dir: ${srcdir}")

# Ensure a check-in notice was provided
if (logmsg)
  # Specify log message on command line
  set (svn_log_opt "-m")
elseif (logmsgfile)
  if (NOT EXISTS "${logmsgfile}")
    message (FATAL_ERROR "Log message file ${logmsgfile} does not exist!")
  else ()
    # Specify log message from a file
    set (svn_log_opt "-F")
    set (logmsg "${logmsgfile}")
  endif ()
else ()
  message (FATAL_ERROR "No checkin notice provided! Specify with -Dlogmsg='log message' or -Dlogmsgfile=filename")
endif ()

# Lock and increment last_checkin property
lock_queue_prop (last_checkin)
get_queue_prop (last_checkin)
math (EXPR last_checkin "${last_checkin} + 1")

# While holding lock (to prevent two different checkins with the same
# ID), copy the local working repository to the remotequeue directory
# in the svn repository.  In future, we could pass data to the remote
# queue (such as test suites to run, etc.) with properties on the
# checkin.
message ("Submitting local changes as job ${last_checkin}...")
execute_process (COMMAND
                 "${svn}" copy "${srcdir}"
                 "${svn_path}/remotequeue/workingsets/${last_checkin}"
                 "${svn_log_opt}" "${logmsg}")

# Update and unlock last_checkin property
set_queue_prop (last_checkin "${last_checkin}")      
message ("Updated last_checkin to ${last_checkin}")
unlock_queue_prop (last_checkin)

message ("Test job ${last_checkin} submitted to remote queue.")
