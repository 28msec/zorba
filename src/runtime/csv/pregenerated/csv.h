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
#ifndef ZORBA_RUNTIME_CSV_CSV_H
#define ZORBA_RUNTIME_CSV_CSV_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include <sstream>
#include <vector>
#include "runtime/csv/csv_util.h"
#include "util/csv_parser.h"
#include "util/mem_streambuf.h"
#include "zorbatypes/zstring.h"


namespace zorba {

/**
 * 
 * Author: 
 */
class CsvParseIteratorState : public PlanIteratorState
{
public:
  bool cast_unquoted_; //
  csv_parser csv_; //
  zstring extra_name_; //
  std::istringstream iss_; //
  std::vector<store::Item_t> keys_; //
  unsigned line_no_; //
  mem_streambuf mem_streambuf_; //
  missing::type missing_; //
  zstring string_; //

  CsvParseIteratorState();

  ~CsvParseIteratorState();

  void reset(PlanState&);
};

class CsvParseIterator : public NaryBaseIterator<CsvParseIterator, CsvParseIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CsvParseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CsvParseIterator,
    NaryBaseIterator<CsvParseIterator, CsvParseIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CsvParseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CsvParseIterator, CsvParseIteratorState>(sctx, loc, children)
  {}

  virtual ~CsvParseIterator();

public:
  bool count(store::Item_t& result, PlanState& planState) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class CsvSerializeIteratorState : public PlanIteratorState
{
public:
  zstring boolean_string_[2]; //
  store::Item_t header_item_; //
  std::vector<store::Item_t> keys_; //
  zstring must_quote_; //
  zstring null_string_; //
  char quote_; //
  zstring quote_esc_; //
  char separator_; //

  CsvSerializeIteratorState();

  ~CsvSerializeIteratorState();

  void reset(PlanState&);
};

class CsvSerializeIterator : public NaryBaseIterator<CsvSerializeIterator, CsvSerializeIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CsvSerializeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CsvSerializeIterator,
    NaryBaseIterator<CsvSerializeIterator, CsvSerializeIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CsvSerializeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CsvSerializeIterator, CsvSerializeIteratorState>(sctx, loc, children)
  {}

  virtual ~CsvSerializeIterator();

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
