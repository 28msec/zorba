# Utility routines to package a local SVN working copy's changes into
# a single file, and for applying that file to a fresh SVN enlistment
# elsewhere.


macro (find_prereqs)
  # Definitely need svn here.
  FIND_PROGRAM(SVN_EXECUTABLE svn
  DOC "subversion command line client")
  IF(NOT SVN_EXECUTABLE)
    message (FATAL_ERROR "Subversion is required; not found")
  ENDIF(NOT SVN_EXECUTABLE)
  set (svn "${SVN_EXECUTABLE}")

  # We also want zorba itself (you HAVE built it, right?).
  find_program(zorba NAMES zorba zorba.exe
               PATHS "${cwd}/../../build" "${ZORBA_BUILD_DIR}"
               PATH_SUFFIXES bin)
  if (NOT zorba)
    message (FATAL_ERROR "Zorba is required; not found. Specify -DZORBA_BUILD_DIR to point to your build directory if necessary.")
  endif (NOT zorba)
endmacro (find_prereqs)


# Utility routine: given svn-status.xml file and a changelist (may be
# ""), return a list of files which match any specified status.
macro (get_files_with_status filelist svnstatusxml changelist)
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
    set (whereclause "${whereclause}${prefix} $status=\"${status}\"")
    set (prefix " or")
  endforeach (status ${ARGN})
  set (query
    "fn:string-join(
      for $entry in status/${elem}/entry
      let $status := data($entry/wc-status/@item)
      ${whereclause}
      return $entry/@path,
      \";\")")

  # Set "filelist" to result
  execute_process (COMMAND "${zorba}" --omit-xml-declaration
                   --query "${query}" --context-item "${svnstatusxml}"
                   OUTPUT_VARIABLE "${filelist}")
endmacro (get_files_with_status)


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
  execute_process (COMMAND "${zorba}" --omit-xml-declaration
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
macro (svn_unpackage changefile svndir tmpdir)
  find_prereqs ()

  # Unpack changes.tgz into working dir
  execute_process (COMMAND "${CMAKE_COMMAND}" -E tar xzf "${changefile}"
                   WORKING_DIRECTORY "${tmpdir}")
  set (chgdir "${tmpdir}/changes")

  # Checkout/update svn from specified URL and rev
  execute_process (COMMAND "${zorba}" --omit-xml-declaration
                   --query "data(info/entry/url)"
                   --context-item "${chgdir}/svn-info.xml"
                   OUTPUT_VARIABLE svnroot)
  execute_process (COMMAND "${zorba}" --omit-xml-declaration
                   --query "data(info/entry/@revision)"
                   --context-item "${chgdir}/svn-info.xml"
                   OUTPUT_VARIABLE svnrev)
  execute_process (COMMAND "${svn}" checkout
                   -r "${svnrev}" "${svnroot}" "${svndir}")

  # Copy modified/added files on top of svn directory
  execute_process (COMMAND "${CMAKE_COMMAND}" -E copy_directory
                   "${chgdir}/files" "${svndir}")

  # Modified files are already all set. Process svn-status.xml to
  # delete any files which were deleted on client's svn, as named in
  # the client's changelist.
  file (READ "${chgdir}/changelist" changelist)
  get_files_with_status (deletefiles
                         "${chgdir}/svn-status.xml" "${changelist}" deleted)
  execute_process (COMMAND "${zorba}" --omit-xml-declaration
                   --query "data(info/entry/@path)"
                   --context-item "${chgdir}/svn-info.xml"
                   OUTPUT_VARIABLE clientroot)
  foreach (filepath ${deletefiles})
    # These are absolute paths from the client; convert to relative paths
    file (RELATIVE_PATH relpath "${clientroot}" "${filepath}")
    execute_process (COMMAND "${svn}" delete "${svndir}/${relpath}")
  endforeach (filepath ${deletefiles})

  # Now add any new files, using the local output of "svn status" to
  # find "unversioned" files.  (We could read the svn-status.xml from
  # the changes file, but when it is based on a changelist, it won't
  # include directories to add.)
  execute_process (COMMAND "${svn}" --xml status "${svndir}"
                   OUTPUT_FILE "${chgdir}/svn-status.xml")
  get_files_with_status (addfiles "${chgdir}/svn-status.xml" "" unversioned)
  foreach (filepath ${addfiles})
    execute_process (COMMAND "${svn}" add "${filepath}")
  endforeach (filepath ${addfiles})

  # Remove temporary unpackaged workingset
  file (REMOVE_RECURSE "${chgdir}")

endmacro (svn_unpackage)
