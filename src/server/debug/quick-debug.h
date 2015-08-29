#ifndef QUICK_DEBUG_H_
#define QUICK_DEBUG_H_

#include <iomanip>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <fstream>

//#define DISABLE_DEBUG

#ifdef DISABLE_DEBUG

#define DEBUG_S(args) {}
#define DEBUG_SS(args) {}
#define DEBUG_S2(args) {DebugLogger::log(args);}
#define DEBUG_SS2(args) {std::stringstream __debugStringStream;  __debugStringStream << args; DebugLogger::log_err(__debugStringStream.str());}
#else
#define DEBUG_S(args) {DebugLogger::log(args);}
#define DEBUG_SS(args) {std::stringstream __debugStringStream;  __debugStringStream << args; DebugLogger::log(__debugStringStream.str());}
#define DEBUG_S2(args) {DebugLogger::log(args);}
#define DEBUG_SS2(args) {std::stringstream __debugStringStream;  __debugStringStream << args; DebugLogger::log_err(__debugStringStream.str());}
#endif /* DISABLE_DEBUG */

class DebugLogger{
public:

   static void start()
   {
     log("");
     log("************ STARTING ************");
     log("");
   };

   static void log(const std::string aMessage)
   {
     log("/log/log.txt", aMessage);
   }

   static void log_err(const std::string aMessage)
   {
     log("/log/log_err.txt", aMessage);
   }

   static void log(const std::string aFile, const std::string aMessage)
   {
     std::fstream fs;
     fs.open (aFile.c_str(), std::fstream::out | std::fstream::app);

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

};
#endif /* QUICK_DEBUG_H_ */
