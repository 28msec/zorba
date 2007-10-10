#include "logger.hh"

#include <time.h>
#include <cassert>
#include "loggermanager.hh"
#include "loggerconfig.hh"


namespace xqp {

Logger::Logger(const std::string& loggerName) : theLoggerName(loggerName){ 
	theLoggerPtr = LoggerManager::logmanager()->registerLogger(loggerName);
}

int Logger::getLevel() const{
	return theLoggerPtr->getLogLevel();
}

void Logger::logMessage(int level, const std::string& message) {
	if(getLevel() <= level)
	{
		//get and format the current time
		time_t rawtime;
  		struct tm * timeinfo;
		time ( &rawtime );
		timeinfo = localtime ( &rawtime );
		std::string formattedTime = asctime(timeinfo);
		formattedTime = formattedTime.substr(0,formattedTime.length()-1);
		std::stringstream logMessage;
		logMessage << formattedTime << '\t';
    if(LoggerManager::logmanager()->getLogTheLoggerName())
    {
      long width = LoggerManager::logmanager()->getLongestLoggerNameLength()-theLoggerName.length();
      assert(width>=0); //sanity
      logMessage << theLoggerName << std::string(width, ' ') << '\t';
    }
		logMessage << "LogLevel=" << level << '\t' << message << std::endl ;
		std::string lMessage(logMessage.str().c_str());
		theLoggerPtr->logMessage(lMessage);
	}
}

void Logger::setLevel(int newLevel)
{
	LoggerManager::logmanager()->setLevel(theLoggerName, newLevel);
}
void Logger::setFileName(const std::string& newFileName)
{
	LoggerManager::logmanager()->setFileName(theLoggerName, newFileName);
}

Logger::~Logger() {}

} //end of namespace xqp
