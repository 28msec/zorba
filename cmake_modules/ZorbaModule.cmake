# Copyright 2006-2010 The FLWOR Foundation.
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

# macro which should be used for generating module libraries.
# this macro will create a shared library in the (build) directory
# from which the macro was invoked. Also, it will generate
# an install command which installs the library in the corresponding
# module directory of the installation directory
MACRO(GENERATE_MODULE_LIBRARY MODULE_NAME LINK_LIBRARIES)

  # all the cpp files found in the ${MODULE_NAME}.xq.src
  # directory are added to the sources list
  FILE(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}.xq.src/*.cpp")

  # only for smtp library set -Wno-write-strings in order to remove
  # the warning "deprecated conversion from string constant to char*".
  # we need to set it to both GNUCC and GNUCXX because of linkage.c
  # and c-client.h. QQQ this is a crappy solution - move it somehow to
  # the smtp module itself
  IF(${MODULE_NAME} STREQUAL "smtp")
    IF (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
      FOREACH(SMTP_SRC ${SRC_FILES})
        SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/smtp.xq.src/${SMTP_SRC} PROPERTIES COMPILE_FLAGS "-Wno-write-strings")
      ENDFOREACH(SMTP_SRC)
    ENDIF (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  ENDIF(${MODULE_NAME} STREQUAL "smtp")

  # Each library name is module name without ending prefixed by the
  # path of the module (slashes replaced by underscores)
  # E.g. 'com/zorba-xquery/www/modules/file.xq' ->
  # com_zorba-xquery_www_modules_file.  To compute this name, we need
  # to know the root directory that the module path is relative to. We
  # will figure it out automatically if it is a top-level directory
  # named "src/" or "modules/"; otherwise, set ZORBA_MODULE_ROOT_DIR
  # prior to calling this macro.
  SET(ZORBA_MODULE_RELPATH)
  SET(possible_roots "${CMAKE_SOURCE_DIR}/modules" "${CMAKE_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/modules" "${PROJECT_SOURCE_DIR}/src")
  IF (ZORBA_MODULE_ROOT_DIR)
    LIST(APPEND possible_roots "${ZORBA_MODULE_ROOT_DIR}")
  ENDIF (ZORBA_MODULE_ROOT_DIR)
  FOREACH (root ${possible_roots})
    FILE(RELATIVE_PATH module_prefix "${root}" "${CMAKE_CURRENT_SOURCE_DIR}")
    IF(NOT module_prefix MATCHES "^\\.\\.")
      SET(ZORBA_MODULE_RELPATH ${module_prefix})
    ENDIF(NOT module_prefix MATCHES "^\\.\\.")
  ENDFOREACH(root)
  IF(NOT ZORBA_MODULE_RELPATH)
    MESSAGE(FATAL_ERROR "Unable to determine module root directory for "
      "${CMAKE_CURRENT_SOURCE_DIR}. Please set ZORBA_MODULE_ROOT_DIR.")
  ENDIF(NOT ZORBA_MODULE_RELPATH)
  STRING(REPLACE "/" "_" ZORBA_MODULE_PREFIX ${ZORBA_MODULE_RELPATH})

  MESSAGE(STATUS "Add library " ${MODULE_NAME})
  FOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
    SET(SUFFIX)
    # simplestore executable doesn't need an extension
    IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
      SET(SUFFIX "_${ZORBA_STORE_NAME}")
    ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")

    SET(MODULE_LIB_NAME "${ZORBA_MODULE_PREFIX}_${MODULE_NAME}${SUFFIX}")
    ADD_LIBRARY(${MODULE_LIB_NAME} SHARED ${SRC_FILES})
    SET_TARGET_PROPERTIES(${MODULE_LIB_NAME} PROPERTIES 
      OUTPUT_NAME "${MODULE_NAME}${SUFFIX}")
    TARGET_LINK_LIBRARIES(${MODULE_LIB_NAME}
      zorba_${ZORBA_STORE_NAME} ${LINK_LIBRARIES})

    # the shared libraries are considered RUNTIME on WIN32 platforms
    # and LIBRARY on UNIX-based platforms
    IF (WIN32)
      SET_TARGET_PROPERTIES(${MODULE_LIB_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
      # in VS, the dll's are generated in the $(ConfigurationName)
      # directory, so we have to copy these dll's one level up in the
      # ${CMAKE_CURRENT_BINARY_DIR} the commands below use VS macro
      # expansions $(...)
      IF (MSVC_IDE)
        # if we change something in the project generating this target, make
        # sure we don't have a zombie DLL hanging around from an older build
        ADD_CUSTOM_COMMAND(TARGET ${MODULE_LIB_NAME} PRE_BUILD COMMAND
          if exist "\"$(ProjectDir)\\$(TargetFileName)\"" del "\"$(ProjectDir)\\$(TargetFileName)\"")
        ADD_CUSTOM_COMMAND(TARGET ${MODULE_LIB_NAME} POST_BUILD COMMAND
          copy "\"$(TargetPath)\"" "\"$(ProjectDir)\"")
      ENDIF (MSVC_IDE)
    ELSE (WIN32)
      SET_TARGET_PROPERTIES(${MODULE_LIB_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
    ENDIF (WIN32)
    # QQQ This should be the *module* version, not the Zorba version!
    SET_TARGET_PROPERTIES(${MODULE_LIB_NAME} PROPERTIES
      VERSION ${ZORBA_VERSION}
      CLEAN_DIRECT_OUTPUT 0)
  ENDFOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})

  # install to include/zorba/modules/com/zorba-xquery/www/modules
  # (simplestore libs only).  the include/zorba/modules directory
  # needs to belong to the set of Zorba Module Paths. QQQ installing
  # shared libraries to the *include* directory?!
  IF (WIN32)
    INSTALL(TARGETS "${ZORBA_MODULE_PREFIX}_${MODULE_NAME}"
            RUNTIME
            DESTINATION "include/zorba/modules/${ZORBA_MODULE_RELPATH}")
  ELSE (WIN32)
    INSTALL(TARGETS "${ZORBA_MODULE_PREFIX}_${MODULE_NAME}"
            LIBRARY
            DESTINATION "include/zorba/modules/${ZORBA_MODULE_RELPATH}")
  ENDIF (WIN32)
ENDMACRO(GENERATE_MODULE_LIBRARY)


# Convenience macro for adding tests in a standard format. QQQ doc!
MACRO(ADD_TEST_DIRECTORY TEST_DIR)
  # QQQ error-check: Queries directory exists, some tests found...
  FILE(GLOB_RECURSE TESTFILES FOLLOW_SYMLINKS 
    RELATIVE "${TEST_DIR}/Queries" "${TEST_DIR}/Queries/*.xq")
  SET(TESTCOUNTER 0)
  FOREACH(TESTFILE ${TESTFILES})
    SET(TESTNAME "${PROJECT_NAME}/${TESTFILE}")

    IF(WIN32)
      SET(PATH_SEP ";")
    ELSE(WIN32)
      SET(PATH_SEP ":")
    ENDIF(WIN32)
    ADD_TEST(${TESTNAME} "${Zorba_TESTDRIVER}"
      --rbkt-src "${TEST_DIR}"
      --module-path "${PROJECT_SOURCE_DIR}/src/${PATH_SEP}${PROJECT_BINARY_DIR}/src/${PATH_SEP}${SECONDARY_MODULE_PATHS}"
      "${TESTFILE}")
      
    MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
    MATH(EXPR TESTMOD "${TESTCOUNTER}%100")
    IF (${TESTMOD} EQUAL 0)
      MESSAGE(STATUS "Adding another 100 Tests")
    ENDIF (${TESTMOD} EQUAL 0)
  ENDFOREACH(TESTFILE)
  MESSAGE(STATUS "Added ${TESTCOUNTER} tests in ${TEST_DIR}")
ENDMACRO(ADD_TEST_DIRECTORY)

# Convenience Macro for Setting up configure files for it to be
# exported as a secondary Module Dependency
MACRO(SET_EXTERNAL_MODULE_CONFIG)
CONFIGURE_FILE("${Zorba_EXTERNALMODULECONFIG_FILE}"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake" @ONLY)
ENDMACRO(SET_EXTERNAL_MODULE_CONFIG)