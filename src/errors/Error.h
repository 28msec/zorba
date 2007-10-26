
#ifndef ZORBA_ERROR_ALERTS_11_JULY_2007
#define ZORBA_ERROR_ALERTS_11_JULY_2007


///Daniel T @ IPDEVEL
/*
	Implementing error/warning alert.

	These include xquery errors and zorba errors, fatal errors and notification alerts..

*/

#include <string>
#include <vector>

#include "errors.h"
#include "xqp_exception.h"
#include "util/rchandle.h"
#include "compiler/parser/location.hh"
//#include "runtime/zorba.h"
//#include "../values/item.h"
//#include "../values/atomic_items.h"
//#include "zorba_api.h"

using namespace std;


namespace xqp {

class zorba;
class Item;
class Zorba_AlertsManager;

class ZorbaErrorAlerts : public rcobject
{
public:
	///members to be accessed from static member functions
	rchandle<error_messages> err_messages;
private:
	Zorba_AlertsManager				*errmanager_api;

public:
	ZorbaErrorAlerts( );
	~ZorbaErrorAlerts();

//	enum Zorba_Alert_Type
//	{
//		Error,
//		Warning,
//
//		NotifyEvent,////maybe for debugger
//		AskUser,///let user decide if to go on or which way to go
//	};

public:
	static void error_alert( 
													//	const char *file,
													//	const int line,
														const error_messages::errcode,///one of predefined error messages in errors.h
														error_messages::error_type,
														const yy::location *ploc = NULL, ///if NULL location will be taken from current iterator from zorba object
														bool continue_execution = false, ///recoverable (continue execution) ? fatal (throw error)?
														const string param1 = "",
														const string param2 = ""
													 );
	static void error_alert_withoutlocation( 
												//	const char *file,
												//	const int line,
													const error_messages::errcode,///one of predefined error messages in errors.h
													error_messages::error_type,
													bool continue_execution = false, ///recoverable (continue execution) ? fatal (throw error)?
													const string param1 = "",
													const string param2 = ""
													 );

	static void warning_alert( 
													//	const char *file,
													//	const int line,
														const error_messages::warning_code,
														const yy::location *ploc = NULL,///if NULL location will be taken from current iterator from zorba object
														const string param1 = "",
														const string param2 = ""
													 );
	static void warning_alert_withoutlocation( 
													//	const char *file,
													//	const int line,
														const error_messages::warning_code,
														const string param1 = "",
														const string param2 = ""
													 );

	static void notify_event( 
													//	const char *file,
													//	const int line,
														const error_messages::NotifyEvent_code notif_event,
													//	const yy::location loc, 
														const string param1 = "",
														const string param2 = ""
													 );

//	static void notify_event( const std::string notif_string,
//													 const string param1,
//													 const string param2
//													 );

	///return the index of the option chosen by user
	static int ask_user( const error_messages::AskUserString_code ask_string,
												const error_messages::AskUserStringOptions_code ask_string_options,
												const string param1 = "",
												const string param2 = ""
												);

//	static void ask_user( const std::string ask_string,
//												const string param1,
//												const string param2
//												);



	static void user_error (Item* err_qname,///optional
													const std::string description,//optional
													const std::vector<class Item*> *items);//optional

	static void user_trace ( const std::vector<class Item*> *items,
													const std::string label);
	
private:
	static void DumpItemsAsText( 
										 const std::vector<class Item*> *items);
};



////define some macros to catch the __FILE__ and __LINE__ where the error is fired

#define		ZORBA_ERROR_ALERT				\
				cout << __FILE__ << "[" << __LINE__ << "]:" << endl; \
				ZorbaErrorAlerts::error_alert
/*#define		error_alert_withoutlocation( errcode,error_type,continue_execution, param1,param2)		\
				error_alert_withoutlocation_fl(__FILE__, __LINE__,errcode,error_type,continue_execution, param1,param2)
*/
#define		ZORBA_WARNING_ALERT		\
				cout << __FILE__ << "[" << __LINE__ << "]:" << endl; \
				ZorbaErrorAlerts::warning_alert
/*#define		warning_alert_withoutlocation( warncode,ploc, param1,param2)		\
				warning_alert_without_location_fl(__FILE__, __LINE__,warncode,ploc, param1,param2)
*/
#define		ZORBA_NOTIFY_EVENT		\
				cout << __FILE__ << "[" << __LINE__ << "]:" << endl; \
				ZorbaErrorAlerts::notify_event


}

#endif
