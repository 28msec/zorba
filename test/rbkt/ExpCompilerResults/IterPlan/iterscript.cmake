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

STRING (LENGTH ${TESTFILE} testfile_length)
MATH (EXPR testfile_length "${testfile_length} - 5")
STRING (SUBSTRING ${TESTFILE} 0 ${testfile_length} test_file)
    
SET (APITEST_OUT_DIR ${CMAKE_ZORBA_BINARY_DIR}/test/rbkt/CompilerResults/IterPlan/${test_file}.spec)
GET_FILENAME_COMPONENT (APITEST_OUT_PATH ${APITEST_OUT_DIR} PATH)
    
FILE (MAKE_DIRECTORY ${APITEST_OUT_PATH})
    
EXECUTE_PROCESS (
  COMMAND
    ${APITEST_PATH}
    --iter-plan-test
    --print-iterator-tree
    --no-tree-ids ${CMAKE_ZORBA_SOURCE_DIR}/test/rbkt/Queries/${test_file}.xq
  OUTPUT_FILE ${APITEST_OUT_DIR}
) 
    
FILE (TO_NATIVE_PATH ${CMAKE_ZORBA_BINARY_DIR}/test/rbkt/itertest.xq itertest_xq_path)
    
EXECUTE_PROCESS (
  COMMAND
    ${ZORBA_EXE}
    -f -q ${itertest_xq_path}
    -e testfile:=${TESTFILE} 
    -e apitest-path:=${APITEST_PATH}
    -e query-result:=${APITEST_OUT_DIR} 
    -z method=text
  OUTPUT_VARIABLE out_var
)
              
MESSAGE(STATUS ${out_var})
