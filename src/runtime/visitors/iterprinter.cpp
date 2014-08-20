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
#include "stdafx.h"

// standard
#include <cassert>
#include <iostream>

// Zorba
#include "runtime/visitors/iterprinter.h"
#include "util/ascii_util.h"
#include "util/json_util.h"
#include "util/indent.h"
#include "util/xml_util.h"
#include "zorba/serializer.h"
#include "zorba/singleton_item_sequence.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

IterPrinter::IterPrinter( ostream &os, char const *descr,  const bool ignore_start_stop  ) :
  descr_( descr ),
  os_( os ),
  ignore_start_stop_( ignore_start_stop )
{
}

IterPrinter::~IterPrinter() {
  // out-of-line since it's virtual
}

template<typename T>
void IterPrinter::doAddVecAttribute( char const *name, const std::vector<T>& values )
{
  std::stringstream joinedValue;
  for (typename std::vector<T>::size_type i = 0; i < values.size(); ++i)
  {
    joinedValue << values[i];
    if (i < (values.size() -1))
      joinedValue << " ";
  }
  addAttribute( name, joinedValue.str().c_str() );
}

void IterPrinter::addVecAttribute( char const *name, const std::vector<std::string>& values )
{
  doAddVecAttribute( name, values );
}

void IterPrinter::addVecAttribute( char const *name, const std::vector<int>& values )
{
  doAddVecAttribute( name, values );
}

void IterPrinter::addItemAttribute( char const *name, const zorba::Item& value )
{
  if (value.isNull())
    return;

  if (value.isJSONItem() || value.isNode())
  {
    Zorba_SerializerOptions_t serOptions;
    serOptions.indent = ZORBA_INDENT_YES;
    Serializer_t serializer = Serializer::createSerializer(serOptions);

    std::stringstream valueSS;
    zorba::SingletonItemSequence lSeq(value);
    serializer->serialize(lSeq.getIterator(), valueSS);

    addAttribute(name, valueSS.str().c_str());
  }
  else if (value.isAtomic())
  {
    switch (value.getTypeCode())
    {
      case zorba::store::XS_STRING:
      case zorba::store::XS_NORMALIZED_STRING:
      case zorba::store::XS_TOKEN:
      case zorba::store::XS_LANGUAGE:
      case zorba::store::XS_NMTOKEN:
      case zorba::store::XS_NAME:
      case zorba::store::XS_NCNAME:
      case zorba::store::XS_ID:
      case zorba::store::XS_IDREF:
      case zorba::store::XS_ENTITY:
      case zorba::store::XS_UNTYPED_ATOMIC:
      case zorba::store::XS_DATETIME:
      case zorba::store::XS_DATE:
      case zorba::store::XS_TIME:
      case zorba::store::XS_DURATION:
      case zorba::store::XS_DT_DURATION:
      case zorba::store::XS_YM_DURATION:
      case zorba::store::XS_GYEAR_MONTH:
      case zorba::store::XS_GYEAR:
      case zorba::store::XS_GMONTH_DAY:
      case zorba::store::XS_GDAY:
      case zorba::store::XS_GMONTH:
      case zorba::store::XS_BASE64BINARY:
      case zorba::store::XS_HEXBINARY:
      case zorba::store::XS_ANY_URI:
      case zorba::store::XS_QNAME:
      case zorba::store::XS_NOTATION:
      case zorba::store::XS_DATETIME_STAMP:
        addAttribute(name, value.getStringValue().c_str());
        return;

      case zorba::store::XS_FLOAT:
      case zorba::store::XS_DOUBLE:
      case zorba::store::XS_DECIMAL:
        addDecAttribute(name, value.getDoubleValue());
        return;

      case zorba::store::XS_INTEGER:
      case zorba::store::XS_NON_POSITIVE_INTEGER:
      case zorba::store::XS_NEGATIVE_INTEGER:
      case zorba::store::XS_POSITIVE_INTEGER:
      case zorba::store::XS_NON_NEGATIVE_INTEGER:
      case zorba::store::XS_INT:
      case zorba::store::XS_LONG:
      case zorba::store::XS_SHORT:
      case zorba::store::XS_BYTE:
      case zorba::store::XS_UNSIGNED_LONG:
      case zorba::store::XS_UNSIGNED_SHORT:
      case zorba::store::XS_UNSIGNED_INT:
      case zorba::store::XS_UNSIGNED_BYTE:
        addIntAttribute(name, value.getLongValue());
        return;

      case zorba::store::XS_BOOLEAN:
        addBoolAttribute(name, value.getBooleanValue());
        return;

      case zorba::store::JS_NULL:
        addAttribute(name, "null");
        return;

      case zorba::store::XS_ANY_ATOMIC:
      case zorba::store::XS_LAST:
        return;
    }
  }
}


///////////////////////////////////////////////////////////////////////////////

XMLIterPrinter::XMLIterPrinter( ostream &os, char const *descr, const bool ignore_start_stop ) :
  IterPrinter( os, descr, ignore_start_stop ),
  theOpenStart( false )
{
}

XMLIterPrinter::~XMLIterPrinter() {
  // out-of-line since it's virtual
}

void XMLIterPrinter::start() {
  if ( !ignore_start_stop_ )
  {
    os_ << indent << "<iterator-tree";
    if ( !descr_.empty() )
      os_ << " description=\"" << zorba::xml::serialize(descr_, true) << '"';
    os_ << ">\n" << inc_indent;
  }
}

void XMLIterPrinter::stop() {
  if ( !ignore_start_stop_ )
  {
    os_ << dec_indent << indent << "</iterator-tree>\n";
  }
}

void XMLIterPrinter::startBeginVisit( char const *name, int ) {
  if ( theOpenStart )
    os_ << ">\n";
  assert( zorba::xml::is_NCName(zstring(name)) );
  os_ << indent << '<' << name << inc_indent;
  theNameStack.push( name );
  theOpenStart = true;
}

void XMLIterPrinter::endBeginVisit( int ) {
}

void XMLIterPrinter::addBoolAttribute( char const *name, bool value ) {
  assert( theOpenStart );
  assert(zorba::xml::is_NCName(zstring(name)));
  os_ << ' ' << name << "=\"" << (value ? "true" : "false") << "\"";
}

void XMLIterPrinter::addAttribute( char const *name, char const *value ) {
  assert( theOpenStart );
  assert( zorba::xml::is_NCName(zstring(name)) );
  os_ << ' ' << name << "=\"" << zorba::xml::serialize(value, true) << "\"";
}

void XMLIterPrinter::addItemAttribute( char const *name, const zorba::Item& value )
{
  if (value.isNull())
    return;

  if (value.isNode())
  {
    Zorba_SerializerOptions_t serOptions;
    serOptions.indent = ZORBA_INDENT_YES;
    serOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    Serializer_t serializer = Serializer::createSerializer(serOptions);

    std::stringstream valueSS;
    zorba::SingletonItemSequence lSeq(value);
    serializer->serialize(lSeq.getIterator(), valueSS);

    addRawStructure(name, valueSS.str().c_str());
  }
  else
    IterPrinter::addItemAttribute(name, value);
}

void XMLIterPrinter::addRawStructure( char const *name, char const *value ) {

  assert( zorba::xml::is_NCName(zstring(name)) );

  if ( theOpenStart )
    os_ << ">\n";

  os_ << inc_indent << indent;
  while (*value != '\0')
  {
    os_ << *value;
    if (*value == '\n')
      os_ << indent;
    ++value;
  }
  os_ << "\n" << dec_indent;

  theOpenStart = false;
}

void XMLIterPrinter::addIntAttribute( char const *name, xs_long value ) {
  assert( theOpenStart );
  assert( zorba::xml::is_NCName(zstring(name)) );
  os_ << ' ' << name << "=\"" << value << "\"";
}

void XMLIterPrinter::addIntAttribute( char const *name, xs_integer value ) {
  assert( theOpenStart );
  assert (zorba::xml::is_NCName(zstring(name)) );
  os_ << ' ' << name << "=\"" << value << "\"";
}

void XMLIterPrinter::addDecAttribute( char const *name, double value ) {
  assert( theOpenStart );
  assert( zorba::xml::is_NCName(zstring(name)) );
  os_ << ' ' << name << "=\"" << value << "\"";
}

void XMLIterPrinter::startEndVisit() {
  assert( !theNameStack.empty() );
  if ( theOpenStart )
    os_ << "/>\n" << dec_indent;
  else
    os_ << dec_indent << indent << "</" << theNameStack.top() << ">\n";
  theNameStack.pop();
  theOpenStart = false;
}

void XMLIterPrinter::endEndVisit() {
}

///////////////////////////////////////////////////////////////////////////////

DOTIterPrinter::DOTIterPrinter( ostream &os, char const *descr, const bool ignore_start_stop ) :
  IterPrinter( os, descr, ignore_start_stop )
{
}

DOTIterPrinter::~DOTIterPrinter() {
  // out-of-line since it's virtual
}

void DOTIterPrinter::start() {
  if ( !ignore_start_stop_ )
  {
    os_ << indent << "digraph {\n" << inc_indent
        << indent << "node [ color=gray, fontname=\"Arial\" ]\n";
  }
}

void DOTIterPrinter::stop() {
  if ( !ignore_start_stop_ )
  {
    os_ << dec_indent << indent << "}\n";
  }
}

void DOTIterPrinter::startBeginVisit( char const *name, int addr ) {
  os_ << indent << addr << " [ label=\"" << name;
}

void DOTIterPrinter::endBeginVisit( int addr ) {
  os_ << "\" ];\n";
  if ( !theNameStack.empty() && theNameStack.top() != addr )
    os_ << indent << theNameStack.top() << " -> " << addr << '\n';
  theNameStack.push( addr );
}

void DOTIterPrinter::addBoolAttribute( char const *name, bool value ) {
  os_ << "\\n" << name << '=' << (value ? "true" : "false");
}

void DOTIterPrinter::addAttribute( char const *name, char const *value ) {
  string temp( value );
  ascii::replace_all( temp, "\"", "\\\"" );
  ascii::replace_all( temp, "\n", " \\n " );
  os_ << "\\n" << name << '=' << temp;
}

void DOTIterPrinter::addRawStructure( char const *name, char const *value ) {
  os_ << "\\n" << name << '=' << value;
}

void DOTIterPrinter::addIntAttribute( char const *name, xs_long value ) {
  os_ << indent << "\\n" << name << '=' << value;
}

void DOTIterPrinter::addIntAttribute( char const *name, xs_integer value ) {
  os_ << indent << "\\n" << name << '=' << value;
}

void DOTIterPrinter::addDecAttribute( char const *name, double value ) {
  os_ << indent << "\\n" << name << '=' << value;
}

void DOTIterPrinter::startEndVisit() {
}

void DOTIterPrinter::endEndVisit() {
  theNameStack.pop();
}

///////////////////////////////////////////////////////////////////////////////

JSONIterPrinter::JSONIterPrinter( ostream &os, char const *descr, const bool ignore_start_stop ) :
  IterPrinter( os, descr, ignore_start_stop )
{
}

JSONIterPrinter::~JSONIterPrinter() {
  // out-of-line since it's virtual
}

void JSONIterPrinter::start() {
  if ( !ignore_start_stop_ )
  {
    os_ << indent << "{\n" << inc_indent;
    if ( !descr_.empty() )
      os_ << indent << "\"description\": \"" << descr_ << "\",\n";
    os_ << indent << "\"iterator-tree\":\n" << inc_indent;
  }
}

void JSONIterPrinter::stop() {
  if ( !ignore_start_stop_ )
  {
    os_ << '\n' << dec_indent << dec_indent << indent << "}\n";
  }
}

void JSONIterPrinter::startBeginVisit( char const *name, int ) {
  if ( !theListStack.empty() )
    os_ << ",\n";
  if ( !theListStack.empty() && !theListStack.top() ) {
    os_ << indent << "\"iterators\": [\n" << inc_indent;
    theListStack.pop();
    theListStack.push( true );
  }
  os_ << indent << "{\n" << inc_indent
      << indent << "\"kind\": \"" << zorba::json::serialize(name) << "\"";
  theListStack.push( false );
}

void JSONIterPrinter::endBeginVisit( int ) {
}

void JSONIterPrinter::addBoolAttribute( char const *name, bool value ) {
  os_ << ",\n" << indent << "\"" << zorba::json::serialize(name) << "\": "
      << (value ? "true" : "false");
}

void JSONIterPrinter::addAttribute( char const *name, char const *value ) {
  os_ << ",\n" << indent << "\"" << zorba::json::serialize(name) << "\": \""
      << zorba::json::serialize(value) << "\"";
}

void JSONIterPrinter::addItemAttribute( char const *name, const zorba::Item& value )
{
  if (value.isNull())
    return;

  if (value.isJSONItem())
  {
    Zorba_SerializerOptions_t serOptions;
    serOptions.indent = ZORBA_INDENT_YES;
    Serializer_t serializer = Serializer::createSerializer(serOptions);

    std::stringstream valueSS;
    zorba::SingletonItemSequence lSeq(value);
    serializer->serialize(lSeq.getIterator(), valueSS);

    addRawStructure(name, valueSS.str().c_str());
  }
  else
    IterPrinter::addItemAttribute(name, value);
}


void JSONIterPrinter::addRawStructure( char const *name, char const *value ) {
  os_ << ",\n" << indent << "\"" << zorba::json::serialize(name) << "\":\n";
  os_ << inc_indent << indent;
  while (*value != '\0')
  {
    os_ << *value;
    if (*value == '\n')
      os_ << indent;
    ++value;
  }
  os_ << '\n' << dec_indent;
}

void JSONIterPrinter::addVecAttribute( char const *name, const std::vector<std::string>& values )
{
  os_ << ",\n" << indent << "\"" << zorba::json::serialize(name) << "\": [";
  for (std::vector<std::string>::size_type i = 0; i < values.size(); ++i)
  {
    os_ << "\"" << zorba::json::serialize(values[i]) << "\"";
    if (i < (values.size() -1))
      os_ << ", ";
  }
  os_ << "]";
}

void JSONIterPrinter::addVecAttribute( char const *name, const std::vector<int>& values )
{
  os_ << ",\n" << indent << "\"" << zorba::json::serialize(name) << "\": [";
  for (std::vector<std::string>::size_type i = 0; i < values.size(); ++i)
  {
    os_ << values[i];
    if (i < (values.size() -1))
      os_ << ", ";
  }
  os_ << "]";
}

void JSONIterPrinter::addIntAttribute( char const *name, xs_long value ) {
  os_ << ",\n" << indent << "\"" << zorba::json::serialize(name) << "\": "
      << value;
}

void JSONIterPrinter::addIntAttribute( char const *name, xs_integer value ) {
  os_ << ",\n" << indent << "\"" << zorba::json::serialize(name) << "\": "
      << value;
}

void JSONIterPrinter::addDecAttribute( char const *name, double value ) {
  os_ << ",\n" << indent << "\"" << zorba::json::serialize(name) << "\": "
      << value;
}

void JSONIterPrinter::startEndVisit() {
  if ( theListStack.top() )
    os_ << '\n' << dec_indent << indent << ']';
  os_ << '\n' << dec_indent << indent << '}';
  theListStack.pop();
}

void JSONIterPrinter::endEndVisit() {
}

///////////////////////////////////////////////////////////////////////////////

}; // namespace zorba
/* vim:set et sw=2 ts=2: */
