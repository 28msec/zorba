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

#STRING(LENGTH "${CMAKE_SOURCE_DIR}/src/runtime/spec/" RUNTIME_SPEC_LENGTH)

SET(RUNTIME_HEADER_GENERATOR "${CMAKE_SOURCE_DIR}/src/runtime/spec/iterator_h.xq")
SET(RUNTIME_CPP_GENERATOR    "${CMAKE_SOURCE_DIR}/src/runtime/spec/iterator_cpp.xq")
SET(PRINTER_VISITOR_HEADER_GENERATOR      "${CMAKE_SOURCE_DIR}/src/runtime/spec/printer_visitor_h.xq")
SET(PRINTER_VISITOR_CPP_VISITOR_GENERATOR "${CMAKE_SOURCE_DIR}/src/runtime/spec/printer_visitor_cpp.xq")
SET(PLANINTER_VISITOR_HEADER_GENERATOR    "${CMAKE_SOURCE_DIR}/src/runtime/spec/plan_iter_visitor_h.xq")

FOREACH(SPEC_FILE ${SPEC_FILES})
  STRING(LENGTH ${SPEC_FILE} SPEC_FILE_NAME_LENGTH)
  MATH(EXPR SPEC_PREFIX_LENGTH "${SPEC_FILE_NAME_LENGTH} - 4")
  STRING(SUBSTRING ${SPEC_FILE} 0 ${SPEC_PREFIX_LENGTH} SPEC_PREFIX)

  SET(ABSOLUTE_SPEC_FILE_NAME "${CMAKE_SOURCE_DIR}/src/runtime/spec/${SPEC_FILE}")

  RUNTIME_GENERATOR(${RUNTIME_CPP_GENERATOR}
                    ${RUNTIME_HEADER_GENERATOR}
                    "${ABSOLUTE_SPEC_FILE_NAME}"
                    "src/runtime/${SPEC_PREFIX}"
                    "name:=runtime/${SPEC_PREFIX}"
                    "input=${ABSOLUTE_SPEC_FILE_NAME}"
                    ${ZORBA_WORKS})

  LIST(APPEND RUNTIME_SRCS 
              "${SPEC_PREFIX}.cpp"
              "${SPEC_PREFIX}_impl.cpp")
ENDFOREACH(SPEC_FILE)

# generate the printer_visitor.h and printer_visitor.cpp
# given all the spec files as a list
# the printer_visitor.cpp and printer_visitor_impl.cpp are added to the RUNTIME_SRCS
# the printer_visitor.h depends on the planiter_visitor.h file
PRINTER_VISITOR_GENERATOR(${PRINTER_VISITOR_CPP_VISITOR_GENERATOR}
                          ${PRINTER_VISITOR_HEADER_GENERATOR}
                          "${ABSOLUTE_SPEC_FILES}"
                          "src/runtime/visitors/printer_visitor"
                          "files:=${ABSOLUTE_SPEC_FILES}"
                          ${ZORBA_WORKS})

LIST(APPEND RUNTIME_SRCS
    visitors/printer_visitor.cpp
    visitors/printer_visitor_impl.cpp
)

PLANINTER_VISITOR_GENERATOR(${PLANINTER_VISITOR_HEADER_GENERATOR}
                            "${ABSOLUTE_SPEC_FILES}"
                            "src/runtime/visitors/planiter_visitor"
                            "files:=${SPEC_FILES}"
                            ${ZORBA_WORKS})


LIST(APPEND RUNTIME_SRCS
    visitors/printer_visitor_api.cpp
    api/plan_iterator_wrapper.cpp
    api/plan_wrapper.cpp
    base/plan_iterator.cpp
    booleans/BooleanImpl.cpp
    collections/CollectionsImpl.cpp
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
    core/gflwor/count_iterator.cpp
    core/gflwor/groupby_iterator.cpp
    core/gflwor/tuplesource_iterator.cpp
    core/gflwor/window_iterator.cpp
    core/gflwor/orderby_iterator.cpp
    core/gflwor/outerfor_iterator.cpp
    core/tuple_iterators.cpp
    core/internal_operators.cpp
    durations_dates_times/DurationsDatesTimesImpl.cpp
    debug/zorba_debug_iterator.cpp
    indexing/value_index_ddl.cpp
    indexing/value_index_probe.cpp
    indexing/value_index_context.cpp
    indexing/doc_indexer.cpp
    numerics/NumericsImpl.cpp
    sequences/SequencesImpl.cpp
    visitors/iterprinter.cpp
    update/update.cpp
    util/item_iterator.cpp
    util/UtilImpl.cpp
    util/timeout.cpp
    util/flowctl_exception.cpp
)

HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS debug)

IF (ZORBA_WITH_REST)
  SET(RUNTIME_SRCS ${RUNTIME_SRCS} rest/rest.cpp)
  HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS rest)
ENDIF (ZORBA_WITH_REST)

IF (ZORBA_WITH_FOP)
  SET(RUNTIME_SRCS ${RUNTIME_SRCS} fop/FopImpl.cpp)
  HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS fop)
ENDIF (ZORBA_WITH_FOP)
    

HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS accessors)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS collections)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS context)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS convertors)
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
