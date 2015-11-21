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
#include <iomanip>
#include <sys/time.h>
#include <sys/types.h>

#include <fstream>

#include "exceptions/server_exceptions.h"

#include "debug.h"

namespace zorba
{
namespace server
{
namespace utils
{

std::string DebugLogger::theLogFile = "/log/log.txt";

void DebugLogger::log(const std::string aMessage)
{
  log(theLogFile, aMessage);
}

void DebugLogger::log(const std::string aFile, const std::string aMessage)
{
  std::ofstream fs;
  fs.open(aFile.c_str(), std::fstream::out | std::fstream::app);
  if (!fs.is_open())
    throw exceptions::ServerException("Cannot write to debug log.");

  struct timeval tv;
  struct timezone tz;
  struct tm *tm;
  gettimeofday(&tv,&tz);
  tm=localtime(&tv.tv_sec);

  fs << "[" << getpid() << "]["
      << std::setfill('0') << std::setw(2) << tm->tm_hour << ":"
      << std::setfill('0') << std::setw(2) << tm->tm_min << ":"
      << std::setfill('0') << std::setw(2) << tm->tm_sec << "."
      << std::setfill('0') << std::setw(3) << (tv.tv_usec/1000) << "] ";
  fs << aMessage << std::endl;
  fs.close();
}

}
}
}
