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


MACRO (FIND_PREREQS)
  # Definitely need svn here.
  FIND_PROGRAM(SVN_EXECUTABLE svn DOC "subversion command line client")
  IF(NOT SVN_EXECUTABLE)
    MESSAGE (FATAL_ERROR "Subversion is required; not found")
  ENDIF(NOT SVN_EXECUTABLE)
  SET (svn "${SVN_EXECUTABLE}")

  # create path to execute zorba
  SET(ZORBA_EXE "${ZORBA_BUILD_DIR}/bin/zorba")
  IF (WIN32)
    SET(ZORBA_EXE "${ZORBA_EXE}.bat")
  ENDIF (WIN32)
  IF (NOT EXISTS ${ZORBA_EXE})
    MESSAGE (FATAL_ERROR "Zorba is required; not found. Specify -DZORBA_BUILD_DIR to point to your build directory if necessary. (${ZORBA_EXE})")
  ENDIF (NOT EXISTS ${ZORBA_EXE})
  EXECUTE_PROCESS (COMMAND "${ZORBA_EXE}" --omit-xml-declaration
    --query "1+1" OUTPUT_VARIABLE ignored RESULT_VARIABLE result)
  IF (result)
    MESSAGE (FATAL_ERROR "Zorba is not functional. Specify -DZORBA_BUILD_DIR to point to your build directory if necessary. (${ZORBA_EXE})")
  ENDIF (result)
ENDMACRO (FIND_PREREQS)


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
  execute_process (COMMAND "${ZORBA_EXE}" --omit-xml-declaration
                   --query "${query}" --context-item "${svnstatusxml}"
                   OUTPUT_VARIABLE "${filelist}")
ENDMACRO (get_files_with_status)


# Args:
#   srcdir: root of local SVN working copy with changes to package
#   tmpdir: directory to hold temp files
#   changelist: svn changelist to package (may be "" to package all changes)
#   resultfile: Full path to changes.tgz file to create
#
# Note that this function will NOT create any output file if there are no
# svn changes in the given srcdir.
macro (svn_package srcdir tmpdir changelist resultfile)
  find_prereqs ()

  # Canonicalize srcdir
  get_filename_component (abssrcdir "${srcdir}" ABSOLUTE)

  # Start by making our working directory
  set (chgdir "${tmpdir}/changes")
  file (MAKE_DIRECTORY "${chgdir}")

  # Write out the "svn info" and "svn status" information
  execute_process (COMMAND "${svn}" --xml info "${abssrcdir}"
                   OUTPUT_FILE "${chgdir}/svn-info.xml")
  execute_process (COMMAND "${svn}" --xml status "${abssrcdir}"
                   OUTPUT_FILE "${chgdir}/svn-status.xml")

  # Also save the named of the changelist for the remote queue to use
  file (WRITE "${chgdir}/changelist" "${changelist}")

  # Check to see whether there are any changes to package
  get_files_with_status (chgfiles "${chgdir}/svn-status.xml" "${changelist}"
    added modified deleted)
  if (chgfiles)
    # Pick out path names for added and modified files in the
    # specified changelist, or from the default changelist (<target>
    # element) if no changelist specified
    get_files_with_status (copyfiles "${chgdir}/svn-status.xml" "${changelist}"
      added modified)

    # Copy each modified or added file to a corresponding place in the
    # directory hierarchy of the changes directory. Skip directories.
    file (MAKE_DIRECTORY "${chgdir}/files")
    foreach (filepath ${copyfiles})
      if (NOT IS_DIRECTORY "${filepath}")
        file (TO_CMAKE_PATH "${filepath}" filepath)
        file (RELATIVE_PATH relpath "${abssrcdir}" "${filepath}")
        get_filename_component (reldir "${relpath}" PATH)
        file (MAKE_DIRECTORY "${chgdir}/files/${reldir}")
        message ("Copying ${filepath} to ${chgdir}/files/${reldir}..")
        execute_process (COMMAND "${CMAKE_COMMAND}" -E copy
          "${filepath}" "${chgdir}/files/${reldir}")
      endif (NOT IS_DIRECTORY "${filepath}")
    endforeach (filepath)

    # Package up changes/ directory
    execute_process (COMMAND "${CMAKE_COMMAND}" -E tar czf
      "${resultfile}" "changes"
      WORKING_DIRECTORY "${tmpdir}")
  endif (chgfiles)
  file (REMOVE_RECURSE "${chgdir}")
endmacro (svn_package)


# Args:
#   changefile - a changes.tgz file from package_svn
#   outdir - directory to check out SVN into and apply changes - see below
#   tmpdir - directory to temporarily unpack changefile into
#   logfile - file to append log messages into
#   result_var - if the variable named by "result_var" is non-zero or contains
#     a message after svn_unpackage() returns, an error was encountered
#   resultdir_var - the variable named by "resultdir_var" will be set to
#     the path the package was unpackaged into
#
# Regarding "outdir": svn_unpackage() will place the results into a
# subdir of outdir. If there is already a subdir of outdir that is an
# svn checkout of the same URL, it will unpackage into that
# directory. Otherwise, it will create a new subdir with the basename
# of "changefile" minus the .tgz extension.
function (svn_unpackage changefile outdir tmpdir logfile result_var
    resultdir_var)
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

  # Determine SVN URL and revision
  execute_process (COMMAND "${ZORBA_EXE}" --omit-xml-declaration
                   --query "data(info/entry/@revision)"
                   --context-item "${chgdir}/svn-info.xml"
                   OUTPUT_VARIABLE svnrev)
  execute_process (COMMAND "${ZORBA_EXE}" --omit-xml-declaration
                   --query "data(info/entry/url)"
                   --context-item "${chgdir}/svn-info.xml"
                   OUTPUT_VARIABLE svnroot)
  # Special hack: Sourceforge has two URLs for everything, one http: and
  # one https:. The remote queue checks out via http:, so we have to
  # tweak the unpackaged URL here if it's https:.
  if ("${svnroot}" MATCHES "^https:.*sourceforge.net")
    string (REPLACE "https:" "http:" svnroot "${svnroot}")
  endif ("${svnroot}" MATCHES "^https:.*sourceforge.net")
  file (APPEND "${logfile}" "Checking out/updating from ${svnroot}...\n")

  # Look through outdir for a subdir matching svnroot.
  set (svndir)
  file (GLOB subdirs "${outdir}/*")
  foreach (subdir ${subdirs})
    execute_process (COMMAND "${svn}" info --xml "${subdir}"
      OUTPUT_FILE "${tmpdir}/tmpinfo.xml" ERROR_VARIABLE ignored
      RESULT_VARIABLE result)
    if (NOT result)
      execute_process (COMMAND "${ZORBA_EXE}" --omit-xml-declaration
        --query "data(info/entry/url)"
        --context-item "${tmpdir}/tmpinfo.xml"
        OUTPUT_VARIABLE subdir_svnroot)
      file (REMOVE "${tmpdir}/tmpinfo.xml")
      if (subdir_svnroot STREQUAL svnroot)
        set (svndir "${subdir}")
        break ()
      endif (subdir_svnroot STREQUAL svnroot)
    endif (NOT result)
  endforeach (subdir)
  if (NOT svndir)
    # No matching URL found; use basename of input file
    get_filename_component (basename "${changesfile}" NAME_WE)
    set (svndir "${outdir}/${basename}")
  endif (NOT svndir)
  file (APPEND "${logfile}" "..outputting to ${svndir}\n")
  set (${resultdir_var} "${svndir}" PARENT_SCOPE)

  execute_process (COMMAND "${svn}" checkout
                   -r "${svnrev}" "${svnroot}" "${svndir}"
                   OUTPUT_VARIABLE svnlog ERROR_VARIABLE svnlog)
  file (APPEND "${logfile}" ${svnlog})

  # Copy modified/added files on top of svn directory
  file (APPEND "${logfile}" "Copying added/modified files...\n")
  execute_process (COMMAND "${CMAKE_COMMAND}" -E copy_directory
                   "${chgdir}/files" "${svndir}")
  file (APPEND "${logfile}" "Done copying.\n")

  # Modified files are already all set. Process svn-status.xml to
  # delete any files which were deleted on client's svn, as named in
  # the client's changelist.
  file (READ "${chgdir}/changelist" changelist)
  get_files_with_status (deletefiles
                         "${chgdir}/svn-status.xml" "${changelist}" deleted)
  execute_process (COMMAND "${ZORBA_EXE}" --omit-xml-declaration
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
    file (APPEND "${logfile}" "${output}")
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
    file (APPEND "${logfile}" "${output}")
    if (result)
      set (${result_var} ${result} PARENT_SCOPE)
      return ()
    endif ()
  endforeach (filepath ${addfiles})

  # Remove temporary unpackaged workingset
  file (REMOVE_RECURSE "${chgdir}")

endfunction (svn_unpackage)
