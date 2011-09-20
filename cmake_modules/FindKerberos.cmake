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
# Finds the KERBEROS library
#
#  KERBEROS_FOUND        - True if SASL library found.
#  KERBEROS_LIBRARY      - Libraries to link against for the SASL library
#

if (KERBEROS_LIBRARIES)
  # Already in cache, be silent
 set(KERBEROS_FIND_QUIETLY TRUE)
endif (KERBEROS_LIBRARIES)

# Look for the library.
find_library(
  KERBEROS_LIBRARY
  NAMES gssapi_krb5
  PATHS ${KERBEROS_LIBRARY_DIRS} /opt/local/lib /usr/lib /usr/local/lib
  DOC "Library to link against for kerberos support (gssapi_krb5)")
mark_as_advanced(KERBEROS_LIBRARY)

if (KERBEROS_LIBRARY)
  MESSAGE(STATUS "Found Kerberos library -- " ${KERBEROS_LIBRARY})
else (KERBEROS_LIBRARY)
  MESSAGE(STATUS "Could not find Kerberos library")
endif (KERBEROS_LIBRARY)

# Copy the results to the output variables.
if(KERBEROS_LIBRARY)
  set(KERBEROS_FOUND 1)
else(KERBEROS_LIBRARY)
  set(KERBEROS_FOUND 0)
  set(KERBEROS_LIBRARY)
  set(KERBEROS_INCLUDE)
endif(KERBEROS_LIBRARY)
