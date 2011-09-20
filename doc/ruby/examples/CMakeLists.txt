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

FIND_PACKAGE(Ruby)

IF (RUBY_LIBRARY AND RUBY_INCLUDE_PATH)
  IF (NOT RUBY_EXECUTABLE)
    MESSAGE(STATUS "Ruby test not added because Ruby Interpreter not found.")
  ELSE (NOT RUBY_EXECUTABLE)
    SET(rubyPath ${CMAKE_BINARY_DIR}/swig/ruby)
    CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ruby_test.rb.in ${CMAKE_CURRENT_BINARY_DIR}/ruby_test.rb)
    ADD_TEST("ruby" ${RUBY_EXECUTABLE} ruby_test.rb)
  ENDIF(NOT RUBY_EXECUTABLE)

  INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/ruby_test.rb
        COMPONENT "ruby_examples"
        DESTINATION
        share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/ruby/examples)
ENDIF (RUBY_LIBRARY AND RUBY_INCLUDE_PATH)
