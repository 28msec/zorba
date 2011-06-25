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
MACRO (DECLARE_ZORBA_MODULE MODULE_URI MODULE_VERSION MODULE_NAME)
 
  SET(SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}.xq")
  
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
    IF ("${final_comp}" MATCHES "\\.xq$")
      SET (module_filename "${final_comp}")
    ELSE ("${final_comp}" MATCHES "\\.xq$")
      SET (module_filename "${final_comp}.xq")
    ENDIF ("${final_comp}" MATCHES "\\.xq$")
  ENDIF (NOT final_comp)
  STRING (REPLACE ";" "/" module_path "${module_path}")
 
  STRING(REPLACE "/" "_" ZORBA_MODULE_PREFIX "${module_path}")
  
  # Compute a CMake-symbol-safe version of the target URI, for storing
  # things in CMake properties and declaring CMake targets.
  STRING (REGEX REPLACE "[/ ]" "_" uri_sym "${module_path}/${module_filename}")

  # Compute the version numbers.
  STRING (REPLACE "." ";" version "${MODULE_VERSION}")
  LIST (LENGTH version version_len)
  IF (NOT (version_len EQUAL 2) OR (version_len EQUAL 3))
    MESSAGE (FATAL_ERROR
      "Version ${MODULE_VERSION} not of form 'major.minor[.patch]'")
  ENDIF (NOT (version_len EQUAL 2) OR (version_len EQUAL 3))
  LIST (GET version 0 major_ver)
  LIST (GET version 1 minor_ver)
  IF (version_len EQUAL 3)
    LIST (GET version 2 patch_ver)
  ELSE (version_len EQUAL 3)
    SET (patch_ver 0)
  ENDIF (version_len EQUAL 3)

  # We maintain a global CMake property named after the target URI
  # which remembers all versions of this URI which have been
  # declared. If a *lower* version has already been declared, the
  # output file rules will be messed up, so die.
  GET_PROPERTY (target_versions GLOBAL PROPERTY "${uri_sym}-versions")
  MATH (EXPR version_int
    "${major_ver} * 100000000 + ${minor_ver} * 100000 + ${patch_ver}")
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

  # Now, deal with associated C++ source for external functions.

  IF(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}.xq.src/")
    # all the cpp files found in the ${MODULE_NAME}.xq.src
    # directory are added to the sources list
    SET (SRC_FILES)
    FILE(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
      "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}.xq.src/*.cpp")
    
    MESSAGE(STATUS "Add library " ${MODULE_NAME})
    FOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
      SET(SUFFIX)
      # simplestore executable doesn't need an extension
      IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
        SET(SUFFIX "_${ZORBA_STORE_NAME}")
      ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
  
#      IF(WIN32)
#        # configure_file doesn't replace variable with parameters; they
#        # have to be defined in the macro
#        SET(MODULE_VERSION ${MODULE_VERSION})
#        SET(MODULE_NAME ${MODULE_NAME})
#        # set the rc file for the windows dll version
#        CONFIGURE_FILE("${Zorba_CMAKE_MODULES_DIR}/Windows/WindowsDLLVersion.rc.in"
#                        "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}.xq.src/version.rc"
#                        @ONLY)                        
#        LIST(APPEND SRC_FILES 
#          "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}.xq.src/version.rc")
#      ENDIF(WIN32)

      # Shared libraries are considered RUNTIME targets on Win32
      # platforms and LIBRARY targets elsewhere
      IF (WIN32)
        SET (target_type RUNTIME)
      ELSE (WIN32)
        SET (target_type LIBRARY)
      ENDIF (WIN32)

      # Add the library target. Ensure that the output name is based on
      # the module *URI*'s final component.
      SET(MODULE_LIB_NAME "${ZORBA_MODULE_PREFIX}_${MODULE_NAME}${SUFFIX}")
      ADD_LIBRARY(${MODULE_LIB_NAME} SHARED ${SRC_FILES})
      GET_FILENAME_COMPONENT(module_filewe "${module_filename}" NAME_WE)
      SET_TARGET_PROPERTIES(${MODULE_LIB_NAME} PROPERTIES 
        OUTPUT_NAME "${module_filewe}${SUFFIX}"
        ${target_type}_OUTPUT_DIRECTORY
        "${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME}.xq.src")
      # It seems like it would be nice to set the VERSION and/or
      # SOVERSION target properties here. However: On Windows, it
      # doesn't seem to do anything (the .rc file configured above
      # embeds the version instead).  On the other hand, on Unix, it
      # changes the actual output target location to something like
      # "libext.so.2.0", which is difficult to transmogrify into the
      # target filename we actually want later. So in either case, the
      # target property isn't desirable.
      TARGET_LINK_LIBRARIES(${MODULE_LIB_NAME}
        zorba_${ZORBA_STORE_NAME} ${LINK_LIBRARIES})

#      IF (WIN32 AND MSVC_IDE)
#        # in VS, the dll's are generated in the $(ConfigurationName)
#        # directory, so we have to copy these dll's one level up in the
#        # ${CMAKE_CURRENT_BINARY_DIR} the commands below use VS macro
#        # expansions $(...)

#        # if we change something in the project generating this target, make
#        # sure we don't have a zombie DLL hanging around from an older build
#        #left in for ctest need to change testing macro to be able to remove this
#        ADD_CUSTOM_COMMAND(TARGET ${MODULE_LIB_NAME} PRE_BUILD COMMAND
#          if exist "\"$(ProjectDir)\\$(TargetFileName)\"" del "\"$(ProjectDir)\\$(TargetFileName)\"")
#        ADD_CUSTOM_COMMAND(TARGET ${MODULE_LIB_NAME} POST_BUILD COMMAND
#          copy "\"$(TargetPath)\"" "\"$(ProjectDir)\"")
#        #Copy file to the corresponding module path inside the build  
#        ADD_CUSTOM_COMMAND(TARGET ${MODULE_LIB_NAME} PRE_BUILD COMMAND
#          if exist "\"${output_dir}\\$(TargetFileName)\"" del "\"${output_dir}\\$(TargetFileName)\"")
#        ADD_CUSTOM_COMMAND(TARGET ${MODULE_LIB_NAME} POST_BUILD COMMAND
#          copy "\"$(TargetPath)\"" "\"${output_dir}\"")
#        #Copy a versioned file to the corresponding module path inside the build
#        ADD_CUSTOM_COMMAND(TARGET ${MODULE_LIB_NAME} PRE_BUILD COMMAND
#          if exist "\"${output_dir}\\$(TargetFileName).${MODULE_VERSION}\"" del "\"${output_dir}\\$(TargetFileName).${MODULE_VERSION}\"")  
#        ADD_CUSTOM_COMMAND(TARGET ${MODULE_LIB_NAME} POST_BUILD COMMAND
#          copy "\"${output_dir}\\$(TargetFileName)\""  "\"${output_dir}\\${MODULE_NAME}.${MODULE_VERSION}.dll\"")                   
#      ENDIF (WIN32 AND MSVC_IDE)
#        
    ENDFOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})   
   
  ENDIF(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}.xq.src/")


  # Done dealing with C++. Now, set up CMake custom commands which
  # will copy the module source file and dynamic library to each
  # target filename in the output directory.

  # Create the output directory for this module.
  SET (output_dir "${PROJECT_BINARY_DIR}/MODULE_PATH/${module_path}")
  FILE (MAKE_DIRECTORY "${output_dir}")

  SET (output_files)
  FOREACH (version_infix "" "${major_ver}" "${major_ver}.${minor_ver}"
      "${major_ver}.${minor_ver}.${patch_ver}")
    ADD_COPY_RULE ("${SOURCE_FILE}" "${output_dir}/${module_filename}"
      "${version_infix}" "${SOURCE_FILE}")
  ENDFOREACH (version_infix)
    
  # Also copy the dynamic library from the location it was built.
  # Because the dynamic library is only loaded after the .xq file, the
  # exact module version is known; thus only one copy needs to be
  # made.
  IF (MODULE_LIB_NAME)
    GET_TARGET_PROPERTY (lib_location "${MODULE_LIB_NAME}" LOCATION)
    GET_FILENAME_COMPONENT (lib_filename "${lib_location}" NAME)
    ADD_COPY_RULE ("${lib_location}" "${output_dir}/${lib_filename}"
      "${MODULE_VERSION}" "${MODULE_LIB_NAME}")
  ENDIF (MODULE_LIB_NAME)

  # Associate these custom commands with the "all" target via a custom
  # target. (I couldn't find any neater way to do this in CMake; you
  # can't directly add a dependency to "all".) Target needs to be
  # named uniquely, and cannot have slashes, so...
  ADD_CUSTOM_TARGET ("check_${uri_sym}_${MODULE_VERSION}" ALL
    DEPENDS ${output_files})


#  QQQ FILE(COPY ...) only exists in Cmake 2.8 :(
#  FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}
#        DESTINATION "${output_dir}/.."
#        FILES_MATCHING
#        PATTERN "*.xsd"
#        PATTERN "*.svn" EXCLUDE
#        PATTERN "*.xq.src" EXCLUDE)


   STRING(REPLACE "/" "_" ZORBA_OUTPUT_INSTALLED "${output_dir}_installed")
   GET_PROPERTY (is_installed GLOBAL PROPERTY ${ZORBA_OUTPUT_INSTALLED})
   IF(NOT is_installed)
    INSTALL(DIRECTORY ${PROJECT_BINARY_DIR}/modules
        DESTINATION "include/zorba/"
        FILES_MATCHING
        PATTERN "*.vc*" EXCLUDE
        PATTERN "*.cmake" EXCLUDE
        PATTERN "CMakeFiles" EXCLUDE
        PATTERN "*.dir" EXCLUDE
        PATTERN "Debug" EXCLUDE
        PATTERN "Release" EXCLUDE
        PATTERN "*")
    SET_PROPERTY(GLOBAL PROPERTY ${ZORBA_OUTPUT_INSTALLED} 1)
   ENDIF(NOT is_installed)

    
ENDMACRO (DECLARE_ZORBA_MODULE)

# Utility macro for setting up a build rule to copy a file to a particular
# versioned name.
MACRO (ADD_COPY_RULE INPUT_FILE OUTPUT_FILE VERSION_ARG DEPEND_TARGET)
  # Compute the modified output filename by inserting VERSION_ARG (if
  # non-empty) in front of its extension.
  GET_FILENAME_COMPONENT (_output_dir "${OUTPUT_FILE}" PATH)
  GET_FILENAME_COMPONENT (_output_filename "${OUTPUT_FILE}" NAME_WE)
  GET_FILENAME_COMPONENT (_output_ext "${OUTPUT_FILE}" EXT)
  IF (NOT "${VERSION_ARG}" STREQUAL "")
    SET (_output_file
      "${_output_dir}/${_output_filename}_${VERSION_ARG}${_output_ext}")
  ELSE (NOT "${VERSION_ARG}" STREQUAL "")
    SET (_output_file "${OUTPUT_FILE}")
  ENDIF (NOT "${VERSION_ARG}" STREQUAL "")
  
  # We maintain a global CMake property named after the target URI
  # which remembers all known output source files. If the output
  # file we just computed is already on that list, that means that a
  # module with the same URI but a higher version number has already
  # declared that output file, so we skip it now.
  GET_PROPERTY (target_files GLOBAL PROPERTY "${uri_sym}-output-files")
  LIST (FIND target_files "${_output_file}" file_found)
  IF (file_found EQUAL -1)
    LIST (APPEND output_files "${_output_file}")
    ADD_CUSTOM_COMMAND (OUTPUT "${_output_file}"
      COMMAND "${CMAKE_COMMAND}" -E copy_if_different
      "${INPUT_FILE}" "${_output_file}"
      DEPENDS "${DEPEND_TARGET}"
      COMMENT "Copying ${INPUT_FILE} to module directories" VERBATIM)
    SET_PROPERTY (GLOBAL APPEND PROPERTY "${uri_sym}-output-files"
      "${_output_file}")
  ENDIF (file_found EQUAL -1)
ENDMACRO (ADD_COPY_RULE)


# macro which should be used for generating module libraries.
# this macro will create a shared library in the (build) directory
# from which the macro was invoked. Also, it will generate
# an install command which installs the library in the corresponding
# module directory of the installation directory
MACRO (GENERATE_MODULE_LIBRARY MODULE_NAME LINK_LIBRARIES)

  # all the cpp files found in the ${MODULE_NAME}.xq.src
  # directory are added to the sources list
  FILE (GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}.xq.src/*.cpp")

  # only for smtp library set -Wno-write-strings in order to remove
  # the warning "deprecated conversion from string constant to char*".
  # we need to set it to both GNUCC and GNUCXX because of linkage.c
  # and c-client.h. QQQ this is a crappy solution - move it somehow to
  # the smtp module itself
  IF (${MODULE_NAME} STREQUAL "smtp")
    IF (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
      FOREACH (SMTP_SRC ${SRC_FILES})
        SET_SOURCE_FILES_PROPERTIES (${CMAKE_CURRENT_SOURCE_DIR}/smtp.xq.src/${SMTP_SRC} PROPERTIES COMPILE_FLAGS "-Wno-write-strings")
      ENDFOREACH (SMTP_SRC)
    ENDIF (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  ENDIF (${MODULE_NAME} STREQUAL "smtp")

  # Each library name is module name without ending prefixed by the
  # path of the module (slashes replaced by underscores)
  # E.g. 'com/zorba-xquery/www/modules/file.xq' -> com_zorba-xquery_www_modules_file
  # To compute this name, we need to know the root directory that the module
  # path is relative to. We will figure it out automatically if it is a
  # top-level directory named "src/" or "modules/"; otherwise,
  # set ZORBA_MODULE_ROOT_DIR prior to calling this macro.
  SET (ZORBA_MODULE_RELPATH)
  SET (possible_roots "${CMAKE_SOURCE_DIR}/modules" "${CMAKE_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/modules" "${PROJECT_SOURCE_DIR}/src")
  IF (ZORBA_MODULE_ROOT_DIR)
    LIST (APPEND possible_roots "${ZORBA_MODULE_ROOT_DIR}")
  ENDIF (ZORBA_MODULE_ROOT_DIR)
  FOREACH (root ${possible_roots})
    FILE (RELATIVE_PATH module_prefix "${root}" "${CMAKE_CURRENT_SOURCE_DIR}")
    IF (NOT module_prefix MATCHES "^\\.\\.")
      SET (ZORBA_MODULE_RELPATH ${module_prefix})
    ENDIF (NOT module_prefix MATCHES "^\\.\\.")
  ENDFOREACH (root)
  IF (NOT ZORBA_MODULE_RELPATH)
    MESSAGE (FATAL_ERROR "Unable to determine module root directory for "
      "${CMAKE_CURRENT_SOURCE_DIR}. Please set ZORBA_MODULE_ROOT_DIR.")
  ENDIF (NOT ZORBA_MODULE_RELPATH)
  STRING (REPLACE "/" "_" ZORBA_MODULE_PREFIX ${ZORBA_MODULE_RELPATH})

  MESSAGE (STATUS "Add library " ${MODULE_NAME})
  FOREACH (ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
    SET (SUFFIX)
    # simplestore executable doesn't need an extension
    IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
      SET (SUFFIX "_${ZORBA_STORE_NAME}")
    ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")

    SET (MODULE_LIB_NAME "${ZORBA_MODULE_PREFIX}_${MODULE_NAME}${SUFFIX}")
    ADD_LIBRARY (${MODULE_LIB_NAME} SHARED ${SRC_FILES})
    SET_TARGET_PROPERTIES (${MODULE_LIB_NAME} PROPERTIES 
      OUTPUT_NAME "${MODULE_NAME}${SUFFIX}")
    TARGET_LINK_LIBRARIES (${MODULE_LIB_NAME}
      zorba_${ZORBA_STORE_NAME} ${LINK_LIBRARIES})

#  MESSAGE (STATUS "----------------------------------------------${CMAKE_CURRENT_SOURCE_DIR}")
#  MESSAGE (STATUS "----------------------------------------------${CMAKE_CURRENT_BINARY_DIR}")
#  MESSAGE (STATUS "----------------------------------------------${SRC_FILES}")

#    # the shared libraries are considered RUNTIME on WIN32 platforms
#    # and LIBRARY on UNIX-based platforms
#    IF (WIN32)
##      SET_TARGET_PROPERTIES(${MODULE_LIB_NAME} PROPERTIES
##        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
#      # in VS, the dll's are generated in the $(ConfigurationName)
#      # directory, so we have to copy these dll's one level up in the
#      # ${CMAKE_CURRENT_BINARY_DIR} the commands below use VS macro
#      # expansions $(...)
##      IF (MSVC_IDE)
##        # if we change something in the project generating this target, make
##        # sure we don't have a zombie DLL hanging around from an older build
##        ADD_CUSTOM_COMMAND(TARGET ${MODULE_LIB_NAME} PRE_BUILD COMMAND
##          if exist "\"$(ProjectDir)\\$(TargetFileName)\"" del "\"$(ProjectDir)\\$(TargetFileName)\"")
##        ADD_CUSTOM_COMMAND(TARGET ${MODULE_LIB_NAME} POST_BUILD COMMAND
##          copy "\"$(TargetPath)\"" "\"$(ProjectDir)\"")
##      ENDIF (MSVC_IDE)
#    ELSE (WIN32)
#      SET_TARGET_PROPERTIES(${MODULE_LIB_NAME} PROPERTIES
#        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
#    ENDIF (WIN32)

    # QQQ This should be the *module* version, not the Zorba version!
    SET_TARGET_PROPERTIES (${MODULE_LIB_NAME} PROPERTIES
      VERSION ${ZORBA_VERSION}
      CLEAN_DIRECT_OUTPUT 0)
  ENDFOREACH (ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})

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

# Adds a test to the project.
#
# Syntax:
#
#   ZORBA_ADD_TEST_SIMPLE(NAME TARGET ...) 
#   
#     NAME - the name of the added test
#     TARGET - target that will be executed when the test is run
#     ... - arguments that will be passed to the target
#
MACRO (ZORBA_ADD_TEST_SIMPLE NAME TARGET ...)
  SET (ARGS ${ARGV2} ${ARGN})

  GET_TARGET_PROPERTY (TARGET_LOCATION "${TARGET}" LOCATION)
  IF (WIN32)
    IF (MSVC_IDE)
      STRING (REPLACE "/${CMAKE_CFG_INTDIR}" "" TARGET_LOCATION ${TARGET_LOCATION})
    ENDIF (MSVC_IDE)
    STRING (REPLACE ".exe" ".bat" TARGET_LOCATION ${TARGET_LOCATION})
  ELSE(WIN32)
    # if building the static library, always use the static executables for testing
    IF (ZORBA_BUILD_STATIC_LIBRARY)
      SET(TARGET_LOCATION "${TARGET_LOCATION}_static")
    ENDIF (ZORBA_BUILD_STATIC_LIBRARY)
  ENDIF(WIN32)

  ADD_TEST ("${NAME}" "${TARGET_LOCATION}" ${ARGS})
  SET_TESTS_PROPERTIES ("${NAME}" PROPERTIES TIMEOUT "${NORMAL_TIMEOUT_VALUE}")
  GET_PROPERTY (TEST_EXTRAPROPS GLOBAL PROPERTY "EXTRAPROPS-${NAME}")
  IF (TEST_EXTRAPROPS)
    MESSAGE (STATUS "using additional properties for ${NAME}: [${TEST_EXTRAPROPS}]")
    SET_TESTS_PROPERTIES ("${NAME}" PROPERTIES ${TEST_EXTRAPROPS})
  ENDIF (TEST_EXTRAPROPS)
ENDMACRO (ZORBA_ADD_TEST_SIMPLE)

# This macro easies the process of adding test for store dependent executables 
# (e.g. if the rbkt tests must be added for the executables testdriver and testdriver_firststore). 
# It adds one test for each store registered. It has the same naming convection for the target as 
# the macro that is used to generated store dependent executables (thus, 
# 'testdriver' must be passed as TARGET if the test should be executed with the executables
# testdriver and testdriver_firststore).
#
# Syntax:
#
#   ZORBA_ADD_TEST_SIMPLE(NAME TARGET ...) 
#   
#     NAME - the name of the added test
#     TARGET - target that will be executed when the test is run. For each registered store, 
#              a suffix will be added to the target 
#              (similar convention than in ZORBA_GENERATE_STORE_SPECIFIC_EXES)
#     ... - arguments that will be passed to the target
#
MACRO(ZORBA_ADD_TEST_ALLSTORES NAME TARGET ...)
  SET(ARGS ${ARGV2} ${ARGN})
  FOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
    # simplestore executable doesn't need an extension
    SET(SUFFIX)
    IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
      SET(SUFFIX "_${ZORBA_STORE_NAME}")
    ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")

    ZORBA_ADD_TEST_SIMPLE("${NAME}${SUFFIX}" "${TARGET}${SUFFIX}" ${ARGS})
  ENDFOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
ENDMACRO(ZORBA_ADD_TEST_ALLSTORES)

# This macro can be used to set a property to each test generated by the macro ZORBA_ADD_TEST_ALLSTORES.
#
# Syntax:
#
#   ZORBA_SET_TEST_PROPERTY_ALLSTORES(NAME PROPERTY VALUE) 
#   
#     PROPERTY - property
#     VALUE - value of property
#
MACRO(ZORBA_SET_TEST_PROPERTY_ALLSTORES NAME PROPERTY VALUE)
  FOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
    # simplestore executable doesn't need an extension
    SET(SUFFIX)
    IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
      SET(SUFFIX "_${ZORBA_STORE_NAME}")
    ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
    SET_TESTS_PROPERTIES ("${NAME}${SUFFIX}" PROPERTIES ${PROPERTY} "${VALUE}")
  ENDFOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
ENDMACRO(ZORBA_SET_TEST_PROPERTY_ALLSTORES)





#macro to add the xqdoc generation targets for a module
#call this macro from inside the CMakeLists.txt from the root of that external module
#it uses some variables that may be set before in zorba, if the external module is compiled inside zorba
#if the external module is not compiled in zorba, it will set the variables to point to executables and files in the installed zorba
#if you want to use the files from your local zorba build, you have to set the variables manually
#the variables are:
# ZORBA_XQDOC_MAIN_EXTMODULES_XML_XQ - points to file xqdoc-main-extmodules-xml.xq
# ZORBA_XQDOC_MAIN_EXTMODULES_HTML_XQ - points to file xqdoc-main-extmodules-html.xq
# ZORBA_EXTMODULE_XQDOC_OUTPUT_DIR - points to the output dir for xml and html
# ZORBA_XHTML_REQUISITES_PATH - points to the dir containing the html requisites (images, lib, styles, templates dirs)
# ZORBA_EXE_SCRIPT - points to zorba.exe (or zorba.bat)
MACRO (ADD_XQDOC_TARGETS)
  
  MESSAGE(STATUS "ADD_XQDOC_TARGETS for project ${PROJECT_NAME}")

  # Add the xqdoc command for which a working zorba cmd is required.
  SET(ZORBA_EXE_SCRIPT  ${Zorba_DIR}/bin/zorba CACHE PATH "Path to installed zorba.exe")
 
  FILE(GLOB_RECURSE LOCAL_MODULES  ${PROJECT_SOURCE_DIR}/src/*.xq)
  SET(ZORBA_XQDOC_MAIN_EXTMODULES_XML_XQ  ${Zorba_DIR}/xqdoc/generator/xqdoc-main-extmodules-xml.xq CACHE PATH "The xqdoc xml generator for external modules")
  SET(ZORBA_XQDOC_MAIN_EXTMODULES_HTML_XQ  ${Zorba_DIR}/xqdoc/generator/xqdoc-main-extmodules-html.xq CACHE PATH "The xqdoc html generator for external modules")
  SET(ZORBA_EXTMODULE_XQDOC_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR} CACHE PATH "Dir where to store xqdoc generated files, xml and html")
  ADD_CUSTOM_TARGET(xqdoc-xml-${PROJECT_NAME}
    ${ZORBA_EXE_SCRIPT}
      --omit-xml-declaration
      -f
      -q "${ZORBA_XQDOC_MAIN_EXTMODULES_XML_XQ}"
      -e "\"modulePath:=${PROJECT_SOURCE_DIR}/src\""
      -e "\"xqdocBuildPath:=${ZORBA_EXTMODULE_XQDOC_OUTPUT_DIR}\""
      DEPENDS ${LOCAL_MODULES}
      COMMENT "Building XQDoc XML documentation for ${PROJECT_NAME} module..."
  )
  #SET_TARGET_PROPERTIES(xqdoc-xml-${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)
  IF(TARGET xqdoc-xml)
    ADD_DEPENDENCIES(xqdoc-xml-${PROJECT_NAME} zorba_simplestore)
    ADD_DEPENDENCIES(xqdoc-xml-${PROJECT_NAME} xqdoc-xml)
    ADD_DEPENDENCIES(xqdoc xqdoc-xml-${PROJECT_NAME})
  ENDIF(TARGET xqdoc-xml)

  SET(ZORBA_XHTML_REQUISITES_PATH ${Zorba_DIR}/xqdoc/requisites CACHE PATH "Dir where to the html requisites are stored")
  ADD_CUSTOM_TARGET(xqdoc-${PROJECT_NAME}
    ${ZORBA_EXE_SCRIPT}
      --omit-xml-declaration
      -f
      -q "${ZORBA_XQDOC_MAIN_EXTMODULES_HTML_XQ}"
      -e "\"modulePath:=${PROJECT_SOURCE_DIR}/src\""
      -e "\"xhtmlRequisitesPath:=${ZORBA_XHTML_REQUISITES_PATH}\""
      -e "\"xqdocBuildPath:=${ZORBA_EXTMODULE_XQDOC_OUTPUT_DIR}\""
      -e "\"examplePath:=${Zorba_DIR}/..\""
      -e "\"zorbaVersion:=${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}\""
      COMMENT "Building XQDoc documentation for the ${PROJECT_NAME} module ..."
  )
  ADD_DEPENDENCIES(xqdoc-${PROJECT_NAME} xqdoc-xml-${PROJECT_NAME})
  SET_TARGET_PROPERTIES(xqdoc-${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

ENDMACRO(ADD_XQDOC_TARGETS)

#macro to be called from CMakeLists.txt in the root of external module
#should be called by all external modules that comply with this build system
MACRO (SETUP_EXTERNAL_MODULE)
 ADD_XQDOC_TARGETS()
ENDMACRO(SETUP_EXTERNAL_MODULE)
