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
# Try to find the PAM libraries
#
# PAM_FOUND       - True if PAM library found
# PAM_INCLUDE_DIR - Directory to include to get PAM headers
# PAM_LIBRARIES   - Libraries to link against for the PAM library

if (PAM_INCLUDE_DIR AND PAM_LIBRARY)
 # Already in cache, be silent
 set(PAM_FIND_QUIETLY TRUE)
endif (PAM_INCLUDE_DIR AND PAM_LIBRARY)

find_path(PAM_INCLUDE_DIR NAMES security/pam_appl.h pam/pam_appl.h)
find_library(PAM_LIBRARY pam)
find_library(DL_LIBRARY dl)

if (PAM_INCLUDE_DIR AND PAM_LIBRARY)
 set(PAM_FOUND TRUE)
  if (DL_LIBRARY)
    set(PAM_LIBRARIES ${PAM_LIBRARY} ${DL_LIBRARY})
  else (DL_LIBRARY)
    set(PAM_LIBRARIES ${PAM_LIBRARY})
  endif (DL_LIBRARY)
endif (PAM_INCLUDE_DIR AND PAM_LIBRARY)
