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
#ifndef XQP_ERROR_MANAGER_H
#define XQP_ERROR_MANAGER_H

#include <vector>
#include <sstream>

#include <zorba/error.h>
#include "zorbaerrors/errors.h"

namespace zorba { namespace error {

class ErrorManager
{
 protected:
  // contains all errors that were raised but the execution went on
  std::vector<ZorbaError>    theErrors;

  // contains all the warnings
  std::vector<ZorbaWarning>  theWarnings;

public:

  static ZorbaError
  createException(
        XQUERY_ERROR        aErrorCode,
        const std::string&  aFileName,
        int                 aLineNumber);

  static ZorbaError
  createException(
        XQUERY_ERROR        aErrorCode,
        const std::string&  aFileName,
        int                 aLineNumber, 
        unsigned int        aQueryLine,
        unsigned int        aQueryColumn,
        const std::string&  aQueryFileName);


  static ZorbaError
  createException(
        XQUERY_ERROR        aErrorCode,
        const std::string&  aParam1,
        const std::string&  aParam2,
        const std::string&  aFileName,
        int                 aLineNumber,
        unsigned int        aQueryLine = 0,
        unsigned int        aQueryColumn = 0,
        const std::string&  aQueryFileName = "");


  static ZorbaError
  createException(
        XQUERY_ERROR        aErrorCode,
        const std::string&  aDescription, 
        const std::string&  aFileName,
        int                 aLineNumber);

  static ZorbaError
  createException(
        XQUERY_ERROR        aErrorCode,
        const xqpString&    aDescription,
        const std::string&  aFileName,
        int                 aLineNumber,
        unsigned int        aQueryLine,
        unsigned int        aQueryColumn,
        const std::string&  aQueryFileName);

protected:

  static void applyParams(
        std::string*        errorMsg,
        const std::string*  param1,
        const std::string*  param2);
  
  static std::string::size_type applyParam(
        std::string*           errorMsg,
        const std::string*     param1,
        std::string::size_type start);

public:

  ErrorManager();

  virtual ~ErrorManager();

  void
  addError(
        XQUERY_ERROR        aErrorCode,
        const xqpString&    aDescription,
        const std::string&  aFileName,
        int                 aLineNumber,
        unsigned int        aQueryLine = 0,
        unsigned int        aQueryColumn = 0,
        const std::string&  aQueryFileName = "");

  void
  addError(
        XQUERY_ERROR        aErrorCode, 
        const std::string&  aParam1,
        const std::string&  aParam2,
        const std::string&  aFileName,
        int                 aLineNumber,
        unsigned int        aQueryLine = 0,
        unsigned int        aQueryColumn = 0,
        const std::string&  aQueryFileName = "");

  void
  addWarning(
        ZorbaWarning::WarningCode aWarningCode,
        const xqpString&          aDescription,
        const std::string&        aFileName,
        int                       aLineNumber,
        unsigned int              aQueryLine = 0,
        unsigned int              aQueryColumn = 0,
        const std::string&        aQueryFileName = "");

  bool
  hasErrors() { return theErrors.size() != 0; }

  std::vector<ZorbaError>&
  getErrors() { return theErrors; }
};


//
// create an exception and throw it
//

#define ZORBA_ERROR(code)                                                 \
  do                                                                      \
  {                                                                       \
    throw error::ErrorManager::createException(code, __FILE__, __LINE__); \
  } while (0)
 

#define ZORBA_ERROR_LOC(code, loc)                                       \
  do                                                                     \
  {                                                                      \
    throw error::ErrorManager::createException(code, __FILE__, __LINE__, \
                                               (loc).getLineBegin(),     \
                                               (loc).getColumnBegin(),   \
                                               (loc).getFilenameBegin());\
  } while (0 )


#define ZORBA_ERROR_DESC_OSS(code, desc)                                \
  do                                                                    \
  {                                                                     \
    std::ostringstream lOStringStream;                                  \
    lOStringStream << desc;                                             \
    throw error::ErrorManager::createException(code,                    \
                                               lOStringStream.str(),    \
                                               __FILE__, __LINE__);     \
  } while (0) 


#define ZORBA_ERROR_DESC(code, desc) \
  ZORBA_ERROR_DESC_OSS (code, (desc))


#define ZORBA_ERROR_LOC_DESC_OSS(code, loc, descr)                        \
  do                                                                      \
  {                                                                       \
    std::ostringstream lOStringStream;                                    \
    lOStringStream << descr;                                              \
    throw error::ErrorManager::createException(code,                      \
                                               lOStringStream.str(),      \
                                               __FILE__, __LINE__,        \
                                               (loc).getLineBegin(),      \
                                               (loc).getColumnBegin(),    \
                                               (loc).getFilenameBegin()); \
  } while (0) 

#define ZORBA_ERROR_LOC_DESC(code, loc, desc) \
  ZORBA_ERROR_LOC_DESC_OSS(code, loc, (desc))


//
// create an exception, replace params, and throw it
//

#define ZORBA_ERROR_PARAM_OSS(code, param1, param2)                     \
  do                                                                    \
  {                                                                     \
  std::ostringstream lOStringStream1, lOStringStream2;                  \
  lOStringStream1 << param1;                                            \
  lOStringStream2 << param2;                                            \
  throw error::ErrorManager::createException(code,                      \
                                             lOStringStream1.str(),     \
                                             lOStringStream2.str(),     \
                                             __FILE__, __LINE__);       \
  } while (0) 


#define ZORBA_ERROR_LOC_PARAM_OSS(code, loc, param1, param2)              \
  do                                                                      \
  {                                                                       \
    std::ostringstream lOStringStream1, lOStringStream2;                  \
    lOStringStream1 << param1;                                            \
    lOStringStream2 << param2;                                            \
    throw error::ErrorManager::createException(code,                      \
                                               lOStringStream1.str(),     \
                                               lOStringStream2.str(),     \
                                               __FILE__, __LINE__,        \
                                               (loc).getLineBegin(),      \
                                               (loc).getColumnBegin(),    \
                                               (loc).getFilenameBegin()); \
  } while (0) 


#define ZORBA_ERROR_PARAM(code, param1, param2) \
  ZORBA_ERROR_PARAM_OSS(code, (param1), (param2))


#define ZORBA_ERROR_LOC_PARAM(code, loc, param1, param2) \
  ZORBA_ERROR_LOC_PARAM_OSS(code, (loc), (param1), (param2))


//
// create an error, remeber it, and continue
//

#define ZORBA_ERROR_DESC_CONTINUE(manager, code,  desc) \
  do                                                    \
  {                                                     \
    manager->addError(code, desc, __FILE__, __LINE__);  \
  } while (0) 


//
// create an error, replace params, and continue
//

#define ZORBA_ERROR_PARAM_CONTINUE_OSS(manager, code, param1, param2)   \
  do                                                                    \
  {                                                                     \
    std::ostringstream lOStringStream1, lOStringStream2;                \
    lOStringStream1 << param1;                                          \
    lOStringStream2 << param2;                                          \
    manager->addError(code,                                             \
                      lOStringStream1.str(),                            \
                      lOStringStream2.str(),                            \
                      __FILE__, __LINE__);                              \
  } while (0) 


#define ZORBA_ERROR_LOC_PARAM_CONTINUE_OSS(manager, code, loc, param1, param2) \
  do                                                                    \
  {                                                                     \
    std::ostringstream lOStringStream1, lOStringStream2;                \
    lOStringStream1 << param1;                                          \
    lOStringStream2 << param2;                                          \
    throw manager->addError(code,                                       \
                            lOStringStream1.str(),                      \
                            lOStringStream2.str(),                      \
                            __FILE__, __LINE__,                         \
                            (loc).getLineBegin(),                       \
                            (loc).getColumnBegin(),                     \
                            (loc).getFilenameBegin());                  \
  } while (0) 


#define ZORBA_ERROR_PARAM_CONTINUE(manager, code, param1, param2) \
  ZORBA_ERROR_PARAM_CONTINUE_OSS(manager, code, (param1), (param2))


#define ZORBA_ERROR_LOC_PARAM_CONTINUE(manager, code, loc, param1, param2) \
  ZORBA_ERROR_PARAM_LOC_CONTINUE_OSS(manager, code, loc, (param1), (param2))


//
// create a warning and continue
//

#define ZORBA_WARNING(manager, code, desc, loc)                         \
  do                                                                    \
  {                                                                     \
    manager->addWarning(ZorbaWarning::code, desc, __FILE__, __LINE__,   \
                        (loc).getLineBegin(),                           \
                        (loc).getColumnBegin(),                         \
                        (loc).getFilenameBegin());                      \
  } while (0) 


//
//
//

#define ZORBA_NOT_IMPLEMENTED( what )                                 \
  do                                                                  \
  {                                                                   \
    ZORBA_ERROR_DESC(XQP0004_SYSTEM_NOT_SUPPORTED, what); \
  } while (0) 
 

#define ZORBA_NOT_SUPPORTED( what )                                   \
  do                                                                  \
  {                                                                   \
    ZORBA_ERROR_DESC(XQP0004_SYSTEM_NOT_SUPPORTED, what); \
  } while (0) 


} /* namespace error */
} /* namespace zorba */
#endif
