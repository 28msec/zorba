/*
 * Copyright 2015 Federico Cavalieri.
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
#ifndef SERVER_EXCEPTIONS_FORMATTER_H
#define SERVER_EXCEPTIONS_FORMATTER_H

#include "utils/JSONObject.h"

namespace zorba
{
namespace server
{
namespace exceptions
{

class Formatter
{
public:
  static void formatException(const std::exception& aException, zorba::Item& aFormattedException, int& aStatusCode);
  static void formatZorbaException(const zorba::ZorbaException& aZorbaException, utils::JSONObject& aFormattedException, int& aStatusCode);
  static void formatServerException(const exceptions::ServerException& aServerException, utils::JSONObject& aFormattedException, int& aStatusCode);
};

}
}
}
#endif



