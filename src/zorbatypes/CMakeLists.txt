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

INCLUDE(${CMAKE_MODULE_PATH}/FindICU.cmake)

SET(requiredlibs-zorbatypes)
IF (CYGWIN)
  SET(requiredlibs-zorbatypes ${requiredlibs-zorbatypes} ${XERCESC_LIBRARY})
ENDIF(CYGWIN)
               
IF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)
  MESSAGE(FATAL_ERROR "The ICU library is required in order to build Zorba.")

ELSE (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)

  SET(requiredlibs-zorbatypes ${requiredlibs-zorbatypes} ${ICU_LIBRARIES} ${ICU_I18N_LIBRARIES} ${ICU_DATA_LIBRARIES})           
  INCLUDE_DIRECTORIES(${ICU_INCLUDE_DIRS})

ENDIF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)                                                                  

SET(ZORBATYPES_SRCS 
  decimal.cpp
  floatimpl.cpp
  integer.cpp
  numconversions.cpp
  binary.cpp
  URI.cpp
  transcoder.cpp
  utf8/Unicode_util.cpp
  collation_manager.cpp
  icu_init.cpp
  chartype.cpp)
  
IF(ZORBA_NO_UNICODE)
LIST(APPEND ZORBATYPES_SRCS 
  xqpString_ascii.cpp
  regex_ascii.cpp
  )
ELSE(ZORBA_NO_UNICODE)
LIST(APPEND ZORBATYPES_SRCS 
  utf8/xqpString.cpp
  )
ENDIF(ZORBA_NO_UNICODE)


ADD_SRC_SUBFOLDER(ZORBATYPES_SRCS mapm     MAPM_SRCS)
ADD_SRC_SUBFOLDER(ZORBATYPES_SRCS datetime DATETIME_SRCS)

ADD_LIBRARY(zorbatypes ${ZORBATYPES_SRCS})

TARGET_LINK_LIBRARIES(zorbatypes ${requiredlibs-zorbatypes})
