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
  instantiate_string.cpp
  test_base64.cpp
  test_base64_streambuf.cpp
  test_fs_iterator.cpp
  test_json_parser.cpp
  test_string.cpp
  test_uri.cpp
  unit_tests.cpp
)

IF (NOT ZORBA_NO_FULL_TEXT)
  LIST (APPEND UNIT_TEST_SRCS
    test_stemmer.cpp
    test_thesaurus.cpp
    test_tokenizer.cpp)
ENDIF (NOT ZORBA_NO_FULL_TEXT)

IF (NOT ZORBA_NO_ICU)
  LIST (APPEND UNIT_TEST_SRCS
    test_icu_streambuf.cpp)
ENDIF (NOT ZORBA_NO_ICU)

IF (NOT ZORBA_HAVE_UNIQUE_PTR)
  LIST (APPEND UNIT_TEST_SRCS
    test_unique_ptr.cpp)
ENDIF (NOT ZORBA_HAVE_UNIQUE_PTR)

IF (NOT ZORBA_HAVE_UNORDERED_MAP)
  LIST (APPEND UNIT_TEST_SRCS
    instantiate_unordered_map.cpp
    test_unordered_map.cpp)
ENDIF (NOT ZORBA_HAVE_UNORDERED_MAP)

IF (NOT ZORBA_HAVE_UNORDERED_SET)
  LIST (APPEND UNIT_TEST_SRCS
    test_unordered_set.cpp)
ENDIF (NOT ZORBA_HAVE_UNORDERED_SET)

# vim:set et sw=2 ts=2:
