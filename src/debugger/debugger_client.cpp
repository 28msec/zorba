#include "common/common.h"

#ifdef ZORBA_DEBUGGER

#include <zorba/debugger_client.hpp>

#include "debugger/debugger_clientimpl.hpp"

namespace zorba{

ZorbaDebuggerClient * ZorbaDebuggerClient::createClient( unsigned short aRequestPortno, unsigned short aEventPortno )
{
  return new ZorbaDebuggerClientImpl( aRequestPortno, aEventPortno );
}

}//end of namespace

#endif