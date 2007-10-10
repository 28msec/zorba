#ifndef XQP_LOGGERMANAGER_H
#define XQP_LOGGERMANAGER_H

#include <map>
#include <limits>
#include <string>

namespace xqp {

class LoggerConfig;
	
class LoggerManager
{
   public:
	 /**  */
     static LoggerManager* logmanager();
     
	 /**
	  * create a new logger called LoggerName
	  * @param LoggerName: the name for the logger
	  */     
     LoggerConfig* registerLogger(const std::string& LoggerName);
     
	 /**
	  * sets the new level for the logger called LoggerName
	  * @param LoggerName: the logger
	  * @param newLevel: the new level
	  */          
     void setLevel(const std::string& LoggerName, int newLevel);
     
	 /**
	  * sets the new filename for the logger called LoggerName
	  * @param LoggerName: the logger
	  * @param newFileName: the new filename
	  */    
     void setFileName(const std::string& LoggerName, const std::string& newFileName);
     
	 /**
	  * destructor
	  */          
     ~LoggerManager();
     
	 /**
	  * 
	  */          
     void registerLogger(const std::string& LoggerName, const std::string& FileName, int logLevel);
     
	 /**
	  * 
	  */          
	 void extractLoggerData(std::string loggerData);
     
	 /**
	  * configures the loggers from a string
	  * @param text2Parse: the text containing the logger configs
	  */     	 
	 void setLoggerConfig(std::string text2Parse);
          
	 /**
	  * returns the current logger configs as a string
	  */
	  std::string getLoggerConfig();
	  
	  /**
	   * Log the Logger Name?
	   * @return bool
	   */
	   bool getLogTheLoggerName() const;

     /**
      * Get length (in characters) of the longest logger name
      * @return the length of the longest logger name
      */
      unsigned int getLongestLoggerNameLength() const;

   private:
     std::map<std::string,LoggerConfig*> theLoggerCollection;
     typedef std::map<std::string,LoggerConfig*>::const_iterator LoggerConfigIterator;
     //Name des Wurzelelementes
     std::string theRootElement;
     //Default-Dateiname, in die geloggt werden soll
     std::string theDefaultFileName;
     //Default-Loglevel
     static int theLogBarrier;
     //Trennzeichen innerhalb einer config
     static std::string theConfigSeparator;
     //Trennzeichen fuer mehrere logger
	 static std::string theLoggerSeparator;
     static bool theLogTheLoggerNameFlag;
     unsigned int theLongestLoggerNameLength;
	 /** 
	  * constructor
	  */     
     LoggerManager();
	 /**
	  * sets the WriteLoggerConfig Flag in the corresponding LoggerConfig
	  * Flag = true, if the LoggerConfig should be saved (via getLoggerConfig())
	  * @param iterator:
	  * @param LoggerName:
	  */
     void setWriteLoggerConfig(const LoggerConfigIterator iterator, const std::string& LoggerName);
	 /**
	  * Checks whether a given character is in the list of valid characters (a-zA-Z_:0-9)
	  * @param c: the character to be checked
	  */
     bool isValidChar(const char c) const;
	 /**
	  * Checks whether a given string qualifies as a valid name for a logger
	  * @param LoggerName: the name to be checked
	  */
     bool isValidLogger(const std::string& LoggerName) const;
};

}
#endif
