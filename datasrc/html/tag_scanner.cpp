/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: tag_scanner.cpp,v 1.2 2006/10/13 06:54:00 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "tag_scanner.h"

#include <string>

using namespace std;
namespace xqp {

string tag_scanner::decode_htmltag(
	tag_scanner::htmltag tag) 
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


string tag_scanner::decode_htmlattr(
	tag_scanner::htmlattr attr) 
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


string tag_scanner::decode_adtag(
	tag_scanner::adtag adtag) 
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


string tag_scanner::decode_metafield(tag_scanner::metafield field) 
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


}	/* namespace xqp */
