
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
#include "parser/location.hh"
//#include "runtime/zorba.h"
#include "../values/item.h"
#include "../values/atomic_items.h"

using namespace std;
namespace xqp {

class zorba;
class QNameItem;

class ZorbaErrorAlerts : public rcobject
{
public:
	///members to be accessed from static member functions
	rchandle<error_messages> err_messages;

public:
	ZorbaErrorAlerts( class error_messages *_err_messages);
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
	static void error_alert( const error_messages::errcode,///one of predefined error messages in errors.h
														error_messages::error_type,
														const yy::location *ploc = NULL, ///if NULL location will be taken from current iterator from zorba object
														bool continue_execution = false, ///recoverable (continue execution) ? fatal (throw error)?
														const string param1 = NULL,
														const string param2 = NULL
													 );
	static void error_alert_withoutlocation( 
													const error_messages::errcode,///one of predefined error messages in errors.h
													error_messages::error_type,
													bool continue_execution = false, ///recoverable (continue execution) ? fatal (throw error)?
													const string param1 = NULL,
													const string param2 = NULL
													 );

	static void warning_alert( const error_messages::warning_code,
														const yy::location *ploc = NULL,///if NULL location will be taken from current iterator from zorba object
														const string param1 = NULL,
														const string param2 = NULL
													 );
	static void warning_alert_withoutlocation( 
														const error_messages::warning_code,
														const string param1 = NULL,
														const string param2 = NULL
													 );

	static void notify_event( const error_messages::NotifyEvent_code notif_event,
													//	const yy::location loc, 
													 const string param1 = NULL,
													 const string param2 = NULL
													 );

//	static void notify_event( const std::string notif_string,
//													 const string param1,
//													 const string param2
//													 );

	///return the index of the option chosen by user
	static int ask_user( const error_messages::AskUserString_code ask_string,
												const error_messages::AskUserStringOptions_code ask_string_options,
												const string param1 = NULL,
												const string param2 = NULL
												);

//	static void ask_user( const std::string ask_string,
//												const string param1,
//												const string param2
//												);



	static void user_error (QNameItem* err_qname,///optional
													const std::string description,//optional
													const std::vector<class Item*> *items);//optional

	static void user_trace ( const std::vector<class Item*> *items,
													const std::string label);
	
private:
	static void DumpItemsAsText( 
										 const std::vector<class Item*> *items);
};

}

#endif
