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
#include "runtime/fetch/fetch.h"
#include "system/globalenv.h"



namespace zorba {

// <FetchContentIterator>
const char* FetchContentIterator::class_name_str = "FetchContentIterator";
FetchContentIterator::class_factory<FetchContentIterator>
FetchContentIterator::g_class_factory;

const serialization::ClassVersion 
FetchContentIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FetchContentIterator::class_versions_count =
sizeof(FetchContentIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FetchContentIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FetchContentIterator::~FetchContentIterator() {}

// </FetchContentIterator>


// <FetchContentTypeIterator>
const char* FetchContentTypeIterator::class_name_str = "FetchContentTypeIterator";
FetchContentTypeIterator::class_factory<FetchContentTypeIterator>
FetchContentTypeIterator::g_class_factory;

const serialization::ClassVersion 
FetchContentTypeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FetchContentTypeIterator::class_versions_count =
sizeof(FetchContentTypeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FetchContentTypeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FetchContentTypeIterator::~FetchContentTypeIterator() {}

// </FetchContentTypeIterator>



}

