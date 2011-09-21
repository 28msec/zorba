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

SET(DIAGNOSTICS_SRCS
   dict.cpp
   dict_en.cpp
   diagnostic.cpp
   qname.cpp 
   diagnostic_list.cpp
   assert.cpp
   zorba_exception.cpp
   xquery_diagnostics.cpp
   xquery_exception.cpp 
   xquery_stack_trace.cpp
   user_error.cpp
   user_exception.cpp 
   )

ZORBA_DIAGNOSTIC_GENERATOR(
    "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_h.xq"
    "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml"
    "diagnostic_en.xml"
    ""
    "${CMAKE_BINARY_DIR}/include/zorba/diagnostic_list.h")

ZORBA_DIAGNOSTIC_GENERATOR(
    "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_cpp.xq"
    "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml"
    "diagnostic_en.xml"
    "${CMAKE_BINARY_DIR}/include/zorba/diagnostic_list.h"
    "${CMAKE_BINARY_DIR}/src/diagnostics/diagnostic_list.cpp")

ZORBA_DIAGNOSTIC_GENERATOR(
    "${CMAKE_SOURCE_DIR}/src/diagnostics/dict_XX_cpp.xq"
    "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml"
    "diagnostic_en.xml"
    ""
    "${CMAKE_BINARY_DIR}/src/diagnostics/dict_en.cpp")

ZORBA_DIAGNOSTIC_GENERATOR(
    "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_xq.xq"
    "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml;ns:=err"
    "diagnostic_en.xml"
    ""
    "${CMAKE_BINARY_DIR}/modules/w3c/xqt-errors.xq"
)

ZORBA_DIAGNOSTIC_GENERATOR(
    "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_xq.xq"
    "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml;ns:=zerr"
    "diagnostic_en.xml"
    ""
    "${CMAKE_BINARY_DIR}/modules/com/zorba-xquery/www/modules/errors.xq"
)

ZORBA_DIAGNOSTIC_GENERATOR(
    "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_xq.xq"
    "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml;ns:=zwarn"
    "diagnostic_en.xml"
    ""
    "${CMAKE_BINARY_DIR}/modules/com/zorba-xquery/www/modules/warnings.xq"
)

ADD_CUSTOM_TARGET (gen_diag_modules
  DEPENDS ${CMAKE_BINARY_DIR}/modules/com/zorba-xquery/www/modules/warnings.xq
          ${CMAKE_BINARY_DIR}/modules/com/zorba-xquery/www/modules/errors.xq
          ${CMAKE_BINARY_DIR}/modules/w3c/xqt-errors.xq
)
SET_TARGET_PROPERTIES (gen_diag_modules PROPERTIES
  FOLDER "Modules"
)

IF (WIN32)
  SET(DIAGNOSTICS_SRCS ${DIAGNOSTICS_SRCS} StackWalker.cpp)
ENDIF (WIN32)
