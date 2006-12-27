

#include "http_request.h"
#include "stdio.h"

#include <vector>
#include <string>


void msg(
  const char* version,
  const char* built,
  char* buf,
  int max)
{
  std::vector<std::string> svec;
  svec.push_back("test string");
  
  sprintf(buf,
      "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">"
      "<HTML>\n"
      " <HEAD>\n"
      "  <TITLE>mod_xqp Content-Handler Output\n"
      "  </TITLE>\n"
      " </HEAD>\n"
      " <BODY>\n"
      "  <H1><SAMP>mod_xqp</SAMP> Module Content-Handler</H1>\n"
      "  <H2>Mark IV</H2>\n"
      "  <P>\n"
      "  Apache HTTP Server version: \"%s\"\n"
      "  <BR>\n"
      "  Server built: \"%s\"\n"
      "  </P>\n"
      " </BODY>\n"
      "</HTML>\n", version, built);
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

