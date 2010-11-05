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
# create the testing file and list of tests

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/guestbook_main.xq ${CMAKE_CURRENT_BINARY_DIR}/guestbook_main.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/guestbook.xq ${CMAKE_CURRENT_BINARY_DIR}/guestbook.xq)

#belongs to test external_function.cpp
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_mod.xq ${CMAKE_CURRENT_BINARY_DIR}/ext_mod.xq)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ext_main.xq ${CMAKE_CURRENT_BINARY_DIR}/ext_main.xq)

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

IF(WIN32)
  CREATE_TEST_SOURCELIST(UnitTests
    UnitTests.cpp
    uri.cpp
    path_resolver.cpp
    userdefined_uri_resolver.cpp
    multiple_runs.cpp
    runnable.cpp
    plan_serializer.cpp
    call_stack.cpp
    external_function.cpp
    no_folding.cpp
    debug_iter_serialization.cpp
    ordpath_big.cpp
    uri_file_decoding_test.cpp
    ext_in_opt.cpp
    collection.cpp
    string_instantiate.cpp
    string_test.cpp
    main_sequential.cpp
  )
ELSE(WIN32)
  CREATE_TEST_SOURCELIST(UnitTests
    UnitTests.cpp
    uri.cpp
    path_resolver.cpp
    userdefined_uri_resolver.cpp
    plan_serializer.cpp
    call_stack.cpp
    external_function.cpp
    no_folding.cpp
    debug_iter_serialization.cpp
    ordpath_big.cpp
    uri_file_decoding_test.cpp
    ext_in_opt.cpp
    collection.cpp
    string_instantiate.cpp
    string_test.cpp
    main_sequential.cpp
  # multithread_simple.cpp
  # multithread_stress_test.cpp
 )
ENDIF(WIN32)

# add the executable
ZORBA_GENERATE_STORE_SPECIFIC_EXES(UnitTests "${UnitTests}" "" "" "")

# remove the test driver source file
SET (TestsToRun ${UnitTests})
REMOVE (TestsToRun UnitTests.cpp)

MESSAGE(STATUS "Adding unit tests for CTest")

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
  GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
  SET (TestName "test/unit/${TName}")
  ZORBA_ADD_TEST_ALLSTORES(${TestName} UnitTests ${TName})
ENDFOREACH(test)

EXPECTED_FAILURE(test/unit/uri_file_decoding_test 123)
EXPECTED_FAILURE(test/unit/userdefined_uri_resolver 3085804)

ADD_SUBDIRECTORY(debugger)
