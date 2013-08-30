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

  FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/known_issues.dox "/** \\page known_issues Known Issues
")
  FILE(READ  ${CMAKE_SOURCE_DIR}/KNOWN_ISSUES.txt KNWON_ISSUES_CONTENS)
  STRING (REPLACE "\\s" "\\code \\s \\endcode" KNWON_ISSUES_CONTENS ${KNWON_ISSUES_CONTENS})
  STRING (REPLACE "#others" "\\code #others \\endcode" KNWON_ISSUES_CONTENS ${KNWON_ISSUES_CONTENS})
  FILE(APPEND ${CMAKE_CURRENT_BINARY_DIR}/known_issues.dox "${KNWON_ISSUES_CONTENS}
*/")

ENDIF (DOXYGEN_FOUND)

# adding the subdirectory responsible for adding the
# xqdoc generated API documentation
ADD_SUBDIRECTORY(xqdoc)

# make the xqdoc target as a dependency of the doc target
ADD_DEPENDENCIES(doc "xqdoc")