

#include "http_request.h"
#include "stdio.h"

#include <sstream>
#include <string>

using namespace std;

void msg(
  const char* version,
  const char* built,
  char* buf,
  int max)
{
  ostringstream oss;
  
  oss <<
      "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">"
      "<HTML>\n"
      " <HEAD>\n"
      "  <TITLE>mod_xqp Content-Handler Output</TITLE>\n"
      " </HEAD>\n"
      " <BODY>\n"
      "  <H1><SAMP>mod_xqp</SAMP> Module Content-Handler</H1>\n"
      "  <H2>Mark IV</H2>\n"
      "  <P>\n"
      "  Apache HTTP Server version: \""
      <<version<<
      "\"<BR>\n"
      "  Server built: \""
      <<built<<
      "\"</P>\n</BODY></HTML>";
      
  string s = oss.str();
  int n = s.length();
  int m = (n>max ? max : n);
  strncpy(buf,s.c_str(),m);
}



extern "C" {
   
void handle_request(
  const char* version, 
  const char* built,
  char* buf,
  int max)
{
  msg(version,built,buf,max);
}
}

