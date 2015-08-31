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
#ifndef ZORBA_SERVER_API_EVALUATION_H_
#define ZORBA_SERVER_API_EVALUATION_H_

#include "io/request.h"
#include "io/response.h"

namespace zorba
{
namespace server
{
namespace api
{
  class Evaluation
  {
    public:
    static void handleRequest(const io::Request& aRequest, io::Response& aResponse);

    private:
    static void evaluate(const io::Request& aRequest, io::Response& aResponse);
  };
}
}
}

#endif
