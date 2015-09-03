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
# Check Zorba server prerequisites
#
MESSAGE (STATUS "")
MESSAGE (STATUS "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
MESSAGE (STATUS "Configuring optional component <server>")
MESSAGE (STATUS "-------------------------------------------------------------")
MESSAGE (STATUS "")

MESSAGE (STATUS "Looking for FCGI libraries...")
FIND_PACKAGE(FCGI)
IF(FCGI_FOUND)
  SET (REQUIRED_LIBS ${FCGI_LIBRARIES})
  MESSAGE(STATUS "Fcgi libraries: FOUND.")
ELSE(FCGI_FOUND)
  MESSAGE(STATUS "Fcgi libraries: NOT FOUND. Server will not be built.")
ENDIF(FCGI_FOUND)

MESSAGE (STATUS "Looking for MongoDriver...")
FIND_PACKAGE(MongoDriver)
IF(MONGODRIVER_FOUND)
  SET (REQUIRED_LIBS ${REQUIRED_LIBS} ${MONGODRIVER_LIBRARY})
  MESSAGE(STATUS "MongoDriver library: FOUND.")
ELSE(MONGODRIVER_FOUND)
  MESSAGE(STATUS "MongoDriver library: NOT FOUND. Server will not be built.")
ENDIF(MONGODRIVER_FOUND)

MESSAGE (STATUS "Looking for Boost system component...")
FIND_PACKAGE(Boost COMPONENTS system)
IF (Boost_SYSTEM_FOUND)
  SET (REQUIRED_LIBS ${REQUIRED_LIBS} ${Boost_LIBRARIES})  
  MESSAGE(STATUS "Boost system component: FOUND.")
ELSE (Boost_SYSTEM_FOUND)
  MESSAGE(STATUS "Boost system component: NOT FOUND. Server will not be built.")
ENDIF (Boost_SYSTEM_FOUND)

MESSAGE (STATUS "Looking for Boost filesystem component...")
FIND_PACKAGE(Boost COMPONENTS filesystem)
IF (Boost_FILESYSTEM_FOUND)
  SET (REQUIRED_LIBS ${REQUIRED_LIBS} ${Boost_LIBRARIES})
  MESSAGE(STATUS "Boost filesystem component: FOUND.")
ELSE (Boost_FILESYSTEM_FOUND)
  MESSAGE(STATUS "Boost filesystem component: NOT FOUND. Server will not be built.")
ENDIF (Boost_FILESYSTEM_FOUND)

IF (FCGI_FOUND AND MONGODRIVER_FOUND AND Boost_SYSTEM_FOUND AND Boost_FILESYSTEM_FOUND)
  MESSAGE(STATUS "All required libraries have been found. Building server...")

  INCLUDE_DIRECTORIES(AFTER ${CMAKE_SOURCE_DIR}/src/)
  INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR})

  INCLUDE("${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaGenerateExe.cmake")

  SET (SERVER_SRCS
    server.cpp
    request_handler.cpp

    api/evaluation.cpp

    io/request.cpp
    io/response.cpp
    io/response_iterator.cpp
     
    exceptions/formatter.cpp
    exceptions/server_exceptions.cpp
    
    utils/debug.cpp 
    utils/JSONItems.cpp
  )

  ZORBA_GENERATE_EXE("zorba-server" "${SERVER_SRCS}" "${REQUIRED_LIBS}" "zorba-server" "bin")
  
  MESSAGE(STATUS "") 
  MESSAGE(STATUS "-------------------------------------------------------------")
  MESSAGE(STATUS "Configuration SUCCEEDED for optional component <server>")
  MESSAGE(STATUS "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
  MESSAGE(STATUS "") 

ELSE (FCGI_FOUND AND MONGODRIVER_FOUND AND Boost_SYSTEM_FOUND AND Boost_FILESYSTEM_FOUND)
  MESSAGE(STATUS "Some required libraries were not found. Server will not be built.")
  
  MESSAGE(STATUS "")
  MESSAGE(STATUS "-------------------------------------------------------------")
  MESSAGE(STATUS "Configuration FAILED for optional component <server>")
  MESSAGE(STATUS "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
  MESSAGE(STATUS "")
  
ENDIF (FCGI_FOUND AND MONGODRIVER_FOUND AND Boost_SYSTEM_FOUND AND Boost_FILESYSTEM_FOUND)
