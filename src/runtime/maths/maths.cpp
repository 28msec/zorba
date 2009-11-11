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

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/maths/maths.h"
#include "system/globalenv.h"



namespace zorba {

// <FnSQRTIterator>
const char* FnSQRTIterator::class_name_str = "FnSQRTIterator";
FnSQRTIterator::class_factory<FnSQRTIterator>
FnSQRTIterator::g_class_factory;

const serialization::ClassVersion 
FnSQRTIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnSQRTIterator::class_versions_count =
sizeof(FnSQRTIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnSQRTIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

FnSQRTIterator::~FnSQRTIterator() {}

// </FnSQRTIterator>


// <FnAtan2Iterator>
const char* FnAtan2Iterator::class_name_str = "FnAtan2Iterator";
FnAtan2Iterator::class_factory<FnAtan2Iterator>
FnAtan2Iterator::g_class_factory;

const serialization::ClassVersion 
FnAtan2Iterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnAtan2Iterator::class_versions_count =
sizeof(FnAtan2Iterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnAtan2Iterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

FnAtan2Iterator::~FnAtan2Iterator() {}

// </FnAtan2Iterator>



}