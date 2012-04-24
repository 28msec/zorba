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
#include "runtime/schema/schema.h"
#include "system/globalenv.h"


#include "types/typemanager.h"
#include "types/schema/schema.h"
#include "types/schema/validate.h"

namespace zorba {

#ifndef ZORBA_NO_XMLSCHEMA
// <ValidateIterator>
ValidateIterator::class_factory<ValidateIterator>
ValidateIterator::g_class_factory;


void ValidateIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ValidateIterator::~ValidateIterator() {}

// </ValidateIterator>

#endif
// <ZorbaValidateInPlaceIterator>
ZorbaValidateInPlaceIterator::class_factory<ZorbaValidateInPlaceIterator>
ZorbaValidateInPlaceIterator::g_class_factory;


void ZorbaValidateInPlaceIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ZorbaValidateInPlaceIterator::~ZorbaValidateInPlaceIterator() {}

// </ZorbaValidateInPlaceIterator>


// <ZorbaSchemaTypeIterator>
ZorbaSchemaTypeIterator::class_factory<ZorbaSchemaTypeIterator>
ZorbaSchemaTypeIterator::g_class_factory;


void ZorbaSchemaTypeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaSchemaTypeIterator::~ZorbaSchemaTypeIterator() {}

// </ZorbaSchemaTypeIterator>


// <ZorbaIsValidatedIterator>
ZorbaIsValidatedIterator::class_factory<ZorbaIsValidatedIterator>
ZorbaIsValidatedIterator::g_class_factory;


void ZorbaIsValidatedIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaIsValidatedIterator::~ZorbaIsValidatedIterator() {}

// </ZorbaIsValidatedIterator>



}


