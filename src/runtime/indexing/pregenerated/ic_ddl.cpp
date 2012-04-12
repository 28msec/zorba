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
ActivateICIterator::class_factory<ActivateICIterator>
ActivateICIterator::g_class_factory;


void ActivateICIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ActivateICIterator::~ActivateICIterator() {}

// </ActivateICIterator>


// <DeactivateICIterator>
DeactivateICIterator::class_factory<DeactivateICIterator>
DeactivateICIterator::g_class_factory;


void DeactivateICIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

DeactivateICIterator::~DeactivateICIterator() {}

// </DeactivateICIterator>


// <CheckICIterator>
CheckICIterator::class_factory<CheckICIterator>
CheckICIterator::g_class_factory;


void CheckICIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

CheckICIterator::~CheckICIterator() {}

// </CheckICIterator>



}


