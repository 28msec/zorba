# Copyright 2006-2010 The FLWOR Foundation.
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

DECLARE_ZORBA_MODULE(FILE "util-curl.xq" VERSION 1.0
  URI "http://zorba.io/modules/util-curl")

# The important stuff is the library that we install in Zorba's default lib
# directory.
ADD_LIBRARY(util-curl SHARED curl_streambuf.cpp util-curl.cpp)
TARGET_LINK_LIBRARIES(util-curl zorba_${ZORBA_STORE_NAME} ${CURL_LIBRARIES})
INSTALL(TARGETS util-curl 
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib${LIB_SUFFIX}
  ARCHIVE DESTINATION lib)

IF (WIN32)
  SET_TARGET_PROPERTIES(util-curl PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src)  
ENDIF (WIN32) 
 
IF (APPLE)
  # MAC OS X only property
  # This is required to make sure that the library has the correct install name
  # after installation such that dependent modules always find it.
  SET_TARGET_PROPERTIES(util-curl PROPERTIES INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")
ENDIF (APPLE)

# Set this in the parent scope so it will be put into our Config.cmake file.
# As with many other things, this doesn't work when the module is installed.
SET(ZORBA_PROJECT_LIBRARIES util-curl PARENT_SCOPE)

# vim:set et sw=2 ts=2:
