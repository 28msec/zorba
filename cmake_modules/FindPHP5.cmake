# - Find PHP5
# This module finds if PHP5 is installed and determines where the include files
# and libraries are. It also determines what the name of the library is. This
# code sets the following variables:
#
#  PHP5_INCLUDE_PATH       = path to where php.h can be found
#  PHP5_EXECUTABLE         = full path to the php5 binary
#
#  file is derived from FindPHP4.cmake
#

SET(PHP5_FOUND "NO")

SET(PHP5_POSSIBLE_INCLUDE_PATHS
  /usr/include/php5
  /usr/local/include/php5
  /usr/include/php
  /usr/local/include/php
  /usr/local/apache/php
  )

SET(PHP5_POSSIBLE_LIB_PATHS
  /usr/lib
  )

#FIND_PATH(PHP5_FOUND_INCLUDE_PATH main/php.h
#  ${PHP5_POSSIBLE_INCLUDE_PATHS})
#
#IF(PHP5_FOUND_INCLUDE_PATH)
#  SET(php5_paths "${PHP5_POSSIBLE_INCLUDE_PATHS}")
#  FOREACH(php5_path Zend main TSRM)
#    SET(php5_paths ${php5_paths} "${PHP5_FOUND_INCLUDE_PATH}/${php5_path}")
#  ENDFOREACH(php5_path Zend main TSRM)
#  SET(PHP5_INCLUDE_PATH "${php5_paths}" INTERNAL "PHP5 include paths")
#ENDIF(PHP5_FOUND_INCLUDE_PATH)

FIND_PROGRAM(PHP5_EXECUTABLE
  NAMES php5 php
  PATHS
  /usr/bin
  /usr/local/bin
  )

MARK_AS_ADVANCED(
  PHP5_EXECUTABLE
  PHP5_FOUND_INCLUDE_PATH
  )

IF(APPLE)
# this is a hack for now
  SET(CMAKE_SHARED_MODULE_CREATE_C_FLAGS
   "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS} -Wl,-flat_namespace")
  FOREACH(symbol
    _zend_throw_exception
    _zend_register_long_constant
    _zend_get_constant
    __zval_copy_ctor_func
    __convert_to_string
    __estrndup
    __efree
    __emalloc
    __estrdup
    __object_init_ex
    __zend_get_parameters_array_ex
    __zend_list_find
    __zval_copy_ctor
    _add_property_zval_ex
    _alloc_globals
    _compiler_globals
    _convert_to_double
    _convert_to_long
    _zend_error
    _zend_hash_find
    _zend_register_internal_class_ex
    _zend_register_list_destructors_ex
    _zend_register_resource
    _zend_rsrc_list_get_rsrc_type
    _zend_wrong_param_count
    _zval_used_for_init
    )
    SET(CMAKE_SHARED_MODULE_CREATE_C_FLAGS
      "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS},-U,${symbol}")
  ENDFOREACH(symbol)
ENDIF(APPLE)


FIND_PROGRAM(PHP5_CONFIG_EXECUTABLE
  NAMES php5-config php-config
  PATHS
  /usr/bin
  /usr/local/bin
  )

EXECUTE_PROCESS(COMMAND ${PHP5_CONFIG_EXECUTABLE} --version
   OUTPUT_VARIABLE PHP5_VERSION)

EXECUTE_PROCESS(COMMAND ${PHP5_CONFIG_EXECUTABLE} --extension-dir
   OUTPUT_VARIABLE PHP5_EXTENSION_DIR)
STRING(REPLACE "\n" "" PHP5_EXTENSION_DIR "${PHP5_EXTENSION_DIR}")

EXECUTE_PROCESS(COMMAND ${PHP5_CONFIG_EXECUTABLE} --includes
   OUTPUT_VARIABLE PHP5_INCLUDES)
STRING(REPLACE "-I" ";" PHP5_INCLUDES "${PHP5_INCLUDES}")
STRING(REPLACE " " "" PHP5_INCLUDES "${PHP5_INCLUDES}")
STRING(REPLACE "\n" "" PHP5_INCLUDES "${PHP5_INCLUDES}")
LIST(GET PHP5_INCLUDES 0 PHP5_INCLUDE_DIR)

set(PHP5_MAIN_INCLUDE_DIR ${PHP5_INCLUDE_DIR}/main)
set(PHP5_TSRM_INCLUDE_DIR ${PHP5_INCLUDE_DIR}/TSRM)
set(PHP5_ZEND_INCLUDE_DIR ${PHP5_INCLUDE_DIR}/Zend)
set(PHP5_REGEX_INCLUDE_DIR ${PHP5_INCLUDE_DIR}/regex)
set(PHP5_EXT_INCLUDE_DIR ${PHP5_INCLUDE_DIR}/ext)
set(PHP5_DATE_INCLUDE_DIR ${PHP5_INCLUDE_DIR}/ext/date/lib)
set(PHP5_STANDARD_INCLUDE_DIR ${PHP5_INCLUDE_DIR}/ext/standard)

MESSAGE(STATUS ${PHP5_MAIN_INCLUDE_DIR})

IF(PHP5_VERSION LESS 5)
    MESSAGE(FATAL_ERROR "PHP version is not 5 or later")
ENDIF(PHP5_VERSION LESS 5)

IF(PHP5_EXECUTABLE AND PHP5_INCLUDES)
    SET(PHP5_FOUND "yes")
    MESSAGE(STATUS "Found PHP5-Version ${PHP5_VERSION}")
ENDIF(PHP5_EXECUTABLE AND PHP5_INCLUDES)
