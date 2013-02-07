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

IF (WIN32)
  FIND_PACKAGE ( CSharp )
  MESSAGE(STATUS "SWIG: Generating C# API")
  SET_SOURCE_FILES_PROPERTIES(zorba_api.i PROPERTIES CPLUSPLUS ON)
# csc /out:test01.exe /reference:..\zorba_csharp.dll test01.cs
  SET(CMAKE_SWIG_FLAGS -namespace org.zorbaxquery.api)
  SWIG_ADD_MODULE(zorba_api_csharp csharp zorba_api.i)
  SWIG_LINK_LIBRARIES(zorba_api_csharp zorba_simplestore )
  SET_TARGET_PROPERTIES (zorba_api_csharp PROPERTIES OUTPUT_NAME "zorba_api")
  SET_TARGET_PROPERTIES( zorba_api_csharp PROPERTIES PROJECT_LABEL "CSharp" FOLDER "APIs")

  ADD_CUSTOM_COMMAND(TARGET zorba_api_csharp
                 POST_BUILD
                 COMMAND cmake -E echo "Compiling C# files..."
                 COMMAND ${csc_EXECUTABLE} /platform:x86 /target:library /out:${CMAKE_CURRENT_BINARY_DIR}\\zorba_csharp.dll ${CMAKE_CURRENT_BINARY_DIR}\\*.cs 
  )
  

  FILE(GLOB ZORBA_API_HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/../" "${CMAKE_CURRENT_SOURCE_DIR}/../*.h")
  FOREACH(ZORBA_API_HEADER ${ZORBA_API_HEADERS})
    CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../${ZORBA_API_HEADER}"  "${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_API_HEADER}")
  ENDFOREACH(ZORBA_API_HEADER ${ZORBA_API_HEADERS})

  IF (MSVC_IDE)
    INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/zorba_api.dll 
    DESTINATION share/csharp
    COMPONENT csharp_swig)
  ELSE (MSVC_IDE)
    INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.dll 
    DESTINATION share/csharp
    COMPONENT csharp_swig)
  ENDIF (MSVC_IDE)
  
  INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_csharp.dll 
  DESTINATION share/csharp
  COMPONENT csharp_swig)

  ADD_SUBDIRECTORY (tests) 
  
ELSEIF (WIN32)
  MESSAGE(STATUS "SWIG C#: binding not yet supported on this platform.")
ENDIF (WIN32)
