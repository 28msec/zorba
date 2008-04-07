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
