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

FILE(GLOB_RECURSE XQ_MODULES ${CMAKE_SOURCE_DIR}/modules/*.xq)
LIST(APPEND XQDOC_DEPENDS ${XQ_MODULES})

FILE(GLOB_RECURSE XQDOC_TEMPLATES ${CMAKE_CURRENT_SOURCE_DIR}/templates/*)
LIST(APPEND XQDOC_DEPENDS ${XQDOC_TEMPLATES})

FILE(GLOB_RECURSE XQDOC_GENERATORS ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
LIST(APPEND XQDOC_DEPENDS ${XQDOC_GENERATORS})

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/styles/zorba.css ${CMAKE_CURRENT_BINARY_DIR}/xhtml/css/zorba.css COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/images/S.gif ${CMAKE_CURRENT_BINARY_DIR}/xhtml/images/S.gif COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/images/U.gif ${CMAKE_CURRENT_BINARY_DIR}/xhtml/images/U.gif COPYONLY)

ADD_CUSTOM_TARGET(xqdoc
  ${ZORBA_RUNTIME_GENERATOR}
    --omit-xml-declaration
    -f
    -q "\"${CMAKE_CURRENT_SOURCE_DIR}/src/xqdoc-main.xq\""
    -e "\"modulesPath:=${CMAKE_SOURCE_DIR}/modules\""
    -e "\"xqdocBuildPath:=${CMAKE_CURRENT_BINARY_DIR}\""
    -e "\"indexHtmlPath:=${CMAKE_CURRENT_SOURCE_DIR}/templates/index.html\""
    -o "\"${CMAKE_CURRENT_BINARY_DIR}/xhtml/index.html\""
  DEPENDS
    ${XQDOC_DEPENDS}
)
  
ADD_DEPENDENCIES(doc xqdoc)
