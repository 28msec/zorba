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

SET(UNIT_TEST_SRCS
  mem_sizeof.cpp
  string_instantiate.cpp
  string.cpp
  test_uri.cpp
  unique_ptr.cpp
  unit_tests.cpp
  test_uri.cpp
  json_parser.cpp
  test_fs_iterator.cpp
)

IF (NOT ZORBA_NO_FULL_TEXT)
  LIST (APPEND UNIT_TEST_SRCS
    stemmer.cpp
    thesaurus.cpp
    tokenizer.cpp)
ENDIF (NOT ZORBA_NO_FULL_TEXT)

IF (NOT ZORBA_NO_ICU)
  LIST (APPEND UNIT_TEST_SRCS
    test_icu_streambuf.cpp)
ENDIF (NOT ZORBA_NO_ICU)

# vim:set et sw=2 tw=2:
