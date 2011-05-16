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

SET(ZORBAERRORS_SRCS
   dict.cpp
   dict_en.cpp
   diagnostic.cpp
   qname.cpp 
   error_list.cpp
   assert.cpp
   zorba_exception.cpp
   xquery_diagnostics.cpp
   xquery_exception.cpp 
   xquery_stack_trace.cpp
   user_error.cpp
   user_exception.cpp 
   warning_list.cpp
   )

IF (WIN32)
  SET(ZORBAERRORS_SRCS ${ZORBAERRORS_SRCS} StackWalker.cpp)
ENDIF (WIN32)
