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
#ifndef ZORBA_RUNTIME_CONVERTORS_CONVERTORS_H
#define ZORBA_RUNTIME_CONVERTORS_CONVERTORS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"
#include "fstream"
#include "zorbatypes/codepoint_iterator.h"
#include "zorbautils/checked_vector.h"
#include "zorba/xquery.h"


namespace zorba {

/**
 * Parsing a sequence of valid JSON strings into a sequence of XDM elements.
 * Author: Zorba Team
 */
class ZorbaJsonParseIteratorState : public PlanIteratorState
{
public:
  zstring theBaseUri; //the base URI

  ZorbaJsonParseIteratorState();

  ~ZorbaJsonParseIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaJsonParseIterator : public NaryBaseIterator<ZorbaJsonParseIterator, ZorbaJsonParseIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaJsonParseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaJsonParseIterator,
    NaryBaseIterator<ZorbaJsonParseIterator, ZorbaJsonParseIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaJsonParseIterator, ZorbaJsonParseIteratorState>*)this);
  }

  ZorbaJsonParseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaJsonParseIterator, ZorbaJsonParseIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaJsonParseIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * The serialize function takes a sequence of elements as parameter and transforms each element into a valid JSON string.
 * Author: Zorba Team
 */
class ZorbaJsonSerializeIterator : public NaryBaseIterator<ZorbaJsonSerializeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaJsonSerializeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaJsonSerializeIterator,
    NaryBaseIterator<ZorbaJsonSerializeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaJsonSerializeIterator, PlanIteratorState>*)this);
  }

  ZorbaJsonSerializeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaJsonSerializeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaJsonSerializeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Parsing a sequence of valid JsonML strings into a sequence of XDM elements.
 * Author: Zorba Team
 */
class ZorbaJsonParseMLIteratorState : public PlanIteratorState
{
public:
  zstring theBaseUri; //the base URI

  ZorbaJsonParseMLIteratorState();

  ~ZorbaJsonParseMLIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaJsonParseMLIterator : public NaryBaseIterator<ZorbaJsonParseMLIterator, ZorbaJsonParseMLIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaJsonParseMLIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaJsonParseMLIterator,
    NaryBaseIterator<ZorbaJsonParseMLIterator, ZorbaJsonParseMLIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaJsonParseMLIterator, ZorbaJsonParseMLIteratorState>*)this);
  }

  ZorbaJsonParseMLIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaJsonParseMLIterator, ZorbaJsonParseMLIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaJsonParseMLIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * The serialize function takes a sequence of elements as parameter and transforms each element into a valid JsonML string.
 * Author: Zorba Team
 */
class ZorbaJsonSerializeMLIterator : public NaryBaseIterator<ZorbaJsonSerializeMLIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaJsonSerializeMLIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaJsonSerializeMLIterator,
    NaryBaseIterator<ZorbaJsonSerializeMLIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaJsonSerializeMLIterator, PlanIteratorState>*)this);
  }

  ZorbaJsonSerializeMLIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaJsonSerializeMLIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaJsonSerializeMLIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Parse a Comma Separated Values text and generate an XML.
 * Author: Zorba Team
 */
class ZorbaCSV2XMLIteratorState : public PlanIteratorState
{
public:
  xqp_string csv; //csv text
  string_codepoints_iterator csv_it; //iterator over csv codepoints
  bool first_row_is_header; //if the first line of csv describe the name of the columns
  checked_vector<uint32_t> separator_cp; //separator codepoint
  checked_vector <uint32_t> quote_char_cp; //quote char codepoint
  checked_vector <uint32_t> quote_escape_cp; //quote escape codepoints
  store::Item_t row_node_name; //qname of the row element
  store::Item_t default_column_node_name; //default qname of the column element
  zstring baseUri; //keep the base uri from static context
  checked_vector <store::Item_t> header_qnames; //names of headers

  ZorbaCSV2XMLIteratorState();

  ~ZorbaCSV2XMLIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaCSV2XMLIterator : public NaryBaseIterator<ZorbaCSV2XMLIterator, ZorbaCSV2XMLIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaCSV2XMLIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaCSV2XMLIterator,
    NaryBaseIterator<ZorbaCSV2XMLIterator, ZorbaCSV2XMLIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaCSV2XMLIterator, ZorbaCSV2XMLIteratorState>*)this);
  }

  ZorbaCSV2XMLIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaCSV2XMLIterator, ZorbaCSV2XMLIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaCSV2XMLIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Parse a Column Separated Values text and generate an XML.
 * Author: Zorba Team
 */
class ZorbaTXT2XMLIteratorState : public PlanIteratorState
{
public:
  xqp_string csv; //csv text
  string_codepoints_iterator csv_it; //iterator over csv codepoints
  bool first_row_is_header; //if the first line of csv describe the name of the columns
  checked_vector<unsigned int> columns_positions; //separator codepoint
  store::Item_t row_node_name; //qname of the row element
  store::Item_t default_column_node_name; //default qname of the column element
  zstring baseUri; //keep the base uri from static context
  checked_vector <store::Item_t> header_qnames; //names of headers

  ZorbaTXT2XMLIteratorState();

  ~ZorbaTXT2XMLIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaTXT2XMLIterator : public NaryBaseIterator<ZorbaTXT2XMLIterator, ZorbaTXT2XMLIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaTXT2XMLIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaTXT2XMLIterator,
    NaryBaseIterator<ZorbaTXT2XMLIterator, ZorbaTXT2XMLIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaTXT2XMLIterator, ZorbaTXT2XMLIteratorState>*)this);
  }

  ZorbaTXT2XMLIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaTXT2XMLIterator, ZorbaTXT2XMLIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaTXT2XMLIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Parse a Comma Separated Values text file and generate an XML.
 * Author: Zorba Team
 */
class ZorbaCSV2XMLFromFileIteratorState : public PlanIteratorState
{
public:
  std::ifstream csv_stream; //csv text
  ifstream_codepoints_iterator csv_it; //csv codepoints iterator
  bool first_row_is_header; //if the first line of csv describe the name of the columns
  checked_vector<uint32_t> separator_cp; //separator codepoint
  checked_vector <uint32_t> quote_char_cp; //quote char codepoint
  checked_vector <uint32_t> quote_escape_cp; //quote escape codepoints
  store::Item_t row_node_name; //qname of the row element
  store::Item_t default_column_node_name; //default qname of the column element
  zstring baseUri; //keep the base uri from static context
  checked_vector <store::Item_t> header_qnames; //names of headers

  ZorbaCSV2XMLFromFileIteratorState();

  ~ZorbaCSV2XMLFromFileIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaCSV2XMLFromFileIterator : public NaryBaseIterator<ZorbaCSV2XMLFromFileIterator, ZorbaCSV2XMLFromFileIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaCSV2XMLFromFileIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaCSV2XMLFromFileIterator,
    NaryBaseIterator<ZorbaCSV2XMLFromFileIterator, ZorbaCSV2XMLFromFileIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaCSV2XMLFromFileIterator, ZorbaCSV2XMLFromFileIteratorState>*)this);
  }

  ZorbaCSV2XMLFromFileIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaCSV2XMLFromFileIterator, ZorbaCSV2XMLFromFileIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaCSV2XMLFromFileIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Parse a Column Separated Values text file and generate an XML.
 * Author: Zorba Team
 */
class ZorbaTXT2XMLFromFileIteratorState : public PlanIteratorState
{
public:
  std::ifstream csv_stream; //csv text
  ifstream_codepoints_iterator csv_it; //csv codepoints iterator
  bool first_row_is_header; //if the first line of csv describe the name of the columns
  checked_vector<unsigned int> columns_positions; //separator codepoint
  store::Item_t row_node_name; //qname of the row element
  store::Item_t default_column_node_name; //default qname of the column element
  zstring baseUri; //keep the base uri from static context
  checked_vector <store::Item_t> header_qnames; //names of headers

  ZorbaTXT2XMLFromFileIteratorState();

  ~ZorbaTXT2XMLFromFileIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaTXT2XMLFromFileIterator : public NaryBaseIterator<ZorbaTXT2XMLFromFileIterator, ZorbaTXT2XMLFromFileIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaTXT2XMLFromFileIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaTXT2XMLFromFileIterator,
    NaryBaseIterator<ZorbaTXT2XMLFromFileIterator, ZorbaTXT2XMLFromFileIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaTXT2XMLFromFileIterator, ZorbaTXT2XMLFromFileIteratorState>*)this);
  }

  ZorbaTXT2XMLFromFileIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaTXT2XMLFromFileIterator, ZorbaTXT2XMLFromFileIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaTXT2XMLFromFileIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Export XML to a Comma Separated Values text string.
 * Author: Zorba Team
 */
class ZorbaXML2CSVIteratorState : public PlanIteratorState
{
public:
  checked_vector<XQuery_t> compiled_xpaths; //the list of compiled xpaths

  ZorbaXML2CSVIteratorState();

  ~ZorbaXML2CSVIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaXML2CSVIterator : public NaryBaseIterator<ZorbaXML2CSVIterator, ZorbaXML2CSVIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaXML2CSVIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaXML2CSVIterator,
    NaryBaseIterator<ZorbaXML2CSVIterator, ZorbaXML2CSVIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaXML2CSVIterator, ZorbaXML2CSVIteratorState>*)this);
  }

  ZorbaXML2CSVIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaXML2CSVIterator, ZorbaXML2CSVIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaXML2CSVIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Export XML to a Comma Separated Values text file.
 * Author: Zorba Team
 */
class ZorbaXML2CSVFILEIteratorState : public PlanIteratorState
{
public:
  checked_vector<XQuery_t> compiled_xpaths; //the list of compiled xpaths

  ZorbaXML2CSVFILEIteratorState();

  ~ZorbaXML2CSVFILEIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaXML2CSVFILEIterator : public NaryBaseIterator<ZorbaXML2CSVFILEIterator, ZorbaXML2CSVFILEIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaXML2CSVFILEIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaXML2CSVFILEIterator,
    NaryBaseIterator<ZorbaXML2CSVFILEIterator, ZorbaXML2CSVFILEIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaXML2CSVFILEIterator, ZorbaXML2CSVFILEIteratorState>*)this);
  }

  ZorbaXML2CSVFILEIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaXML2CSVFILEIterator, ZorbaXML2CSVFILEIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaXML2CSVFILEIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Export XML to a Column Separated Values text string.
 * Author: Zorba Team
 */
class ZorbaXML2TXTIteratorState : public PlanIteratorState
{
public:
  checked_vector<XQuery_t> compiled_xpaths; //the list of compiled xpaths

  ZorbaXML2TXTIteratorState();

  ~ZorbaXML2TXTIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaXML2TXTIterator : public NaryBaseIterator<ZorbaXML2TXTIterator, ZorbaXML2TXTIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaXML2TXTIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaXML2TXTIterator,
    NaryBaseIterator<ZorbaXML2TXTIterator, ZorbaXML2TXTIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaXML2TXTIterator, ZorbaXML2TXTIteratorState>*)this);
  }

  ZorbaXML2TXTIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaXML2TXTIterator, ZorbaXML2TXTIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaXML2TXTIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Export XML to a Column Separated Values text file.
 * Author: Zorba Team
 */
class ZorbaXML2TXTFILEIteratorState : public PlanIteratorState
{
public:
  checked_vector<XQuery_t> compiled_xpaths; //the list of compiled xpaths

  ZorbaXML2TXTFILEIteratorState();

  ~ZorbaXML2TXTFILEIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaXML2TXTFILEIterator : public NaryBaseIterator<ZorbaXML2TXTFILEIterator, ZorbaXML2TXTFILEIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaXML2TXTFILEIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaXML2TXTFILEIterator,
    NaryBaseIterator<ZorbaXML2TXTFILEIterator, ZorbaXML2TXTFILEIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaXML2TXTFILEIterator, ZorbaXML2TXTFILEIteratorState>*)this);
  }

  ZorbaXML2TXTFILEIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaXML2TXTFILEIterator, ZorbaXML2TXTFILEIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaXML2TXTFILEIterator();

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
