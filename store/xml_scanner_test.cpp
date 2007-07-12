/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: xml_scanner_unittest.cpp,v 1.1.1.1 2006/10/09 06:58:38 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include <errno.h>
#include <stdio.h>

#include "../util/file.h"
#include "../util/xqp_exception.h"
#include "scan_handler.h"
#include "xml_scanner.h"

using namespace xqp;
using namespace std;

int main(int argc, char* argv[])
{
  try {
    if (argc<2) {
      cerr << "Expecting one arguments: PATH\n";
      return -1;
    }
    string path(argv[1],0,strlen(argv[1]));
		file f(path);
    if (!f.exists()) {
      cout << "file '" << path << "' does not exist\n";
      return -1;
    }
    unsigned sz = f.get_size();
    size_t n = (sz > (1<<24) ? (1<<24) : (size_t)(sz));
    char* ibuf = new char[n+1];
		f.readfile(ibuf,n);
    xml_scanner xmls = xml_scanner();
    scan_handler* s = new scan_handler();
    xmls.scan(ibuf, n, s);
    delete s;
		delete[] ibuf;
  } catch (xqp_exception& e1) {
    cout << "Application exception: " << e1.what() << '\t' << e1.get_msg() << endl;
  } catch (exception& e2) {
    cout << "System exception: " << e2.what() << endl;
  } catch (...) {
    cout << "Unhandled exception\n";
  }
}

