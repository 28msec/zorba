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

int main(int argc, char* argv[])
{
	ostringstream oss;
	vector<string> termv;
	string s(argv[1],0,strlen(argv[1]));
	string t1, t2, t3;
	if (argc > 2) termv.push_back(string(argv[2],0,strlen(argv[2])));
	if (argc > 3) termv.push_back(string(argv[3],0,strlen(argv[3])));
	if (argc > 4) termv.push_back(string(argv[4],0,strlen(argv[4])));
	if (argc > 5) termv.push_back(string(argv[5],0,strlen(argv[5])));

	tokenbuf tokbuf(s.c_str(), " \n\r\t,.?;:!()-+=");
	tokbuf.set_lowercase(true);
	tokbuf.set_return_delims(false);

	tokenbuf::token_iterator it = tokbuf.begin();
	for (; it!=tokbuf.end(); ++it) {
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


/*
int main(int argc, char* argv[])
{
	const char* s1 = " this is  a   sentence.--,all  about children, and other,fuzzy - creatures.";
	const char* s2 = "this sentence is all about           children";
	const char* s3 = "a   sentence all about children.";
	const char* s4 = "children are all   over   this  sentence";

	cout << "          1         2         3         4         5         6         7         \n";
	cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789\n" ;
	cout << s1 << "\n\n";

	km::tokenizer t(s1," ,-.",true);
	while (t.hasMoreTokens()) {
		string& s = t.nextToken();
		if (s.length()==0) continue;
		cout	<< s << "[("
					<< t.getTokenPos() << ","
					<< t.getTokenLen() << "), ("
					<< t.getDelimPos() << ","
					<< t.getDelimLen() << ")]"
					<< endl;
	}

	cout << "-----------------\n";
	km::tokenizer t0(s1," ,-.",false);
	while (t0.hasMoreTokens()) {
		cout << t0.nextToken()
				 << " : "
				 << t0.getNextDelim() << endl;
	}

	cout << "-----------------\n";
	t.init(s2," ");
	while (t.hasMoreTokens()) {
		cout << t.nextToken() << " : " << t.getNextDelim() << endl;
	}

	cout << "-----------------\n";
	t.init(s3, " .");
	while (t.hasMoreTokens()) {
		cout << t.nextToken() << " : " << t.getNextDelim() << endl;
	}

	cout << "-----------------\n";
	t.init(s4, " ");
	while (t.hasMoreTokens()) {
		cout << t.nextToken() << " : " << t.getNextDelim() << endl;
	}

	cout << "=====================================================\n";
	string arg = "training";
	km::tokenizer ttok(arg.c_str(), "+", false);
	while (ttok.hasMoreTokens()) {
		cout << "ttok.nextToken() = " << ttok.nextToken() << endl;
	}
	
}
*/
