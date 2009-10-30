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

# all external module libraries are generated in the directory
# of the corresponding .xq file
SET(SRCS 
      httpimpl/http_client.cpp
      httpimpl/request_parser.cpp
      httpimpl/request_handler.cpp
      httpimpl/http_request_handler.cpp
      httpimpl/http_response_handler.cpp
      httpimpl/http_response_parser.cpp
      httpimpl/curl_stream_buffer.cpp
      httpimpl/inform_data_read.cpp)
ADD_LIBRARY(httpclientimpl SHARED ${SRCS})
TARGET_LINK_LIBRARIES(httpclientimpl zorba_simplestore)
SET_TARGET_PROPERTIES(httpclientimpl PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})  
SET_TARGET_PROPERTIES(httpclientimpl PROPERTIES CLEAN_DIRECT_OUTPUT 0)

# install to include/modules/com/zorba-xquery/www/modules
# the include/modules directory needs to belong to the set of Zorba Module Paths
FILE(RELATIVE_PATH RELATIVE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" "${CMAKE_CURRENT_SOURCE_DIR}")
INSTALL(TARGETS httpclientimpl DESTINATION "include/${RELATIVE_MODULE_PATH}")
