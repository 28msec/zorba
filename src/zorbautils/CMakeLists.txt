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

SET(ZORBAUTILS_SRCS
    fatal.cpp
    hashset_structured_itemh.cpp
    hashset_atomic_itemh.cpp
    mutex.cpp
    condition.cpp
    latch.cpp
    lock.cpp
    runnable.cpp
    synchronous_logger.cpp
    store_util.cpp
    string_util.cpp)

IF (ZORBA_WITH_LIBXML2_SAX)
  SET(ZORBAUTILS_SRCS ${ZORBAUTILS_SRCS} SAXParser.cpp)
ENDIF (ZORBA_WITH_LIBXML2_SAX)
