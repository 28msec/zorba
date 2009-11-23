# Generate an XQUTS test submission from a recent CTest run.

get_filename_component (cwd ${CMAKE_CURRENT_LIST_FILE} PATH)
if (ZORBA_BUILD_DIR)
  set (builddir "${ZORBA_BUILD_DIR}")
else ()
  set (builddir "${cwd}/../../../build")
endif ()
find_program(zorba NAMES zorba zorba.exe PATHS "${builddir}" "${builddir}/release" PATH_SUFFIXES bin)
if (NOT zorba)
  message (FATAL_ERROR "Zorba is required; not found. Specify -DZORBA_BUILD_DIR to point to your build directory if necessary.")
endif ()

# Read most recent CTest tag
file (STRINGS "${builddir}/Testing/TAG" _tag_content)
list (GET _tag_content 0 ctest_tag)
set (testfile "${builddir}/Testing/${ctest_tag}/Test.xml")
MESSAGE(STATUS "using testresults from: ${testfile}")

# Execute Zorba
execute_process (COMMAND "${zorba}" --omit-xml-declaration --indent
                 --query "${cwd}/generate-submission.xq" --as-files
                 -e "ctests=${testfile}")
