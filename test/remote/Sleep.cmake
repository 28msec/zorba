# This script only exists to use ctest_sleep (). Pass number of
# seconds as CTest script argument (separate from script name by a
# comma).

# Tell CTest just to run as a pure script, not launch any tests.
set (CTEST_RUN_CURRENT_SCRIPT 0)

ctest_sleep(${CTEST_SCRIPT_ARG})
