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


ZORBA_GENERATE_EXE("test_extern_func" "test_extern_func.cpp" "" "" "")

# Test 1
ZORBA_ADD_TEST         (test/extern-func-1 test_extern_func --test1 ${CMAKE_CURRENT_SOURCE_DIR}/extern-func-1.xq)
ZORBA_SET_TEST_PROPERTY(test/extern-func-1 PASS_REGULAR_EXPRESSION myns)

# Test 2
ZORBA_ADD_TEST         (test/extern-func-2 test_extern_func --test1 ${CMAKE_CURRENT_SOURCE_DIR}/extern-func-2.xq)
ZORBA_SET_TEST_PROPERTY(test/extern-func-2 PASS_REGULAR_EXPRESSION myns)

# Test 3
ZORBA_ADD_TEST         (test/extern-func-3 test_extern_func --test2 ${CMAKE_CURRENT_SOURCE_DIR}/extern-func-module-2.xq)
ZORBA_SET_TEST_PROPERTY(test/extern-func-3 PASS_REGULAR_EXPRESSION myns)

# Test 4
ZORBA_ADD_TEST         (test/extern-func-4 test_extern_func --test2 ${CMAKE_CURRENT_SOURCE_DIR}/extern-func-module-3.xq)
ZORBA_SET_TEST_PROPERTY(test/extern-func-4 PASS_REGULAR_EXPRESSION myns)

# Test 5
ZORBA_ADD_TEST         (test/extern-func-5 test_extern_func --test2 ${CMAKE_CURRENT_SOURCE_DIR}/extern-func-module-4.xq)
ZORBA_SET_TEST_PROPERTY(test/extern-func-5 PASS_REGULAR_EXPRESSION myns)


#
# Tests for nondeterministic external functions
#

# nondeterm-1
ZORBA_ADD_TEST         (test/extern_nondeterm_1 test_extern_func --nondeterm ${CMAKE_CURRENT_SOURCE_DIR}/nondeterm-1.xq)
ZORBA_SET_TEST_PROPERTY(test/extern_nondeterm_1 PASS_REGULAR_EXPRESSION "1 2 3 4 5")

# nondeterm-2
ZORBA_ADD_TEST         (test/extern_nondeterm_2 test_extern_func --nondeterm ${CMAKE_CURRENT_SOURCE_DIR}/nondeterm-2.xq)
ZORBA_SET_TEST_PROPERTY(test/extern_nondeterm_2 PASS_REGULAR_EXPRESSION "Yes 2")

# nondeterm-3
ZORBA_ADD_TEST         (test/extern_nondeterm_3 test_extern_func --nondeterm ${CMAKE_CURRENT_SOURCE_DIR}/nondeterm-3.xq)
ZORBA_SET_TEST_PROPERTY(test/extern_nondeterm_3 PASS_REGULAR_EXPRESSION "1 2 3 4 5")

# nondeterm-4
ZORBA_ADD_TEST         (test/extern_nondeterm_4 test_extern_func --nondeterm ${CMAKE_CURRENT_SOURCE_DIR}/nondeterm-4.xq)
ZORBA_SET_TEST_PROPERTY(test/extern_nondeterm_4 PASS_REGULAR_EXPRESSION "Yes 2")

# nondeterm-5
ZORBA_ADD_TEST         (test/extern_nondeterm_5 test_extern_func --nondeterm ${CMAKE_CURRENT_SOURCE_DIR}/nondeterm-5.xq)
ZORBA_SET_TEST_PROPERTY(test/extern_nondeterm_5 PASS_REGULAR_EXPRESSION "1 2 3 4 5")

# nondeterm-6
ZORBA_ADD_TEST         (test/extern_nondeterm_6 test_extern_func --nondeterm ${CMAKE_CURRENT_SOURCE_DIR}/nondeterm-6.xq)
ZORBA_SET_TEST_PROPERTY(test/extern_nondeterm_6 PASS_REGULAR_EXPRESSION "1 2 3 4 5 6 7 8 9 10")

# nondeterm-7
ZORBA_ADD_TEST         (test/extern_nondeterm_7 test_extern_func --nondeterm ${CMAKE_CURRENT_SOURCE_DIR}/nondeterm-7.xq)
ZORBA_SET_TEST_PROPERTY(test/extern_nondeterm_7 PASS_REGULAR_EXPRESSION "2 1 4 2 6 3")

# nondeterm-8
ZORBA_ADD_TEST         (test/extern_nondeterm_8 test_extern_func --nondeterm ${CMAKE_CURRENT_SOURCE_DIR}/nondeterm-8.xq)
ZORBA_SET_TEST_PROPERTY(test/extern_nondeterm_8 PASS_REGULAR_EXPRESSION "0 1 0 2 0 3 0 4 0 5")

# nondeterm-9
ZORBA_ADD_TEST         (test/extern_nondeterm_9 test_extern_func --nondeterm ${CMAKE_CURRENT_SOURCE_DIR}/nondeterm-9.xq)
ZORBA_SET_TEST_PROPERTY(test/extern_nondeterm_9 PASS_REGULAR_EXPRESSION "1 2 3 4 5 6 7 8 9 10")
