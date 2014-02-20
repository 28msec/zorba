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
#include "util/xml_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

IterPrinter::~IterPrinter() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

XMLIterPrinter::XMLIterPrinter( ostream &os ) :
  IterPrinter(os),
  theOpenStart(false)
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
  if (theOpenStart)
    os_ << ">\n";
  printSpaces(2 * theNameStack.size());
  os_ << '<' << name;
  theNameStack.push(name);
  theOpenStart = true;
}

void XMLIterPrinter::endBeginVisit( int ) {
}

void XMLIterPrinter::addAttribute( string const &name, string const &value) {
  assert(theOpenStart);
  os_ << ' ' << name << "=\"" << value << "\"";
}

void XMLIterPrinter::addAttribute( string const &name, xs_long value) {
  assert(theOpenStart);
  os_ << ' ' << name << "=\"" << value << "\"";
}

void XMLIterPrinter::startEndVisit() {
  assert(!theNameStack.empty());
  if (theOpenStart)
    os_ << "/>" << endl;
  else {
    printSpaces(2 * (theNameStack.size() - 1));
    os_ << "</" << theNameStack.top() << '>' << endl;
  }
  theNameStack.pop();
  theOpenStart = false;
}

void XMLIterPrinter::endEndVisit() {
}

///////////////////////////////////////////////////////////////////////////////

DOTIterPrinter::DOTIterPrinter( ostream &os ) :
  IterPrinter(os),
  theIndent(0)
{
}

DOTIterPrinter::~DOTIterPrinter() {
  // out-of-line since it's virtual
}

void DOTIterPrinter::start() {
  os_ << "digraph {" << endl;
  os_ << "node [ color=gray, fontname=\"Arial\" ]" << endl;
}

void DOTIterPrinter::stop() {
  os_ << '}' << endl;
}

void DOTIterPrinter::startBeginVisit( string const &name, int addr ) {
  printSpaces(theIndent);
  os_ << addr << " [ label=\"" << name;
  ++theIndent;
}

void DOTIterPrinter::endBeginVisit( int addr ) {
  --theIndent;
  printSpaces(theIndent);
  os_ << "\"];" << endl;
  printSpaces(theIndent);
  if ( !theNameStack.empty() && theNameStack.top() != addr )
    os_ << theNameStack.top() << "->" << addr << endl;
  theNameStack.push(addr);
}

void DOTIterPrinter::addAttribute( string const &name, string const &value) {
  printSpaces(theIndent);
  string temp( value );
  ascii::replace_all( temp, "\"", "\\\"" );
  ascii::replace_all( temp, "\n", " \\n " );
  os_ << "\\n" << name << '=' << temp;
}

void DOTIterPrinter::addAttribute( string const &name, xs_long value) {
  printSpaces(theIndent);
  os_ << "\\n" << name << '=' << value;
}

void DOTIterPrinter::startEndVisit() {
}

void DOTIterPrinter::endEndVisit() {
  theNameStack.pop();
}

///////////////////////////////////////////////////////////////////////////////

JSONIterPrinter::JSONIterPrinter( ostream &os ) :
  IterPrinter( os ), theIndent( 0 )
{
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
  if (!theListStack.empty())
    os_ << ',' << endl;

  if (!theListStack.empty() && !theListStack.top()) {
    printSpaces(2 * theIndent);
    os_ << "\"iterators\":" << endl;
    printSpaces(2 * theIndent);
    os_ << '[';
    theListStack.pop();
    theListStack.push(true);
    theIndent++;
    os_ << endl;
  }

  printSpaces(2 * theIndent);
  os_ << '{' << endl;
  printSpaces(2 * ++theIndent);
  os_ << "\"kind\": \"" << name << "\"";
  theListStack.push(false);
}

void JSONIterPrinter::endBeginVisit( int ) {
}

void JSONIterPrinter::addAttribute( string const &name, string const& aValue) {
  os_ << ',' << endl;
  printSpaces(2 * theIndent);
  os_ << "\"" << name << "\": \"" << aValue << "\"";
}

void JSONIterPrinter::addAttribute( string const &name, xs_long aValue) {
  os_ << ',' << endl;
  printSpaces(2 * theIndent);
  os_ << "\"" << name << "\": " << aValue;
}

void JSONIterPrinter::startEndVisit() {
  if (theListStack.top()) {
    os_ << endl;
    printSpaces(2 * (theIndent - 1));
    os_ << ']';
    theIndent--;
  }

  os_ << endl;
  printSpaces(2 * (theIndent - 1));
  os_ << '}';
  theIndent--;
  theListStack.pop();
}

void JSONIterPrinter::endEndVisit() {
}

///////////////////////////////////////////////////////////////////////////////

}; // namespace zorba
/* vim:set et sw=2 ts=2: */
