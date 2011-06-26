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


#
# cURL
#
IF(ZORBA_SUPPRESS_CURL)
  MESSAGE(STATUS "ZORBA_SUPPRESS_CURL is true - not searching for cURL library")
ELSE(ZORBA_SUPPRESS_CURL)
  MESSAGE(STATUS "Looking for cURL")
  FIND_PACKAGE(CURL)

  IF(CURL_FOUND)
    MESSAGE(STATUS "Found cURL library -- " ${CURL_LIBRARIES})
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})

    GENERATE_MODULE_LIBRARY(http-client ${CURL_LIBRARIES})
  ELSE(CURL_FOUND)
    MESSAGE(STATUS "The cURL library was not found - http-client will not be built")
  ENDIF(CURL_FOUND)
ENDIF(ZORBA_SUPPRESS_CURL)

GENERATE_MODULE_LIBRARY(datetime "")
