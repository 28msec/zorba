# The expected_failure() function is used to mark a test which is currently
# failing, but is being worked on.
#
# Usage: expected_failure (testname bugid)
#  where "testname" is the full test name and "bugid" is the Sourceforge
#  Tracker artifact ID.

function (expected_failure testname bugid)
  # The meat: flip the "will_fail" flag
  get_test_property ("${testname}" WILL_FAIL willfail)
  if (willfail)
    set (willfail 0)
  else ()
    set (willfail 1)
  endif ()
  set_tests_properties ("${testname}" PROPERTIES WILL_FAIL ${willfail})

  # Also store the name and bug ID of this test in our output file
  file (APPEND "${expected_failures_file}"
        "<Test name=\"${testname}\" bug=\"${bugid}\"/>")

endfunction ()

# Initialize output file when first included
set (expected_failures_file "${CMAKE_BINARY_DIR}/ExpectedFailures.xml")
file (WRITE "${expected_failures_file}" "<ExpectedFailures>")

# Call this function to close out output file
function (close_expected_failures)
  file (APPEND "${expected_failures_file}" "</ExpectedFailures>")
endfunction ()
