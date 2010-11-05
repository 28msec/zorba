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

ADD_SUBDIRECTORY(email)
ADD_SUBDIRECTORY(security)
ADD_SUBDIRECTORY(image)
 

IF(ZORBA_WITH_FILE_ACCESS)
  GENERATE_MODULE_LIBRARY(file "")
ENDIF(ZORBA_WITH_FILE_ACCESS)


IF(ZORBA_WITH_PROCESS_ACCESS)
  GENERATE_MODULE_LIBRARY(process "")
ENDIF(ZORBA_WITH_PROCESS_ACCESS)

IF(CURL_FOUND)
  GENERATE_MODULE_LIBRARY(http-client "")
ENDIF(CURL_FOUND)

GENERATE_MODULE_LIBRARY(serialize "")
GENERATE_MODULE_LIBRARY(datetime "")

FIND_PACKAGE(Geos)
IF(GEOS_FOUND)
INCLUDE_DIRECTORIES(${GEOS_INCLUDE_DIR})
GENERATE_MODULE_LIBRARY(geo ${GEOS_LIBRARIES})
ELSE(GEOS_FOUND)
MESSAGE(STATUS "Geos Library Not Found. You need to install Geos library in order to compile the Geo Module.")
ENDIF(GEOS_FOUND)

