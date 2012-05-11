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
IF(APPLE)
CMAKE_FIND_FRAMEWORKS ( Ruby )
ENDIF(APPLE)
FIND_PACKAGE(Ruby)

IF (RUBY_LIBRARY AND RUBY_INCLUDE_PATH)
  MESSAGE(STATUS "SWIG Ruby: generating Ruby API")
  SET_SOURCE_FILES_PROPERTIES(zorba_api.i PROPERTIES CPLUSPLUS ON)
  INCLUDE_DIRECTORIES(${RUBY_INCLUDE_PATH})
  IF (WIN32)
    SWIG_ADD_MODULE(zorba_api_ruby ruby zorba_api.i)
    SWIG_LINK_LIBRARIES(zorba_api_ruby zorba_simplestore ${RUBY_LIBRARY})
    SET_TARGET_PROPERTIES( zorba_api_ruby PROPERTIES OUTPUT_NAME "zorba_api")
    SET_TARGET_PROPERTIES( zorba_api_ruby PROPERTIES PROJECT_LABEL "Api_Ruby" )
    SET_TARGET_PROPERTIES( zorba_api_ruby PROPERTIES SUFFIX ".so" )
  ELSE (WIN32)
    SWIG_ADD_MODULE(zorba_api ruby zorba_api.i)
    SWIG_LINK_LIBRARIES(zorba_api zorba_simplestore ${RUBY_LIBRARY})
    # Necessary because UseSWIG.cmake uses ADD_LIBRARY(..MODULE..), which
    # apparently doesn't allow CMake's RPATH-rewriting magic to work.
    GET_TARGET_PROPERTY(_rpath zorba_simplestore LOCATION)
    GET_FILENAME_COMPONENT(_rpath "${_rpath}" PATH)
    SET_TARGET_PROPERTIES(zorba_api PROPERTIES
      INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:${_rpath}"
      BUILD_WITH_INSTALL_RPATH ON)
  ENDIF (WIN32)

  IF ( APPLE )
    set_target_properties( zorba_api PROPERTIES SUFFIX .bundle )
  ENDIF ( APPLE )

  # The following fix was added because of the changes in CMake 2.8, which have the
  # result of naming the java binding library "liblibzorba_api.so" instead of "libzorba_api.so"
  IF ( LINUX OR CYGWIN )
    SET_TARGET_PROPERTIES( ${SWIG_MODULE_zorba_api_REAL_NAME} PROPERTIES PREFIX "" )
  ENDIF ( LINUX OR CYGWIN )

  EXECUTE_PROCESS(COMMAND ${RUBY_EXECUTABLE} -r rbconfig -e "print Config::CONFIG['sitearchdir']"
    OUTPUT_VARIABLE RUBY_SITEARCH_DIR)
  #STRING(REPLACE "/usr/" "" RUBY_SITEARCH_DIR "${RUBY_SITEARCH_DIR}" )
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../StaticContext.h" "${CMAKE_CURRENT_BINARY_DIR}/StaticContext.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../ItemFactory.h" "${CMAKE_CURRENT_BINARY_DIR}/ItemFactory.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Item.h" "${CMAKE_CURRENT_BINARY_DIR}/Item.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Iterator.h" "${CMAKE_CURRENT_BINARY_DIR}/Iterator.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../XQuery.h" "${CMAKE_CURRENT_BINARY_DIR}/XQuery.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../DynamicContext.h" "${CMAKE_CURRENT_BINARY_DIR}/DynamicContext.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../XmlDataManager.h" "${CMAKE_CURRENT_BINARY_DIR}/XmlDataManager.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../TypeIdentifier.h" "${CMAKE_CURRENT_BINARY_DIR}/TypeIdentifier.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../SerializationOptions.h" "${CMAKE_CURRENT_BINARY_DIR}/SerializationOptions.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Collection.h" "${CMAKE_CURRENT_BINARY_DIR}/Collection.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../CollectionManager.h" "${CMAKE_CURRENT_BINARY_DIR}/CollectionManager.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../StaticCollectionManager.h" "${CMAKE_CURRENT_BINARY_DIR}/StaticCollectionManager.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../DocumentManager.h" "${CMAKE_CURRENT_BINARY_DIR}/DocumentManager.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../ItemSequence.h" "${CMAKE_CURRENT_BINARY_DIR}/ItemSequence.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Zorba.h" "${CMAKE_CURRENT_BINARY_DIR}/Zorba.h" COPYONLY)

  SET (RUBY_SITEARCH_DIR "${CMAKE_INSTALL_PREFIX}/share/ruby")
  
  IF ( APPLE )
    INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_SWIG_LIB_PREFIX}zorba_api.bundle
    DESTINATION ${RUBY_SITEARCH_DIR} )
  ELSE ( APPLE )
    IF ( LINUX )
      INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.so
      DESTINATION ${RUBY_SITEARCH_DIR}
      COMPONENT ruby_swig )
    ELSE ( LINUX )
      IF (MSVC_IDE)
        INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/zorba_api.dll
        DESTINATION share/ruby
        COMPONENT ruby_swig )
      ELSE (MSVC_IDE)
        INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.dll
        DESTINATION share/ruby
        COMPONENT ruby_swig )
      ENDIF (MSVC_IDE)
      
    ENDIF ( LINUX )
  ENDIF ( APPLE )

  ADD_SUBDIRECTORY (tests)

ELSE (RUBY_LIBRARY AND RUBY_INCLUDE_PATH)
  MESSAGE(STATUS "SWIG Ruby: binding not generated because library and include files are not installed.")
ENDIF (RUBY_LIBRARY AND RUBY_INCLUDE_PATH)
