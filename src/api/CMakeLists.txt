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
                                  
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/api/version.cpp.cmake ${CMAKE_CURRENT_BINARY_DIR}/api/version.cpp)

SET(API_SRCS
    zorba.cpp
    zorbaimpl.cpp
    xqueryimpl.cpp
    sax2impl.cpp
    default_error_handler.cpp
    exception.cpp
    staticcontextimpl.cpp
    dynamiccontextimpl.cpp
    resultiteratorimpl.cpp
    zorbastring.cpp
    itemfactoryimpl.cpp
    serialization/serializer.cpp
    item.cpp
    typeidentimpl.cpp
    unmarshaller.cpp
    xmldatamanagerimpl.cpp
    resultiteratorchainer.cpp
    collectionimpl.cpp
    )

SET(API_BUILD_SRCS
  ${CMAKE_CURRENT_BINARY_DIR}/api/version.cpp
  )
