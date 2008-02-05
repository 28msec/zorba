
#include "errors/error_messages.h"
#include "error_manager.h"
#include "system/zorba.h"
#include "errors/errors.h"
#include "api/external/xquery.h"

using namespace std;
namespace xqp {

static bool g_throw_exceptions = false;

ZorbaAlertsManager::~ZorbaAlertsManager()
{
}


AlertsManagerImpl::AlertsManagerImpl( )
{
	thread_registered_callback = NULL;
	thread_registered_param = NULL;
	theIsFromUser = true;
//	theAlertMessages = NULL;
  AlertMessagesEnglish* codes = new AlertMessagesEnglish;
	setAlertMessages(codes, false);
	is_error = false;
}


AlertsManagerImpl::~AlertsManagerImpl()
{
	clearAlertList();

  if (!theIsFromUser && theAlertMessages != NULL)
    delete theAlertMessages;
}


void AlertsManagerImpl::clearAlertList()
{
	std::list<ZorbaAlert*>::const_iterator errit;
	
	for(errit = begin(); errit != end(); errit++)
		delete *errit;

	clear();
	is_error = false;
}


/*
	Register the callback for the thread specific error manager
*/
void AlertsManagerImpl::registerAlertCallback(
    alert_callback* user_alert_callback,
    void* param)
{
	thread_registered_callback = user_alert_callback;
	thread_registered_param = param;
}


AlertMessages& AlertsManagerImpl::getAlertMessages()
{
	return *theAlertMessages;
}


void AlertsManagerImpl::setAlertMessages(AlertMessages* c, bool is_from_user)
{
	if(!theIsFromUser)
		delete theAlertMessages;
	theAlertMessages = c;
	theIsFromUser = is_from_user;
}


int AlertsManagerImpl::sendAlertToUser(Zorba* z, ZorbaAlert* alert)
{
	int		retval;

	if(alert->theKind == ZorbaAlert::ERROR_ALERT)
		setIsError();

	if(thread_registered_callback)
	{
		if(z->current_xquery && z->current_xquery->alert_callback_param)
    {
			retval = thread_registered_callback(alert, 
																			z->current_xquery,
																			z->current_xquery->alert_callback_param);
    }
		else
    {
			retval = thread_registered_callback(alert, 
																			z->current_xquery,
																			thread_registered_param);
    }
		delete alert;
		return retval;
	}
	else
	{
		///if no callback was registered, then put the error in list
		push_back(alert);
	}

	return -1;
}

bool AlertsManagerImpl::isError()
{
	return is_error;
}

void AlertsManagerImpl::setIsError()
{
	is_error = true;
}

bool ZorbaAlertsManager::setThrowExceptionsMode(bool throw_exceptions)
{
	bool original_throw_mode = g_throw_exceptions;
	g_throw_exceptions = throw_exceptions;
	return original_throw_mode;
}

bool ZorbaAlertsManager::getThrowExceptionsMode()
{
	return g_throw_exceptions;
}

void AlertsManagerImpl::dumpAlerts(std::ostream &os)
{

  std::list<ZorbaAlert*>::const_iterator errit;

  for(errit = this->begin(); errit != this->end(); errit++)
  {
    if (errit == this->begin())
      os << endl << "Error list:" << endl;
    
    (*errit)->dumpAlert(os);
  }

  clearAlertList();
}



void ZorbaError::dumpAlert(std::ostream &os)
{
//  if(err->theIsFatal)
//    cerr << "Fatal Error: ";
//  else
    os << "Error: ";

  if(theLocation.line)
  {
    if(!theLocation.filename.empty())
      os << theLocation.filename;

    os << "[line: " << theLocation.line << "][col: "
         << theLocation.column << "]: ";
  } 

  os << theDescription << std::endl;
}


void ZorbaWarning::dumpAlert(std::ostream &os)
{
  os << "Warning:";
  if(theLocation.line)
  {
    if(!theLocation.filename.empty())
      os << theLocation.filename;

    os << "[line: " << theLocation.line << "][col: "
         << theLocation.column << "]";
  } 

  os << " : " << theDescription << std::endl;
}


void ZorbaNotify::dumpAlert(std::ostream &os)
{
  os << "Notif: " << theDescription << std::endl;
}


void ZorbaAskUser::dumpAlert(std::ostream &os)
{
  ///not implemented
  os << "Ask user: " << theDescription << std::endl;
}


void ZorbaFnError::dumpAlert(std::ostream &os)
{
  os << "User Error: ";
  os << "[QName: " << theErrorQName->getStringValue() 
    << "<decoded: " << theDescription << " > ]";
  os << " : " <<  theUserDescription << endl;

	std::vector<class Item*>::const_iterator item_it;

  for ( item_it = theItems.begin( ) ; item_it != theItems.end( ) ; item_it++ )
  {
    os  << " =-= " 
          << (*item_it)->getStringValue() 
          << "  [0x" << std::hex << (void*)(*item_it) << "]" << endl;
  }
}


void ZorbaFnTrace::dumpAlert(std::ostream &os)
{
  os << "User Trace: " << theDescription << endl;

  std::vector<class Item*>::const_iterator item_it;

  for ( item_it = items_trace.begin( ) ; item_it != items_trace.end( ) ; item_it++ )
  {
    os  << " =-= " 
          << (*item_it)->getStringValue() 
          << "  [0x" << std::hex << (void*)(*item_it) << "]" << endl;
  }

}

std::ostream& operator<<(std::ostream& os, ZorbaAlert &x)
{
	x.dumpAlert(os);
	return os;
}

}
