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
  call_stack.cpp
)
ELSE(WIN32)
 CREATE_TEST_SOURCELIST(UnitTests
 UnitTests.cpp
 itemfactory.cpp
 xmldatamanager.cpp
 uri.cpp
 call_stack.cpp
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

ADD_SUBDIRECTORY(debugger)
