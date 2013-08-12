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


# Compute results directory for testdriver
SET (_results_dir "${CMAKE_CURRENT_BINARY_DIR}/QueryResults")

# collect all queries (suffix .xq) in all subdirectories of the Queries dir
FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries/ *.xq)

MESSAGE(STATUS "Adding SAX2 tests for CTest")
SET(TESTCOUNTER 0)

FOREACH(TESTFILE ${TESTFILES})

 STRING(LENGTH ${TESTFILE} TESTFILELENGTH)
 MATH(EXPR TESTLENGTH '${TESTFILELENGTH}-3' )
 STRING(SUBSTRING ${TESTFILE} 0 ${TESTLENGTH} TESTNAME)

 SET (TESTNAME "test/sax2/${TESTNAME}")
 ZORBA_ADD_TEST(${TESTNAME} sax2testdriver ${TESTFILE})

 # Create directory for output, if it doesn't exist
 GET_FILENAME_COMPONENT(_bucket_path ${TESTFILE} PATH)
 IF (NOT EXISTS "${_results_dir}/${_bucket_path}")
   FILE (MAKE_DIRECTORY "${_results_dir}/${_bucket_path}")
 ENDIF (NOT EXISTS "${_results_dir}/${_bucket_path}")

 ZORBA_SET_TEST_PROPERTY (${TESTNAME} TIMEOUT "10")

 MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
 MATH(EXPR TESTMOD "${TESTCOUNTER}/1000")
 IF (${TESTMOD})
   MESSAGE(STATUS "Adding another 1000 Tests")
   SET(TESTCOUNTER 0)
 ENDIF (${TESTMOD})
                
ENDFOREACH(TESTFILE)
