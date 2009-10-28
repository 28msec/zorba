# This script only exists to use ctest_sleep (). Pass number of
# seconds as CTest script argument (separate from script name by a
# comma). Since it doesn't actually run any tests, it will produce
# error output unless you pass -Q:
#
#  ctest -Q -S Sleep.cmake,5   # sleep for 5 seconds

# Keep ctest (mostly) quiet - this fools it into not complaining that
# it didn't actually run any tests.
set (CTEST_SOURCE_DIRECTORY /ignore)
set (CTEST_BINARY_DIRECTORY /ignore)
ctest_start(Experimental)

ctest_sleep(${CTEST_SCRIPT_ARG})
