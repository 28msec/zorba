/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_scanner_unittest.cpp,v 1.1.1.1 2006/10/09 06:58:38 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include <errno.h>
#include <stdio.h>

#include "../util/file.h"
#include "../util/hashmap.h"
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
    if (!file(path).exists()) {
      cout << "file '" << path << "' does not exist\n";
      return -1;
    }
    int fd = open(argv[1], O_RDONLY, S_IRUSR);
    if (fd < 0 ) {
      cout << "open failed on '" << path << "' with error: " << strerror(errno);
      return -1;
    }
    unsigned sz = f.getSize();
    size_t n = (sz > (1<<20) ? (1<<20) : (size_t)(sz));
    char ibuf[n];
    ssize_t m;
    if ((m = read(fd, ibuf, n))==-1) {
      cout << "read failed on '" << path << "' with error: " << strerror(errno) << endl;
    }

    xml_scanner xmls = xml_scanner();
    scan_handler* s = new scan_handler();
    xmls.scan(ibuf, m, s);
    close(fd);
    delete s;
  } catch (Exception& e1) {
    cout << "Application exception: " << e1.what() << '\t' << e1.getMsg() << endl;
  } catch (exception& e2) {
    cout << "System exception: " << e2.what() << endl;
  } catch (...) {
    cout << "Unhandled exception\n";
  }
}

