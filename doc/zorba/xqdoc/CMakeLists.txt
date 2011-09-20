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

IF(NOT ZORBA_WITH_FILE_ACCESS)
  MESSAGE(WARNING "Can not build XQDoc documentation because 'File' module is not present")
ELSE(NOT ZORBA_WITH_FILE_ACCESS)

INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/images
        DESTINATION share/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/xqdoc/requisites
        COMPONENT "doc"
        PATTERN "*.svn" EXCLUDE
        )
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
        DESTINATION share/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/xqdoc/requisites
        COMPONENT "doc"
        PATTERN "*.svn" EXCLUDE
        )
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/styles
        DESTINATION share/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/xqdoc/requisites 
        COMPONENT "doc"
        PATTERN "*.svn" EXCLUDE
        )
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/templates
        DESTINATION share/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/xqdoc/requisites  
        COMPONENT "doc"
        PATTERN "*.svn" EXCLUDE
        )
INSTALL(FILES src/xqdoc-html.xq
              src/xqdoc-xml.xq
        DESTINATION share/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/xqdoc/generator/ 
        COMPONENT "doc"
        )

CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/src/xqdoc-html.xq
                ${CMAKE_CURRENT_BINARY_DIR}/../../../xqdoc/generator/xqdoc-html.xq COPYONLY)

CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/src/xqdoc-xml.xq
                ${CMAKE_CURRENT_BINARY_DIR}/../../../xqdoc/generator/xqdoc-xml.xq COPYONLY)

#   Add the modules_svg command for which a working zorba cmd is required.
  ADD_CUSTOM_TARGET(modules_svg
    ${ZORBA_EXE}
      --omit-xml-declaration
      -f
      -q "\"${CMAKE_CURRENT_SOURCE_DIR}/src/generate-module-dependencies-svg.xq\""
      -e "\"xqdocXMLPath:=${CMAKE_CURRENT_BINARY_DIR}/xml\""
      -o "\"${CMAKE_CURRENT_BINARY_DIR}/xhtml/images/modules.svg\""
      COMMENT "Building module dependencies SVG..."
  )
  SET_TARGET_PROPERTIES (modules_svg PROPERTIES
    EXCLUDE_FROM_DEFAULT_BUILD 1
    FOLDER "Docs"
  )
  ADD_DEPENDENCIES(modules_svg "xqdoc-zorba")

ENDIF(NOT ZORBA_WITH_FILE_ACCESS)
