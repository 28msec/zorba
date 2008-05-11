#ifndef XQP_ZORBA_DEBUGGER_H
#define XQP_ZORBA_DEBUGGER_H

#include <iostream>

#include <zorba/zorba.h>

namespace zorba{

/**
 * @
 */

class ZorbaDebugger
{

  public:

    static ZorbaDebugger *
    getInstance();

    virtual ~ZorbaDebugger();
    
    virtual void
    start( std::istream * aQuery,
            const String & aFileName,
            unsigned short aRequestPort = 8000,
            unsigned short aEventPort = 9000 ) = 0;

    virtual bool
    isEnabled() const = 0;
};
}//end of namespace xqp

#endif
