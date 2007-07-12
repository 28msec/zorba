/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: content_handler.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "http_request.h"
#include "stdio.h"

#include <sstream>
#include <string>

#include "../util/hashmap.h"
#include "../util/tokenbuf.h"
#include "../parser/xquery_driver.h"

using namespace std;
using namespace xqp;

void msg(request_rec* r,char* buf,int max)
{
  ostringstream oss;
  oss <<  "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">"
          "<HTML><HEAD><TITLE>mod_xqp content_handler</TITLE></HEAD><BODY>\n"
          "<H1><SAMP>mod_xqp content_handler</SAMP></H1>\n"
          "<H2>Parse mode</H2>\n";
      
  // parse the query args
  hashmap<string> param_map;
  tokenbuf tokbuf(r->args,0,strlen(r->args),"&=");
	tokbuf.set_return_delims(false);
	tokenbuf::token_iterator it = tokbuf.begin();
	tokenbuf::token_iterator end = tokbuf.end();
	string key, value;
	for (; it!=end; ++it) {
  	string const& value  = *it;
  	string const& delim = it.get_delim();
  	if (delim.find('=')!=string::npos) {
    	key = value;
  	}
  	else {
    	param_map.put(key,value);
  	}
	}
	
	oss << "<PRE>\n";
  
	string qfile;
	if (param_map.get("q",qfile)) {
  	xquery_driver driver(oss);
  	if (param_map.get("p",value)) {
  	  driver.set_trace_parsing();
	  }
	  if (param_map.get("s",value)) {
  	  driver.set_trace_scanning();
	  }	
    driver.parse(qfile.c_str());
  } 
  else {
    oss << "<br/>Param error<br/>";
  }
     		
  oss << "\n</PRE></BODY></HTML>";
  string s = oss.str();
  int n = s.length();
  int m = (n>max ? max : n);
  strncpy(buf,s.c_str(),m);
}



extern "C" {
   
void handle_request(request_rec* r,char* buf,int max)
{
  msg(r,buf,max);
}

}

