/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "debugger/debugger_protocol.h"
#include "util/stl_util.h"

#include <iomanip>
#include <list>

#include <zorba/zorba.h>

#include <jansson.h>

#include "api/unmarshaller.h"
#include "zorbatypes/numconversions.h"
#include "zorbautils/lock.h"
#include "debugger/utils.h"
#include "util/ascii_util.h"

using namespace std;

namespace zorba {

bool is_little_endian()
{
  short int word = 0x0001;
  char * byte = (char *) &word;
  return(byte[0] ? true : false);
}

uint16_t uint_swap(uint16_t i)
{
  if (!is_little_endian()) {
    return i;
  } else {
    unsigned char b1, b2;
    b1 = i & 255;
    b2 = (i >> 8) & 255;
    return (b1 << 8) + b2;
  }
}

uint32_t uint_swap(uint32_t i)
{
  if (!is_little_endian()) {
    return i;
  } else {
    unsigned char b1, b2, b3, b4;
    b1 = i & 255;
    b2 = (i >> 8) & 255;
    b3 = (i >> 16) & 255;
    b4 = (i >> 24) & 255;
    return (b1 << 24) + (b2 << 16) + (b3 << 8) + b4;
  }
}

std::ostream& operator << (std::ostream &os, const AbstractMessage* message)
{
  Length length;
  const char* lData = reinterpret_cast<const char*>(message->serialize(length));
  os.write(lData, length);
  return os;
}

json_t* getJsonValue(Byte* aMessage, const unsigned int aLength)
{
  std::string lMessageStr(reinterpret_cast<char *>(aMessage + MESSAGE_HEADER_SIZE), aLength - MESSAGE_HEADER_SIZE);
  json_error_t error;
  return json_loads(lMessageStr.c_str(), 0, &error);
}

void replaceAllInString(std::string& aString,
                        std::string aPattern,
                        std::string aReplace)
{
  std::string::size_type lPos = aString.find(aPattern);
  while (lPos != std::string::npos) {
    aString.replace(lPos, aPattern.size(), aReplace);
    lPos = aString.find(aPattern, lPos + 1);
  }
}

void deserializeString(std::string& aString)
{
  std::string lRes;
  std::string::size_type lBegin = 0;
  std::string::size_type lPos = aString.find("\\\"");
  while (lPos != std::string::npos) {
    std::string lSub = aString.substr(lBegin, lPos - lBegin) + "\"";
    lRes += lSub;
    lBegin = lPos + 2;
    lPos = aString.find("\\\"", lBegin);
  }
  lRes += aString.substr(lBegin, std::string::npos);
  lBegin = 0;
  aString = lRes;
  lPos = aString.find("\\n");
  lRes = "";
  while (lPos != std::string::npos) {
    lRes += aString.substr(lBegin, lPos - lBegin) + "\n";
    lBegin = lPos + 2;
    lPos = aString.find("\\n", lBegin);
  }
  lRes += aString.substr(lBegin, std::string::npos);
  aString = lRes;
}

bool AbstractMessage::operator == (const AbstractMessage & message)
{
  Length length;
  Byte* msg1 = serialize(length);
  Byte* msg2 = message.serialize(length);
  bool r = memcmp(msg1, msg2, length) == 0;
  delete[] msg1;
  delete[] msg2;
  return r;
}

bool AbstractMessage::operator != (const AbstractMessage & message)
{
  return ! (* this == message);
}

MessageException::MessageException(const std::string &aMessage) throw() : userMessage(aMessage) {}

MessageException::~MessageException() throw() {}

const char * MessageException::what() const throw()
{
  return userMessage.c_str();
}

AbstractMessage::AbstractMessage(const Id aId, const Flags aFlags)
{
  theHeaderContent = new HeaderContent();
  setId(aId);
  setFlags(aFlags);
  setLength(SIZE_OF_HEADER_CONTENT);
}

AbstractMessage::AbstractMessage(Byte* aMessage)
{
  HeaderContent * lmsg = reinterpret_cast<HeaderContent*>(aMessage);
  theHeaderContent = new HeaderContent();
  memcpy(theHeaderContent, lmsg, SIZE_OF_HEADER_CONTENT);
}

AbstractMessage::~AbstractMessage()
{
  delete theHeaderContent;
}

void AbstractMessage::checkIntegrity()
{
  //if (!isValidMessage()) {
  //  throw MessageException("Invalid Message");
  //}
}

ReplyMessage::ReplyMessage(const Id aId, const ErrorCode aErrorCode)
  : AbstractMessage(aId, REPLY_FLAG)
{
  theReplyContent = new ReplyContent();
  setErrorCode(aErrorCode);
  setLength(MESSAGE_HEADER_SIZE);
}

ReplyMessage::ReplyMessage(Byte* aMessage, const unsigned int aLength)
  : AbstractMessage(aMessage)
{
  ErrorCode * lmsg =  reinterpret_cast<ErrorCode*>(aMessage + SIZE_OF_HEADER_CONTENT);
  theReplyContent = new ReplyContent();
  memcpy(theReplyContent, lmsg, SIZE_OF_REPLY_CONTENT);
  if (aLength - MESSAGE_HEADER_SIZE > 0) {
    ztd::auto_vec<char> lData(new char[ aLength - MESSAGE_HEADER_SIZE + 1 ]);
    memset(lData.get(), '\0', aLength - MESSAGE_HEADER_SIZE + 1);
    memcpy(lData.get(), aMessage + MESSAGE_HEADER_SIZE, aLength - MESSAGE_HEADER_SIZE);
    theData = lData.get();
  }
  checkIntegrity();
}

ReplyMessage::~ReplyMessage()
{
  delete theReplyContent;
}

Byte* ReplyMessage::serialize(Length & aLength) const
{
  std::stringstream lData;
  lData << theData;
  aLength = getLength();
  Byte* lHeader = reinterpret_cast< Byte* > (theHeaderContent);
  Byte* lReply  = reinterpret_cast< Byte* > (theReplyContent);
  //Harcoded value to avoid padding on sizeof(HeaderContent)
  Byte* lMsg = new Byte[SIZE_OF_HEADER_CONTENT + SIZE_OF_REPLY_CONTENT + lData.str().length()];
  memcpy(lMsg, lHeader, SIZE_OF_HEADER_CONTENT);
  memcpy(lMsg + SIZE_OF_HEADER_CONTENT, lReply, SIZE_OF_REPLY_CONTENT);
  if (lData.str().length() > 0) {
    memcpy(lMsg + SIZE_OF_HEADER_CONTENT + SIZE_OF_REPLY_CONTENT, lData.str().c_str(), lData.str().length());
  }
  return lMsg;
}

bool ReplyMessage::isValidMessage() const
{
  //Logic of the reply packet
  //TODO: implement the logic of the message
  return true;
}

bool ReplyMessage::isOk() const
{
  return getErrorCode() == DEBUGGER_NO_ERROR;
}

/**
 * Compute and assemble a packet implementing the debugger protocol
 * @param id (4 bytes): The packet id
 * @param flags (1 byte)
 * @param command_set (1 byte)
 * @param command (1 byte)
 * @param data (variable)
 */
unsigned long
AbstractCommandMessage::getNextId()
{
  // needs to be synchronized if server
  // and client run in the same process
  static Lock theLock;
  AutoLock lLock(theLock, Lock::WRITE);
  static unsigned long theLastId = 0;
  return ++theLastId;
}

AbstractCommandMessage::AbstractCommandMessage(const CommandSet aCommandSet, const Command aCommand, const Flags flags)
  : AbstractMessage(getNextId(), flags),
    theReply(0),
    theCommandContent(new CommandContent())
{
  setCommandSet(aCommandSet);
  setCommand(aCommand);
  setLength(MESSAGE_HEADER_SIZE);
}

AbstractCommandMessage::AbstractCommandMessage(Byte* aMessage, const unsigned int aLength)
  : AbstractMessage(aMessage),
    theReply(0),
    theCommandContent(new CommandContent())
{
  CommandContent * lmsg =  reinterpret_cast< CommandContent *>(aMessage + SIZE_OF_HEADER_CONTENT);
  memcpy(theCommandContent, lmsg, sizeof(CommandContent));
  checkIntegrity();
}

Byte* AbstractCommandMessage::serialize(Length & aLength) const
{
  Byte* lHeader   = reinterpret_cast< Byte* > (theHeaderContent);
  Byte* lCommand  = reinterpret_cast< Byte* > (theCommandContent);
  //Harcoded value to avoid padding on sizeof(HeaderContent)
  Byte* lMsg = new Byte[ SIZE_OF_HEADER_CONTENT + sizeof(CommandContent) ];
  memcpy(lMsg, lHeader, SIZE_OF_HEADER_CONTENT);
  memcpy(lMsg + SIZE_OF_HEADER_CONTENT, lCommand, sizeof(CommandContent));
  aLength = MESSAGE_HEADER_SIZE;
  return lMsg;
}

AbstractCommandMessage::~AbstractCommandMessage()
{
  delete theCommandContent;
}

bool AbstractCommandMessage::isValidMessage() const
{
  return isExecutionCommand() || isBreakpointsCommand() ||
         isEngineEventCommand() || isStaticCommand() ||
         isDynamicCommand();
}

bool AbstractCommandMessage::isExecutionCommand() const
{
  return getCommandSet() == EXECUTION &&
          (getCommand() == RUN || getCommand() == SUSPEND ||
            getCommand() == RESUME || getCommand() == STEP ||
            getCommand() == TERMINATE);
}

bool AbstractCommandMessage::isBreakpointsCommand() const
{
  return getCommandSet() == BREAKPOINTS &&
          (getCommand() == SET || getCommand() == CLEAR);
}

bool AbstractCommandMessage::isEngineEventCommand() const
{
  return getCommandSet() == ENGINE_EVENT &&
          (getCommand() == STARTED || getCommand() == TERMINATED ||
            getCommand() == SUSPENDED || getCommand() == RESUMED  || getCommand() == EVALUATED);
}

bool AbstractCommandMessage::isStaticCommand() const
{
  return getCommandSet() == STATIC
          && (getCommand() == OPTIONS || getCommand() == DEFAULTS ||
                getCommand() == SETS);
}

bool AbstractCommandMessage::isDynamicCommand() const
{
  return getCommandSet() == DYNAMIC &&
    (getCommand() == DATA || getCommand() == VARIABLES ||
      getCommand() == FOCUS || getCommand() == TIME || 
      getCommand() == DOCUMENTS || getCommand() == COLLECTION ||
      getCommand() == COLLECTIONS || getCommand() == EVAL);
}

/**
 * Run message
 */
RunMessage::RunMessage()
  : AbstractCommandMessage(EXECUTION, RUN) {}

RunMessage::RunMessage(Byte* aMessage, const unsigned int aLength)
  : AbstractCommandMessage(aMessage, aLength) {}

RunMessage::~RunMessage() {}

/**
 * Suspend message
 */
SuspendMessage::SuspendMessage():
  AbstractCommandMessage(EXECUTION, SUSPEND) {}

SuspendMessage::SuspendMessage(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength) {}

SuspendMessage::~SuspendMessage() {}

/**
 * Resume message
 */
ResumeMessage::ResumeMessage():
  AbstractCommandMessage(EXECUTION, RESUME) {}

ResumeMessage::ResumeMessage(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength) {}

ResumeMessage::~ResumeMessage() {}

/**
 * Terminate message
 */
TerminateMessage::TerminateMessage():
  AbstractCommandMessage(EXECUTION, TERMINATE) {}

TerminateMessage::TerminateMessage(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength) {}

TerminateMessage::~TerminateMessage() {}

/**
 * Detach message
 */
DetachMessage::DetachMessage():
  AbstractCommandMessage(EXECUTION, DETACH) {}

DetachMessage::DetachMessage(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength) {}

DetachMessage::~DetachMessage() {}

/**
 * Step message
 */
StepMessage::StepMessage(StepCommand aKind):
  AbstractCommandMessage(EXECUTION, STEP), theKind(aKind)
{
  setLength((Length)(MESSAGE_HEADER_SIZE + getData().length()));
  checkIntegrity();
}

StepMessage::StepMessage(Byte* aMessage, const unsigned int aLength):
  AbstractCommandMessage(aMessage, aLength)
{
  json_t* lData = getJsonValue(aMessage, aLength);
  json_t* lStepType = json_object_get(lData, "stepType");
  if (lStepType != 0) {
    theKind = (StepCommand)json_integer_value(lStepType);
  }
  checkIntegrity();
}

StepMessage::~StepMessage() {}

Byte* StepMessage::serialize(Length& aLength) const
{
  ztd::auto_vec<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  std::string lJSONString = getData();
  Byte* lMsg = new Byte[getLength() + 1];
  memset(lMsg, '\0', getLength() + 1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  const char* s = lJSONString.c_str();
  size_t l = lJSONString.length();
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg; 
}

std::string StepMessage::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{\"stepType\":" << (int)theKind << "}";
  return lJSONString.str();
}

bool StepMessage::isValidMessage() const
{
  return AbstractCommandMessage::isValidMessage() && (
      theKind == STEP_INTO ||
      theKind == STEP_OUT ||
      theKind == STEP_OVER);
}

StepCommand StepMessage::getStepKind() const
{
  return theKind;
}

/**
 * Set Breakpoints message
 */
SetMessage::SetMessage(): AbstractCommandMessage(BREAKPOINTS, SET) {}

SetMessage::SetMessage(Byte* aMessage, const unsigned int aLength):
  AbstractCommandMessage(aMessage, aLength)
{
  json_t* lValue = getJsonValue(aMessage, aLength);
  
  json_t* lBreakpoints = json_object_get(lValue, "breakpoints");
  if (lBreakpoints != 0) {
    int lSize = json_array_size(lBreakpoints);
    
    for (int i = 0; i < lSize; i++) {
      json_t* lCurr = json_array_get(lBreakpoints, i);
      if (lCurr == 0) {
        throw MessageFormatException("Invalid JSON format for Set breakpoint message: a problem occured while iterating the breakpoints.");
      }

      json_t* lIdJ = json_object_get(lCurr, "id");
      if (lIdJ == 0) {
        throw MessageFormatException("Invalid JSON format for Set breakpoint message: no 'id' found");
      }
      int lId = (unsigned int)json_integer_value(lIdJ);

      json_t* lExpLoc = json_object_get(lCurr, "location");
      if (lExpLoc != 0) {
        QueryLoc lLoc = debugger::fromJSONToQueryLoc(lExpLoc);
        theLocations.insert(std::make_pair(lId, lLoc));
        continue;
      }

      lExpLoc = json_object_get(lCurr, "expr");
      if (lExpLoc != 0) {
        std::string lExpr = json_string_value(lExpLoc);
        theExprs.insert(std::make_pair(lId, zstring(lExpr)));
        continue;
      }

      throw MessageFormatException("Invalid JSON format for Set breakpoint message: neither 'location' nor 'expr' were found");
    }
  } else {
    throw MessageFormatException("Invalid JSON format for Set breakpoint message: no 'breakpoints' array found");
  }
  checkIntegrity();
}

SetMessage::~SetMessage() {}

Byte* SetMessage::serialize(Length & aLength) const
{
  ztd::auto_vec<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  std::string lJSONString = getData();
  Byte* lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '\0', getLength()+1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  const char * s = lJSONString.c_str();
  size_t l = lJSONString.length();
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg; 
}

std::string SetMessage::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{\"breakpoints\":[";
  std::map<unsigned int, QueryLoc>::const_iterator it;
  for(it = theLocations.begin(); it != theLocations.end(); it++)
  { 
    if (it != theLocations.begin())
    {
      lJSONString << ',';
    }
    lJSONString << "{\"id\":" << it->first << ",\"location\":"
      << debugger::queryLocToJSON(it->second) << "}";
  }

  std::map<unsigned int, zstring>::const_iterator it2;
  for(it2 = theExprs.begin(); it2 != theExprs.end(); it2++)
  {
    lJSONString << ",{\"id\":" << it2->first << ",\"expr\":\"" << it2->second << "\"}";
  }
  lJSONString << "]}";
  return lJSONString.str();
}

/**
 * Clear Breakpoints message
 */
ClearMessage::ClearMessage() : AbstractCommandMessage(BREAKPOINTS, CLEAR) {}

ClearMessage::ClearMessage(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength)
{
  json_t* lValue = getJsonValue(aMessage, aLength);
  json_t* lIds = json_object_get(lValue, "ids");
  if (lIds != 0) {
    int lSize = json_array_size(lIds);
    for (int i = 0; i < lSize; ++i) {
      json_t* lIdJ = json_array_get(lIds, i);
      theIds.push_back((unsigned int)(json_integer_value(lIdJ)));
    }
  } else {
    throw MessageFormatException("Invalid JSON format for Clear breakpoint message.");
  }
  checkIntegrity();
}

ClearMessage::~ClearMessage() {}

Byte* ClearMessage::serialize(Length & aLength) const
{
  ztd::auto_vec<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  std::string lJSONString = getData();
  Byte* lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '\0', getLength()+1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  const char * s = lJSONString.c_str();
  size_t l = lJSONString.length();
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg; 
}

std::string ClearMessage::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{\"ids\":[";
  std::vector<unsigned int>::const_iterator it;
  for(it = theIds.begin(); it != theIds.end(); it++)
  {
    if (it != theIds.begin())
    {
      lJSONString << ",";
    }
    lJSONString << *it;
  }
  lJSONString << "]}";
  return lJSONString.str();
}

/**
 * Started Engine Event
 */
StartedEvent::StartedEvent():
  AbstractCommandMessage(ENGINE_EVENT, STARTED) {}

StartedEvent::StartedEvent(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength)
{
    checkIntegrity();
}

StartedEvent::~StartedEvent() {}

/**
 * Terminated Engine Event
 */
TerminatedEvent::TerminatedEvent():
  AbstractCommandMessage(ENGINE_EVENT, TERMINATED) {}

TerminatedEvent::TerminatedEvent(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength) {}

TerminatedEvent::~TerminatedEvent() {}

/**
 * Suspended Engine Event
 */
SuspendedEvent::SuspendedEvent(const QueryLoc &aLocation, const SuspensionCause aCause) :
  AbstractCommandMessage(ENGINE_EVENT, SUSPENDED), theLocation(aLocation), theCause(aCause) 
{
  Length l = (Length)(MESSAGE_HEADER_SIZE + getData().length());
  setLength(l);
  checkIntegrity();
}

SuspendedEvent::SuspendedEvent(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength)
{
  json_t* lValue = getJsonValue(aMessage, aLength);
  json_t* lCause = json_object_get(lValue, "cause");
  json_t* lLocation = json_object_get(lValue, "location");

  if (lCause == 0) {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message: 'cause' not found");
  }
  theCause = (unsigned int)(json_integer_value(lCause));
  
  if (lLocation == 0) {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message.");
  }
  theLocation = debugger::fromJSONToQueryLoc(lLocation);
  checkIntegrity();
}

SuspendedEvent::~SuspendedEvent() {}

Byte* SuspendedEvent::serialize(Length & aLength) const
{
  ztd::auto_vec<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  std::string lJSONString = getData();
  Byte* lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '\0', getLength()+1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  const char * s = lJSONString.c_str();
  size_t l = lJSONString.length();
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg; 
}

QueryLoc SuspendedEvent::getLocation() const
{
  return theLocation;
}

SuspensionCause SuspendedEvent::getCause() const
{
  return theCause;
}

std::string SuspendedEvent::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{";
  lJSONString << "\"cause\":" << theCause << ",";
  lJSONString << "\"location\":" << debugger::queryLocToJSON(theLocation);
  lJSONString << "}";
  return lJSONString.str();
}

/**
 * Resumed Engine Event
 */
ResumedEvent::ResumedEvent():
  AbstractCommandMessage(ENGINE_EVENT, RESUMED) 
{
  checkIntegrity();
}

ResumedEvent::ResumedEvent(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength) {}

ResumedEvent::~ResumedEvent() {}

/**
 * Evaluated Engine Event
 */
EvaluatedEvent::EvaluatedEvent(int aId, zstring const &anExpr, zstring const &anError) :
  AbstractCommandMessage(ENGINE_EVENT, EVALUATED), theExpr(anExpr), theError(anError)
{
  setId(aId);
  
  Length l = (Length)(MESSAGE_HEADER_SIZE + getData().length());
  setLength(l);
  checkIntegrity();
}

EvaluatedEvent::EvaluatedEvent(int aId, zstring const &anExpr, list<pair<zstring, zstring> > valuesAndTypes) :
  AbstractCommandMessage(ENGINE_EVENT, EVALUATED), theExpr(anExpr), theValuesAndTypes(valuesAndTypes)
{
  setId(aId);

  list<pair<zstring, zstring> > lValues;
  list<pair<zstring, zstring> >::iterator it;
  for(it=theValuesAndTypes.begin(); it!=theValuesAndTypes.end(); it++)
  {
    zstring lFirst(it->first);
    zstring lSecond(it->second);

    ascii::replace_all(lFirst, "\"", "\\\"");
    ascii::replace_all(lFirst, "\\n", "\\\\n");
    ascii::replace_all(lFirst, "\\r", "\\\\r");
    ascii::replace_all(lFirst, "\\t", "\\\\t");

    ascii::replace_all(lSecond, "\"", "\\\"");
    ascii::replace_all(lSecond, "\\n", "\\\\n");
    ascii::replace_all(lSecond, "\\r", "\\\\r");
    ascii::replace_all(lSecond, "\\t", "\\\\t");

    lValues.push_back(std::make_pair(lFirst, lSecond));
  }
  theValuesAndTypes = lValues;
  Length l = (Length)(MESSAGE_HEADER_SIZE + getData().length());
  setLength(l);
  checkIntegrity();
}

EvaluatedEvent::EvaluatedEvent(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength)
{
  json_t* lValue = getJsonValue(aMessage, aLength);
  json_t* lExpr = json_object_get(lValue, "expr");
  json_t* lResults = json_object_get(lValue, "results");
  json_t* lError = json_object_get(lValue, "error");

  if (lExpr == 0) {
    throw MessageFormatException("Invalid JSON format for EvaluatedEvent message: 'expr' not found");
  }
  std::string lString = json_string_value(lExpr);
  deserializeString(lString);
  theExpr = lString;
  
  if (lResults == 0) {
    throw MessageFormatException("Invalid JSON format for EvaluatedEvent message: 'results' not found");
  }

  int lSize = json_array_size(lResults);
  for (int i = 0; i < lSize; ++i) {
    json_t* lResult = json_array_get(lResults, i);
    if (lResult == 0){
      throw MessageFormatException("Invalid JSON format for variable message: cound not retrieve one result");
    }

    json_t* lValue = json_object_get(lResult, "result");
    if (lValue == 0) {
      throw MessageFormatException("Invalid JSON format for variable message: 'result' not found");
    }
    std::string lValueStr = json_string_value(lValue);

    json_t* lType = json_object_get(lResult, "type");
    if (lType == 0) {
      throw MessageFormatException("Invalid JSON format for variable message: 'type' not found");
    }
    std::string lTypeStr = json_string_value(lType);

    deserializeString(lValueStr);
    deserializeString(lTypeStr);
    theValuesAndTypes.push_back(std::make_pair(lValueStr, lTypeStr));

    if (lError == 0) {
      throw MessageFormatException("Invalid JSON format for EvaluatedEvent message.");
    }
    std::string lErrorStr = json_string_value(lError);
    deserializeString(lErrorStr);
    theError = lErrorStr;
  }
  checkIntegrity();
}

EvaluatedEvent::~EvaluatedEvent() {}

zstring const& EvaluatedEvent::getExpr() const
{
  return theExpr;
}

list<pair<zstring, zstring> > EvaluatedEvent::getValuesAndTypes() const
{
  return theValuesAndTypes;
}

zstring const& EvaluatedEvent::getError() const
{
  return theError;
}

Byte* EvaluatedEvent::serialize(Length &aLength) const
{
  ztd::auto_vec<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  zstring lJSONString = getData();
  Byte* lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '0', getLength()+1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  const char * s = lJSONString.c_str();
  size_t l = lJSONString.length();
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg; 
}

zstring EvaluatedEvent::getData() const
{
  zstring lExpr = theExpr;

  ascii::replace_all(lExpr, "\"", "\\\"");
  ascii::replace_all(lExpr, "\\n", "\\\\n");
  ascii::replace_all(lExpr, "\\r", "\\\\r");
  ascii::replace_all(lExpr, "\\t", "\\\\t");

  zstring lErr = theError;

  ascii::replace_all(lErr, "\"", "\\\"");
  ascii::replace_all(lErr, "\\n", "\\\\n");
  ascii::replace_all(lErr, "\\r", "\\\\r");
  ascii::replace_all(lErr, "\\t", "\\\\t");

  std::stringstream lJSONString;
  lJSONString << "{";
  lJSONString << "\"id\":\"" << uint_swap(theHeaderContent->theId) << "\",";
  lJSONString << "\"expr\":\"" << lExpr << "\",";
  lJSONString << "\"results\":[";
  list<pair<zstring, zstring> >::const_iterator it = theValuesAndTypes.begin();
  for(; it != theValuesAndTypes.end(); it++)
  {
    if (it != theValuesAndTypes.begin())
    {
      lJSONString << ',';
    }
    lJSONString << "{\"result\":\"" << it->first << "\",\"type\":\"" << it->second << "\"}";
  }
  lJSONString << "],";
  lJSONString << "\"error\":\"" << lErr << "\"";
  lJSONString << "}";
  zstring lData(lJSONString.str());
  return lData;
}

void EvaluatedEvent::setId(Id aId)
{
  AbstractMessage::setId(aId);
}

/**
 * Eval Message
 */
EvalMessage::EvalMessage(zstring const &anExpr) :
  AbstractCommandMessage(DYNAMIC, EVAL),
  theExpr(anExpr)
{
    Length l = (Length)(MESSAGE_HEADER_SIZE + getData().length());
    setLength(l);

    checkIntegrity();
}

EvalMessage::EvalMessage(Byte* aMessage, const unsigned int aLength) :
  AbstractCommandMessage(aMessage, aLength)
{
  json_t* lValue = getJsonValue(aMessage, aLength);
  json_t* lExpr = json_object_get(lValue, "expr");
  if (lExpr == 0) {
    throw MessageFormatException("Invalid JSON format for eval command message: 'expr' not found");
  }
  std::string lExprStr(json_string_value(lExpr));
  theExpr = lExprStr;
  ascii::replace_all(theExpr, "\\\"", "\"");

  checkIntegrity();
}

EvalMessage::~EvalMessage() {}

zstring EvalMessage::getData() const
{
  zstring lExpr = theExpr;
  ascii::replace_all(lExpr, "\"", "\\\"");
  std::stringstream lJSONString;
  lJSONString << "{";
  lJSONString << "\"expr\":\"" << lExpr << "\"";
  lJSONString << "}";
  zstring lReturnString(lJSONString.str());
  return lReturnString;
}

Byte* EvalMessage::serialize(Length & aLength) const
{
  ztd::auto_vec<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  zstring lJSONString = getData();
  Byte* lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '0', getLength()+1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  const char * s = lJSONString.c_str();
  size_t l = lJSONString.length();
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg; 
}

zstring EvalMessage::getExpr() const
{
  return theExpr;
}

VariableMessage::VariableMessage(bool dataFlag)
  : AbstractCommandMessage(DYNAMIC, VARIABLES, dataFlag ? VARIABLE_DATA_FLAG : NULL_FLAG), theDataFlag(dataFlag)
{
  checkIntegrity();
}

VariableMessage::VariableMessage(Byte* aMessage, const unsigned int aLength):
  AbstractCommandMessage(aMessage, aLength)
{
  theDataFlag = aMessage[MESSAGE_FLAGS_FIELD_INDEX] == VARIABLE_DATA_FLAG;
}

VariableMessage::~VariableMessage() {}

/**
 * Frame Message
 */
FrameMessage::FrameMessage(): AbstractCommandMessage(DYNAMIC, FRAME) {}

FrameMessage::FrameMessage(Byte* aMessage, const unsigned int aLength)
  : AbstractCommandMessage(aMessage, aLength) {}

FrameMessage::~FrameMessage() {}

/**
 * Frame Reply
 */
FrameReply::FrameReply(const Id anId, const ErrorCode aErrorCode,
                       std::stack< std::pair<std::string, QueryLoc> >  aStack)
  : ReplyMessage(anId, aErrorCode), theStack(aStack)
{
  setFlags(REPLY_FRAME_FLAG);
  Length l = (Length)(MESSAGE_HEADER_SIZE + getData().length());
  setLength(l);
  checkIntegrity();
}

FrameReply::FrameReply(Byte* aMessage, const unsigned int aLength)
  : ReplyMessage(aMessage, aLength)
{
  setFlags(REPLY_FRAME_FLAG);
  json_t* lValue = getJsonValue(aMessage, aLength);
  json_t* lFrame = json_object_get(lValue, "frame");
  if (lFrame == 0) {
    throw MessageFormatException("Invalid JSON format for stack frame messsage: 'frame' not found");
  }

  int lSize = json_array_size(lFrame);
  for (int i = 0; i < lSize; ++i) {
    json_t* lCurr = json_array_get(lFrame, i);
    json_t* lLocJ = json_object_get(lCurr, "location");
    if (lLocJ == 0) {
      throw MessageFormatException("Invalid JSON format for Stack: 'location' not found");
    }
    QueryLoc lLoc = debugger::fromJSONToQueryLoc(lLocJ);

    json_t* lLabel = json_object_get(lCurr, "label");
    if (lLabel == 0) {
      throw MessageFormatException("Invalid JSON format for Stack: 'label' not found");
    }
    std::string lLabelStr = json_string_value(lLabel);
    theStack.push(std::make_pair<std::string, const QueryLoc>(lLabelStr, lLoc));
  }
}

zstring FrameReply::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{\"frame\":[";
  std::stack< std::pair<std::string, QueryLoc> > lStack(theStack);
  while(!lStack.empty())
  {
    if (lStack.size() != theStack.size())
    {
      lJSONString << ",";
    }
    std::pair<std::string, QueryLoc> it = lStack.top();
    lJSONString << "{\"label\":\"" << it.first << "\",\"location\":"
      << debugger::queryLocToJSON(it.second) << "}";
    lStack.pop();
  }
  lJSONString << "]}";
  return lJSONString.str();
}

Byte* FrameReply::serialize(Length& aLength) const
{
  ztd::auto_vec<Byte> lHeader(ReplyMessage::serialize(aLength));
  zstring lJSON = getData();
  const char* s = lJSON.c_str();
  size_t l = lJSON.length();
  Byte* lMsg = new Byte[MESSAGE_HEADER_SIZE + l + 1];
  memset(lMsg, '0', MESSAGE_HEADER_SIZE + l + 1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg;
}


/**
 * Set Breakpoint reply message
 */
SetReply::SetReply(const Id anId, const ErrorCode aErrorCode):
  ReplyMessage(anId, aErrorCode)
{
  setFlags(REPLY_SET_FLAG);
  Length l = (Length)(MESSAGE_HEADER_SIZE + getData().length());
  setLength(l);
  checkIntegrity();
}

SetReply::SetReply(Byte* aMessage, const unsigned int aLength)
  : ReplyMessage(aMessage, aLength)
{
  setFlags(REPLY_SET_FLAG);
  json_t* lValue = getJsonValue(aMessage, aLength);
  json_t* lBreakpoints = json_object_get(lValue, "breakpoints");
  if (lBreakpoints == 0) {
    throw MessageFormatException("Invalid JSON format for breakpoint reply message: 'breakpoints' not found");
  }
  int lSize = json_array_size(lBreakpoints);
  for(int i = 0; i < lSize; ++i) {
    json_t* lCurr = json_array_get(lBreakpoints, i);
    json_t* lLocJ = json_object_get(lCurr, "location");
    if (lLocJ == 0) {
      throw MessageFormatException("Invalid JSON format for breakpoint reply message: 'location' not found");
    }
    QueryLoc lLoc = debugger::fromJSONToQueryLoc(lLocJ);

    json_t* lIdJ = json_object_get(lCurr, "id");
    if (lIdJ == 0) {
      throw MessageFormatException("Invalid JSON format for Set breakpoint reply message: 'id' not found");
    }
    unsigned int lId = (unsigned int)json_integer_value(lIdJ);
    theBreakpoints.insert(std::make_pair(lId, lLoc));
  }
}

SetReply::~SetReply() {}

zstring SetReply::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{\"breakpoints\":[";
  std::map<unsigned int, QueryLoc>::const_iterator it;
  for(it = theBreakpoints.begin(); it != theBreakpoints.end(); ++it) { 
    if (it != theBreakpoints.begin()) {
      lJSONString << ',';
    }
    lJSONString << "{\"id\":" << it->first << ",\"location\":"
      << debugger::queryLocToJSON(it->second) << "}";
  }
  lJSONString << "]}";
  return lJSONString.str();
}

Byte* SetReply::serialize(Length& aLength) const
{
  ztd::auto_vec<Byte> lHeader(ReplyMessage::serialize(aLength));
  zstring lJSONString = getData();
  const char * s = lJSONString.c_str();
  size_t l = lJSONString.length();
  Byte* lMsg = new Byte[ MESSAGE_HEADER_SIZE + l + 1 ];
  memset(lMsg, '0', MESSAGE_HEADER_SIZE + l + 1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg; 
}

void SetReply::addBreakpoint(unsigned int anId, QueryLoc& aLocation)
{
  theBreakpoints.insert(std::make_pair<unsigned int, QueryLoc>(anId, aLocation));
  setLength((Length)(MESSAGE_HEADER_SIZE + getData().length()));
}

/**
 * Variable Reply Message
 */
VariableReply::VariableReply(const Id anId, const ErrorCode aErrorCode, bool containsData) :
  ReplyMessage(anId, aErrorCode), theContainsData(containsData)
{
  setFlags(theContainsData ? REPLY_VARIABLE_FLAG | VARIABLE_DATA_FLAG : REPLY_VARIABLE_FLAG);
  Length l = (Length)(MESSAGE_HEADER_SIZE + getData().length());
  setLength(l);
  checkIntegrity();
}

VariableReply::VariableReply(Byte* aMessage, const unsigned int aLength)
  : ReplyMessage(aMessage, aLength),
    theContainsData(false)
{
  theContainsData = (aMessage[MESSAGE_FLAGS_FIELD_INDEX] & VARIABLE_DATA_FLAG) != 0;
  setFlags(REPLY_VARIABLE_FLAG);
  json_t* lJson = getJsonValue(aMessage, aLength);
  json_t* lGlobals = json_object_get(lJson, "globals");
  json_t* lLocals = json_object_get(lJson, "locals");

  if (lGlobals == 0) {
    throw MessageFormatException("Invalid JSON format for variable message: 'globals' not found");
  }

  int lSize = json_array_size(lGlobals);
  for (int i = 0; i < lSize; ++i) {
    json_t* lCurr = json_array_get(lGlobals, i);

    json_t* lNameJ = json_object_get(lCurr, "name");
    if (lNameJ == 0) {
      throw MessageFormatException("Invalid JSON format for variable message: 'name' not found");
    }
    std::string lNameStr = json_string_value(lNameJ);

    json_t* lTypeJ = json_object_get(lCurr, "type");
    if (lTypeJ == 0) {
      throw MessageFormatException("Invalid JSON format for variable message: 'type' not found");
    }
    std::string lTypeStr = json_string_value(lTypeJ);

    json_t* lValueJ = json_object_get(lCurr, "value");
    if (lValueJ == 0 && theContainsData) {
      throw MessageFormatException("Invalid JSON format for variable message: 'value' object not found");
    }
    if (theContainsData) {
      std::list<std::pair<zstring, zstring> > lData;

      int lValueSize = json_array_size(lValueJ);
      for (int j = 0; i < lValueSize; ++j) {
        json_t* lCurrValue = json_array_get(lValueJ, j);
        json_t* lV = json_object_get(lCurrValue, "value");
        if (lV == 0) {
          throw MessageFormatException("Invalid JSON format for variable message: 'value' string not found");
        }
        std::string lVStr(json_string_value(lV));

        json_t* lT = json_object_get(lCurrValue, "type");
        if (lT == 0) {
          throw MessageFormatException("Invalid JSON format for variable message: 'type' string not found");
        }
        std::string lTStr(json_string_value(lT));

        lData.push_back(std::pair<zstring, zstring>(lVStr, lTStr));
      }
      addGlobal(lNameStr, lTypeStr, lData);
    } else {
      addGlobal(lNameStr, lTypeStr);
    }
  }

  if (lLocals == 0) {
    throw MessageFormatException("Invalid JSON format for variable message: 'locals' not found");
  }

  lSize = json_array_size(lLocals);
  for (int i = 0; i < lSize; ++i) {
    json_t* lCurr = json_array_get(lLocals, i);

    json_t* lNameJ = json_object_get(lCurr, "name");
    if (lNameJ == 0) {
      throw MessageFormatException("Invalid JSON format for variable message: 'name' not found");
    }
    std::string lNameStr = json_string_value(lNameJ);

    json_t* lTypeJ = json_object_get(lCurr, "type");
    if (lTypeJ == 0) {
      throw MessageFormatException("Invalid JSON format for variable message: 'type' not found");
    }
    std::string lTypeStr = json_string_value(lTypeJ);

    json_t* lValueJ = json_object_get(lCurr, "value");
    if (lValueJ == 0 && theContainsData) {
      throw MessageFormatException("Invalid JSON format for variable message: 'value' object not found");
    }
    if (theContainsData) {
      std::list<std::pair<zstring, zstring> > lData;

      int lValueSize = json_array_size(lValueJ);
      for (int j = 0; i < lValueSize; ++j) {
        json_t* lCurrValue = json_array_get(lValueJ, j);
        json_t* lV = json_object_get(lCurrValue, "value");
        if (lV == 0) {
          throw MessageFormatException("Invalid JSON format for variable message: 'value' string not found");
        }
        std::string lVStr(json_string_value(lV));

        json_t* lT = json_object_get(lCurrValue, "type");
        if (lT == 0) {
          throw MessageFormatException("Invalid JSON format for variable message: 'type' string not found");
        }
        std::string lTStr(json_string_value(lT));

        lData.push_back(std::pair<zstring, zstring>(lVStr, lTStr));
      }
      addLocal(lNameStr, lTypeStr, lData);
    } else {
      addLocal(lNameStr, lTypeStr);
    }
  }
} 

VariableReply::~VariableReply() {}

zstring VariableReply::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{";
  lJSONString << "\"globals\":[";
  std::map<zstring, zstring>::const_iterator it = theGlobals.begin();
  long pos = 0;
  for(; it != theGlobals.end(); it++)
  {
    if (it != theGlobals.begin())
    {
      lJSONString << ',';
    }
    if (theContainsData) {
      zstring vString;
      for (std::list<std::pair<zstring, zstring> >::const_iterator iter = theGlobalData[pos].begin(); 
        iter != theGlobalData[pos].end(); it++) {
          if (iter != theGlobalData[pos].begin()) {
            vString += ",";
          }
          vString += "{\"value\":\"" + iter->first + "\",\"type\":\"" + iter->second + "\"}";
      }
      lJSONString << "{\"name\":\"" << it->first << "\",\"type\":\"" << it->second << "\",\"value\":" 
        << "[" << vString << "]}";
    } else {
      lJSONString << "{\"name\":\"" << it->first << "\",\"type\":\"" << it->second << "\"}";
    }
    ++pos;
  }
  lJSONString << "],\"locals\":[";
  std::map<zstring, zstring>::const_iterator lIter;
  pos = 0;
  for(lIter = theLocals.begin(); lIter != theLocals.end(); ++lIter)
  {
    if (lIter != theLocals.begin())
    {
      lJSONString << ',';
    }
    if (theContainsData) {
      zstring vString;
      for (std::list<std::pair<zstring, zstring> >::const_iterator iter = theLocalData[pos].begin(); 
        iter != theLocalData[pos].end(); iter++) {
          if (iter != theLocalData[pos].begin()) {
            vString += ",";
          }
          vString += "{\"value\":\"" + iter->first + "\",\"type\":\"" + iter->second + "\"}";
      }
      lJSONString << "{\"name\":\"" << lIter->first << "\",\"type\":\"" << lIter->second << "\",\"value\":" 
        << "[" << vString << "]}";
    } else {
      lJSONString << "{\"name\":\"" << lIter->first << "\",\"type\":\"" << lIter->second << "\"}";
    }
    ++pos;
  }
  lJSONString << "]}";
  zstring lReturnString(lJSONString.str());
  return lReturnString;
}

Byte* VariableReply::serialize(Length & aLength) const
{
  ztd::auto_vec<Byte> lHeader(ReplyMessage::serialize(aLength));
  zstring lJSONString = getData();
  const char * s = lJSONString.c_str();
  size_t l = lJSONString.length();
  Byte* lMsg = new Byte[ MESSAGE_HEADER_SIZE + l + 1 ];
  memset(lMsg, '0', MESSAGE_HEADER_SIZE + l + 1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg; 
}

std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > > VariableReply::getVariables() const
{
  std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > > lVariables;
  unsigned int pos = 0;
  for (std::map<zstring, zstring>::const_iterator it = theGlobals.begin(); it != theGlobals.end(); it++) {
    std::pair<zstring, zstring> p = *it;
    std::list<std::pair<zstring, zstring> > l;
    if (theContainsData) {
      l = theGlobalData[pos];
    }
    lVariables.insert(std::pair<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > >(p, l));
    ++pos;
  }
  pos = 0;
  for (std::map<zstring, zstring>::const_iterator it = theLocals.begin(); it != theLocals.end(); it++) {
    std::pair<zstring, zstring> p = *it;
    std::list<std::pair<zstring, zstring> > l;
    if (theContainsData) {
      l = theLocalData[pos];
    }
    lVariables.insert(std::pair<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > >(p, l));
    ++pos;
  }
  return lVariables;
}

std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > > VariableReply::getLocalVariables() const
{
  std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > > lVariables;
  unsigned int pos = 0;
  for (std::map<zstring, zstring>::const_iterator it = theLocals.begin(); it != theLocals.end(); it++) {
    std::pair<zstring, zstring> p = *it;
    std::list<std::pair<zstring, zstring> > l;
    if (theContainsData) {
      l = theGlobalData[pos];
    }
    lVariables.insert(std::pair<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > >(p, l));
    ++pos;
  }
  return lVariables;
}

std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > > VariableReply::getGlobalVariables() const
{
  std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > > lVariables;
  unsigned int pos = 0;
  for (std::map<zstring, zstring>::const_iterator it = theGlobals.begin(); it != theGlobals.end(); it++) {
    std::pair<zstring, zstring> p = *it;
    std::list<std::pair<zstring, zstring> > l;
    if (theContainsData) {
      l = theGlobalData[pos];
    }
    lVariables.insert(std::pair<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > >(p, l));
    ++pos;
  }
  return lVariables;
}

void VariableReply::addGlobal(zstring const &aVariable, zstring const &aType)
{
  theGlobals.insert(std::make_pair(aVariable, aType));
  setLength((Length)(MESSAGE_HEADER_SIZE + getData().length()));
}

void VariableReply::addGlobal(zstring const &aVariable, zstring const &aType, std::list<std::pair<zstring, zstring> > val)
{
  theGlobals.insert(std::make_pair(aVariable, aType));
  theGlobalData.push_back(val);
  setLength((Length)(MESSAGE_HEADER_SIZE + getData().length()));
}

void VariableReply::addLocal(zstring const &aVariable, zstring const &aType)
{
  theLocals.insert(std::make_pair(aVariable, aType));
  setLength((Length)(MESSAGE_HEADER_SIZE + getData().length()));
}

void VariableReply::addLocal(zstring const &aVariable, zstring const &aType, std::list<std::pair<zstring, zstring> > val)
{
  theLocals.insert(std::make_pair(aVariable, aType));
  theLocalData.push_back(val);
  setLength((Length)(MESSAGE_HEADER_SIZE + getData().length()));
}

/**
* List command
*/
ListCommand::ListCommand(Byte* aMessage, const unsigned int aLength) :
AbstractCommandMessage(aMessage, aLength)
{
  json_t* lJson = getJsonValue(aMessage, aLength);
  json_t* lFilenameJ = json_object_get(lJson, "filename");
  if (lFilenameJ != 0) {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message: 'filename' not found");
  }
  std::string lFilenameStr(json_string_value(lFilenameJ));
  theFilename = lFilenameStr;

  json_t* lFirstlineJ = json_object_get(lJson, "firstline");
  if (lFirstlineJ != 0) {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message: 'firstline' not found");
  }
  theFirstLine = (unsigned long)json_integer_value(lFirstlineJ);

  json_t* lLastlineJ = json_object_get(lJson, "lastline");
  if (lLastlineJ != 0) {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message: 'firstline' not found");
  }
  theLastLine = (unsigned long)json_integer_value(lLastlineJ);
}

ListCommand::ListCommand(std::string aFilename,
                         unsigned long aFirstline,
                         unsigned long aLastline) :
AbstractCommandMessage(STATIC, LIST),
theFilename(aFilename),
theFirstLine(aFirstline),
theLastLine(aLastline)
{
  Length l = (Length)(MESSAGE_HEADER_SIZE + getData().length());
  setLength(l);
  checkIntegrity();
}

ListCommand::~ListCommand()
{
}

Byte* ListCommand::serialize(Length& aLength) const
{
  ztd::auto_vec<Byte> lHeader(
    AbstractCommandMessage::serialize(aLength));
  std::string lJSONString = getData();
  Byte* lMsg = new Byte[getLength() + 1];
  memset(lMsg, '0', getLength() + 1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  const char * s = lJSONString.c_str();
  size_t l = lJSONString.length();
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg;
}

std::string ListCommand::getData() const
{
  std::string lFileName;
  std::string::const_iterator lIter;
  for (lIter = theFilename.begin(); lIter != theFilename.end(); ++lIter) {
    if (*lIter == '\\') {
      lFileName += "\\\\";
    } else {
      lFileName += *lIter;
    }
  }
  std::stringstream lStream;
  lStream << "{" << std::endl;
  lStream << "\"filename\":\"" << lFileName << "\",";
  lStream << "\"firstline\":\"" << theFirstLine << "\",";
  lStream << "\"lastline\":\"" << theLastLine << "\"";
  lStream << "}";
  return lStream.str();
}

std::string ListCommand::getFilename() const
{
  return theFilename;
}

unsigned long ListCommand::getFirstline() const
{
  return theFirstLine;
}

unsigned long ListCommand::getLastline() const
{
  // if the last line is set to 0, return just the biggest possible number,
  // so the file will be read to the end.
  return theLastLine == 0 ? -1 : theLastLine;
}

ListReply::ListReply(const Id aId,
                     const ErrorCode aErrorCode,
                     const std::string& aCode) :
ReplyMessage(aId, aErrorCode), theString(aCode)
{
  setFlags(REPLY_LIST_FLAG);
  Length l = (Length)(MESSAGE_HEADER_SIZE + getData().length());
  setLength(l);
  checkIntegrity();
}

ListReply::ListReply(Byte* aMessage, const unsigned int aLength) :
ReplyMessage(aMessage, aLength)
{
  setFlags(REPLY_LIST_FLAG);
  json_t* lJson = getJsonValue(aMessage, aLength);
  json_t* lCodeJ = json_object_get(lJson, "code");
  if (lCodeJ == 0) {
    throw MessageFormatException("Invalid JSON format for List reply message: 'code' not found");
  }
  std::string lCodeStr(json_string_value(lCodeJ));
  deserializeString(lCodeStr);
  theString = lCodeStr;
}

ListReply::~ListReply() {}

Byte* ListReply::serialize(Length &aLength) const
{
  ztd::auto_vec<Byte> lHeader(ReplyMessage::serialize(aLength));
  zstring lJSONString = getData();
  const char * s = lJSONString.c_str();
  size_t l = lJSONString.length();
  Byte* lMsg = new Byte[ MESSAGE_HEADER_SIZE + l + 1 ];
  memset(lMsg, '0', MESSAGE_HEADER_SIZE + l + 1);
  memcpy(lMsg, lHeader.get(), MESSAGE_HEADER_SIZE);
  memcpy(lMsg + MESSAGE_HEADER_SIZE, s, l);
  aLength = getLength();
  return lMsg; 
}

std::string ListReply::getData() const
{
  std::stringstream lJSONString;
  std::string lTmp;  
  std::string::const_iterator lIter;
  for (lIter = theString.begin(); lIter != theString.end(); lIter++) {
    if (*lIter == '"') {
      lTmp += "\\\"";
    } else {
      lTmp += *lIter;
    }
  }

  lJSONString << "{\"code\":\"" << lTmp << "\"}";
  return lJSONString.str();
}

ReplyMessage * ListReply::getReplyMessage()
{
  ReplyMessage * lReply =  new ReplyMessage(getId(), DEBUGGER_NO_ERROR);
  lReply->setData(getData());
  return lReply;
}

std::string ListReply::getString() const
{
  return theString;
}

void ListReply::setString(std::string const &aString)
{
  theString = aString;
}
} // namespace zorba
/* vim:set et sw=2 ts=2: */

