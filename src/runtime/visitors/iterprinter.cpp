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

#include <iostream>

#include "runtime/visitors/iterprinter.h"
#include "util/ascii_util.h"

namespace zorba {

/**
 * Iterator printer for xml
 */
XMLIterPrinter::XMLIterPrinter(std::ostream& aOStream) : IterPrinter(aOStream), theOpenStart(false) {}


void XMLIterPrinter::start() 
{
}


void XMLIterPrinter::stop() 
{
}

  
void XMLIterPrinter::startBeginVisit(const std::string& aName, int) 
{
  if (theOpenStart)
    theOStream << ">\n";

  printSpaces(2 * theNameStack.size());
  theOStream << "<" << aName;
  theNameStack.push(aName);
  theOpenStart = true;
}


void XMLIterPrinter::endBeginVisit(int) 
{
}


void XMLIterPrinter::addAttribute(const std::string& aName, const std::string& aValue)
{
  assert(theOpenStart);
  theOStream << " " << aName << "=\"" << aValue << "\"";
}


void XMLIterPrinter::addAttribute(const std::string& aName, xs_long aValue)
{
  assert(theOpenStart);
  theOStream << " " << aName << "=\"" << aValue << "\"";
}


void XMLIterPrinter::startEndVisit() 
{
  assert(!theNameStack.empty());
  if (theOpenStart)
    theOStream << "/>" << std::endl;
  else 
  {
    printSpaces(2 * (theNameStack.size() - 1));
    theOStream << "</" << theNameStack.top() << ">" << std::endl;
  }
  theNameStack.pop();
  theOpenStart = false;
}


void XMLIterPrinter::endEndVisit() 
{
}
  

/**
 * Iterator printer for dot
 */
DOTIterPrinter::DOTIterPrinter(std::ostream& aOStream) 
  : IterPrinter(aOStream),
    theIndent(0)
{
}

void DOTIterPrinter::start() 
{
  theOStream << "digraph {" << std::endl;
  theOStream << "node [ color=gray, fontname=\"Arial\" ]" << std::endl;
}

void DOTIterPrinter::stop() 
{
  theOStream << "}" << std::endl;
}
  

void DOTIterPrinter::startBeginVisit(const std::string& aName, int aAddr) 
{
  printSpaces(theIndent);
  theOStream << aAddr << " [ label=\"" << aName;
  ++theIndent;
}


void DOTIterPrinter::endBeginVisit(int aAddr) 
{
  --theIndent;
  printSpaces(theIndent);
  theOStream << "\"];" << std::endl;
  printSpaces(theIndent);
  if (!theNameStack.empty() && theNameStack.top() != aAddr)
    theOStream << theNameStack.top() << "->" << aAddr << std::endl;
  theNameStack.push(aAddr);
}


void DOTIterPrinter::addAttribute(const std::string& aName, const std::string& aValue)
{
  printSpaces(theIndent);

  std::string mvalue = aValue;

  if(aValue.find('"') != std::string::npos)
    ascii::replace_all(mvalue, "\"", "\\\"");

  if(aValue.find("\n") != std::string::npos)
    ascii::replace_all(mvalue, "\n", " \\n ");

  theOStream << "\\n" << aName << "=" << mvalue;
}

void DOTIterPrinter::addAttribute(const std::string& aName, xs_long aValue)
{
  printSpaces(theIndent);
  theOStream << "\\n" << aName << "=" << aValue;
}


void DOTIterPrinter::startEndVisit() 
{
}


void DOTIterPrinter::endEndVisit() 
{
  theNameStack.pop();
}
  
  
}; /* namespace zorba */
/* vim:set et sw=2 ts=2: */
