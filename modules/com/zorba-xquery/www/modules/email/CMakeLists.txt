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

IF (ZORBA_WITH_EMAIL)

  # create and install the external file module
  SET(EMAIL_SRCS uw-imap.cpp smtp.cpp email_function.cpp email_module.cpp)
  ADD_LIBRARY(smtp SHARED ${EMAIL_SRCS})
  IF( NOT WIN32 AND NOT CYGWIN)
    TARGET_LINK_LIBRARIES(smtp zorba_simplestore ${CCLIENT_LIBRARIES})
  ELSE( NOT WIN32 AND NOT CYGWIN)
    TARGET_LINK_LIBRARIES(smtp zorba_simplestore ${CCLIENT_LIBRARIES} secur32.lib crypt32.lib winmm.lib ws2_32.lib)
  ENDIF( NOT WIN32 AND NOT CYGWIN)
  SET_TARGET_PROPERTIES(smtp PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})
  SET_TARGET_PROPERTIES(smtp PROPERTIES CLEAN_DIRECT_OUTPUT 0)

  # install to include/zorba/modules/com/zorba-xquery/www/modules
  # the include/zorba/modules directory needs to belong to the set of Zorba Module Paths
  FILE(RELATIVE_PATH RELATIVE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" "${CMAKE_CURRENT_SOURCE_DIR}")
  INSTALL(TARGETS smtp DESTINATION "include/zorba/modules/${RELATIVE_MODULE_PATH}")

ENDIF (ZORBA_WITH_EMAIL)