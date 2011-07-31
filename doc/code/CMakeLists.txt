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

ZORBA_DOXYGEN("${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}" "codedocs")

IF (DOXYGEN_FOUND)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/rtab_b.gif
  ${CMAKE_CURRENT_BINARY_DIR}/html/rtab_b.gif COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/rtab_r.gif
  ${CMAKE_CURRENT_BINARY_DIR}/html/rtab_r.gif COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/rtab_l.gif
  ${CMAKE_CURRENT_BINARY_DIR}/html/rtab_l.gif COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/headers_svg/components.svg
  ${CMAKE_CURRENT_BINARY_DIR}/headers_svg/components.svg COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/headers_svg/headers.svg
  ${CMAKE_CURRENT_BINARY_DIR}/headers_svg/headers.svg COPYONLY)
ENDIF (DOXYGEN_FOUND)

IF(NOT ZORBA_WITH_FILE_ACCESS)
  MESSAGE(WARNING "Can not build headers SVG because 'File' module is not present")
ELSE(NOT ZORBA_WITH_FILE_ACCESS)
  FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/headers_svg/)

  # Add the headers_svg command for which a working zorba cmd is required.
  ADD_CUSTOM_TARGET(headers_svg
    ${ZORBA_EXE_SCRIPT}
      --omit-xml-declaration
      -f
      -q "\"${CMAKE_CURRENT_SOURCE_DIR}/headers_svg/generate-headers-dependencies-svg.xq\""
      -e "\"doxygenCodePath:=${CMAKE_CURRENT_BINARY_DIR}/html\""
      -o "\"${CMAKE_CURRENT_BINARY_DIR}/headers_svg/headers.svg\""
      COMMENT "Building header dependencies SVG..."
  )
  SET_TARGET_PROPERTIES (headers_svg PROPERTIES
    EXCLUDE_FROM_DEFAULT_BUILD 1
    FOLDER "Docs"
  )
  
  ADD_DEPENDENCIES(headers_svg "codedocs")
  
ENDIF(NOT ZORBA_WITH_FILE_ACCESS)