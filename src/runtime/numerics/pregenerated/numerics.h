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
#ifndef ZORBA_RUNTIME_NUMERICS_NUMERICS_H
#define ZORBA_RUNTIME_NUMERICS_NUMERICS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "util/utf8_string.h"


namespace zorba {

/**
 * fn:abs
 * Author: Zorba Team
 */
class AbsIterator : public NaryBaseIterator<AbsIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(AbsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AbsIterator,
    NaryBaseIterator<AbsIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  AbsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<AbsIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~AbsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:ceiling
 * Author: Zorba Team
 */
class CeilingIterator : public NaryBaseIterator<CeilingIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CeilingIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CeilingIterator,
    NaryBaseIterator<CeilingIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CeilingIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CeilingIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CeilingIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:floor
 * Author: Zorba Team
 */
class FloorIterator : public NaryBaseIterator<FloorIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FloorIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FloorIterator,
    NaryBaseIterator<FloorIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FloorIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FloorIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FloorIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:round
 * Author: Zorba Team
 */
class RoundIterator : public NaryBaseIterator<RoundIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(RoundIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RoundIterator,
    NaryBaseIterator<RoundIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  RoundIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<RoundIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~RoundIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:round-half-to-even
 * Author: Zorba Team
 */
class RoundHalfToEvenIterator : public NaryBaseIterator<RoundHalfToEvenIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(RoundHalfToEvenIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RoundHalfToEvenIterator,
    NaryBaseIterator<RoundHalfToEvenIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  RoundHalfToEvenIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<RoundHalfToEvenIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~RoundHalfToEvenIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:format-number
 * Author: Zorba Team
 */
class FormatNumberIterator : public NaryBaseIterator<FormatNumberIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FormatNumberIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FormatNumberIterator,
    NaryBaseIterator<FormatNumberIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FormatNumberIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FormatNumberIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FormatNumberIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:format-integer
 * Author: Zorba Team
 */
class FormatIntegerIterator : public NaryBaseIterator<FormatIntegerIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FormatIntegerIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FormatIntegerIterator,
    NaryBaseIterator<FormatIntegerIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FormatIntegerIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FormatIntegerIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FormatIntegerIterator();

public:
  static xs_integer StringToXsInteger(const char * str);
  static void checkOptionalModifier(utf8_string<zstring> & utf8_picture, unsigned int off, bool * is_ordinal, bool * is_traditional, utf8_string<zstring> & word_terminal);
  static void formatIntegerAZ(xs_integer valueInteger, char c0, zstring & resultString);
  static void formatIntegerRoman(xs_integer valueInteger, zstring & resultString);
  static void formatIntegerEnglish(xs_integer valueInteger, bool is_ordinal, zstring & resultString);
  static bool isDecimalDigitPattern(utf8_string<zstring> & utf8_picture, unsigned int * picture_size, unsigned int * groupingInterval, utf8_string<zstring>::value_type * groupingChar, utf8_string<zstring>::value_type * utf8zero);
  static void formatIntegerDecimalPattern(zstring::const_reverse_iterator valueit, zstring::const_reverse_iterator   & valueit_rend, std::vector<unicode::code_point>::const_reverse_iterator pictureit, std::vector<unicode::code_point>::const_reverse_iterator  & pictureit_rend, unsigned int picture_pos, unsigned int grouping_interval, utf8_string<zstring>::value_type grouping_char, utf8_string<zstring>::value_type utf8zero, utf8_string<zstring> & utf8_result);
  static void addOrdinalEnglish(zstring & valueString, unsigned int valuelen, utf8_string<zstring> & utf8_result);
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
