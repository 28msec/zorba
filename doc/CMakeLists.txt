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
ADD_SUBDIRECTORY(cxx_api)
ADD_SUBDIRECTORY(c_api)

FIND_PACKAGE(SWIG)
IF (SWIG_FOUND)
  ADD_SUBDIRECTORY(python_api)
#  ADD_SUBDIRECTORY(ruby_api)
ENDIF (SWIG_FOUND)

# workaround: a dir is already needed for the install command. the html directory, however, is generated with the make doc call
FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/cxx_api/html)
FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/c_api/html)

INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/cxx_api/html 
        DESTINATION share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/cxx)

INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/c_api/html 
        DESTINATION share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/c)

INSTALL(FILES ${CMAKE_SOURCE_DIR}/LICENSE.txt DESTINATION share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})
INSTALL(FILES ${CMAKE_SOURCE_DIR}/README.txt  DESTINATION share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})
INSTALL(FILES ${CMAKE_SOURCE_DIR}/NOTICE.txt  DESTINATION share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})
INSTALL(FILES ${CMAKE_SOURCE_DIR}/AUTHORS.txt DESTINATION share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})
