
#ifndef ALERTS_ALERT_FACTORY
#define ALERTS_ALERT_FACTORY


///Daniel T @ IPDEVEL
/*
	Implementing error/warning alert.

	These include xquery errors and zorba errors, fatal errors and notification alerts..

*/

#include <string>

#include <zorba/errors.h>
#include <zorba/xqp_exception.h>

namespace zorba
{
class QueryLoc;

typedef enum
{
	DONT_CONTINUE_EXECUTION = 0,
	CONTINUE_EXECUTION
}enumContinueExecution_t;

class ZorbaAlertFactory 
{
public:
  /**
   *  @param code  One of predefined error codes in errors.h
   *  @param loc   If NULL location will be taken from current iterator from zorba object
   *  @param continue_execution If true, the error is recoverable and execution can continue; otherwise the error is fatal and an exception is thrown.
   *
   */
	static void error_alert(
        const ZorbaError::ErrorCodes code,
        const QueryLoc* ploc = NULL,
        enumContinueExecution_t continue_execution = DONT_CONTINUE_EXECUTION,
				const std::string param1 = "",
        const std::string param2 = "");


	static void warning_alert(
        const ZorbaWarning::WarningCodes code,
        const QueryLoc* ploc = NULL,
        const std::string param1 = "",
        const std::string param2 = "");


	static void notify_event(
        const ZorbaNotify::NotifyCodes code,
        const std::string param1 = "",
        const std::string param2 = "");


	static int ask_user(
        const ZorbaAskUser::UserQuestionCodes questionCode,
        const ZorbaAskUser::UserReplyOptionsCodes replyCode,
        const std::string param1 = "",
        const std::string param2 = "");

  static void fn_user_error(
        store::Item* err_qname,///optional
        const std::string description,//optional
        const std::vector<class store::Item*> *items);//optional

  static void fn_user_trace(
        const std::vector<class store::Item*> *items,
        const std::string label);
};

void ZorbaAssert (const char *where, const char *fun, const char *what);


/// define some macros to catch the __FILE__ and __LINE__ where the error is fired
#ifndef NDEBUG

extern const char*		g_error_in_file;
extern int						g_error_at_line;
extern bool						g_abort_when_fatal_error;


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


#define ZORBA_WARNING_ALERT(...) do {                           \
    g_error_in_file = __FILE__;  g_error_at_line = __LINE__;    \
    ZorbaAlertFactory::warning_alert(__VA_ARGS__);              \
  } while(0)


#define ZORBA_NOTIFY_EVENT(...) do {                            \
    g_error_in_file = __FILE__;  g_error_at_line = __LINE__;    \
    ZorbaAlertFactory::notify_event(__VA_ARGS__);               \
  } while(0)
  
  
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


#define		ZORBA_NOTIFY_EVENT(...)		\
				ZorbaAlertFactory::notify_event(__VA_ARGS__)


#endif //#ifndef NDEBUG

#define ZORBA_NOT_SUPPORTED( what )                                     \
  ZORBA_ERROR_ALERT(ZorbaError::XQP0004_SYSTEM_NOT_SUPPORTED, NULL, DONT_CONTINUE_EXECUTION, what)

#define ZORBA_NOT_IMPLEMENTED( what )                                     \
  ZORBA_ERROR_ALERT(ZorbaError::XQP0004_SYSTEM_NOT_SUPPORTED, NULL, DONT_CONTINUE_EXECUTION, what)
  
#define CATCH_ALL( uninit_instr, ret )                                                \
  catch(xqp_exception &x)\
  {\
		uninit_instr\
		x.setLocation(&Zorba::null_loc);\
		if(ZorbaEngine::getInstance()->getAlertsManagerForCurrentThread()->getThrowExceptionsMode())\
			throw;\
    ret;                                                                \
	}\
  catch (const std::exception &e) {                                     \
		uninit_instr\
    ZORBA_ERROR_ALERT(ZorbaError::XQP0019_INTERNAL_ERROR, NULL, CONTINUE_EXECUTION, e.what ()); \
		if(ZorbaEngine::getInstance()->getAlertsManagerForCurrentThread()->getThrowExceptionsMode())\
			throw;\
    ret;                                                                \
  } catch (...) {                                                       \
		uninit_instr\
    ZORBA_ERROR_ALERT(ZorbaError::XQP0019_INTERNAL_ERROR, NULL, CONTINUE_EXECUTION);  \
		if(ZorbaEngine::getInstance()->getAlertsManagerForCurrentThread()->getThrowExceptionsMode())\
			throw;\
    ret;                                                                \
  }

#define	CATCH_ALL_RETURN_NULL	 CATCH_ALL (;, return NULL)
#define	CATCH_ALL_RETURN_false CATCH_ALL (;, return false)
#define	CATCH_ALL_RETURN_VOID  CATCH_ALL (;, return)

#define CATCH_ALL_NO_RETURN(uninit_instr)    CATCH_ALL (uninit_instr, (void) 0)

#define CATCH_ITERATOR_EXCEPTION		\
  catch(xqp_exception &x)\
  {\
		x.setLocation(&this->loc);\
		throw;\
	}



class xqp_exception : public ZorbaException
{
  bool    callback_called;
public:
	xqp_exception(ZorbaError::ErrorCodes ecode);
	xqp_exception(ZorbaError_t err); 
	virtual ~xqp_exception();

	void	setLocation(const QueryLoc* ploc);
};

}

#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
