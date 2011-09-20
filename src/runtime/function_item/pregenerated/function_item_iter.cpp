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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************

#include "stdafx.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/function_item/function_item_iter.h"
#include "system/globalenv.h"


#include "context/static_context.h"
#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"

namespace zorba {

// <FunctionNameIterator>
const char* FunctionNameIterator::class_name_str = "FunctionNameIterator";
FunctionNameIterator::class_factory<FunctionNameIterator>
FunctionNameIterator::g_class_factory;

const serialization::ClassVersion 
FunctionNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FunctionNameIterator::class_versions_count =
sizeof(FunctionNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FunctionNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FunctionNameIterator::~FunctionNameIterator() {}

// </FunctionNameIterator>


// <FunctionArityIterator>
const char* FunctionArityIterator::class_name_str = "FunctionArityIterator";
FunctionArityIterator::class_factory<FunctionArityIterator>
FunctionArityIterator::g_class_factory;

const serialization::ClassVersion 
FunctionArityIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FunctionArityIterator::class_versions_count =
sizeof(FunctionArityIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FunctionArityIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FunctionArityIterator::~FunctionArityIterator() {}

// </FunctionArityIterator>


// <PartialApplyIterator>
const char* PartialApplyIterator::class_name_str = "PartialApplyIterator";
PartialApplyIterator::class_factory<PartialApplyIterator>
PartialApplyIterator::g_class_factory;

const serialization::ClassVersion 
PartialApplyIterator::class_versions[] ={{ 1, 0x000905, false}};

const int PartialApplyIterator::class_versions_count =
sizeof(PartialApplyIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void PartialApplyIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

PartialApplyIterator::~PartialApplyIterator() {}

// </PartialApplyIterator>



}


