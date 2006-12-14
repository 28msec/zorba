/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_scanner.h,v 1.1.1.1 2006/10/09 06:58:38 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

/*_______________________________________________________________________
|
|	Derived from the 'tagsoup' Java scanner.
|	Licensed under the Academic Free License (AFL) 3.0.
|	Original author: John Cowan (cowan@ccil.org).
|________________________________________________________________________*/

#ifndef XQP_XML_SCANNER_H
#define XQP_XML_SCANNER_H

#include "scan_handler.h"

namespace xqp {

class xml_scanner
{
protected:
	int theState;									// current state
	int theNextState;							// next state
	char theOutputBuffer[1<<20];	// output buffer
	int theSize;									// current buffer size in use

public:
	xml_scanner();
	~xml_scanner();


public:
 /*____________________________________________________________
	|
	|  Scan XML source, reporting lexical events
	|  @param r    buffer that provides characters
	|  @param len  length of buffer
	|  @param h    scan_handler that accepts lexical events.
	|____________________________________________________________*/
	void scan(const char* r, unsigned len, scan_handler* h);

 /*____________________________________________________________
	|                                                            
	|  A callback for the scan_handler that allows it to force   
	|  the lexer state to CDATA content (no markup is            
	|  recognized except the end of element.                     
	|____________________________________________________________*/
	void startCDATA();


private:
	void save(int ch, scan_handler* h);
	void flush(scan_handler* h);
};


inline void xml_scanner::save(int ch, scan_handler* h)
{
  if (theSize >= ((1<<20)-20)) {
    if (theState == S_PCDATA || theState == S_CDATA) {
      h->pcdata(theOutputBuffer, 0, theSize);
      theSize = 0;
    } else return;
  }
  theOutputBuffer[theSize++] = (char)ch;
}


inline void xml_scanner::flush(scan_handler* h)
{
	if (theState == S_PCDATA || theState == S_CDATA) {
		h->pcdata(theOutputBuffer, 0, theSize);
    theSize = 0;
  }
	else return;
}


}	/* namespace xqp */
#endif /* XQP_XML_SCANNER_H */
