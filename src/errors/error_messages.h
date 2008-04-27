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
#ifndef XQP_ERROR_MESSAGES_H
#define XQP_ERROR_MESSAGES_H

#include <string>
#include "errors/errors.h"
#include "zorbatypes/zorbatypesError.h"

namespace zorba {  namespace error {

::zorba::ZorbaError::ErrorCode DecodeZorbatypesError(::zorba::ZorbatypesError::ErrorCode code);

class AlertMessages
{
 public:
   virtual ~AlertMessages() { }

   virtual std::string error_decode(::zorba::ZorbaError::ErrorCode&) = 0;
   virtual std::string warning_decode(ZorbaWarning::WarningCode&) = 0;

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
      std::string error_decode(::zorba::ZorbaError::ErrorCode&);
      std::string warning_decode(ZorbaWarning::WarningCode&);
  };


} /* namespace error */
} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
