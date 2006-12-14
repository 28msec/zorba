/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: tag_scanner_test.cpp 1 2006-08-31 07:31:37Z paul $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "tag_scanner.h"

#include <iostream>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	const char* tags =
	"a         abbr      acronym   address   applet    area      b         base      basefont  bdo       big       blockquotebody      br        button    caption   center    cite      code      col       colgroup  dd        del       dfn       dir       div       dl        dt        em        fieldset  font      form      frame     frameset  h1        h2        h3        h4        h5        h6        head      hr        html      i         iframe    img       input     ins       isindex   kbd       label     legend    li        link      map       menu      meta      noframes  noscript  object    ol        optgroup  option    p         param     pre       q         s         samp      script    select    small     span      strike    strong    style     sub       sup       table     tbody     td        textarea  tfoot     th        thead     title     tr        tt        u         ul        var       ";

	const char* TAGS =
	"A         ABBR      ACRONYM   ADDRESS   APPLET    AREA      B         BASE      BASEFONT  BDO       BIG       BLOCKQUOTEBODY      BR        BUTTON    CAPTION   CENTER    CITE      CODE      COL       COLGROUP  DD        DEL       DFN       DIR       DIV       DL        DT        EM        FIELDSET  FONT      FORM      FRAME     FRAMESET  H1        H2        H3        H4        H5        H6        HEAD      HR        HTML      I         IFRAME    IMG       INPUT     INS       ISINDEX   KBD       LABEL     LEGEND    LI        LINK      MAP       MENU      META      NOFRAMES  NOSCRIPT  OBJECT    OL        OPTGROUP  OPTION    P         PARAM     PRE       Q         S         SAMP      SCRIPT    SELECT    SMALL     SPAN      STRIKE    STRONG    STYLE     SUB       SUP       TABLE     TBODY     TD        TEXTAREA  TFOOT     TH        THEAD     TITLE     TR        TT        U         UL        VAR       ";

	const int taglen[] = {
		1, 4, 7, 7, 6, 4, 1, 4, 8, 3, 3, 10, 4, 2, 6, 7, 6, 4, 4, 3, 8, 2, 3, 3, 3, 3, 2, 2, 
		2, 8, 4, 4, 5, 8, 2, 2, 2, 2, 2, 2, 4, 2, 4, 1, 6, 3, 5, 3, 7, 3, 5, 6, 2, 4, 3, 4, 4,
		8, 8, 6, 2, 8, 6, 1, 5, 3, 1, 1, 4, 6, 6, 5, 4, 6, 6, 5, 3, 3, 5, 5, 2, 8, 5, 2, 5,
		5, 2, 2, 1, 2, 3 };

	const char* attrs =
  "action    alink     alt       archive   backgroundbgcolor   checked   cite      class     classid   code      codebase  codetype  color     cols      colspan   content   data      datetime  dir       frame     headers   href      hreflang  http-equivid        label     lang      language  link      longdesc  media     method    name      object    onchange  onclick   ondblclickonreset   onselect  onsubmit  onunload  profile   prompt    rel       rev       rows      rowspan   rules     scheme    scope     selected  shape     size      span      src       start     style     summary   tabindex  target    text      title     type      valign    value     valuetype vlink     enctype   bogon";

	const char* ATTRS =
  "ACTION    ALINK     ALT       ARCHIVE   BACKGROUNDBGCOLOR   CHECKED   CITE      CLASS     CLASSID   CODE      CODEBASE  CODETYPE  COLOR     COLS      COLSPAN   CONTENT   DATA      DATETIME  DIR       FRAME     HEADERS   HREF      HREFLANG  HTTP-EQUIVID        LABEL     LANG      LANGUAGE  LINK      LONGDESC  MEDIA     METHOD    NAME      OBJECT    ONCHANGE  ONCLICK   ONDBLCLICKONRESET   ONSELECT  ONSUBMIT  ONUNLOAD  PROFILE   PROMPT    REL       REV       ROWS      ROWSPAN   RULES     SCHEME    SCOPE     SELECTED  SHAPE     SIZE      SPAN      SRC       START     STYLE     SUMMARY   TABINDEX  TARGET    TEXT      TITLE     TYPE      VALIGN    VALUE     VALUETYPE VLINK     ENCTYPE";

	const int attrlen[] = {
		6, 5, 3, 7, 10, 7, 7, 4, 5, 7, 4, 8, 8, 5, 4, 7, 7, 4, 8, 3, 5, 7, 4, 8, 10, 2, 5, 4,
		8, 4, 8, 5, 6, 4, 6, 8, 7, 10, 7, 8, 8, 8, 7, 6, 3, 3, 4, 7, 5, 6, 5, 8, 5, 4, 4, 3, 5,
		5, 7, 8, 6, 4, 5, 4, 6, 5, 9, 5, 7 };

	const char* adtags =
	"ad        ads       adlog     adview    adserver  adtech    adpopup   adclick   adframe   advertise phpads    fastclick doubleclick";

	const char* Adtags =
	"Ad        Ads       Adlog     Adview    Adserver  Adtech    adPopup   adClick   adFrame   ADVERTISE phpads    fastclick doubleClick";

	const int adtaglen[] = {
		2, 3, 5, 6, 8, 6, 7, 7, 7, 9, 6, 9, 11 };
	tag_scanner tscan;


	for (int a=0; a<91; ++a) {
		cout << "scan_htmltag(\"" << string(tags,a*10,taglen[a]) << "\"[" << taglen[a] << "]) = "
				 <<  tscan.decode_htmltag(tscan.scan_htmltag(tags,a*10,taglen[a])) << endl;
	}

	for (int a=0; a<91; ++a) {
		cout << "scan-htmltag(\"" << string(TAGS,a*10,taglen[a]) << "\"[" << taglen[a] << "]) = "
				 <<  tscan.decode_htmltag(tscan.scan_htmltag(TAGS,a*10,taglen[a])) << endl;
	}

	for (int a=0; a<69; ++a) {
		cout << "scan_htmlattr(\"" << string(attrs,a*10,attrlen[a]) << "\"[" << attrlen[a] << "]) = "
				 <<  tscan.decode_htmlattr(tscan.scan_htmlattr(attrs,a*10,attrlen[a])) << endl;
	}

	for (int a=0; a<69; ++a) {
		cout << "scan_htmlattr(\"" << string(ATTRS,a*10,attrlen[a]) << "\"[" << attrlen[a] << "]) = "
				 <<  tscan.decode_htmlattr(tscan.scan_htmlattr(ATTRS,a*10,attrlen[a])) << endl;
	}

	for (int a=0; a<13; ++a) {
		cout << "scan_adtag(\"" << string(adtags,a*10,adtaglen[a]) << "\"[" << adtaglen[a] << "]) = "
				 <<  tscan.decode_adtag(tscan.scan_adtag(adtags,a*10,adtaglen[a])) << endl;
	}

	for (int a=0; a<13; ++a) {
		cout << "scan_adtag(\"" << string(Adtags,a*10,adtaglen[a]) << "\"[" << adtaglen[a] << "]) = "
				 <<  tscan.decode_adtag(tscan.scan_adtag(Adtags,a*10,adtaglen[a])) << endl;
	}

/*
	tag_scanner::htmltag tag;
	for (int t=0; t<5000; ++t) {
		for (int a=0; a<90; ++a) tag = tag_scanner::scan_htmltag(buf,a*10,lenv[a]);
	}
	for (int t=0; t<5000; ++t) {
		for (int a=0; a<90; ++a) tag = tag_scanner::scan_htmltag(BUF,a*10,lenv[a]);
	}
*/

}

