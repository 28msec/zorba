#include <cassert>

#include "runtime/visitors/iterprinter.h"

namespace xqp {

XMLIterPrinter::XMLIterPrinter(std::ostream& aOStream) : theOStream(aOStream), theOpenStart(false) {}
  
void XMLIterPrinter::startIter(const std::string& aName) {
  if (theOpenStart)
    theOStream << ">\n";
  printSpaces(theNameStack.size());
  theOStream << "<" << aName;
  theNameStack.push(aName);
  theOpenStart = true;
}


void XMLIterPrinter::addAttribute(const std::string& aName, const std::string& aValue)
{
  assert(theOpenStart);
  theOStream << " " << aName << "=\"" << aValue << "\"";
}

void XMLIterPrinter::addAttribute(const std::string& aName, bool aValue)
{
  assert(theOpenStart);
  theOStream << " " << aName << "=\"" << (aValue ? "true" : "false") << "\"";
}


void XMLIterPrinter::endIter() {
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
  
void XMLIterPrinter::printSpaces(size_t aNr) {
  for (unsigned int i = 0; i < aNr; i++)
    theOStream << "  ";
}

}; /* namespace xqp */
