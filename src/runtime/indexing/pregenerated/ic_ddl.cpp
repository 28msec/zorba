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
#include "runtime/indexing/ic_ddl.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

// <ActivateICIterator>
const char* ActivateICIterator::class_name_str = "ActivateICIterator";
ActivateICIterator::class_factory<ActivateICIterator>
ActivateICIterator::g_class_factory;

const serialization::ClassVersion 
ActivateICIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ActivateICIterator::class_versions_count =
sizeof(ActivateICIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ActivateICIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ActivateICIterator::~ActivateICIterator() {}

// </ActivateICIterator>


// <DeactivateICIterator>
const char* DeactivateICIterator::class_name_str = "DeactivateICIterator";
DeactivateICIterator::class_factory<DeactivateICIterator>
DeactivateICIterator::g_class_factory;

const serialization::ClassVersion 
DeactivateICIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DeactivateICIterator::class_versions_count =
sizeof(DeactivateICIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void DeactivateICIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

DeactivateICIterator::~DeactivateICIterator() {}

// </DeactivateICIterator>


// <CheckICIterator>
const char* CheckICIterator::class_name_str = "CheckICIterator";
CheckICIterator::class_factory<CheckICIterator>
CheckICIterator::g_class_factory;

const serialization::ClassVersion 
CheckICIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CheckICIterator::class_versions_count =
sizeof(CheckICIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CheckICIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

CheckICIterator::~CheckICIterator() {}

// </CheckICIterator>



}


