SET(ZORBA_CMD_SRCS zorbacmd.cpp zorbacmdproperties.cpp)

ADD_EXECUTABLE(zorbacmd ${ZORBA_CMD_SRCS})
TARGET_LINK_LIBRARIES(zorbacmd zorba)
SET_TARGET_PROPERTIES(zorbacmd PROPERTIES OUTPUT_NAME "zorba") # cmake way to rename the file

# test the command line tool
ADD_TEST(cmd1 zorbacmd --omit-xml-declaration -i "1+1")
SET_TESTS_PROPERTIES(cmd1 PROPERTIES PASS_REGULAR_EXPRESSION "2")

ADD_TEST(cmd2 zorbacmd --serialize-html -i "1+1")
SET_TESTS_PROPERTIES(cmd2 PROPERTIES PASS_REGULAR_EXPRESSION "<html>2</html>")

ADD_TEST(cmd3 zorbacmd -m 0 -i "1+1")
SET_TESTS_PROPERTIES(cmd3 PROPERTIES PASS_REGULAR_EXPRESSION "")

ADD_TEST(cmd4 zorbacmd --context-item=${CMAKE_CURRENT_SOURCE_DIR}/test.xml  -m 3 -i "./test/child[1]")
SET_TESTS_PROPERTIES(cmd4 PROPERTIES PASS_REGULAR_EXPRESSION "(.*<child>child1</child>)*")

