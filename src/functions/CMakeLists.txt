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
SET(FUNCTIONS_SRCS)

STRING(LENGTH "${CMAKE_SOURCE_DIR}/src/runtime/spec/" RUNTIME_SPEC_LENGTH)

SET(CODEGEN_HEADER_GENERATOR              "${CMAKE_SOURCE_DIR}/src/runtime/spec/codegen-h.xq")
SET(CODEGEN_SOURCE_GENERATOR              "${CMAKE_SOURCE_DIR}/src/runtime/spec/codegen-cpp.xq")
SET(FUNCTION_HEADER_GENERATOR             "${CMAKE_SOURCE_DIR}/src/runtime/spec/function-enum.xq")

FUNCTION_ENUM_GENERATOR(${FUNCTION_HEADER_GENERATOR}
                        "${ABSOLUTE_SPEC_FILES}"
                        "src/functions/function_enum.h"
                        "file-list:=${SPEC_FILES}"
                        ${ZORBA_WORKS})

SET_SOURCE_FILES_PROPERTIES(${CMAKE_SOURCE_DIR}/src/functions/function.h
                            PROPERTIES OBJECT_DEPENDS "${CMAKE_SOURCE_DIR}/src/functions/function_enum.h")

FOREACH(SPEC_FILE ${SPEC_FILES})
  GET_FILENAME_COMPONENT(SPEC_FILE_NAME ${SPEC_FILE} NAME)
  STRING(REPLACE ".xml" "" SPEC_PREFIX ${SPEC_FILE_NAME})

  CODEGEN_GENERATOR(${CODEGEN_SOURCE_GENERATOR}
                    ${CODEGEN_HEADER_GENERATOR} "${CMAKE_SOURCE_DIR}/src/runtime/spec/${SPEC_FILE}"
                    "src/functions/func_${SPEC_PREFIX}"
                    "file:=${CMAKE_SOURCE_DIR}/src/runtime/spec/${SPEC_FILE}"
                    "mappings:=${CMAKE_SOURCE_DIR}/src/runtime/spec/mappings.xml"
                      ${ZORBA_WORKS})
  LIST(APPEND FUNCTIONS_SRCS
              "func_${SPEC_PREFIX}.cpp"
      )

ENDFOREACH(SPEC_FILE)

LIST(APPEND FUNCTIONS_SRCS
    # provides the functions return_type,
    # computeAnnotation, and specialize
    accessors_impl.cpp
    booleans_impl.cpp
    durations_dates_times_impl.cpp
    sequences_impl.cpp
    Alexis.cpp
    arithmetic.cpp
    Collections.cpp
    StaticContext.cpp
    DynamicContext.cpp
    DataDefinitionLanguage.cpp
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
    signature.cpp
    tuple_functions.cpp
    XQDocFunctions.cpp
    InternalOperators.cpp
    Index.cpp
    nodeid_internal.cpp)

IF (ZORBA_WITH_REST)
  SET(FUNCTIONS_SRCS ${FUNCTIONS_SRCS} Rest.cpp)
ENDIF (ZORBA_WITH_REST)

IF (ZORBA_WITH_FOP)
  SET(FUNCTIONS_SRCS ${FUNCTIONS_SRCS} Fop.cpp)
ENDIF (ZORBA_WITH_FOP)

