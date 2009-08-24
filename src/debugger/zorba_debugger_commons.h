#ifndef ZORBA_DEBUGGER_COMMONS
#define ZORBA_DEBUGGER_COMMONS

#include <map>
#include <string>

#include "compiler/parser/query_loc.h"

namespace zorba {
  class dynamic_context;
  class static_context;
  class ZorbaDebuggerRuntime;
  class ZorbaDebugIterator;
  class TranslatorImpl;
  struct DebugLocation;
  typedef struct DebugLocation DebugLocation_t;
  struct DebugLocation {
    std::string theFileName;
    unsigned long theLineNumber;
    QueryLoc theQueryLocation;
    bool operator()(const DebugLocation_t& aLocation1, const DebugLocation_t& aLocation2) const;
  };
  class ZorbaDebuggerCommons {
    friend class TranslatorImpl;
  public: // Commands
    //************************************
    // Method:    setRuntime
    // FullName:  zorba::ZorbaDebuggerCommons::setRuntime
    // Access:    public 
    // Returns:   void
    // Qualifier:
    // Parameter: ZorbaDebuggerRuntime * aRuntime
    //************************************
    void setRuntime(ZorbaDebuggerRuntime* aRuntime);
    //************************************
    // Method:    setCurrentDynamicContext
    // FullName:  zorba::ZorbaDebuggerCommons::setCurrentDynamicContext
    // Access:    public 
    // Returns:   void
    // Qualifier:
    // Parameter: dynamic_context * aDynamicContext
    //************************************
    void setCurrentDynamicContext(dynamic_context* aDynamicContext);
    void setCurrentStaticContext(static_context* aStaticContext);
  public: //Queries
    /**
    * Adds a breakpoint and then sets theLocation from aLocation
    * to the QueryLoc object, where it has to break.
    * @return true, if a breakable expression was found - false otherwise
    */
    bool addBreakpoint(DebugLocation_t& aLocation);
    //************************************
    // Method:    getRuntime
    // FullName:  zorba::ZorbaDebuggerCommons::getRuntime
    // Access:    public 
    // Returns:   ZorbaDebuggerRuntime*
    // Qualifier:
    //************************************
    ZorbaDebuggerRuntime* getRuntime();
    //************************************
    // Method:    getCurrentDynamicContext
    // FullName:  zorba::ZorbaDebuggerCommons::getCurrentDynamicContext
    // Access:    public 
    // Returns:   dynamic_context*
    // Qualifier: const
    //************************************
    dynamic_context* getCurrentDynamicContext() const;
    //************************************
    // Method:    getCurrentStaticContext
    // FullName:  zorba::ZorbaDebuggerCommons::getCurrentStaticContext
    // Access:    public 
    // Returns:   static_context*
    // Qualifier: const
    //************************************
    static_context* getCurrentStaticContext() const;
    /**
    * Returns true, if a breakpoint is set to the given location - false 
    * otherwise.
    */
    bool hasToBreakAt(const QueryLoc& aLocation) const;
  private:
    std::map<DebugLocation_t, bool, DebugLocation> theLocationMap;
    ZorbaDebuggerRuntime*                          theRuntime;
    static_context*                                theCurrentStaticContext;
    dynamic_context*                               theCurrentDynamicContext;
  };
}

#endif // ZORBA_DEBUGGER_COMMONS
