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
#include "runtime/datetime/datetime.h"
#include "system/globalenv.h"



namespace zorba {

// <CurrentDate>
SERIALIZABLE_CLASS_VERSIONS(CurrentDate)

void CurrentDate::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CurrentDate, PlanIteratorState>*)this);
}


void CurrentDate::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CurrentDate::~CurrentDate() {}

// </CurrentDate>


// <CurrentDateTime>
SERIALIZABLE_CLASS_VERSIONS(CurrentDateTime)

void CurrentDateTime::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CurrentDateTime, PlanIteratorState>*)this);
}


void CurrentDateTime::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CurrentDateTime::~CurrentDateTime() {}

// </CurrentDateTime>


// <CurrentTime>
SERIALIZABLE_CLASS_VERSIONS(CurrentTime)

void CurrentTime::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CurrentTime, PlanIteratorState>*)this);
}


void CurrentTime::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CurrentTime::~CurrentTime() {}

// </CurrentTime>


// <MillisToDateTime>
SERIALIZABLE_CLASS_VERSIONS(MillisToDateTime)

void MillisToDateTime::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MillisToDateTime, PlanIteratorState>*)this);
}


void MillisToDateTime::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MillisToDateTime::~MillisToDateTime() {}

// </MillisToDateTime>


// <ParseDate>
SERIALIZABLE_CLASS_VERSIONS(ParseDate)

void ParseDate::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ParseDate, PlanIteratorState>*)this);
}


void ParseDate::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ParseDate::~ParseDate() {}

// </ParseDate>


// <ParseDateTime>
SERIALIZABLE_CLASS_VERSIONS(ParseDateTime)

void ParseDateTime::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ParseDateTime, PlanIteratorState>*)this);
}


void ParseDateTime::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ParseDateTime::~ParseDateTime() {}

// </ParseDateTime>


// <ParseTime>
SERIALIZABLE_CLASS_VERSIONS(ParseTime)

void ParseTime::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ParseTime, PlanIteratorState>*)this);
}


void ParseTime::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ParseTime::~ParseTime() {}

// </ParseTime>


// <Timestamp>
SERIALIZABLE_CLASS_VERSIONS(Timestamp)

void Timestamp::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<Timestamp, PlanIteratorState>*)this);
}


void Timestamp::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

Timestamp::~Timestamp() {}

// </Timestamp>


// <UTCOffset>
SERIALIZABLE_CLASS_VERSIONS(UTCOffset)

void UTCOffset::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<UTCOffset, PlanIteratorState>*)this);
}


void UTCOffset::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

UTCOffset::~UTCOffset() {}

// </UTCOffset>



}


