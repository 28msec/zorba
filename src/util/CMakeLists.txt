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

SET(UTIL_SRCS
  ascii_util.cpp
  dynamic_bitset.cpp
  error_util.cpp
  file.cpp
  fs_util.cpp
  indent.cpp
  json_parser.cpp
  mem_streambuf.cpp
  regex.cpp
  string_util.cpp
  unicode_util.cpp
  unicode_categories.cpp
  uri_util.cpp
  utf8_util.cpp
  xml_util.cpp
  fx/fxcharheap.cpp
  string/empty_rep_base.cpp
  uuid/sysdep.cpp
  uuid/uuid.cpp
  http_util.h
  http_util.cpp)

IF(ZORBA_WITH_FILE_ACCESS)
  LIST(APPEND UTIL_SRCS mmap_file.cpp)
ENDIF(ZORBA_WITH_FILE_ACCESS)

IF(ZORBA_NO_ICU)
  LIST(APPEND UTIL_SRCS
    regex_xquery.cpp
    passthru_streambuf.cpp)
ELSE(ZORBA_NO_ICU)
  LIST(APPEND UTIL_SRCS
    icu_streambuf.cpp)
ENDIF(ZORBA_NO_ICU)

HEADER_GROUP_SUBFOLDER(UTIL_SRCS fx)
HEADER_GROUP_SUBFOLDER(UTIL_SRCS win32)

IF (NOT (ZORBA_HAVE_UNORDERED_MAP AND ZORBA_HAVE_UNORDERED_SET))
  ADD_SRC_SUBFOLDER(UTIL_SRCS hash UTIL_HASH_SRCS)
ENDIF (NOT (ZORBA_HAVE_UNORDERED_MAP AND ZORBA_HAVE_UNORDERED_SET))
