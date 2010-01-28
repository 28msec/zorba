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
# The expected_failure() function is used to mark a test which is currently
# failing, but is being worked on.
#
# Usage: expected_failure (testname bugid)
#  where "testname" is the full test name and "bugid" is the Sourceforge
#  Tracker artifact ID.

MACRO(expected_failure testname bugid)
  # The meat: flip the "will_fail" flag
  get_test_property ("${testname}" WILL_FAIL willfail)
  if (willfail)
    set (willfail 0)
  else (willfail)
    set (willfail 1)
  endif (willfail)
  set_tests_properties ("${testname}" PROPERTIES WILL_FAIL ${willfail})

  # Also store the name and bug ID of this test in our output file
  file (APPEND "${expected_failures_file}"
        "<Test name=\"${testname}\" bug=\"${bugid}\"/>")

ENDMACRO(expected_failure)

# Initialize output file when first included
set (expected_failures_file "${CMAKE_BINARY_DIR}/ExpectedFailures.xml")
file (WRITE "${expected_failures_file}" "<ExpectedFailures>")

# Call this MACRO to close out output file
MACRO(close_expected_failures)
  file (APPEND "${expected_failures_file}" "</ExpectedFailures>")
ENDMACRO(close_expected_failures)
