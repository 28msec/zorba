# Copyright 2011 The FLWOR Foundation.
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
# - Try to find the libedit library
#
# Once done this will define
#
#  LIBEDIT_FOUND        - True if libedit library is found
#  LIBEDIT_INCLUDE_DIRS - Directory to include to get libedit headers
#  LIBEDIT_LIBRARIES    - Libraries to link against for the libedit library
#

FIND_PATH (
  LIBEDIT_INCLUDE
  editline/readline.h
  PATHS ${LIBEDIT_INCLUDE_DIR} /usr/include /usr/local/include
)
MESSAGE(STATUS ${LIBEDIT_INCLUDE})

FIND_LIBRARY (
  LIBEDIT_LIBRARY
  NAMES edit
  PATHS ${LIBEDIT_LIBRARY_DIR} /usr/lib /usr/local/lib /usr/lib64 /usr/local/lib64
) 
MESSAGE(STATUS ${LIBEDIT_LIBRARY})

SET (LIBEDIT_INCLUDE_DIRS ${LIBEDIT_INCLUDE})
SET (LIBEDIT_LIBRARIES ${LIBEDIT_LIBRARY})

FIND_PACKAGE_HANDLE_STANDARD_ARGS (
  Libedit
  DEFAULT_MSG
  LIBEDIT_INCLUDE LIBEDIT_LIBRARY
)

