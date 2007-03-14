/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_handler_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *	Author: John Cowan,Paul Pedersen
 *
 */

#include "../context/context.h"
#include "../util/file.h"

#include "xml_handler.h"
#include "xml_scanner.h"
#include "xml_term.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[]) 
{
	context ctx;
	itemstore& istore = *ctx.istore();
  try {
    if (argc<2) {
      cerr << "Expecting one argument: PATH\n";
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
		cout << "reading file of size (" << sz << ")\n";
		f.readfile(ibuf,n);

    xml_scanner xscanner;
		vector<xml_term> xterm_v;
		string baseuri = "/";
		string uri = path;
		cout << "allocate xml_handler\n";
    xml_handler* xhandler_p = new xml_handler(&ctx,baseuri,uri,xterm_v);

		cout << "run xml_scanner\n";
    xscanner.scan(ibuf, n, dynamic_cast<scan_handler*>(xhandler_p));

		cout << "docindex.put(\"" << path << "\")\n";
		uint32_t m = baseuri.length();
		if (baseuri[m-1]!='/') baseuri += '/';

    delete xhandler_p;
		delete[] ibuf;

		document_node * d_p = new(istore,ctx.docref()) document_node();
		if (d_p==NULL) {
			cout << "doc (" << path << ") not found\n"; 
		} else {
			d_p->put(cout, &ctx) << endl;
		}

  } catch (xqp_exception& e1) {
    cout << "Application exception: " << e1.what() << '\t' << e1.get_msg() << endl;
  } catch (exception& e2) {
    cout << "System exception: " << e2.what() << endl;
  } catch (...) {
    cout << "Unhandled exception\n";
  }
	
}

