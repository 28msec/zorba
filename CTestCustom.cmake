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

# do not take mapm into the coverage analysis
SET (CTEST_CUSTOM_COVERAGE_EXCLUDE "mapm.*")
SET (CTEST_CUSTOM_MAXIMUM_PASSED_TEST_OUTPUT_SIZE 8192)
SET (CTEST_CUSTOM_MAXIMUM_FAILED_TEST_OUTPUT_SIZE 8192)

# other possible options
#  CTEST_CUSTOM_ERROR_MATCH  Regular expression for errors during build process
#  CTEST_CUSTOM_ERROR_EXCEPTION  Regular expression for error exceptions during build process
#  CTEST_CUSTOM_WARNING_MATCH  Regular expression for warnings during build process
#  CTEST_CUSTOM_WARNING_EXCEPTION  Regular expression for warning exception during build process
#  CTEST_CUSTOM_MAXIMUM_NUMBER_OF_ERRORS   Maximum number of errors to display
#  CTEST_CUSTOM_MAXIMUM_NUMBER_OF_WARNINGS   Maximum number of warnings to display
#  CTEST_CUSTOM_TESTS_IGNORE   List of tests to ignore during the Test stage
#  CTEST_CUSTOM_MEMCHECK_IGNORE  List of tests to ignore during the MemCheck stage
#  CTEST_CUSTOM_PRE_TEST   Command to execute before any tests are run during Test stage
#  CTEST_CUSTOM_POST_TEST  Command to execute after any tests are run during Test stage
#  CTEST_CUSTOM_MAXIMUM_PASSED_TEST_OUTPUT_SIZE  Maximum size of passed test output
#  CTEST_CUSTOM_MAXIMUM_FAILED_TEST_OUTPUT_SIZE  Maximum size of failed test output
#  CTEST_CUSTOM_PRE_MEMCHECK   Command to execute before any tests are run during MemCheck stage
#  CTEST_CUSTOM_POST_MEMCHECK  Command to execute after any tests are run during MemCheck stage
#  CTEST_CUSTOM_COVERAGE_EXCLUDE
