# Copyright 2015 Federico Cavalieri.
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
# Compile and build the zorba-server
#

INCLUDE_DIRECTORIES(AFTER ${CMAKE_SOURCE_DIR}/src/)
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR})

INCLUDE("${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaGenerateExe.cmake")

SET (SERVER_SRCS
     server.cpp
     request-handler.cpp
     
     api/evaluation.cpp
     api/projects.cpp
     api/users.cpp
     
     io/request.cpp
     io/response.cpp
     io/response-iterator.cpp
     
     exceptions/formatter.cpp     
     exceptions/server-exceptions.cpp
     
     utils/JSONObject.cpp
  )

#
# Server
#
MESSAGE (STATUS "Looking for FCGI")

FIND_PACKAGE(FCGI)
IF(FCGI_FOUND)
  SET (REQUIRED_LIBS ${FCGI_LIBRARIES})
ELSE(FCGI_FOUND)
  MESSAGE(FATAL_ERROR "libfcgi not found")
ENDIF(FCGI_FOUND)

ZORBA_GENERATE_EXE("zorba-server" "${SERVER_SRCS}" "${REQUIRED_LIBS}" "zorba-server" "bin")
