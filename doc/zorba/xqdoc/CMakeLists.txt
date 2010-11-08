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

SET(XQDOC_DEPENDS)

IF(NOT ZORBA_WITH_FILE_ACCESS)
  MESSAGE(WARNING "Can not build XQDoc documentation because 'File' module is not present")
ELSE(NOT ZORBA_WITH_FILE_ACCESS)

# find all files required for xqdoc generation
# i.e. modules, templates, and xquery generator queries
FILE(GLOB_RECURSE XQ_MODULES ${CMAKE_SOURCE_DIR}/modules/*.xq)
LIST(APPEND XQDOC_DEPENDS ${XQ_MODULES})

FILE(GLOB_RECURSE XQDOC_TEMPLATES ${CMAKE_CURRENT_SOURCE_DIR}/templates/*)
LIST(APPEND XQDOC_DEPENDS ${XQDOC_TEMPLATES})

FILE(GLOB_RECURSE XQDOC_GENERATORS ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
LIST(APPEND XQDOC_DEPENDS ${XQDOC_GENERATORS})

#create the xhtml folder
IF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/xhtml")
  FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/xhtml)
  MESSAGE(STATUS "created directory ${CMAKE_CURRENT_BINARY_DIR}/xhtml")
ENDIF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/xhtml")

#gather all the schemas and copy them into the ${CMAKE_CURRENT_BINARY_DIR}/xhtml/schemas folder
FILE(GLOB_RECURSE XSD_SCHEMAS ${CMAKE_SOURCE_DIR}/modules/*.xsd)
FOREACH (XSD_SCHEMA ${XSD_SCHEMAS})
  IF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/xhtml/schemas")
    FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/xhtml/schemas)
    MESSAGE(STATUS "created directory ${CMAKE_CURRENT_BINARY_DIR}/xhtml/schemas")
  ENDIF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/xhtml/schemas")
  CONFIGURE_FILE(${XSD_SCHEMA}
                 ${CMAKE_CURRENT_BINARY_DIR}/xhtml/schemas COPYONLY)
ENDFOREACH(XSD_SCHEMA)

#gather all the *.xq.src folders and copy them into the ${CMAKE_CURRENT_BINARY_DIR}/xhtml/xq.src folder
#note that the .xq.src are copied even if all the external functions are annotated as %private
IF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/xhtml/xq.src")
  FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/xhtml/xq.src)
  MESSAGE(STATUS "created directory ${CMAKE_CURRENT_BINARY_DIR}/xhtml/xq.src")
ENDIF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/xhtml/xq.src")

FILE(GLOB_RECURSE XQ_SRCS ${CMAKE_SOURCE_DIR}/modules/*.cpp)
FOREACH (XQ_SRC ${XQ_SRCS})
  #create the *.xq.src folders
  set(FOLDER "(.*)/([a-z-]+).xq.src/(.*)")
  string(REGEX REPLACE "${FOLDER}" "\\2" XQ_SRC_NAME "${XQ_SRC}")

  string(COMPARE NOTEQUAL ${XQ_SRC_NAME} ${XQ_SRC} FOUND)
  IF(${FOUND})
    SET(DESTINATION_FOLDER "${CMAKE_CURRENT_BINARY_DIR}/xhtml/xq.src/${XQ_SRC_NAME}.xq.src")
    IF (XQ_SRC_NAME AND NOT EXISTS "${DESTINATION_FOLDER}")
      FILE(MAKE_DIRECTORY "${DESTINATION_FOLDER}")
      MESSAGE(STATUS "created directory ${DESTINATION_FOLDER}")
    ENDIF (XQ_SRC_NAME AND NOT EXISTS "${DESTINATION_FOLDER}")

    #copy all the *.cpp and *.h into the newly created folder
    string(REGEX REPLACE "${FOLDER}" "\\1" XQ_SRC_PATH "${XQ_SRC}")
    SET(SOURCE_FOLDER "${XQ_SRC_PATH}/${XQ_SRC_NAME}.xq.src")

    FILE(GLOB_RECURSE CPPS ${SOURCE_FOLDER}/*.cpp)
    FOREACH (CPP ${CPPS})
      CONFIGURE_FILE(${CPP} ${DESTINATION_FOLDER})
    ENDFOREACH(CPP)

    FILE(GLOB_RECURSE HEADERS ${SOURCE_FOLDER}/*.h)
    FOREACH (HEADER ${HEADERS})
      CONFIGURE_FILE(${HEADER} ${DESTINATION_FOLDER})
    ENDFOREACH(HEADER)
  ENDIF(${FOUND})
ENDFOREACH(XQ_SRC)

#create the ${CMAKE_CURRENT_BINARY_DIR}/xhtml/examples folder
IF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/xhtml/examples")
  FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/xhtml/examples)
  MESSAGE(STATUS "created directory ${CMAKE_CURRENT_BINARY_DIR}/xhtml/examples")
ENDIF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/xhtml/examples")

# use the index.html template for the documentation
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/templates/index.html.in
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/templates/index.html)

# copy stylesheets, images and lib required by the xqdoc generated xhtml page
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/styles/jquery.treeview.css
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/css/jquery.treeview.css COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/styles/main.css
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/css/main.css COPYONLY)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/images/S.gif
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/images/S.gif COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/images/U.gif
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/images/U.gif COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/images/N.gif
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/images/N.gif COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/images/treeview-default.gif
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/images/treeview-default.gif COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/images/treeview-default-line.gif
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/images/treeview-default-line.gif COPYONLY)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/lib/jquery.cookie.js
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/lib/jquery.cookie.js COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/lib/jquery.js
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/lib/jquery.js COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/lib/jquery.treeview.js
               ${CMAKE_CURRENT_BINARY_DIR}/xhtml/lib/jquery.treeview.js COPYONLY)

# Finally, add the xqdoc command,
# therefore, a working zorba cmd is required.
ADD_CUSTOM_TARGET(xqdoc
  ${ZORBA_EXE_SCRIPT}
    --omit-xml-declaration
    -f
    -q "\"${CMAKE_CURRENT_SOURCE_DIR}/src/xqdoc-main.xq\""
    -e "\"modulesPath:=${CMAKE_SOURCE_DIR}/modules\""
    -e "\"xqdocBuildPath:=${CMAKE_CURRENT_BINARY_DIR}\""
    -e "\"indexHtmlPath:=${CMAKE_CURRENT_BINARY_DIR}/xhtml/templates/index.html\""
    --module-path "\"${CMAKE_CURRENT_SOURCE_DIR}/src\""
    -o "\"${CMAKE_CURRENT_BINARY_DIR}/xhtml/index.html\""
  DEPENDS
    ${XQDOC_DEPENDS}
)
SET_TARGET_PROPERTIES(xqdoc PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

ENDIF(NOT ZORBA_WITH_FILE_ACCESS)
