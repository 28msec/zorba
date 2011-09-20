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
#include <string>
#include <vector>

#ifdef WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#include <zorba/zorba.h>
#include <zorba/store_manager.h>

#include "compiler/parsetree/parsenodes.h"
#include "parsertestdriverconfig.h" // SRC and BIN dir definitions
#include "compiler/parser/xquery_driver.h"
#include "compiler/api/compilercb.h"
#include "context/static_context.h"

using namespace zorba;

class Timer {
public:
  Timer();
  void start();
  void stop();
  ulong difference();
private:
#ifdef WIN32
  typedef FILETIME SysTime_t;
#else
  typedef struct timeval SysTime_t;
#endif
  void setLastToCurrent();
  ulong difference(SysTime_t& aBegin, SysTime_t& aEnd) const;
  SysTime_t getCurrentTime() const;
  SysTime_t theStartTime;
  SysTime_t theLastDiffTime;
  SysTime_t theEndTime;
  bool theRunning;
};

Timer::Timer() :theRunning(false) {}

void Timer::start()
{
  theRunning = true;
#ifdef WIN32
  GetSystemTimeAsFileTime(&theStartTime);
  GetSystemTimeAsFileTime(&theLastDiffTime);
#else
  gettimeofday(&theStartTime, 0);
  gettimeofday(&theLastDiffTime, 0);
#endif
}

void Timer::stop()
{
  theRunning = false;
#ifdef WIN32
  GetSystemTimeAsFileTime(&theEndTime);
#else
  gettimeofday(&theEndTime, 0);
#endif
}

ulong Timer::difference()
{
  ulong lResult;
  if (theRunning) {
    SysTime_t lCurrent = getCurrentTime();
    lResult = difference(theLastDiffTime, lCurrent);
    setLastToCurrent();
  }else {
    lResult = difference(theStartTime, theEndTime);
  }
  return lResult;
}

void Timer::setLastToCurrent()
{
#ifdef WIN32
  GetSystemTimeAsFileTime(&theLastDiffTime);
#else
  gettimeofday(&theLastDiffTime, 0);
#endif
}

ulong Timer::difference(SysTime_t& aBegin, SysTime_t& aEnd) const
{
  ulong lResult;
#ifdef WIN32
  ULARGE_INTEGER lBegin;
  ULARGE_INTEGER lEnd;

  lBegin.HighPart = aBegin.dwHighDateTime;
  lBegin.LowPart = aBegin.dwLowDateTime;
  lEnd.HighPart = aEnd.dwHighDateTime;
  lEnd.LowPart = aEnd.dwLowDateTime;

  ULONGLONG lDiff = lEnd.QuadPart - lBegin.QuadPart;
  lResult = static_cast<ulong>(lDiff/10000);
#else
  ulong lSeconds = aEnd.tv_sec - aBegin.tv_sec;
  ulong lMicro = aEnd.tv_usec - aBegin.tv_usec;
  lResult = 100*lSeconds + lMicro/1000;
#endif
  return lResult;
}

Timer::SysTime_t Timer::getCurrentTime() const
{
  SysTime_t lTime;
#ifdef WIN32
  GetSystemTimeAsFileTime(&lTime);
#else
  gettimeofday(&lTime, 0);
#endif
  return lTime;
}

static void printTime(ulong aMilli)
{
  ulong lMilli = aMilli;
  ulong lSeconds = lMilli / 1000;
  lMilli -= lSeconds*1000;
  ulong lMinutes = lSeconds / 60;
  lSeconds -= lMinutes*60;
  ulong lHours = lSeconds / 60;
  lHours -= lMinutes*60;
  if (lHours)
    std::cout << lHours << "h ";
  if (lMinutes)
    std::cout << lMinutes << "m ";
  if (lSeconds)
    std::cout << lSeconds << "s ";
  if (lMilli)
    std::cout << lMilli << "ms ";
}

void readCommandLine(int argc,
                     std::string &lQueryFileString,
                     char** argv,
                     bool &lTime,
                     unsigned lNumber,
                     int &status)
{
  if ( argc == 2 )
  {
    lQueryFileString  = zorba::PARSER_TEST_SRC_DIR +"/Queries/" + argv[1];
    std::string lQueryWithoutSuffix = std::string(argv[1]).substr( 0, std::string(argv[1]).size()-3 );

    std::cout << "parsertest " << lQueryWithoutSuffix << std::endl;
  } else if (argc >= 3 && argc <= 6) {
    for (int lI = 0; lI < argc; ++lI) {
      std::string lArg(argv[lI]);
      std::stringstream lStr;
      if (lArg[0] == '-') {
        switch (lArg[1])
        {
        case 'f':
          lQueryFileString = std::string(argv[++lI]);
          break;
        case 't':
          lTime = true;
          break;
        case 'n':
          lStr.str(argv[++lI]);
          lStr >> lNumber;
          break;
        default:
          std::cerr << std::endl <<
            "usage:   parsertestdriver (-f file|testfile) [-t] [-n exectimes]"
            << std::endl;
          status = 1;
          // break out of the loop
          lI = argc;
        }
      } else if (lQueryFileString == "") {
        lQueryFileString  = zorba::PARSER_TEST_SRC_DIR +"/Queries/" + argv[1];
        std::string lQueryWithoutSuffix = std::string(argv[1]).substr(
          0, std::string(argv[1]).size()-3);

        std::cout << "parsertest " << lQueryWithoutSuffix << std::endl;
      } else {
        std::cerr << std::endl <<
          "usage:   parsertestdriver (-f file|testfile) [-t] [-n exectimes]"
          << std::endl;
        status = 1;
        lI = argc;
      }
    }
  } else {
    std::cerr << std::endl <<
      "usage:   parsertestdriver (-f file|testfile) [-t] [-n exectimes]" << std::endl;
    status = 1;
  }
}

void printTimingInfoOfRun( unsigned lI, Timer &lTimer, std::vector<ulong> &lTimes )
{
  std::cout << "Time consumed for ";
  switch (lI)
  {
  case 0:
    std::cout << "1st";
    break;
  case 1:
    std::cout << "2nd";
    break;
  case 2:
    std::cout << "3rd";
    break;
  default:
    std::cout << lI + 1 << "th";
  }
  std::cout << " run: ";
  ulong lDiff = lTimer.difference();
  lTimes.push_back(lDiff);
  printTime(lDiff);
  std::cout << std::endl;
}

void printEndTimeInfo( Timer &lTimer, std::vector<ulong> &lTimes, unsigned lNumber )
{
  lTimer.stop();
  std::cout << "Total time: ";
  printTime(lTimer.difference());
  std::cout << std::endl;
  std::vector<ulong>::iterator lIter;
  unsigned long lTotal = 0;
  for (lIter = lTimes.begin(); lIter != lTimes.end(); ++lIter) {
    lTotal += *lIter;
  }
  lTotal /= lNumber;
  std::cout << "Average run time: ";
  printTime(lTotal);
  std::cout << std::endl;
}

int parseCode( int status, std::string &lQueryFileString )
{
  XQueryDiagnostics* xqueryDiagnostics = NULL;
  CompilerCB aCompilerCB(xqueryDiagnostics);
  xquery_driver lDriver(&aCompilerCB);

  if (!status) {
    // TODO correct Exception handling with try-catch
    try {
      lDriver.parse_file(lQueryFileString.c_str());
    } catch (...) {
      assert(false);
    }
  }

  if (!status) {
    parsenode* lNode = lDriver.get_expr();
    if (typeid (*lNode) == typeid (ParseErrorNode)) {
      ParseErrorNode *err = static_cast<ParseErrorNode *> (&*lNode);
      std::cerr << "Query parsed but no parsenode root generated!" << std::endl;
      std::cerr << err->msg << std::endl;
      status = 3;
    }
  }	return status;
}

int
#ifdef _WIN32_WCE
_tmain(int argc, _TCHAR* argv[])
#else
main(int argc, char** argv)
#endif
{
  int status = 0;
  bool lTime = false;
  unsigned lNumber = 1;
  std::vector<ulong> lTimes;

  std::string lQueryFileString;
  Zorba* lZorba = Zorba::getInstance(zorba::StoreManager::getStore());


  // do initial stuff
  readCommandLine(argc, lQueryFileString, argv, lTime, lNumber, status);


  Timer lTimer;
  if (lTime) {
    lTimer.start();
  }

  for (unsigned lI = 0; lI < lNumber; ++lI) {
    {
      status = parseCode(status, lQueryFileString);

    }
    if (lTime) {
      printTimingInfoOfRun(lI, lTimer, lTimes);

    }
  }
  lZorba->shutdown();
  if (lTime && lNumber != 1) {
    printEndTimeInfo(lTimer, lTimes, lNumber);

  }
  return status;
}
