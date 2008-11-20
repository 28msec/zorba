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

SET(ZORBAUTILS_SRCS
    properties_base.cpp
    thread.cpp
    mutex.cpp
    condition.cpp
    latch.cpp
    lock.cpp)


IF(CYGWIN)
  ADD_LIBRARY(zorbautils SHARED ${ZORBAUTILS_SRCS})
ELSE(CYGWIN)
  ADD_LIBRARY(zorbautils ${ZORBAUTILS_SRCS})
ENDIF(CYGWIN)
  

SET(requiredlibs-zorbautils ${requiredlibs-zorbautils} zorbaerrors zorbatypes)
TARGET_LINK_LIBRARIES(zorbautils ${requiredlibs-zorbautils})

IF (ZORBA_BUILD_STATIC_LIBRARY)
ELSE (ZORBA_BUILD_STATIC_LIBRARY)
  IF (MSVC)
    #compile zorbautils as DLL
    REMOVE_DEFINITIONS(-DZORBA_INTERNAL)
    ADD_DEFINITIONS(-DZORBAUTILS_INTERNAL)
  ENDIF (MSVC)
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)
