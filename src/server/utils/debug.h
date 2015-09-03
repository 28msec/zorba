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
#ifndef ZORBA_SERVER_UTILS_DEBUG_H_
#define ZORBA_SERVER_UTILS_DEBUG_H_

#include <string>
#include <sstream>

//#define DISABLE_DEBUG

#ifdef DISABLE_DEBUG
#define DEBUG_SS(args) {}
#else
#define DEBUG_SS(args) {std::stringstream __debugStringStream;  __debugStringStream << args; zorba::server::utils::DebugLogger::log(__debugStringStream.str());}

#endif /* DISABLE_DEBUG */

namespace zorba
{
namespace server
{
namespace utils
{

/*
 * This class provides an OOB logging for debugging server code.
 * It is NOT meant to be used in final code.
 */
class DebugLogger
{

public:
   static void log(const std::string aMessage);
   static void log(const std::string aFile, const std::string aMessage);

private:
   static std::string theLogFile;
   static bool theFirst;

};

}
}
}
#endif /* ZORBA_SERVER_UTILS_DEBUG_H_ */
