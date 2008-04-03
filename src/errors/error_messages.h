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
