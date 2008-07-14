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

SET(ZORBA_MINIMAL_STORE  OFF CACHE BOOL "Choose zorba minimal store for better performance")


IF(ZORBA_MINIMAL_STORE)

ADD_SUBDIRECTORY(minimal)

HEADER_GROUP_SUBFOLDER(STORE_SRCS api)
HEADER_GROUP_SUBFOLDER(STORE_SRCS util)
HEADER_GROUP_SUBFOLDER(STORE_SRCS update)

HEADER_GROUP_SUBFOLDER(STORE_SRCS minimal)


ELSE(ZORBA_MINIMAL_STORE)

ADD_SUBDIRECTORY(naive)

ENDIF(ZORBA_MINIMAL_STORE)

