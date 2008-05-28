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
#ifndef ZORBA_ERRORS_ERROR_MESSAGES_H
#define ZORBA_ERRORS_ERROR_MESSAGES_H

#include <string>
#include <zorba/error.h>
#include "zorbatypes/zorbatypesError.h"

namespace zorba {  namespace error {

XQUERY_ERROR
DecodeZorbatypesError(::zorba::ZorbatypesError::ErrorCode code);


/*******************************************************************************

********************************************************************************/
class ErrorMessages
{
 public:
  virtual ~ErrorMessages() { }

  static XQUERY_ERROR getErrorCodeForName(const std::string& name); 

  static std::string getNameForErrorCode(const XQUERY_ERROR&);

  static std::string getMessageForErrorCode(const XQUERY_ERROR&);
  static std::string getMessageForWarningCode(ZorbaWarning::WarningCode&);
};


} /* namespace error */
} /* namespace zorba */
#endif
