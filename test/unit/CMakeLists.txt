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

IF(WIN32)
CREATE_TEST_SOURCELIST(UnitTests
  UnitTests.cpp
  itemfactory.cpp
  xmldatamanager.cpp
  uri.cpp
  multiple_runs.cpp
  runnable.cpp
)
ELSE(WIN32)
 CREATE_TEST_SOURCELIST(UnitTests
 UnitTests.cpp
 itemfactory.cpp
 xmldatamanager.cpp
 uri.cpp
# multithread_simple.cpp
# multithread_stress_test.cpp
)
ENDIF(WIN32)

# add the executable
ADD_EXECUTABLE(UnitTests ${UnitTests})
TARGET_LINK_LIBRARIES(UnitTests zorba_simplestore)

IF (ZORBA_BUILD_STATIC_LIBRARY)                                                                         
  ADD_EXECUTABLE(UnitTests_static ${UnitTests})                                                 
  SET_TARGET_PROPERTIES(UnitTests_static PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)
  TARGET_LINK_LIBRARIES(UnitTests_static zorba_simplestore_static)                           
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)           

IF(WIN32)
SET(UNITTESTS_EXE_PATH    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/UnitTests)
ELSE(WIN32)
SET(UNITTESTS_EXE_PATH    UnitTests)
ENDIF(WIN32)

# remove the test driver source file
SET (TestsToRun ${UnitTests})
REMOVE (TestsToRun UnitTests.cpp)

MESSAGE(STATUS "Adding unit tests for CTest")

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
  GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
  SET (TestName "test/unit/${TName}")
  ADD_TEST(${TestName} ${UNITTESTS_EXE_PATH} ${TName})
ENDFOREACH(test)

ADD_SUBDIRECTORY(debugger)
