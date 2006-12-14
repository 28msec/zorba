/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: scan_handler.cpp,v 1.1.1.1 2006/10/09 06:58:35 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 Paul Pedersen.  All Rights Reserved.
 *
 */

#include "scan_handler.h"

#include <iostream>
#include <string>
#include "../core/hashmap.h"
#include "tag_scanner.h"

using namespace std;
namespace pv {

// static initializers
bool scan_handler::static_init = false;
hash32map<char> scan_handler::breaktagTable(1024,0.6f);
hashmap<unsigned short> scan_handler::entityMap(4096,0.6f);

scan_handler::scan_handler()
{
	if (!static_init) {
		static_init = true;
		for (unsigned i=0; i<994; ++i) {
			entityMap.put(entities[i].name, entities[i].codepoint);
		}
		init_breaktags();
	}
}

void scan_handler::init_breaktags()
{
	breaktagTable.put_unsync(tag_scanner::h_a,0);
	breaktagTable.put_unsync(tag_scanner::h_abbr,0);
	breaktagTable.put_unsync(tag_scanner::h_acronym,0);
	breaktagTable.put_unsync(tag_scanner::h_address,1);
	breaktagTable.put_unsync(tag_scanner::h_applet,1);
	breaktagTable.put_unsync(tag_scanner::h_area,0);
	breaktagTable.put_unsync(tag_scanner::h_b,0);
	breaktagTable.put_unsync(tag_scanner::h_base,0);
	breaktagTable.put_unsync(tag_scanner::h_basefont,0);
	breaktagTable.put_unsync(tag_scanner::h_bdo,0);
	breaktagTable.put_unsync(tag_scanner::h_big,0);
	breaktagTable.put_unsync(tag_scanner::h_blockquote,1);
	breaktagTable.put_unsync(tag_scanner::h_body,1);
	breaktagTable.put_unsync(tag_scanner::h_br,1);
	breaktagTable.put_unsync(tag_scanner::h_button,1);
	breaktagTable.put_unsync(tag_scanner::h_caption,0);
	breaktagTable.put_unsync(tag_scanner::h_center,1);
	breaktagTable.put_unsync(tag_scanner::h_cite,0);
	breaktagTable.put_unsync(tag_scanner::h_code,0);
	breaktagTable.put_unsync(tag_scanner::h_col,0);
	breaktagTable.put_unsync(tag_scanner::h_colgroup,0);
	breaktagTable.put_unsync(tag_scanner::h_dd,1);
	breaktagTable.put_unsync(tag_scanner::h_del,0);
	breaktagTable.put_unsync(tag_scanner::h_dfn,0);
	breaktagTable.put_unsync(tag_scanner::h_dir,1);
	breaktagTable.put_unsync(tag_scanner::h_div,1);
	breaktagTable.put_unsync(tag_scanner::h_dl,1);
	breaktagTable.put_unsync(tag_scanner::h_dt,1);
	breaktagTable.put_unsync(tag_scanner::h_em,0);
	breaktagTable.put_unsync(tag_scanner::h_fieldset,1);
	breaktagTable.put_unsync(tag_scanner::h_font,0);
	breaktagTable.put_unsync(tag_scanner::h_form,1);
	breaktagTable.put_unsync(tag_scanner::h_frame,1);
	breaktagTable.put_unsync(tag_scanner::h_frameset,1);
	breaktagTable.put_unsync(tag_scanner::h_h1,1);
	breaktagTable.put_unsync(tag_scanner::h_h2,1);
	breaktagTable.put_unsync(tag_scanner::h_h3,1);
	breaktagTable.put_unsync(tag_scanner::h_h4,1);
	breaktagTable.put_unsync(tag_scanner::h_h5,1);
	breaktagTable.put_unsync(tag_scanner::h_h6,1);
	breaktagTable.put_unsync(tag_scanner::h_head,1);
	breaktagTable.put_unsync(tag_scanner::h_hr,1);
	breaktagTable.put_unsync(tag_scanner::h_html,1);
	breaktagTable.put_unsync(tag_scanner::h_i,0);
	breaktagTable.put_unsync(tag_scanner::h_iframe,1);
	breaktagTable.put_unsync(tag_scanner::h_img,1);
	breaktagTable.put_unsync(tag_scanner::h_input,1);
	breaktagTable.put_unsync(tag_scanner::h_ins,0);
	breaktagTable.put_unsync(tag_scanner::h_isindex,1);
	breaktagTable.put_unsync(tag_scanner::h_kbd,0);
	breaktagTable.put_unsync(tag_scanner::h_label,0);
	breaktagTable.put_unsync(tag_scanner::h_legend,1);
	breaktagTable.put_unsync(tag_scanner::h_li,1);
	breaktagTable.put_unsync(tag_scanner::h_link,0);
	breaktagTable.put_unsync(tag_scanner::h_map,0);
	breaktagTable.put_unsync(tag_scanner::h_menu,1);
	breaktagTable.put_unsync(tag_scanner::h_meta,1);
	breaktagTable.put_unsync(tag_scanner::h_noframes,0);
	breaktagTable.put_unsync(tag_scanner::h_noscript,0);
	breaktagTable.put_unsync(tag_scanner::h_object,0);
	breaktagTable.put_unsync(tag_scanner::h_ol,1);
	breaktagTable.put_unsync(tag_scanner::h_optgroup,0);
	breaktagTable.put_unsync(tag_scanner::h_option,0);
	breaktagTable.put_unsync(tag_scanner::h_p,1);
	breaktagTable.put_unsync(tag_scanner::h_param,1);
	breaktagTable.put_unsync(tag_scanner::h_pre,1);
	breaktagTable.put_unsync(tag_scanner::h_q,0);
	breaktagTable.put_unsync(tag_scanner::h_s,0);
	breaktagTable.put_unsync(tag_scanner::h_samp,0);
	breaktagTable.put_unsync(tag_scanner::h_script,0);
	breaktagTable.put_unsync(tag_scanner::h_select,1);
	breaktagTable.put_unsync(tag_scanner::h_small,0);
	breaktagTable.put_unsync(tag_scanner::h_span,0);
	breaktagTable.put_unsync(tag_scanner::h_strike,0);
	breaktagTable.put_unsync(tag_scanner::h_strong,0);
	breaktagTable.put_unsync(tag_scanner::h_style,1);
	breaktagTable.put_unsync(tag_scanner::h_sub,0);
	breaktagTable.put_unsync(tag_scanner::h_sup,0);
	breaktagTable.put_unsync(tag_scanner::h_table,1);
	breaktagTable.put_unsync(tag_scanner::h_tbody,1);
	breaktagTable.put_unsync(tag_scanner::h_td,1);
	breaktagTable.put_unsync(tag_scanner::h_textarea,1);
	breaktagTable.put_unsync(tag_scanner::h_tfoot,1);
	breaktagTable.put_unsync(tag_scanner::h_th,1);
	breaktagTable.put_unsync(tag_scanner::h_thead,1);
	breaktagTable.put_unsync(tag_scanner::h_title,1);
	breaktagTable.put_unsync(tag_scanner::h_tr,1);
	breaktagTable.put_unsync(tag_scanner::h_tt,1);
	breaktagTable.put_unsync(tag_scanner::h_u,0);
	breaktagTable.put_unsync(tag_scanner::h_ul,1);
	breaktagTable.put_unsync(tag_scanner::h_var,0);
	breaktagTable.put_unsync(tag_scanner::h_url,0);
}


void scan_handler::adup(const char* buff, int offset, int length)
{
	string s(buff,offset,length);;
	cout << "adup: " << (length>0?s:"") << endl;
}


void  scan_handler::aname(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "aname: " << (length>0?s:"") << endl;
}


void scan_handler::aval(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "aval: " << (length>0?s:"") << endl;
}


void scan_handler::entity(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "entity: " << (length>0?s:"") << endl;
	unsigned short code;
  entityMap.get(s, code);
	ent = (char)code;
}


void scan_handler::eof(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "eof" << endl;
}


void scan_handler::etag(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "etag: " << (length>0?s:"") << endl;
}


void scan_handler::gi(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "gi: " << (length>0?s:"") << endl;
}


void scan_handler::pcdata(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "pcdata: " << (length>0?s:"") << endl;
}


void scan_handler::pi(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "pi: " << (length>0?s:"") << endl;
}


void scan_handler::pitarget(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "pitarget: " << (length>0?s:"") << endl;
}


void scan_handler::stagc(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "stagc: " << (length>0?s:"") << endl;
}


void scan_handler::cmnt(const char* buff, int offset, int length)
{
	string s(buff,offset,length);
	cout << "cmnt: " << (length>0?s:"") << endl;
}


unsigned short scan_handler::getEntity() { return ent; }


}	/* namespace pv */

