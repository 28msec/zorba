/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: scan_handler.h,v 1.1.1.1 2006/10/09 06:58:35 Paul Pedersen Exp $
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

#ifndef XQP_SCAN_HANDLER_H
#define XQP_SCAN_HANDLER_H

#include <string>

#include "../util/hashmap.h"

namespace xqp {

//tokens
#define EOF_								 0		// 	eof
#define WS									 1		// 	whitespace
#define DEF									 2		//	default
#define CR									 3		// 	cr  = 0xa
#define LF									 4		// 	lf  = 0xd
#define LT									 5		//	'<' = 0x3c
#define GT									 6		//	'>' = 0x3e
#define SL									 7		//	'/' 
#define EQ									 8		//	'=' 
#define DASH								 9		//	'-' 
#define AMP									10		//	'&' 
#define APOS								11		//	''' 
#define QUOT								12		//	'"' 
#define BANG								13		//	'!' 
#define HOOK								14		//	'?' 
#define PER 								15		//	'%' 
#define C										16		//	'C' 
#define D										17		//	'D' 
#define A										18		//	'A' 
#define T										19		//	'T' 
#define LBRA								20		//	'[' 
#define RBRA								21		//	']' 

//states
#define S_ANAME			 				 0
#define S_APOS			 				 1
#define S_AVAL			 				 2
#define S_CDATA			 				 3
#define S_CDATA2						 4
#define S_COM								 5
#define S_COMCRLF				 		 6
#define S_COMD			 				 7
#define S_CRLF			 				 8
#define S_CCRLF			 				 9
#define S_DECL							10
#define S_DECL2							11
#define S_ENT								12
#define S_EQ								13
#define S_ETAG							14
#define S_GI								15
#define S_PCDATA						16
#define S_PI								17
#define S_PICRLF						18
#define S_PITARGET					19
#define S_QUOT							20
#define S_STAGC							21
#define S_TAG								22
#define S_TAGWS							23
#define S_EMPTYTAG					24
#define S_BB								25
#define S_BBC								26
#define S_BBCD							27
#define S_BBCDA							28
#define S_BBCDAT						29
#define S_BBCDATA						30
#define S_CDSECT						31
#define S_CDSECT1						32
#define S_CDSECT2						33
#define S_DONE							34

//actions
#define A_ADUP							 0
#define A_ADUP_SAVE					 1
#define A_ADUP_STAGC				 2
#define A_ANAME							 3
#define A_ANAME_ADUP_STAGC	 4
#define A_AVAL							 5
#define A_AVAL_STAGC				 6
#define A_CDATA							 7
#define A_CMNT							 8
#define A_ENTITY						 9
#define A_ETAG							10
#define A_EMPTYTAG					11
#define A_ANAME_ADUP				12
#define A_GI								13
#define A_GI_STAGC					14
#define A_LF								15
#define A_LT								16
#define A_LT_PCDATA					17
#define A_PCDATA						18
#define A_PCDATA_SAVE_PUSH	19
#define A_PI								20
#define A_PITARGET					21
#define A_PITARGET_PI				22
#define A_SAVE							23
#define A_SAVE_PUSH					24
#define A_SKIP							25
#define A_SP								26
#define A_STAGC							27
#define A_UNGET							28
#define A_UNSAVE_PCDATA			29

/*_______________________________________________________________________
|
|  An interface that Scanners use to report events
|  in the input stream.
|  Per-method documentation appears in scan_handler.cpp.
|________________________________________________________________________*/

static struct {
  unsigned short codepoint;
  const char* name;
} const entities[] = {
	{0x0021,"excl"},     // exclamation mark 
	{0x0022,"quot"},     // quotation mark 
	{0x0023,"num"},      // number sign 
	{0x0024,"dollar"},   // dollar sign 
	{0x0025,"percnt"},   // percent sign 
	{0x0026,"amp"},      // ampersand 
	{0x0027,"apos"},     // apostrophe 
	{0x0028,"lpar"},     // left parenthesis 
	{0x0029,"rpar"},     // right parenthesis 
	{0x002A,"ast"},      // asterisk 
	{0x002B,"plus"},     // plus sign 
	{0x002C,"comma"},    // comma 
	{0x002D,"hyphen"},   // hyphen-minus 
	{0x002E,"period"},   // full stop 
	{0x002F,"sol"},      // solidus 
	{0x003A,"colon"},    // colon 
	{0x003B,"semi"},     // semicolon 
	{0x003C,"lt"},       // less-than sign 
	{0x003D,"equals"},   // equals sign 
	{0x003E,"gt"},       // greater-than sign 
	{0x003F,"quest"},    // question mark 
	{0x0040,"commat"},   // commercial at 
	{0x005B,"lsqb"},     // left square bracket 
	{0x005C,"bsol"},     // reverse solidus 
	{0x005C,"sbsol"},    // reverse solidus 
	{0x005D,"rsqb"},     // right square bracket 
	{0x005F,"lowbar"},   // low line 
	{0x0060,"grave"},    // grave accent 
	{0x007B,"lcub"},     // left curly bracket 
	{0x007C,"verbar"},   // vertical line 
	{0x007D,"rcub"},     // right curly bracket 
	{0x00A0,"nbsp"},     // no-break space 
	{0x00A1,"iexcl"},    // inverted exclamation mark 
	{0x00A2,"cent"},     // cent sign 
	{0x00A3,"pound"},    // pound sign 
	{0x00A4,"curren"},   // currency sign 
	{0x00A5,"yen"},      // yen sign 
	{0x00A6,"brvbar"},   // broken bar 
	{0x00A7,"sect"},     // section sign 
	{0x00A8,"Dot"},      // diaeresis 
	{0x00A8,"die"},      // diaeresis 
	{0x00A8,"uml"},      // diaeresis 
	{0x00A9,"copy"},     // copyright sign 
	{0x00AA,"ordf"},     // feminine ordinal indicator 
	{0x00AB,"laquo"},    // left-pointing double angle quotation mark 
	{0x00AC,"not"},      // not sign 
	{0x00AD,"shy"},      // soft hyphen 
	{0x00AE,"reg"},      // registered sign 
	{0x00AF,"macr"},     // macron 
	{0x00B0,"deg"},      // degree sign 
	{0x00B1,"plusmn"},   // plus-minus sign 
	{0x00B2,"sup2"},     // superscript two 
	{0x00B3,"sup3"},     // superscript three 
	{0x00B4,"acute"},    // acute accent 
	{0x00B5,"micro"},    // micro sign 
	{0x00B6,"para"},     // pilcrow sign 
	{0x00B7,"middot"},   // middle dot 
	{0x00B8,"cedil"},    // cedilla 
	{0x00B9,"sup1"},     // superscript one 
	{0x00BA,"ordm"},     // masculine ordinal indicator 
	{0x00BB,"raquo"},    // right-pointing double angle quotation mark 
	{0x00BC,"frac14"},   // vulgar fraction one quarter 
	{0x00BD,"frac12"},   // vulgar fraction one half 
	{0x00BD,"half"},     // vulgar fraction one half 
	{0x00BE,"frac34"},   // vulgar fraction three quarters 
	{0x00BF,"iquest"},   // inverted question mark 
	{0x00C0,"Agrave"},   // latin capital letter a with grave 
	{0x00C1,"Aacute"},   // latin capital letter a with acute 
	{0x00C2,"Acirc"},    // latin capital letter a with circumflex 
	{0x00C3,"Atilde"},   // latin capital letter a with tilde 
	{0x00C4,"Auml"},     // latin capital letter a with diaeresis 
	{0x00C5,"Aring"},    // latin capital letter a with ring above 
	{0x00C6,"AElig"},    // latin capital letter ae 
	{0x00C7,"Ccedil"},   // latin capital letter c with cedilla 
	{0x00C8,"Egrave"},   // latin capital letter e with grave 
	{0x00C9,"Eacute"},   // latin capital letter e with acute 
	{0x00CA,"Ecirc"},    // latin capital letter e with circumflex 
	{0x00CB,"Euml"},     // latin capital letter e with diaeresis 
	{0x00CC,"Igrave"},   // latin capital letter i with grave 
	{0x00CD,"Iacute"},   // latin capital letter i with acute 
	{0x00CE,"Icirc"},    // latin capital letter i with circumflex 
	{0x00CF,"Iuml"},     // latin capital letter i with diaeresis 
	{0x00D0,"ETH"},      // latin capital letter eth 
	{0x00D1,"Ntilde"},   // latin capital letter n with tilde 
	{0x00D2,"Ograve"},   // latin capital letter o with grave 
	{0x00D3,"Oacute"},   // latin capital letter o with acute 
	{0x00D4,"Ocirc"},    // latin capital letter o with circumflex 
	{0x00D5,"Otilde"},   // latin capital letter o with tilde 
	{0x00D6,"Ouml"},     // latin capital letter o with diaeresis 
	{0x00D7,"times"},    // multiplication sign 
	{0x00D8,"Oslash"},   // latin capital letter o with stroke 
	{0x00D9,"Ugrave"},   // latin capital letter u with grave 
	{0x00DA,"Uacute"},   // latin capital letter u with acute 
	{0x00DB,"Ucirc"},    // latin capital letter u with circumflex 
	{0x00DC,"Uuml"},     // latin capital letter u with diaeresis 
	{0x00DD,"Yacute"},   // latin capital letter y with acute 
	{0x00DE,"THORN"},    // latin capital letter thorn 
	{0x00DF,"szlig"},    // latin small letter sharp s 
	{0x00E0,"agrave"},   // latin small letter a with grave 
	{0x00E1,"aacute"},   // latin small letter a with acute 
	{0x00E2,"acirc"},    // latin small letter a with circumflex 
	{0x00E3,"atilde"},   // latin small letter a with tilde 
	{0x00E4,"auml"},     // latin small letter a with diaeresis 
	{0x00E5,"aring"},    // latin small letter a with ring above 
	{0x00E6,"aelig"},    // latin small letter ae 
	{0x00E7,"ccedil"},   // latin small letter c with cedilla 
	{0x00E8,"egrave"},   // latin small letter e with grave 
	{0x00E9,"eacute"},   // latin small letter e with acute 
	{0x00EA,"ecirc"},    // latin small letter e with circumflex 
	{0x00EB,"euml"},     // latin small letter e with diaeresis 
	{0x00EC,"igrave"},   // latin small letter i with grave 
	{0x00ED,"iacute"},   // latin small letter i with acute 
	{0x00EE,"icirc"},    // latin small letter i with circumflex 
	{0x00EF,"iuml"},     // latin small letter i with diaeresis 
	{0x00F0,"eth"},      // latin small letter eth 
	{0x00F1,"ntilde"},   // latin small letter n with tilde 
	{0x00F2,"ograve"},   // latin small letter o with grave 
	{0x00F3,"oacute"},   // latin small letter o with acute 
	{0x00F4,"ocirc"},    // latin small letter o with circumflex 
	{0x00F5,"otilde"},   // latin small letter o with tilde 
	{0x00F6,"ouml"},     // latin small letter o with diaeresis 
	{0x00F7,"divide"},   // division sign 
	{0x00F8,"oslash"},   // latin small letter o with stroke 
	{0x00F9,"ugrave"},   // latin small letter u with grave 
	{0x00FA,"uacute"},   // latin small letter u with acute 
	{0x00FB,"ucirc"},    // latin small letter u with circumflex 
	{0x00FC,"uuml"},     // latin small letter u with diaeresis 
	{0x00FD,"yacute"},   // latin small letter y with acute 
	{0x00FE,"thorn"},    // latin small letter thorn 
	{0x00FF,"yuml"},     // latin small letter y with diaeresis 
	{0x0100,"Amacr"},    // latin capital letter a with macron 
	{0x0101,"amacr"},    // latin small letter a with macron 
	{0x0102,"Abreve"},   // latin capital letter a with breve 
	{0x0103,"abreve"},   // latin small letter a with breve 
	{0x0104,"Aogon"},    // latin capital letter a with ogonek 
	{0x0105,"aogon"},    // latin small letter a with ogonek 
	{0x0106,"Cacute"},   // latin capital letter c with acute 
	{0x0107,"cacute"},   // latin small letter c with acute 
	{0x0108,"Ccirc"},    // latin capital letter c with circumflex 
	{0x0109,"ccirc"},    // latin small letter c with circumflex 
	{0x010A,"Cdot"},     // latin capital letter c with dot above 
	{0x010B,"cdot"},     // latin small letter c with dot above 
	{0x010C,"Ccaron"},   // latin capital letter c with caron 
	{0x010D,"ccaron"},   // latin small letter c with caron 
	{0x010E,"Dcaron"},   // latin capital letter d with caron 
	{0x010F,"dcaron"},   // latin small letter d with caron 
	{0x0110,"Dstrok"},   // latin capital letter d with stroke 
	{0x0111,"dstrok"},   // latin small letter d with stroke 
	{0x0112,"Emacr"},    // latin capital letter e with macron 
	{0x0113,"emacr"},    // latin small letter e with macron 
	{0x0116,"Edot"},     // latin capital letter e with dot above 
	{0x0117,"edot"},     // latin small letter e with dot above 
	{0x0118,"Eogon"},    // latin capital letter e with ogonek 
	{0x0119,"eogon"},    // latin small letter e with ogonek 
	{0x011A,"Ecaron"},   // latin capital letter e with caron 
	{0x011B,"ecaron"},   // latin small letter e with caron 
	{0x011C,"Gcirc"},    // latin capital letter g with circumflex 
	{0x011D,"gcirc"},    // latin small letter g with circumflex 
	{0x011E,"Gbreve"},   // latin capital letter g with breve 
	{0x011F,"gbreve"},   // latin small letter g with breve 
	{0x0120,"Gdot"},     // latin capital letter g with dot above 
	{0x0121,"gdot"},     // latin small letter g with dot above 
	{0x0122,"Gcedil"},   // latin capital letter g with cedilla 
	{0x0123,"gcedil"},   // latin small letter g with cedilla 
	{0x0124,"Hcirc"},    // latin capital letter h with circumflex 
	{0x0125,"hcirc"},    // latin small letter h with circumflex 
	{0x0126,"Hstrok"},   // latin capital letter h with stroke 
	{0x0127,"hstrok"},   // latin small letter h with stroke 
	{0x0128,"Itilde"},   // latin capital letter i with tilde 
	{0x0129,"itilde"},   // latin small letter i with tilde 
	{0x012A,"Imacr"},    // latin capital letter i with macron 
	{0x012B,"imacr"},    // latin small letter i with macron 
	{0x012E,"Iogon"},    // latin capital letter i with ogonek 
	{0x012F,"iogon"},    // latin small letter i with ogonek 
	{0x0130,"Idot"},     // latin capital letter i with dot above 
	{0x0131,"inodot"},   // latin small letter dotless i 
	{0x0131,"inodot"},   // latin small letter dotless i 
	{0x0132,"IJlig"},    // latin capital ligature ij 
	{0x0133,"ijlig"},    // latin small ligature ij 
	{0x0134,"Jcirc"},    // latin capital letter j with circumflex 
	{0x0135,"jcirc"},    // latin small letter j with circumflex 
	{0x0136,"Kcedil"},   // latin capital letter k with cedilla 
	{0x0137,"kcedil"},   // latin small letter k with cedilla 
	{0x0138,"kgreen"},   // latin small letter kra 
	{0x0139,"Lacute"},   // latin capital letter l with acute 
	{0x013A,"lacute"},   // latin small letter l with acute 
	{0x013B,"Lcedil"},   // latin capital letter l with cedilla 
	{0x013C,"lcedil"},   // latin small letter l with cedilla 
	{0x013D,"Lcaron"},   // latin capital letter l with caron 
	{0x013E,"lcaron"},   // latin small letter l with caron 
	{0x013F,"Lmidot"},   // latin capital letter l with middle dot 
	{0x0140,"lmidot"},   // latin small letter l with middle dot 
	{0x0141,"Lstrok"},   // latin capital letter l with stroke 
	{0x0142,"lstrok"},   // latin small letter l with stroke 
	{0x0143,"Nacute"},   // latin capital letter n with acute 
	{0x0144,"nacute"},   // latin small letter n with acute 
	{0x0145,"Ncedil"},   // latin capital letter n with cedilla 
	{0x0146,"ncedil"},   // latin small letter n with cedilla 
	{0x0147,"Ncaron"},   // latin capital letter n with caron 
	{0x0148,"ncaron"},   // latin small letter n with caron 
	{0x0149,"napos"},    // latin small letter n preceded by apostrophe 
	{0x014A,"ENG"},      // latin capital letter eng 
	{0x014B,"eng"},      // latin small letter eng 
	{0x014C,"Omacr"},    // latin capital letter o with macron 
	{0x014D,"omacr"},    // latin small letter o with macron 
	{0x0150,"Odblac"},   // latin capital letter o with double acute 
	{0x0151,"odblac"},   // latin small letter o with double acute 
	{0x0152,"OElig"},    // latin capital ligature oe 
	{0x0153,"oelig"},    // latin small ligature oe 
	{0x0154,"Racute"},   // latin capital letter r with acute 
	{0x0155,"racute"},   // latin small letter r with acute 
	{0x0156,"Rcedil"},   // latin capital letter r with cedilla 
	{0x0157,"rcedil"},   // latin small letter r with cedilla 
	{0x0158,"Rcaron"},   // latin capital letter r with caron 
	{0x0159,"rcaron"},   // latin small letter r with caron 
	{0x015A,"Sacute"},   // latin capital letter s with acute 
	{0x015B,"sacute"},   // latin small letter s with acute 
	{0x015C,"Scirc"},    // latin capital letter s with circumflex 
	{0x015D,"scirc"},    // latin small letter s with circumflex 
	{0x015E,"Scedil"},   // latin capital letter s with cedilla 
	{0x015F,"scedil"},   // latin small letter s with cedilla 
	{0x0160,"Scaron"},   // latin capital letter s with caron 
	{0x0161,"scaron"},   // latin small letter s with caron 
	{0x0162,"Tcedil"},   // latin capital letter t with cedilla 
	{0x0163,"tcedil"},   // latin small letter t with cedilla 
	{0x0164,"Tcaron"},   // latin capital letter t with caron 
	{0x0165,"tcaron"},   // latin small letter t with caron 
	{0x0166,"Tstrok"},   // latin capital letter t with stroke 
	{0x0167,"tstrok"},   // latin small letter t with stroke 
	{0x0168,"Utilde"},   // latin capital letter u with tilde 
	{0x0169,"utilde"},   // latin small letter u with tilde 
	{0x016A,"Umacr"},    // latin capital letter u with macron 
	{0x016B,"umacr"},    // latin small letter u with macron 
	{0x016C,"Ubreve"},   // latin capital letter u with breve 
	{0x016D,"ubreve"},   // latin small letter u with breve 
	{0x016E,"Uring"},    // latin capital letter u with ring above 
	{0x016F,"uring"},    // latin small letter u with ring above 
	{0x0170,"Udblac"},   // latin capital letter u with double acute 
	{0x0171,"udblac"},   // latin small letter u with double acute 
	{0x0172,"Uogon"},    // latin capital letter u with ogonek 
	{0x0173,"uogon"},    // latin small letter u with ogonek 
	{0x0174,"Wcirc"},    // latin capital letter w with circumflex 
	{0x0175,"wcirc"},    // latin small letter w with circumflex 
	{0x0176,"Ycirc"},    // latin capital letter y with circumflex 
	{0x0177,"ycirc"},    // latin small letter y with circumflex 
	{0x0178,"Yuml"},     // latin capital letter y with diaeresis 
	{0x0179,"Zacute"},   // latin capital letter z with acute 
	{0x017A,"zacute"},   // latin small letter z with acute 
	{0x017B,"Zdot"},     // latin capital letter z with dot above 
	{0x017C,"zdot"},     // latin small letter z with dot above 
	{0x017D,"Zcaron"},   // latin capital letter z with caron 
	{0x017E,"zcaron"},   // latin small letter z with caron 
	{0x0192,"fnof"},     // latin small letter f with hook 
	{0x01F5,"gacute"},   // latin small letter g with acute 
	{0x02C6,"circ"},     // modifier letter circumflex accent 
	{0x02C7,"caron"},    // caron 
	{0x02D8,"breve"},    // breve 
	{0x02D9,"dot"},      // dot above 
	{0x02DA,"ring"},     // ring above 
	{0x02DB,"ogon"},     // ogonek 
	{0x02DC,"tilde"},    // small tilde 
	{0x02DD,"dblac"},    // double acute accent 
	{0x0386,"Aacgr"},    // greek capital letter alpha with tonos 
	{0x0388,"Eacgr"},    // greek capital letter epsilon with tonos 
	{0x0389,"EEacgr"},   // greek capital letter eta with tonos 
	{0x038A,"Iacgr"},    // greek capital letter iota with tonos 
	{0x038C,"Oacgr"},    // greek capital letter omicron with tonos 
	{0x038E,"Uacgr"},    // greek capital letter upsilon with tonos 
	{0x038F,"OHacgr"},   // greek capital letter omega with tonos 
	{0x0390,"idiagr"},   // greek small letter iota with dialytika and tonos 
	{0x0391,"Agr"},      // greek capital letter alpha 
	{0x0391,"Alpha"},    // greek capital letter alpha 
	{0x0392,"Beta"},     // greek capital letter beta 
	{0x0392,"Bgr"},      // greek capital letter beta 
	{0x0393,"Gamma"},    // greek capital letter gamma 
	{0x0393,"Ggr"},      // greek capital letter gamma 
	{0x0393,"b.Gamma"},  // greek capital letter gamma 
	{0x0394,"Delta"},    // greek capital letter delta 
	{0x0394,"Dgr"},      // greek capital letter delta 
	{0x0394,"b.Delta"},  // greek capital letter delta 
	{0x0395,"Egr"},      // greek capital letter epsilon 
	{0x0395,"Epsilon"},  // greek capital letter epsilon 
	{0x0396,"Zeta"},     // greek capital letter zeta 
	{0x0396,"Zgr"},      // greek capital letter zeta 
	{0x0397,"EEgr"},     // greek capital letter eta 
	{0x0397,"Eta"},      // greek capital letter eta 
	{0x0398,"THgr"},     // greek capital letter theta 
	{0x0398,"Theta"},    // greek capital letter theta 
	{0x0398,"b.Theta"},  // greek capital letter theta 
	{0x0399,"Igr"},      // greek capital letter iota 
	{0x0399,"Iota"},     // greek capital letter iota 
	{0x039A,"Kappa"},    // greek capital letter kappa 
	{0x039A,"Kgr"},      // greek capital letter kappa 
	{0x039B,"Lambda"},   // greek capital letter lamda 
	{0x039B,"Lgr"},      // greek capital letter lamda 
	{0x039B,"b.Lambda"}, // greek capital letter lamda 
	{0x039C,"Mgr"},      // greek capital letter mu 
	{0x039C,"Mu"},       // greek capital letter mu 
	{0x039D,"Ngr"},      // greek capital letter nu 
	{0x039D,"Nu"},       // greek capital letter nu 
	{0x039E,"Xgr"},      // greek capital letter xi 
	{0x039E,"Xi"},       // greek capital letter xi 
	{0x039E,"b.Xi"},     // greek capital letter xi 
	{0x039F,"Ogr"},      // greek capital letter omicron 
	{0x039F,"Omicron"},  // greek capital letter omicron 
	{0x03A0,"Pgr"},      // greek capital letter pi 
	{0x03A0,"Pi"},       // greek capital letter pi 
	{0x03A0,"b.Pi"},     // greek capital letter pi 
	{0x03A1,"Rgr"},      // greek capital letter rho 
	{0x03A1,"Rho"},      // greek capital letter rho 
	{0x03A3,"Sgr"},      // greek capital letter sigma 
	{0x03A3,"Sigma"},    // greek capital letter sigma 
	{0x03A3,"b.Sigma"},  // greek capital letter sigma 
	{0x03A4,"Tau"},      // greek capital letter tau 
	{0x03A4,"Tgr"},      // greek capital letter tau 
	{0x03A5,"Ugr"},      // greek capital letter upsilon 
	{0x03A5,"Upsi"},     // greek capital letter upsilon 
	{0x03A5,"Upsilon"},  // greek capital letter upsilon 
	{0x03A5,"b.Upsi"},   // greek capital letter upsilon 
	{0x03A6,"PHgr"},     // greek capital letter phi 
	{0x03A6,"Phi"},      // greek capital letter phi 
	{0x03A6,"b.Phi"},    // greek capital letter phi 
	{0x03A7,"Chi"},      // greek capital letter chi 
	{0x03A7,"KHgr"},     // greek capital letter chi 
	{0x03A8,"PSgr"},     // greek capital letter psi 
	{0x03A8,"Psi"},      // greek capital letter psi 
	{0x03A8,"b.Psi"},    // greek capital letter psi 
	{0x03A9,"OHgr"},     // greek capital letter omega 
	{0x03A9,"Omega"},    // greek capital letter omega 
	{0x03A9,"b.Omega"},  // greek capital letter omega 
	{0x03AA,"Idigr"},    // greek capital letter iota with dialytika 
	{0x03AB,"Udigr"},    // greek capital letter upsilon with dialytika 
	{0x03AC,"aacgr"},    // greek small letter alpha with tonos 
	{0x03AD,"eacgr"},    // greek small letter epsilon with tonos 
	{0x03AE,"eeacgr"},   // greek small letter eta with tonos 
	{0x03AF,"iacgr"},    // greek small letter iota with tonos 
	{0x03B0,"udiagr"},   // greek small letter upsilon with dialytika and tonos 
	{0x03B1,"agr"},      // greek small letter alpha 
	{0x03B1,"alpha"},    // greek small letter alpha 
	{0x03B1,"b.alpha"},  // greek small letter alpha 
	{0x03B2,"b.beta"},   // greek small letter beta 
	{0x03B2,"beta"},     // greek small letter beta 
	{0x03B2,"bgr"},      // greek small letter beta 
	{0x03B3,"b.gamma"},  // greek small letter gamma 
	{0x03B3,"gamma"},    // greek small letter gamma 
	{0x03B3,"ggr"},      // greek small letter gamma 
	{0x03B4,"b.delta"},  // greek small letter delta 
	{0x03B4,"delta"},    // greek small letter delta 
	{0x03B4,"dgr"},      // greek small letter delta 
	{0x03B5,"b.epsi"},   // greek small letter epsilon 
	{0x03B5,"b.epsis"},  // greek small letter epsilon 
	{0x03B5,"b.epsiv"},  // greek small letter epsilon 
	{0x03B5,"egr"},      // greek small letter epsilon 
	{0x03B5,"epsi"},     // greek small letter epsilon 
	{0x03B5,"epsilon"},  // greek small letter epsilon 
	{0x03B6,"b.zeta"},   // greek small letter zeta 
	{0x03B6,"zeta"},     // greek small letter zeta 
	{0x03B6,"zgr"},      // greek small letter zeta 
	{0x03B7,"b.eta"},    // greek small letter eta 
	{0x03B7,"eegr"},     // greek small letter eta 
	{0x03B7,"eta"},      // greek small letter eta 
	{0x03B8,"b.thetas"}, // greek small letter theta 
	{0x03B8,"theta"},    // greek small letter theta 
	{0x03B8,"thetas"},   // greek small letter theta 
	{0x03B8,"thgr"},     // greek small letter theta 
	{0x03B9,"b.iota"},   // greek small letter iota 
	{0x03B9,"igr"},      // greek small letter iota 
	{0x03B9,"iota"},     // greek small letter iota 
	{0x03BA,"b.kappa"},  // greek small letter kappa 
	{0x03BA,"kappa"},    // greek small letter kappa 
	{0x03BA,"kgr"},      // greek small letter kappa 
	{0x03BB,"b.lambda"}, // greek small letter lamda 
	{0x03BB,"lambda"},   // greek small letter lamda 
	{0x03BB,"lgr"},      // greek small letter lamda 
	{0x03BC,"b.mu"},     // greek small letter mu 
	{0x03BC,"mgr"},      // greek small letter mu 
	{0x03BC,"mu"},       // greek small letter mu 
	{0x03BD,"b.nu"},     // greek small letter nu 
	{0x03BD,"ngr"},      // greek small letter nu 
	{0x03BD,"nu"},       // greek small letter nu 
	{0x03BE,"b.xi"},     // greek small letter xi 
	{0x03BE,"xgr"},      // greek small letter xi 
	{0x03BE,"xi"},       // greek small letter xi 
	{0x03BF,"ogr"},      // greek small letter omicron 
	{0x03BF,"omicron"},  // greek small letter omicron 
	{0x03C0,"b.pi"},     // greek small letter pi 
	{0x03C0,"pgr"},      // greek small letter pi 
	{0x03C0,"pi"},       // greek small letter pi 
	{0x03C1,"b.rho"},    // greek small letter rho 
	{0x03C1,"rgr"},      // greek small letter rho 
	{0x03C1,"rho"},      // greek small letter rho 
	{0x03C2,"b.sigmav"}, // greek small letter final sigma 
	{0x03C2,"sfgr"},     // greek small letter final sigma 
	{0x03C2,"sigmaf"},   // greek small letter final sigma 
	{0x03C2,"sigmav"},   // greek small letter final sigma 
	{0x03C3,"b.sigma"},  // greek small letter sigma 
	{0x03C3,"sgr"},      // greek small letter sigma 
	{0x03C3,"sigma"},    // greek small letter sigma 
	{0x03C4,"b.tau"},    // greek small letter tau 
	{0x03C4,"tau"},      // greek small letter tau 
	{0x03C4,"tgr"},      // greek small letter tau 
	{0x03C5,"b.upsi"},   // greek small letter upsilon 
	{0x03C5,"ugr"},      // greek small letter upsilon 
	{0x03C5,"upsi"},     // greek small letter upsilon 
	{0x03C5,"upsilon"},  // greek small letter upsilon 
	{0x03C6,"b.phis"},   // greek small letter phi 
	{0x03C6,"phgr"},     // greek small letter phi 
	{0x03C6,"phi"},      // greek small letter phi 
	{0x03C6,"phis"},     // greek small letter phi 
	{0x03C7,"b.chi"},    // greek small letter chi 
	{0x03C7,"chi"},      // greek small letter chi 
	{0x03C7,"khgr"},     // greek small letter chi 
	{0x03C8,"b.psi"},    // greek small letter psi 
	{0x03C8,"psgr"},     // greek small letter psi 
	{0x03C8,"psi"},      // greek small letter psi 
	{0x03C9,"ohgr"},     // greek small letter omega 
	{0x03C9,"omega"},    // greek small letter omega 
	{0x03CA,"idigr"},    // greek small letter iota with dialytika 
	{0x03CB,"udigr"},    // greek small letter upsilon with dialytika 
	{0x03CC,"oacgr"},    // greek small letter omicron with tonos 
	{0x03CD,"uacgr"},    // greek small letter upsilon with tonos 
	{0x03CE,"b.omega"},  // greek small letter omega with tonos 
	{0x03CE,"ohacgr"},   // greek small letter omega with tonos 
	{0x03D1,"b.thetav"}, // greek theta symbol 
	{0x03D1,"thetasym"}, // greek theta symbol 
	{0x03D1,"thetav"},   // greek theta symbol 
	{0x03D2,"upsih"},    // greek upsilon with hook symbol 
	{0x03D5,"b.phiv"},   // greek phi symbol 
	{0x03D5,"phiv"},     // greek phi symbol 
	{0x03D6,"b.piv"},    // greek pi symbol 
	{0x03D6,"piv"},      // greek pi symbol 
	{0x03DC,"b.gammad"}, // greek letter digamma 
	{0x03DC,"gammad"},   // greek letter digamma 
	{0x03F0,"b.kappav"}, // greek kappa symbol 
	{0x03F0,"kappav"},   // greek kappa symbol 
	{0x03F1,"b.rhov"},   // greek rho symbol 
	{0x03F1,"rhov"},     // greek rho symbol 
	{0x0401,"IOcy"},     // cyrillic capital letter io 
	{0x0402,"DJcy"},     // cyrillic capital letter dje 
	{0x0403,"GJcy"},     // cyrillic capital letter gje 
	{0x0404,"Jukcy"},    // cyrillic capital letter ukrainian ie 
	{0x0405,"DScy"},     // cyrillic capital letter dze 
	{0x0406,"Iukcy"},    // cyrillic capital letter byelorussian-ukrainian i 
	{0x0407,"YIcy"},     // cyrillic capital letter yi 
	{0x0408,"Jsercy"},   // cyrillic capital letter je 
	{0x0409,"LJcy"},     // cyrillic capital letter lje 
	{0x040A,"NJcy"},     // cyrillic capital letter nje 
	{0x040B,"TSHcy"},    // cyrillic capital letter tshe 
	{0x040C,"KJcy"},     // cyrillic capital letter kje 
	{0x040E,"Ubrcy"},    // cyrillic capital letter short u 
	{0x040F,"DZcy"},     // cyrillic capital letter dzhe 
	{0x0410,"Acy"},      // cyrillic capital letter a 
	{0x0411,"Bcy"},      // cyrillic capital letter be 
	{0x0412,"Vcy"},      // cyrillic capital letter ve 
	{0x0413,"Gcy"},      // cyrillic capital letter ghe 
	{0x0414,"Dcy"},      // cyrillic capital letter de 
	{0x0415,"IEcy"},     // cyrillic capital letter ie 
	{0x0416,"ZHcy"},     // cyrillic capital letter zhe 
	{0x0417,"Zcy"},      // cyrillic capital letter ze 
	{0x0418,"Icy"},      // cyrillic capital letter i 
	{0x0419,"Jcy"},      // cyrillic capital letter short i 
	{0x041A,"Kcy"},      // cyrillic capital letter ka 
	{0x041B,"Lcy"},      // cyrillic capital letter el 
	{0x041C,"Mcy"},      // cyrillic capital letter em 
	{0x041D,"Ncy"},      // cyrillic capital letter en 
	{0x041E,"Ocy"},      // cyrillic capital letter o 
	{0x041F,"Pcy"},      // cyrillic capital letter pe 
	{0x0420,"Rcy"},      // cyrillic capital letter er 
	{0x0421,"Scy"},      // cyrillic capital letter es 
	{0x0422,"Tcy"},      // cyrillic capital letter te 
	{0x0423,"Ucy"},      // cyrillic capital letter u 
	{0x0424,"Fcy"},      // cyrillic capital letter ef 
	{0x0425,"KHcy"},     // cyrillic capital letter ha 
	{0x0426,"TScy"},     // cyrillic capital letter tse 
	{0x0427,"CHcy"},     // cyrillic capital letter che 
	{0x0428,"SHcy"},     // cyrillic capital letter sha 
	{0x0429,"SHCHcy"},   // cyrillic capital letter shcha 
	{0x042A,"HARDcy"},   // cyrillic capital letter hard sign 
	{0x042B,"Ycy"},      // cyrillic capital letter yeru 
	{0x042C,"SOFTcy"},   // cyrillic capital letter soft sign 
	{0x042D,"Ecy"},      // cyrillic capital letter e 
	{0x042E,"YUcy"},     // cyrillic capital letter yu 
	{0x042F,"YAcy"},     // cyrillic capital letter ya 
	{0x0430,"acy"},      // cyrillic small letter a 
	{0x0431,"bcy"},      // cyrillic small letter be 
	{0x0432,"vcy"},      // cyrillic small letter ve 
	{0x0433,"gcy"},      // cyrillic small letter ghe 
	{0x0434,"dcy"},      // cyrillic small letter de 
	{0x0435,"iecy"},     // cyrillic small letter ie 
	{0x0436,"zhcy"},     // cyrillic small letter zhe 
	{0x0437,"zcy"},      // cyrillic small letter ze 
	{0x0438,"icy"},      // cyrillic small letter i 
	{0x0439,"jcy"},      // cyrillic small letter short i 
	{0x043A,"kcy"},      // cyrillic small letter ka 
	{0x043B,"lcy"},      // cyrillic small letter el 
	{0x043C,"mcy"},      // cyrillic small letter em 
	{0x043D,"ncy"},      // cyrillic small letter en 
	{0x043E,"ocy"},      // cyrillic small letter o 
	{0x043F,"pcy"},      // cyrillic small letter pe 
	{0x0440,"rcy"},      // cyrillic small letter er 
	{0x0441,"scy"},      // cyrillic small letter es 
	{0x0442,"tcy"},      // cyrillic small letter te 
	{0x0443,"ucy"},      // cyrillic small letter u 
	{0x0444,"fcy"},      // cyrillic small letter ef 
	{0x0445,"khcy"},     // cyrillic small letter ha 
	{0x0446,"tscy"},     // cyrillic small letter tse 
	{0x0447,"chcy"},     // cyrillic small letter che 
	{0x0448,"shcy"},     // cyrillic small letter sha 
	{0x0449,"shchcy"},   // cyrillic small letter shcha 
	{0x044A,"hardcy"},   // cyrillic small letter hard sign 
	{0x044B,"ycy"},      // cyrillic small letter yeru 
	{0x044C,"softcy"},   // cyrillic small letter soft sign 
	{0x044D,"ecy"},      // cyrillic small letter e 
	{0x044E,"yucy"},     // cyrillic small letter yu 
	{0x044F,"yacy"},     // cyrillic small letter ya 
	{0x0451,"iocy"},     // cyrillic small letter io 
	{0x0452,"djcy"},     // cyrillic small letter dje 
	{0x0453,"gjcy"},     // cyrillic small letter gje 
	{0x0454,"jukcy"},    // cyrillic small letter ukrainian ie 
	{0x0455,"dscy"},     // cyrillic small letter dze 
	{0x0456,"iukcy"},    // cyrillic small letter byelorussian-ukrainian i 
	{0x0457,"yicy"},     // cyrillic small letter yi 
	{0x0458,"jsercy"},   // cyrillic small letter je 
	{0x0459,"ljcy"},     // cyrillic small letter lje 
	{0x045A,"njcy"},     // cyrillic small letter nje 
	{0x045B,"tshcy"},    // cyrillic small letter tshe 
	{0x045C,"kjcy"},     // cyrillic small letter kje 
	{0x045E,"ubrcy"},    // cyrillic small letter short u 
	{0x045F,"dzcy"},     // cyrillic small letter dzhe 
	{0x2002,"ensp"},     // en space 
	{0x2003,"emsp"},     // em space 
	{0x2004,"emsp13"},   // three-per-em space 
	{0x2005,"emsp14"},   // four-per-em space 
	{0x2007,"numsp"},    // figure space 
	{0x2008,"puncsp"},   // punctuation space 
	{0x2009,"thinsp"},   // thin space 
	{0x200A,"hairsp"},   // hair space 
	{0x200C,"zwnj"},     // zero width non-joiner 
	{0x200D,"zwj"},      // zero width joiner 
	{0x200E,"lrm"},      // left-to-right mark 
	{0x200F,"rlm"},      // right-to-left mark 
	{0x2010,"dash"},     // hyphen 
	{0x2013,"ndash"},    // en dash 
	{0x2014,"mdash"},    // em dash 
	{0x2015,"horbar"},   // horizontal bar 
	{0x2016,"Verbar"},   // double vertical line 
	{0x2018,"lsquo"},    // left single quotation mark 
	{0x2018,"rsquor"},   // left single quotation mark 
	{0x2019,"rsquo"},    // right single quotation mark 
	{0x201A,"lsquor"},   // single low-9 quotation mark 
	{0x201A,"sbquo"},    // single low-9 quotation mark 
	{0x201C,"ldquo"},    // left double quotation mark 
	{0x201C,"rdquor"},   // left double quotation mark 
	{0x201D,"rdquo"},    // right double quotation mark 
	{0x201E,"bdquo"},    // double low-9 quotation mark 
	{0x201E,"ldquor"},   // double low-9 quotation mark 
	{0x2020,"dagger"},   // dagger 
	{0x2021,"Dagger"},   // double dagger 
	{0x2022,"bull"},     // bullet 
	{0x2025,"nldr"},     // two dot leader 
	{0x2026,"hellip"},   // horizontal ellipsis 
	{0x2026,"mldr"},     // horizontal ellipsis 
	{0x2030,"permil"},   // per mille sign 
	{0x2032,"prime"},    // prime 
	{0x2032,"vprime"},   // prime 
	{0x2033,"Prime"},    // double prime 
	{0x2034,"tprime"},   // triple prime 
	{0x2035,"bprime"},   // reversed prime 
	{0x2039,"lsaquo"},   // single left-pointing angle quotation mark 
	{0x203A,"rsaquo"},   // single right-pointing angle quotation mark 
	{0x203E,"oline"},    // overline 
	{0x2041,"caret"},    // caret insertion point 
	{0x2043,"hybull"},   // hyphen bullet 
	{0x2044,"frasl"},    // fraction slash 
	{0x20AC,"euro"},     // euro 
	{0x20DB,"tdot"},     // combining three dots above 
	{0x20DC,"DotDot"},   // combining four dots above 
	{0x2105,"incare"},   // care of 
	{0x210B,"hamilt"},   // script capital h 
	{0x210F,"planck"},   // planck constant over two pi 
	{0x2111,"image"},    // black-letter capital i 
	{0x2112,"lagran"},   // script capital l 
	{0x2113,"ell"},      // script small l 
	{0x2116,"numero"},   // numero sign 
	{0x2117,"copysr"},   // sound recording copyright 
	{0x2118,"weierp"},   // script capital p 
	{0x211C,"real"},     // black-letter capital r 
	{0x211E,"rx"},       // prescription take 
	{0x2122,"trade"},    // trade mark sign 
	{0x2126,"ohm"},      // ohm sign 
	{0x212B,"angst"},    // angstrom sign 
	{0x212C,"bernou"},   // script capital b 
	{0x2133,"phmmat"},   // script capital m 
	{0x2134,"order"},    // script small o 
	{0x2135,"alefsym"},  // alef symbol 
	{0x2135,"aleph"},    // alef symbol 
	{0x2136,"beth"},     // bet symbol 
	{0x2137,"gimel"},    // gimel symbol 
	{0x2138,"daleth"},   // dalet symbol 
	{0x2153,"frac13"},   // vulgar fraction one third 
	{0x2154,"frac23"},   // vulgar fraction two thirds 
	{0x2155,"frac15"},   // vulgar fraction one fifth 
	{0x2156,"frac25"},   // vulgar fraction two fifths 
	{0x2157,"frac35"},   // vulgar fraction three fifths 
	{0x2158,"frac45"},   // vulgar fraction four fifths 
	{0x2159,"frac16"},   // vulgar fraction one sixth 
	{0x215A,"frac56"},   // vulgar fraction five sixths 
	{0x215B,"frac18"},   // vulgar fraction one eighth 
	{0x215C,"frac38"},   // vulgar fraction three eighths 
	{0x215D,"frac58"},   // vulgar fraction five eighths 
	{0x215E,"frac78"},   // vulgar fraction seven eighths 
	{0x2190,"larr"},     // leftwards arrow 
	{0x2191,"uarr"},     // upwards arrow 
	{0x2192,"rarr"},     // rightwards arrow 
	{0x2193,"darr"},     // downwards arrow 
	{0x2194,"harr"},     // left right arrow 
	{0x2194,"xhArr"},    // left right arrow 
	{0x2194,"xharr"},    // left right arrow 
	{0x2195,"varr"},     // up down arrow 
	{0x2196,"nwarr"},    // north west arrow 
	{0x2197,"nearr"},    // north east arrow 
	{0x2198,"drarr"},    // south east arrow 
	{0x2199,"dlarr"},    // south west arrow 
	{0x219A,"nlarr"},    // leftwards arrow with stroke 
	{0x219B,"nrarr"},    // rightwards arrow with stroke 
	{0x219D,"rarrw"},    // rightwards wave arrow 
	{0x219E,"Larr"},     // leftwards two headed arrow 
	{0x21A0,"Rarr"},     // rightwards two headed arrow 
	{0x21A2,"larrtl"},   // leftwards arrow with tail 
	{0x21A3,"rarrtl"},   // rightwards arrow with tail 
	{0x21A6,"map"},      // rightwards arrow from bar 
	{0x21A9,"larrhk"},   // leftwards arrow with hook 
	{0x21AA,"rarrhk"},   // rightwards arrow with hook 
	{0x21AB,"larrlp"},   // leftwards arrow with loop 
	{0x21AC,"rarrlp"},   // rightwards arrow with loop 
	{0x21AD,"harrw"},    // left right wave arrow 
	{0x21AE,"nharr"},    // left right arrow with stroke 
	{0x21B0,"lsh"},      // upwards arrow with tip leftwards 
	{0x21B1,"rsh"},      // upwards arrow with tip rightwards 
	{0x21B5,"crarr"},    // downwards arrow with corner leftwards 
	{0x21B6,"cularr"},   // anticlockwise top semicircle arrow 
	{0x21B7,"curarr"},   // clockwise top semicircle arrow 
	{0x21BA,"olarr"},    // anticlockwise open circle arrow 
	{0x21BB,"orarr"},    // clockwise open circle arrow 
	{0x21BC,"lharu"},    // leftwards harpoon with barb upwards 
	{0x21BD,"lhard"},    // leftwards harpoon with barb downwards 
	{0x21BE,"uharr"},    // upwards harpoon with barb rightwards 
	{0x21BF,"uharl"},    // upwards harpoon with barb leftwards 
	{0x21C0,"rharu"},    // rightwards harpoon with barb upwards 
	{0x21C1,"rhard"},    // rightwards harpoon with barb downwards 
	{0x21C2,"dharr"},    // downwards harpoon with barb rightwards 
	{0x21C3,"dharl"},    // downwards harpoon with barb leftwards 
	{0x21C4,"rlarr2"},   // rightwards arrow over leftwards arrow 
	{0x21C6,"lrarr2"},   // leftwards arrow over rightwards arrow 
	{0x21C7,"larr2"},    // leftwards paired arrows 
	{0x21C8,"uarr2"},    // upwards paired arrows 
	{0x21C9,"rarr2"},    // rightwards paired arrows 
	{0x21CA,"darr2"},    // downwards paired arrows 
	{0x21CB,"lrhar2"},   // leftwards harpoon over rightwards harpoon 
	{0x21CC,"rlhar2"},   // rightwards harpoon over leftwards harpoon 
	{0x21CD,"nlArr"},    // leftwards double arrow with stroke 
	{0x21CE,"nhArr"},    // left right double arrow with stroke 
	{0x21CF,"nrArr"},    // rightwards double arrow with stroke 
	{0x21D0,"lArr"},     // leftwards double arrow 
	{0x21D0,"xlArr"},    // leftwards double arrow 
	{0x21D1,"uArr"},     // upwards double arrow 
	{0x21D2,"rArr"},     // rightwards double arrow 
	{0x21D2,"xrArr"},    // rightwards double arrow 
	{0x21D3,"dArr"},     // downwards double arrow 
	{0x21D4,"hArr"},     // left right double arrow 
	{0x21D4,"iff"},      // left right double arrow 
	{0x21D5,"vArr"},     // up down double arrow 
	{0x21DA,"lAarr"},    // leftwards triple arrow 
	{0x21DB,"rAarr"},    // rightwards triple arrow 
	{0x2200,"forall"},   // for all 
	{0x2201,"comp"},     // complement 
	{0x2202,"part"},     // partial differential 
	{0x2203,"exist"},    // there exists 
	{0x2204,"nexist"},   // there does not exist 
	{0x2205,"empty"},    // empty set 
	{0x2207,"nabla"},    // nabla 
	{0x2208,"isin"},     // element of 
	{0x2209,"notin"},    // not an element of 
	{0x220A,"epsis"},    // small element of 
	{0x220B,"ni"},       // contains as member 
	{0x220D,"bepsi"},    // small contains as member 
	{0x220F,"prod"},     // n-ary product 
	{0x2210,"amalg"},    // n-ary coproduct 
	{0x2210,"coprod"},   // n-ary coproduct 
	{0x2210,"samalg"},   // n-ary coproduct 
	{0x2211,"sum"},      // n-ary summation 
	{0x2212,"minus"},    // minus sign 
	{0x2213,"mnplus"},   // minus-or-plus sign 
	{0x2214,"plusdo"},   // dot plus 
	{0x2216,"setmn"},    // set minus 
	{0x2216,"ssetmn"},   // set minus 
	{0x2217,"lowast"},   // asterisk operator 
	{0x2218,"compfn"},   // ring operator 
	{0x221A,"radic"},    // square root 
	{0x221D,"prop"},     // proportional to 
	{0x221D,"vprop"},    // proportional to 
	{0x221E,"infin"},    // infinity 
	{0x221F,"ang90"},    // right angle 
	{0x2220,"ang"},      // angle 
	{0x2221,"angmsd"},   // measured angle 
	{0x2222,"angsph"},   // spherical angle 
	{0x2223,"mid"},      // divides 
	{0x2224,"nmid"},     // does not divide 
	{0x2225,"par"},      // parallel to 
	{0x2225,"spar"},     // parallel to 
	{0x2226,"npar"},     // not parallel to 
	{0x2226,"nspar"},    // not parallel to 
	{0x2227,"and"},      // logical and 
	{0x2228,"or"},       // logical or 
	{0x2229,"cap"},      // intersection 
	{0x222A,"cup"},      // union 
	{0x222B,"int"},      // integral 
	{0x222E,"conint"},   // contour integral 
	{0x2234,"there4"},   // therefore 
	{0x2235,"becaus"},   // because 
	{0x223C,"sim"},      // tilde operator 
	{0x223C,"thksim"},   // tilde operator 
	{0x223D,"bsim"},     // reversed tilde 
	{0x2240,"wreath"},   // wreath product 
	{0x2241,"nsim"},     // not tilde 
	{0x2243,"sime"},     // asymptotically equal to 
	{0x2244,"nsime"},    // not asymptotically equal to 
	{0x2245,"cong"},     // approximately equal to 
	{0x2247,"ncong"},    // neither approximately nor actually equal to 
	{0x2248,"ap"},       // almost equal to 
	{0x2248,"asymp"},    // almost equal to 
	{0x2248,"thkap"},    // almost equal to 
	{0x2249,"nap"},      // not almost equal to 
	{0x224A,"ape"},      // almost equal or equal to 
	{0x224C,"bcong"},    // all equal to 
	{0x224E,"bump"},     // geometrically equivalent to 
	{0x224F,"bumpe"},    // difference between 
	{0x2250,"esdot"},    // approaches the limit 
	{0x2251,"eDot"},     // geometrically equal to 
	{0x2252,"efDot"},    // approximately equal to or the image of 
	{0x2253,"erDot"},    // image of or approximately equal to 
	{0x2254,"colone"},   // colon equals 
	{0x2255,"ecolon"},   // equals colon 
	{0x2256,"ecir"},     // ring in equal to 
	{0x2257,"cire"},     // ring equal to 
	{0x2259,"wedgeq"},   // estimates 
	{0x225C,"trie"},     // delta equal to 
	{0x2260,"ne"},       // not equal to 
	{0x2261,"equiv"},    // identical to 
	{0x2262,"nequiv"},   // not identical to 
	{0x2264,"le"},       // less-than or equal to 
	{0x2264,"les"},      // less-than or equal to 
	{0x2265,"ge"},       // greater-than or equal to 
	{0x2265,"ges"},      // greater-than or equal to 
	{0x2266,"lE"},       // less-than over equal to 
	{0x2267,"gE"},       // greater-than over equal to 
	{0x2268,"lnE"},      // less-than but not equal to 
	{0x2268,"lne"},      // less-than but not equal to 
	{0x2268,"lvnE"},     // less-than but not equal to 
	{0x2269,"gnE"},      // greater-than but not equal to 
	{0x2269,"gne"},      // greater-than but not equal to 
	{0x2269,"gvnE"},     // greater-than but not equal to 
	{0x226A,"Lt"},       // much less-than 
	{0x226B,"Gt"},       // much greater-than 
	{0x226C,"twixt"},    // between 
	{0x226E,"nlt"},      // not less-than 
	{0x226F,"ngt"},      // not greater-than 
	{0x2270,"nle"},      // neither less-than nor equal to 
	{0x2270,"nles"},     // neither less-than nor equal to 
	{0x2271,"nge"},      // neither greater-than nor equal to 
	{0x2271,"nges"},     // neither greater-than nor equal to 
	{0x2272,"lsim"},     // less-than or equivalent to 
	{0x2273,"gsim"},     // greater-than or equivalent to 
	{0x2276,"lg"},       // less-than or greater-than 
	{0x2277,"gl"},       // greater-than or less-than 
	{0x227A,"pr"},       // precedes 
	{0x227B,"sc"},       // succeeds 
	{0x227C,"cupre"},    // precedes or equal to 
	{0x227C,"pre"},      // precedes or equal to 
	{0x227D,"sccue"},    // succeeds or equal to 
	{0x227D,"sce"},      // succeeds or equal to 
	{0x227E,"prsim"},    // precedes or equivalent to 
	{0x227F,"scsim"},    // succeeds or equivalent to 
	{0x2280,"npr"},      // does not precede 
	{0x2281,"nsc"},      // does not succeed 
	{0x2282,"sub"},      // subset of 
	{0x2283,"sup"},      // superset of 
	{0x2284,"nsub"},     // not a subset of 
	{0x2285,"nsup"},     // not a superset of 
	{0x2286,"subE"},     // subset of or equal to 
	{0x2286,"sube"},     // subset of or equal to 
	{0x2287,"supE"},     // superset of or equal to 
	{0x2287,"supe"},     // superset of or equal to 
	{0x2288,"nsubE"},    // neither a subset of nor equal to 
	{0x2288,"nsube"},    // neither a subset of nor equal to 
	{0x2289,"nsupE"},    // neither a superset of nor equal to 
	{0x2289,"nsupe"},    // neither a superset of nor equal to 
	{0x228A,"subnE"},    // subset of with not equal to 
	{0x228A,"subne"},    // subset of with not equal to 
	{0x228A,"vsubnE"},   // subset of with not equal to 
	{0x228A,"vsubne"},   // subset of with not equal to 
	{0x228B,"supnE"},    // superset of with not equal to 
	{0x228B,"supne"},    // superset of with not equal to 
	{0x228B,"vsupnE"},   // superset of with not equal to 
	{0x228B,"vsupne"},   // superset of with not equal to 
	{0x228E,"uplus"},    // multiset union 
	{0x228F,"sqsub"},    // square image of 
	{0x2290,"sqsup"},    // square original of 
	{0x2291,"sqsube"},   // square image of or equal to 
	{0x2292,"sqsupe"},   // square original of or equal to 
	{0x2293,"sqcap"},    // square cap 
	{0x2294,"sqcup"},    // square cup 
	{0x2295,"oplus"},    // circled plus 
	{0x2296,"ominus"},   // circled minus 
	{0x2297,"otimes"},   // circled times 
	{0x2298,"osol"},     // circled division slash 
	{0x2299,"odot"},     // circled dot operator 
	{0x229A,"ocir"},     // circled ring operator 
	{0x229B,"oast"},     // circled asterisk operator 
	{0x229D,"odash"},    // circled dash 
	{0x229E,"plusb"},    // squared plus 
	{0x229F,"minusb"},   // squared minus 
	{0x22A0,"timesb"},   // squared times 
	{0x22A1,"sdotb"},    // squared dot operator 
	{0x22A2,"vdash"},    // right tack 
	{0x22A3,"dashv"},    // left tack 
	{0x22A4,"top"},      // down tack 
	{0x22A5,"bottom"},   // up tack 
	{0x22A5,"perp"},     // up tack 
	{0x22A7,"models"},   // models 
	{0x22A8,"vDash"},    // true 
	{0x22A9,"Vdash"},    // forces 
	{0x22AA,"Vvdash"},   // triple vertical bar right turnstile 
	{0x22AC,"nvdash"},   // does not prove 
	{0x22AD,"nvDash"},   // not true 
	{0x22AE,"nVdash"},   // does not force 
	{0x22AF,"nVDash"},   // negated double vertical bar double right turnstile 
	{0x22B2,"vltri"},    // normal subgroup of 
	{0x22B3,"vrtri"},    // contains as normal subgroup 
	{0x22B4,"ltrie"},    // normal subgroup of or equal to 
	{0x22B5,"rtrie"},    // contains as normal subgroup or equal to 
	{0x22B8,"mumap"},    // multimap 
	{0x22BA,"intcal"},   // intercalate 
	{0x22BB,"veebar"},   // xor 
	{0x22BC,"barwed"},   // nand 
	{0x22C4,"diam"},     // diamond operator 
	{0x22C5,"sdot"},     // dot operator 
	{0x22C6,"sstarf"},   // star operator 
	{0x22C7,"divonx"},   // division times 
	{0x22C8,"bowtie"},   // bowtie 
	{0x22C9,"ltimes"},   // left normal factor semidirect product 
	{0x22CA,"rtimes"},   // right normal factor semidirect product 
	{0x22CB,"lthree"},   // left semidirect product 
	{0x22CC,"rthree"},   // right semidirect product 
	{0x22CD,"bsime"},    // reversed tilde equals 
	{0x22CE,"cuvee"},    // curly logical or 
	{0x22CF,"cuwed"},    // curly logical and 
	{0x22D0,"Sub"},      // double subset 
	{0x22D1,"Sup"},      // double superset 
	{0x22D2,"Cap"},      // double intersection 
	{0x22D3,"Cup"},      // double union 
	{0x22D4,"fork"},     // pitchfork 
	{0x22D6,"ldot"},     // less-than with dot 
	{0x22D7,"gsdot"},    // greater-than with dot 
	{0x22D8,"Ll"},       // very much less-than 
	{0x22D9,"Gg"},       // very much greater-than 
	{0x22DA,"leg"},      // less-than equal to or greater-than 
	{0x22DB,"gel"},      // greater-than equal to or less-than 
	{0x22DC,"els"},      // equal to or less-than 
	{0x22DD,"egs"},      // equal to or greater-than 
	{0x22DE,"cuepr"},    // equal to or precedes 
	{0x22DF,"cuesc"},    // equal to or succeeds 
	{0x22E0,"npre"},     // does not precede or equal 
	{0x22E1,"nsce"},     // does not succeed or equal 
	{0x22E6,"lnsim"},    // less-than but not equivalent to 
	{0x22E7,"gnsim"},    // greater-than but not equivalent to 
	{0x22E8,"prnsim"},   // precedes but not equivalent to 
	{0x22E9,"scnsim"},   // succeeds but not equivalent to 
	{0x22EA,"nltri"},    // not normal subgroup of 
	{0x22EB,"nrtri"},    // does not contain as normal subgroup 
	{0x22EC,"nltrie"},   // not normal subgroup of or equal to 
	{0x22ED,"nrtrie"},   // does not contain as normal subgroup or equal 
	{0x22EE,"vellip"},   // vertical ellipsis 
	{0x2306,"Barwed"},   // perspective 
	{0x2308,"lceil"},    // left ceiling 
	{0x2309,"rceil"},    // right ceiling 
	{0x230A,"lfloor"},   // left floor 
	{0x230B,"rfloor"},   // right floor 
	{0x230C,"drcrop"},   // bottom right crop 
	{0x230D,"dlcrop"},   // bottom left crop 
	{0x230E,"urcrop"},   // top right crop 
	{0x230F,"ulcrop"},   // top left crop 
	{0x2315,"telrec"},   // telephone recorder 
	{0x2316,"target"},   // position indicator 
	{0x231C,"ulcorn"},   // top left corner 
	{0x231D,"urcorn"},   // top right corner 
	{0x231E,"dlcorn"},   // bottom left corner 
	{0x231F,"drcorn"},   // bottom right corner 
	{0x2322,"frown"},    // frown 
	{0x2322,"sfrown"},   // frown 
	{0x2323,"smile"},    // smile 
	{0x2323,"ssmile"},   // smile 
	{0x2329,"lang"},     // left-pointing angle bracket 
	{0x232A,"rang"},     // right-pointing angle bracket 
	{0x2423,"blank"},    // open box 
	{0x24C8,"oS"},       // circled latin capital letter s 
	{0x2500,"boxh"},     // box drawings light horizontal 
	{0x2502,"boxv"},     // box drawings light vertical 
	{0x250C,"boxdr"},    // box drawings light down and right 
	{0x2510,"boxdl"},    // box drawings light down and left 
	{0x2514,"boxur"},    // box drawings light up and right 
	{0x2518,"boxul"},    // box drawings light up and left 
	{0x251C,"boxvr"},    // box drawings light vertical and right 
	{0x2524,"boxvl"},    // box drawings light vertical and left 
	{0x252C,"boxhd"},    // box drawings light down and horizontal 
	{0x2534,"boxhu"},    // box drawings light up and horizontal 
	{0x253C,"boxvh"},    // box drawings light vertical and horizontal 
	{0x2550,"boxH"},     // box drawings double horizontal 
	{0x2551,"boxV"},     // box drawings double vertical 
	{0x2552,"boxdR"},    // box drawings down single and right double 
	{0x2553,"boxDr"},    // box drawings down double and right single 
	{0x2554,"boxDR"},    // box drawings double down and right 
	{0x2555,"boxdL"},    // box drawings down single and left double 
	{0x2556,"boxDl"},    // box drawings down double and left single 
	{0x2557,"boxDL"},    // box drawings double down and left 
	{0x2558,"boxuR"},    // box drawings up single and right double 
	{0x2559,"boxUr"},    // box drawings up double and right single 
	{0x255A,"boxUR"},    // box drawings double up and right 
	{0x255B,"boxuL"},    // box drawings up single and left double 
	{0x255C,"boxUl"},    // box drawings up double and left single 
	{0x255D,"boxUL"},    // box drawings double up and left 
	{0x255E,"boxvR"},    // box drawings vertical single and right double 
	{0x255F,"boxVr"},    // box drawings vertical double and right single 
	{0x2560,"boxVR"},    // box drawings double vertical and right 
	{0x2561,"boxvL"},    // box drawings vertical single and left double 
	{0x2562,"boxVl"},    // box drawings vertical double and left single 
	{0x2563,"boxVL"},    // box drawings double vertical and left 
	{0x2564,"boxHd"},    // box drawings down single and horizontal double 
	{0x2565,"boxhD"},    // box drawings down double and horizontal single 
	{0x2566,"boxHD"},    // box drawings double down and horizontal 
	{0x2567,"boxHu"},    // box drawings up single and horizontal double 
	{0x2568,"boxhU"},    // box drawings up double and horizontal single 
	{0x2569,"boxHU"},    // box drawings double up and horizontal 
	{0x256A,"boxvH"},    // box drawings vertical single and horizontal double 
	{0x256B,"boxVh"},    // box drawings vertical double and horizontal single 
	{0x256C,"boxVH"},    // box drawings double vertical and horizontal 
	{0x2580,"uhblk"},    // upper half block 
	{0x2584,"lhblk"},    // lower half block 
	{0x2588,"block"},    // full block 
	{0x2591,"blk14"},    // light shade 
	{0x2592,"blk12"},    // medium shade 
	{0x2593,"blk34"},    // dark shade 
	{0x25A1,"squ"},      // white square 
	{0x25A1,"square"},   // white square 
	{0x25AA,"squf"},     // black small square 
	{0x25AD,"rect"},     // white rectangle 
	{0x25AE,"marker"},   // black vertical rectangle 
	{0x25B3,"xutri"},    // white up-pointing triangle 
	{0x25B4,"utrif"},    // black up-pointing small triangle 
	{0x25B5,"utri"},     // white up-pointing small triangle 
	{0x25B8,"rtrif"},    // black right-pointing small triangle 
	{0x25B9,"rtri"},     // white right-pointing small triangle 
	{0x25BD,"xdtri"},    // white down-pointing triangle 
	{0x25BE,"dtrif"},    // black down-pointing small triangle 
	{0x25BF,"dtri"},     // white down-pointing small triangle 
	{0x25C2,"ltrif"},    // black left-pointing small triangle 
	{0x25C3,"ltri"},     // white left-pointing small triangle 
	{0x25CA,"loz"},      // lozenge 
	{0x25CB,"cir"},      // white circle 
	{0x25CB,"xcirc"},    // white circle 
	{0x2605,"starf"},    // black star 
	{0x2606,"star"},     // white star 
	{0x260E,"phone"},    // black telephone 
	{0x2640,"female"},   // female sign 
	{0x2642,"male"},     // male sign 
	{0x2660,"spades"},   // black spade suit 
	{0x2663,"clubs"},    // black club suit 
	{0x2665,"hearts"},   // black heart suit 
	{0x2666,"diams"},    // black diamond suit 
	{0x266A,"sung"},     // eighth note 
	{0x266D,"flat"},     // music flat sign 
	{0x266E,"natur"},    // music natural sign 
	{0x266F,"sharp"},    // music sharp sign 
	{0x2713,"check"},    // check mark 
	{0x2717,"cross"},    // ballot x 
	{0x2720,"malt"},     // maltese cross 
	{0x2726,"lozf"},     // black four pointed star 
	{0x2727,"loz"},      // white four pointed star 
	{0x2736,"sext"},     // six pointed black star 
	{0xFB00,"fflig"},    // latin small ligature ff 
	{0xFB01,"filig"},    // latin small ligature fi 
	{0xFB02,"fllig"},    // latin small ligature fl 
	{0xFB03,"ffilig"},   // latin small ligature ffi 
	{0xFB04,"ffllig"}    // latin small ligature ffl 
};


class scan_handler
{
protected:	// state
	unsigned short ent;
	static hashmap<unsigned short> entityMap;
	static bool static_init;

public:	// ctor, dtor
	scan_handler();
	virtual ~scan_handler() {};

public:	// callback methods
	// Report an attribute name, a value will not follow
	virtual void adup(const char* buf, int offset, int length);

	// Report an attribute name, a value will follow
	virtual void aname(const char* buf, int offset, int length);

	// Report an attribute value
	virtual void aval(const char* buf, int offset, int length);

	// Report an entity reference or character reference
	virtual void entity(const char* buf, int offset, int length);

	// Report EOF
	virtual void eof(const char* buf, int offset, int length);

	// Report end tag
	virtual void etag(const char* buf, int offset, int length);

	// Report general identifier (element type name) of a start tag 
	virtual void gi(const char* buf, int offset, int length);

	// Report character data
	virtual void pcdata(const char* buf, int offset, int length);

	// Report the data part of a processing instruction
	virtual void pi(const char* buf, int offset, int length);

	// Report the target part of a processing instruction
	virtual void pitarget(const char* buf, int offset, int length);

	// Report the close of a start tag
	virtual void stagc(const char* buf, int offset, int length);

	// Report a comment
	virtual void cmnt(const char* buf, int offset, int length);

	// Return the value of the last entity or character reference reported. 
	unsigned short getEntity();

};


}	/* namespace xqp */
#endif	/* XQP_SCANHANDLER_H */
