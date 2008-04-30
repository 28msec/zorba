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
SET(FUNCTIONS_SRCS
    Accessors.cpp Sequences.cpp library.cpp
    Constructor.cpp ContextFunctions.cpp Numerics.cpp 
    Boolean.cpp FnContext.cpp QNames.cpp signature.cpp
    DateTime.cpp Misc.cpp function.cpp arithmetic.cpp Nodes.cpp
    external_function_adapters.cpp)

IF (ZORBA_WITH_REST)
  SET(FUNCTIONS_SRCS ${FUNCTIONS_SRCS} Rest.cpp)
ENDIF (ZORBA_WITH_REST)
