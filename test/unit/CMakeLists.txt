# Copyright 2006-2008 The FLWOR Foundation.#   
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

# create the testing file and list of tests

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/guestbook_main.xq ${CMAKE_CURRENT_BINARY_DIR}/guestbook_main.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/mini_http.xq ${CMAKE_CURRENT_BINARY_DIR}/mini_http.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/mini_audit.xq ${CMAKE_CURRENT_BINARY_DIR}/mini_audit.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/guestbook.xq ${CMAKE_CURRENT_BINARY_DIR}/guestbook.xq)

#belongs to test cxx_api_changes.cpp
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/cxx_api_ch1.xq ${CMAKE_CURRENT_BINARY_DIR}/cxx_api_ch1.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/cxx_api_ch2.xq ${CMAKE_CURRENT_BINARY_DIR}/cxx_api_ch2.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/cxx_api_ch3.xq ${CMAKE_CURRENT_BINARY_DIR}/cxx_api_ch3.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/cxx_api_ch4.xq ${CMAKE_CURRENT_BINARY_DIR}/cxx_api_ch4.xq)
DECLARE_ZORBA_MODULE(URI "http://www.zorba-xquery.com/modules/testGetExtVarA"
  FILE "testGetExtVarA.xq" TEST_ONLY)  
DECLARE_ZORBA_MODULE(URI "http://www.zorba-xquery.com/modules/testGetExtVarB"
  FILE "testGetExtVarB.xq" TEST_ONLY)

#belongs to test external_function.cpp
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_mod.xq ${CMAKE_CURRENT_BINARY_DIR}/ext_mod.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_mod2.xq ${CMAKE_CURRENT_BINARY_DIR}/ext_mod2.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_main.xq ${CMAKE_CURRENT_BINARY_DIR}/ext_main.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_main2.xq ${CMAKE_CURRENT_BINARY_DIR}/ext_main2.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_main3.xq ${CMAKE_CURRENT_BINARY_DIR}/ext_main3.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_main4.xq ${CMAKE_CURRENT_BINARY_DIR}/ext_main4.xq)

#belongs to test no_folding.cpp
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/fold_mod1.xq ${CMAKE_CURRENT_BINARY_DIR}/fold_mod1.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/fold_mod2.xq ${CMAKE_CURRENT_BINARY_DIR}/fold_mod2.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/fold_main.xq ${CMAKE_CURRENT_BINARY_DIR}/fold_main.xq)

#belongs to test ext_in_opt.cpp
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_in_opt.xq ${CMAKE_CURRENT_BINARY_DIR}/ext_in_opt.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_in_opt.xqlib ${CMAKE_CURRENT_BINARY_DIR}/ext_in_opt.xqlib)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_in_opt2.xqlib ${CMAKE_CURRENT_BINARY_DIR}/ext_in_opt2.xqlib)

#belongs to test collection.cpp
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/collection1.xq ${CMAKE_CURRENT_BINARY_DIR}/collection1.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/collection2.xq ${CMAKE_CURRENT_BINARY_DIR}/collection2.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/collection1.xqlib ${CMAKE_CURRENT_BINARY_DIR}/collection1.xqlib)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/collection2.xqlib ${CMAKE_CURRENT_BINARY_DIR}/collection2.xqlib)

#belongs to test main_sequential
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/main_sequential.xq ${CMAKE_CURRENT_BINARY_DIR}/main_sequential.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/main_sequential.xqlib ${CMAKE_CURRENT_BINARY_DIR}/main_sequential.xqlib)

# belongs to the staticcollectionmanager test
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/main_invoke.xq ${CMAKE_CURRENT_BINARY_DIR}/main_invoke.xq)

#belongs to test context_item
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/context_item1.xq ${CMAKE_CURRENT_BINARY_DIR}/context_item1.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/context_item2.xq ${CMAKE_CURRENT_BINARY_DIR}/context_item2.xq)

#belongs to streamable_string
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/streamable_string_query_1.xq ${CMAKE_CURRENT_BINARY_DIR}/streamable_string_query_1.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/streamable_string_query_2.xq ${CMAKE_CURRENT_BINARY_DIR}/streamable_string_query_2.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/streamable_string.cpp ${CMAKE_CURRENT_BINARY_DIR}/streamable_string.cpp)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/module1.xq ${CMAKE_CURRENT_BINARY_DIR}/module1.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/module2.xq ${CMAKE_CURRENT_BINARY_DIR}/module2.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/module3.xq ${CMAKE_CURRENT_BINARY_DIR}/module3.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/module4.xq ${CMAKE_CURRENT_BINARY_DIR}/module4.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/module5.xq ${CMAKE_CURRENT_BINARY_DIR}/module5.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/module6.xq ${CMAKE_CURRENT_BINARY_DIR}/module6.xq)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/schema1.xsd ${CMAKE_CURRENT_BINARY_DIR}/schema1.xsd)

SET(UNIT_TESTS_SRCS
  multiple_runs.cpp
  plan_serializer.cpp
  call_stack.cpp
  cxx_api_changes.cpp
  external_function.cpp
  no_folding.cpp
  ordpath_big.cpp
  uri_file_decoding_test.cpp
  ext_in_opt.cpp
  collection.cpp
  test_audit.cpp
  streamable_string.cpp
  main_sequential.cpp
  context_item.cpp
  datetime.cpp
  invoke.cpp
  xquery_functions.cpp
  xmldatamanager.cpp
  staticcollectionmanager.cpp
  test_static_context.cpp
)

# multithread_simple.cpp
# multithread_stress_test.cpp

IF(ZORBA_WITH_DEBUGGER)
  LIST(APPEND SPEC_FILES "debug_iter_serialization.cpp")
ENDIF(ZORBA_WITH_DEBUGGER)

IF(WIN32)
  # SF#3191791
  LIST(REMOVE_ITEM UNIT_TESTS_SRCS "string_test.cpp")
ENDIF(WIN32)

CREATE_TEST_SOURCELIST(UnitTests
  UnitTests.cpp
  ${UNIT_TESTS_SRCS}
)

# add the executable
INCLUDE_DIRECTORIES("${CMAKE_BINARY_DIR}/test/driver")
ZORBA_GENERATE_EXE(UnitTests "${UnitTests}" "" "" "")

# remove the test driver source file
SET (TestsToRun ${UnitTests})
REMOVE (TestsToRun UnitTests.cpp)

MESSAGE(STATUS "Adding unit tests for CTest")

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
  GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
  SET (TestName "test/unit/${TName}")
  ZORBA_ADD_TEST(${TestName} UnitTests ${TName})
ENDFOREACH(test)

IF(ZORBA_WITH_UNIT_TESTS)
  # Add lib-internal unit tests
  ZORBA_GENERATE_EXE(LibUnitTest lib_unit_test.cpp "" "" "")

  # ADD NEW UNIT TESTS HERE
  ZORBA_ADD_TEST("test/libunit/base64" LibUnitTest base64)
  ZORBA_ADD_TEST("test/libunit/base64_streambuf" LibUnitTest base64_streambuf)
  IF (NOT WIN32)
    # disabled because of bug lp:867271
    ZORBA_ADD_TEST("test/libunit/string" LibUnitTest string)
  ENDIF (NOT WIN32)
  ZORBA_ADD_TEST("test/libunit/uri" LibUnitTest uri)
  EXPECTED_FAILURE(test/libunit/uri 3118348)
  IF (NOT ZORBA_NO_ICU)
    ZORBA_ADD_TEST("test/libunit/icu_streambuf" LibUnitTest icu_streambuf)
  ENDIF (NOT ZORBA_NO_ICU)
  ZORBA_ADD_TEST("test/libunit/json_parser" LibUnitTest json_parser)
  ZORBA_ADD_TEST("test/libunit/parameters" LibUnitTest parameters)
  ZORBA_ADD_TEST("test/libunit/time_parse" LibUnitTest time_parse)
  #ZORBA_ADD_TEST("test/libunit/memory_manager" LibUnitTest memory_manager)
  IF (NOT ZORBA_NO_FULL_TEXT)
    ZORBA_ADD_TEST("test/libunit/stemmer" LibUnitTest stemmer)
    ZORBA_ADD_TEST("test/libunit/thesaurus" LibUnitTest thesaurus)
    ZORBA_ADD_TEST("test/libunit/tokenizer" LibUnitTest tokenizer)
  ENDIF (NOT ZORBA_NO_FULL_TEXT)
  IF (NOT ZORBA_HAVE_UNIQUE_PTR)
    ZORBA_ADD_TEST("test/libunit/unique_ptr" LibUnitTest unique_ptr)
  ENDIF (NOT ZORBA_HAVE_UNIQUE_PTR)
  IF (NOT ZORBA_HAVE_UNORDERED_MAP)
    ZORBA_ADD_TEST("test/libunit/unordered_map" LibUnitTest unordered_map)
  ENDIF (NOT ZORBA_HAVE_UNORDERED_MAP)
  IF (NOT ZORBA_HAVE_UNORDERED_SET)
    ZORBA_ADD_TEST("test/libunit/unordered_set" LibUnitTest unordered_set)
  ENDIF (NOT ZORBA_HAVE_UNORDERED_SET)
  ZORBA_ADD_TEST("test/libunit/utf8_streambuf" LibUnitTest utf8_streambuf)
ENDIF(ZORBA_WITH_UNIT_TESTS)
# vim:set et sw=2 ts=2:
