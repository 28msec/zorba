# Copyright 2006-2011 The FLWOR Foundation.
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
#
#
# -helper macro to add a "doc" target with CMake build system. 
# and configure doxy.config.in to doxy.config
#
# target "doc" allows building the documentation with doxygen/dot on WIN32 and Linux
# Creates .chm windows help file if MS HTML help workshop 
# (available from http://msdn.microsoft.com/workshop/author/htmlhelp)
# is installed with its DLLs in PATH.
#
#
# Please note, that the tools, e.g.:
# doxygen, dot, latex, dvips, makeindex, gswin32, etc.
# must be in path.
#
# Note about Visual Studio Projects: 
# MSVS hast its own path environment which may differ from the shell.
# See "Menu Tools/Options/Projects/VC++ Directories" in VS 7.1
#
# author Jan Woetzel 2004-2006
# www.mip.informatik.uni-kiel.de/~jw

MACRO (ZORBA_DOXYGEN DOXYGEN_SOURCE DOXYGEN_BINARY DOXYGEN_TARGET_NAME)
  IF (DOXYGEN_FOUND)
    # the FindDoxygen module doesn't set DOXYGEN_DOT_FOUND like it is
    # supposed to, so here we have a workaround.
    IF (DOXYGEN_DOT_EXECUTABLE)

      FIND_PROGRAM(DOXYGEN_DOT_EXECUTABLE_PATH
        NAMES dot
        PATHS 
          "$ENV{ProgramFiles}/Graphviz 2.21/bin"
          "C:/Program Files/Graphviz 2.21/bin"
          "$ENV{ProgramFiles}/ATT/Graphviz/bin"
          "C:/Program Files/ATT/Graphviz/bin"
          [HKEY_LOCAL_MACHINE\\SOFTWARE\\ATT\\Graphviz;InstallPath]/bin
          /Applications/Graphviz.app/Contents/MacOS
          /Applications/Doxygen.app/Contents/Resources
          /Applications/Doxygen.app/Contents/MacOS
          DOC "Graphviz Dot tool for using Doxygen"
      )

      SET(DOXYGEN_DOT_FOUND "YES")
      # The Doxyfile wants the path to Dot, not the entire path and executable
      GET_FILENAME_COMPONENT(DOXYGEN_DOT_PATH "${DOXYGEN_DOT_EXECUTABLE}" PATH CACHE)

    ENDIF (DOXYGEN_DOT_EXECUTABLE)

    # click+jump in Emacs and Visual Studio (for doxy.config) (jw)
    IF (CMAKE_BUILD_TOOL MATCHES "(msdev|devenv)")
      SET(DOXY_WARN_FORMAT "\"$file($line) : $text \"")
    ELSE (CMAKE_BUILD_TOOL MATCHES "(msdev|devenv)")
      SET(DOXY_WARN_FORMAT "\"$file:$line: $text \"")
    ENDIF (CMAKE_BUILD_TOOL MATCHES "(msdev|devenv)")

    # we need latex for doxygen because of the formulas
    FIND_PACKAGE (LATEX)
    IF (NOT LATEX_COMPILER)
      MESSAGE(STATUS "latex command LATEX_COMPILER not found but usually required. You will probably get warnings and user inetraction on doxy run.")
    ENDIF (NOT LATEX_COMPILER)
    IF (NOT MAKEINDEX_COMPILER)
      MESSAGE (STATUS "makeindex command MAKEINDEX_COMPILER not found but usually required.")
    ENDIF (NOT MAKEINDEX_COMPILER)
    IF (NOT DVIPS_CONVERTER)
      MESSAGE (STATUS "dvips command DVIPS_CONVERTER not found but usually required.")
    ENDIF (NOT DVIPS_CONVERTER)

    IF (EXISTS "${DOXYGEN_SOURCE}/doxy.config.in")
      MESSAGE (STATUS "configured ${DOXYGEN_SOURCE}/doxy.config.in --> ${DOXYGEN_BINARY}/doxy.config")
      CONFIGURE_FILE (
        ${DOXYGEN_SOURCE}/doxy.config.in 
        ${DOXYGEN_BINARY}/doxy.config
        @ONLY
      )
      # use (configured) doxy.config from (out of place) BUILD tree:
      SET (DOXY_CONFIG "${DOXYGEN_BINARY}/doxy.config")
    ELSE (EXISTS "${DOXYGEN_SOURCE}/doxy.config.in")
      # use static hand-edited doxy.config from SOURCE tree:
      SET (DOXY_CONFIG "${DOXYGEN_SOURCE}/doxy.config")
      IF (EXISTS "${DOXYGEN_SOURCE}/doxy.config")
        MESSAGE (STATUS "WARNING: using existing ${DOXYGEN_SOURCE}/doxy.config instead of configuring from doxy.config.in file.")
      ELSE (EXISTS "${DOXYGEN_SOURCE}/doxy.config")
        IF (EXISTS "${CMAKE_MODULE_PATH}/doxy.config.in")
          # using template doxy.config.in
          MESSAGE (STATUS "configured ${CMAKE_CMAKE_MODULE_PATH}/doxy.config.in --> ${DOXYGEN_BINARY}/doxy.config")
          CONFIGURE_FILE (
            ${CMAKE_MODULE_PATH}/doxy.config.in 
            ${DOXYGEN_BINARY}/doxy.config
            @ONLY
          )
          SET (DOXY_CONFIG "${DOXYGEN_BINARY}/doxy.config")
        ELSE (EXISTS "${CMAKE_MODULE_PATH}/doxy.config.in")
          # failed completely...
          MESSAGE (SEND_ERROR "Please create ${DOXYGEN_SOURCE}/doxy.config.in (or doxy.config as fallback)")
        ENDIF (EXISTS "${CMAKE_MODULE_PATH}/doxy.config.in")

      ENDIF (EXISTS "${DOXYGEN_SOURCE}/doxy.config")
    ENDIF (EXISTS "${DOXYGEN_SOURCE}/doxy.config.in")

    SET (DOXY_CONFIG_NATIVE)
    FILE (TO_NATIVE_PATH ${DOXY_CONFIG} DOXY_CONFIG_NATIVE)
    ADD_CUSTOM_TARGET (${DOXYGEN_TARGET_NAME} "${DOXYGEN_EXECUTABLE}" "${DOXY_CONFIG_NATIVE}")
    SET_TARGET_PROPERTIES(${DOXYGEN_TARGET_NAME} PROPERTIES
      FOLDER "Docs"
    )

    # create a windows help .chm file using hhc.exe
    # HTMLHelp DLL must be in path!
    # fallback: use hhw.exe interactively
    IF (WIN32)
      FIND_PACKAGE (HTMLHelp)
      IF (HTML_HELP_COMPILER)      
        SET (TMP "${DOXYGEN_BINARY}\\Doc\\html\\index.hhp")
        STRING (REGEX REPLACE "[/]" "\\\\" HHP_FILE ${TMP} )
        ADD_CUSTOM_TARGET (winhelp_${DOXYGEN_TARGET_NAME} ${HTML_HELP_COMPILER} ${HHP_FILE})
        ADD_DEPENDENCIES (winhelp_${DOXYGEN_TARGET_NAME} ${DOXYGEN_TARGET_NAME})
        SET_TARGET_PROPERTIES(winhelp_${DOXYGEN_TARGET_NAME} PROPERTIES
          FOLDER "Docs"
        )

        IF (NOT TARGET_DOC_SKIP_INSTALL)
        # install windows help?
        # determine useful name for output file 
        # should be project and version unique to allow installing 
        # multiple projects into one global directory      
        IF (EXISTS "${PROJECT_BINARY_DIR}/Doc/html/index.chm")
          IF (PROJECT_NAME)
            SET (OUT "${PROJECT_NAME}")
          ELSE (PROJECT_NAME)
            SET (OUT "Documentation") # default
          ENDIF (PROJECT_NAME)
          IF (${PROJECT_NAME}_VERSION_MAJOR)
            SET (OUT "${OUT}-${${PROJECT_NAME}_VERSION_MAJOR}")
            IF (${PROJECT_NAME}_VERSION_MINOR)
              SET (OUT  "${OUT}.${${PROJECT_NAME}_VERSION_MINOR}")
              IF (${PROJECT_NAME}_VERSION_PATCH)
                SET(OUT "${OUT}.${${PROJECT_NAME}_VERSION_PATCH}")      
              ENDIF (${PROJECT_NAME}_VERSION_PATCH)
            ENDIF (${PROJECT_NAME}_VERSION_MINOR)
          ENDIF (${PROJECT_NAME}_VERSION_MAJOR)
          # keep suffix
          SET (OUT  "${OUT}.chm")

          # create target used by install and package commands 
          INSTALL (
            FILES "${PROJECT_BINARY_DIR}/Doc/html/index.chm"
            DESTINATION "doc"
            RENAME "${OUT}"
          )
        ENDIF (EXISTS "${PROJECT_BINARY_DIR}/Doc/html/index.chm")
        ENDIF (NOT TARGET_DOC_SKIP_INSTALL)

      ENDIF (HTML_HELP_COMPILER)
    ENDIF (WIN32) 
  ENDIF (DOXYGEN_FOUND)
ENDMACRO (ZORBA_DOXYGEN)
