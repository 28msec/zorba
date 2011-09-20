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
# - Try to find the version of Xerces-C
#  Expects XERCESC_INCLUDE - the Xerces-C include directory
#
# Once done this will define
#
#  XERCESC_VERSION - Xerces-C found version

FIND_PATH(XVERHPPPATH NAMES XercesVersion.hpp PATHS 
  ${XERCESC_INCLUDE}/xercesc/util  NO_DEFAULT_PATH)

IF ( ${XVERHPPPATH} STREQUAL XVERHPPPATH-NOTFOUND )
  SET(XERCES_VERSION "0")
ELSE( ${XVERHPPPATH} STREQUAL XVERHPPPATH-NOTFOUND )
  FILE(READ ${XVERHPPPATH}/XercesVersion.hpp XVERHPP)
  
  STRING(REGEX MATCH "\n *#define XERCES_VERSION_MAJOR +[0-9]+" XVERMAJ 
    ${XVERHPP}) 
  STRING(REGEX MATCH "\n *#define XERCES_VERSION_MINOR +[0-9]+" XVERMIN 
    ${XVERHPP})
  STRING(REGEX MATCH "\n *#define XERCES_VERSION_REVISION +[0-9]+" XVERREV 
    ${XVERHPP})
  
  STRING(REGEX REPLACE "\n *#define XERCES_VERSION_MAJOR +" "" 
    XVERMAJ ${XVERMAJ})
  STRING(REGEX REPLACE "\n *#define XERCES_VERSION_MINOR +" "" 
    XVERMIN ${XVERMIN})
  STRING(REGEX REPLACE "\n *#define XERCES_VERSION_REVISION +" "" 
    XVERREV ${XVERREV})
  
  SET(XERCESC_VERSION ${XVERMAJ}.${XVERMIN}.${XVERREV})
  #MESSAGE(STATUS "Xerces-C Version: ${XERCESC_VERSION}")
  
ENDIF ( ${XVERHPPPATH} STREQUAL XVERHPPPATH-NOTFOUND )
