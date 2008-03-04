#ifndef XQP_LOGGERCONFIG_H
#define XQP_LOGGERCONFIG_H

#include <iostream>
#include <fstream>
#include <sstream>

namespace zorba {
	
class LoggerConfig {


	public:
		/**
		 * constructor for LoggerConfig class
		 * @param FileName: the output filename
		 */
		LoggerConfig(const std::string& FileName);
		
		/**
		 * constructor for LoggerConfig class
		 * @param FileName: the output filename
		 * @param LogLevel: the log level
		 */
		LoggerConfig(const std::string& FileName, int LogLevel);	
		
		/**
		 */
		 ~LoggerConfig();
		 
		/**
		 * returns the log level for this config
		 * @return the log level
		 */
		int getLogLevel() const;
		
		/**
		 * sets the new level for this config
		 * @param newLevel: the new log level
		 */
		void setLogLevel(int newLevel);
		
		/**
		 * returns the current output filename
		 * @return the current output filename
		 */
		std::string getFileName() const;
		
		/**
		 * sets the new filename for this config
		 * @param newFileName: the new output filename
		 */
		void setFileName(const std::string& newFileName);
		
		/**
		 */
		 void setWriteLoggerConfig(bool flag); 

		/**
		 */
		 bool getWriteLoggerConfig() const;		 
		 
		 /**
		  */
		  void logMessage(const std::string& logMessage);
		  
	private:
		std::string theFileName;
		int theLogLevel;
		bool theWriteLoggerConfig;
  	    std::ofstream* theLogFile;

  	     /**
		  */
		  void createLogFileStream();
		  
		  /**
		   */
		  void updateLogFileStream();
};

}

#endif
