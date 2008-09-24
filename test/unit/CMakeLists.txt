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
CREATE_TEST_SOURCELIST(UnitTests
  UnitTests.cpp
  typesystem_isSubtype.cpp
  itemfactory.cpp
  uri.cpp
#   multithread_simple.cpp
)

# add the executable
ADD_EXECUTABLE(UnitTests ${UnitTests})
TARGET_LINK_LIBRARIES(UnitTests zorba simplestore)

IF ( APPLE )
    SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -all_load" )
ENDIF (APPLE)

# remove the test driver source file
SET (TestsToRun ${UnitTests})
REMOVE (TestsToRun UnitTests.cpp)

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
  GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
  MESSAGE(STATUS ${TName})
  ADD_TEST(${TName} UnitTests ${TName})
ENDFOREACH(test)


# CAPI Unit test
CREATE_TEST_SOURCELIST(CAPIUnitTests
   CAPIUnitTests.c
   citemfactory.c
 )
 
 # add the executable
 ADD_EXECUTABLE(CAPIUnitTests ${CAPIUnitTests})
 TARGET_LINK_LIBRARIES(CAPIUnitTests zorba simplestore)

IF (ZORBA_BUILD_STATIC_LIBRARY)                                                                         
  ADD_EXECUTABLE(CAPIUnitTests_static ${CAPIUnitTests})                                                 
  TARGET_LINK_LIBRARIES(CAPIUnitTests_static zorba_static simplestore_static)                           
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)           
 
 # remove the test driver source file
 SET (CAPITestsToRun ${CAPIUnitTests})
 REMOVE (CAPITestsToRun CAPIUnitTests.cpp)
 
 # add all the ADD_TEST for each testing
 FOREACH (test ${CTestsToRun})
   GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
   MESSAGE(STATUS ${TName})
   ADD_TEST(${TName} CAPIUnitTests ${TName})
 ENDFOREACH(test)

IF(ZORBA_DEBUGGER)
  ADD_SUBDIRECTORY(debugger)
ENDIF(ZORBA_DEBUGGER)
