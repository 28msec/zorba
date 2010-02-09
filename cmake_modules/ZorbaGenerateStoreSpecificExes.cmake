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
#
# This macro helps creating executables that are store dependent (e.g. one zorbacmd version must be 
# compiled and linked for each registered store). This macro iterates through the CMake variable 
# ZORBA_STORE_NAMES and creates one executable for each store name.
# Per convention, the source file that contains the main function of the executable must be located in 
# the directory where this macro is executabed and must the following name: 'EXE_NAME.cpp.in'. 
# To enable store dependent code in the source file, the macro sets the cmake variable ZORBA_STORE_NAME. 
# This variable can be used in the source file by adding the replacement @ZORBA_STORE_NAME@. Logically, 
# all other available cmake variables can be used from this source file because the cmake command
# CONFIGURE_FILE is used to generate the store specific sources.
# The resulting libraries are named by the following convention: Executables that are linked agains a store lib
# other than simplestore contain the suffix '_${ZORBA_STORE_NAME}'.
# If the cmake variable ZORBA_BUILD_STATIC_LIBRARY is set to "ON", the macro produces static libraries and add
# the additional suffix '_static' to them.
#
# Synatx:
# 
#   ZORBA_GENERATE_STORE_SPECIFIC_EXES(EXE_NAME DEPEND_SRCS DEPEND_LIBS NEW_NAME) 
#   
#     EXE_NAME - the name of the executable. Per convention, the file that contains the main function 
#                and the CMake replacement @ZORBA_STORE_NAME@ must have the name EXE_NAME.cpp.in and
#                must be located in the directory where the invocation of this function is located.
#     DEPEND_SRCS - additional source files which will be compiled and linked to the created libraries
#     DEPEND_LIBS - libraries (exception zorba-store libs) to which the created libraries depend on
#     NEW_NAME - If this variable is not equal "", the executables will be renamed to NEW_NAME
#
#
MACRO(ZORBA_GENERATE_STORE_SPECIFIC_EXES EXE_NAME DEPEND_SRCS DEPEND_LIBS NEW_NAME)
	# We need to change the CMAKE_CFG_INTDIR from the default value (a VS macro)
	# otherwise this will make CMake fail when searching for the zorba.exe, because
	# it does not know how to expand VS macros like $(OutDir).
	IF (MSVC_IDE)
		SET(CMAKE_CFG_INTDIR ${CMAKE_BUILD_TYPE})
	ENDIF (MSVC_IDE)

  FOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
    SET(SUFFIX)
    # simplestore executable doesn't need an extension
    IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
      SET(SUFFIX "_${ZORBA_STORE_NAME}")
    ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")

    SET( SRCS
      ${CMAKE_CURRENT_SOURCE_DIR}/${EXE_NAME}.cpp
      ${DEPEND_SRCS}
    )
    ADD_EXECUTABLE("${EXE_NAME}${SUFFIX}" ${SRCS})
    TARGET_LINK_LIBRARIES("${EXE_NAME}${SUFFIX}" 
                          "zorba_${ZORBA_STORE_NAME}"
                          ${DEPEND_LIBS})
    IF (NOT ${NEW_NAME} STREQUAL "")
      SET_TARGET_PROPERTIES("${EXE_NAME}${SUFFIX}" PROPERTIES OUTPUT_NAME "${NEW_NAME}${SUFFIX}")
    ENDIF (NOT ${NEW_NAME} STREQUAL "")

    INSTALL(TARGETS ${EXE_NAME}${SUFFIX} DESTINATION bin)

    IF (ZORBA_BUILD_STATIC_LIBRARY)
      ADD_EXECUTABLE("${EXE_NAME}${SUFFIX}_static" ${SRCS})
      SET_TARGET_PROPERTIES("${EXE_NAME}${SUFFIX}_static" PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)
      TARGET_LINK_LIBRARIES("${EXE_NAME}${SUFFIX}_static" 
                            "zorba_${ZORBA_STORE_NAME}_static"
                            ${DEPEND_LIBS})
      IF (NOT ${NEW_NAME} STREQUAL "")
        SET_TARGET_PROPERTIES("${EXE_NAME}${SUFFIX}_static" PROPERTIES OUTPUT_NAME "${NEW_NAME}${SUFFIX}_static")
      ENDIF (NOT ${NEW_NAME} STREQUAL "")
    ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

  ENDFOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
ENDMACRO(ZORBA_GENERATE_STORE_SPECIFIC_EXES)



