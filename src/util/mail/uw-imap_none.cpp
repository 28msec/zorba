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
#include "util/mail/uw-imap.h"
#include "zorbaerrors/error_manager.h"

namespace zorba
{

bool mail(const char* to, const char* subject, const char* message,
          const char* SMTPServer, const char* SMTPUser, const char* SMTPPwd,
          xqp_string& diagnostics)
{
  ZORBA_ERROR_PARAM(  XQP0004_SYSTEM_NOT_SUPPORTED, "MAIL" , "");

  return 0;
}
} // namespace zorba
