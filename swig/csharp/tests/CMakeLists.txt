# Copyright 2006-2011 The FLWOR Foundation.
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

SET(CSharpPath ${CMAKE_BINARY_DIR}/swig/csharp)
IF (MSVC_IDE)
  SET(CSharpBuildPath ${CSharpPath}/${CMAKE_BUILD_TYPE})
ELSE (MSVC_IDE)
  SET(CSharpBuildPath ${CSharpPath})
ENDIF (MSVC_IDE)
STRING(REGEX REPLACE "/" "\\\\" CSharpPath "${CSharpPath}")
STRING(REGEX REPLACE "/" "\\\\" CSharpBuildPath "${CSharpBuildPath}")

FILE(GLOB CSHARP_EXAMPLES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/" "${CMAKE_CURRENT_SOURCE_DIR}/*.in")
FOREACH(CSHARP_EXAMPLE ${CSHARP_EXAMPLES})
  STRING(REPLACE ".in" "" CSHARP_EXAMPLE_DEST ${CSHARP_EXAMPLE})
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/${CSHARP_EXAMPLE}"  "${CMAKE_CURRENT_BINARY_DIR}/${CSHARP_EXAMPLE_DEST}")
ENDFOREACH(CSHARP_EXAMPLE ${CSHARP_EXAMPLES})

FILE(GLOB CSHARP_EXAMPLES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/" "${CMAKE_CURRENT_SOURCE_DIR}/*.cs")
FOREACH(CSHARP_EXAMPLE ${CSHARP_EXAMPLES})
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/${CSHARP_EXAMPLE}"  "${CMAKE_CURRENT_BINARY_DIR}/${CSHARP_EXAMPLE}")
  STRING(REPLACE ".cs" "" CSHARP_EXAMPLE_DEST ${CSHARP_EXAMPLE})
  ADD_TEST ("csharp_${CSHARP_EXAMPLE}" csharp_test.bat ${CSHARP_EXAMPLE_DEST})
  SET_TESTS_PROPERTIES("csharp_${CSHARP_EXAMPLE}" PROPERTIES FAIL_REGULAR_EXPRESSION "Fail;Error")
ENDFOREACH(CSHARP_EXAMPLE ${CSHARP_EXAMPLES})
