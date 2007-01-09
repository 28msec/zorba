/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: URLCanonicalizer_unittest.cpp 251 2006-04-04 03:16:46Z paul $
 *
 *  Copyright 2005-2006 SearchMe Corporation.  All Rights Reserved.
 *
 */

// Unix headers
#include <errno.h>
#include <sys/types.h>
#include <regex.h>

// C++ headers
#include <sstream>
#include <fstream>
#include <vector>

// search headers
#include "URLCanonicalizer.h"
#include "Logger.h"

using namespace km;
using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 4) {
    cerr << "Expecting three arguments: URLFILENAME MAXLOOPCOUNT STRIPINDEXPAGES\n";
    return 1;
  }

  Logger *log = new Logger("URLCanonicalizer_log");

  int maxloopscount;
  bool stripindex = false;

  string maxloops(argv[2],0,strlen(argv[2]));

  istringstream iss(maxloops);
  iss >> maxloopscount;

  if (argv[3][0] == 't' || argv[3][0] == 'T') {
    stripindex = true;
  }

  URLCanonicalizer canon(maxloopscount, stripindex);
  canon.setLogger(log);

  vector<string> urlv;
  string line;
  urlv.clear();

  ifstream infile (argv[1], ios_base::in);
  while (getline(infile, line, '\n')) {
    urlv.push_back (line);
  }

  vector<string>::iterator vsIt = urlv.begin();
  for (; vsIt != urlv.end(); ++vsIt) {
    cout << "URL:  " << *vsIt << endl;
    if (canon.canonicalizeUrl(*vsIt)) cout << "GOOD: " << *vsIt << endl;
    else cout << "BAD." << endl;
    cout << endl;
  }
}

