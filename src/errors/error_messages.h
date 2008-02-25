#ifndef ALERTS_ALERT_MESSAGES
#define ALERTS_ALERT_MESSAGES

#include <zorba/errors.h>

namespace xqp
{

/*******************************************************************************

********************************************************************************/
class AlertMessages
{
 public:
  virtual ~AlertMessages() { }

	virtual std::string error_decode(ZorbaError::ErrorCodes) = 0;
	virtual std::string warning_decode(ZorbaWarning::WarningCodes) = 0;
	virtual std::string notify_event_decode(ZorbaNotify::NotifyCodes) = 0;
	virtual std::string ask_user_decode(ZorbaAskUser::UserQuestionCodes) = 0;
	virtual std::string ask_user_options_decode(ZorbaAskUser::UserReplyOptionsCodes) = 0;

	void applyParams(
        std::string* errorMsg,
        const std::string* param1,
        const std::string* param2);

  std::string::size_type applyParam(
        std::string* errorMsg,
        const std::string* param1,
        std::string::size_type);
};


/*******************************************************************************

********************************************************************************/
class AlertMessagesEnglish : public AlertMessages
{
public:
	std::string error_decode(ZorbaError::ErrorCodes);
	std::string warning_decode(ZorbaWarning::WarningCodes);
	std::string notify_event_decode(ZorbaNotify::NotifyCodes);
	std::string ask_user_decode(ZorbaAskUser::UserQuestionCodes);
	std::string ask_user_options_decode(ZorbaAskUser::UserReplyOptionsCodes);
};



/*******************************************************************************
	This class reads the error messages from a string table file.
	No need to recompile the code to use international languages.
********************************************************************************/
class AlertMessagesTable : public AlertMessages
{
public:
	AlertMessagesTable(std::string file_name);

	//std::string error_decode(ZorbaError::ErrorCodes);
	//std::string warning_decode(ZorbaWarning::WarningCodes);
	//std::string notify_event_decode(ZorbaNotify::NotifyCodes);
	//std::string ask_user_decode(ZorbaAskUser::UserQuestionCodes);
	//std::string ask_user_options_decode(ZorbaAskUser::UserReplyOptionsCodes);
};


}

#endif
