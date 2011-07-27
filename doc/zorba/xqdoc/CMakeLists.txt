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
        DESTINATION xqdoc/requisites
        PATTERN "*.svn" EXCLUDE
        )
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
        DESTINATION xqdoc/requisites
        PATTERN "*.svn" EXCLUDE
        )
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/styles
        DESTINATION xqdoc/requisites
        PATTERN "*.svn" EXCLUDE
        )
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/templates
        DESTINATION xqdoc/requisites
        PATTERN "*.svn" EXCLUDE
        )
INSTALL(FILES src/xqdoc-main-extmodules-html.xq
              src/xqdoc-main-extmodules-xml.xq
        DESTINATION xqdoc/generator/
        )

  SET(MODULES_PATHS ${CMAKE_SOURCE_DIR}/modules) # ${ZORBA_EXTERNAL_MODULES_SRCS})
  # Add the xqdoc command for which a working zorba cmd is required.
  FILE(GLOB_RECURSE ZORBA_ALL_MODULES  ../../../modules/*.xq)
  ADD_CUSTOM_TARGET(xqdoc-xml
    ${ZORBA_EXE_SCRIPT}
      --omit-xml-declaration
      -f
      -q "\"${CMAKE_CURRENT_SOURCE_DIR}/src/xqdoc-main-zorbamodules-xml.xq\""
      -e "\"modulesPath:=${MODULES_PATHS}\""
      -e "\"xqdocBuildPath:=${CMAKE_CURRENT_BINARY_DIR}\""
      DEPENDS ${ZORBA_ALL_MODULES}
      COMMENT "Building XQDoc XML documentation for the modules..."
  )
  #SET_TARGET_PROPERTIES(xqdoc-xml PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)
  ADD_DEPENDENCIES(xqdoc-xml zorba_simplestore)

  ADD_CUSTOM_TARGET(xqdoc
    ${ZORBA_EXE_SCRIPT}
      --omit-xml-declaration
      -f
      -q "\"${CMAKE_CURRENT_SOURCE_DIR}/src/xqdoc-main-zorbamodules-html.xq\""
      -e "\"modulesPath:=${MODULES_PATHS}\""
      -e "\"xhtmlRequisitesPath:=${CMAKE_CURRENT_SOURCE_DIR}\""
      -e "\"xqdocBuildPath:=${CMAKE_CURRENT_BINARY_DIR}\""
      -e "\"examplePath:=${CMAKE_SOURCE_DIR}\""
      -e "\"zorbaVersion:=${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}\""
      COMMENT "Building XQDoc documentation for the modules..."
  )
  ADD_DEPENDENCIES(xqdoc "xqdoc-xml")
  SET_TARGET_PROPERTIES(xqdoc PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

  ADD_TEST(doc/stress_tests/make_xqdoc
      ${ZORBA_EXE_SCRIPT}
      --omit-xml-declaration
      -f
      -q "${CMAKE_CURRENT_SOURCE_DIR}/src/xqdoc-zorbamodules-html.xq"
      -e "modulesPath:=${MODULES_PATHS}"
      -e "xhtmlRequisitesPath:=${CMAKE_CURRENT_SOURCE_DIR}"
      -e "xqdocBuildPath:=${CMAKE_CURRENT_BINARY_DIR}"
      -e "examplePath:=${CMAKE_SOURCE_DIR}"
      -e "zorbaVersion:=${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}"
      )

  EXPECTED_FAILURE(doc/stress_tests/make_xqdoc 3330316)

  # Add the modules_svg command for which a working zorba cmd is required.
  ADD_CUSTOM_TARGET(modules_svg
    ${ZORBA_EXE_SCRIPT}
      --omit-xml-declaration
      -f
      -q "\"${CMAKE_CURRENT_SOURCE_DIR}/src/generate-module-dependencies-svg.xq\""
      -e "\"xqdocXMLPath:=${CMAKE_CURRENT_BINARY_DIR}/xml\""
      -o "\"${CMAKE_CURRENT_BINARY_DIR}/xhtml/images/modules.svg\""
      COMMENT "Building module dependencies SVG..."
  )
  SET_TARGET_PROPERTIES(modules_svg PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

  ADD_DEPENDENCIES(modules_svg xqdoc-xml xqdoc)

ENDIF(NOT ZORBA_WITH_FILE_ACCESS)
