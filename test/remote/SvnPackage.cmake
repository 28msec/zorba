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
# Utility routines to package a local SVN working copy's changes into
# a single file, and for applying that file to a fresh SVN enlistment
# elsewhere.


MACRO (find_prereqs)
  # Definitely need svn here.
  FIND_PROGRAM(SVN_EXECUTABLE svn
  DOC "subversion command line client")
  IF(NOT SVN_EXECUTABLE)
    message (FATAL_ERROR "Subversion is required; not found")
  ENDIF(NOT SVN_EXECUTABLE)
  set (svn "${SVN_EXECUTABLE}")

  # create path to execute zorba
  IF (WIN32)
    SET(ZORBA_EXE_SCRIPT "${ZORBA_BUILD_DIR}/scripts/zorba_cmake.bat")
  ELSE (WIN32)
    SET(ZORBA_EXE_SCRIPT "${ZORBA_BUILD_DIR}/bin/zorba")
  ENDIF (WIN32)
  if (NOT EXISTS ${ZORBA_EXE_SCRIPT})
    message (FATAL_ERROR "Zorba is required; not found. Specify -DZORBA_BUILD_DIR to point to your build directory if necessary. (${ZORBA_EXE_SCRIPT})")
  endif (NOT EXISTS ${ZORBA_EXE_SCRIPT})
  execute_process (COMMAND "${ZORBA_EXE_SCRIPT}" --omit-xml-declaration
    --query "1+1" OUTPUT_VARIABLE ignored RESULT_VARIABLE result)
  if (result)
    message (FATAL_ERROR "Zorba is not functional. Specify -DZORBA_BUILD_DIR to point to your build directory if necessary. (${ZORBA_EXE_SCRIPT})")
  endif (result)
ENDMACRO (find_prereqs)


# Utility routine: given svn-status.xml file and a changelist (may be
# ""), return a list of files which match any specified status.
MACRO (get_files_with_status filelist svnstatusxml changelist)
  # Which element to look at?
  if ("${changelist}" STREQUAL "")
    set (elem "target")
  else ("${changelist}" STREQUAL "")
    set (elem "changelist[@name=\"${changelist}\"]")
  endif ("${changelist}" STREQUAL "")

  # Which statuses to look at?
  set (whereclause "")
  set (prefix "where")
  foreach (status ${ARGN})
    set (whereclause "${whereclause}${prefix} $status eq \"${status}\"")
    set (prefix " or")
  endforeach (status ${ARGN})
  
  # BUG: if the query below has new lines you will get a Zorba syntax error on Windows
  set (query "fn:string-join(for $entry in status/${elem}/entry let $status := data($entry/wc-status/@item) ${whereclause} return $entry/@path, ';')")
  # Set "filelist" to result
  execute_process (COMMAND "${ZORBA_EXE_SCRIPT}" --omit-xml-declaration
                   --query "${query}" --context-item "${svnstatusxml}"
                   OUTPUT_VARIABLE "${filelist}")
ENDMACRO (get_files_with_status)


# Args:
#   srcdir: root of local SVN working copy with changes to package
#   outdir: directory to place resulting changes.tgz (will also hold temp files)
#   changelist: svn changelist to package (may be "" to package all changes)
#   resultfile: Variable to store resulting filename in
macro (svn_package srcdir outdir changelist resultfile)
  find_prereqs ()

  # Start by making our working directory
  set (chgdir "${outdir}/changes")
  file (MAKE_DIRECTORY "${chgdir}")

  # Write out the "svn info" and "svn status" information
  execute_process (COMMAND "${svn}" --xml info "${srcdir}"
                   OUTPUT_FILE "${chgdir}/svn-info.xml")
  execute_process (COMMAND "${svn}" --xml status "${srcdir}"
                   OUTPUT_FILE "${chgdir}/svn-status.xml")

  # Also save the named of the changelist for the remote queue to use
  file (WRITE "${chgdir}/changelist" "${changelist}")

  # Pick out path names for added and modified files in the specified
  # changelist, or from the default changelist (<target> element) if
  # no changelist specified
  get_files_with_status (copyfiles "${chgdir}/svn-status.xml" "${changelist}"
                         added modified)

  # Copy each modified or added file to a corresponding place in the
  # directory hierarchy of the changes directory. Skip directories.
  file (MAKE_DIRECTORY "${chgdir}/files")
  foreach (filepath ${copyfiles})
    if (NOT IS_DIRECTORY "${filepath}")
      message ("Copying ${filepath}..")
      file (TO_CMAKE_PATH "${filepath}" filepath)
      file (RELATIVE_PATH relpath "${srcdir}" "${filepath}")
      get_filename_component (reldir "${relpath}" PATH)
      file (MAKE_DIRECTORY "${chgdir}/files/${reldir}")
      execute_process (COMMAND "${CMAKE_COMMAND}" -E copy
                       "${filepath}" "${chgdir}/files/${reldir}")
    endif (NOT IS_DIRECTORY "${filepath}")
  endforeach (filepath)

  # Package up for delivery to remote queue - name the archive after
  # the current time to ensure first-come, first-serve and prevent
  # collisions
  execute_process (COMMAND "${ZORBA_EXE_SCRIPT}" --omit-xml-declaration
                   --query "fn:adjust-dateTime-to-timezone(fn:current-dateTime(), xs:dayTimeDuration(\"PT0H\"))"
                   OUTPUT_VARIABLE datetime)
  string (REPLACE ":" "-" datetime "${datetime}")
  set (changefile "changes-${datetime}.tgz")
  execute_process (COMMAND "${CMAKE_COMMAND}" -E tar czf
                   "${outdir}/${changefile}" "changes"
                   WORKING_DIRECTORY "${outdir}")
  set (${resultfile} "${changefile}")
  file (REMOVE_RECURSE "${chgdir}")
endmacro (svn_package)


# Args:
#   changefile - a changes.tgz file from package_svn
#   svndir - directory to check out SVN into and apply changes
#   tmpdir - directory to temporarily unpack changefile into
#   svnlogfile - file to output SVN checkout messages into
#   changeslogfile - file to output change-application log messages into
#   result_var - if the variable named by "result" is non-zero or contains a
#     message after svn_unpackage() returns, an error was encountered
function (svn_unpackage changefile svndir tmpdir svnlogfile changeslogfile
    result_var)
  find_prereqs ()

  # Unpack changes.tgz into working dir
  execute_process (COMMAND "${CMAKE_COMMAND}" -E tar xzf "${changefile}"
                   WORKING_DIRECTORY "${tmpdir}")
  set (chgdir "${tmpdir}/changes")

  # De-Windows all text files - this also is currently Linux-specific
  # and depends on "dos2unix" existing.
  file (GLOB_RECURSE textfiles
        "${chgdir}/*.c" "${chgdir}/*.cpp" "${chgdir}/*.cxx"
        "${chgdir}/*.h" "${chgdir}/*.hpp" "${chgdir}/*.hxx"
        "${chgdir}/*.txt" "${chgdir}/*.cmake" "${chgdir}/*.conf"
        "${chgdir}/*.xml" "${chgdir}/*.xq" "${chgdir}/*.txt"
        "${chgdir}/*.res" "${chgdir}/*.spec" "${chgdir}/*.xqlib")
  foreach (textfile ${textfiles})
    execute_process (COMMAND dos2unix -k "${textfile}")
  endforeach (textfile)

  # Checkout/update svn from specified URL and rev
  execute_process (COMMAND "${ZORBA_EXE_SCRIPT}" --omit-xml-declaration
                   --query "data(info/entry/url)"
                   --context-item "${chgdir}/svn-info.xml"
                   OUTPUT_VARIABLE svnroot)
  execute_process (COMMAND "${ZORBA_EXE_SCRIPT}" --omit-xml-declaration
                   --query "data(info/entry/@revision)"
                   --context-item "${chgdir}/svn-info.xml"
                   OUTPUT_VARIABLE svnrev)
  execute_process (COMMAND "${svn}" checkout
                   -r "${svnrev}" "${svnroot}" "${svndir}"
                   OUTPUT_FILE "${svnlogfile}" ERROR_FILE "${svnlogfile}")

  # Copy modified/added files on top of svn directory
  file (WRITE "${changeslogfile}" "Copying added/modified files...\n")
  execute_process (COMMAND "${CMAKE_COMMAND}" -E copy_directory
                   "${chgdir}/files" "${svndir}")

  # Modified files are already all set. Process svn-status.xml to
  # delete any files which were deleted on client's svn, as named in
  # the client's changelist.
  file (READ "${chgdir}/changelist" changelist)
  get_files_with_status (deletefiles
                         "${chgdir}/svn-status.xml" "${changelist}" deleted)
  execute_process (COMMAND "${ZORBA_EXE_SCRIPT}" --omit-xml-declaration
                   --query "data(info/entry/@path)"
                   --context-item "${chgdir}/svn-info.xml"
                   OUTPUT_VARIABLE clientroot)
  # clientroot and the filepaths below are absolute paths from the
  # client, which might be Windows-style paths with drive letters. The
  # following is a horrific hack which lets us get the remote path
  # component no matter which platform they came from. (Note: This
  # only works on Linux, which is the platform the remote queue runs
  # on. If we ever have a Windows remote queue machine, this will
  # die.)
  # 1. Stick a leading / on them, so Linux thinks they're absolute.
  # 2. Convert to "CMake paths", which have forward-slashes.
  # 3. Do relative_path as normal.
  file (TO_CMAKE_PATH "/${clientroot}" clientroot)
  foreach (filepath ${deletefiles})
    file (TO_CMAKE_PATH "/${filepath}" filepath)
    file (RELATIVE_PATH relpath "${clientroot}" "${filepath}")
    execute_process (COMMAND "${svn}" delete "${svndir}/${relpath}"
      OUTPUT_VARIABLE output ERROR_VARIABLE output RESULT_VARIABLE result)
    file (APPEND "${changeslogfile}" "${output}")
    if (result)
      set (${result_var} ${result} PARENT_SCOPE)
      return ()
    endif ()
  endforeach (filepath ${deletefiles})

  # Now add any new files, using the local output of "svn status" to
  # find "unversioned" files.  (We could read the svn-status.xml from
  # the changes file, but when it is based on a changelist, it won't
  # include directories to add.)
  execute_process (COMMAND "${svn}" --xml status "${svndir}"
                   OUTPUT_FILE "${chgdir}/svn-status.xml")
  get_files_with_status (addfiles "${chgdir}/svn-status.xml" "" unversioned)
  foreach (filepath ${addfiles})
    execute_process (COMMAND "${svn}" add "${filepath}"
      OUTPUT_VARIABLE output ERROR_VARIABLE output RESULT_VARIABLE result)
    file (APPEND "${changeslogfile}" "${output}")
    if (result)
      set (${result_var} ${result} PARENT_SCOPE)
      return ()
    endif ()
  endforeach (filepath ${addfiles})

  # Remove temporary unpackaged workingset
  file (REMOVE_RECURSE "${chgdir}")

endfunction (svn_unpackage)
