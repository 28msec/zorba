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
#include "runtime/context/context.h"
#include "system/globalenv.h"



namespace zorba {

// <CurrentDateTimeIterator>
CurrentDateTimeIterator::class_factory<CurrentDateTimeIterator>
CurrentDateTimeIterator::g_class_factory;


void CurrentDateTimeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CurrentDateTimeIterator::~CurrentDateTimeIterator() {}

// </CurrentDateTimeIterator>


// <CurrentDateIterator>
CurrentDateIterator::class_factory<CurrentDateIterator>
CurrentDateIterator::g_class_factory;


void CurrentDateIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CurrentDateIterator::~CurrentDateIterator() {}

// </CurrentDateIterator>


// <CurrentTimeIterator>
CurrentTimeIterator::class_factory<CurrentTimeIterator>
CurrentTimeIterator::g_class_factory;


void CurrentTimeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CurrentTimeIterator::~CurrentTimeIterator() {}

// </CurrentTimeIterator>


// <ImplicitTimezoneIterator>
ImplicitTimezoneIterator::class_factory<ImplicitTimezoneIterator>
ImplicitTimezoneIterator::g_class_factory;


void ImplicitTimezoneIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ImplicitTimezoneIterator::~ImplicitTimezoneIterator() {}

// </ImplicitTimezoneIterator>


// <DefaultCollationIterator>
DefaultCollationIterator::class_factory<DefaultCollationIterator>
DefaultCollationIterator::g_class_factory;


void DefaultCollationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DefaultCollationIterator::~DefaultCollationIterator() {}

// </DefaultCollationIterator>



}


