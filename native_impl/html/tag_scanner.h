/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: tag_scanner.h,v 1.2 2006/10/13 06:54:00 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_TAG_SCANNER_H
#define XQP_TAG_SCANNER_H

#include <string>


/*_______________________________________________________________________
|
| 	Sorting networks for HTML tag names.
|________________________________________________________________________*/

namespace xqp {

class tag_scanner
{
public:
// ----- this is the complete set of HTML 4.0 element names + some others ----- 
	enum htmltag {
	  h_a,						h_abbr,					h_acronym,			h_address,			h_applet,				h_area,
		h_b,						h_base, 				h_basefont,			h_bdo,					h_big,					h_blockquote,
		h_body,					h_br,						h_button,				h_caption,			h_center,				h_cite,
		h_code,					h_col,					h_colgroup, 		h_dd,						h_del,					h_dfn,
	  h_dir,					h_div,					h_dl,						h_dt,						h_em,						h_fieldset,
		h_font,					h_form,					h_frame,				h_frameset, 		h_h1,						h_h2,
		h_h3,						h_h4,						h_h5,						h_h6, 					h_head,					h_hr,
		h_html,					h_i,						h_iframe,				h_img,					h_input,				h_ins,
		h_isindex,			h_kbd,					h_label,				h_legend,				h_li,						h_link,
		h_map,					h_menu,					h_meta, 				h_noframes, 		h_noscript, 		h_object,
		h_ol,						h_optgroup, 		h_option,				h_p,						h_param, 				h_pre,
		h_q,						h_s,						h_samp,					h_script,				h_select,				h_small,
		h_span,					h_strike,				h_strong,				h_style,				h_sub,					h_sup,
		h_table,				h_tbody,				h_td, 					h_textarea, 		h_tfoot,				h_th,
		h_thead,				h_title,				h_tr,						h_tt,						h_u, 						h_ul,
		h_var,					h_url,					/* (non-html application tags) */
																		h_vertical,			h_doc,					h_docset,				h_docid,
		h_anchor0,			h_anchor1,			h_anchor2,			h_anchor3,			h_anchor4,			h_anchorphrase,				
		bogon
	};

// ----- this is the complete set of HTML 4.0 attribute names ----- 
/*
		a_abbr,					a_acceptcharset,a_accept,				a_accesskey,		a_action, 			a_align,
		a_alink,				a_alt,					a_archive,			a_axis,					a_background,		a_bgcolor,
		a_border,				a_cellpadding,	a_cellspacing,	a_char,					a_charoff,			a_charset,
		a_checked,			a_cite,					a_class,				a_classid,			a_clear,				a_code,
		a_codebase,			a_codetype,			a_color,				a_cols,					a_colspan,			a_compact,
		a_content,			a_coords,				a_data,					a_datetime,			a_declare,			a_defer,
		a_dir,					a_disabled,			a_enctype,			a_face,					a_for,					a_frame,
		a_frameborder,	a_headers,			a_height,				a_href,					a_hreflang,			a_hspace,
		a_http-equiv,		a_id,						a_ismap,				a_label,				a_lang,					a_language,
		a_link,					a_longdesc,			a_marginheight,	a_marginwidth,	a_maxlength,		a_media,
		a_method,				a_multiple,			a_name,					a_nohref,				a_noresize,			a_noshade,
		a_nowrap,				a_object,				a_onblur,				a_onchange,			a_onclick,			a_ondblclick,
		a_onfocus,			a_onkeydown,		a_onkeypress,		a_onkeyup,			a_onload,				a_onmousedown,
		a_onmousemove,	a_onmouseout,		a_onmouseover,	a_onmouseup,		a_onreset,			a_onselect,
		a_onsubmit,			a_onunload,			a_profile,			a_prompt,				a_readonly,			a_rel,
		a_rev,					a_rows,					a_rowspan,			a_rules,				a_scheme,				a_scope,
		a_scrolling,		a_selected,			a_shape,				a_size,					a_span,					a_src,
		a_standby,			a_start,				a_style,				a_summary,			a_tabindex,			a_target,
		a_text,					a_title,				a_type,					a_usemap,				a_valign,				a_value,
		a_valuetype,		a_version,			a_vlink,				a_vspace,				a_width
	};
*/

/* ----- This is the subset of attributes we care about ----- */
	enum htmlattr {
		a_action, 			a_alink,				a_alt,					a_archive,			a_background,		a_bgcolor,
		a_checked,			a_cite,					a_class,				a_classid,			a_code,					a_codebase,
		a_codetype,			a_color,				a_cols,					a_colspan,			a_content,			a_data,
		a_datetime,			a_dir,					a_frame,				a_headers,			a_href,					a_hreflang,			
		a_http_equiv,		a_id,						a_label,				a_lang,					a_language,			a_link,
		a_longdesc,			a_media,				a_method,				a_name,					a_object,				a_onchange,
		a_onclick,			a_ondblclick,		a_onreset,			a_onselect,			a_onsubmit,			a_onunload,
		a_profile,			a_prompt,				a_rel,					a_rev,					a_rows,					a_rowspan,
		a_rules,				a_scheme,				a_scope,				a_selected,			a_shape,				a_size,
		a_span,					a_src,					a_start,				a_style,				a_summary,			a_tabindex,
		a_target,				a_text,					a_title,				a_type,					a_valign,				a_value,
		a_valuetype,		a_vlink,				a_enctype,			a_bogon
	};

/* ----- List of advertising keywords ----- */
	enum adtag {
		d_ad,						d_ads,					d_adlog,				d_adview,				d_adserver,			d_adtech,
		d_adpopup,			d_adclick,			d_fastclick,		d_advertise,		d_phpads,				d_adframe,
		d_doubleclick,	d_bogon
	};

/* ----- List of meta tag fields of interest ----- */
	enum metafield {
		m_title,				m_keywords,			m_description,	m_bogon
	};


	htmltag		scan_htmltag(const char* buf, int offset, int length);
	htmlattr	scan_htmlattr(const char* buf, int offset, int length);
	adtag			scan_adtag(const char* buf, int offset, int length);
	metafield	scan_metafield(const char* buf, int offset, int length);

	static uint32_t tag_map(htmltag tag);
	static std::string decode_htmltag(htmltag tag);
	static std::string decode_htmlattr(htmlattr at);
	static std::string decode_adtag(adtag tag);
	static std::string decode_metafield(metafield f);

};


inline tag_scanner::htmltag tag_scanner::scan_htmltag(
	const char* buf,
	int offset,
	int len)
{
	if (len==0) return bogon;

	const char* p = &buf[offset];
	char p0,p1,p2,p3,p4,p5,p6,p7,p8,p9;
	p0=p1=p2=p3=p4=p5=p6=p7=p8=p9=' ';

	switch (len) {
	case 10: p9 = p[9]|0x20;
	case 9:  p8 = p[8]|0x20;
	case 8:  p7 = p[7]|0x20;
	case 7:  p6 = p[6]|0x20;
	case 6:  p5 = p[5]|0x20;
	case 5:  p4 = p[4]|0x20;
	case 4:  p3 = p[3]|0x20;
	case 3:  p2 = p[2]|0x20;
	case 2:  p1 = p[1]|0x20;
	case 1:  p0 = p[0]|0x20; break;
	default: return bogon; 
	}

	switch (p0-'a') {
	case 0: {	//if (*p=='a') {	// a,abbr,area,applet,address,acronym
		if (len==1) return h_a;
		if (len==4)
			return (p1=='r'&&p2=='e'&&p3=='a') ? h_area :
						 (p1=='b'&&p2=='b'&&p3=='r') ? h_abbr : bogon;
		if (len==6)
			return (p1=='p'&&p2=='p'&&p3=='l'&&p4=='e'&&p5=='t') ? h_applet : bogon;
		if (len==7)
			return (p1=='d'&&p2=='d'&&p3=='r'&&p4=='e'&&p5=='s'&&p6=='s') ? h_address :
						 (p1=='c'&&p2=='r'&&p3=='o'&&p4=='n'&&p5=='y'&&p6=='m') ? h_acronym : bogon;
		return bogon;
	}

	case 1:	{ //if (*p=='b') {	// b,br,body,blockquote,bdo,big,base,basefont
		if (len==1) return h_b;
		if (len==2&&p1=='r') return h_br;
		if (len==3)
			return (p1=='i'&&p2=='g') ? h_big :
						 (p1=='d'&&p2=='o') ? h_bdo : bogon;
		if (len==4)
			return (p1=='o'&&p2=='d'&&p3=='y') ? h_body :
						 (p1=='a'&&p2=='s'&&p3=='e') ? h_base : bogon;
		return
			(len==6&&p1=='u'&&p2=='t'&&p3=='t'&&p4=='o'&&p5=='n') ? h_button :
			(len==8&&p1=='a'&&p2=='s'&&p3=='e'&&p4=='f'&&p5=='o'&&p6=='n'&&p7=='t') ? h_basefont :
			(len==10&&p1=='l'&&p2=='o'&&p3=='c'&&p4=='k'&&p5=='q'&&p6=='u'&&p7=='o'
																										&&p8=='t'&&p9=='e') ? h_blockquote :
			bogon;
	}

	case 2: {	//if (*p=='c') {	// caption,center,cite,col,colgroup,code
		if (len==3)
			return (p1=='o'&&p2=='l') ? h_col : bogon;
		if (len==4)
			return (p1=='o'&&p2=='d'&&p3=='e') ? h_code :
						 (p1=='i'&&p2=='t'&&p3=='e') ? h_cite : bogon;
		return
			(len==6&&p1=='e'&&p2=='n'&&p3=='t'&&p4=='e'&&p5=='r') ? h_center :
			(len==7&&p1=='a'&&p2=='p'&&p3=='t'&&p4=='i'&&p5=='o'&&p6=='n') ? h_caption :
			(len==8&&p1=='o'&&p2=='l'&&p3=='g'&&p4=='r'&&p5=='o'&&p6=='u'&&p7=='p') ? h_colgroup :
			bogon;
	}

	case 3:	{	//if (*p=='d') {	// div,dir,dd,dl,dt,del,dfn
		if (len==3)
			return (p1=='i'&&p2=='v') ? h_div :
						 (p1=='i'&&p2=='r') ? h_dir : 
						 (p1=='e'&&p2=='l') ? h_del :
						 (p1=='f'&&p2=='n') ? h_dfn : bogon;
		if (len==2)
			return (p1=='d') ? h_dd : (p1=='l') ? h_dl : (p1=='t') ? h_dt : bogon;
		return bogon;
	}

	case 4:	{ //if (*p=='e') {	// em
		return (len=2 && p1=='m') ? h_em : bogon;
	}

	case 5:	{ //if (*p=='f') {	// fieldset,font,form,frame,frameset
		if (len==4) 
			return (p1=='o'&&p2=='n'&&p3=='t') ? h_font :
						 (p1=='o'&&p2=='r'&&p3=='m') ? h_form : bogon;
		if (len==5) 
			return (p1=='r'&&p2=='a'&&p3=='m'&&p4=='e') ? h_frame : bogon;
		if (len==8)
			return (p1=='r'&&p2=='a'&&p3=='m'&&p4=='e'&&p5=='s'&&p6=='e'&&p7=='t') ? h_frameset :
						 (p1=='i'&&p2=='e'&&p3=='l'&&p4=='d'&&p5=='s'&&p6=='e'&&p7=='t') ? h_fieldset : bogon;
		return bogon;
	}

	case 7:	{ //if (*p=='h') {	// h1,h2,h3,h4,h5,h6,hr,head,html
		if (len==2)
			return (p1=='1') ? h_h1 : (p1=='2') ? h_h2 : (p1=='3') ? h_h3 : 
			       (p1=='4') ? h_h4 : (p1=='5') ? h_h5 : (p1=='6') ? h_h6 :
						 (p1=='r') ? h_hr : bogon;
		if (len==4)
			return (p1=='e'&&p2=='a'&&p3=='d') ? h_head :
						 (p1=='t'&&p2=='m'&&p3=='l') ? h_html : bogon;
		return bogon;
	}

	case 8:	{ //if (*p=='i') {	// i,img,ins,input,iframe,isindex
		if (len==1) return h_i;
		if (len==3)
			return (p1=='m'&&p2=='g') ? h_img : (p1=='n'&&p2=='s') ? h_ins : bogon; 
		return
			(len==5&&p1=='n'&&p2=='p'&&p3=='u'&&p4=='t') ? h_input :
			(len==6&&p1=='f'&&p2=='r'&&p3=='a'&&p4=='m'&&p5=='e') ? h_iframe :
		  (len==7&&p1=='s'&&p2=='i'&&p3=='n'&&p4=='d'&&p5=='e'&&p6=='x') ? h_isindex :
			bogon;
	}

	case 10: { //if (*p=='k') {	// kbd
		return
			(len==3&&p1=='b'&&p2=='d') ? h_kbd :
			bogon;
	}

	case 11: { //if (*p=='l') {	// li,link,label,legend
		return
			(len==2&&p1=='i') ? h_li :
		  (len==4&&p1=='i'&&p2=='n'&&p3=='k') ? h_link :
		  (len==5&&p1=='a'&&p2=='b'&&p3=='e'&&p4=='l') ? h_label :
		  (len==6&&p1=='e'&&p2=='g'&&p3=='e'&&p4=='n'&&p5=='d') ? h_legend :
			bogon;
	}

	case 12: { //if (*p=='m') {	// meta,menu,map
		return
			(len==4&&p1=='e'&&p2=='t'&&p3=='a') ? h_meta :
			(len==4&&p1=='e'&&p2=='n'&&p3=='u') ? h_menu :
		  (len==3&&p1=='a'&&p2=='p') ? h_map :
			bogon;
	}

	case 13: { //if (*p=='n') {	// noframes,noscript
		if (len!=8) return bogon;
		return
			(p1=='o'&&p2=='f'&&p3=='r'&&p4=='a'&&p5=='m'&&p6=='e'&&p7=='s') ? h_noframes :
		  (p1=='o'&&p2=='s'&&p3=='c'&&p4=='r'&&p5=='i'&&p6=='p'&&p7=='t') ? h_noscript :
			bogon;
	}

	case 14: { //if (*p=='o') {	// ol, option,object,optgroup
		return
			(len==2&&p1=='l') ? h_ol :
		  (len==6&&p1=='p'&&p2=='t'&&p3=='i'&&p4=='o'&&p5=='n') ? h_option :
		  (len==6&&p1=='b'&&p2=='j'&&p3=='e'&&p4=='c'&&p5=='t') ? h_object :
		  (len==8&&p1=='p'&&p2=='t'&&p3=='g'&&p4=='r'&&p5=='o'&&p6=='u'&&p7=='p') ? h_optgroup :
			bogon;
	}

	case 15: { //if (*p=='p') {	// p,pre,param
		return
			(len==1) ? h_p :
		  (len==3&&p1=='r'&&p2=='e') ? h_pre :
		  (len==5&&p1=='a'&&p2=='r'&&p3=='a'&&p4=='m') ? h_param :
			bogon;
	}

	case 16: { //if (*p=='q') {	// q
		return (len==1) ? h_q : bogon;
	}

	case 18: { //if (*p=='s') {	// s,sub,sup,span,samp,style,small,script,strike,strong,select
		if (len==1) return h_s;
		if (len==3)
			return (p1=='u'&&p2=='b') ? h_sub :
						 (p1=='u'&&p2=='p') ? h_sup : bogon;
		if (len==4)
			return (p1=='p'&&p2=='a'&&p3=='n') ? h_span :
						 (p1=='a'&&p2=='m'&&p3=='p') ? h_samp : bogon;
		if (len==5)
			return (p1=='t'&&p2=='y'&&p3=='l'&&p4=='e') ? h_style :
						 (p1=='m'&&p2=='a'&&p3=='l'&&p4=='l') ? h_small : bogon;
		if (len==6)
			return (p1=='c'&&p2=='r'&&p3=='i'&&p4=='p'&&p5=='t') ? h_script :
						 (p1=='t'&&p2=='r'&&p3=='o'&&p4=='n'&&p5=='g') ? h_strong : 
						 (p1=='e'&&p2=='l'&&p3=='e'&&p4=='c'&&p5=='t') ? h_select : 
						 (p1=='t'&&p2=='r'&&p3=='i'&&p4=='k'&&p5=='e') ? h_strike : bogon;
		return bogon;
	}

	case 19: { //if (*p=='t') {	// td,tr,tt,th,table,title,thead,tbody,tfoot,textarea
		if (len==2)
			return (p1=='d') ? h_td : (p1=='r') ? h_tr :
						 (p1=='t') ? h_tt : (p1=='h') ? h_th : bogon;
		if (len==5)
			return (p1=='a'&&p2=='b'&&p3=='l'&&p4=='e') ? h_table :
						 (p1=='i'&&p2=='t'&&p3=='l'&&p4=='e') ? h_title :
						 (p1=='h'&&p2=='e'&&p3=='a'&&p4=='d') ? h_thead :
						 (p1=='b'&&p2=='o'&&p3=='d'&&p4=='y') ? h_tbody :
						 (p1=='f'&&p2=='o'&&p3=='o'&&p4=='t') ? h_tfoot : bogon;
		if (len==8)
			return (p1=='e'&&p2=='x'&&p3=='t'&&p4=='a'&&
						  p5=='r'&&p6=='e'&&p7=='a') ? h_textarea : bogon;
		return bogon;
	} 

	case 20: { //if (*p=='u') {	// u,ul
		if (len==1) return h_u;
		if (len==2&&p1=='l') return h_ul;
		return bogon;
	}

	case 21: { //if (*p=='v') {	// var
		return (len==3&&p1=='a'&&p2=='r') ? h_var : bogon;
	}
	case 23: { //if (*p=='x') {	// var
		return (len==3&&p1=='m'&&p2=='l') ? h_script : bogon;
	}
	default:
		return bogon;
	}
}


/*_______________________________________________________________________
|
|	Sorting network for HTML attribute names.
|________________________________________________________________________*/
inline tag_scanner::htmlattr tag_scanner::scan_htmlattr(
	const char* buf,
	int offset,
	int len)
{
	if (len==0) return a_bogon;

	const char* p = &buf[offset];
	char p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
	p0=p1=p2=p3=p4=p5=p6=p7=p8=p9=p10=' ';

	switch (len) {
	case 11: p10 = p[10]|0x20;
	case 10: p9 = p[9]|0x20;
	case 9:  p8 = p[8]|0x20;
	case 8:  p7 = p[7]|0x20;
	case 7:  p6 = p[6]|0x20;
	case 6:  p5 = p[5]|0x20;
	case 5:  p4 = p[4]|0x20;
	case 4:  p3 = p[3]|0x20;
	case 3:  p2 = p[2]|0x20;
	case 2:  p1 = p[1]|0x20;
	case 1:  p0 = p[0]|0x20; break;
	default: return a_bogon; 
	}


	switch (p0-'a') {
  case 0:		// 'a' = first char
    if (len==3)
      return (p1=='l'&&p2=='t') ? a_alt : 
              a_bogon;
    if (len==5)
      return (p1=='l'&&p2=='i'&&p3=='n'&&p4=='k') ? a_alink : 
              a_bogon;
    if (len==6)
      return (p1=='c'&&p2=='t'&&p3=='i'&&p4=='o'&&p5=='n') ? a_action : 
              a_bogon;
    if (len==7)
      return (p1=='r'&&p2=='c'&&p3=='h'&&p4=='i'&&p5=='v'&&p6=='e') ? a_archive : 
              a_bogon;
    return a_bogon;
  case 1:		// 'b' = first char
    if (len==7)
      return (p1=='g'&&p2=='c'&&p3=='o'&&p4=='l'&&p5=='o'&&p6=='r') ? a_bgcolor : 
              a_bogon;
    if (len==10)
      return (p1=='a'&&p2=='c'&&p3=='k'&&p4=='g'&&p5=='r'&&p6=='o'
																			 &&p7=='u'&&p8=='n'&&p9=='d') ? a_background : 
              a_bogon;
    return a_bogon;
  case 2:		// 'c' = first char
    if (len==4)
      return (p1=='i'&&p2=='t'&&p3=='e') ? a_cite : 
             (p1=='o'&&p2=='d'&&p3=='e') ? a_code : 
             (p1=='o'&&p2=='l'&&p3=='s') ? a_cols : 
              a_bogon;
    if (len==5)
      return (p1=='l'&&p2=='a'&&p3=='s'&&p4=='s') ? a_class : 
             (p1=='o'&&p2=='l'&&p3=='o'&&p4=='r') ? a_color : 
              a_bogon;
    if (len==7)
      return (p1=='h'&&p2=='e'&&p3=='c'&&p4=='k'&&p5=='e'&&p6=='d') ? a_checked : 
             (p1=='o'&&p2=='l'&&p3=='s'&&p4=='p'&&p5=='a'&&p6=='n') ? a_colspan : 
             (p1=='o'&&p2=='n'&&p3=='t'&&p4=='e'&&p5=='n'&&p6=='t') ? a_content : 
              a_bogon;
    if (len==8)
      return (p1=='o'&&p2=='d'&&p3=='e'&&p4=='b'&&p5=='a'&&p6=='s'&&p7=='e') ? a_codebase : 
              a_bogon;
    return a_bogon;
  case 3:		// 'd' = first char
    if (len==3)
      return (p1=='i'&&p2=='r') ? a_dir : 
              a_bogon;
    if (len==4)
      return (p1=='a'&&p2=='t'&&p3=='a') ? a_data : 
              a_bogon;
    if (len==8)
      return (p1=='a'&&p2=='t'&&p3=='e'&&p4=='t'&&p5=='i'&&p6=='m'&&p7=='e') ? a_datetime : 
              a_bogon;
    return a_bogon;
  case 4:		// 'e' = first char
    if (len==7)
      return (p1=='n'&&p2=='c'&&p3=='t'&&p4=='y'&&p5=='p'&&p6=='e') ? a_enctype : 
              a_bogon;
    return a_bogon;
  case 5:		// 'f' = first char
    if (len==5)
      return (p1=='r'&&p2=='a'&&p3=='m'&&p4=='e') ? a_frame : 
              a_bogon;
    return a_bogon;
  case 7:		// 'h' = first char
    if (len==4)
      return (p1=='r'&&p2=='e'&&p3=='f') ? a_href : 
              a_bogon;
    if (len==7)
      return (p1=='e'&&p2=='a'&&p3=='d'&&p4=='e'&&p5=='r'&&p6=='s') ? a_headers : 
              a_bogon;
    if (len==10)
      return (p1=='t'&&p2=='t'&&p3=='p'&&p4=='-'&&p5=='e'&&p6=='q'
																			 &&p7=='u'&&p8=='i'&&p9=='v') ? a_http_equiv : 
              a_bogon;
    return a_bogon;
  case 8:		// 'i' = first char
    if (len==2)
      return (p1=='d') ? a_id : 
              a_bogon;
    return a_bogon;
  case 11:		// 'l' = first char
    if (len==4)
      return (p1=='a'&&p2=='n'&&p3=='g') ? a_lang : 
             (p1=='i'&&p2=='n'&&p3=='k') ? a_link : 
              a_bogon;
    if (len==5)
      return (p1=='a'&&p2=='b'&&p3=='e'&&p4=='l') ? a_label : 
              a_bogon;
    if (len==8)
      return (p1=='a'&&p2=='n'&&p3=='g'&&p4=='u'&&p5=='a'&&p6=='g'&&p7=='e') ? a_language : 
             (p1=='o'&&p2=='n'&&p3=='g'&&p4=='d'&&p5=='e'&&p6=='s'&&p7=='c') ? a_longdesc : 
              a_bogon;
    return a_bogon;
  case 12:		// 'm' = first char
    if (len==5)
      return (p1=='e'&&p2=='d'&&p3=='i'&&p4=='a') ? a_media : 
              a_bogon;
    if (len==6)
      return (p1=='e'&&p2=='t'&&p3=='h'&&p4=='o'&&p5=='d') ? a_method : 
              a_bogon;
    return a_bogon;
  case 13:		// 'n' = first char
    if (len==4)
      return (p1=='a'&&p2=='m'&&p3=='e') ? a_name : 
              a_bogon;
    return a_bogon;
  case 14:		// 'o' = first char
    if (len==6)
      return (p1=='b'&&p2=='j'&&p3=='e'&&p4=='c'&&p5=='t') ? a_object : 
              a_bogon;
    if (len==7)
      return (p1=='n'&&p2=='c'&&p3=='l'&&p4=='i'&&p5=='c'&&p6=='k') ? a_onclick : 
             (p1=='n'&&p2=='r'&&p3=='e'&&p4=='s'&&p5=='e'&&p6=='t') ? a_onreset : 
              a_bogon;
    if (len==8)
      return (p1=='n'&&p2=='c'&&p3=='h'&&p4=='a'&&p5=='n'&&p6=='g'&&p7=='e') ? a_onchange : 
             (p1=='n'&&p2=='s'&&p3=='e'&&p4=='l'&&p5=='e'&&p6=='c'&&p7=='t') ? a_onselect : 
             (p1=='n'&&p2=='s'&&p3=='u'&&p4=='b'&&p5=='m'&&p6=='i'&&p7=='t') ? a_onsubmit : 
             (p1=='n'&&p2=='u'&&p3=='n'&&p4=='l'&&p5=='o'&&p6=='a'&&p7=='d') ? a_onunload : 
              a_bogon;
    if (len==10)
      return (p1=='n'&&p2=='d'&&p3=='b'&&p4=='l'&&p5=='c'&&p6=='l'
																			 &&p7=='i'&&p8=='c'&&p9=='k') ? a_ondblclick : 
              a_bogon;
    return a_bogon;
  case 15:		// 'p' = first char
    if (len==6)
      return (p1=='r'&&p2=='o'&&p3=='m'&&p4=='p'&&p5=='t') ? a_prompt : 
              a_bogon;
    if (len==7)
      return (p1=='r'&&p2=='o'&&p3=='f'&&p4=='i'&&p5=='l'&&p6=='e') ? a_profile : 
              a_bogon;
    return a_bogon;
  case 17:		// 'r' = first char
    if (len==3)
      return (p1=='e'&&p2=='l') ? a_rel : 
             (p1=='e'&&p2=='v') ? a_rev : 
              a_bogon;
    if (len==4)
      return (p1=='o'&&p2=='w'&&p3=='s') ? a_rows : 
              a_bogon;
    if (len==5)
      return (p1=='u'&&p2=='l'&&p3=='e'&&p4=='s') ? a_rules : 
              a_bogon;
    if (len==7)
      return (p1=='o'&&p2=='w'&&p3=='s'&&p4=='p'&&p5=='a'&&p6=='n') ? a_rowspan : 
              a_bogon;
    return a_bogon;
  case 18:		// 's' = first char
    if (len==3)
      return (p1=='r'&&p2=='c') ? a_src : 
              a_bogon;
    if (len==4)
      return (p1=='i'&&p2=='z'&&p3=='e') ? a_size : 
             (p1=='p'&&p2=='a'&&p3=='n') ? a_span : 
              a_bogon;
    if (len==5)
      return (p1=='c'&&p2=='o'&&p3=='p'&&p4=='e') ? a_scope : 
             (p1=='h'&&p2=='a'&&p3=='p'&&p4=='e') ? a_shape : 
             (p1=='t'&&p2=='a'&&p3=='r'&&p4=='t') ? a_start : 
             (p1=='t'&&p2=='y'&&p3=='l'&&p4=='e') ? a_style : 
              a_bogon;
    if (len==7)
      return (p1=='u'&&p2=='m'&&p3=='m'&&p4=='a'&&p5=='r'&&p6=='y') ? a_summary : 
              a_bogon;
    if (len==8)
      return (p1=='e'&&p2=='l'&&p3=='e'&&p4=='c'&&p5=='t'&&p6=='e'&&p7=='d') ? a_selected : 
              a_bogon;
    return a_bogon;
  case 19:		// 't' = first char
    if (len==4)
      return (p1=='e'&&p2=='x'&&p3=='t') ? a_text : 
             (p1=='y'&&p2=='p'&&p3=='e') ? a_type : 
              a_bogon;
    if (len==5)
      return (p1=='i'&&p2=='t'&&p3=='l'&&p4=='e') ? a_title : 
              a_bogon;
    if (len==6)
      return (p1=='a'&&p2=='r'&&p3=='g'&&p4=='e'&&p5=='t') ? a_target : 
              a_bogon;
    if (len==8)
      return (p1=='a'&&p2=='b'&&p3=='i'&&p4=='n'&&p5=='d'&&p6=='e'&&p7=='x') ? a_tabindex : 
              a_bogon;
    return a_bogon;
  case 21:		// 'v' = first char
    if (len==5)
      return (p1=='a'&&p2=='l'&&p3=='u'&&p4=='e') ? a_value : 
             (p1=='l'&&p2=='i'&&p3=='n'&&p4=='k') ? a_vlink : 
              a_bogon;
    if (len==6)
      return (p1=='a'&&p2=='l'&&p3=='i'&&p4=='g'&&p5=='n') ? a_valign : 
              a_bogon;
    if (len==9)
      return (p1=='a'&&p2=='l'&&p3=='u'&&p4=='e'&&p5=='t'&&p6=='y'
																								&&p7=='p'&&p8=='e') ? a_valuetype : 
              a_bogon;
    return a_bogon;
	default:
		return a_bogon;
	}
}


/*_______________________________________________________________________
|
|	Sorting network for ad tags.
|________________________________________________________________________*/
inline tag_scanner::adtag tag_scanner::scan_adtag(
	const char* buf,
	int offset,
	int len)
{
	if (len==0) return d_bogon;
	const char* p = &buf[offset];
	char p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
	switch (len) {
	case 11: p10 = p[10]|0x20;
	case 10: p9 = p[9]|0x20;
	case 9:  p8 = p[8]|0x20;
	case 8:  p7 = p[7]|0x20;
	case 7:  p6 = p[6]|0x20;
	case 6:  p5 = p[5]|0x20;
	case 5:  p4 = p[4]|0x20;
	case 4:  p3 = p[3]|0x20;
	case 3:  p2 = p[2]|0x20;
	case 2:  p1 = p[1]|0x20;
	case 1:  p0 = p[0]|0x20; break;
	default: return d_bogon; 
	}

	switch (p0-'a') {
	case 0:               // 'a' = first char
	  if (len==2)
	    return (p1=='d') ? d_ad :
	            d_bogon;
	  if (len==3)
	    return (p1=='d'&&p2=='s') ? d_ads :
	            d_bogon;
	  if (len==5)
	    return (p1=='d'&&p2=='l'&&p3=='o'&&p4=='g') ? d_adlog :
	            d_bogon;
	  if (len==6)
	    return (p1=='d'&&p2=='t'&&p3=='e'&&p4=='c'&&p5=='h') ? d_adtech :
	           (p1=='d'&&p2=='v'&&p3=='i'&&p4=='e'&&p5=='w') ? d_adview :
	            d_bogon;
	  if (len==7)
	    return (p1=='d'&&p2=='f'&&p3=='r'&&p4=='a'&&p5=='m'&&p6=='e') ? d_adframe :
	           (p1=='d'&&p2=='p'&&p3=='o'&&p4=='p'&&p5=='u'&&p6=='p') ? d_adpopup :
	           (p1=='d'&&p2=='c'&&p3=='l'&&p4=='i'&&p5=='c'&&p6=='k') ? d_adclick :
	            d_bogon;
	  if (len==8)
	    return (p1=='d'&&p2=='s'&&p3=='e'&&p4=='r'&&p5=='v'&&p6=='e'&&p7=='r') ? d_adserver :
	            d_bogon;
	  if (len==9)
	    return (p1=='d'&&p2=='v'&&p3=='e'&&p4=='r'&&p5=='t'&&p6=='i'
																								&&p7=='s'&&p8=='e') ? d_advertise :
	            d_bogon;
	  return d_bogon;
	case 3:               // 'd' = first char
	  if (len==11)
	    return (p1=='o'&&p2=='u'&&p3=='b'&&p4=='l'&&p5=='e'&&p6=='c'
															&&p7=='l'&&p8=='i'&&p9=='c'&&p10=='k') ? d_doubleclick :
	            d_bogon;
	  return d_bogon;
	case 5:               // 'f' = first char
	  if (len==9)
	    return (p1=='a'&&p2=='s'&&p3=='t'&&p4=='c'&&p5=='l'&&p6=='i'&&p7=='c'&&p8=='k') ? d_fastclick :
	            d_bogon;
	  return d_bogon;
	case 15:              // 'p' = first char
	  if (len==6)
	    return (p1=='h'&&p2=='p'&&p3=='a'&&p4=='d'&&p5=='s') ? d_phpads :
	            d_bogon;
	  return d_bogon;
	default:
	  return d_bogon;
	}
}


inline tag_scanner::metafield tag_scanner::scan_metafield(
	const char* buf, int offset, int len)
{
	if (len==5  && strncasecmp(&buf[offset],"title",5)==0) return m_title;
	if (len==8  && strncasecmp(&buf[offset],"keywords",8)==0) return m_keywords;
	if (len==11 && strncasecmp(&buf[offset],"description",11)==0) return m_description;
	return m_bogon;
}


}	/* namespace xqp */
#endif	/* XQP_TAG_SCANNER_H */
