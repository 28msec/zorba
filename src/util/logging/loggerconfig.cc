#include "loggerconfig.hh"
#include <iostream>
#include <string>
#include <cassert>


namespace xqp {

LoggerConfig::LoggerConfig(const std::string& FileName) : theFileName(FileName),
    theLogLevel(0), theWriteLoggerConfig(true), theLogFile(0) {}

LoggerConfig::LoggerConfig(const std::string& FileName, int LogLevel) : 
    theFileName(FileName), theLogLevel(LogLevel), theWriteLoggerConfig(true), theLogFile(0) {}

LoggerConfig::~LoggerConfig() {
  if(theLogFile)
  {
  	theLogFile->flush();
  	theLogFile->close();
  	delete theLogFile;
  }
}

void LoggerConfig::createLogFileStream() {
    int length = theFileName.length();
    theLogFile = new std::ofstream(theFileName.c_str(), std::ios::app);
}

void LoggerConfig::updateLogFileStream() {
	if(theLogFile != 0) {
		theLogFile->flush();
		theLogFile->close();
		delete theLogFile;
        // int length = theFileName.length();
        // char* lFileName = new char[length+1];
        // theFileName.extract(0,length,lFileName);
        // lFileName[length]=0;
        theLogFile = new std::ofstream(theFileName.c_str(), std::ios::app);
        // delete[] lFileName;
	}
}

void LoggerConfig::logMessage(const std::string& logMessage) {
	if(theLogFile==NULL)
		createLogFileStream();
	*theLogFile << logMessage;
	theLogFile->flush();
}

int LoggerConfig::getLogLevel() const
{
	return theLogLevel;
}

void LoggerConfig::setLogLevel(int newLevel) {
	theLogLevel = newLevel;
}

std::string LoggerConfig::getFileName() const
{
	return theFileName;
}

void LoggerConfig::setFileName(const std::string& newFileName) {
	theFileName = newFileName;
	updateLogFileStream();
}

void LoggerConfig::setWriteLoggerConfig(bool flag){
	theWriteLoggerConfig = flag;
}

bool LoggerConfig::getWriteLoggerConfig() const
{
	return theWriteLoggerConfig;
}

}

