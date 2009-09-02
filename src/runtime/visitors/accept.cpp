/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * For simplicity, this file contains the accept implementation of all PlanIterators.
 * The majority of accept's can be implemented with a macro.
 **/

#include "runtime/visitors/planitervisitor.h"

#include "runtime/indexing/value_index_probe.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/debug/debug_iterators.h"
#include "runtime/update/update.h"
#include "runtime/qnames/QNamesImpl.h"
#ifdef ZORBA_WITH_REST
#include "runtime/rest/rest.h"
#endif

#include "store/api/iterator.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

    

namespace zorba {
  



} /* namespace zorba */
