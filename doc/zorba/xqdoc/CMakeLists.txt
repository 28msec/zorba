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

#gather all the schemas and copy them into the ${CMAKE_CURRENT_BINARY_DIR}/schemas folder
FILE(GLOB_RECURSE XSD_SCHEMAS ${CMAKE_SOURCE_DIR}/modules/*.xsd)
FOREACH (XSD_SCHEMA ${XSD_SCHEMAS})
  IF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/schemas")
    FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/schemas)
    MESSAGE(STATUS "created directory ${CMAKE_CURRENT_BINARY_DIR}/schemas")
  ENDIF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/schemas")
  CONFIGURE_FILE(${XSD_SCHEMA}
                 ${CMAKE_CURRENT_BINARY_DIR}/schemas COPYONLY)
ENDFOREACH(XSD_SCHEMA)

# use the index.html template for the documentation
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/templates/index.html.in
               ${CMAKE_CURRENT_BINARY_DIR}/templates/index.html)

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
    -e "\"indexHtmlPath:=${CMAKE_CURRENT_BINARY_DIR}/templates/index.html\""
    --module-path "\"${CMAKE_CURRENT_SOURCE_DIR}/src\""
    -o "\"${CMAKE_CURRENT_BINARY_DIR}/xhtml/index.html\""
  DEPENDS
    ${XQDOC_DEPENDS}
)
SET_TARGET_PROPERTIES(xqdoc PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

ENDIF(NOT ZORBA_WITH_FILE_ACCESS)
