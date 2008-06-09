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
#INCLUDE(${CMAKE_MODULE_PATH}/FindPHP5.cmake)
#FIND_PACKAGE(PHP5)
#STRING(COMPARE EQUAL ${PHP5_POSSIBLE_LIB_PATHS} "PHP5_LIBRARY-NOTFOUND" PHP5_LIBS_NOT_FOUND)
#STRING(COMPARE EQUAL ${PHP5_INCLUDES} "PHP5_INCLUDE_PATH-NOTFOUND" PHP5_INCL_NOT_FOUND) 
#
#IF(${PHP5_LIBS_NOT_FOUND} OR ${PHP5_INCL_NOT_FOUND})
#  MESSAGE(STATUS "PHP binding not generated because library and include file not installed.")
#ELSE(${PHP5_LIBS_NOT_FOUND} OR ${PHP5_INCL_NOT_FOUND})
#  MESSAGE(STATUS "Generating PHP API")
#  SET_SOURCE_FILES_PROPERTIES(zorba_api.i PROPERTIES CPLUSPLUS ON)
#  INCLUDE_DIRECTORIES(${PHP5_INCLUDES})
#  SWIG_ADD_MODULE(zorba_api php zorba_api.i)
#  SWIG_LINK_LIBRARIES(zorba_api zorba ${PHP5_POSSIBLE_LIB_PATHS})
#ENDIF(${PHP5_LIBS_NOT_FOUND} OR ${PHP5_INCL_NOT_FOUND})
