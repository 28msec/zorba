#ifndef XQP_VISITORPRINTER_H
#define XQP_VISITORPRINTER_H

#include <string>
#include <ostream>
#include <stack>

namespace yy {
  class location;
}

namespace xqp {
  /**
   * Interface to print the PlanIterators.
   */
  class IterPrinter {
    public:
      virtual ~IterPrinter(){}
      virtual void startIter(const std::string& aName) = 0;
      virtual void addAttribute(const std::string& aName, const std::string& aValue) = 0;
      virtual void endIter() = 0;
  }; /* class VisitorPrinter */
  
  /**
   * Implementation of IterPrinter to print a PlanIterator tree in XML format
   */
  class XMLIterPrinter : public IterPrinter {
    private:
      std::ostream& theOStream;
      bool theOpenStart;
      std::stack<std::string> theNameStack;
      
    public:
      XMLIterPrinter(std::ostream& aOStream);
      virtual ~XMLIterPrinter(){}
      virtual void startIter(const std::string& aName);
      virtual void addAttribute(const std::string& aName, const std::string& aValue);
      virtual void endIter();
      
    private:
      void printSpaces(size_t aNr);
  }; /* class XMLVisitorPrinter */
} /* namespace xqp */

#endif
