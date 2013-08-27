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
#include "runtime/csv/csv.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

// <CsvParseIterator>
SERIALIZABLE_CLASS_VERSIONS(CsvParseIterator)

void CsvParseIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CsvParseIterator, CsvParseIteratorState>*)this);
}


void CsvParseIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CsvParseIterator::~CsvParseIterator() {}

CsvParseIteratorState::CsvParseIteratorState() {}

CsvParseIteratorState::~CsvParseIteratorState() {}


void CsvParseIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  cast_unquoted_ = true;
  line_no_ = 1;
  missing_ = missing::null;
  skip_called_ = false;
}

void CsvParseIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  cast_unquoted_ = true;
  line_no_ = 1;
  missing_ = missing::null;
  skip_called_ = false;
}
// </CsvParseIterator>


// <CsvSerializeIterator>
SERIALIZABLE_CLASS_VERSIONS(CsvSerializeIterator)

void CsvSerializeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CsvSerializeIterator, CsvSerializeIteratorState>*)this);
}


void CsvSerializeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CsvSerializeIterator::~CsvSerializeIterator() {}

CsvSerializeIteratorState::CsvSerializeIteratorState() {}

CsvSerializeIteratorState::~CsvSerializeIteratorState() {}


void CsvSerializeIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </CsvSerializeIterator>



}


