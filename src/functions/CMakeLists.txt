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
    Accessors.cpp
    Alexis.cpp
    arithmetic.cpp
    Boolean.cpp
    Collections.cpp
    ContextFunctions.cpp
    Convertors.cpp
    DateTime.cpp
    EnclosedExpr.cpp
    external_function_adapters.cpp
    VarDecl.cpp
    function.cpp
    single_seq_func.cpp
    library.cpp
    Misc.cpp
    Nodes.cpp
    Numerics.cpp
    QNames.cpp
    Sequences.cpp
    signature.cpp
    Strings.cpp
    tuple_functions.cpp
    XQDocFunctions.cpp
    InternalOperators.cpp
    Index.cpp)

IF (ZORBA_WITH_REST)
  SET(FUNCTIONS_SRCS ${FUNCTIONS_SRCS} Rest.cpp)
ENDIF (ZORBA_WITH_REST)

IF (ZORBA_WITH_EMAIL)
  SET(FUNCTIONS_SRCS ${FUNCTIONS_SRCS} Email.cpp)
ENDIF (ZORBA_WITH_EMAIL)

IF (ZORBA_WITH_FOP)
  SET(FUNCTIONS_SRCS ${FUNCTIONS_SRCS} Fop.cpp)
ENDIF (ZORBA_WITH_FOP)

