/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: dom_xml_handler_test.cpp 703 2006-06-09 16:28:05Z paul $
 *  Copyright 2006-2007  FLWOR Foundation
 *	Author:  John Cowan, Paul Pedersen
 *
 */


#include "dom_xml_handler.h"
#include "dom_nodes.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "runtime/zorba.h"
#include "store/data_manager.h"
#include "store/itemstore.h"
#include "store/scan_handler.h"
#include "store/xml_scanner.h"
#include "util/file.h"

#include <sstream>
#include <fstream>
#include <errno.h>

using namespace xqp;
using namespace std;

#define MAXSIZE (1<<20)

int main(int argc, char* argv[])
{
	try {
		if (argc<3) {
			cerr << "Expecting three arguments:  PATH  BASEURI URI\n";
			return 1;
		}
		string path(argv[1],0,strlen(argv[1]));
		string baseuri(argv[2],0,strlen(argv[2]));
		string uri(argv[3],0,strlen(argv[3]));

		file f(path);
		if (!f.exists()) {
			cout << "file '" << path << "' does not exist\n";
			return -1;
		}
		int fd = open(path.c_str(), O_RDONLY, S_IRUSR);
		if (fd < 0 ) {
		  cout << "open failed on '" << path << "' with error: " << strerror(errno);
			return -1;
		}
		size_t sz = f.get_size();
		if (sz>MAXSIZE) sz = MAXSIZE;
		char ibuf[sz];

		ssize_t nread;
		if ((nread = read(fd, ibuf, sz))==-1) {
		  cout << "read failed on '" << path << "' with error: " << strerror(errno) << endl;
		}
		close(fd);

		zorba* zorp = new zorba();

		rchandle<data_manager> dataManager = new itemstore("test",1<<20);
		rchandle<static_context> staticContext = new static_context(zorp, NULL);
		rchandle<dynamic_context> dynamicContext = new dynamic_context(zorp, NULL);

		zorp->set_data_manager(dataManager);
		zorp->set_value_factory(NULL);
		zorp->set_static_context(staticContext);
		zorp->set_dynamic_context(dynamicContext);

		dom_xml_handler* dxmlh_p = new dom_xml_handler(zorp, baseuri, uri);
		xml_scanner* xmls_p = new xml_scanner();
		xmls_p->scan(ibuf, nread, dynamic_cast<scan_handler*>(dxmlh_p));
		dom_node* en_p = dxmlh_p->context_node();
		cout << "\n=====================\n";
		en_p->put(zorp,cout);

		delete en_p;
		delete xmls_p;
		delete dxmlh_p;

	} catch (xqp_exception& e) {
		cout << "Application exception: " << e.what() << '\t' << e.get_msg() << endl;
	} catch (exception& e) {
		cout << "System exception: " << e.what() << endl;
	} catch (...) {
		cout << "Unhandled exception\n";
	}
}

