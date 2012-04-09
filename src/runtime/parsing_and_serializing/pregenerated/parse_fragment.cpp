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
#include "runtime/parsing_and_serializing/parse_fragment.h"
#include "system/globalenv.h"



namespace zorba {

// <FnParseXmlFragmentIterator>
FnParseXmlFragmentIterator::class_factory<FnParseXmlFragmentIterator>
FnParseXmlFragmentIterator::g_class_factory;


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

FnParseXmlFragmentIteratorState::FnParseXmlFragmentIteratorState() {}

FnParseXmlFragmentIteratorState::~FnParseXmlFragmentIteratorState() {}


void FnParseXmlFragmentIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </FnParseXmlFragmentIterator>



}


