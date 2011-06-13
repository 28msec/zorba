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

# Macro which declares a module. This sets up the installation of the
# module, including creating the correct paths for module versioning.
#
# QQQ either this should subsume GENERATE_MODULE_LIBRARY entirely, or
# else the latter should be changed to more closely match this.
#
# QQQ this currently doesn't support modules with multiple component
# .xq files. (Neither does Zorba's automatic loading mechanism, so
# this probably isn't a huge deal, but worth thinking about.)
#
# QQQ might it be possible / reasonable to attempt to parse the source
# file enough to deduce the URI and version?
MACRO (DECLARE_ZORBA_MODULE MODULE_URI MODULE_VERSION SOURCE_FILE)

  # Mangle the module URI into Zorba's filesystem form - namely:
  # 1. Drop the scheme: (and // if present)
  # 2. Reverse the authority (host) on dots, then split on dots into subdirs
  # 3. If the final component ends in /, append "index.xq"; else if it
  #    doesn't end in .xq, append ".xq"
  STRING (REGEX REPLACE "^[^:]+:(//)?" "" module_path ${MODULE_URI})
  STRING (REPLACE "/" ";" module_path ${module_path})
  LIST (GET module_path 0 authority)
  LIST (REMOVE_AT module_path 0)
  STRING (REPLACE "." ";" authority "${authority}")
  LIST (REVERSE authority)
  LIST (INSERT module_path 0 ${authority})
  LIST (GET module_path -1 final_comp)
  LIST (REMOVE_AT module_path -1)
  IF (NOT final_comp)
    SET (module_filename "index.xq")
  ELSE (NOT final_comp)
    SET (module_filename "${final_comp}.xq")
  ENDIF (NOT final_comp)
  STRING (REPLACE ";" "/" module_path "${module_path}")

  # Compute a CMake-symbol-safe version of the target URI, for storing
  # things in CMake properties and declaring CMake targets.
  STRING (REGEX REPLACE "[/ ]" "_" uri_sym "${module_path}/${module_filename}")

  # Compute the version numbers.
  STRING (REPLACE "." ";" version "${MODULE_VERSION}")
  LIST (LENGTH version version_len)
  IF (NOT version_len EQUAL 2)
    MESSAGE (FATAL_ERROR "Version ${MODULE_VERSION} not of form 'major.minor'")
  ENDIF (NOT version_len EQUAL 2)
  LIST (GET version 0 major_ver)
  LIST (GET version 1 minor_ver)

  # We maintain a global CMake property named after the target URI
  # which remembers all versions of this URI which have been
  # declared. If a *lower* version has already been declared, the
  # output file rules will be messed up, so die.
  GET_PROPERTY (target_versions GLOBAL PROPERTY "${uri_sym}-versions")
  MATH (EXPR version_int "${major_ver} * 100000 + ${minor_ver}")
  FOREACH (known_ver ${target_versions})
    IF (known_ver LESS version_int)
      MESSAGE (FATAL_ERROR
        "The module ${MODULE_URI} has already been declared with a "
        "lower version number than ${MODULE_VERSION}. "
        "Please call DECLARE_ZORBA_MODULE() for higher versions of the same "
        "module first.")
    ENDIF (known_ver LESS version_int)
  ENDFOREACH (known_ver)
  SET_PROPERTY (GLOBAL APPEND PROPERTY "${uri_sym}-versions" ${version_int})

  # Create the output directory.
  SET (output_dir "${PROJECT_BINARY_DIR}/modules/${module_path}")
  FILE (MAKE_DIRECTORY "${output_dir}")

  # Install CMake custom commands which will copy the module source
  # file to each target filename in the output directory.
  SET (output_files)
  FILE (RELATIVE_PATH rel_source "${PROJECT_SOURCE_DIR}" "${SOURCE_FILE}")
  FOREACH (version_ext "" ".${major_ver}" ".${major_ver}.${minor_ver}")
    SET (output_file "${output_dir}/${module_filename}${version_ext}")

    # We maintain a global CMake property named after the target URI
    # which remembers all known output files. If the output file we
    # just computed is already on that list, that means that a module
    # with the same URI but a higher version number has already
    # declared that output file, so we skip it now.
    GET_PROPERTY (target_files GLOBAL PROPERTY "${uri_sym}-output-files")
    LIST (FIND target_files "${output_file}" file_found)
    IF (file_found EQUAL -1)
      LIST (APPEND output_files "${output_file}")
      ADD_CUSTOM_COMMAND (OUTPUT "${output_file}"
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${SOURCE_FILE}" "${output_file}"
        DEPENDS "${SOURCE_FILE}"
        COMMENT "Copying ${rel_source} to module directories" VERBATIM)
      SET_PROPERTY (GLOBAL APPEND PROPERTY "${uri_sym}-output-files"
        "${output_file}")
    ENDIF (file_found EQUAL -1)
  ENDFOREACH (version_ext)

  # Associate these custom commands with the "all" target via a custom
  # target. (I couldn't find any neater way to do this in CMake; you
  # can't directly add a dependency to "all".) Target needs to be
  # named uniquely, and cannot have slashes, so...
  ADD_CUSTOM_TARGET ("check_${uri_sym}_${MODULE_VERSION}" ALL
    DEPENDS ${output_files})
ENDMACRO (DECLARE_ZORBA_MODULE)

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

# Initialize output file when first included
set (expected_failures_file "${CMAKE_BINARY_DIR}/ExpectedFailures.xml")
GET_PROPERTY (is_init GLOBAL PROPERTY expected_failures_initialized)
IF (NOT is_init)
  file (WRITE "${expected_failures_file}" "")
  SET_PROPERTY (GLOBAL PROPERTY expected_failures_initialized 1)
ENDIF (NOT is_init)

# The expected_failure() function is used to mark a test which is currently
# failing, but is being worked on.
#
# Usage: expected_failure (testname bugid)
#  where "testname" is the full test name and "bugid" is the Sourceforge
#  Tracker artifact ID.
MACRO(expected_failure testname bugid)
  # The meat: flip the "will_fail" flag
  get_test_property ("${testname}" WILL_FAIL willfail)
  if (willfail)
    set (willfail 0)
  else (willfail)
    set (willfail 1)
  endif (willfail)

  FOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
    # simplestore executable doesn't need an extension
    SET(SUFFIX)
    IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
      SET(SUFFIX "_${ZORBA_STORE_NAME}")
    ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")

    set_tests_properties ("${testname}${SUFFIX}"
      PROPERTIES WILL_FAIL ${willfail})

    # Also store the name and bug ID of this test in our output file
    file (APPEND "${expected_failures_file}"
      "<Test name=\"${testname}${SUFFIX}\" bug=\"${bugid}\"/>")
  ENDFOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})

ENDMACRO(expected_failure)




# Convenience macro for adding tests in a standard format. QQQ doc!
MACRO(ADD_TEST_DIRECTORY TEST_DIR)
  # QQQ error-check: Queries directory exists, some tests found...
  FILE(GLOB_RECURSE TESTFILES FOLLOW_SYMLINKS 
    RELATIVE "${TEST_DIR}/Queries" "${TEST_DIR}/Queries/*.xq")
  SET(TESTCOUNTER 0)
  FOREACH(TESTFILE ${TESTFILES})
    SET(TESTNAME "${PROJECT_NAME}/${TESTFILE}")

    IF(WIN32)
      SET(PATH_SEP ",")
    ELSE(WIN32)
      SET(PATH_SEP ":")
    ENDIF(WIN32)
    ZORBA_ADD_TEST_ALLSTORES(${TESTNAME} testdriver
      "--rbkt-src" "${TEST_DIR}"
      "--module-path" "${PROJECT_SOURCE_DIR}/src/${PATH_SEP}${PROJECT_BINARY_DIR}/src/${PATH_SEP}${SECONDARY_MODULE_PATHS}"
      "${TESTFILE}")
      
    MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
    MATH(EXPR TESTMOD "${TESTCOUNTER}%100")
    IF (${TESTMOD} EQUAL 0)
      MESSAGE(STATUS "Adding another 100 Tests")
    ENDIF (${TESTMOD} EQUAL 0)
  ENDFOREACH(TESTFILE)
  MESSAGE(STATUS "Added ${TESTCOUNTER} tests in ${TEST_DIR}")
ENDMACRO(ADD_TEST_DIRECTORY)

# Macro to install a basic CMake config file for a module. Provide a
# source and binary directory. Result will be installed in binary
# directory. This is a macro because it is called from two different
# places: ZorbaUse.cmake, and Zorba's modules/CMakeLists.txt.
MACRO(CREATE_MODULE_CONFIG name src_dir bin_dir)
  # Set variables referenced in ExternalModuleConfig.cmake.in
  SET(MODULE_SOURCE_DIR ${src_dir})
  SET(MODULE_BINARY_DIR ${bin_dir})
  CONFIGURE_FILE("${Zorba_EXTERNALMODULECONFIG_FILE}"
    "${MODULE_BINARY_DIR}/${name}Config.cmake" @ONLY)
ENDMACRO(CREATE_MODULE_CONFIG)