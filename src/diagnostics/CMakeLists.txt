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
   qname_util.cpp
   qnames.cpp 
   diagnostic_list.cpp
   assert.cpp
   zorba_exception.cpp
   xquery_diagnostics.cpp
   xquery_exception.cpp 
   xquery_stack_trace.cpp
   user_error.cpp
   user_exception.cpp 
   dict_zed_keys.h
   )

IF (WIN32)
  SET( DIAGNOSTICS_SRCS ${DIAGNOSTICS_SRCS} StackWalker.cpp )
ENDIF (WIN32)

###############################################################################

ZORBA_DIAGNOSTIC_GENERATOR(
  "${CMAKE_SOURCE_DIR}/src/diagnostics/qnames_h.xq"
  "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_namespaces.xml"
  "diagnostic_namespaces.xml"
  ""
  "${CMAKE_BINARY_DIR}/include/zorba/internal/qnames.h"
)

ZORBA_DIAGNOSTIC_GENERATOR(
  "${CMAKE_SOURCE_DIR}/src/diagnostics/qnames_cpp.xq"
  "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_namespaces.xml"
  "diagnostic_namespaces.xml"
  ""
  "${CMAKE_BINARY_DIR}/src/diagnostics/qnames.cpp"
)

ZORBA_DIAGNOSTIC_GENERATOR(
  "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_h.xq"
  "diagnostics-input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml;namespaces-input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_namespaces.xml"
  "diagnostic_en.xml"
  "${CMAKE_BINARY_DIR}/include/zorba/internal/qnames.h"
  "${CMAKE_BINARY_DIR}/include/zorba/diagnostic_list.h"
)

ZORBA_DIAGNOSTIC_GENERATOR(
  "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_cpp.xq"
  "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml"
  "diagnostic_en.xml"
  "${CMAKE_BINARY_DIR}/include/zorba/diagnostic_list.h"
  "${CMAKE_BINARY_DIR}/src/diagnostics/diagnostic_list.cpp"
)

ZORBA_DIAGNOSTIC_GENERATOR(
  "${CMAKE_SOURCE_DIR}/src/diagnostics/dict_XX_cpp.xq"
  "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml"
  "diagnostic_en.xml"
  ""
  "${CMAKE_BINARY_DIR}/src/diagnostics/dict_en.cpp"
)

ZORBA_DIAGNOSTIC_GENERATOR(
  "${CMAKE_SOURCE_DIR}/src/diagnostics/dict_zed_keys_h.xq"
  "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml"
  "diagnostic_en.xml"
  ""
  "${CMAKE_BINARY_DIR}/src/diagnostics/dict_zed_keys.h"
)

###############################################################################

ZORBA_DIAGNOSTIC_GENERATOR(
  "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_xq.xq"
  "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml;ns:=err"
  "diagnostic_en.xml"
  ""
  "${CMAKE_BINARY_DIR}/modules/w3c/xqt-errors.xq"
)

ZORBA_DIAGNOSTIC_GENERATOR(
  "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_xq.xq"
  "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml;ns:=jerr"
  "diagnostic_en.xml"
  ""
  "${CMAKE_BINARY_DIR}/modules/jsoniq-errors.xq"
)

ZORBA_DIAGNOSTIC_GENERATOR(
  "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_xq.xq"
  "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml;ns:=zerr"
  "diagnostic_en.xml"
  ""
  "${CMAKE_BINARY_DIR}/modules/zorba-errors.xq"
)

ZORBA_DIAGNOSTIC_GENERATOR(
  "${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_list_xq.xq"
  "input=${CMAKE_SOURCE_DIR}/src/diagnostics/diagnostic_en.xml;ns:=zwarn"
  "diagnostic_en.xml"
  ""
  "${CMAKE_BINARY_DIR}/modules/zorba-warnings.xq"
)

###############################################################################

SET( DIAG_MODULES
  ${CMAKE_BINARY_DIR}/modules/zorba-errors.xq
  ${CMAKE_BINARY_DIR}/modules/zorba-warnings.xq
  ${CMAKE_BINARY_DIR}/modules/w3c/xqt-errors.xq
  ${CMAKE_BINARY_DIR}/modules/jsoniq-errors.xq
)

ADD_CUSTOM_TARGET( gen_diag_modules DEPENDS ${DIAG_MODULES} )
SET_TARGET_PROPERTIES( gen_diag_modules PROPERTIES FOLDER "Modules" )

# vim:set et sw=2 ts=2:
