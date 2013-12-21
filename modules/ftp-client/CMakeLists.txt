# Copyright 2006-2013 The FLWOR Foundation.
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

SET( CURL_FOUND )

IF ( ZORBA_SUPPRESS_CURL )
  MESSAGE( STATUS "ZORBA_SUPPRESS_CURL is true - not searching for cURL library" )
ELSE ( ZORBA_SUPPRESS_CURL )
  MESSAGE( STATUS "Looking for cURL" )
  FIND_PACKAGE( CURL )

  IF ( CURL_FOUND )
    MESSAGE( STATUS "Found cURL library -- " ${CURL_LIBRARIES} )
    INCLUDE_DIRECTORIES( ${CURL_INCLUDE_DIR} )

    DECLARE_ZORBA_MODULE( FILE ftp-client.xq VERSION 1.0
      URI "http://zorba.io/modules/ftp-client"
      LINK_LIBRARIES ${CURL_LIBRARIES} )

  ELSE ( CURL_FOUND )
    MESSAGE( STATUS "The cURL library was not found - ftp-client will not be built" )
  ENDIF ( CURL_FOUND )
ENDIF ( ZORBA_SUPPRESS_CURL )

SET( ZORBA_HAVE_CURL ${CURL_FOUND} CACHE BOOL "Whether Zorba found cURL" FORCE )
MARK_AS_ADVANCED( ZORBA_HAVE_CURL )

# vim:set et sw=2 ts=2:
