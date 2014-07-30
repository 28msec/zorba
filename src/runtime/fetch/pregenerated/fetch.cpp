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
#include "runtime/fetch/fetch.h"
#include "system/globalenv.h"



namespace zorba {

// <FetchContentIterator>
SERIALIZABLE_CLASS_VERSIONS(FetchContentIterator)

void FetchContentIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FetchContentIterator, PlanIteratorState>*)this);
}


void FetchContentIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FetchContentIterator::~FetchContentIterator() {}


zstring FetchContentIterator::getNameAsString() const {
  return "fn-zorba-fetch:content";
}
// </FetchContentIterator>


// <FetchContentBinaryIterator>
SERIALIZABLE_CLASS_VERSIONS(FetchContentBinaryIterator)

void FetchContentBinaryIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FetchContentBinaryIterator, PlanIteratorState>*)this);
}


void FetchContentBinaryIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FetchContentBinaryIterator::~FetchContentBinaryIterator() {}


zstring FetchContentBinaryIterator::getNameAsString() const {
  return "fn-zorba-fetch:content-binary";
}
// </FetchContentBinaryIterator>


// <FetchContentTypeIterator>
SERIALIZABLE_CLASS_VERSIONS(FetchContentTypeIterator)

void FetchContentTypeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FetchContentTypeIterator, PlanIteratorState>*)this);
}


void FetchContentTypeIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FetchContentTypeIterator::~FetchContentTypeIterator() {}


zstring FetchContentTypeIterator::getNameAsString() const {
  return "fn-zorba-fetch:content-type";
}
// </FetchContentTypeIterator>



}


