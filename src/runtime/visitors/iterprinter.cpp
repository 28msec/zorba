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
    {
      zstring escDescription;
      zorba::xml::escape(descr_, &escDescription);
      os_ << " description=\"" << escDescription << '"';
    }
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
  zstring escValue;
  zorba::xml::escape(zstring(value), &escValue);
  os_ << ' ' << name << "=\"" << escValue << "\"";
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
  os_ << dec_indent;

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

void JSONIterPrinter::addRawStructure( char const *name, char const *value ) {
  os_ << ",\n" << indent << "\"" << zorba::json::serialize(name) << "\": [\n";
  os_ << inc_indent << indent;
  while (*value != '\0')
  {
    os_ << *value;
    if (*value == '\n')
      os_ << indent;
    ++value;
  }
  os_ << '\n' << dec_indent << indent << ']';
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
