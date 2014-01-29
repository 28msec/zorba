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

#ifndef ZORBA_RUNTIME_DATETIME_DATETIME_H
#define ZORBA_RUNTIME_DATETIME_DATETIME_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 *    function for getting the current date
 *  
 * Author: Zorba Team
 */
class CurrentDate : public NaryBaseIterator<CurrentDate, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CurrentDate);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CurrentDate,
    NaryBaseIterator<CurrentDate, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CurrentDate(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CurrentDate, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CurrentDate();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    function for getting the current date and time
 *  
 * Author: Zorba Team
 */
class CurrentDateTime : public NaryBaseIterator<CurrentDateTime, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CurrentDateTime);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CurrentDateTime,
    NaryBaseIterator<CurrentDateTime, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CurrentDateTime(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CurrentDateTime, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CurrentDateTime();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    function for getting the current time
 *  
 * Author: Zorba Team
 */
class CurrentTime : public NaryBaseIterator<CurrentTime, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CurrentTime);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CurrentTime,
    NaryBaseIterator<CurrentTime, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CurrentTime(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CurrentTime, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CurrentTime();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    function for converting seconds since epoch to an xs:dateTime
 *  
 * Author: Zorba Team
 */
class MillisToDateTime : public NaryBaseIterator<MillisToDateTime, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MillisToDateTime);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MillisToDateTime,
    NaryBaseIterator<MillisToDateTime, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  MillisToDateTime(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MillisToDateTime, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MillisToDateTime();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    function for parsing strings into a date
 *  
 * Author: Zorba Team
 */
class ParseDate : public NaryBaseIterator<ParseDate, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ParseDate);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ParseDate,
    NaryBaseIterator<ParseDate, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ParseDate(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ParseDate, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ParseDate();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    function for parsing strings into a dateTime
 *  
 * Author: Zorba Team
 */
class ParseDateTime : public NaryBaseIterator<ParseDateTime, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ParseDateTime);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ParseDateTime,
    NaryBaseIterator<ParseDateTime, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ParseDateTime(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ParseDateTime, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ParseDateTime();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    function for parsing strings into a time
 *  
 * Author: Zorba Team
 */
class ParseTime : public NaryBaseIterator<ParseTime, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ParseTime);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ParseTime,
    NaryBaseIterator<ParseTime, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ParseTime(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ParseTime, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ParseTime();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    function for getting the current number of seconds since epoch
 *  
 * Author: Zorba Team
 */
class Timestamp : public NaryBaseIterator<Timestamp, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(Timestamp);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(Timestamp,
    NaryBaseIterator<Timestamp, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  Timestamp(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<Timestamp, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~Timestamp();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    function for getting the current offset from UTC
 *  
 * Author: Zorba Team
 */
class UTCOffset : public NaryBaseIterator<UTCOffset, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(UTCOffset);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(UTCOffset,
    NaryBaseIterator<UTCOffset, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  UTCOffset(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<UTCOffset, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~UTCOffset();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
