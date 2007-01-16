/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: html_scanner.h,v 1.1.1.1 2006/10/09 06:58:31 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */
#ifndef XQP_HTML_SCANNER_H
#define XQP_HTML_SCANNER_H

/*______________________________________________________________________
|                                                            
|	Scan HTML source, reporting lexical events.
|	Used in conjunction with a scan_handler callback
|	implementation.
|
|	Derived from the 'tagsoup' Java scanner.
|	Licensed under the Academic Free License (AFL) 3.0.
|	Original author: John Cowan (cowan@ccil.org).
|________________________________________________________________________*/

#include "scan_handler.h"
#include "unicode_decompositions.h"

namespace xqp {

class html_scanner
{
protected:
	int theState;									// current state
	int theNextState;							// next state
	char* theOutputBuffer;				// output buffer
	int theSize;									// current buffer size in use
  unicode_decompositions ud;

public:
	html_scanner();
	~html_scanner();

public:
	/*______________________________________________________________________
	|
	|  Scan HTML source, reporting lexical events. 
	|  @param r    buffer that provides characters 
	|  @param len  length of buffer
	|  @param h    scan_handler that accepts lexical events. 
	|________________________________________________________________________*/
	void scan(const char* r, unsigned len, scan_handler* h);

	/*______________________________________________________________________
	|
	|  A callback for the scan_handler that allows it to force 
	|  the lexer state to CDATA content (no markup is
	|  recognized except the end of element.) 
	|________________________________________________________________________*/
	void startCDATA();

private:
	void save(int ch, scan_handler* h);
	void flush(scan_handler* h);

};


inline void html_scanner::save(int ch, scan_handler* h)
{
  if (theSize >= ((1<<20)-20)) {
    if (theState == S_PCDATA || theState == S_CDATA) {
      h->pcdata(theOutputBuffer, 0, theSize);
      theSize = 0;
    } else return;
  }
  theOutputBuffer[theSize++] = (char)ch;
}


inline void html_scanner::flush(scan_handler* h)
{
	if (theState == S_PCDATA || theState == S_CDATA) {
		h->pcdata(theOutputBuffer, 0, theSize);
    theSize = 0;
  }
	else return;
}

}	/* namespace xqp */
#endif /* XQP_HTML_SCANNER_H */
