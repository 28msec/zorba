/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
SERIALIZABLE_CLASS_VERSIONS(FnParseXmlIterator)

void FnParseXmlIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnParseXmlIterator, PlanIteratorState>*)this);
}


void FnParseXmlIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnParseXmlIterator::~FnParseXmlIterator() {}


zstring FnParseXmlIterator::getNameAsString() const {
  return "fn:parse-xml";
}
// </FnParseXmlIterator>


// <FnSerializeIterator>
SERIALIZABLE_CLASS_VERSIONS(FnSerializeIterator)

void FnSerializeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnSerializeIterator, PlanIteratorState>*)this);
}


void FnSerializeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSerializeIterator::~FnSerializeIterator() {}


zstring FnSerializeIterator::getNameAsString() const {
  return "fn:serialize";
}
// </FnSerializeIterator>



}


