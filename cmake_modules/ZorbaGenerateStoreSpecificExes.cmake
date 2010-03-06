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
# the directory where this macro is executabed and must the following name: '${EXE_NAME}.cpp'. 
# If the cmake variable ZORBA_BUILD_STATIC_LIBRARY is set to "ON", the macro produces additinally a 
# static executable.
#
# The resulting executable has the name ${EXE_NAME}_${ZORBA_STORE_NAME} or 
# ${EXE_NAME}_${ZORBA_STORE_NAME}_static if the store name is not equal "simplestore". Otherwise, 
# the name is ${EXE_NAME} or ${EXE_NAME}_static.
#
# Synatx:
# 
#   ZORBA_GENERATE_STORE_SPECIFIC_EXES(EXE_NAME DEPEND_SRCS DEPEND_LIBS NEW_NAME) 
#   
#     EXE_NAME - the name of the executable. Per convention, the file that contains the main function 
#                and must be located in the directory where the invocation of this function is located.
#     DEPEND_SRCS - additional source files which will be compiled and linked to the created libraries
#     DEPEND_LIBS - libraries (exception zorba-store libs) to which the created libraries depend on
#     NEW_NAME - If this variable is not equal "", the executables will be renamed to NEW_NAME
#     INSTALL_DESTINATION - if non empty string, the created executable(s) is(are) installed to 
#                           the passed destination
#
#
MACRO(ZORBA_GENERATE_STORE_SPECIFIC_EXES EXE_NAME DEPEND_SRCS DEPEND_LIBS NEW_NAME INSTALL_DESTINATION)
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

    IF (NOT ${INSTALL_DESTINATION} STREQUAL "")
      INSTALL(TARGETS ${EXE_NAME}${SUFFIX} DESTINATION ${INSTALL_DESTINATION})
    ENDIF (NOT ${INSTALL_DESTINATION} STREQUAL "")

    IF (ZORBA_BUILD_STATIC_LIBRARY)
      ADD_EXECUTABLE("${EXE_NAME}${SUFFIX}_static" ${SRCS})
      SET_TARGET_PROPERTIES("${EXE_NAME}${SUFFIX}_static" PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)
      TARGET_LINK_LIBRARIES("${EXE_NAME}${SUFFIX}_static" 
                            "zorba_${ZORBA_STORE_NAME}_static"
                            ${DEPEND_LIBS})
      IF (NOT ${NEW_NAME} STREQUAL "")
        SET_TARGET_PROPERTIES("${EXE_NAME}${SUFFIX}_static" PROPERTIES OUTPUT_NAME "${NEW_NAME}${SUFFIX}_static")
      ENDIF (NOT ${NEW_NAME} STREQUAL "")
      IF (INSTALL_DESTINATION)
        INSTALL(TARGETS "${EXE_NAME}${SUFFIX}_static" DESTINATION ${INSTALL_DESTINATION})
      ENDIF (INSTALL_DESTINATION)
    ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

  ENDFOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
ENDMACRO(ZORBA_GENERATE_STORE_SPECIFIC_EXES)



