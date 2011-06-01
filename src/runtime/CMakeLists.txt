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
SET(RUNTIME_SRCS)

SET(RUNTIME_HEADER_GENERATOR          "${SPEC_DIR}/iterator_h.xq")
SET(RUNTIME_CPP_GENERATOR             "${SPEC_DIR}/iterator_cpp.xq")

SET(PRINTER_VISITOR_HEADER_GENERATOR  "${SPEC_DIR}/printer_visitor_h.xq")
SET(PRINTER_VISITOR_CPP_GENERATOR     "${SPEC_DIR}/printer_visitor_cpp.xq")
SET(PLANITER_VISITOR_HEADER_GENERATOR "${SPEC_DIR}/plan_iter_visitor_h.xq")
SET(CODEGEN_UTILS_FILE                "${SPEC_DIR}/utils.xq")

SET(PRINTER_VISITOR_HEADER_FILE
  "${SPEC_BINARY_DIR}/visitors/printer_visitor.h")
SET(PRINTER_VISITOR_CPP_FILE
  "${SPEC_BINARY_DIR}/visitors/printer_visitor.cpp")
SET(PLANITER_VISITOR_HEADER_FILE
  "${SPEC_BINARY_DIR}/visitors/planiter_visitor.h")


FOREACH(SPEC_FILE ${SPEC_FILES})
  STRING(LENGTH ${SPEC_FILE} SPEC_FILE_NAME_LENGTH)
  MATH(EXPR SPEC_PREFIX_LENGTH "${SPEC_FILE_NAME_LENGTH} - 4")
  STRING(SUBSTRING ${SPEC_FILE} 0 ${SPEC_PREFIX_LENGTH} SPEC_PREFIX)

  # Generate .cpp and .h files. .cpp depends on .h.
  ZORBA_RUNTIME_GENERATOR(
    "${RUNTIME_HEADER_GENERATOR}"
    "name:=runtime/${SPEC_PREFIX};input=${SPEC_FILE}"
    "${SPEC_FILE}"
    "${CODEGEN_UTILS_FILE}"
    "${SPEC_BINARY_DIR}/${SPEC_PREFIX}.h")
  ZORBA_RUNTIME_GENERATOR(
    "${RUNTIME_CPP_GENERATOR}"
    "name:=runtime/${SPEC_PREFIX};input=${SPEC_FILE}"
    "${SPEC_FILE}"
    "${SPEC_BINARY_DIR}/${SPEC_PREFIX}.h;${CODEGEN_UTILS_FILE}"
    "${SPEC_BINARY_DIR}/${SPEC_PREFIX}.cpp")

  LIST(APPEND RUNTIME_SRCS 
    "${SPEC_PREFIX}.cpp"
    "${SPEC_PREFIX}_impl.cpp")
ENDFOREACH(SPEC_FILE)

# generate the printer_visitor.h and printer_visitor.cpp
# given all the spec files as a list
# the printer_visitor.cpp and printer_visitor_impl.cpp are added to the RUNTIME_SRCS
# the printer_visitor.h depends on the planiter_visitor.h file
ZORBA_RUNTIME_GENERATOR(
  "${PRINTER_VISITOR_HEADER_GENERATOR}"
  "" # No external variables for query
  "${SPEC_FILES}"
  "${CODEGEN_UTILS_FILE}"
  "${PRINTER_VISITOR_HEADER_FILE}")

ZORBA_RUNTIME_GENERATOR(
  "${PRINTER_VISITOR_CPP_GENERATOR}"
  "" # No external variables for query
  "${SPEC_FILES}"
  "${PRINTER_VISITOR_HEADER_FILE};${PLANITER_VISITOR_HEADER_FILE};${CODEGEN_UTILS_FILE}"
  "${PRINTER_VISITOR_CPP_FILE}")


ZORBA_RUNTIME_GENERATOR(
  "${PLANITER_VISITOR_HEADER_GENERATOR}"
  "" # No external variables for query
  "${SPEC_FILES}"
  "${CODEGEN_UTILS_FILE}"
  "${PLANITER_VISITOR_HEADER_FILE}")


LIST(APPEND RUNTIME_SRCS
  visitors/printer_visitor.cpp
  visitors/printer_visitor_impl.cpp
  visitors/printer_visitor_api.cpp
  api/plan_iterator_wrapper.cpp
  api/plan_wrapper.cpp
  base/plan_iterator.cpp
  booleans/BooleanImpl.cpp
  core/apply_updates.cpp
  core/arithmetic_impl.cpp
  core/constructors.cpp
  core/flwor_iterator.cpp
  core/fncall_iterator.cpp
  core/item_iterator.cpp
  core/nodeid_iterators.cpp
  core/path_iterators.cpp
  core/sequencetypes.cpp
  core/trycatch.cpp
  core/var_iterators.cpp
  core/gflwor/common.cpp
  core/gflwor/tuplestream_iterator.cpp
  core/gflwor/for_iterator.cpp
  core/gflwor/let_iterator.cpp
  core/gflwor/where_iterator.cpp
  core/gflwor/comp_function.cpp
  core/gflwor/count_iterator.cpp
  core/gflwor/groupby_iterator.cpp
  core/gflwor/tuplesource_iterator.cpp
  core/gflwor/window_iterator.cpp
  core/gflwor/orderby_iterator.cpp
  core/gflwor/outerfor_iterator.cpp
  core/internal_operators.cpp
  durations_dates_times/DurationsDatesTimesImpl.cpp
  indexing/doc_indexer.cpp
  indexing/index_ddl.cpp
  numerics/NumericsImpl.cpp
  numerics/format_integer_impl.cpp
  sequences/SequencesImpl.cpp
  visitors/iterprinter.cpp
  update/update.cpp
  util/item_iterator.cpp
  util/timeout.cpp
  util/flowctl_exception.cpp
  function_item/function_item.cpp
  function_item/dynamic_fncall_iterator.cpp
  eval/eval.cpp
  collections/collections_base.cpp
  misc/materialize.cpp
  scripting/scripting.cpp
)

IF(NOT ZORBA_NO_FULL_TEXT)
  ADD_SRC_SUBFOLDER(RUNTIME_SRCS full_text FULLTEXT_SRCS)
ENDIF(NOT ZORBA_NO_FULL_TEXT)

IF(ZORBA_WITH_DEBUGGER)
  HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS debug)
ENDIF(ZORBA_WITH_DEBUGGER)

HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS accessors)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS collections)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS store)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS context)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS core)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS numerics)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS strings)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS booleans)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS dateTime)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS base)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS sequences)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS visitors)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS fncontext)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS misc)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS nodes)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS scripting)
