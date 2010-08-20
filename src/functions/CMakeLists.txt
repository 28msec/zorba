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

SET(CODEGEN_HEADER_GENERATOR     "${SPEC_DIR}/codegen-h.xq")
SET(CODEGEN_SOURCE_GENERATOR     "${SPEC_DIR}/codegen-cpp.xq")
SET(FUNCTION_HEADER_GENERATOR    "${SPEC_DIR}/function-enum.xq")
SET(CODEGEN_MAPPINGS_FILE        "${SPEC_DIR}/mappings.xml")
SET(CODEGEN_UTILS_FILE           "${SPEC_DIR}/utils.xq")

# Generate function_enum.h, and mark function.h as depending on the
# generated file so it will be built at appropriate times
ZORBA_RUNTIME_GENERATOR(
  "${FUNCTION_HEADER_GENERATOR}"
  "" # No external variables for query
  "${SPEC_FILES}"
  "${CODEGEN_UTILS_FILE}"
  "${CMAKE_BINARY_DIR}/src/functions/function_enum.h")
SET_SOURCE_FILES_PROPERTIES(${CMAKE_SOURCE_DIR}/src/functions/function.h
  PROPERTIES OBJECT_DEPENDS "${CMAKE_BINARY_DIR}/src/functions/function_enum.h")

FOREACH(SPEC_FILE ${SPEC_FILES})

  GET_FILENAME_COMPONENT(SPEC_FILE_NAME ${SPEC_FILE} NAME)
  STRING(REPLACE ".xml" "" SPEC_PREFIX ${SPEC_FILE_NAME})

  SET(GEN_H "${CMAKE_BINARY_DIR}/src/functions/func_${SPEC_PREFIX}.h")
  SET(GEN_CPP "${CMAKE_BINARY_DIR}/src/functions/func_${SPEC_PREFIX}.cpp")

  # Generate .cpp and .h files. .cpp file depends on .h.
  ZORBA_RUNTIME_GENERATOR(
    "${CODEGEN_HEADER_GENERATOR}"
    "file:=${SPEC_FILE}"    
    "${SPEC_FILE}"
    "${CODEGEN_MAPPINGS_FILE};${CODEGEN_UTILS_FILE}"
    "${GEN_H}")
  ZORBA_RUNTIME_GENERATOR(
    "${CODEGEN_SOURCE_GENERATOR}"
    "file:=${SPEC_FILE};mappings:=${CODEGEN_MAPPINGS_FILE}"    
    "${SPEC_FILE}"
    "${GEN_H};${CODEGEN_MAPPINGS_FILE};${CODEGEN_UTILS_FILE}"
    "${GEN_CPP}")

  LIST(APPEND FUNCTIONS_SRCS
    "func_${SPEC_PREFIX}.cpp"
    )

ENDFOREACH(SPEC_FILE)

LIST(APPEND FUNCTIONS_SRCS
    # provides the functions return_type,
    # computeAnnotation, and specialize
    accessors_impl.cpp
    booleans_impl.cpp
    debug_impl.cpp
    durations_dates_times_impl.cpp
    sequences_impl.cpp
    fnerror_impl.cpp
    index_ddl_impl.cpp
    Alexis.cpp
    arithmetic.cpp
    EnclosedExpr.cpp
    external_function_adapters.cpp
    VarDecl.cpp
    function.cpp
    single_seq_func.cpp
    udf.cpp
    library.cpp
    Numerics.cpp
    signature.cpp
    InternalOperators.cpp
    nodeid_internal.cpp
    func_numerics_impl.cpp
    func_index_ddl.cpp)

IF (ZORBA_WITH_REST)
  SET(FUNCTIONS_SRCS ${FUNCTIONS_SRCS} Rest.cpp)
ENDIF (ZORBA_WITH_REST)

IF (ZORBA_WITH_FOP)
  SET(FUNCTIONS_SRCS ${FUNCTIONS_SRCS} Fop.cpp)
ENDIF (ZORBA_WITH_FOP)

