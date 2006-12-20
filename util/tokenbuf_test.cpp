/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: tokenbuf_test.cpp,v 1.2 2006/10/22 01:32:22 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#include "tokenbuf.h"

#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
using namespace xqp;


/*______________________________________________________________________
|		This unit test simulates the highlighting of a block of text
|		for a list of 1,2,3, or 4 input keywords.
|_______________________________________________________________________*/

int main(int argc, char* argv[])
{
	ostringstream oss;
	vector<string> termv;
	string s(argv[1],0,strlen(argv[1]));
	if (argc > 2) termv.push_back(string(argv[2],0,strlen(argv[2])));
	if (argc > 3) termv.push_back(string(argv[3],0,strlen(argv[3])));
	if (argc > 4) termv.push_back(string(argv[4],0,strlen(argv[4])));
	if (argc > 5) termv.push_back(string(argv[5],0,strlen(argv[5])));

	tokenbuf tokbuf(s.c_str(),10,100," \n\r\t,.?;:!()-+=");
	tokbuf.set_lowercase(true);
	tokbuf.set_return_delims(false);

	tokenbuf::token_iterator it = tokbuf.begin();
	tokenbuf::token_iterator end = tokbuf.end();
	for (; it!=end; ++it) {
  	string const& term  = *it;
		cout << "term = " << term << endl;
  	string const& delim = it.get_delim();

  	vector<string>::const_iterator it = termv.begin();
		bool hit = false;
  	for (; it!=termv.end(); ++it)
  	{	// match against each query term
    	string t = *it;
    	if (strcasecmp(term.c_str(),t.c_str())==0) {
      	oss << " <b>"+term+"</b> ";
				hit = true;
   		}
  	}
		if (!hit) oss << term;
		oss << delim;
	}
 	cout << oss.str() << endl;
}

