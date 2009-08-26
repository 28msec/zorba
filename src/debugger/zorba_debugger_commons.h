#ifndef ZORBA_DEBUGGER_COMMONS
#define ZORBA_DEBUGGER_COMMONS

#include <map>
#include <string>

#include "compiler/parser/query_loc.h"

#include "debugger/debugger_common.h"

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
  /**
  * @brief A class used as common shared object between the debugger runtime
  *  and the debug iterators.
  *
  * This class is by the iterators to share information, get commands from
  * the debug runtime and deliver information to the debugger runtime.
  *
  */
  class ZorbaDebuggerCommons {
    friend class TranslatorImpl;
  public: // Creation and destruction
    /**
    * @brief The default constructor.
    *
    * Initializes the internally used variables.
    */
    ZorbaDebuggerCommons();
    virtual ~ZorbaDebuggerCommons();
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
    /**
    * @brief Sets the theBreak variable.
    *
    * @see ZorbaDebuggerCommons::hasToBrak for a description why this is
    *  needed.
    *
    * @pre lBreak implies aCause != 0
    * @post theBreak == lBreak
    * @post theCause == aCause
    */
    void setBreak(bool lBreak, SuspensionCause aCause = 0);

    /**
    * @brief Sets the current iterator which can then be used by the
    *  debugger runtime.
    *
    * @param aIterator A pointer to the current iterator.
    * @post aIterator == theCurrentIterator
    */
    void setCurrentIterator(const ZorbaDebugIterator* aIterator);
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
    * @brief Returns true, if a breakpoint is set to the given location -
    * false otherwise.
    */
    bool hasToBreakAt(const QueryLoc& aLocation) const;
    /**
    * @brief Returns true, if a breakpoint is set to the given debugger
    * iterator - false otherwise.
    *
    * This method is used for step out and step over commands. It also
    * deletes the debugger from the list of step points, as soon, as
    * this function is called.
    *
    * @brief aIter != NULL
    */
    bool hasToBreakAt(const ZorbaDebugIterator* aIter);
    /**
    * @brief This returns true, if the runtime wants to suspend.
    *
    * If the debugger runtime wants to suspend, it sets theBreak to true,
    * which should be checked by every debug iterator on every iteration
    * step. If the variable is set to true, the iterator should suspend
    * the runtime immediately.
    *
    * There can be several reasons for the runtime for setting theBreak
    * to true. It could be a step in command from the user (where this
    * mechanism is used for convenience) or an interrupt from the user.
    *
    * @retval aCause sets aCause to the cause, why the debugger runtime
    *  has to suspend.
    * @return true, if the runtime wants the debugger to suspend.
    * @pre *aCause == 0
    * @post *aCause == theCause
    * @post Result == theBreak
    */
    bool hasToBrak(SuspensionCause* aCause) const;

    /**
    * @brief Gets the current debugger iterator.
    */
    const ZorbaDebugIterator* getCurrentIterator();

    /**
    * @brief Sets a setpoint according to the step out rules.
    *
    * This method sets a breakpoint according to the rules according to
    * the step out rules.
    *
    * @pre theCurrentIterator != NULL
    */
    void makeStepOut();

    /**
    * @ brief Sets a setpoint according to the step over rules.
    *
    * @pre theCurrentIterator != NULL
    */
    void makeStepOver();
  private:
    std::map<DebugLocation_t, bool, DebugLocation> theLocationMap;
    ZorbaDebuggerRuntime*                          theRuntime;
    static_context*                                theCurrentStaticContext;
    dynamic_context*                               theCurrentDynamicContext;
    bool                                           theBreak;
    SuspensionCause                                theCause;
    const ZorbaDebugIterator*                      theCurrentIterator;
    /**
    * @brief The list of step expressions.
    */
    std::list<const ZorbaDebugIterator*>           theBreakIterators;
  };
}

#endif // ZORBA_DEBUGGER_COMMONS
