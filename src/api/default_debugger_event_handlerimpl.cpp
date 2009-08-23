#include <zorba/debugger_default_event_handler.h>

zorba::DefaultDebuggerEventHandler::~DefaultDebuggerEventHandler()
{
}

void zorba::DefaultDebuggerEventHandler::started()
{
}

void zorba::DefaultDebuggerEventHandler::idle()
{
}

void zorba::DefaultDebuggerEventHandler::resumed()
{
}

void zorba::DefaultDebuggerEventHandler::terminated()
{
}

void zorba::DefaultDebuggerEventHandler::suspended(
  zorba::QueryLocation & aLocation,
  zorba::SuspendedBy aCause)
{
}

void zorba::DefaultDebuggerEventHandler::evaluated(
  zorba::String &anExpr, 
  std::list<std::pair<String,String> > &aValuesAndTypes)
{
}

void zorba::DefaultDebuggerEventHandler::evaluated(zorba::String &anExpr, 
                                                   zorba::String &anError)
{
}
