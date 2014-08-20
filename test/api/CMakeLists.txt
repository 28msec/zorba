# Copyright 2006-2010 The FLWOR Foundation.
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

CREATE_TEST_SOURCELIST(APITests
  APITests.cpp
  itemfactory.cpp
  xmldatamanager.cpp
  jsondatamanager.cpp
  xquery.cpp
  test_static_context.cpp
  test_dynamic_context.cpp
  serializer.cpp
  annotations.cpp
  external_function_errors.cpp
  userdefined_uri_resolution.cpp
  validate.cpp
)

# add the executable
ZORBA_GENERATE_EXE(APITests "${APITests}" "" "" "")

# remove the test driver source file
SET (TestsToRun ${APITests})
REMOVE (TestsToRun APITests.cpp)

MESSAGE(STATUS "Adding API tests for CTest")

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
  GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
  SET (TestName "test/api/${TName}")
  ZORBA_ADD_TEST(${TestName} APITests ${TName}
    "${CMAKE_BINARY_DIR}/TEST_URI_PATH")
ENDFOREACH(test)

# Add importing schema for userdefined_uri_resolution test
DECLARE_ZORBA_SCHEMA(FILE import-hello.xsd
  URI http://www.zorba-xquery.com/import-hello TEST_ONLY)

EXPECTED_FAILURE(test/api/test_static_context 3118348)
