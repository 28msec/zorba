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

# Utility macro to parse CMake-style argument lists
MACRO(PARSE_ARGUMENTS prefix arg_names onearg_names option_names)
  SET(DEFAULT_ARGS)
  FOREACH(arg_name ${arg_names})
    SET(${prefix}_${arg_name})
  ENDFOREACH(arg_name)
  FOREACH(option ${option_names})
    SET(${prefix}_${option} FALSE)
  ENDFOREACH(option)

  SET(current_arg_name DEFAULT_ARGS)
  SET(current_arg_list)
  SET(current_arg_is_singular)
  SET(larg_names ${arg_names})
  SET(lonearg_names ${onearg_names})
  SET(loption_names ${option_names})
  FOREACH(arg ${ARGN})
    LIST(FIND larg_names "${arg}" is_arg_name)
    LIST(FIND lonearg_names "${arg}" is_onearg_name)
    IF (is_arg_name GREATER -1 OR is_onearg_name GREATER -1)
      SET(${prefix}_${current_arg_name} ${current_arg_list})
      SET(current_arg_name ${arg})
      SET(current_arg_list)
      IF (is_arg_name GREATER -1)
        SET(current_arg_is_singular)
      ELSE (is_arg_name GREATER -1)
        SET(current_arg_is_singular 1)
      ENDIF (is_arg_name GREATER -1)
    ELSE (is_arg_name GREATER -1 OR is_onearg_name GREATER -1)
      LIST(FIND loption_names "${arg}" is_option)
      IF (is_option GREATER -1)
        SET(${prefix}_${arg} TRUE)
      ELSE (is_option GREATER -1)
        SET(current_arg_list ${current_arg_list} ${arg})
        IF (current_arg_is_singular)
          LIST(LENGTH current_arg_list current_list_len)
          IF (current_list_len GREATER 1)
            MESSAGE (FATAL_ERROR "Argument ${current_arg_name} may only have one value")
          ENDIF (current_list_len GREATER 1)
        ENDIF (current_arg_is_singular)
      ENDIF (is_option GREATER -1)
    ENDIF (is_arg_name GREATER -1 OR is_onearg_name GREATER -1)
  ENDFOREACH(arg)
  SET(${prefix}_${current_arg_name} ${current_arg_list})
ENDMACRO(PARSE_ARGUMENTS)

# Utility macro to angle a URI into Zorba's filesystem form - namely:
# 1. Drop the scheme: (and // if present)
# 2. Reverse the authority (host) on dots, then split on dots into subdirs
# 3. If the final component ends in /, append "index.EXT"; else if it
#    doesn't end in .EXT, append ".EXT"
#
# Parameters:
#   URI - URI to mangle
#   EXT - extension to ensure URI ends with
#   DIR_VAR - variable to set with the directory part of the mangled path
#   FILE_VAR - variable to set with the file part of the mangled path
MACRO (MANGLE_URI URI EXT DIR_VAR FILE_VAR)
  # Eliminate scheme, and turn into a list
  STRING (REGEX REPLACE "^[^:]+:(//)?" "" mangled_path "${URI}")
  STRING (REPLACE "/" ";" mangled_path ${mangled_path})

  # Pop off authority part and reverse on dots
  LIST (GET mangled_path 0 authority)
  LIST (REMOVE_AT mangled_path 0)
  message (STATUS "After remove: ${mangled_path}")
  STRING (REPLACE "." ";" authority "${authority}")
  LIST (REVERSE authority)

  # If there's any path left, pop off the final component
  SET (final_comp)
  IF (mangled_path)
    LIST (GET mangled_path -1 final_comp)
    LIST (REMOVE_AT mangled_path -1)
  ENDIF (mangled_path)

  # Convert final component into proper filename
  IF (NOT final_comp)
    SET (${FILE_VAR} "index.${EXT}")
  ELSE (NOT final_comp)
    IF ("${final_comp}" MATCHES "\\.${EXT}$")
      SET (${FILE_VAR} "${final_comp}")
    ELSE ("${final_comp}" MATCHES "\\.${EXT}$")
      SET (${FILE_VAR} "${final_comp}.${EXT}")
    ENDIF ("${final_comp}" MATCHES "\\.${EXT}$")
  ENDIF (NOT final_comp)

  # Stick the reversed authority back on the front of the path: done!
  LIST (INSERT mangled_path 0 ${authority})
  STRING (REPLACE ";" "/" ${DIR_VAR} "${mangled_path}")
  message (STATUS "uri: ${URI} dir: ${${DIR_VAR}} file: ${${FILE_VAR}}")
ENDMACRO (MANGLE_URI)

# Macro which declares a module. This sets up the installation of the
# module, including creating the correct paths for module versioning.
#
# Args: URI - the namespace URI of the module
#       VERSION - (optional) the version of the module, major.minor[.patch]
#       FILE - path to .xq file (if not absolute, will be resolved
#              relative to CMAKE_CURRENT_SOURCE_DIR)
#       LINK_LIBRARIES - (optional) List of libraries to link external
#              function library against
#       OUTPUT_DIRECTORY - (optional) Base path to produce output in
#
# QQQ this currently doesn't support modules with multiple component
# .xq files. (Neither does Zorba's automatic loading mechanism, so
# this probably isn't a huge deal, but worth thinking about.)
#
# QQQ might it be possible / reasonable to attempt to parse the source
# file enough to deduce the URI and version?
MACRO (DECLARE_ZORBA_MODULE)
  # Parse and validate arguments
  PARSE_ARGUMENTS(MODULE "LINK_LIBRARIES" "URI;FILE;VERSION;OUTPUT_DIRECTORY"
    "" ${ARGN})
  IF (NOT IS_ABSOLUTE "${MODULE_FILE}")
    SET (SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_FILE}")
    SET (module_name "${MODULE_FILE}")
  ELSE (NOT IS_ABSOLUTE "${MODULE_FILE}")
    SET (SOURCE_FILE "${MODULE_FILE}")
    GET_FILENAME_COMPONENT (module_name "${MODULE_FILE}" NAME)
  ENDIF (NOT IS_ABSOLUTE "${MODULE_FILE}")

  # Determine which module this is, numerically. This number will be
  # used to generate unique target names for the external library (if
  # any) and the target to copy files into URI_PATH. I wish I could
  # name these targets after the URI rather than an int to avoid any
  # possibility of conflicts, but when you do that you quickly run up
  # against Windows' pathetic 260-character path limitation.
  GET_PROPERTY (num_mod_targets GLOBAL PROPERTY ZORBA_MODULE_TARGET_COUNT)
  IF (NOT num_mod_targets)
    SET (num_mod_targets 0)
  ENDIF (NOT num_mod_targets)
  MATH (EXPR num_mod_targets "${num_mod_targets} + 1")
  SET_PROPERTY (GLOBAL PROPERTY ZORBA_MODULE_TARGET_COUNT ${num_mod_targets})


  MANGLE_URI (${MODULE_URI} "xq" module_path module_filename)

  # Compute a CMake-symbol-safe version of the target URI, for storing
  # things in CMake properties and declaring CMake targets.
  STRING (REGEX REPLACE "[/ ]" "_" uri_sym "${module_path}/${module_filename}")

  # Compute the version numbers, if any provided.
  IF (MODULE_VERSION)
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
      MATH (EXPR version_int
        "${major_ver} * 100000000 + ${minor_ver} * 100000 + ${patch_ver}")
    ELSE (version_len EQUAL 3)
      SET (patch_ver)
      MATH (EXPR version_int "${major_ver} * 100000000 + ${minor_ver} * 100000")
    ENDIF (version_len EQUAL 3)

    # We maintain a global CMake property named after the target URI
    # which remembers all versions of this URI which have been
    # declared. If a *lower* version has already been declared, the
    # output file rules will be messed up, so die.
    GET_PROPERTY (target_versions GLOBAL PROPERTY "${uri_sym}-versions")
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
  ENDIF (MODULE_VERSION)

  # Now, deal with associated C++ source for external functions.

  IF(EXISTS "${SOURCE_FILE}.src/")
    # all the cpp files found in the ${module_name}.xq.src
    # directory are added to the sources list
    SET (SRC_FILES)
    FILE(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
      "${SOURCE_FILE}.src/*.cpp")

    MESSAGE(STATUS "Add library " ${module_name})
    SET(SUFFIX)
    # simplestore executable doesn't need an extension
    IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
      SET(SUFFIX "_${ZORBA_STORE_NAME}")
    ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")

#    IF(WIN32 AND MODULE_VERSION)
#      # configure_file doesn't replace variable with parameters; they
#      # have to be defined in the macro
#      SET(MODULE_VERSION ${MODULE_VERSION})
#      SET(MODULE_NAME ${module_name})
#      # set the rc file for the windows dll version
#      CONFIGURE_FILE("${Zorba_CMAKE_MODULES_DIR}/Windows/WindowsDLLVersion.rc.in"
#                      "${CMAKE_CURRENT_BINARY_DIR}/${module_name}.xq.src/version.rc"
#                      @ONLY)
#      LIST(APPEND SRC_FILES
#        "${CMAKE_CURRENT_BINARY_DIR}/${module_name}.xq.src/version.rc")
#    ENDIF(WIN32)

    # Shared libraries are considered RUNTIME targets on Win32
    # platforms and LIBRARY targets elsewhere
    IF (WIN32)
      SET (target_type RUNTIME)
    ELSE (WIN32)
      SET (target_type LIBRARY)
    ENDIF (WIN32)

    # Add the library target. Ensure that the output name is based on
    # the module *URI*'s final component.
    SET(module_lib_target "modlib_${num_mod_targets}")
    ADD_LIBRARY(${module_lib_target} SHARED ${SRC_FILES})
    GET_FILENAME_COMPONENT(module_filewe "${module_filename}" NAME_WE)
    # It seems like it would be nice to set the VERSION and/or
    # SOVERSION target properties here. However: On Windows, it
    # doesn't seem to do anything (the .rc file configured above
    # embeds the version instead).  On the other hand, on Unix, it
    # changes the actual output target location to something like
    # "libext.so.2.0", which is difficult to transmogrify into the
    # target filename we actually want later. So in either case, the
    # target property isn't desirable.
    SET_TARGET_PROPERTIES(${module_lib_target} PROPERTIES
      OUTPUT_NAME "${module_filewe}${SUFFIX}"
      ${target_type}_OUTPUT_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}/${module_name}.src")
    TARGET_LINK_LIBRARIES(${module_lib_target}
      zorba_${ZORBA_STORE_NAME} ${MODULE_LINK_LIBRARIES})

  ENDIF(EXISTS "${SOURCE_FILE}.src/")


  # Done dealing with C++. Now, set up CMake custom commands which
  # will copy the module source file and dynamic library to each
  # target filename in the output directory.

  IF (MODULE_OUTPUT_DIRECTORY)
    SET (output_dir "${MODULE_OUTPUT_DIRECTORY}/${module_path}")
  ELSE (MODULE_OUTPUT_DIRECTORY)
    SET (output_dir "${CMAKE_BINARY_DIR}/URI_PATH/${module_path}")
  ENDIF (MODULE_OUTPUT_DIRECTORY)
  SET (output_files)
  SET (version_infixes)
  IF (MODULE_VERSION)
    LIST (APPEND version_infixes "${major_ver}" "${major_ver}.${minor_ver}")
    IF (patch_ver)
      LIST (APPEND version_infixes "${major_ver}.${minor_ver}.${patch_ver}")
    ENDIF (patch_ver)
  ENDIF (MODULE_VERSION)
  FOREACH (version_infix "" ${version_infixes})
    ADD_COPY_RULE ("${SOURCE_FILE}" "${output_dir}/${module_filename}"
      "${version_infix}" "${SOURCE_FILE}")
  ENDFOREACH (version_infix)

  # Also copy the dynamic library from the location it was built.
  # Because the dynamic library is only loaded after the .xq file, the
  # exact module version is known; thus only one copy needs to be
  # made.
  IF (module_lib_target)
    GET_TARGET_PROPERTY (lib_location "${module_lib_target}" LOCATION)
    GET_FILENAME_COMPONENT (lib_filename "${lib_location}" NAME)
    ADD_COPY_RULE ("${lib_location}" "${output_dir}/${lib_filename}"
      "${MODULE_VERSION}" "${module_lib_target}")
  ENDIF (module_lib_target)

  # Associate these custom commands with the "all" target via a custom
  # target. (I couldn't find any neater way to do this in CMake; you
  # can't directly add a dependency to "all", nor is it possible to
  # add additional file dependencies to an already-created target.)
  ADD_CUSTOM_TARGET ("chkmod_${num_mod_targets}" ALL DEPENDS ${output_files})

  ENSURE_URI_PATH_INSTALLED()

ENDMACRO (DECLARE_ZORBA_MODULE)

# Macro which declares a schema. This sets up the installation of the
# schema into the URI_PATH folder so it will be found at runtime.
#
# Args: URI - the namespace URI of the schema
#       FILE - path to .xsd file (if not absolute, will be resolved
#              relative to CMAKE_CURRENT_SOURCE_DIR)
#       OUTPUT_DIRECTORY - (optional) Base path to produce output in
MACRO (DECLARE_ZORBA_SCHEMA)
  PARSE_ARGUMENTS(SCHEMA "" "URI;FILE;OUTPUT_DIRECTORY" "" ${ARGN})
  IF (NOT IS_ABSOLUTE "${SCHEMA_FILE}")
    SET (SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${SCHEMA_FILE}")
  ELSE (NOT IS_ABSOLUTE "${SCHEMA_FILE}")
    SET (SOURCE_FILE "${SCHEMA_FILE}")
  ENDIF (NOT IS_ABSOLUTE "${SCHEMA_FILE}")
  MANGLE_URI (${SCHEMA_URI} "xsd" schema_path schema_filename)

  IF (SCHEMA_OUTPUT_DIRECTORY)
    SET (output_dir "${SCHEMA_OUTPUT_DIRECTORY}/${schema_path}")
  ELSE (SCHEMA_OUTPUT_DIRECTORY)
    SET (output_dir "${CMAKE_BINARY_DIR}/URI_PATH/${schema_path}")
  ENDIF (SCHEMA_OUTPUT_DIRECTORY)
  ADD_CUSTOM_COMMAND (OUTPUT "${output_dir}/${schema_filename}"
    COMMAND "${CMAKE_COMMAND}" -E copy
    "${SOURCE_FILE}" "${output_dir}/${schema_filename}"
    COMMENT "Copying ${SOURCE_FILE} to URI path" VERBATIM)
  GET_PROPERTY (num_schema_targets GLOBAL PROPERTY ZORBA_SCHEMA_TARGET_COUNT)
  IF (NOT num_schema_targets)
    SET (num_schema_targets 0)
  ENDIF (NOT num_schema_targets)
  MATH (EXPR num_schema_targets "${num_schema_targets} + 1")
  ADD_CUSTOM_TARGET ("chkschema_${num_schema_targets}" ALL
    DEPENDS "${output_dir}/${schema_filename}")
  SET_PROPERTY (GLOBAL PROPERTY ZORBA_SCHEMA_TARGET_COUNT ${num_schema_targets})

  ENSURE_URI_PATH_INSTALLED()
ENDMACRO (DECLARE_ZORBA_SCHEMA)

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
      COMMAND "${CMAKE_COMMAND}" -E copy
      "${INPUT_FILE}" "${_output_file}"
      DEPENDS "${DEPEND_TARGET}"
      COMMENT "Copying ${INPUT_FILE} to URI path" VERBATIM)
    SET_PROPERTY (GLOBAL APPEND PROPERTY "${uri_sym}-output-files"
      "${_output_file}")
  ENDIF (file_found EQUAL -1)
ENDMACRO (ADD_COPY_RULE)

MACRO (ENSURE_URI_PATH_INSTALLED)
  # Ensure there exactly one INSTALL() directive for the URI path.
  GET_PROPERTY (is_installed GLOBAL PROPERTY ZORBA_URI_PATH_INSTALLED)
  IF(NOT is_installed)
    INSTALL(DIRECTORY "${PROJECT_BINARY_DIR}/URI_PATH/."
      DESTINATION "include/zorba/modules/")
    SET_PROPERTY(GLOBAL PROPERTY ZORBA_URI_PATH_INSTALLED 1)
  ENDIF(NOT is_installed)
ENDMACRO (ENSURE_URI_PATH_INSTALLED)

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
    ZORBA_ADD_TEST(${TESTNAME} testdriver
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
#              (similar convention than in ZORBA_GENERATE_EXE)
#     ... - arguments that will be passed to the target
#
MACRO(ZORBA_ADD_TEST NAME TARGET ...)
  SET(ARGS ${ARGV2} ${ARGN})

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
ENDMACRO(ZORBA_ADD_TEST)

# This macro can be used to set a property to each test generated by the macro ZORBA_ADD_TEST.
#
# Syntax:
#
#   ZORBA_SET_TEST_PROPERTY(NAME PROPERTY VALUE)
#
#     PROPERTY - property
#     VALUE - value of property
#
MACRO(ZORBA_SET_TEST_PROPERTY NAME PROPERTY VALUE)
  SET_TESTS_PROPERTIES ("${NAME}" PROPERTIES ${PROPERTY} "${VALUE}")
ENDMACRO(ZORBA_SET_TEST_PROPERTY)





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
