/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: XMLTagScanner.cpp,v 1.1.1.1 2006/10/09 06:58:38 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 Paul Pedersen.  All Rights Reserved.
 *
 */

#include <iostream>
#include <string>

#include "TagScanner.h"

using namespace std;

namespace pv {

unsigned TagScanner::tag_map(TagScanner::htmltag tag)
{
	switch(tag) {
	case h_a: return 10;
	case h_abbr: return 10;
	case h_acronym: return 10;
	case h_address: return 10;
	case h_applet: return 10;
	case h_area: return 10;
	case h_b: return 20;
	case h_base: return 10;
	case h_basefont: return 10;
	case h_bdo: return 10;
	case h_big: return 20;
	case h_blockquote: return 10;
	case h_body: return 10;
	case h_br: return 10;
	case h_button: return 10;
	case h_caption: return 10;
	case h_center: return 10;
	case h_cite: return 10;
	case h_code: return 10;
	case h_col: return 10;
	case h_colgroup: return 10;
	case h_dd: return 10;
	case h_del: return 10;
	case h_dfn: return 10;
	case h_dir: return 10;
	case h_div: return 10;
	case h_dl: return 10;
	case h_dt: return 10;
	case h_em: return 20;
	case h_fieldset: return 10;
	case h_font: return 10;
	case h_form: return 10;
	case h_frame: return 10;
	case h_frameset: return 10;
	case h_h1: return 50;
	case h_h2: return 40;
	case h_h3: return 30;
	case h_h4: return 20;
	case h_h5: return 10;
	case h_h6: return 10;
	case h_head: return 10;
	case h_hr: return 10;
	case h_html: return 10;
	case h_i: return 20;
	case h_iframe: return 10;
	case h_img: return 10;
	case h_input: return 10;
	case h_ins: return 10;
	case h_isindex: return 10;
	case h_kbd: return 10;
	case h_label: return 10;
	case h_legend: return 10;
	case h_li: return 10;
	case h_link: return 10;
	case h_map: return 10;
	case h_menu: return 10;
	case h_meta: return 10;
	case h_noframes: return 10;
	case h_noscript: return 10;
	case h_object: return 10;
	case h_ol: return 10;
	case h_optgroup: return 10;
	case h_option: return 10;
	case h_p: return 10;
	case h_param: return 10;
	case h_pre: return 10;
	case h_q: return 10;
	case h_s: return 10;
	case h_samp: return 10;
	case h_script: return 10;
	case h_select: return 10;
	case h_small: return 10;
	case h_span: return 10;
	case h_strike: return 10;
	case h_strong: return 30;
	case h_style: return 10;
	case h_sub: return 10;
	case h_sup: return 10;
	case h_table: return 10;
	case h_tbody: return 10;
	case h_td: return 10;
	case h_textarea: return 10;
	case h_tfoot : return 10;
	case h_th : return 10;
	case h_thead: return 10;
	case h_title: return 50;
	case h_tr: return 10;
	case h_tt: return 10;
	case h_u: return 20;
	case h_ul: return 10;
	case h_var: return 10;
	case h_url: return 50;
	case h_vertical: return 10;
	case bogon: return 10;
	default: return 10;
	}
	return 10;
}

string TagScanner::decode_htmltag(TagScanner::htmltag tag) const
{
	switch(tag) {
	case h_a: return "a";
	case h_abbr: return "abbr";
	case h_acronym: return "acronym";
	case h_address: return "address";
	case h_applet: return "applet";
	case h_area: return "area";
	case h_b: return "b";
	case h_base: return "base";
	case h_basefont: return "basefont";
	case h_bdo: return "bdo";
	case h_big: return "big";
	case h_blockquote: return "blockquote";
	case h_body: return "body";
	case h_br: return "br";
	case h_button: return "button";
	case h_caption: return "caption";
	case h_center: return "center";
	case h_cite: return "cite";
	case h_code: return "code";
	case h_col: return "col";
	case h_colgroup: return "colgroup";
	case h_dd: return "dd";
	case h_del: return "del";
	case h_dfn: return "dfn";
	case h_dir: return "dir";
	case h_div: return "div";
	case h_dl: return "dl";
	case h_dt: return "dt";
	case h_em: return "em";
	case h_fieldset: return "fieldset";
	case h_font: return "font";
	case h_form: return "form";
	case h_frame: return "frame";
	case h_frameset: return "frameset";
	case h_h1: return "h1";
	case h_h2: return "h2";
	case h_h3: return "h3";
	case h_h4: return "h4";
	case h_h5: return "h5";
	case h_h6: return "h6";
	case h_head: return "head";
	case h_hr: return "hr";
	case h_html: return "html";
	case h_i: return "i";
	case h_iframe: return "iframe";
	case h_img: return "img";
	case h_input: return "input";
	case h_ins: return "ins";
	case h_isindex: return "isindex";
	case h_kbd: return "kbd";
	case h_label: return "label";
	case h_legend: return "legend";
	case h_li: return "li";
	case h_link: return "link";
	case h_map: return "map";
	case h_menu: return "menu";
	case h_meta: return "meta";
	case h_noframes: return "noframes";
	case h_noscript: return "noscript";
	case h_object: return "object";
	case h_ol: return "ol";
	case h_optgroup: return "optgroup";
	case h_option: return "option";
	case h_p: return "p";
	case h_param: return "param";
	case h_pre: return "pre";
	case h_q: return "q";
	case h_s: return "s";
	case h_samp: return "samp";
	case h_script: return "script";
	case h_select: return "select";
	case h_small: return "small";
	case h_span: return "span";
	case h_strike: return "strike";
	case h_strong: return "strong";
	case h_style: return "style";
	case h_sub: return "sub";
	case h_sup: return "sup";
	case h_table: return "table";
	case h_tbody: return "tbody";
	case h_td: return "td";
	case h_textarea: return "textarea";
	case h_tfoot : return "tfoot ";
	case h_th : return "th ";
	case h_thead: return "thead";
	case h_title: return "title";
	case h_tr: return "tr";
	case h_tt: return "tt";
	case h_u: return "u";
	case h_ul: return "ul";
	case h_var: return "var";
	case h_url: return "url";
	case h_vertical: return "vertical";
	case bogon: return "!!!bogon";
	default: return "unrecognized";
	}
	return "bogon";
}


string TagScanner::decode_htmlattr(TagScanner::htmlattr attr) const
{
	switch (attr) {
  case a_action: return "action";
  case a_alink: return "alink";
  case a_alt: return "alt";
  case a_archive: return "archive";
  case a_background: return "background";
  case a_bgcolor: return "bgcolor";
  case a_checked: return "checked";
  case a_cite: return "cite";
  case a_class: return "class";
  case a_classid: return "classid";
  case a_code: return "code";
  case a_codebase: return "codebase";
  case a_codetype: return "codetype";
  case a_color: return "color";
  case a_cols: return "cols";
  case a_colspan: return "colspan";
  case a_content: return "content";
  case a_data: return "data";
  case a_datetime: return "datetime";
  case a_dir: return "dir";
  case a_frame: return "frame";
  case a_headers: return "headers";
  case a_href: return "href";
  case a_hreflang: return "hreflang";
  case a_http_equiv: return "http_equiv";
  case a_id: return "id";
  case a_label: return "label";
  case a_lang: return "lang";
  case a_language: return "language";
  case a_link: return "link";
  case a_longdesc: return "longdesc";
  case a_media: return "media";
  case a_method: return "method";
  case a_name: return "name";
  case a_object: return "object";
  case a_onchange: return "onchange";
  case a_onclick: return "onclick";
  case a_ondblclick: return "ondblclick";
  case a_onreset: return "onreset";
  case a_onselect: return "onselect";
  case a_onsubmit: return "onsubmit";
  case a_onunload: return "onunload";
  case a_profile: return "profile";
  case a_prompt: return "prompt";
  case a_rel: return "rel";
  case a_rev: return "rev";
  case a_rows: return "rows";
  case a_rowspan: return "rowspan";
  case a_rules: return "rules";
  case a_scheme: return "scheme";
  case a_scope: return "scope";
  case a_selected: return "selected";
  case a_shape: return "shape";
  case a_size: return "size";
  case a_span: return "span";
  case a_src: return "src";
  case a_start: return "start";
  case a_style: return "style";
  case a_summary: return "summary";
  case a_tabindex: return "tabindex";
  case a_target: return "target";
  case a_text: return "text";
  case a_title: return "title";
  case a_type: return "type";
  case a_valign: return "valign";
  case a_value: return "value";
  case a_valuetype: return "valuetype";
  case a_vlink: return "vlink";
  case a_enctype: return "enctype";
  case a_bogon: return "bogon";
	default: {} // impossible
	}
	return "bogon";
}



string TagScanner::decode_adtag(TagScanner::adtag adtag) const
{
	switch (adtag) {
	case d_ad: return "ad";
	case d_ads: return "ads";
	case d_adlog: return "adlog";
	case d_adview: return "adview";
	case d_adserver: return "adserver";
	case d_adtech: return "adtech";
	case d_adpopup: return "adpopup";
	case d_adclick: return "adclick";
	case d_adframe: return "adframe";
	case d_advertise: return "advertise";
	case d_phpads: return "phpads";
	case d_fastclick: return "fastclick";
	case d_doubleclick: return "doubleclick";
	default: {} // impossible
	}
	return "bogon";
}


string TagScanner::decode_metafield(TagScanner::metafield field) const
{
	switch (field) {
	case m_title: return "title";
	case m_keywords: return "keywords";
	case m_description: return "description";
	case m_bogon: return "bogon";
	default: {} // impossible
	}
	return "bogon";
}


}	/* namespace pv */


#ifdef DEBUG
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
	km::TagScanner tscan;


/*
	for (int a=0; a<91; ++a) {
		cout << "scan_htmltag(\"" << string(tags,a*10,taglen[a]) << "\"[" << taglen[a] << "]) = "
				 <<  tscan.decode_htmltag(tscan.scan_htmltag(buf,a*10,taglen[a])) << endl;
	}

	for (int a=0; a<91; ++a) {
		cout << "scan-htmltag(\"" << string(BUF,a*10,taglen[a]) << "\"[" << taglen[a] << "]) = "
				 <<  tscan.decode_htmltag(tscan.scan_htmltag(BUF,a*10,taglen[a])) << endl;
	}
*/

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
	km::TagScanner::htmltag tag;
	for (int t=0; t<5000; ++t) {
		for (int a=0; a<90; ++a) tag = km::TagScanner::scan_htmltag(buf,a*10,lenv[a]);
	}
	for (int t=0; t<5000; ++t) {
		for (int a=0; a<90; ++a) tag = km::TagScanner::scan_htmltag(BUF,a*10,lenv[a]);
	}
*/
}
#endif
 
