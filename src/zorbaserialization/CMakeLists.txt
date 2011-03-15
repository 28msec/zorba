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

SET(ZORBA_PLAN_SERIALIZER_STATISTICS OFF CACHE BOOL "Set to ON to get some statistics on saved plan")
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/zorbaserialization/plan_settings.h.in ${CMAKE_CURRENT_BINARY_DIR}/zorbaserialization/plan_settings.h)
SET(ZORBASERIALIZATION_SRCS 
  archiver.cpp
  base64impl.cpp
  class_serializer.cpp
  zorba_classes_version.cpp
  mem_archiver.cpp
  xml_archiver.cpp
  bin_archiver.cpp
  zorba_class_serializer.cpp
  zorba_class_versions.cpp
  )  