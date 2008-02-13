#include <cassert>
#include <iostream>

#include "runtime/visitors/iterprinter.h"

namespace xqp {

/**
 * Iterator printer for xml
 */
XMLIterPrinter::XMLIterPrinter(std::ostream& aOStream) : IterPrinter(aOStream), theOpenStart(false) {}

void
XMLIterPrinter::start() {}
void
XMLIterPrinter::stop() {}
  
void XMLIterPrinter::startBeginVisit(const std::string& aName, intptr_t) {
  if (theOpenStart)
    theOStream << ">\n";
  printSpaces(theNameStack.size());
  theOStream << "<" << aName;
  theNameStack.push(aName);
  theOpenStart = true;
}

void XMLIterPrinter::endBeginVisit(intptr_t) {}

void XMLIterPrinter::addAttribute(const std::string& aName, const std::string& aValue)
{
  assert(theOpenStart);
  theOStream << " " << aName << "=\"" << aValue << "\"";
}


void XMLIterPrinter::startEndVisit() {
  assert(!theNameStack.empty());
  if (theOpenStart)
    theOStream << "/>" << std::endl;
  else {
    printSpaces(theNameStack.size() - 1);
    theOStream << "</" << theNameStack.top() << ">" << std::endl;
  }
  theNameStack.pop();
  theOpenStart = false;
}

void XMLIterPrinter::endEndVisit() {}
  

/**
 * Iterator printer for dot
 */
DOTIterPrinter::DOTIterPrinter(std::ostream& aOStream) 
  : IterPrinter(aOStream),
    theIndent(0)
{
}

void
DOTIterPrinter::start() 
{
  theOStream << "digraph {" << std::endl;
}

void
DOTIterPrinter::stop() 
{
  theOStream << "}" << std::endl;
}
  
void DOTIterPrinter::startBeginVisit(const std::string& aName, intptr_t aAddr) 
{
  printSpaces(theIndent);
  theOStream << aAddr << " [ label=\"" << aName;
  ++theIndent;
}

void DOTIterPrinter::endBeginVisit(intptr_t aAddr) 
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
  theOStream << "\\n" << aName << "=" << aValue;
}

void DOTIterPrinter::startEndVisit() {
}

void DOTIterPrinter::endEndVisit() 
{
  theNameStack.pop();
}
  
  
}; /* namespace xqp */
