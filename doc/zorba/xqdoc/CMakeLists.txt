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

CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/src/xqdoc.xq
                ${CMAKE_CURRENT_BINARY_DIR}/../../../xqdoc/generator/xqdoc.xq COPYONLY)
CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/src/xqdoc-html.xq
                ${CMAKE_CURRENT_BINARY_DIR}/../../../xqdoc/generator/xqdoc-html.xq COPYONLY)
CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/src/batch.xq
                ${CMAKE_CURRENT_BINARY_DIR}/../../../xqdoc/generator/batch.xq COPYONLY)
CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/src/menu.xq
                ${CMAKE_CURRENT_BINARY_DIR}/../../../xqdoc/generator/menu.xq COPYONLY)
CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/src/html.xq
                ${CMAKE_CURRENT_BINARY_DIR}/../../../xqdoc/generator/html.xq COPYONLY)

# Add the modules_svg command for which a working zorba cmd is required.
# We need to add this target in all cases because ADD_XQDOC_TARGETS() in
# ZorbaModule.cmake expects it to exist. However, generating this depends
# on the non-core Graphviz module. Therefore, we check to see if Graphviz
# is available, and if not, add a dummy target with the same name.
IS_ZORBA_MODULE_DECLARED(_graphviz_avail
 "http://www.zorba-xquery.com/modules/image/graphviz")
IF (_graphviz_avail)
 ADD_CUSTOM_TARGET(modules_svg
 ${ZORBA_EXE}
 --omit-xml-declaration
 -f
 -q "\"${CMAKE_CURRENT_SOURCE_DIR}/src/generate-module-dependencies-svg.xq\""
 -e "\"ZorbaBuildFolder:=${CMAKE_CURRENT_BINARY_DIR}/../../../\""
 -o "\"${CMAKE_CURRENT_SOURCE_DIR}/images/modules_new.svg\""
 COMMENT "Building module dependencies SVG..."
 )
ELSE (_graphviz_avail)
 ADD_CUSTOM_TARGET(modules_svg
 COMMENT "Not building modules dependencies SVG since Graphviz module not available")
ENDIF (_graphviz_avail)
 SET_TARGET_PROPERTIES (modules_svg PROPERTIES
 EXCLUDE_FROM_DEFAULT_BUILD 1
 FOLDER "Docs"
 )

ENDIF(NOT ZORBA_WITH_FILE_ACCESS)
