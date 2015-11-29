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
# compiled and linked for each registered store). This macro takes the CMake variable 
# ZORBA_STORE_NAME and creates one executable with this name.
# Per convention, the source file that contains the main function of the executable must be located in 
# the directory where this macro is executabed and must the following name: '${EXE_NAME}.cpp'. 
#
# The resulting executable has the name ${EXE_NAME}_${ZORBA_STORE_NAME} 
# if the store name is not equal "simplestore". Otherwise, 
# the name is ${EXE_NAME}.
#
# Synatx:
# 
#   ZORBA_GENERATE_EXE(EXE_NAME DEPEND_SRCS DEPEND_LIBS NEW_NAME) 
#   
#     EXE_NAME - the name of the executable.
#     SRCS - source files which will be compiled and linked to the created libraries
#     DEPEND_LIBS - libraries (exception zorba-store libs) to which the created libraries depend on
#     NEW_NAME - If this variable is not equal "", the executables will be renamed to NEW_NAME
#     INSTALL_DESTINATION - if non empty string, the created executable(s) is(are) installed to 
#                           the passed destination
#
#
MACRO(ZORBA_GENERATE_EXE EXE_NAME SRCS DEPEND_LIBS NEW_NAME INSTALL_DESTINATION)

  SET (SUFFIX)
  # simplestore executable doesn't need an extension
  IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
    SET (SUFFIX "_${ZORBA_STORE_NAME}")
  ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")

  ADD_EXECUTABLE ("${EXE_NAME}${SUFFIX}" ${SRCS})
  TARGET_LINK_LIBRARIES (
    "${EXE_NAME}${SUFFIX}" 
    "zorba_${ZORBA_STORE_NAME}"
    ${DEPEND_LIBS}
  )
  IF (NOT ${NEW_NAME} STREQUAL "")
    SET_TARGET_PROPERTIES ("${EXE_NAME}${SUFFIX}" PROPERTIES OUTPUT_NAME "${NEW_NAME}${SUFFIX}")
  ENDIF (NOT ${NEW_NAME} STREQUAL "")
  
  # select an appropriate folder to put this target into in the IDE
  IF (${EXE_NAME} MATCHES ".*(T|t)est.*")
    SET (folder "Tests")
  ELSEIF (${EXE_NAME} MATCHES ".*(E|e)xample.*")
    SET (folder "Examples")
  ENDIF (${EXE_NAME} MATCHES ".*(T|t)est.*")
  SET_TARGET_PROPERTIES ("${EXE_NAME}${SUFFIX}" PROPERTIES
    FOLDER "${folder}"
  )

  IF (NOT ${INSTALL_DESTINATION} STREQUAL "")
    INSTALL (TARGETS ${EXE_NAME}${SUFFIX} DESTINATION ${INSTALL_DESTINATION})
  ENDIF (NOT ${INSTALL_DESTINATION} STREQUAL "")

  IF (WIN32)
    # generate list of bat scripts to set the PATH variable for the executables
    IF (NOT ${NEW_NAME} STREQUAL "")
      SET (ZORBA_EXE_NAME "${NEW_NAME}${SUFFIX}")
    ELSE (NOT ${NEW_NAME} STREQUAL "")
      SET (ZORBA_EXE_NAME "${EXE_NAME}${SUFFIX}")
    ENDIF (NOT ${NEW_NAME} STREQUAL "")

    SET (ZORBA_EXE_SCRIPT_LIST "${ZORBA_EXE_SCRIPT_LIST};${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_EXE_NAME}.bat;"
      CACHE STRING "List of Windows batch scripts to be generated, one for each executable" FORCE
    )


    # generate list of Visual Studio project files to set the PATH variable
    IF (MSVC_IDE)
      SET (SYSTEM_NAME $ENV{USERDOMAIN})
      SET (USER_NAME $ENV{USERNAME})
      SET (ZORBA_VC_PROJECT_FILE_LIST "${ZORBA_VC_PROJECT_FILE_LIST};${EXE_NAME}.vcproj.${SYSTEM_NAME}.${USER_NAME}.user"
        CACHE STRING "List of Visual Studio project files to be generated, one for each executable" FORCE
      )
    ENDIF (MSVC_IDE)
  ENDIF (WIN32)
  
ENDMACRO (ZORBA_GENERATE_EXE)


# This macro will read the ZORBA_EXE_SCRIPT_LIST and ZORBA_VC_PROJECT_CONFIG_FILE 
# environment variables and will generate them near each corresponding executable.
# This macro must be invoked AFTER all the required libraries have been searched
# for (both Zorba and external modules) in order to set a correct path in the
# scripts.
MACRO (ZORBA_GENERATE_EXE_HELPERS_WIN32)

  IF (NOT WIN32)
    MESSAGE (FATAL_ERROR "This macro is intended only for Windows platforms.")
  ENDIF (NOT WIN32)

  FOREACH (SCRIPT ${ZORBA_EXE_SCRIPT_LIST})

    MESSAGE (STATUS "Adding exe script: ${SCRIPT}")

    # used to make a difference between VS and NMake
    IF (MSVC_IDE)
      SET (IDE "MSVC")
    ENDIF (MSVC_IDE)
    # used to know where zorba_simplestore.dll is
    FILE (TO_NATIVE_PATH "${CMAKE_BINARY_DIR}" CMAKE_BINARY_DIR_NATIVE)
    # used to find out the original executable name
    FILE (TO_NATIVE_PATH "${SCRIPT}" SCRIPT_NATIVE)

    # ZORBA_REQUIRED_DLL_PATHS is also needed and picked from the CACHE
    CONFIGURE_FILE ("${CMAKE_SOURCE_DIR}/scripts/win_exec.bat.in" ${SCRIPT} @ONLY)

  ENDFOREACH (SCRIPT)

  FOREACH (VCFILE ${ZORBA_VC_PROJECT_FILE_LIST})
    # Do not overwrite old property files. The user might have adapted something.
    IF (NOT EXISTS ${VCFILE})
      CONFIGURE_FILE (${CMAKE_SOURCE_DIR}/cmake_modules/VCProject.vcproj.in ${VCFILE})
    ENDIF (NOT EXISTS ${VCFILE})
  ENDFOREACH(VCFILE)


ENDMACRO (ZORBA_GENERATE_EXE_HELPERS_WIN32)
