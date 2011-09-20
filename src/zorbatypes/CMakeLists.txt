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

SET(ZORBATYPES_SRCS 
  decimal.cpp
  floatimpl.cpp
  integer.cpp
  numconversions.cpp
  binary.cpp
  URI.cpp
  transcoder.cpp
  collation_manager.cpp
  chartype.cpp
  rchandle.cpp)
  
IF (NOT ZORBA_NO_FULL_TEXT)
  LIST(APPEND ZORBATYPES_SRCS ft_token.cpp)
ENDIF (NOT ZORBA_NO_FULL_TEXT)

ADD_SRC_SUBFOLDER(ZORBATYPES_SRCS mapm     MAPM_SRCS)
ADD_SRC_SUBFOLDER(ZORBATYPES_SRCS datetime DATETIME_SRCS)
