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
#include "runtime/parsing_and_serializing/parsing_and_serializing.h"
#include "system/globalenv.h"



namespace zorba {

// <FnParseXmlIterator>
const char* FnParseXmlIterator::class_name_str = "FnParseXmlIterator";
FnParseXmlIterator::class_factory<FnParseXmlIterator>
FnParseXmlIterator::g_class_factory;

const serialization::ClassVersion 
FnParseXmlIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnParseXmlIterator::class_versions_count =
sizeof(FnParseXmlIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnParseXmlIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnParseXmlIterator::~FnParseXmlIterator() {}

// </FnParseXmlIterator>


// <FnParseXmlFragmentIterator>
const char* FnParseXmlFragmentIterator::class_name_str = "FnParseXmlFragmentIterator";
FnParseXmlFragmentIterator::class_factory<FnParseXmlFragmentIterator>
FnParseXmlFragmentIterator::g_class_factory;

const serialization::ClassVersion 
FnParseXmlFragmentIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnParseXmlFragmentIterator::class_versions_count =
sizeof(FnParseXmlFragmentIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnParseXmlFragmentIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnParseXmlFragmentIterator::~FnParseXmlFragmentIterator() {}

// </FnParseXmlFragmentIterator>


// <FnSerializeIterator>
const char* FnSerializeIterator::class_name_str = "FnSerializeIterator";
FnSerializeIterator::class_factory<FnSerializeIterator>
FnSerializeIterator::g_class_factory;

const serialization::ClassVersion 
FnSerializeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnSerializeIterator::class_versions_count =
sizeof(FnSerializeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnSerializeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSerializeIterator::~FnSerializeIterator() {}

// </FnSerializeIterator>



}


