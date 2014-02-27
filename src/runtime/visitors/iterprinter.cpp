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
#include "util/indent.h"
#include "util/xml_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

IterPrinter::IterPrinter( ostream &os, char const *descr ) :
  os_( os ), descr_( descr )
{
}

IterPrinter::~IterPrinter() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

XMLIterPrinter::XMLIterPrinter( ostream &os, char const *descr ) :
  IterPrinter( os, descr ),
  theOpenStart( false )
{
}

XMLIterPrinter::~XMLIterPrinter() {
  // out-of-line since it's virtual
}

void XMLIterPrinter::start() {
  os_ << indent << "<iterator-tree";
  if ( !descr_.empty() )
    os_ << " description=\"" << descr_ << '"';
  os_ << ">\n" << inc_indent;
}

void XMLIterPrinter::stop() {
  os_ << dec_indent << indent << "</iterator-tree>\n";
}

void XMLIterPrinter::startBeginVisit( char const *name, int ) {
  if ( theOpenStart )
    os_ << ">\n";
  os_ << indent << '<' << name << inc_indent;
  theNameStack.push( name );
  theOpenStart = true;
}

void XMLIterPrinter::endBeginVisit( int ) {
}

void XMLIterPrinter::addAttribute( char const *name, char const *value ) {
  assert( theOpenStart );
  os_ << ' ' << name << "=\"" << value << "\"";
}

void XMLIterPrinter::addAttribute( char const *name, xs_long value ) {
  assert( theOpenStart );
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

DOTIterPrinter::DOTIterPrinter( ostream &os, char const *descr ) :
  IterPrinter( os, descr )
{
}

DOTIterPrinter::~DOTIterPrinter() {
  // out-of-line since it's virtual
}

void DOTIterPrinter::start() {
  os_ << indent << "digraph {\n" << inc_indent
      << indent << "node [ color=gray, fontname=\"Arial\" ]\n";
}

void DOTIterPrinter::stop() {
  os_ << dec_indent << indent << "}\n";
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

void DOTIterPrinter::addAttribute( char const *name, char const *value ) {
  string temp( value );
  ascii::replace_all( temp, "\"", "\\\"" );
  ascii::replace_all( temp, "\n", " \\n " );
  os_ << "\\n" << name << '=' << temp;
}

void DOTIterPrinter::addAttribute( char const *name, xs_long value ) {
  os_ << indent << "\\n" << name << '=' << value;
}

void DOTIterPrinter::startEndVisit() {
}

void DOTIterPrinter::endEndVisit() {
  theNameStack.pop();
}

///////////////////////////////////////////////////////////////////////////////

JSONIterPrinter::JSONIterPrinter( ostream &os, char const *descr ) :
  IterPrinter( os, descr )
{
}

JSONIterPrinter::~JSONIterPrinter() {
  // out-of-line since it's virtual
}

void JSONIterPrinter::start() {
  os_ << indent << "{\n" << inc_indent;
  if ( !descr_.empty() )
    os_ << indent << "\"description\": \"" << descr_ << "\",\n";
  os_ << indent << "\"iterator-tree\":\n" << inc_indent;
}

void JSONIterPrinter::stop() {
  os_ << '\n' << dec_indent << dec_indent << indent << "}\n";
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
      << indent << "\"kind\": \"" << name << "\"";
  theListStack.push( false );
}

void JSONIterPrinter::endBeginVisit( int ) {
}

void JSONIterPrinter::addAttribute( char const *name, char const *value ) {
  os_ << ",\n" << indent << "\"" << name << "\": \"" << value << "\"";
}

void JSONIterPrinter::addAttribute( char const *name, xs_long value ) {
  os_ << ",\n" << indent << "\"" << name << "\": " << value;
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
