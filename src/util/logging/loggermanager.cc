#include "loggermanager.hh"

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>


#include "loggerconfig.hh"
#include "logging.hh"


namespace xqp {

bool LoggerManager::theLogTheLoggerNameFlag = true;
std::string LoggerManager::theConfigSeparator = "#";
std::string LoggerManager::theLoggerSeparator = " " ;
int LoggerManager::theLogBarrier = INT_MAX;


LoggerManager* LoggerManager::logmanager()
{
  static LoggerManager theLogManagerInstance;
	return &theLogManagerInstance;
}

LoggerManager::LoggerManager() : theLongestLoggerNameLength(0)
{
	theRootElement = "";							
	theDefaultFileName = "logging.log";				
	LoggerConfig* theLoggerConfig = new LoggerConfig(theDefaultFileName, ERROR_LEVEL);
	theLoggerCollection.insert(std::make_pair(theRootElement,theLoggerConfig));
}

LoggerConfig* LoggerManager::registerLogger(const std::string& LoggerName){
	if(isValidLogger(LoggerName)) {	 
		 int logLevel = theLogBarrier;
		 std::string fileName = theDefaultFileName;	 
		 if(theLoggerCollection.find(LoggerName)==theLoggerCollection.end()) {
		 	LoggerConfig* theLoggerConfig = new LoggerConfig(fileName, logLevel);
		 	theLoggerConfig->setWriteLoggerConfig(false);
		 	theLoggerCollection.insert(std::make_pair(LoggerName,theLoggerConfig));
      //check whether current logger name is longer than every other previous encountered & adapt
      assert(LoggerName.length()>0);  //sanity
      if(static_cast<unsigned int>(LoggerName.length())>theLongestLoggerNameLength)
        theLongestLoggerNameLength = LoggerName.length();
			return theLoggerConfig;
		 }
		 else
		 {
			return theLoggerCollection.find(LoggerName)->second;
		 }
	}
	else {
        assert(false);
	}
	return NULL;
}

void LoggerManager::registerLogger(const std::string& LoggerName, const std::string& FileName, int logLevel){
	if(isValidLogger(LoggerName)) {
		registerLogger(LoggerName);
		setLevel(LoggerName, logLevel);
		setFileName(LoggerName, FileName);
	}
}

void LoggerManager::setLevel(const std::string& LoggerName, int newLevel) {
	if(theLoggerCollection.find(LoggerName)==theLoggerCollection.end()) {
		registerLogger(LoggerName);
	}	
	LoggerConfigIterator startIterator, endIterator;
	//Falls LoggerName = rootElement ersetze alle Level
	if(LoggerName==theRootElement)
	{
		startIterator = theLoggerCollection.begin();
		endIterator = theLoggerCollection.end();		
		for(LoggerConfigIterator iterator = startIterator;
			iterator != endIterator; iterator++)
		{
			iterator->second->setLogLevel(newLevel);
			setWriteLoggerConfig(iterator, LoggerName);
		}
	}
	//Ansonsten ersetzte nur die Level von LoggerName + dessen Kindern
	else
	{
		startIterator = theLoggerCollection.lower_bound(LoggerName);
		endIterator = theLoggerCollection.lower_bound(LoggerName+"::~");
		for(LoggerConfigIterator iterator = startIterator;
		iterator != endIterator; iterator++)
		{
			iterator->second->setLogLevel(newLevel);
			setWriteLoggerConfig(iterator, LoggerName);
		}
	}

}

void LoggerManager::setFileName(const std::string& LoggerName, const std::string& newFileName) {
	//Falls noch kein Logger-Objekt hierzu existiert neu anlegen
	if(theLoggerCollection.find(LoggerName)==theLoggerCollection.end()) {
		registerLogger(LoggerName);
	}
	LoggerConfigIterator startIterator, endIterator;
	//Falls LoggerName = theRootElement ersetze alle Dateinamen
	if(LoggerName==theRootElement)
	{
		startIterator = theLoggerCollection.begin();		
		endIterator = theLoggerCollection.end();
		for(LoggerConfigIterator iterator = startIterator;
			iterator != endIterator; iterator++)
		{
			iterator->second->setFileName(newFileName);
			setWriteLoggerConfig(iterator, LoggerName);
		}
	}
	//Ansonsten ersetzte nur die Level von LoggerName + dessen Kindern
	else
	{
		startIterator = theLoggerCollection.lower_bound(LoggerName);
		endIterator = theLoggerCollection.lower_bound(LoggerName+"::~");		
		for(LoggerConfigIterator iterator = startIterator;
		iterator != endIterator; iterator++)
		{
			iterator->second->setFileName(newFileName);
			setWriteLoggerConfig(iterator, LoggerName);
		}
	}
}

void LoggerManager::setWriteLoggerConfig(const LoggerConfigIterator iterator, const std::string& LoggerName) {
	if(iterator->first.compare(LoggerName)!=0) {
		iterator->second->setWriteLoggerConfig(false);
	}
	else
	{
		iterator->second->setWriteLoggerConfig(true);				
	}
}


LoggerManager::~LoggerManager()
{
	//Delete all stored LoggerConfigs
	for(LoggerConfigIterator iterator = theLoggerCollection.begin();
      iterator != theLoggerCollection.end(); ++iterator)
		delete iterator->second;
}


void LoggerManager::setLoggerConfig(std::string text2Parse) {
	while(text2Parse.length()>0) {
		int nextSpace = text2Parse.find_first_of(theLoggerSeparator.c_str());
		std::string dataExtract;
		if(nextSpace==-1) {
			extractLoggerData(text2Parse);		
		} else {
			dataExtract = text2Parse.substr(0, nextSpace);
			extractLoggerData(dataExtract);		
		}
		if(nextSpace==-1) break;		
		text2Parse = text2Parse.substr(nextSpace+1,text2Parse.length());
	}
	
}

void LoggerManager::extractLoggerData(std::string loggerData) {
	
	if((loggerData=="logtheloggername=true")||(loggerData=="logtheloggername=false")) {
		//extrahieren
		std::string theFlagValue;
		theFlagValue = loggerData.substr(17,loggerData.length());
		if(theFlagValue=="true") {
			theLogTheLoggerNameFlag=true;
		}
		if(theFlagValue=="false"){
			theLogTheLoggerNameFlag=false;
		}
	}
	else
	{
		int firstOccurence = loggerData.find_first_of(theConfigSeparator.c_str());
		std::string loggerName = loggerData.substr(0, firstOccurence);
		loggerData = loggerData.substr(firstOccurence+1,loggerData.length());
		int secondOccurence = loggerData.find_first_of(theConfigSeparator.c_str());
		std::string logLevelString = loggerData.substr(0, secondOccurence);
		int logLevel = theLogBarrier;
		if(logLevelString!="") {
			logLevel = atoi(logLevelString.c_str());
		}
		std::string outputFile = loggerData.substr(secondOccurence+1, loggerData.length());
		if(outputFile=="")
			outputFile = theDefaultFileName;
		setLevel(loggerName,logLevel);
		setFileName(loggerName, outputFile);
	}
}

bool LoggerManager::getLogTheLoggerName() const
{
	return theLogTheLoggerNameFlag;
}

unsigned int LoggerManager::getLongestLoggerNameLength() const
{
  return theLongestLoggerNameLength;
}

std::string LoggerManager::getLoggerConfig() {
	std::ostringstream loggerConfig;
	LoggerConfigIterator startIterator, endIterator;
	startIterator = theLoggerCollection.begin();
	endIterator = theLoggerCollection.end();
	for(LoggerConfigIterator iterator = startIterator;
		iterator!=endIterator; iterator++) {
		if(iterator->second->getWriteLoggerConfig()) {
			loggerConfig << iterator->first << theConfigSeparator 
						 << iterator->second->getLogLevel() << theConfigSeparator
						 << iterator->second->getFileName() << theLoggerSeparator;
		}
	}
	std::string returnString(loggerConfig.str().c_str());
	return returnString;
}

bool LoggerManager::isValidLogger(const std::string& LoggerName) const {
	for(uint i=0;i<LoggerName.length();i++) {
		char c = LoggerName[i];
		if(!isValidChar(c))
			return false;
	}
	return true;
}

bool LoggerManager::isValidChar(const char c) const {
	if(  (('0' <= c)&&(c<=':'))
	   ||(('A'<=c)&&(c<='Z'))
	   ||(('a'<=c)&&(c<='z'))
	   ||(c=='_')
	  )
	  	return true;
	return false;
}

}//end namespace xqp
