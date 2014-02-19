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

XMLIterPrinter::XMLIterPrinter(ostream& aOStream) :
  IterPrinter(aOStream),
  theOpenStart(false)
{
}

void XMLIterPrinter::start() {
}

void XMLIterPrinter::stop() {
}

void XMLIterPrinter::startBeginVisit(string const &aName, int) {
  if (theOpenStart)
    theOStream << ">\n";
  printSpaces(2 * theNameStack.size());
  theOStream << '<' << aName;
  theNameStack.push(aName);
  theOpenStart = true;
}

void XMLIterPrinter::endBeginVisit(int) {
}

void XMLIterPrinter::addAttribute(string const &aName, string const &aValue) {
  assert(theOpenStart);
  string temp( aValue );
  xml::escape( temp );
  theOStream << ' ' << aName << "=\"" << temp << "\"";
}

void XMLIterPrinter::addAttribute(string const &aName, xs_long aValue) {
  assert(theOpenStart);
  theOStream << ' ' << aName << "=\"" << aValue << "\"";
}

void XMLIterPrinter::startEndVisit() {
  assert(!theNameStack.empty());
  if (theOpenStart)
    theOStream << "/>" << endl;
  else {
    printSpaces(2 * (theNameStack.size() - 1));
    theOStream << "</" << theNameStack.top() << '>' << endl;
  }
  theNameStack.pop();
  theOpenStart = false;
}

void XMLIterPrinter::endEndVisit() {
}

///////////////////////////////////////////////////////////////////////////////

DOTIterPrinter::DOTIterPrinter(ostream& aOStream) :
  IterPrinter(aOStream),
  theIndent(0)
{
}

void DOTIterPrinter::start() {
  theOStream << "digraph {" << endl;
  theOStream << "node [ color=gray, fontname=\"Arial\" ]" << endl;
}

void DOTIterPrinter::stop() {
  theOStream << '}' << endl;
}

void DOTIterPrinter::startBeginVisit(string const &aName, int aAddr) {
  printSpaces(theIndent);
  theOStream << aAddr << " [ label=\"" << aName;
  ++theIndent;
}

void DOTIterPrinter::endBeginVisit(int aAddr) {
  --theIndent;
  printSpaces(theIndent);
  theOStream << "\"];" << endl;
  printSpaces(theIndent);
  if (!theNameStack.empty() && theNameStack.top() != aAddr)
    theOStream << theNameStack.top() << "->" << aAddr << endl;
  theNameStack.push(aAddr);
}

void DOTIterPrinter::addAttribute(string const &aName, string const &aValue) {
  printSpaces(theIndent);
  string mvalue( aValue );
  ascii::replace_all(mvalue, "\"", "\\\"");
  ascii::replace_all(mvalue, "\n", " \\n ");
  theOStream << "\\n" << aName << '=' << mvalue;
}

void DOTIterPrinter::addAttribute(string const &aName, xs_long aValue) {
  printSpaces(theIndent);
  theOStream << "\\n" << aName << '=' << aValue;
}

void DOTIterPrinter::startEndVisit() {
}

void DOTIterPrinter::endEndVisit() {
  theNameStack.pop();
}

///////////////////////////////////////////////////////////////////////////////

JSONIterPrinter::JSONIterPrinter(ostream& aOStream) :
  IterPrinter(aOStream), theIndent(0)
{
}

void JSONIterPrinter::start() {
}

void JSONIterPrinter::stop() {
  theOStream << endl;
}

void JSONIterPrinter::startBeginVisit(const string& aName, int) {
  if (!theListStack.empty())
    theOStream << ',' << endl;

  if (!theListStack.empty() && !theListStack.top()) {
    printSpaces(2 * theIndent);
    theOStream << "\"iterators\":" << endl;
    printSpaces(2 * theIndent);
    theOStream << '[';
    theListStack.pop();
    theListStack.push(true);
    theIndent++;
    theOStream << endl;
  }

  printSpaces(2 * theIndent);
  theOStream << "{" << endl;
  printSpaces(2 * (1+theIndent));
  theOStream << "\"kind\": \"" << aName << "\"";
  theIndent++;
  theListStack.push(false);
}

void JSONIterPrinter::endBeginVisit(int) {
}

void JSONIterPrinter::addAttribute(const string& aName, const string& aValue) {
  theOStream << ',' << endl;
  printSpaces(2 * theIndent);
  theOStream << "\"" << aName << "\": \"" << aValue << "\"";
}

void JSONIterPrinter::addAttribute(const string& aName, xs_long aValue) {
  theOStream << ',' << endl;
  printSpaces(2 * theIndent);
  theOStream << "\"" << aName << "\": " << aValue;
}

void JSONIterPrinter::startEndVisit() {
  if (theListStack.top()) {
    theOStream << endl;
    printSpaces(2 * (theIndent - 1));
    theOStream << ']';
    theIndent--;
  }

  theOStream << endl;
  printSpaces(2 * (theIndent - 1));
  theOStream << '}';
  theIndent--;
  theListStack.pop();
}

void JSONIterPrinter::endEndVisit() {
}

///////////////////////////////////////////////////////////////////////////////

}; // namespace zorba
/* vim:set et sw=2 ts=2: */
