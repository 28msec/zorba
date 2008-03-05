/*
Declaration in header file (inside a class) with DECLARE_LOGGER;
Definition with DEFINE_LOGGER(_FULLYQUALIFIEDLOGGERNAME);
Logging with LOG_DEBUG(msg), LOG_INFO(msg) and LOG_ERROR(msg) to current class logger
Logging with LOG_DEBUGTO(TO,msg), LOG_INFOTO(TO,msg) and LOG_ERRORTO(TO,msg) to specified logger TO
msg is a stream (e.g. LOG_DEBUG(var1 << ": " << var2))



Configuration with
1) instanceconfigset INSTANCE logconfig THELOGCONFIG
2) xqp::LoggerManager::logmanager()->setLoggerConfig(THELOGCONFIG)

THELOGCONFIG is a string with the following form:
LoggerName#logLevel#FileName

multiple Loggers can be specified with a SPACE as a separator, e.g.:
LoggerName1#logLevel1#FileName1 LoggerName2#logLevel2#FileName2

the root element is specified as an empty name:
#rootloglevel#rootfilename

THELOGCONFIG may also contain elements with the following form (although the last one naturally overwrites the previous ones):
logtheloggername=bool  (bool=(true||false))
if the variable is set to true (which is the default value), the name of the logger is also written with the logmessage into the logfile

Configuration is hierarchical. Childs are separated with :: (e.g. xqp::parser)
If a parent element is configured after one of its childs, the childs configuration is overwritten

  
***********************************************************************/


#ifndef ZORBA_LOGGING_H
#define ZORBA_LOGGING_H

#include "loggermanager.hh"
#include "logger.hh"


const int DEBUG_LEVEL = 1;
const int INFO_LEVEL = 2;
const int ERROR_LEVEL = 3;

/**
 * used to declare a logger in a class definition (in the header file)
 */
#define DECLARE_LOGGER static xqp::Logger logger

/**
 * defines the logger, to be used in the .cc file
 * parameter is the fully qualified classname, in which the logger was declared (via DECLARE_LOGGER), which is also uses as the LoggerName
 */
#ifndef NDEBUG
#define DEFINE_LOGGER(_FULLQUALIFIEDCLASSNAME)  \
  xqp::Logger _FULLQUALIFIEDCLASSNAME::logger(std::string(#_FULLQUALIFIEDCLASSNAME))
#else
#define DEFINE_LOGGER(_FULLQUALIFIEDCLASSNAME) 
#endif


/**
 * same as DEFINE_LOGGER, except that this one is for templates
 */
#ifndef NDEBUG
#define DEFINE_LOGGER_TEMPLATE(_FULLQUALIFIEDCLASSNAME, _TEMPLATENAME)  \
  template <class _TEMPLATENAME> xqp::Logger _FULLQUALIFIEDCLASSNAME <_TEMPLATENAME>::logger(std::string(#_FULLQUALIFIEDCLASSNAME))
#else
#define DEFINE_LOGGER_TEMPLATE(_FULLQUALIFIEDCLASSNAME, _TEMPLATENAMEs) 
#endif


/**
 * logs a message in debug level (if allowed)
 * parameter is a stream
 */
#ifndef NDEBUG
#define LOG_DEBUG(message) \
      if(logger.getLevel()<=DEBUG_LEVEL) { \
	      std::ostringstream logText; \
	      logText << message; \
          std::string nString(logText.str().c_str()); \
	      logger.logMessage(DEBUG_LEVEL,nString); \
      } 
#else
#define LOG_DEBUG(message)
#endif

/**
 * logs a message in debug level (if allowed) on logger TO
 * parameter is a stream
 */
#ifndef NDEBUG
#define LOG_DEBUGTO(_TO, message) \
      if(_TO.getLevel()<=DEBUG_LEVEL) { \
	      std::ostringstream logText; \
	      logText << message; \
          std::string nString(logText.str().c_str()); \
	      _TO.logMessage(DEBUG_LEVEL,nString); \
      } 
#else
#define LOG_DEBUG(message)
#endif


/**
 * logs a message in info level (if allowed)
 * parameter is a stream
 */
#ifndef NDEBUG
#define LOG_INFO(message) \
      if(logger.getLevel()<=INFO_LEVEL) { \
	      std::ostringstream logText; \
	      logText << message; \
          std::string nString(logText.str().c_str()); \
	      logger.logMessage(INFO_LEVEL,nString); \
      } 
#else
#define LOG_INFO(message)
#endif

/**
 * logs a message in info level (if allowed) on logger TO
 * parameter is a stream
 */
#ifndef NDEBUG
#define LOG_INFOTO(_TO, message) \
      if(_TO.getLevel()<=INFO_LEVEL) { \
	      std::ostringstream logText; \
	      logText << message; \
          std::string nString(logText.str().c_str()); \
	      _TO.logMessage(INFO_LEVEL,nString); \
      } 
#else
#define LOG_INFO(message)
#endif


/**
 * logs a message in error level (if allowed)
 * parameter is a stream
 */
#ifndef NDEBUG
#define LOG_ERROR(message) \
      if(logger.getLevel()<=ERROR_LEVEL) { \
	      std::ostringstream logText; \
	      logText << message; \
          std::string nString(logText.str().c_str()); \
	      logger.logMessage(ERROR_LEVEL,nString); \
      } 
#else
#define LOG_ERROR(message) 
#endif

/**
 * logs a message in error level (if allowed) on logger TO
 * parameter is a stream
 */
#ifndef NDEBUG
#define LOG_ERRORTO(_TO, message) \
      if(_TO.getLevel()<=ERROR_LEVEL) { \
	      std::ostringstream logText; \
	      logText << message; \
          std::string nString(logText.str().c_str()); \
	      _TO.logMessage(ERROR_LEVEL,nString); \
      } 
#else
#define LOG_ERROR(message)
#endif

#endif
