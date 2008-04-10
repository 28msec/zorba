#ifndef ZORBA_VISITORPRINTER_H
#define ZORBA_VISITORPRINTER_H

#include <string>
#include <ostream>
#include <stack>

#include "common/common.h"

namespace yy {
  class location;
}

namespace zorba {
  /**
   * Interface to print the PlanIterators.
   */
  class IterPrinter {
    public:
      IterPrinter(std::ostream& aOStream)
        : theOStream(aOStream) {}

      virtual ~IterPrinter() {}

      virtual void start() = 0;
      virtual void stop() = 0;

      virtual void startBeginVisit(const std::string& aName, int aAddr) = 0;
      virtual void endBeginVisit(int aAddr) = 0;

      virtual void addAttribute(const std::string& aName, const std::string& aValue) = 0;

      virtual void startEndVisit() = 0;
      virtual void endEndVisit() = 0;

    protected:  
      std::ostream& theOStream;
      void printSpaces(size_t aNr) { theOStream << std::string(aNr, ' '); }
  }; /* class VisitorPrinter */
  
  /**
   * Implementation of IterPrinter to print a PlanIterator tree in XML format
   */
  class XMLIterPrinter : public IterPrinter {
    private:
      bool theOpenStart;
      std::stack<std::string> theNameStack;
      
    public:
      XMLIterPrinter(std::ostream& aOStream);
      virtual ~XMLIterPrinter(){}

      virtual void start();
      virtual void stop();

      virtual void startBeginVisit(const std::string& aName, int aAddr);
      virtual void endBeginVisit(int aAddr);

      virtual void addAttribute(const std::string& aName, const std::string& aValue);

      virtual void startEndVisit();
      virtual void endEndVisit();
  }; /* class XMLVisitorPrinter */

  /**
   * Implementation of IterPrinter to print a PlanIterator tree in XML format
   */
  class DOTIterPrinter : public IterPrinter {
    private:
      std::stack<int> theNameStack;
      uint32_t theIndent;
      
    public:
      DOTIterPrinter(std::ostream& aOStream);
      virtual ~DOTIterPrinter(){}
      
      virtual void start();
      virtual void stop();

      virtual void startBeginVisit(const std::string& aName, int aAddr);
      virtual void endBeginVisit(int aAddr);

      virtual void addAttribute(const std::string& aName, const std::string& aValue);

      virtual void startEndVisit();
      virtual void endEndVisit();
  
  }; /* class XMLVisitorPrinter */
} /* namespace zorba */

#endif
