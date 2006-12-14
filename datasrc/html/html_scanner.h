/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: html_scanner.h,v 1.1.1.1 2006/10/09 06:58:31 Paul Pedersen Exp $
 *
 *  Copyright 2005-2006 Paul Pedersen.  All Rights Reserved.
 *
 */
#ifndef _PV_HTML_SCANNER_H_
#define _PV_HTML_SCANNER_H_

/*___________________________________________________________
|                                                            |
|  Scan HTML source, reporting lexical events.
|  Used in conjunction with a scan_handler callback
|  implementation.
|____________________________________________________________|*/

#include "../core/logger.h"
#include "scan_handler.h"
#include "unicode_decomposer.h"

namespace pv {

class html_scanner
{
protected:
	int theState;									// current state
	int theNextState;							// next state
	char* theOutputBuffer;				// output buffer
	int theSize;									// current buffer size in use
	logger* logr;									// server logging
  unicode_decomposer ud;

public:
	html_scanner();
	~html_scanner();

public:
 /*____________________________________________________________
	|                                                            |
	|  Scan HTML source, reporting lexical events.               |
	|  @param r    buffer that provides characters               |
	|  @param len  length of buffer                              |
	|  @param h    scan_handler that accepts lexical events.     |
	|____________________________________________________________|*/
	void scan(const char* r, unsigned len, scan_handler* h);

 /*____________________________________________________________
	|                                                            |
	|  A callback for the scan_handler that allows it to force   |
	|  the lexer state to CDATA content (no markup is            |
	|  recognized except the end of element.                     |
	|____________________________________________________________|*/
	void startCDATA();

 /*____________________________________________________________
	|                                                            |
	|  Set server logging                                        |
	|____________________________________________________________|*/
	void setLogger(logger*);


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

inline void html_scanner::setLogger(logger* _logr)
{
	logr = _logr;
}


}	/* namespace pv */
#endif /* _PV_HTML_SCANNER_H_ */
