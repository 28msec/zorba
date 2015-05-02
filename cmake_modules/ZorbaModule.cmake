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
  FOREACH(arg_name ${arg_names} ${onearg_names})
    SET(${prefix}_${arg_name})
  ENDFOREACH(arg_name)
  FOREACH(option ${option_names})
    SET(${prefix}_${option} 0)
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
        SET(${prefix}_${arg} 1)
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
#   EXT - extension to ensure URI ends with (may be empty; if set, must
#         include leading "."
#   DIR_VAR - variable to set with the directory part of the mangled path
#   FILE_VAR - variable to set with the file part of the mangled path
MACRO (MANGLE_URI URI EXT DIR_VAR FILE_VAR)
  # Eliminate scheme, and turn into a list
  STRING (REGEX REPLACE "^[^:]+:(//)?" "" mangled_path "${URI}")
  STRING (REPLACE "/" ";" mangled_path ${mangled_path})

  # Pop off authority part and reverse on dots
  LIST (GET mangled_path 0 authority)
  LIST (REMOVE_AT mangled_path 0)
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
    SET (${FILE_VAR} "index${EXT}")
  ELSE (NOT final_comp)
    # \\ necessary to escape the leading . in EXT
    IF ("${final_comp}" MATCHES "\\${EXT}$")
      SET (${FILE_VAR} "${final_comp}")
    ELSE ("${final_comp}" MATCHES "\\${EXT}$")
      SET (${FILE_VAR} "${final_comp}${EXT}")
    ENDIF ("${final_comp}" MATCHES "\\${EXT}$")
  ENDIF (NOT final_comp)

  # Stick the reversed authority back on the front of the path: done!
  LIST (INSERT mangled_path 0 ${authority})
  STRING (REPLACE ";" "/" ${DIR_VAR} "${mangled_path}")
ENDMACRO (MANGLE_URI)

# Macro which declares a module. This sets up the installation of the
# module, including creating the correct paths for module versioning.
#
# Args: URI - the namespace URI of the module
#       VERSION - (optional) the version of the module, major.minor[.patch]
#       FILE - path to module file (if not absolute, will be resolved
#              relative to CMAKE_CURRENT_SOURCE_DIR)
#       LINK_LIBRARIES - (optional) List of libraries to link external
#              function library against
#       CONFIG_FILES - (optional) List of files to configure with package
#              information; see below
#       TEST_ONLY - (optional) Module is for testcases only and should not
#              be installed
#       LIBRARY_DEPENDS - (optional) List of targets that the external
#              function library will depend on (only works if the module
#              contains C++ external functions)
#       NO_DECL_CHECK - (optional) Skip the check which ensures the module
#              starts with a valid version declaration. This should ONLY
#              be used on external modules that cannot be modified, as it
#              risks the module not being parsed correctly in some cases.
#
# CONFIG_FILES - any files specific here will be copied to
# CMAKE_CURRENT_BINARY_DIR using CONFIGURE_FILE(). They may contain
# the following @VARIABLES@ which will be substituted:
#       ZORBA_MODULE_RELATIVE_DIR - directory portion of mangled URI
#       ZORBA_MODULE_LIBFILE_WE - filename (without extension) portion of
#              mangled URI
# The input files should have a .in extension. The resulting file in
# the build directory will have the .in removed.
#
# QQQ this currently doesn't support modules with multiple component
# .xq files. (Neither does Zorba's automatic loading mechanism, so
# this probably isn't a huge deal, but worth thinking about.)
#
# QQQ might it be possible / reasonable to attempt to parse the source
# file enough to deduce the URI and version?
MACRO (DECLARE_ZORBA_MODULE)
  # Parse and validate arguments
  PARSE_ARGUMENTS(MODULE "LINK_LIBRARIES;EXTRA_SOURCES;CONFIG_FILES;LIBRARY_DEPENDS"
    "URI;FILE;VERSION" "TEST_ONLY;NO_DECL_CHECK" ${ARGN})
  IF (NOT MODULE_FILE)
    MESSAGE (FATAL_ERROR "'FILE' argument is required for ZORBA_DECLARE_MODULE()")
  ENDIF (NOT MODULE_FILE)
  IF (NOT MODULE_URI)
    MESSAGE (FATAL_ERROR "'URI' argument is required for ZORBA_DECLARE_MODULE()")
  ENDIF (NOT MODULE_URI)
  IF (NOT IS_ABSOLUTE "${MODULE_FILE}")
    SET (SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_FILE}")
  ELSE (NOT IS_ABSOLUTE "${MODULE_FILE}")
    SET (SOURCE_FILE "${MODULE_FILE}")
  ENDIF (NOT IS_ABSOLUTE "${MODULE_FILE}")
  GET_FILENAME_COMPONENT (module_name "${MODULE_FILE}" NAME)

  # Ensure specified file starts with a valid version declaration
  # (either XQuery or JSONiq, or whatever future languages we
  # support).  Currently, just check for "xquery version" or "jsoniq
  # version" in the first bytes of the file. (It is invalid by the
  # spec for a version declaration to anywhere else.)
  IF (NOT MODULE_NO_DECL_CHECK)
    FILE (READ ${SOURCE_FILE} _version_decl LIMIT 20)
    STRING (REGEX MATCH "^(xquery|jsoniq) version" _decl_found ${_version_decl})
    IF (NOT _decl_found)
      MESSAGE (FATAL_ERROR "File ${SOURCE_FILE} does not start with a "
        "valid XQuery or JSONiq version declaration. This is required to "
        "ensure correct parsing.")
    ENDIF (NOT _decl_found)
  ENDIF (NOT MODULE_NO_DECL_CHECK)

  MANGLE_URI (${MODULE_URI} ".module" module_path module_filename)

  # Determine which module this is, numerically. This number will be
  # used to generate unique names, for instance for the target name
  # for the external library (if any) and for the compilation test. I
  # wish I could name these targets after the URI rather than an int
  # to avoid any possibility of conflicts, but when you do that you
  # quickly run up against Windows' pathetic 260-character path
  # limitation.
  GET_PROPERTY (num_zorba_modules GLOBAL PROPERTY ZORBA_MODULE_COUNT)
  IF (NOT num_zorba_modules)
    SET (num_zorba_modules 0)
  ENDIF (NOT num_zorba_modules)
  MATH (EXPR num_zorba_modules "${num_zorba_modules} + 1")
  SET_PROPERTY (GLOBAL PROPERTY ZORBA_MODULE_COUNT ${num_zorba_modules})

  # If no version specified, it is effectively treated as 0.0.0.
  IF (NOT MODULE_VERSION)
    SET (MODULE_VERSION "0.0.0")
  ENDIF (NOT MODULE_VERSION)

  # Compute a unique integer, version_int, based on the version
  # number, so we can more easily compare with other versions later.
  STRING (REPLACE "." ";" version "${MODULE_VERSION}")
  LIST (LENGTH version version_len)
  IF (NOT ( (version_len EQUAL 2) OR (version_len EQUAL 3) ) )
    MESSAGE (FATAL_ERROR
      "Version ${version_len} ${MODULE_VERSION} not of form 'major.minor[.patch]'")
  ENDIF (NOT ( (version_len EQUAL 2) OR (version_len EQUAL 3) ) )
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
  # output file rules will be messed up, so die. If the *same* version
  # has already been declare, XQdoc will be messed up, so die.
  STRING (REGEX REPLACE "[/:#% ]" "_" uri_sym "${MODULE_URI}")
  GET_PROPERTY (target_versions GLOBAL PROPERTY "${uri_sym}-versions")
  FOREACH (known_ver ${target_versions})
    IF (known_ver LESS version_int)
      MESSAGE (FATAL_ERROR
        "The module ${MODULE_URI} has already been declared with a "
        "lower version number than ${MODULE_VERSION}. "
        "Please call DECLARE_ZORBA_MODULE() for higher versions of the same "
        "module first.")
    ElSEIF (known_ver EQUAL version_int)
      MESSAGE (FATAL_ERROR
        "The module ${MODULE_URI} has already been declared with the "
        "version number ${MODULE_VERSION}. You cannot declare the same "
        "module twice.")
    ENDIF (known_ver LESS version_int)
  ENDFOREACH (known_ver)
  SET_PROPERTY (GLOBAL APPEND PROPERTY "${uri_sym}-versions" ${version_int})

  # Add to module manifest (except test modules).
  IF (NOT MODULE_TEST_ONLY)
    ADD_ZORBA_MANIFEST_ENTRY("module" ${MODULE_URI} "${MODULE_VERSION}")
  ENDIF (NOT MODULE_TEST_ONLY)

  # Now, deal with associated C++ source for external functions.

  SET (module_lib_target)
  IF(MODULE_EXTRA_SOURCES OR EXISTS "${SOURCE_FILE}.src/")
    # all the cpp files found in the ${module_name}.xq.src directory
    # are added to the sources list, as are any cpp files found in any
    # directory in EXTRA_SOURCES
    SET (SRC_FILES)
    FOREACH (_src_dir "${SOURCE_FILE}.src" ${MODULE_EXTRA_SOURCES})
      IF (NOT IS_ABSOLUTE "${_src_dir}")
        SET (_src_dir "${CMAKE_CURRENT_SOURCE_DIR}/${_src_dir}")
      ENDIF (NOT IS_ABSOLUTE "${_src_dir}")
      FILE(GLOB_RECURSE _srcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 
        "${_src_dir}/*.cpp" "${_src_dir}/*.c")
      LIST (APPEND SRC_FILES ${_srcs})
    ENDFOREACH (_src_dir)

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
    SET(module_lib_target "modlib${num_zorba_modules}_${module_name}")
    ADD_LIBRARY(${module_lib_target} SHARED ${SRC_FILES})
    IF (MODULE_LIBRARY_DEPENDS)
      ADD_DEPENDENCIES(${module_lib_target} ${MODULE_LIBRARY_DEPENDS})
    ENDIF()
    GET_FILENAME_COMPONENT(module_filewe "${module_filename}" NAME_WE)
    IF (MODULE_VERSION)
      # If there's a version, insert it into the module library name
      SET (module_filewe "${module_filewe}_${MODULE_VERSION}")
    ENDIF (MODULE_VERSION)

    # Compute the output path for the library. Note: This is copied
    # from ADD_COPY_RULE(); probably should refactor this logic.
    IF (${MODULE_TEST_ONLY} EQUAL 1)
      SET (_output_basedir "${CMAKE_BINARY_DIR}/TEST_LIB_PATH")
    ELSE (${MODULE_TEST_ONLY} EQUAL 1)
      SET (_output_basedir "${CMAKE_BINARY_DIR}/LIB_PATH")
    ENDIF (${MODULE_TEST_ONLY} EQUAL 1)

    # It seems like it would be nice to set the VERSION and/or
    # SOVERSION target properties here. However: On Windows, it
    # doesn't seem to do anything (the .rc file configured above
    # embeds the version instead).  On the other hand, on Unix, it
    # changes the actual output target location to something like
    # "libext.so.2.0", which is difficult to transmogrify into the
    # target filename we actually want later. So in either case, the
    # target property isn't desirable.
    # FOLDER is to group IDE projects into folders.
    SET_TARGET_PROPERTIES (${module_lib_target} PROPERTIES
      OUTPUT_NAME "${module_filewe}${SUFFIX}"
      ${target_type}_OUTPUT_DIRECTORY "${_output_basedir}/${module_path}"
      FOLDER "Modules"
      )
    TARGET_LINK_LIBRARIES(${module_lib_target} zorba_${ZORBA_STORE_NAME})
 
    # Ridiculous hack: CMake doesn't seem to (reliably) set up
    # dependencies if you specify a library to TARGET_LINK_LIBRARIES()
    # which is the output of some other ADD_LIBRARY(). We can't solve
    # this problem in the general case. We can work around it,
    # however, in the specific case where the target library was
    # generated by an earlier call to DECLARE_ZORBA_MODULE() - by
    # remembering that output library's path and its corresponding
    # target in a global property.
    FOREACH (_lib ${MODULE_LINK_LIBRARIES})
      GET_PROPERTY (_targetname GLOBAL PROPERTY "${_lib}_TARGET")
      IF ("${_targetname}" STREQUAL "")
	TARGET_LINK_LIBRARIES(${module_lib_target} "${_lib}")
      ELSE ("${_targetname}" STREQUAL "")
	TARGET_LINK_LIBRARIES(${module_lib_target} "${_targetname}")
      ENDIF ("${_targetname}" STREQUAL "")
    ENDFOREACH (_lib)

    # Remember this library for the auto-generated module Config.cmake
    # file. Also remember the target name for the hack mentioned
    # above.  QQQ and what about the installed version?
    GET_TARGET_PROPERTY (_lib_location "${module_lib_target}" LOCATION)
    SET_PROPERTY (GLOBAL APPEND PROPERTY "${PROJECT_NAME}_LIBRARIES"
      "${_lib_location}")
    SET_PROPERTY (GLOBAL PROPERTY "${_lib_location}_TARGET"
      "${module_lib_target}")

    # If this is a core module, remember the target that builds the
    # library so zorbacmd can depend on it.
    IF (${PROJECT_NAME} STREQUAL "zorba")
      SET_PROPERTY (GLOBAL APPEND PROPERTY ZORBA_CORE_MODULE_LIB_TARGETS
	"${module_lib_target}")
    ENDIF (${PROJECT_NAME} STREQUAL "zorba")
      
    # Install the library, if it's not a TEST_ONLY module
    IF (NOT MODULE_TEST_ONLY)
      IF(NOT ${PROJECT_NAME} STREQUAL "zorba")
        STRING(REPLACE "-" "_"  component_name ${PROJECT_NAME})
        INSTALL(TARGETS ${module_lib_target}
          ${target_type} DESTINATION ${ZORBA_NONCORE_LIB_DIR}/${module_path}
          COMPONENT ${component_name})
      
      ELSE(NOT ${PROJECT_NAME} STREQUAL "zorba")
        INSTALL(TARGETS ${module_lib_target}
          ${target_type} DESTINATION ${ZORBA_CORE_LIB_DIR}/${module_path})
      ENDIF(NOT ${PROJECT_NAME} STREQUAL "zorba")
    ENDIF (NOT MODULE_TEST_ONLY)
      
  ENDIF(MODULE_EXTRA_SOURCES OR EXISTS "${SOURCE_FILE}.src/")

  # Done dealing with C++. Now, set up rules which will copy the
  # module source file and dynamic library to each target filename in
  # the output directory.

  SET (output_files)
  SET (version_infixes)
  IF (MODULE_VERSION)
    LIST (APPEND version_infixes "${major_ver}" "${major_ver}.${minor_ver}")
    IF (patch_ver)
      LIST (APPEND version_infixes "${major_ver}.${minor_ver}.${patch_ver}")
    ENDIF (patch_ver)
  ENDIF (MODULE_VERSION)
  FOREACH (version_infix "" ${version_infixes})
    ADD_COPY_RULE ("URI" "${SOURCE_FILE}" "${module_path}/${module_filename}"
      "${version_infix}" "" 1 "${MODULE_TEST_ONLY}")
  ENDFOREACH (version_infix)

  # Configure any module-specified config files.
  SET (ZORBA_MODULE_RELATIVE_DIR ${module_path})
  SET (ZORBA_MODULE_LIBFILE_WE ${module_filewe})
  FOREACH (_config_file ${MODULE_CONFIG_FILES})
    # Strip off .in - can't use GET_FILENAME_COMPONENT as it always removes
    # the longest possible extension
    STRING (REGEX REPLACE "\\.in$" "" _config_filename_we "${_config_file}")
    IF (NOT IS_ABSOLUTE "${_config_file}")
      SET (_config_file "${CMAKE_CURRENT_SOURCE_DIR}/${_config_file}")
    ENDIF (NOT IS_ABSOLUTE "${_config_file}")
    CONFIGURE_FILE (${_config_file}
      "${CMAKE_CURRENT_BINARY_DIR}/${_config_filename_we}" @ONLY)
  ENDFOREACH (_config_file)

  # Last but not least, whip up a test case that ensures the module
  # can at least be compiled. Don't bother for test-only modules
  # (presumably they're there to be tested!).
  IF (NOT MODULE_TEST_ONLY)
    SET (module_test_query
      "${CMAKE_CURRENT_BINARY_DIR}/test_mod_${num_zorba_modules}.xq")
    IF (MODULE_VERSION)
      SET (_mod_fragment "#${MODULE_VERSION}")
    ELSE (MODULE_VERSION)
      SET (_mod_fragment)
    ENDIF (MODULE_VERSION)
    FILE (WRITE "${module_test_query}"
      "import module namespace t = \"${MODULE_URI}${_mod_fragment}\";\n1\n")
    ADD_TEST (check_mod_${num_zorba_modules}_${module_name}
      "${Zorba_EXE}" -f -q "${module_test_query}"
      --module-path "${CMAKE_BINARY_DIR}/URI_PATH")
  ENDIF (NOT MODULE_TEST_ONLY)

ENDMACRO (DECLARE_ZORBA_MODULE)

# Macro to see whether a given module has been declared, by URI.
# For now this only returns a true or false value; version introspection
# is not supported.
MACRO (IS_ZORBA_MODULE_DECLARED IS_SET_VAR MODULE_URI)
  # Just check for the existence of the "URI-versions" global property,
  # as set by DECLARE_ZORBA_MODULE()
  STRING (REGEX REPLACE "[/:#% ]" "_" uri_sym "${MODULE_URI}")
  GET_PROPERTY (${IS_SET_VAR} GLOBAL PROPERTY "${uri_sym}-versions" SET)
ENDMACRO (IS_ZORBA_MODULE_DECLARED)

# Macro which declares a schema. This sets up the installation of the
# schema into the URI_PATH folder so it will be found at runtime.
#
# Args: URI - the namespace URI of the schema
#       FILE - path to schema file (if not absolute, will be resolved
#              relative to CMAKE_CURRENT_SOURCE_DIR)
#       TEST_ONLY - (optional) Schema is for testcases only and should not
#              be installed
MACRO (DECLARE_ZORBA_SCHEMA)
  PARSE_ARGUMENTS(SCHEMA "" "URI;FILE" "TEST_ONLY" ${ARGN})
  IF (NOT SCHEMA_FILE)
    MESSAGE (FATAL_ERROR "'FILE' argument is required for ZORBA_DECLARE_SCHEMA()")
  ENDIF (NOT SCHEMA_FILE)
  IF (NOT SCHEMA_URI)
    MESSAGE (FATAL_ERROR "'URI' argument is required for ZORBA_DECLARE_SCHEMA()")
  ENDIF (NOT SCHEMA_URI)
  IF (NOT IS_ABSOLUTE "${SCHEMA_FILE}")
    SET (SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${SCHEMA_FILE}")
  ELSE (NOT IS_ABSOLUTE "${SCHEMA_FILE}")
    SET (SOURCE_FILE "${SCHEMA_FILE}")
  ENDIF (NOT IS_ABSOLUTE "${SCHEMA_FILE}")
  GET_FILENAME_COMPONENT (schema_name "${SCHEMA_FILE}" NAME)
  MANGLE_URI (${SCHEMA_URI} ".schema" schema_path schema_filename)

  # Add to schema manifest (except test schema).
  IF (NOT SCHEMA_TEST_ONLY)
    ADD_ZORBA_MANIFEST_ENTRY("schema" ${SCHEMA_URI} "")
  ENDIF (NOT SCHEMA_TEST_ONLY)

  ADD_COPY_RULE ("URI" "${SOURCE_FILE}" "${schema_path}/${schema_filename}"
    "" "" 1 "${SCHEMA_TEST_ONLY}")

ENDMACRO (DECLARE_ZORBA_SCHEMA)

# Macro which declares a file to be loaded by URI. This sets up the
# installation of the file into the URI_PATH folder so it will be
# found at runtime.
#
# Args: URI - the URI of the file
#       FILE - path to file (if not absolute, will be resolved
#              relative to CMAKE_CURRENT_SOURCE_DIR)
#       TEST_ONLY - (optional) File is for testcases only and should not
#              be installed
MACRO (DECLARE_ZORBA_URI_FILE)
  # QQQ Refactor - this macro is basically identical to DECLARE_ZORBA_SCHEMA
  PARSE_ARGUMENTS(URI_FILE "" "URI;FILE" "TEST_ONLY" ${ARGN})
  IF (NOT URI_FILE_FILE)
    MESSAGE (FATAL_ERROR "'FILE' argument is required for ZORBA_DECLARE_URI_FILE()")
  ENDIF (NOT URI_FILE_FILE)
  IF (NOT URI_FILE_URI)
    MESSAGE (FATAL_ERROR "'URI' argument is required for ZORBA_DECLARE_URI_FILE()")
  ENDIF (NOT URI_FILE_URI)
  IF (NOT IS_ABSOLUTE "${URI_FILE_FILE}")
    SET (SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${URI_FILE_FILE}")
  ELSE (NOT IS_ABSOLUTE "${URI_FILE_FILE}")
    SET (SOURCE_FILE "${URI_FILE_FILE}")
  ENDIF (NOT IS_ABSOLUTE "${URI_FILE_FILE}")
  GET_FILENAME_COMPONENT (uri_file_name "${URI_FILE_FILE}" NAME)
  # Don't enforce any extension on general files
  MANGLE_URI (${URI_FILE_URI} "" uri_file_path uri_file_filename)

  ADD_COPY_RULE ("URI" "${SOURCE_FILE}" "${uri_file_path}/${uri_file_filename}"
    "" "" 1 "${URI_FILE_TEST_ONLY}")

ENDMACRO (DECLARE_ZORBA_URI_FILE)


# Inform Zorba of a .jar file that should be made available on the CLASSPATH
# of the JVM, should the JVM be started. QQQ more doc needed
#
# Args: FILE - path to file(s) (must be absolute)
#       TARGET - (optional) a CMake target that must be executed in order
#              for FILEs to be generated
#       EXTERNAL - (optional) FILE specifies a path that should be added
#              to CLASSPATH as-is
#       TEST_ONLY - (optional) Jar file is for testcases only and should not
#              be installed
#
# Must supply at least one value to FILE or TARGET.
MACRO (DECLARE_ZORBA_JAR)
  PARSE_ARGUMENTS (JAR "FILE;TARGET" "TARGET" "TEST_ONLY;EXTERNAL" ${ARGN})
  IF (NOT JAR_FILE)
    MESSAGE (FATAL_ERROR "'FILE' argument is required for DECLARE_ZORBA_JAR")
  ENDIF (NOT JAR_FILE)

  # Initialize classpath file and set up copy rule (once per project)
  SET (_CP_FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-classpath.txt")
  GET_PROPERTY (_known_project GLOBAL PROPERTY "${PROJECT_NAME}-jars")
  IF (NOT _known_project)
    FILE (REMOVE "${_CP_FILE}")
    SET_PROPERTY (GLOBAL PROPERTY "${PROJECT_NAME}-jars" 1)
    ADD_COPY_RULE ("LIB" "${_CP_FILE}" "jars/${PROJECT_NAME}-classpath.txt"
      "" "" 1 "${JAR_TEST_ONLY}")
  ENDIF (NOT _known_project)

  # Iterate over all supplied jar files
  FOREACH (_jar_file ${JAR_FILE})

    IF (JAR_EXTERNAL AND NOT ZORBA_PACKAGE_EXTERNAL_JARS)
      # Put absolute path into classpath file
      FILE (APPEND "${_CP_FILE}" "${_jar_file}\n")
    ELSE (JAR_EXTERNAL AND NOT ZORBA_PACKAGE_EXTERNAL_JARS)
      # Copy real jar (after following any symlinks) to jars/ directory
      # and add relative path to classpath file
      IF (IS_SYMLINK "${_jar_file}")
	GET_FILENAME_COMPONENT (_jar_file "${_jar_file}" REALPATH)
      ENDIF (IS_SYMLINK "${_jar_file}")
      GET_FILENAME_COMPONENT (_output_filename "${_jar_file}" NAME)
      ADD_COPY_RULE ("LIB" "${_jar_file}" "jars/${_output_filename}" "" 
        "${JAR_TARGET}" 1 "${JAR_TEST_ONLY}")
      FILE (APPEND "${_CP_FILE}" "${_output_filename}\n")
    ENDIF (JAR_EXTERNAL AND NOT ZORBA_PACKAGE_EXTERNAL_JARS)

  ENDFOREACH (_jar_file)
ENDMACRO (DECLARE_ZORBA_JAR)


# Utility macro for setting up a build rule to copy a file to a
# particular (possibly versioned) file in a shared directory if such a
# file has not already been output.
#
# FILE_TYPE: Either "URI" or "LIB"; will be used to determine which shared
#    directory to place output in (URI_PATH or LIB_PATH).
# INPUT_FILE: Absolute path to file to copy.
# OUTPUT_FILE: Relative path to output file (relative to URI_PATH).
# VERSION_ARG: Version; may be "" for non-versioned files.
# DEPEND_TARGET: A CMake target name upon which the copy rule should depend;
#    may be "".
# INSTALL: If 1, an INSTALL() directive will be executed to put the
#    file into the install image.
# TEST_ONLY: If 1, file is for testcases only; will be copied into
#    TEST_URI_PATH/TEST_LIB_PATH and will not be installed.
MACRO (ADD_COPY_RULE FILE_TYPE INPUT_FILE OUTPUT_FILE VERSION_ARG
       DEPEND_TARGET INSTALL TEST_ONLY)
  # Choose output base directory
  IF (${TEST_ONLY} EQUAL 1)
    SET (_output_basedir "${CMAKE_BINARY_DIR}/TEST_${FILE_TYPE}_PATH")
  ELSE (${TEST_ONLY} EQUAL 1)
    SET (_output_basedir "${CMAKE_BINARY_DIR}/${FILE_TYPE}_PATH")
  ENDIF (${TEST_ONLY} EQUAL 1)

  # Compute the modified output filename by inserting VERSION_ARG (if
  # non-empty) in front of its extension.
  GET_FILENAME_COMPONENT (_output_path "${OUTPUT_FILE}" PATH)
  GET_FILENAME_COMPONENT (_output_filename "${OUTPUT_FILE}" NAME_WE)
  GET_FILENAME_COMPONENT (_output_ext "${OUTPUT_FILE}" EXT)
  IF (NOT "${VERSION_ARG}" STREQUAL "")
    SET (_output_filename "${_output_filename}_${VERSION_ARG}${_output_ext}")
  ELSE (NOT "${VERSION_ARG}" STREQUAL "")
    SET (_output_filename "${_output_filename}${_output_ext}")
  ENDIF (NOT "${VERSION_ARG}" STREQUAL "")
  SET (_output_file "${_output_basedir}/${_output_path}/${_output_filename}")

  # We maintain a global CMake property named after the output
  # directory which remembers all known output source files. If the
  # output file we just computed is already on that list, that means
  # that a module with the same URI but a higher version number has
  # already declared that output file, so we skip it now.
  STRING (REGEX REPLACE "[/ ]" "_" _dir_sym
    "${_output_basedir}/${_output_path}")
  GET_PROPERTY (target_files GLOBAL PROPERTY "${_dir_sym}-output-files")
  LIST (FIND target_files "${_output_file}" file_found)
  IF (file_found EQUAL -1)
    SET_PROPERTY (GLOBAL APPEND PROPERTY "${_dir_sym}-output-files"
      "${_output_file}")
    # Detect whether this is a core URI or not
    IF (PROJECT_NAME STREQUAL "zorba")
      SET (_is_core 1)
    ELSE (PROJECT_NAME STREQUAL "zorba")
      SET (_is_core 0)
    ENDIF (PROJECT_NAME STREQUAL "zorba")

    # Save the (input file, output file, any library dependency
    # target, and whether this is a core or non-core file) for this
    # rule in a global property
    SET_PROPERTY (GLOBAL APPEND PROPERTY ZORBA_URI_FILES
      "${INPUT_FILE}" "${_output_file}" "${DEPEND_TARGET}" "${_is_core}")

    # Also set up an INSTALL rule (unless TEST_ONLY).
    IF ( (${INSTALL} EQUAL 1) AND (NOT ${TEST_ONLY} EQUAL 1) )
        
      IF(NOT _is_core)
        STRING(REPLACE "-" "_"  component_name ${PROJECT_NAME})   
        INSTALL (FILES "${INPUT_FILE}"
          DESTINATION "${ZORBA_NONCORE_${FILE_TYPE}_DIR}/${_output_path}"
          RENAME "${_output_filename}"
          COMPONENT "${component_name}")
          
        IF (NOT ${component_name}_cpack)
          SET (${component_name}_cpack 1)
        
          STRING(TOUPPER ${component_name} component_name2)
          FILE(APPEND ${CMAKE_BINARY_DIR}/CMakeCPackModules.cmake "SET(CPACK_COMPONENT_${component_name2}_GROUP \"external_modules\")\n")
            
          STRING(REPLACE "zorba_" "" component_display_name ${component_name})
          STRING(REPLACE "_" " " component_display_name ${component_display_name})
          FILE(APPEND ${CMAKE_BINARY_DIR}/CMakeCPackModules.cmake "SET(CPACK_COMPONENT_${component_name2}_DISPLAY_NAME \"${component_display_name}\")\n")
            
          FILE(APPEND ${CMAKE_BINARY_DIR}/CMakeCPackModules.cmake "SET(CPACK_COMPONENT_${component_name2}_DESCRIPTION \"Install the functionalities of the ${component_display_name}.\")\n")
          FILE(APPEND ${CMAKE_BINARY_DIR}/CMakeCPackModules.cmake "SET(CPACK_COMPONENT_${component_name2}_INSTALL_TYPES Full)\n")
        ENDIF (NOT ${component_name}_cpack)  
            
      ELSE(NOT _is_core)
        INSTALL (FILES "${INPUT_FILE}"
          DESTINATION "${ZORBA_CORE_${FILE_TYPE}_DIR}/${_output_path}"
          RENAME "${_output_filename}")
      ENDIF(NOT _is_core)
          
    ENDIF ( (${INSTALL} EQUAL 1) AND (NOT ${TEST_ONLY} EQUAL 1) )
  ENDIF (file_found EQUAL -1)
ENDMACRO (ADD_COPY_RULE)

# Utility macro for adding a line to either the schema or module
# manifest file.
MACRO (ADD_ZORBA_MANIFEST_ENTRY ENTRY_TYPE URI VERSION)
  SET (_version_attr)
  IF (NOT "${VERSION}" STREQUAL "")
    SET (_version_attr " version=\"${VERSION}\"")
  ENDIF (NOT "${VERSION}" STREQUAL "")
  # A module or schema is "core" if it's part of the Zorba
  # distribution. The Zorba project is named "zorba", so see if we're
  # in that project.
  IF ("${zorba_SOURCE_DIR}" STREQUAL "${PROJECT_SOURCE_DIR}")
    SET (_is_core true)
  ELSE ("${zorba_SOURCE_DIR}" STREQUAL "${PROJECT_SOURCE_DIR}")
    SET (_is_core false)
  ENDIF ("${zorba_SOURCE_DIR}" STREQUAL "${PROJECT_SOURCE_DIR}")

  FILE (APPEND "${zorba_manifest_file}"
    "<z:${ENTRY_TYPE} isCore=\"${_is_core}\"${_version_attr}>\n")
  FILE (APPEND "${zorba_manifest_file}"
    "  <z:uri>${URI}</z:uri>\n")
  FILE (APPEND "${zorba_manifest_file}"
    "  <z:projectRoot>${PROJECT_SOURCE_DIR}</z:projectRoot>\n")
  FILE (APPEND "${zorba_manifest_file}" "</z:${ENTRY_TYPE}>\n")
ENDMACRO (ADD_ZORBA_MANIFEST_ENTRY)

# Macro which states the project is done calling
# DECLARE_ZORBA_MODULE() and DECLARE_ZORBA_SCHEMA(). Causes a single
# target to be declared which will copy all declared module/schema
# files to their corresponding output directories, with appropriate
# dependencies. This macro will only have any effect when called by
# the top-level project in a build.
# Also, this function automatically generates a CMake projectConfig.cmake
# file for the project, based on config/ExternalModuleConfig.cmake.in.
MACRO (DONE_DECLARING_ZORBA_URIS)
  IF (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    # Close out the zorba modules and schemas manifests
    FILE (APPEND "${zorba_manifest_file}" "</z:manifest>\n")
    IF (POLICY CMP0007)
      CMAKE_POLICY (SET CMP0007 NEW)
    ENDIF (POLICY CMP0007)
    MESSAGE (STATUS "Creating check_core_uris and check_uris targets")
    GET_PROPERTY (copy_rules GLOBAL PROPERTY ZORBA_URI_FILES)
    SET (_output_files)
    WHILE (copy_rules)
      # Pop four items off the list, and set up the corresponding
      # rule
      LIST (GET copy_rules 0 _input_file)
      LIST (GET copy_rules 1 _output_file)
      LIST (GET copy_rules 2 _depend_target)
      LIST (GET copy_rules 3 _is_core)
      LIST (REMOVE_AT copy_rules 0 1 2 3)
      IF (_depend_target)
        SET (_depends "${_depend_target}")
      ELSE (_depend_target) 
	SET (_depends "${_input_file}")
      ENDIF (_depend_target)
      ADD_CUSTOM_COMMAND (OUTPUT "${_output_file}"
        COMMAND "${CMAKE_COMMAND}" -E copy
        "${_input_file}" "${_output_file}"
        DEPENDS ${_depends}
        COMMENT "Copying ${_input_file} to URI path" VERBATIM)
      IF (_is_core)
        LIST (APPEND _core_output_files "${_output_file}")
      ELSE (_is_core)
        LIST (APPEND _noncore_output_files "${_output_file}")
      ENDIF (_is_core)
    ENDWHILE (copy_rules)

    # Targets and dependencies:
    #   ALL depends on check_uris; check_uris depends on check_core_uris;
    #   zorbacmd depends on check_core_uris as well as all core module
    #   library targets.
    ADD_CUSTOM_TARGET (check_uris ALL
      DEPENDS ${_noncore_output_files} VERBATIM)
    SET_TARGET_PROPERTIES(check_uris PROPERTIES FOLDER "Modules")
    # Only create check_core_uris target and associated dependencies if
    # there are any core URIs; there should never be any when building a
    # standalone module project.
    LIST (LENGTH _core_output_files _num_core)
    IF (_num_core GREATER 0)
      ADD_CUSTOM_TARGET (check_core_uris 
        DEPENDS ${_core_output_files} VERBATIM)
      ADD_DEPENDENCIES(check_uris check_core_uris)
      ADD_DEPENDENCIES(zorbacmd check_core_uris)
      GET_PROPERTY (_corelibs GLOBAL PROPERTY ZORBA_CORE_MODULE_LIB_TARGETS)
      ADD_DEPENDENCIES(zorbacmd ${_corelibs})
      SET_TARGET_PROPERTIES(check_core_uris PROPERTIES FOLDER "Modules")
    ENDIF (_num_core GREATER 0)
    SET_PROPERTY (GLOBAL PROPERTY ZORBA_URI_FILES)

    #add 'xqdoc' and 'xqdoc-xml' targets
    ADD_XQDOC_TARGETS()
  ENDIF (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)

  # Now, do things that should be done at the end of *any* project, not
  # just the top-level project.

  # Generate project's projectConfig.cmake file, unless the project told
  # us not to by setting the global property ZORBA_PROJECT_UNAVAILABLE to true.
  # QQQ need to create an installable version of this too, once we know
  # how installing a module package should work.
  GET_PROPERTY (_unavailable GLOBAL PROPERTY ZORBA_PROJECT_UNAVAILABLE)
  IF (NOT _unavailable)
    GET_PROPERTY (ZORBA_MODULE_LIBRARIES
      GLOBAL PROPERTY "${PROJECT_NAME}_LIBRARIES")
    CONFIGURE_FILE("${Zorba_EXTERNALMODULECONFIG_FILE}"
      "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake" @ONLY)
  ELSE (NOT _unavailable)
    # Reset this variable so next project will still work
    SET_PROPERTY (GLOBAL PROPERTY ZORBA_PROJECT_UNAVAILABLE)
  ENDIF (NOT _unavailable)

ENDMACRO (DONE_DECLARING_ZORBA_URIS)

# Initialize expected failures and zorba modules output files when
# first included
set (expected_failures_file "${CMAKE_BINARY_DIR}/ExpectedFailures.xml")
set (zorba_manifest_file "${CMAKE_BINARY_DIR}/ZorbaManifest.xml")
GET_PROPERTY (is_init GLOBAL PROPERTY ZorbaModule_initialized)
IF (NOT is_init)
  file (WRITE "${expected_failures_file}" "")
  file (WRITE "${zorba_manifest_file}"
    "<z:manifest xmlns:z=\"http://zorba.io/manifest\">\n")
  SET_PROPERTY (GLOBAL PROPERTY ZorbaModule_initialized 1)
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

  set_tests_properties ("${testname}"
    PROPERTIES WILL_FAIL ${willfail})

  # Also store the name and bug ID of this test in our output file
  file (APPEND "${expected_failures_file}"
    "<Test name=\"${testname}${SUFFIX}\" bug=\"${bugid}\"/>")

ENDMACRO(expected_failure)

# Convenience macro for adding tests in a standard format. All test
# cases (.xq files) in "Queries" subdirectory of the named directory
# will be automatically added for CTest. Each test will be named
# ${PROJECT_NAME}/<filename>, where <filename> is the path relative to
# the Queries/ subdirectory.
# 
# The optional second argument exists for Windows. Normally,
# EXPECTED_FAILURE() can be used even for tests that crash
# (segfault). However, on Windows, when a test crashes, it pops up a
# dialog box. This prevents tests running unattended.  Since it is not
# possible with CMake to remove a test once added,
# ADD_TEST_DIRECTORY() needs to be told not to add the test at all on
# Windows platforms. Therefore, after the directory name, you may
# additional arguments in the form (testname bugnumber testname
# bugnumber ...) to ADD_TEST_DIRECTORY().  On Windows, the named tests
# will be skipped entirely. On other platforms, they will be passed to
# EXPECTED_FAILURE() with the corresponding bug number.
#
# This second argument should only be used for test cases that are 
# currently *crashing* on Windows. If the test is simply failing, then
# you should use EXPECTED_FAILURE() after calling ADD_TEST_DIRECTORY().
#
# Parameters:
#   TEST_DIR - all the .xq files in this directory will be added as tests
#   (additional args)  - expected crashing tests, as discussed above.
MACRO (ADD_TEST_DIRECTORY TEST_DIR)
  # QQQ error-check: Queries directory exists, some tests found...
  FILE(GLOB_RECURSE TESTFILES FOLLOW_SYMLINKS
    RELATIVE "${TEST_DIR}/Queries" "${TEST_DIR}/Queries/*.xq")

  # Convert extra arguments to two lists: test names and bug IDs
  SET (crash_tests)
  SET (crash_bugids)
  SET (known_crashes ${ARGN})
  LIST (LENGTH known_crashes num_crashes)
  WHILE (num_crashes GREATER 0)
    LIST (GET known_crashes 0 _testcase)
    LIST (APPEND crash_tests ${_testcase})
    LIST (GET known_crashes 1 _bugid)
    LIST (APPEND crash_bugids ${_bugid})
    LIST (REMOVE_AT known_crashes 0 1)
    MATH (EXPR num_crashes "${num_crashes} - 2")
  ENDWHILE (num_crashes GREATER 0)

  IF(WIN32)
    SET(PATH_SEP ",")
  ELSE(WIN32)
    SET(PATH_SEP ":")
  ENDIF(WIN32)
  SET(TESTCOUNTER 0)
  FOREACH(TESTFILE ${TESTFILES})
    SET(TESTNAME "${PROJECT_NAME}/${TESTFILE}")

    # See if this test is in the known-crashing list
    SET (_crash_bugid)
    LIST (FIND crash_tests ${TESTNAME} _crash_idx)
    IF (${_crash_idx} GREATER -1)
      # Get corresponding bug ID
      LIST (GET crash_bugids ${_crash_idx} _crash_bugid)
      # Remove from known-crashing list
      LIST (REMOVE_AT crash_tests ${_crash_idx})
    ENDIF (${_crash_idx} GREATER -1)

    # On Windows, skip calling ADD_TEST() for any known crashing tests
    IF (WIN32 AND (${_crash_idx} GREATER -1) )
      MESSAGE (STATUS "WARNING: Skipping test case ${TESTNAME} which is expected to crash - bug ${_crash_bugid}")
    ELSE (WIN32 AND (${_crash_idx} GREATER -1) )
      # DEPENDENCY_MODULE_PATH will always start with an appropriate
      # path separator
      ADD_TEST(${TESTNAME} "${Zorba_TESTDRIVER}"
	"--rbkt-src" "${TEST_DIR}"
	"--rbkt-bin" "${PROJECT_BINARY_DIR}/test/rbkt"
	"--module-path"
	"${CMAKE_BINARY_DIR}/URI_PATH/${PATH_SEP}${DEPENDENCY_MODULE_PATH}"
	"${TESTFILE}")
      # Create test results output directory, if it doesn't exist
      GET_FILENAME_COMPONENT(_bucket_path "${TESTFILE}" PATH)
      SET (_full_bucket_path
	"${PROJECT_BINARY_DIR}/test/rbkt/QueryResults/${_bucket_path}")
      IF (NOT EXISTS "${_full_bucket_path}")
	FILE (MAKE_DIRECTORY "${_full_bucket_path}")
      ENDIF (NOT EXISTS "${_full_bucket_path}")

      # On non-Windows, call EXPECTED_FAILURE() for known crashes
      IF (${_crash_idx} GREATER -1)
	MESSAGE (STATUS "Marking test case ${TESTNAME} as expected to crash - bug ${bugid}")
	EXPECTED_FAILURE (${TESTNAME} ${_bugid})
      ENDIF (${_crash_idx} GREATER -1)

      MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
      MATH(EXPR TESTMOD "${TESTCOUNTER}%100")
      IF (${TESTMOD} EQUAL 0)
	MESSAGE(STATUS "Adding another 100 Tests")
      ENDIF (${TESTMOD} EQUAL 0)

    ENDIF (WIN32 AND (${_crash_idx} GREATER -1) )

  ENDFOREACH(TESTFILE)

  # Ensure that known-crashes list is empty - otherwise some tests were
  # named that didn't exist
  IF (NOT "${crash_tests}" STREQUAL "")
    MESSAGE (FATAL_ERROR "The following non-existing test cases were passed to ADD_TEST_DIRECTORY(): ${crash_tests}")
  ENDIF (NOT "${crash_tests}" STREQUAL "")

  MESSAGE(STATUS "Added ${TESTCOUNTER} tests in ${TEST_DIR}")
ENDMACRO (ADD_TEST_DIRECTORY)

# This macro easies the process of adding test for store dependent
# executables. It has the same naming convection for the target as the
# macro that is used to generated store dependent executables (thus,
# 'testdriver' must be passed as TARGET if the test should be executed
# with the executable testdriver or testdriver_firststore).
#
# Syntax:
#
#   ZORBA_ADD_TEST(NAME TARGET ...)
#
#     NAME - the name of the added test
#     TARGET - target that will be executed when the test is run. For the registered store,
#              a suffix will be added to the target
#              (similar convention than in ZORBA_GENERATE_EXE)
#     ... - arguments that will be passed to the target
#
MACRO(ZORBA_ADD_TEST NAME TARGET ...)
  GET_TARGET_PROPERTY (TARGET_LOCATION "${TARGET}" LOCATION)
  IF (WIN32)
    IF (MSVC_IDE)
      STRING (REPLACE "/${CMAKE_CFG_INTDIR}" "" TARGET_LOCATION ${TARGET_LOCATION})
    ENDIF (MSVC_IDE)
    STRING (REPLACE ".exe" ".bat" TARGET_LOCATION ${TARGET_LOCATION})
  ENDIF(WIN32)

  #We cannot just use ARGN, as this will not work with arguments that contain ;, even if escaped
  #A more recent version of CMake contains a $<SEMICOLON> special token, but this version of cmake
  #is unsupported by some of our target platforms and it doesn't seem to work when used with variadic
  #functions
  ADD_TEST ("${NAME}" "${TARGET_LOCATION}" ${ARGV2}  ${ARGV3}  ${ARGV4}  ${ARGV5}  ${ARGV6}  ${ARGV7}  ${ARGV8}  ${ARGV9} 
                                           ${ARGV10} ${ARGV11} ${ARGV12} ${ARGV13} ${ARGV14} ${ARGV15} ${ARGV16} ${ARGV17}
                                           ${ARGV18} ${ARGV19} ${ARGV20} ${ARGV21} ${ARGV22} ${ARGV23} ${ARGV24} ${ARGV25}
                                           ${ARGV26} ${ARGV27} ${ARGV28} ${ARGV29} ${ARGV30} ${ARGV31} ${ARGV32} ${ARGV33})
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
# ZORBA_XQDOC_HTML_XQ - points to file xqdoc-html.xq
# ZORBA_XQDOC_OUTPUT_DIR - points to the output dir for xml and html
# ZORBA_XHTML_REQUISITES_PATH - points to the dir containing the html requisites (images, lib, styles, templates dirs)
# Zorba_EXE - points to zorba.exe (or zorba.bat)
MACRO (ADD_XQDOC_TARGETS)
  MESSAGE(STATUS "ADD_XQDOC_TARGETS")

  SET(ZORBA_XQDOC_HTML_XQ
    ${CMAKE_BINARY_DIR}/xqdoc/generator/xqdoc.xq
      CACHE PATH
      "The XQDoc XHTML generator for external modules.")

  SET(ZORBA_XHTML_REQUISITES_PATH
      ${CMAKE_SOURCE_DIR}/doc/zorba/xqdoc
      CACHE PATH
      "Dir where to the XHTML requisites are stored.")
  ADD_CUSTOM_TARGET(xqdoc
    ${Zorba_EXE}
      --omit-xml-declaration
      -f
      -q "${ZORBA_XQDOC_HTML_XQ}"
      -e "\"zorbaManifestPath:=${zorba_manifest_file}\""
      -e "\"xhtmlRequisitesPath:=${ZORBA_XHTML_REQUISITES_PATH}\""
      -e "\"xqdocBuildPath:=${CMAKE_BINARY_DIR}/doc/zorba/xqdoc\""
      -e "\"zorbaVersion:=${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}\""
      DEPENDS ${zorba_manifest_file}
      COMMENT "Building XQDoc XHTML documentation ..."
  )
  MESSAGE(STATUS "  added target xqdoc")
  ADD_DEPENDENCIES(xqdoc xqdoc-xml modules_svg)
  SET_TARGET_PROPERTIES (xqdoc PROPERTIES
    EXCLUDE_FROM_DEFAULT_BUILD 1
    FOLDER "Docs"
  )
  ADD_TEST( test/xqdoc/make_xqdoc
      ${Zorba_EXE}
      --omit-xml-declaration
      -f
      -q "${ZORBA_XQDOC_HTML_XQ}"
      -e "zorbaManifestPath:=${zorba_manifest_file}"
      -e "xhtmlRequisitesPath:=${ZORBA_XHTML_REQUISITES_PATH}"
      -e "xqdocBuildPath:=${CMAKE_BINARY_DIR}/test/rbkt/QueryResults/zorba/xqdoc"
      -e "zorbaVersion:=${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}"
  )
  SET_TESTS_PROPERTIES("test/xqdoc/make_xqdoc" PROPERTIES PASS_REGULAR_EXPRESSION "XQDoc generated successfully!")
  MESSAGE(STATUS "  added test test/xqdoc/make_xqdoc")
  MESSAGE(STATUS "ADD_XQDOC_TARGETS END")
ENDMACRO(ADD_XQDOC_TARGETS)


# Macro that takes care of the CMake module path in a project. This will prepend
# "cmake_modules" and "cmake_modules/Windows" to the existing CMAKE_MODULE_PATH
MACRO (SET_CMAKE_MODULE_PATH)

  # first we prepend the "cmake_modules" directory in the project root
  SET (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules ${CMAKE_MODULE_PATH})

  # now we prepend the "cmake_modules/Windows" directory in the project root
  # this takes care about the finding and installing DLL for these libraries
  IF (WIN32)
    # Since the user can install libraries on Windows at any location we use
    # proxy modules that try to guess first the location of the required third
    # party libraries. This will search in order in:
    # 1. the path pointed by ZORBA_THIRD_PARTY_REQUIREMENTS
    # 2. the Program Files directory available on the users computer
    # 3. the PATH environment variable
    # The logic is implemented by the macros in the ProxyFindModule.cmake module.
    SET (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules/Windows ${CMAKE_MODULE_PATH})
  ENDIF (WIN32)
  
ENDMACRO (SET_CMAKE_MODULE_PATH)
