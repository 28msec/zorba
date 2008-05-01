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

SET(RUNTIME_SRCS
    accessors/AccessorsImpl.cpp
    api/plan_iterator_wrapper.cpp
    api/plan_wrapper.cpp
    base/plan_iterator.cpp
    booleans/BooleanImpl.cpp
    context/ContextImpl.cpp
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
    dateTime/DurationsDatesTimes.cpp
    debug/debug_iterators.cpp
    fncontext/FnContextImpl.cpp
    numerics/NumericsImpl.cpp
    qnames/QNamesImpl.cpp
    sequences/SequencesImpl.cpp
    strings/StringsImpl.cpp
    visitors/accept.cpp
    visitors/iterprinter.cpp
    visitors/printervisitor.cpp
    update/update.cpp
    misc/MiscImpl.cpp
    nodes/NodesImpl.cpp
)

IF (ZORBA_WITH_REST)
  SET(RUNTIME_SRCS ${RUNTIME_SRCS} rest/rest.cpp)
  HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS rest)
ENDIF (ZORBA_WITH_REST)


HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS accessors)
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
