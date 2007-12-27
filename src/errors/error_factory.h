
#ifndef ZORBA_ERROR_ALERTS_11_JULY_2007
#define ZORBA_ERROR_ALERTS_11_JULY_2007


///Daniel T @ IPDEVEL
/*
	Implementing error/warning alert.

	These include xquery errors and zorba errors, fatal errors and notification alerts..

*/

#include <string>

#include "errors/error_codes.h"
#include "xqp_exception.h"
#include "compiler/parser/location.hh"

//using namespace std;


namespace xqp {

class ZorbaAlertFactory 
{

public:
  /**
   *  @param ecode One of predefined error codes in errors.h
   *  @param etype One of predefined error types in errors.h
   *  @param loc   If NULL location will be taken from current iterator from zorba object
   *  @param continue_execution If true, the error is recoverable and execution can continue; otherwise the error is fatal and an exception is thrown.
   *
   */
	static void error_alert(
        const AlertCodes::error_code ecode,
        const yy::location *ploc = NULL,
        bool continue_execution = false,
				const std::string param1 = "",
        const std::string param2 = "");


	static void warning_alert(
        const AlertCodes::warning_code,
        const yy::location *ploc = NULL,
        const std::string param1 = "",
        const std::string param2 = "");


	static void notify_event(
        const AlertCodes::NotifyEvent_code notif_event,
        const std::string param1 = "",
        const std::string param2 = "");


	///return the index of the option chosen by user
	static int ask_user(
        const AlertCodes::AskUserString_code ask_string,
        const AlertCodes::AskUserStringOptions_code ask_string_options,
        const std::string param1 = "",
        const std::string param2 = "");
};


////define some macros to catch the __FILE__ and __LINE__ where the error is fired
#ifndef NDEBUG

#define ZORBA_ERROR_ALERT(...) do {                            \
    g_error_in_file = __FILE__; g_error_at_line = __LINE__;    \
    ZorbaAlertFactory::error_alert(__VA_ARGS__);               \
  } while(0)


#define ZORBA_ERROR_ALERT_OSS(e,  ploc, ce, msg1, msg2) {               \
    g_error_in_file = __FILE__; g_error_at_line = __LINE__;             \
    std::ostringstream os1, os2;                                        \
    os1 << msg1;                                                        \
    os2 << msg2;                                                        \
    ZorbaAlertFactory::error_alert(e, ploc, ce, os1.str(), os2.str());  \
}


#define		ZORBA_WARNING_ALERT(...) do {                         \
    g_error_in_file = __FILE__;  g_error_at_line = __LINE__;    \
    ZorbaAlertFactory::warning_alert(__VA_ARGS__);              \
  } while(0)


#define ZORBA_WARNING_ALERT_OSS(w, ploc, msg1, msg2) {                 \
    g_error_in_file = __FILE__; g_error_at_line = __LINE__;            \
    std::ostringstream os1, os2;                                       \
    os1 << msg1;                                                       \
    os2 << msg2;                                                       \
    ZorbaAlertFactory::warning_alert(w, ploc, os1.str(), os2.str());   \
}


#define		ZORBA_NOTIFY_EVENT(...) do {                          \
    g_error_in_file = __FILE__;  g_error_at_line = __LINE__;    \
    ZorbaAlertFactory::notify_event(__VA_ARGS__);               \
  } while(0)
  
  
#define ZORBA_NOTIFY_EVENT_OSS(notif_event, msg1, msg2) {               \
    g_error_in_file = __FILE__; g_error_at_line = __LINE__;             \
    std::ostringstream os1, os2;                                        \
    os1 << msg1;                                                        \
    os2 << msg2;                                                        \
    ZorbaAlertFactory::notify_event(notif_event, os1.str(), os2.str()); \
}

#else ///#ifndef NDEBUG

#define		ZORBA_ERROR_ALERT(...)				\
				ZorbaAlertFactory::error_alert(__VA_ARGS__)


#define ZORBA_ERROR_ALERT_OSS(e, ploc, ce, msg1, msg2) { \
			std::ostringstream os1, os2; \
			os1 << msg1; \
			os2 << msg2; \
			ZorbaAlertFactory::error_alert(e, ploc, ce, os1.str().c_str(), os2.str().c_str()); \
}


#define		ZORBA_WARNING_ALERT(...)		\
				ZorbaAlertFactory::warning_alert(__VA_ARGS__)


#define ZORBA_WARNING_ALERT_OSS(w, ploc, msg1, msg2) { \
			std::ostringstream os1, os2; \
			os1 << msg1; \
			os2 << msg2; \
			ZorbaAlertFactory::warning_alert(w, ploc, os1.str().c_str(), os2.str().c_str()); \
}


#define		ZORBA_NOTIFY_EVENT(...)		\
				ZorbaAlertFactory::notify_event(__VA_ARGS__)


#define ZORBA_NOTIFY_EVENT_OSS(notif_event, msg1, msg2) { \
			std::ostringstream os1, os2; \
			os1 << msg1; \
			os2 << msg2; \
			ZorbaAlertFactory::notify_event(notif_event, os1.str().c_str(), os2.str().c_str()); \
}


#endif //#ifndef NDEBUG


}

#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
