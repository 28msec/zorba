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

IterPrinter::~IterPrinter() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

XMLIterPrinter::XMLIterPrinter( ostream &os ) :
  IterPrinter( os ),
  theOpenStart( false )
{
}

XMLIterPrinter::~XMLIterPrinter() {
  // out-of-line since it's virtual
}

void XMLIterPrinter::start() {
}

void XMLIterPrinter::stop() {
}

void XMLIterPrinter::startBeginVisit( string const &name, int ) {
  if ( theOpenStart )
    os_ << ">\n";
  os_ << indent << '<' << name << inc_indent;
  theNameStack.push( name );
  theOpenStart = true;
}

void XMLIterPrinter::endBeginVisit( int ) {
}

void XMLIterPrinter::addAttribute( string const &name, string const &value) {
  assert( theOpenStart );
  os_ << ' ' << name << "=\"" << value << "\"";
}

void XMLIterPrinter::addAttribute( string const &name, xs_long value) {
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

DOTIterPrinter::DOTIterPrinter( ostream &os ) : IterPrinter( os ) {
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

void DOTIterPrinter::startBeginVisit( string const &name, int addr ) {
  os_ << indent << addr << " [ label=\"" << name;
}

void DOTIterPrinter::endBeginVisit( int addr ) {
  os_ << "\" ];\n";
  if ( !theNameStack.empty() && theNameStack.top() != addr )
    os_ << indent << theNameStack.top() << " -> " << addr << endl;
  theNameStack.push( addr );
}

void DOTIterPrinter::addAttribute( string const &name, string const &value) {
  string temp( value );
  ascii::replace_all( temp, "\"", "\\\"" );
  ascii::replace_all( temp, "\n", " \\n " );
  os_ << "\\n" << name << '=' << temp;
}

void DOTIterPrinter::addAttribute( string const &name, xs_long value) {
  os_ << indent << "\\n" << name << '=' << value;
}

void DOTIterPrinter::startEndVisit() {
}

void DOTIterPrinter::endEndVisit() {
  theNameStack.pop();
}

///////////////////////////////////////////////////////////////////////////////

JSONIterPrinter::JSONIterPrinter( ostream &os ) : IterPrinter( os ) {
}

JSONIterPrinter::~JSONIterPrinter() {
  // out-of-line since it's virtual
}

void JSONIterPrinter::start() {
}

void JSONIterPrinter::stop() {
  os_ << endl;
}

void JSONIterPrinter::startBeginVisit( string const &name, int ) {
  if ( !theListStack.empty() )
    os_ << ',' << endl;
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

void JSONIterPrinter::addAttribute( string const &name, string const &value ) {
  os_ << ",\n" << indent << "\"" << name << "\": \"" << value << "\"";
}

void JSONIterPrinter::addAttribute( string const &name, xs_long value ) {
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
