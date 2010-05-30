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


ZORBA_GENERATE_STORE_SPECIFIC_EXES("test_extern_func" "test_extern_func.cpp" "" "" "")
ZORBA_ADD_TEST_ALLSTORES(test/extern_func_1 test_extern_func --test1)
ZORBA_SET_TEST_PROPERTY_ALLSTORES (test/extern_func_1 PASS_REGULAR_EXPRESSION myns)


# create the result directory for all tests
#IF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)
#    FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)
#ENDIF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)


#
#
#
#ADD_SUBDIRECTORY(Queries)
