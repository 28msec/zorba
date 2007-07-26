/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: [module].cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "uri_resolver.h"

#ifndef WIN32
	#include <sys/time.h>
#else
	#include <time.h>
#endif
#include <time.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>

#include "../util/rchandle.h"
#include "../util/tokenbuf.h"
#include "../util/URI.h"


using namespace std;
namespace xqp {

string uri_resolver::get_base(
  const string& baseurl)
{
  URI baseuri(baseurl);
	return get_base(baseuri);
}


string uri_resolver::get_base(
  const URI& baseuri)
{
  ostringstream oss;
  oss << baseuri.get_scheme() << "://" << baseuri.get_hostinfo();
  vector<string> pathv;

  tokenbuf tokbuf(baseuri.get_path().c_str(),"/");
	tokenbuf::token_iterator it = tokbuf.begin();
	tokenbuf::token_iterator end = tokbuf.end();
  for (; it!=end; ++it) {
    pathv.push_back(*it);
  }

  for (unsigned a=0; a+1<pathv.size(); ++a) {
    oss << '/' << pathv[a];
  }
  return oss.str();
}


bool uri_resolver::make_absolute(
  const string& base,
  const string& url,
	string& result)
{
  URI baseuri(base);
  URI uri(url);
  return make_absolute(baseuri,uri,result);
}


bool uri_resolver::make_absolute(
  const URI& baseuri,
  const URI& uri0,
  string& result)
{
	URI uri(uri0);
  if (uri.get_scheme().length()==0) {
    uri.set_scheme(baseuri.get_scheme());
  }
  if (uri.get_hostname().length()==0) {
		// we have some kind of relative URL
    uri.set_hostname(baseuri.get_hostname()); // use the base host name
    string path = uri.get_path();
    if (path[0]!='/') {                       // path relative
			string basepath; // = baseuri.get_path();
      string basepath0 = baseuri.get_path();
			size_t a = basepath0.rfind('/');
			if (a==string::npos) a = basepath0.length()-1;
			basepath = basepath0.substr(0,a+1);
      basepath += path;

      // resolve '.' and '..' path elements
      tokenbuf pathtok(basepath.c_str(),"/");
			tokenbuf::token_iterator it = pathtok.begin();
			tokenbuf::token_iterator end = pathtok.end();
      vector<string> basepathv;
      for (; it!=end; ++it) {
        basepathv.push_back(*it);
      }

      stack<string> basepathStack;
      vector<string>::iterator vsIt = basepathv.begin();
      for (; vsIt != basepathv.end(); ++vsIt) {
        if (*vsIt == ".") continue;
        else if (*vsIt == "..") {
          if (basepathStack.empty()) continue;
          else basepathStack.pop();
        }
        else basepathStack.push(*vsIt);
      }

      deque<string> basepathq;
      while (!basepathStack.empty()) {
        basepathq.push_front(basepathStack.top());
        basepathStack.pop();
      }
      basepathv = vector<string>(basepathq.begin(),basepathq.end());

			string basepath1;
      if (basepathv.size()) {
        for (vsIt = basepathv.begin(); vsIt != basepathv.end(); ++vsIt) {
          basepath1 += "/";
          basepath1 += *vsIt;
        }
      }
      else {
        basepath1 = "/";
      }
      uri.set_path(basepath1);
    }
    else {
      uri.set_path(path);
    }

    if (baseuri.get_port()!=0 && baseuri.get_port()!=80) {
      uri.set_port(baseuri.get_port());
    }
  }
  result= uri.toString();
  return true;
}


}	/* namespace xqp */

