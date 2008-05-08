#include <zorba/debugger_server.hpp>

#include "debugger/debugger_serverimpl.hpp"

namespace zorba {

  ZorbaDebugger *
  ZorbaDebugger::getInstance()
  {
    static ZorbaDebuggerImpl lInstance;
    return &lInstance;
  }

  ZorbaDebugger::~ZorbaDebugger(){}
}
