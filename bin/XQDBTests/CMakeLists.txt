IF(WIN32)
  SET(SHELL_EXT bat)
ELSE(WIN32)
  SET(SHELL_EXT sh)
ENDIF(WIN32)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/run_test.${SHELL_EXT}.cmake ${CMAKE_CURRENT_BINARY_DIR}/run_test.${SHELL_EXT})
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/run_test.${SHELL_EXT}.cmake --> ${CMAKE_CURRENT_BINARY_DIR}/run_test.${SHELL_EXT}")
ADD_TEST(bin/XQDBTests/xqdb1 ${CMAKE_CURRENT_BINARY_DIR}/run_test.${SHELL_EXT} query1.xq command1.txt result1.txt)
ADD_TEST(bin/XQDBTests/xqdb2 ${CMAKE_CURRENT_BINARY_DIR}/run_test.${SHELL_EXT} query2.xq command2.txt result2.txt)
ADD_TEST(bin/XQDBTests/xqdb3 ${CMAKE_CURRENT_BINARY_DIR}/run_test.${SHELL_EXT} query3.xq command3.txt result3.txt)

