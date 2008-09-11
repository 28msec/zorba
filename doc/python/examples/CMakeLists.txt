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
# install path determined from where Python lives 
FIND_PACKAGE(PythonInterp)

IF ( PYTHONINTERP_FOUND )
    SET(pythonPath ${CMAKE_BINARY_DIR}/swig/python)
    MESSAGE ( STATUS "Adding Python test" )
    CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/python_test.py.in ${CMAKE_CURRENT_BINARY_DIR}/python_test.py)
    ADD_TEST("python" ${PYTHON_EXECUTABLE} python_test.py)
    INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/python_test.py
        DESTINATION
        share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/python/examples)
ELSE( PYTHONINTERP_FOUND )
    MESSAGE(STATUS "Python test not added because Python Interpreter not found.")
ENDIF ( PYTHONINTERP_FOUND )

