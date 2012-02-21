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
const char* CurrentDateTimeIterator::class_name_str = "CurrentDateTimeIterator";
CurrentDateTimeIterator::class_factory<CurrentDateTimeIterator>
CurrentDateTimeIterator::g_class_factory;

const serialization::ClassVersion 
CurrentDateTimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CurrentDateTimeIterator::class_versions_count =
sizeof(CurrentDateTimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* CurrentDateIterator::class_name_str = "CurrentDateIterator";
CurrentDateIterator::class_factory<CurrentDateIterator>
CurrentDateIterator::g_class_factory;

const serialization::ClassVersion 
CurrentDateIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CurrentDateIterator::class_versions_count =
sizeof(CurrentDateIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* CurrentTimeIterator::class_name_str = "CurrentTimeIterator";
CurrentTimeIterator::class_factory<CurrentTimeIterator>
CurrentTimeIterator::g_class_factory;

const serialization::ClassVersion 
CurrentTimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CurrentTimeIterator::class_versions_count =
sizeof(CurrentTimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ImplicitTimezoneIterator::class_name_str = "ImplicitTimezoneIterator";
ImplicitTimezoneIterator::class_factory<ImplicitTimezoneIterator>
ImplicitTimezoneIterator::g_class_factory;

const serialization::ClassVersion 
ImplicitTimezoneIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ImplicitTimezoneIterator::class_versions_count =
sizeof(ImplicitTimezoneIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* DefaultCollationIterator::class_name_str = "DefaultCollationIterator";
DefaultCollationIterator::class_factory<DefaultCollationIterator>
DefaultCollationIterator::g_class_factory;

const serialization::ClassVersion 
DefaultCollationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DefaultCollationIterator::class_versions_count =
sizeof(DefaultCollationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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


