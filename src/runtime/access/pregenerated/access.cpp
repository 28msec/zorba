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
#include "runtime/access/access.h"
#include "system/globalenv.h"



namespace zorba {

// <FnAvailableEnvironmentVariablesIterator>
const char* FnAvailableEnvironmentVariablesIterator::class_name_str = "FnAvailableEnvironmentVariablesIterator";
FnAvailableEnvironmentVariablesIterator::class_factory<FnAvailableEnvironmentVariablesIterator>
FnAvailableEnvironmentVariablesIterator::g_class_factory;

const serialization::ClassVersion 
FnAvailableEnvironmentVariablesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnAvailableEnvironmentVariablesIterator::class_versions_count =
sizeof(FnAvailableEnvironmentVariablesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnAvailableEnvironmentVariablesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnAvailableEnvironmentVariablesIterator::~FnAvailableEnvironmentVariablesIterator() {}

FnAvailableEnvironmentVariablesIteratorState::FnAvailableEnvironmentVariablesIteratorState() {}

FnAvailableEnvironmentVariablesIteratorState::~FnAvailableEnvironmentVariablesIteratorState() {}

// </FnAvailableEnvironmentVariablesIterator>


// <FnEnvironmentVariableIterator>
const char* FnEnvironmentVariableIterator::class_name_str = "FnEnvironmentVariableIterator";
FnEnvironmentVariableIterator::class_factory<FnEnvironmentVariableIterator>
FnEnvironmentVariableIterator::g_class_factory;

const serialization::ClassVersion 
FnEnvironmentVariableIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnEnvironmentVariableIterator::class_versions_count =
sizeof(FnEnvironmentVariableIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnEnvironmentVariableIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnEnvironmentVariableIterator::~FnEnvironmentVariableIterator() {}

// </FnEnvironmentVariableIterator>



}


