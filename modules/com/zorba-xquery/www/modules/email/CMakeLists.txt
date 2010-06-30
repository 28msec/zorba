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

# CClient library part of the UW IMAP toolkit required by the email functionality
FIND_PACKAGE(CClient)
IF (NOT WIN32 AND NOT CYGWIN)
  FIND_PACKAGE(PAM)
ENDIF (NOT WIN32 AND NOT CYGWIN)

IF(CCLIENT_FOUND)

  SET(SMTP_LINK_LIBRARIES ${CCLIENT_LIBRARY})

  INCLUDE_DIRECTORIES(${CCLIENT_INCLUDE})
  IF (NOT WIN32 AND NOT CYGWIN)
    LIST(APPEND SMTP_LINK_LIBRARIES ${PAM_LIBRARIES})
  ELSE (NOT WIN32 AND NOT CYGWIN)
    LIST(APPEND SMTP_LINK_LIBRARIES secur32.lib crypt32.lib winmm.lib ws2_32.lib)
  ENDIF (NOT WIN32 AND NOT CYGWIN)

  GENERATE_MODULE_LIBRARY(smtp "${SMTP_LINK_LIBRARIES}")

ELSE(CCLIENT_FOUND)

  MESSAGE(STATUS "CClient library not found -- if you want to use Email functionality please set CCLIENT_INCLUDE and CCLIENT_LIBRARY parameters.")

ENDIF( CCLIENT_FOUND)
