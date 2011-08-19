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

# - Try to find the LIBXSLT lib on Windows
#
# This is a proxy module that calls the FindLibXslt.cmake module. Before
# doing that, we try to guess where LIBXSLT might be on the user's machine.
# The user should provide ZORBA_THIRD_PARTY_REQUIREMENTS which is a path where
# the LIBXSLT directory can be found. The LIBXSLT directory must have "libxslt"
# (case insensitive) in its name.
#
# This module helps the Windows user to avoid providing the following two
# variables when building Zorba:
# -D LIBXSLT_INCLUDE="path_to_3rd_party_dir\*LIBXSLT*\src"
# -D LIBXSLT_LIBRARY="path_to_3rd_party_dir\*LIBXSLT*\bin\[Release\]libxslt.lib"
#
# See the FindLibTidy.cmake module shipped with Zorba for more information.

FIND_PACKAGE_WIN32(NAME LibXslt FOUND_VAR LIBXSLT_FOUND SEARCH_NAMES libxslt)

IF (LIBXSLT_FOUND)

  # find the needed DLL's
  FIND_PACKAGE_DLLS_WIN32 (${FOUND_LOCATION} libxslt.dll)

ENDIF (LIBXSLT_FOUND)
