#ifndef ZORBA_DEBUGGER_COMMONS
#define ZORBA_DEBUGGER_COMMONS

#include <map>
#include <string>

namespace zorba {
  class ZorbaDebuggerRuntime;
  class ZorbaDebugIterator;
  struct DebugLocation;
  typedef struct DebugLocation DebugLocation_t;
  struct DebugLocation {
    std::string theFileName;
    unsigned long theLineNumber;
    bool operator()(const DebugLocation_t& aLocation1, const DebugLocation_t& aLocation2) const;
  };
  class ZorbaDebuggerCommons {
  public: // Commands
    //************************************
    // Method:    addDebugLocation
    // FullName:  zorba::ZorbaDebuggerCommons::addDebugLocation
    // Access:    public 
    // Returns:   void
    // Qualifier: Inserts a breakable location into the map of debug
    //            iterators
    // Parameter: DebugLocation_t aLocation
    // Parameter: ZorbaDebugIterator * anIterator
    //************************************
    void addDebugLocation(const DebugLocation_t& aLocation, ZorbaDebugIterator* anIterator);
    //************************************
    // Method:    setRuntime
    // FullName:  zorba::ZorbaDebuggerCommons::setRuntime
    // Access:    public 
    // Returns:   void
    // Qualifier:
    // Parameter: ZorbaDebuggerRuntime * aRuntime
    //************************************
    void setRuntime(ZorbaDebuggerRuntime* aRuntime);
  public: //Queries
    //************************************
    // Method:    findDebugIterator
    // FullName:  zorba::ZorbaDebuggerCommons::findDebugIterator
    // Access:    public 
    // Returns:   ZorbaDebugIterator*
    // Qualifier: const
    // Parameter: const DebugLocation_t & aLocation
    //************************************
    ZorbaDebugIterator* findDebugIterator(const DebugLocation_t& aLocation) const;
    //************************************
    // Method:    getRuntime
    // FullName:  zorba::ZorbaDebuggerCommons::getRuntime
    // Access:    public 
    // Returns:   ZorbaDebuggerRuntime*
    // Qualifier:
    //************************************
    ZorbaDebuggerRuntime* getRuntime();
  private:
    std::map<DebugLocation_t, ZorbaDebugIterator*, DebugLocation> theLocationMap;
    ZorbaDebuggerRuntime*                                         theRuntime;
  };
}

#endif // ZORBA_DEBUGGER_COMMONS
