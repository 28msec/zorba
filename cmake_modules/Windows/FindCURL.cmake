# Copyright 2010 The FLWOR Foundation.
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

# - Find the native cURL headers and libraries on Windows
#
# This is a proxy module that calls the FindCURL.cmake module shipped with
# CMake. But before we try to guess where cURL might be on the user's machine.
# The user should provide ZORBA_THIRD_PARTY_REQUIREMENTS which is a path where
# the cURL directory can be found. The cURL directory must have "curl"
# (case insensitive) in its name.
#
# This module helps the Windows user to avoid providing the following two
# variables when building Zorba:
# -D CURL_INCLUDE_DIR="path_to_3rd_party_dir\*curl*\include"
# -D CURL_LIBRARY="path_to_3rd_party_dir\*curl*\libcurl_imp.lib"
#
# See the FindCURL.cmake module shipped with CMake for more information.

FIND_PACKAGE_WIN32(NAME "CURL" FOUND_VAR "CURL_FOUND" SEARCH_NAMES "curl")

IF (CURL_FOUND)

  IF (EXISTS "${FOUND_LOCATION}/bin/curl.exe")

    MESSAGE (STATUS "Found CURL binary distribution: ${FOUND_LOCATION}}")

    # find the needed DLL's
    FIND_PACKAGE_DLL_WIN32 (${FOUND_LOCATION} "libcurl" "curllib")
    #FIND_PACKAGE_DLL_WIN32 (${FOUND_LOCATION} "libeay32")
    #FIND_PACKAGE_DLL_WIN32 (${FOUND_LOCATION} "openldap")
    #FIND_PACKAGE_DLL_WIN32 (${FOUND_LOCATION} "ssleay32")
    #FIND_PACKAGE_DLL_WIN32 (${FOUND_LOCATION} "libsasl")

  ELSE (EXISTS "${FOUND_LOCATION}/bin/curl.exe")

    MESSAGE (STATUS "Found CURL source build")

    # find the needed DLL's
    FIND_PACKAGE_DLL_WIN32 (${FOUND_LOCATION} "libcurl" "curllib")

    # find additional DLL's
    #FIND_DLL_WIN32 ("libeay32.dll")
    #FIND_DLL_WIN32 ("ssleay32.dll")
    #FIND_DLL_WIN32 (libsasl.dll)

  ENDIF (EXISTS "${FOUND_LOCATION}/bin/curl.exe")

ENDIF (CURL_FOUND)
