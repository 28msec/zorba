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

# generate host language and manually written documentation using doxygen
# this adds a custom target called "zorbadocs"
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/indexpage.dox.in ${CMAKE_CURRENT_BINARY_DIR}/indexpage.dox)

ZORBA_DOXYGEN("${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}" "zorbadocs")

IF (DOXYGEN_FOUND)
  # make the zorbadocs target as a dependee of the doc target
  ADD_DEPENDENCIES(doc "zorbadocs")

  # if doxygen documentation is generated
  # we add the target "docs" to the target "doc"
  # which is used to build all documentation related targets
  LIST(APPEND ZORBA_DOC_DEPENDENCIES docs)

  # and install all doxygen required styles and images
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/rtab_b.gif
                  ${CMAKE_CURRENT_BINARY_DIR}/html/rtab_b.gif COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/rtab_r.gif
                  ${CMAKE_CURRENT_BINARY_DIR}/html/rtab_r.gif COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/rtab_l.gif
                  ${CMAKE_CURRENT_BINARY_DIR}/html/rtab_l.gif COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/download.png
                  ${CMAKE_CURRENT_BINARY_DIR}/html/download.png COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/modules.png
                  ${CMAKE_CURRENT_BINARY_DIR}/html/modules.png COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/terminal.png
                  ${CMAKE_CURRENT_BINARY_DIR}/html/terminal.png COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/documentation.png
                  ${CMAKE_CURRENT_BINARY_DIR}/html/documentation.png COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/../style/noisepattern.png
                  ${CMAKE_CURRENT_BINARY_DIR}/html/noisepattern.png COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/scripting_spec.html
                  ${CMAKE_CURRENT_BINARY_DIR}/html/scripting_spec.html COPYONLY)
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/W3C-WD.css
                  ${CMAKE_CURRENT_BINARY_DIR}/html/W3C-WD.css COPYONLY)
ENDIF (DOXYGEN_FOUND)

# adding the subdirectory responsible for adding the
# xqdoc generated API documentation
ADD_SUBDIRECTORY(xqdoc)

# make the xqdoc target as a dependee of the doc target
ADD_DEPENDENCIES(doc "xqdoc")
