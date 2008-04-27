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
#include "util/web/web.h"
#include "errors/error_manager.h"

namespace zorba
{
  
int http_get(const char* url, xqp_string& result)
{
  ZORBA_ERROR(  ZorbaError::XQP0004_SYSTEM_NOT_SUPPORTED );

  return 0;
}

} // namespace zorba
