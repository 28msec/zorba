/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: character_entities.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_CHARACTER_ENTITIES_H
#define XQP_CHARACTER_ENTITIES_H

namespace xqp {

/*_______________________________________________________________________
|
|	See, for example,
|	http://www.ncbi.nlm.nih.gov/entrez/query/static/entities.html
|________________________________________________________________________*/

static struct {
  unsigned short codepoint;
  const char* name;
} const entities[] = {		//ISO Latin-1:
	{ 0x00E1, "aacute" },		// a small a, acute accent
	{ 0x00C1, "Aacute" },		// A capital A, acute accent
	{ 0x00E2, "acirc" },		// a small a, circumflex accent
	{ 0x00C2, "Acirc" },		// A capital A, circumflex accent
	{ 0x00E0, "agrave" },		// a small a, grave accent
	{ 0x00C0, "Agrave" },		// A capital A, grave accent
	{ 0x00E5, "aring" },		// a small a, ring
	{ 0x00C5, "Aring" },		// A capital A, ring
	{ 0x00E3, "atilde" },		// a small a, tilde
	{ 0x00C3, "Atilde" },		// A capital A, tilde
	{ 0x00E4, "auml" },			// a small a, dieresis or umlaut mark
	{ 0x00C4, "Auml" },			// A capital A, dieresis or umlaut mark
	{ 0x00E6, "aelig" },		// ae small ae diphthong (ligature)
	{ 0x00C6, "AElig" },		// AE capital AE diphthong (ligature)
	{ 0x00E7, "ccedil" },		// c small c, cedilla
	{ 0x00C7, "Ccedil" },		// C capital C, cedilla
	{ 0x00F0, "eth" },			// eth small eth, Icelandic
	{ 0x00D0, "ETH" },			// Eth capital Eth, Icelandic
	{ 0x00E9, "eacute" },		// e small e, acute accent
	{ 0x00C9, "Eacute" },		// E capital E, acute accent
	{ 0x00EA, "ecirc" },		// e small e, circumflex accent
	{ 0x00CA, "Ecirc" },		// E capital E, circumflex accent
	{ 0x00E8, "egrave" },		// e small e, grave accent
	{ 0x00C8, "Egrave" },		// E capital E, grave accent
	{ 0x00EB, "euml" },			// e esmall e, dieresis or umlaut mark
	{ 0x00CB, "Euml" },			// E capital E, dieresis or umlaut mark
	{ 0x00ED, "iacute" },		// i small i, acute accent
	{ 0x00CD, "Iacute" },		// I capital I, acute accent
	{ 0x00EE, "icirc" },		// i small i, circumflex accent
	{ 0x00CE, "Icirc" },		// I capital I, circumflex accent
	{ 0x00EC, "igrave" },		// i ismall i, grave accent
	{ 0x00CC, "Igrave" },		// I capital I, grave accent
	{ 0x00EF, "iuml" },			// i small i, dieresis or umlaut mark
	{ 0x00CF, "Iuml" },			// I capital I, dieresis or umlaut mark
	{ 0x00F1, "ntilde" },		// n small n, tilde
	{ 0x00D1, "Ntilde" },		// N capital N, tilde
	{ 0x00F3, "oacute" },		// o small o, acute accent
	{ 0x00D3, "Oacute" },		// O capital O, acute accent
	{ 0x00F4, "ocirc" },		// o small o, circumflex accent
	{ 0x00D4, "Ocirc" },		// O capital O, circumflex accent
	{ 0x00F2, "ograve" },		// o small o, grave accent
	{ 0x00D2, "Ograve" },		// O capital O, grave accent
	{ 0x00F8, "oslash" },		// o small o, slash
	{ 0x00D8, "Oslash" },		// O capital O, slash
	{ 0x00F5, "otilde" },		// o small o, tilde
	{ 0x00D5, "Otilde" },		// O capital O, tilde
	{ 0x00F6, "ouml" },			// o small o, dieresis or umlaut mark
	{ 0x00D6, "Ouml" },			// O capital O, dieresis or umlaut mark
	{ 0x00DF, "szlig" },		// ss small sharp s, German (sz ligature)
	{ 0x00FE, "thorn" },		// thorn small thorn, Icelandic
	{ 0x00DE, "THORN" },		// Thorn capital THORN, Icelandic
	{ 0x00FA, "uacute" },		// u small u, acute accent
	{ 0x00DA, "Uacute" },		// U capital U, acute accent
	{ 0x00FB, "ucirc" },		// u small u, circumflex accent
	{ 0x00DB, "Ucirc" },		// U capital U, circumflex accent
	{ 0x00F9, "ugrave" },		// u small u, grave accent
	{ 0x00D9, "Ugrave" },		// U capital U, grave accent
	{ 0x00FC, "uuml" },			// u small u, dieresis or umlaut mark
	{ 0x00DC, "Uuml" },			// U capital U, dieresis or umlaut mark
	{ 0x00FD, "yacute" },		// y small y, acute accent
	{ 0x00DD, "Yacute" },		// Y capital Y, acute accent
	{ 0x00FF, "yuml" },			// y small y, dieresis or umlaut mark

//ISO Latin-2
	{ 0x0103, "abreve" },		// a small a, breve
	{ 0x0102, "Abreve" },		// A capital A, breve
	{ 0x0101, "amacr" },		// a small a, macron
	{ 0x0100, "Amacr" },		// A capital A, macron
	{ 0x0105, "aogon" },		// a small a, ogonek
	{ 0x0104, "Aogon" },		// A capital A, ogonek
	{ 0x0107, "cacute" },		// c small c, acute accent
	{ 0x0106, "Cacute" },		// C capital C, acute accent
	{ 0x010D, "ccaron" },		// c small c, caron
	{ 0x010C, "Ccaron" },		// C capital C, caron
	{ 0x0109, "ccirc" },		// c small c, circumflex accent
	{ 0x0108, "Ccirc" },		// C capital C, circumflex accent
	{ 0x010B, "cdot" },			// c small c, dot above
	{ 0x010A, "Cdot" },			// C capital C, dot above
	{ 0x010F, "dcaron" },		// d small d, caron
	{ 0x010E, "Dcaron" },		// D capital D, caron
	{ 0x0111, "dstrok" },		// d small d, stroke
	{ 0x0110, "Dstrok" },		// D capital D, stroke
	{ 0x011B, "ecaron" },		// e small e, caron
	{ 0x011A, "Ecaron" },		// E capital E, caron
	{ 0x0117, "edot" },			// e small e, dot above
	{ 0x0116, "Edot" },			// E capital E, dot above
	{ 0x0113, "emacr" },		// e small e, macron
	{ 0x0112, "Emacr" },		// E capital E, macron
	{ 0x0119, "eogon" },		// e small e, ogonek
	{ 0x0118, "Eogon" },		// E capital E, ogonek
	{ 0x01F5, "gacute" },		// g small g, acute accent
	{ 0x011F, "gbreve" },		// g small g, breve
	{ 0x011E, "Gbreve" },		// G capital G, breve
	{ 0x0122, "Gcedil" },		// G capital G, cedilla
	{ 0x011D, "gcirc" },		// g small g, circumflex accent
	{ 0x011C, "Gcirc" },		// G capital G, circumflex accent
	{ 0x0121, "gdot" },			// g small g, dot above
	{ 0x0120, "Gdot" },			// G capital G, dot above
	{ 0x0125, "hcirc" },		// h small h, circumflex accent
	{ 0x0124, "Hcirc" },		// H capital H, circumflex accent
	{ 0x0127, "hstrok" },		// h small h, stroke
	{ 0x0126, "Hstrok" },		// H capital H, stroke
	{ 0x0130, "Idot" },			// I capital I, dot above
	{ 0x012A, "Imacr" },		// I capital I, macron
	{ 0x012B, "imacr" },		// ij small i, macron
	{ 0x0133, "ijlig" },		// ij small ij ligature
	{ 0x0132, "IJlig" },		// IJ capital IJ ligature
	{ 0x0131, "inodot" },		// i small i, no dot
	{ 0x012F, "iogon" },		// i small i, ogonek
	{ 0x012E, "Iogon" },		// I capital I, ogonek
	{ 0x0129, "itilde" },		// ij small i, tilde
	{ 0x0128, "Itilde" },		// I capital I, tilde
	{ 0x0135, "jcirc" },		// j small j, circumflex accent
	{ 0x0134, "Jcirc" },		// J capital J, circumflex accent
	{ 0x0137, "kcedil" },		// k small k, cedilla
	{ 0x0136, "Kcedil" },		// K capital K, cedilla
	{ 0x0138, "kgreen" },		// k small k, Greenlandic
	{ 0x013A, "lacute" },		// l small l, acute accent
	{ 0x0139, "Lacute" },		// L capital L, acute accent
	{ 0x013E, "lcaron" },		// l small l, caron
	{ 0x013D, "Lcaron" },		// L capital L, caron
	{ 0x013C, "lcedil" },		// l small l, cedilla
	{ 0x013B, "Lcedil" },		// L capital L, cedilla
	{ 0x0140, "lmidot" },		// l small l, middle dot
	{ 0x013F, "Lmidot" },		// L capital L, middle dot
	{ 0x0142, "lstrok" },		// l small l, stroke
	{ 0x0141, "Lstrok" },		// L capital L, stroke
	{ 0x0144, "nacute" },		// n small n, acute accent
	{ 0x0143, "Nacute" },		// N capital N, acute accent
	{ 0x014B, "eng" },			// eng small eng, Lapp
	{ 0x014A, "ENG" },			// ENG capital ENG, Lapp
	{ 0x0149, "napos" },		// n small n, apostrophe
	{ 0x0148, "ncaron" },		// n small n, caron
	{ 0x0147, "Ncaron" },		// N capital N, caron
	{ 0x0146, "ncedil" },		// n small n, cedilla
	{ 0x0145, "Ncedil" },		// N capital N, cedilla
	{ 0x0151, "odblac" },		// o small o, double acute accent
	{ 0x0150, "Odblac" },		// O capital O, double acute accent
	{ 0x014C, "Omacr" },		// O capital O, macron
	{ 0x014D, "omacr" },		// o small o, macron
	{ 0x0153, "oelig" },		// oe small oe ligature
	{ 0x0152, "OElig" },		// OE capital OE ligature
	{ 0x0155, "racute" },		// r small r, acute accent
	{ 0x0154, "Racute" },		// R capital R, acute accent
	{ 0x0159, "rcaron" },		// r small r, caron
	{ 0x0158, "Rcaron" },		// R capital R, caron
	{ 0x0157, "rcedil" },		// r small r, cedilla
	{ 0x0156, "Rcedil" },		// R capital R, cedilla
	{ 0x015B, "sacute" },		// s small s, acute accent
	{ 0x015A, "Sacute" },		// S capital S, acute accent
	{ 0x0161, "scaron" },		// s small s, caron
	{ 0x0160, "Scaron" },		// S capital S, caron
	{ 0x015F, "scedil" },		// s small s, cedilla
	{ 0x015E, "Scedil" },		// S capital S, cedilla
	{ 0x015D, "scirc" },		// s small s, circumflex accent
	{ 0x015C, "Scirc" },		// S capital S, circumflex accent
	{ 0x0165, "tcaron" },		// t small t, caron
	{ 0x0164, "Tcaron" },		// T capital T, caron
	{ 0x0163, "tcedil" },		// t small t, cedilla
	{ 0x0162, "Tcedil" },		// T capital T, cedilla
	{ 0x0167, "tstrok" },		// t small t, stroke
	{ 0x0166, "Tstrok" },		// T capital T, stroke
	{ 0x016D, "ubreve" },		// u small u, breve
	{ 0x016C, "Ubreve" },		// U capital U, breve
	{ 0x0171, "udblac" },		// u small u, double acute accent
	{ 0x0170, "Udblac" },		// U capital U, double acute accent
	{ 0x016B, "umacr" },		// u small u, macron
	{ 0x016A, "Umacr" },		// U capital U, macron
	{ 0x0173, "uogon" },		// u small u, ogonek
	{ 0x0172, "Uogon" },		// U capital U, ogonek
	{ 0x016F, "uring" },		// u small u, ring
	{ 0x016E, "Uring" },		// U capital U, ring
	{ 0x0169, "utilde" },		// u small u, tilde
	{ 0x0168, "Utilde" },		// U capital U, tilde
	{ 0x0175, "wcirc" },		// w small w, circumflex accent
	{ 0x0174, "Wcirc" },		// W capital W, circumflex accent
	{ 0x0177, "ycirc" },		// y small y, circumflex accent
	{ 0x0176, "Ycirc" },		// Y capital Y, circumflex accent
	{ 0x0178, "Yuml" },			// Y capital Y, dieresis or umlaut mark
	{ 0x017A, "zacute" },		// z small z, acute accent
	{ 0x0179, "Zacute" },		// Z capital Z, acute accent
	{ 0x017E, "zcaron" },		// z small z, caron
	{ 0x017D, "Zcaron" },		// Z capital Z, caron
	{ 0x017C, "zdot" },			// z small z, dot above
	{ 0x017B, "Zdot" },			// Z capital Z, dot above

//Publishing
	{ 0x2003, "emsp" },			// em space
	{ 0x2002, "ensp" },			// en space (1/2-em)
	{ 0x2004, "emsp13" },		// 1/3-em space
	{ 0x2005, "emsp14" },		// 1/4-em space
	{ 0x2007, "numsp" },		// digit space (width of a number)
	{ 0x2008, "puncsp" },		// punctuation space (width of comma)
	{ 0x2009, "thinsp" },		// thin space (1/6-em)
	{ 0x200A, "hairsp" },		// hair space
	{ 0x2014, "mdash" },		// - em dash
	{ 0x2013, "ndash" },		// - en dash
	{ 0x2010, "dash" },			// - hyphen (true graphic)
	{ 0x2423, "blank" },		// significant blank symbol
	{ 0x2026, "hellip" },		// em leader ellipsis (horizontal)
	{ 0x2025, "nldr" },			// ..  double baseline dot (en leader)
	{ 0x2153, "frac13" },		// (1/3) fraction one-third
	{ 0x2154, "frac23" },		// (2/3) fraction two-thirds
	{ 0x2155, "frac15" },		// (1/5) fraction one-fifth
	{ 0x2156, "frac25" },		// (2/5) fraction two-fifths
	{ 0x2157, "frac35" },		// (3/5) fraction three-fifths
	{ 0x2158, "frac45" },		// (4/5) fraction four-fifths
	{ 0x2159, "frac16" },		// (1/6) fraction one-sixth
	{ 0x215A, "frac56" },		// (5/6) fraction five-sixths
	{ 0x2105, "incare" },		// in-care-of in-care-of symbol
	{ 0x2588, "block" },		// full block full block
	{ 0x2580, "uhblk" },		// upper half block upper half block
	{ 0x2584, "lhblk" },		// lower half block lower half block
	{ 0x2591, "blk14" },		// 25% shaded block 25% shaded block
	{ 0x2592, "blk12" },		// 50% shaded block 50% shaded block
	{ 0x2593, "blk34" },		// 75% shaded block 75% shaded block
	{ 0x25AE, "marker" },		// histogram marker histogram marker
	{ 0x25CB, "cir" },			// o circle, open
	{ 0x25A1, "squ" },			// square square, open
	{ 0x25AD, "rect" },			// rectangle rectangle, open
	{ 0x25B5, "utri" },			// triangle up up triangle, open
	{ 0x25BF, "dtri" },			// triangle down down triangle, open
	{ 0x22C6, "star" },			// small star, filled star, open
	{ 0x2022, "bull" },			// * round bullet, filled
	{ 0x25AA, "squf" },			// blacksquare, square, filled sq bullet, filled
	{ 0x25B4, "utrif" },		// black triangle up triangle , filled
	{ 0x25BE, "dtrif" },		// black triangle down down triangle , filled
	{ 0x25C2, "ltrif" },		// black triangle left left triangle , filled
	{ 0x25B8, "rtrif" },		// black triangle right right triangle , filled
	{ 0x2663, "clubs" },		// club suit symbol club suit symbol
	{ 0x2666, "diams" },		// diamond diamond suit symbol
	{ 0x2661, "hearts" },		// heart heart suit symbol
	{ 0x2660, "spades" },		// spades spades suit symbol
	{ 0x2720, "malt" },			// maltese cross maltese cross
	{ 0x2020, "dagger" },		// dagger dagger
	{ 0x2021, "Dagger" },		// double dagger double dagger
	{ 0x2713, "check" },		// check mark tick, check mark
	{ 0x2717, "cross" },		// ballot cross ballot cross
	{ 0x266F, "sharp" },		// musical sharp musical sharp
	{ 0x266D, "flat" },			// musical flat musical flat
	{ 0x2642, "male" },			// male symbol male symbol
	{ 0x2640, "female" },		// female symbol female symbol
	{ 0x260E, "phone" },		// telephone symbol telephone symbol
	{ 0x2315, "telrec" },		// telephone recorder symbol telephone recorder symbol
	{ 0x2117, "copysr" },		// sound recording copyright sign sound recording copyright sign
	{ 0x2041, "caret" },		// insertion mark caret (insertion mark)
	{ 0x201A, "lsquor" },		// ' rising single quote, left (low)
	{ 0x201E, "ldquor" },		// " rising double quote, left (low)
	{ 0x2026, "mldr" },			// em leader em leader
	{ 0x201D, "rdquor" },		// " double quote, right (high)
	{ 0x2019, "rsquor" },		// ' single quote, right (high)
	{ 0x22EE, "vellip" },		// vertical ellipsis vellipvertical ellipsis
	{ 0x2043, "hybull" },		// rectangle filled hyphen bullet rectangle
	{ 0x25CA, "loz" },			// lozenge lozenge or total mark
	{ 0x25C3, "ltri" },			// triangle left left triangle, open
	{ 0x25B9, "rtri" },			// triangle right right triangle, open
	{ 0x2605, "starf" },		// bigstar star, filled
	{ 0x266E, "natur" },		// music natural music natural
	{ 0x211E, "rx" },				// Rx pharmaceutical prescription (Rx)
	{ 0x2736, "sext" },			// sextile sextile (6-pointed star)
	{ 0x2316, "target" },		// register mark or target mark or target
	{ 0x230D, "dlcrop" },		// downward left crop mark left crop mark
	{ 0x230C, "drcrop" },		// downward right crop mark right crop mark
	{ 0x230F, "ulcrop" },		// upward left crop mark left crop mark
	{ 0x230E, "urcrop" },		// upward right crop mark right crop mark

//General Technical
	{ 0x2135, "aleph" },		// aleph aleph, Hebrew
	{ 0x2227, "and" },			// wedge logical and
	{ 0x221F, "ang90" },		// 90 degree angle right (90 degree) angle
	{ 0x2222, "angsph" },		// angle-spherical angle-spherical
	{ 0x2248, "ap" },				// approximately approximate
	{ 0x2235, "becaus" },		// because because
	{ 0x22A5, "bottom" },		// perpendicular perpendicular
	{ 0x2229, "cap" },			// intersection intersection
	{ 0x2245, "cong" },			// congruent with congruent with
	{ 0x222E, "conint" },		// contour integral operator contour integral operator
	{ 0x222A, "cup" },			// union or logical sum union or logical sum
	{ 0x2261, "equiv" },		// identical with identical with
	{ 0x2203, "exist" },		// exists at least one exists
	{ 0x2200, "forall" },		// for all for all
	{ 0x0192, "fnof" },			// f function of (italic small f)
	{ 0x2265, "ge" },				// >/= greater-than-or-equal
	{ 0x221E, "infin" },		// infinity infinity
	{ 0x222B, "int" },			// integral integral operator
	{ 0x2208, "isin" },			// in set membership
	{ 0x3008, "lang" },			// < left angle bracket
	{ 0x21D0, "lArr" },			// <-- is implied by
	{ 0x2264, "le" },				// </= less-than-or-equal
	{ 0x2212, "minus" },		// - minus sign
	{ 0x2213, "mnplus" },		// -/+ minus-or-plus sign
	{ 0x2207, "nabla" },		// nabla del, Hamilton operator
	{ 0x2260, "ne" },				// not equal not equal
	{ 0x220B, "ni" },				// contains contains
	{ 0x2228, "or" },				// logical or logical or
	{ 0x2225, "par" },			// parallel parallel
	{ 0x2202, "part" },			// partial differential partial differential
	{ 0x2030, "permil" },		// per thousand per thousand
	{ 0x22A5, "perp" },			// perpendicular perpendicular
	{ 0x2032, "prime" },		// ' prime or minute
	{ 0x2033, "Prime" },		// '' double prime or second
	{ 0x221D, "prop" },			// proportional, variant is proportional to
	{ 0x221A, "radic" },		// radical radical
	{ 0x3009, "rang" },			// > right angle bracket
	{ 0x21D2, "rArr" },			// --> implies
	{ 0x223C, "sim" },			// approximately similar
	{ 0x2243, "sime" },			// approximately similar, equals
	{ 0x25A1, "square" },		// square square
	{ 0x2282, "sub" },			// subset subset or is implied by
	{ 0x2286, "sube" },			// subset, dbl equals subset, equals
	{ 0x2283, "sup" },			// superset superset or implies
	{ 0x2287, "supe" },			// superset, dbl equals superset, equals
	{ 0x2234, "there4" },		// therefore therefore
	{ 0x2016, "Verbar" },		// || double vertical bar
	{ 0x212B, "angst" },		// A Angstrom (capital A, ring)
	{ 0x212C, "bernou" },		// Bernoulli function Bernoulli function (script capital B)
	{ 0x2218, "compfn" },		// composite function composite function (small circle)
	{ 0x00A8, "Dot" },			// dieresis or umlaut mark
	{ 0x20DC, "DotDot" },		// ....  four dots above
	{ 0x210B, "hamilt" },		// H Hamiltonian (script capital H)
	{ 0x2112, "lagran" },		// Lgrangian Lagrangian (script capital L)
	{ 0x2217, "lowast" },		// * low asterisk
	{ 0x2209, "notin" },		// negated set membership negated set membership
	{ 0x2134, "order" },		// o order of (script small o)
	{ 0x2133, "phmmat" },		// M physics M-matrix (script capital M)
	{ 0x20DB, "tdot" },			// ...  three dots above
	{ 0x2034, "tprime" },		// ''' triple prime
	{ 0x2259, "wedgeq" },		// wedge corresponds to (wedge, equals)

//Accented Characters
	{ 0x00B4, "acute" },		// acute accent
	{ 0x02D8, "breve" },		// breve
	{ 0x02C7, "caron" },		// caron
	{ 0x00B8, "cedil" },		// cedilla
	{ 0x005E, "circ" },			// circumflex accent
	{ 0x02DD, "dblac" },		// double acute accent
	{ 0x00A8, "die" },			// dieresis
	{ 0x02D9, "dot" },			// dot above
	{ 0x0060, "grave" },		// grave accent
	{ 0x00AF, "macr" },			// macron
	{ 0x02DB, "ogon" },			// ogonek
	{ 0x02DA, "ring" },			// ring
	{ 0x02DC, "tilde" },		// tilde
	{ 0x00A8, "uml" },			// umlaut mark

//Fractions, Super/Subscripts, Punctuation
	{ 0x00BD, "half" },			// (1/2) fraction one-half
	{ 0x00BD, "frac12" },		// (1/2) fraction one-half
	{ 0x00BC, "frac14" },		// (1/4) fraction one-quarter
	{ 0x00BE, "frac34" },		// (3/4) fraction three-quarters
	{ 0x215B, "frac18" },		// (1/8) fraction one-eighth
	{ 0x215C, "frac38" },		// (3/8) fraction three-eighths
	{ 0x215D, "frac58" },		// (5/8) fraction five-eighths
	{ 0x215E, "frac78" },		// (7/8) fraction seven-eighths
	{ 0x00B9, "sup1" },			// (1) superscript one
	{ 0x00B2, "sup2" },			// (2) superscript two
	{ 0x00B3, "sup3" },			// (3) superscript three
	{ 0x002B, "plus" },			// + plus sign
	{ 0x00B1, "plusmn" },		// +/- plus-or-minus sign
	{ 0x003C, "lt" },				// < less-than sign
	{ 0x003D, "equals" },		// = equals sign
	{ 0x003E, "gt" },				// > greater-than sign
	{ 0x00F7, "divide" },		// / divide sign
	{ 0x00D7, "times" },		// x multiply sign
	{ 0x00A4, "curren" },		// currency general currency sign
	{ 0x00A3, "pound" },		// pound pound sign
	{ 0x0024, "dollar" },		// $ dollar sign
	{ 0x00A2, "cent" },			// cent cent sign
	{ 0x00A5, "yen" },			// yen yen sign
	{ 0x0023, "num" },			// # number sign
	{ 0x20AC, "euro"},			// euro sign
	{ 0x0025, "percnt" },		// % percent sign
	{ 0x0026, "amp" },			// & ampersand
	{ 0x002A, "ast" },			// * asterisk
	{ 0x0040, "commat" },		// @ commercial at
	{ 0x005B, "lsqb" },			// [ left square bracket
	{ 0x005C, "bsol" },			// \\ reverse solidus
	{ 0x005D, "rsqb" },			// ] right square bracket
	{ 0x007B, "lcub" },			// { left curly bracket
	{ 0x2015, "horbar" },		// - horizontal bar
	{ 0x007C, "verbar" },		// | vertical bar
	{ 0x007D, "rcub" },			// } right curly bracket
	{ 0x00B5, "micro" },		// micro micro sign
	{ 0x2126, "ohm" },			// ohm ohm sign
	{ 0x00B0, "deg" },			// degrees degree sign
	{ 0x00BA, "ordm" },			// masculine ordinal indicator, masculine
	{ 0x00AA, "ordf" },			// feminine ordinal indicator, feminine
	{ 0x00A7, "sect" },			// section sign section sign
	{ 0x00B6, "para" },			// paragraph sign paragraph sign
	{ 0x00B7, "middot" },		// .  middle dot
	{ 0x2190, "larr" },			// <-- leftward arrow
	{ 0x2192, "rarr" },			// --> rightward arrow
	{ 0x2191, "uarr" },			// upward arrow upward arrow
	{ 0x2193, "darr" },			// downward arrow downward arrow
	{ 0x00A9, "copy" },			// (c) copyright sign
	{ 0x00AE, "reg" },			// (R) registered sign
	{ 0x2122, "trade" },		// trade mark trade mark sign
	{ 0x00A6, "brvbar" },		// | broken (vertical) bar
	{ 0x00AC, "not" },			// not not sign
	{ 0x266A, "sung" },			// music note music note (sung text sign)
	{ 0x0021, "excl" },			// !  exclamation mark
	{ 0x00A1, "iexcl" },		// inverted exclamation mark inverted exclamation mark
	{ 0x0022, "quot" },			// " quotation mark
	{ 0x0027, "apos" },			// ' apostrophe
	{ 0x0028, "lpar" },			// ( left parenthesis
	{ 0x0029, "rpar" },			// right parenthesis
	{ 0x002C, "comma" },		// , comma
	{ 0x005F, "lowbar" },		// _ low line
	{ 0x2010, "hyphen" },		// - hyphen
	{ 0x002E, "period" },		// .  full stop, period
	{ 0x002F, "sol" },			// / solidus
	{ 0x003A, "colon" },		// : colon
	{ 0x003B, "semi" },			// semicolon
	{ 0x003F, "quest" },		// ?  question mark
	{ 0x00BF, "iquest" },		// inverted question mark inverted question mark
	{ 0x00AB, "laquo" },		// << angle quotation mark, left
	{ 0x00BB, "raquo" },		// >> angle quotation mark, right
	{ 0x2018, "lsquo" },		// ' single quotation mark, left
	{ 0x2019, "rsquo" },		// ' single quotation mark, right
	{ 0x201C, "ldquo" },		// " double quotation mark, left
	{ 0x201D, "rdquo" },		// " double quotation mark, right
	{ 0x00A0, "nbsp" },			// no break (required) space
	{ 0x00AD, "shy" },			// - soft hyphen

//Greek Letters
	{ 0x03B1, "agr" },			// alpha small alpha, Greek
	{ 0x0391, "Agr" },			// Alpha capital Alpha, Greek
	{ 0x03B2, "bgr" },			// beta small beta, Greek
	{ 0x0392, "Bgr" },			// Beta capital Beta, Greek
	{ 0x03B3, "ggr" },			// gamma small gamma, Greek
	{ 0x0393, "Ggr" },			// Gamma capital Gamma, Greek
	{ 0x03B4, "dgr" },			// delta small delta, Greek
	{ 0x0394, "Dgr" },			// Delta capital Delta, Greek
	{ 0x03B5, "egr" },			// epsilon small epsilon, Greek
	{ 0x0395, "Egr" },			// Epsilon capital Epsilon, Greek
	{ 0x03B6, "zgr" },			// zeta small zeta, Greek
	{ 0x0396, "Zgr" },			// Zeta capital Zeta, Greek
	{ 0x03B7, "eegr" },			// eta small eta, Greek
	{ 0x0397, "EEgr" },			// Eta capital Eta, Greek
	{ 0x03B8, "thgr" },			// theta small theta, Greek
	{ 0x0398, "THgr" },			// Theta capital Theta, Greek
	{ 0x03B9, "igr" },			// iota small iota, Greek
	{ 0x0399, "Igr" },			// Iota capital Iota, Greek
	{ 0x03BA, "kgr" },			// kappa small kappa, Greek
	{ 0x039A, "Kgr" },			// Kappa capital Kappa, Greek
	{ 0x03BB, "lgr" },			// lambda small lambda, Greek
	{ 0x039B, "Lgr" },			// Lambda capital Lambda, Greek
	{ 0x03BC, "mgr" },			// mu small mu, Greek
	{ 0x039C, "Mgr" },			// mu capital Mu, Greek
	{ 0x03BD, "ngr" },			// nu small nu, Greek
	{ 0x039D, "Ngr" },			// Nu capital Nu, Greek
	{ 0x03BE, "xgr" },			// xi small xi, Greek
	{ 0x039E, "Xgr" },			// Xi capital Xi, Greek
	{ 0x03BF, "ogr" },			// omicron small omicron, Greek
	{ 0x039F, "Ogr" },			// Omicron capital Omicron, Greek
	{ 0x03C0, "pgr" },			// pi small pi, Greek
	{ 0x03A0, "Pgr" },			// Pi capital Pi, Greek
	{ 0x03C1, "rgr" },			// rho small rho, Greek
	{ 0x03A1, "Rgr" },			// Rho capital Rho, Greek
	{ 0x03C3, "sgr" },			// sigma small sigma, Greek
	{ 0x03A3, "Sgr" },			// Sigma capital Sigma, Greek
	{ 0x03C2, "sfgr" },			// sigma final small sigma, Greek
	{ 0x03C4, "tgr" },			// tau small tau, Greek
	{ 0x03A4, "Tgr" },			// Tau capital Tau, Greek
	{ 0x03C5, "ugr" },			// upsilon small upsilon, Greek
	{ 0x03A5, "Ugr" },			// Upsilon capital Upsilon, Greek
	{ 0x03C6, "phgr" },			// phi small phi, Greek
	{ 0x03A6, "PHgr" },			// Phi capital Phi, Greek
	{ 0x03C7, "khgr" },			// chi small chi, Greek
	{ 0x03A7, "KHgr" },			// Chi capital Chi, Greek
	{ 0x03C8, "psgr" },			// psi small psi, Greek
	{ 0x03A8, "PSgr" },			// Psi capital Psi, Greek
	{ 0x03C9, "ohgr" },			// omega small omega, Greek
	{ 0x03A9, "OHgr" },			// Omega capital Omega, Greek

//Monotoniko Greek
	{ 0x03AC, "aacgr" },		// alpha small alpha, accent, Greek
	{ 0x0386, "Aacgr" },		// Alpha capital Alpha, accent, Greek
	{ 0x03AD, "eacgr" },		// epsilon small epsilon, accent, Greek
	{ 0x0388, "Eacgr" },		// Epsilon capital Epsilon, accent, Greek
	{ 0x03AE, "eeacgr" },		// eta small eta, accent, Greek
	{ 0x0389, "EEacgr" },		// Eta capital Eta, accent, Greek
	{ 0x03CA, "idigr" },		// iota small iota, dieresis, Greek
	{ 0x03AA, "Idigr" },		// Iota capital Iota, dieresis, Greek
	{ 0x03AF, "iacgr" },		// iota small iota, accent, Greek
	{ 0x038A, "Iacgr" },		// Iota capital Iota, accent, Greek
	{ 0x0390, "idiagr" },		// iota small iota, dieresis, accent, Greek
	{ 0x03CC, "oacgr" },		// omicron small omicron, accent, Greek
	{ 0x038C, "Oacgr" },		// Omicron capital Omicron, accent, Greek
	{ 0x03CB, "udigr" },		// upsilon small upsilon, dieresis, Greek
	{ 0x03AB, "Udigr" },		// Upsilon capital Upsilon, dieresis, Greek
	{ 0x03CD, "uacgr" },		// upsilon small upsilon, accent, Greek
	{ 0x038E, "Uacgr" },		// Upsilon capital Upsilon, accent, Greek
	{ 0x03B0, "udiagr" },		// upsilon small upsilon, dieresis, accent, Greek
	{ 0x03CE, "ohacgr" },		// omega small omega, accent, Greek
	{ 0x038F, "OHacgr" },		// Omega capital Omega, accent, Greek

//Greek Symbols
	{ 0x03B1, "alpha" },		// alpha small alpha, Greek
	{ 0x03B2, "beta" },			// beta small beta, Greek
	{ 0x03B3, "gamma" },		// gamma small gamma, Greek
	{ 0x0393, "Gamma" },		// Gamma capital Gamma, Greek
	{ 0x03DC, "gammad" },		// digamma digamma
	{ 0x03B4, "delta" },		// delta small delta, Greek
	{ 0x0394, "Delta" },		// Delta capital Delta, Greek
	{ 0x03B5, "epsi" },			// epsilon small epsilon, Greek
	{ 0x025B, "epsiv" },		// epsilon var epsilon
	{ 0x03B5, "epsis" },		// epsilon straight epsilon
	{ 0x03B6, "zeta" },			// zeta small zeta, Greek
	{ 0x03B7, "eta" },			// eta small eta, Greek
	{ 0x03B8, "thetas" },		// theta straight theta
	{ 0x0398, "Theta" },		// Theta capital Theta, Greek
	{ 0x03D1, "thetav" },		// theta var theta - curly or open theta
	{ 0x03B9, "iota" },			// iota small iota, Greek
	{ 0x03BA, "kappa" },		// kappa small kappa, Greek
	{ 0x03F0, "kappav" },		// kappa var kappa
	{ 0x03BB, "lambda" },		// lambda small lambda, Greek
	{ 0x039B, "Lambda" },		// Lambda capital Lambda, Greek
	{ 0x03BC, "mu" },				// mu small mu, Greek
	{ 0x03BD, "nu" },				// nu small nu, Greek
	{ 0x03BE, "xi" },				// xi small xi, Greek
	{ 0x039E, "Xi" },				// Xi capital Xi, Greek
	{ 0x03C0, "pi" },				// pi small pi, Greek
	{ 0x03D6, "piv" },			// pi varpi
	{ 0x03A0, "Pi" },				// Pi capital Pi, Greek
	{ 0x03C1, "rho" },			// rho small rho, Greek
	{ 0x03F1, "rhov" },			// rho var rho
	{ 0x03C3, "sigma" },		// sigma small sigma, Greek
	{ 0x03A3, "Sigma" },		// Sigma capital Sigma, Greek
	{ 0x03C2, "sigmav" },		// sigma var sigma
	{ 0x03C4, "tau" },			// tau small tau, Greek
	{ 0x03C5, "upsi" },			// upsilon small upsilon, Greek
	{ 0x03D2, "Upsi" },			// Upsilon capital Upsilon, Greek
	{ 0x03C6, "phis" },			// phi straight phi
	{ 0x03A6, "Phi" },			// Phi capital Phi, Greek
	{ 0x03D5, "phiv" },			// phi var phi - curly or open phi
	{ 0x03C7, "chi" },			// chi small chi, Greek
	{ 0x03C8, "psi" },			// psi small psi, Greek
	{ 0x03A8, "Psi" },			// Psi capital Psi, Greek
	{ 0x03C9, "omega" },		// omega small omega, Greek
	{ 0x03A9, "Omega" },		// Omega capital Omega, Greek

//Alternative Greek Symbols
	{ 0x03B1, "b.alpha" },	// alpha small alpha, Greek
	{ 0x03B2, "b.beta" },		// beta small beta, Greek
	{ 0x03B3, "b.gamma" },	// gamma small gamma, Greek
	{ 0x0393, "b.Gamma" },	// Gamma capital Gamma, Greek
	{ 0x03DD, "b.gammad" },	// digamma digamma
	{ 0x03B4, "b.delta" },	// delta small delta, Greek
	{ 0x0394, "b.Delta" },	// Delta capital Delta, Greek
	{ 0x03B5, "b.epsi" },		// epsilon small epsilon, Greek
	{ 0x025B, "b.epsiv" },	// epsilon var epsilon
	{ 0x03B5, "b.epsis" },	// epsilon straight epsilon
	{ 0x03B6, "b.zeta" },		// zeta small zeta, Greek
	{ 0x03B7, "b.eta" },		// eta small eta, Greek
	{ 0x03B8, "b.thetas" },	// theta straight theta
	{ 0x0398, "b.Theta" },	// Theta capital Theta, Greek
	{ 0x03D1, "b.thetav" },	// theta var theta - curly or open theta
	{ 0x03B9, "b.iota" },		// iota small iota, Greek
	{ 0x03BA, "b.kappa" },	// kappa small kappa, Greek
	{ 0x03F0, "b.kappav" },	// kappa var kappa
	{ 0x03BB, "b.lambda" },	// lambda small lambda, Greek
	{ 0x039B, "b.Lambda" },	// Lambda capital Lambda, Greek
	{ 0x03BC, "b.mu" },			// mu small mu, Greek
	{ 0x03BD, "b.nu" },			// nu small nu, Greek
	{ 0x03BE, "b.xi" },			// xi small xi, Greek
	{ 0x039E, "b.Xi" },			// Xi capital Xi, Greek
	{ 0x03C0, "b.pi" },			// pi small pi, Greek
	{ 0x03A0, "b.Pi" },			// Pi capital Pi, Greek
	{ 0x03D6, "b.piv" },		// pi var pi
	{ 0x03C1, "b.rho" },		// rho small rho, Greek
	{ 0x03F1, "b.rhov" },		// rho var rho
	{ 0x03C3, "b.sigma" },	// sigma small sigma, Greek
	{ 0x03A3, "b.Sigma" },	// Sigma capital Sigma, Greek
	{ 0x03C2, "b.sigmav" },	// sigma var sigma
	{ 0x03C4, "b.tau" },		// tau small tau, Greek
	{ 0x03C5, "b.upsi" },		// upsilon small upsilon, Greek
	{ 0x03D2, "b.Upsi" },		// Upsilon capital Upsilon, Greek
	{ 0x03C6, "b.phis" },		// phi straight phi
	{ 0x03A6, "b.Phi" },		// Phi capital Phi, Greek
	{ 0x03D5, "b.phiv" },		// phi var phi - curly or open phi
	{ 0x03C7, "b.chi" },		// chi small chi, Greek
	{ 0x03C8, "b.psi" },		// psi small psi, Greek
	{ 0x03A8, "b.Psi" },		// Psi capital Psi, Greek
	{ 0x03C9, "b.omega" },	// omega small omega, Greek
	{ 0x03A9, "b.Omega" },	// Omega capital Omega, Greek

//Relations
	{ 0x2309, "rceil" },		// right ceiling right ceiling
	{ 0x230B, "rfloor" },		// right floor right floor
	{ 0x2994, "rpargt" },		// right paren, gt right paren, gt
	{ 0x231D, "urcorn" },		// upper right corner upper right corner
	{ 0x231F, "drcorn" },		// downward right corner downward right corner
	{ 0x2308, "lceil" },		// left ceiling left ceiling
	{ 0x230A, "lfloor" },		// left floor left floor
	{ 0x231C, "ulcorn" },		// upper left corner upper left corner
	{ 0x231E, "dlcorn" },		// downward left corner downward left corner

//Negated Relations
	{ 0x2269, "gne" },			// greater, not dbl equals greater, not equals
	{ 0x2269, "gnE" },			// greater, not dbl equals greater, not double equals
	{ 0x22E7, "gnsim" },		// greater, not similar greater, not similar
	{ 0x2A89, "lnap" },			// less, not approximate less, not approximate
	{ 0x2268, "lnE" },			// less, not double equals less, not double equals
	{ 0x2268, "lne" },			// less, not double equals less, not equals
	{ 0x22E6, "lnsim" },		// less, not similar less, not similar
	{ 0x2249, "nap" },			// not approximate not approximate
	{ 0x2247, "ncong" },		// not congruent with not congruent with
	{ 0x2262, "nequiv" },		// not identical with not identical with
	{ 0x2271, "ngE" },			// not greater, double equals not greater, double equals
	{ 0x2271, "nge" },			// not greater-than-or-equal not greater-than-or-equal
	{ 0x2271, "nges" },			// not greater, double equals not gt-or-eq, slanted
	{ 0x226F, "ngt" },			// not greater-than not greater-than
	{ 0x2270, "nle" },			// not less-than-or-equal not less-than-or-equal
	{ 0x2270, "nlE" },			// not less, double equals not less, double equals
	{ 0x2270, "nles" },			// not less, double equals not less-or-eq, slant
	{ 0x226E, "nlt" },			// not less-than not less-than
	{ 0x22EA, "nltri" },		// not left triangle not left triangle
	{ 0x22EC, "nltrie" },		// not l tri, eq not left tri, equals
	{ 0x2224, "nmid" },			// nmid nmid
	{ 0x2226, "npar" },			// not parallel not parallel
	{ 0x2280, "npr" },			// not precedes not precedes
	{ 0x22EB, "nrtri" },		// not rt triangle not right triangle
	{ 0x22ED, "nrtrie" },		// not r tri, eq not right tri, equals
	{ 0x2281, "nsc" },			// not succeeds not succeeds
	{ 0x2241, "nsim" },			// not similar not similar
	{ 0x2244, "nsime" },		// not similar, equals not similar, equals
	{ 0x2224, "nsmid" },		// nshortmid not short mid
	{ 0x2284, "nsub" },			// not subset not subset
	{ 0x2288, "nsube" },		// not subset, dbl eq not subset, equals
	{ 0x2288, "nsubE" },		// not subset, dbl eq not subset, double equals
	{ 0x2285, "nsup" },			// not superset not superset
	{ 0x2289, "nsupE" },		// not superset, equals not superset, double equals
	{ 0x2289, "nsupe" },		// not superset, equals not superset, equals
	{ 0x22AC, "nvdash" },		// not vertical, dash not vertical, dash
	{ 0x22AD, "nvDash" },		// not vertical, dbl dash not vertical, double dash
	{ 0x22AF, "nVDash" },		// not dbl vert, dbl dash not double vert, double dash
	{ 0x22AE, "nVdash" },		// not dbl vertical, dash not double vertical, dash
	{ 0x22E8, "prnap" },		// precedes, not approx precedes, not approx
	{ 0x2AB5, "prnE" },			// precedes, not dbl eq precedes, not double equals
	{ 0x22E8, "prnsim" },		// precedes, not approx precedes, not similar
	{ 0x22E9, "scnap" },		// succeeds, not approx succeeds, not approx
	{ 0x2AB6, "scnE" },			// succeeds, not dbl eq succeeds, not double equals
	{ 0x22E9, "scnsim" },		// succeeds, not approx succeeds, not similar
	{ 0x228A, "subne" },		// subset, not equals subset, not equals
	{ 0x228A, "subnE" },		// subset, not equals subset, not double equals
	{ 0x228B, "supne" },		// superset, not dbl eq superset, not equals
	{ 0x228B, "supnE" },		// superset, not dbl eq superset, not double equals

//Arrows
	{ 0x21B6, "cularr" },		// left curved arrow left curved arrow
	{ 0x21B7, "curarr" },		// right curved arrow right curved arrow
	{ 0x21D3, "dArr" },			// down double arrow down double arrow
	{ 0x21CA, "darr2" },		// two down arrows two down arrows
	{ 0x21C3, "dharl" },		// down harpoon-left down harpoon-left
	{ 0x21C2, "dharr" },		// down harpoon-right down harpoon-right
	{ 0x21DA, "lAarr" },		// left triple arrow left triple arrow
	{ 0x219E, "Larr" },			// two head left arrow two head left arrow
	{ 0x21C7, "larr2" },		// two left arrows two left arrows
	{ 0x21A9, "larrhk" },		// left arrow-hooked left arrow-hooked
	{ 0x21AB, "larrlp" },		// left arrow-looped left arrow-looped
	{ 0x21A2, "larrtl" },		// left arrow-tailed left arrow-tailed
	{ 0x21BD, "lhard" },		// left harpoon-down left harpoon-down
	{ 0x21BC, "lharu" },		// left harpoon-up left harpoon-up
	{ 0x21D4, "hArr" },			// <--> left&right double arrow
	{ 0x2194, "harr" },			// <--> left&right arrow
	{ 0x21C6, "lrarr2" },		// left arrow over right arrow left arrow over right arrow
	{ 0x21C4, "rlarr2" },		// right arrow over left arrow right arrow over left arrow
	{ 0x21AD, "harrw" },		// left and right squig arrow left&right arrow-wavy
	{ 0x21CC, "rlhar2" },		// right harpoon over left harpoon right harp over left
	{ 0x21CB, "lrhar2" },		// left harpoon over right harpoon left harp over right
	{ 0x21B0, "lsh" },			// Lsh Lsh
	{ 0x21A6, "map" },			// mapsto maps to
	{ 0x22B8, "mumap" },		// multimap multi map
	{ 0x2197, "nearr" },		// NE pointing arrow near pointing arrow
	{ 0x21CD, "nlArr" },		// not Left arrow, not implied by
	{ 0x219A, "nlarr" },		// not left arrow not left arrow
	{ 0x21CE, "nhArr" },		// not l&r dbl arr not left&right double arrow
	{ 0x21AE, "nharr" },		// not l&r arrow not left&right arrow
	{ 0x219B, "nrarr" },		// not right arrow not right arrow
	{ 0x21CF, "nrArr" },		// not implies not implies
	{ 0x2196, "nwarr" },		// NW pointing arrow NW pointing arrow
	{ 0x21BA, "olarr" },		// left arrow in circle left arrow in circle
	{ 0x21BB, "orarr" },		// right arrow in circle right arrow in circle
	{ 0x21DB, "rAarr" },		// right triple arrow right triple arrow
	{ 0x21A0, "Rarr" },			// two head right arrow two head rightarrow
	{ 0x21C9, "rarr2" },		// two right arrows two right arrows
	{ 0x21AA, "rarrhk" },		// right arrow-hooked right arrow-hooked
	{ 0x21AC, "rarrlp" },		// right arrow-looped right arrow-looped
	{ 0x21A3, "rarrtl" },		// right arrow-tailed right arrow-tailed
	{ 0x21DD, "rarrw" },		// right arrow-wavy right arrow-wavy
	{ 0x21C1, "rhard" },		// right harpoon-down right harpoon-down
	{ 0x21C0, "rharu" },		// right harpoon-up right harpoon-up
	{ 0x21B1, "rsh" },			// Rsh Rsh
	{ 0x2198, "drarr" },		// SE pointing arrow downward right arrow
	{ 0x2199, "dlarr" },		// SW pointing arrow downward left arrow
	{ 0x21D1, "uArr" },			// up dbl arrow up double arrow
	{ 0x21C8, "uarr2" },		// two up arrows two up arrows
	{ 0x21D5, "vArr" },			// up and down dbl arrow up&down double arrow
	{ 0x2195, "varr" },			// up and down arrow up&down arrow
	{ 0x21BF, "uharl" },		// up harpoon-left up harpoon-left
	{ 0x21BE, "uharr" },		// up harp-right up harp-right

//Binary Operators
	{ 0x2306, "Barwed" },		// log and, dbl bar logical and, double bar
	{ 0x22BC, "barwed" },		// logical and, bar above logical and, bar above
	{ 0x22D2, "Cap" },			// dbl intersection double intersection
	{ 0x22D3, "Cup" },			// dbl union double union
	{ 0x22CE, "cuvee" },		// curly logical or curly logical or
	{ 0x22CF, "cuwed" },		// curly logical and curly logical and
	{ 0x22C4, "diam" },			// open diamond open diamond
	{ 0x22C7, "divonx" },		// division on times division on times
	{ 0x22BA, "intcal" },		// intercal intercal
	{ 0x22CB, "lthree" },		// leftthreetimes left three times
	{ 0x22C9, "ltimes" },		// times sign, left closed times sign, left closed
	{ 0x229F, "minusb" },		// minus sign in box minus sign in box
	{ 0x229B, "oast" },			// asterisk in circle asterisk in circle
	{ 0x229A, "ocir" },			// open dot in circle open dot in circle
	{ 0x229D, "odash" },		// hyphen in circle hyphen in circle
	{ 0x2299, "odot" },			// middle dot in circle middle dot in circle
	{ 0x2296, "ominus" },		// minus sign in circle minus sign in circle
	{ 0x2295, "oplus" },		// plus sign in circle plus sign in circle
	{ 0x2298, "osol" },			// solidus in circle solidus in circle
	{ 0x2297, "otimes" },		// multiply sign in circle multiply sign in circle
	{ 0x229E, "plusb" },		// plus sign in box plus sign in box
	{ 0x2214, "plusdo" },		// plus sign, dot above plus sign, dot above
	{ 0x22CC, "rthree" },		// rightthreetimes right threetimes
	{ 0x22CA, "rtimes" },		// times sign, right closed times sign, right closed
	{ 0x00B7, "sdot" },			// .  small middle dot
	{ 0x22A1, "sdotb" },		// small dot in box small dot in box
	{ 0x2216, "setmn" },		// \\ reverse solidus
	{ 0x2293, "sqcap" },		// square intersection square intersection
	{ 0x2294, "sqcup" },		// square union square union
	{ 0x22C6, "sstarf" },		// small star, filled small star, filled
	{ 0x22A0, "timesb" },		// multiply sign in box multiply sign in box
	{ 0x22A4, "top" },			// inverted perpendicular inverted perpendicular
	{ 0x228E, "uplus" },		// plus sign in union plus sign in union
	{ 0x2240, "wreath" },		// wreath product wreath product
	{ 0x25EF, "xcirc" },		// large circle large circle
	{ 0x25BD, "xdtri" },		// big dn tri, open big triangle down open
	{ 0x25B3, "xutri" },		// big up tri, open big triangle up open
	{ 0x2210, "coprod" },		// coproduct operator coproduct operator
	{ 0x220F, "prod" },			// product operator product operator
	{ 0x2211, "sum" },			// summation operator summation operator

//Added Math Symbols - Operators
	{ 0x221F, "ang" },			// 90 degree angle angle
	{ 0x2221, "angmsd" },		// measured angle angle-measured
	{ 0x2136, "beth" },			// beth beth, Hebrew
	{ 0x2035, "bprime" },		// ' reverse prime
	{ 0x2201, "comp" },			// complement complement sign
	{ 0x2138, "daleth" },		// daleth daleth, Hebrew
	{ 0x2113, "ell" },			// l cursive small l
	{ 0x2137, "gimel" },		// gimel gimel, Hebrew
	{ 0x2111, "image" },		// imaginary imaginary
	{ 0x0131, "inodot" },		// i small i, no dot
	{ 0x2204, "nexist" },		// negated exists negated exists
	{ 0x24C8, "oS" },				// S in circle capital S in circle
	{ 0x210F, "planck" },		// variant Planck's over 2pi Planck's over 2pi
	{ 0x211C, "real" },			// Re Re - real
	{ 0x005C, "sbsol" },		// \\ short reverse solidus
	{ 0x2032, "vprime" },		// ' prime, variant
	{ 0x2118, "weierp" },		// Weierstrass p Weierstrass p

//Added Math Symbols - Relations
	{ 0x224A, "ape" },			// approximate, equals approximate, equals
	{ 0x224D, "asymp" },		// asymptotically equal to asymptotically equal to
	{ 0x224C, "bcong" },		// reverse congruent reverse congruent
	{ 0x22C8, "bowtie" },		// bowtie R bowtie
	{ 0x223D, "bsim" },			// reverse similar reverse similar
	{ 0x22CD, "bsime" },		// reverse similar reverse similar, equals
	{ 0x224E, "bump" },			// bumpy equals bumpy equals
	{ 0x224F, "bumpe" },		// bumpy equals, equals bumpy equals, equals
	{ 0x2257, "cire" },			// o= circle, equals
	{ 0x2254, "colone" },		// := colon, equals
	{ 0x22DE, "cuepr" },		// equal to or precedes curly equals, precedes
	{ 0x22DF, "cuesc" },		// equal to or succeeds curly equals, succeeds
	{ 0x227C, "cupre" },		// precedes or equal to curly precedes, equals
	{ 0x22A3, "dashv" },		// dash, vertical dash, vertical
	{ 0x2256, "ecir" },			// circle on equals sign circle on equals sign
	{ 0x2255, "ecolon" },		// =: equals, colon
	{ 0x2251, "eDot" },			// =...  equals, even dots
	{ 0x2250, "esdot" },		// equals, single dot above equals, single dot above
	{ 0x2252, "efDot" },		// falling dots equals, falling dots
	{ 0x22DD, "egs" },			// =/> equal-or-greater, slanted
	{ 0x22DC, "els" },			// =/< equals-or-less, slanted
	{ 0x2253, "erDot" },		// rising dots equals, rising dots
	{ 0x22D4, "fork" },			// pitchfork pitch fork
	{ 0x2322, "frown" },		// down curve down curve
	{ 0x2273, "gap" },			// greater, similar greater, approximate
	{ 0x22D7, "gsdot" },		// greater than, with dot greater than, single dot
	{ 0x2267, "gE" },				// >== greater, double equals
	{ 0x22DB, "gel" },			// >=< greater, equals, less
	{ 0x22DB, "gEl" },			// >=< gt, double equals, less
	{ 0x22D9, "Gg" },				// >>> triple gtr-than
	{ 0x2277, "gl" },				// >< greater, less
	{ 0x2273, "gsim" },			// greater, similar greater, similar
	{ 0x226B, "Gt" },				// >> double greater-than sign
	{ 0x2272, "lap" },			// less, similar less, approximate
	{ 0x22D6, "ldot" },			// less than, with dot less than, with dot
	{ 0x2266, "lE" },				// <== less, double equals
	{ 0x22DA, "lEg" },			// <=> less, double equals, greater
	{ 0x22DA, "leg" },			// <=> less, equals, greater
	{ 0x2276, "lg" },				// <> less, greater
	{ 0x22D8, "Ll" },				// <<< triple less-than
	{ 0x2272, "lsim" },			// less, similar less, similar
	{ 0x226A, "Lt" },				// << double less-than sign
	{ 0x22B4, "ltrie" },		// left triangle, eq left triangle, equals
	{ 0x2223, "mid" },			// mid R: mid
	{ 0x22A7, "models" },		// models R: models
	{ 0x227A, "pr" },				// equal to or precedes precedes
	{ 0x227E, "prap" },			// similar precedes, approximate
	{ 0x227E, "prsim" },		// similar precedes, similar
	{ 0x22B5, "rtrie" },		// right tri, eq right triangle , equals
	{ 0x2210, "samalg" },		// coproduct operator small amalg
	{ 0x227B, "sc" },				// equal to or succeeds succeeds
	{ 0x227F, "scap" },			// succeeds, similar succeeds, approximate
	{ 0x227D, "sccue" },		// succeeds, equals succeeds, curly equals
	{ 0x227D, "sce" },			// succeeds, equals succeeds, equals
	{ 0x227F, "scsim" },		// succeeds, similar succeeds, similar
	{ 0x2322, "sfrown" },		// down curve small down curve
	{ 0x2223, "smid" },			// shortmid R: short mid
	{ 0x2323, "smile" },		// up curve smile up curve
	{ 0x228F, "sqsub" },		// square subset square subset
	{ 0x2291, "sqsube" },		// square subset, equals square subset, equals
	{ 0x2290, "sqsup" },		// square superset square superset
	{ 0x2292, "sqsupe" },		// square superset, eq square superset, equals
	{ 0x2323, "ssmile" },		// up curve small up curve
	{ 0x22D0, "Sub" },			// double subset double subset
	{ 0x2286, "subE" },			// subset, dbl equals subset, double equals
	{ 0x22D1, "Sup" },			// dbl superset double superset
	{ 0x2287, "supE" },			// superset, dbl equals superset, double equals
	{ 0xE306, "thkap" },		// thick approximate thick approximate
	{ 0xE429, "thksim" },		// thick similar thick similar
	{ 0x225C, "trie" },			// triangle, equals triangle, equals
	{ 0x226C, "twixt" },		// between between
	{ 0x22A2, "vdash" },		// vertical, dash vertical, dash
	{ 0x22A9, "Vdash" },		// dbl vertical, dash double vertical, dash
	{ 0x22A8, "vDash" },		// vertical, dbl dash vertical, double dash
	{ 0x22BB, "veebar" },		// logical or, bar below logical or, bar below
	{ 0x22B2, "vltri" },		// left tri, open, var left triangle , open, var
	{ 0x221D, "vprop" },		// proportional, variant proportional, variant
	{ 0x22B3, "vrtri" },		// right tri, open, var right triangle , open, var
	{ 0x22AA, "Vvdash" },		// triple vertical, dash triple vertical, dash

//Russian Cyrillic
	{ 0x0430, "acy" },			// small a, Cyrillic small a, Cyrillic
	{ 0x0410, "Acy" },			// capital A, Cyrillic capital A, Cyrillic
	{ 0x0431, "bcy" },			// small be, Cyrillic small be, Cyrillic
	{ 0x0411, "Bcy" },			// capital BE, Cyrillic capital BE, Cyrillic
	{ 0x0432, "vcy" },			// small ve, Cyrillic small ve, Cyrillic
	{ 0x0412, "Vcy" },			// capital VE, Cyrillic capital VE, Cyrillic
	{ 0x0433, "gcy" },			// small ghe, Cyrillic small ghe, Cyrillic
	{ 0x0413, "Gcy" },			// capital GHE, Cyrillic capital GHE, Cyrillic
	{ 0x0434, "dcy" },			// small de, Cyrillic small de, Cyrillic
	{ 0x0414, "Dcy" },			// capital DE, Cyrillic capital DE, Cyrillic
	{ 0x0435, "iecy" },			// small ie, Cyrillic small ie, Cyrillic
	{ 0x0415, "IEcy" },			// capital IE, Cyrillic capital IE, Cyrillic
	{ 0x0451, "iocy" },			// small io, Russian small io, Russian
	{ 0x0401, "IOcy" },			// capital IO, Russian capital IO, Russian
	{ 0x0436, "zhcy" },			// small zhe, Cyrillic small zhe, Cyrillic
	{ 0x0416, "ZHcy" },			// capital ZHE, Cyrillic capital ZHE, Cyrillic
	{ 0x0437, "zcy" },			// small ze, Cyrillic small ze, Cyrillic
	{ 0x0417, "Zcy" },			// capital ZE, Cyrillic capital ZE, Cyrillic
	{ 0x0438, "icy" },			// small i, Cyrillic small i, Cyrillic
	{ 0x0418, "Icy" },			// capital I, Cyrillic capital I, Cyrillic
	{ 0x0439, "jcy" },			// small short i, Cyrillic small short i, Cyrillic
	{ 0x0419, "Jcy" },			// capital short I, Cyrillic capital short I, Cyrillic
	{ 0x043A, "kcy" },			// small ka, Cyrillic small ka, Cyrillic
	{ 0x041A, "Kcy" },			// capital KA, Cyrillic capital KA, Cyrillic
	{ 0x043B, "lcy" },			// small el, Cyrillic small el, Cyrillic
	{ 0x041B, "Lcy" },			// capital EL, Cyrillic capital EL, Cyrillic
	{ 0x043C, "mcy" },			// small em, Cyrillic small em, Cyrillic
	{ 0x041C, "Mcy" },			// capital EM, Cyrillic capital EM, Cyrillic
	{ 0x043D, "ncy" },			// small en, Cyrillic small en, Cyrillic
	{ 0x041D, "Ncy" },			// capital EN, Cyrillic capital EN, Cyrillic
	{ 0x043E, "ocy" },			// small o, Cyrillic small o, Cyrillic
	{ 0x041E, "Ocy" },			// capital O, Cyrillic capital O, Cyrillic
	{ 0x043F, "pcy" },			// small pe, Cyrillic small pe, Cyrillic
	{ 0x041F, "Pcy" },			// capital PE, Cyrillic capital PE, Cyrillic
	{ 0x0440, "rcy" },			// small er, Cyrillic small er, Cyrillic
	{ 0x0420, "Rcy" },			// capital ER, Cyrillic capital ER, Cyrillic
	{ 0x0441, "scy" },			// small es, Cyrillic small es, Cyrillic
	{ 0x0421, "Scy" },			// capital ES, Cyrillic capital ES, Cyrillic
	{ 0x0442, "tcy" },			// small te, Cyrillic small te, Cyrillic
	{ 0x0422, "Tcy" },			// capital TE, Cyrillic capital TE, Cyrillic
	{ 0x0443, "ucy" },			// small u, Cyrillic small u, Cyrillic
	{ 0x0423, "Ucy" },			// capital U, Cyrillic capital U, Cyrillic
	{ 0x0444, "fcy" },			// small ef, Cyrillic small ef, Cyrillic
	{ 0x0424, "Fcy" },			// capital EF, Cyrillic capital EF, Cyrillic
	{ 0x0445, "khcy" },			// small ha, Cyrillic small ha, Cyrillic
	{ 0x0425, "KHcy" },			// capital HA, Cyrillic capital HA, Cyrillic
	{ 0x0446, "tscy" },			// small tse, Cyrillic small tse, Cyrillic
	{ 0x0426, "TScy" },			// capital TSE, Cyrillic capital TSE, Cyrillic
	{ 0x0447, "chcy" },			// small che, Cyrillic small che, Cyrillic
	{ 0x0427, "CHcy" },			// capital CHE, Cyrillic capital CHE, Cyrillic
	{ 0x0448, "shcy" },			// small sha, Cyrillic small sha, Cyrillic
	{ 0x0428, "SHcy" },			// capital SHA, Cyrillic capital SHA, Cyrillic
	{ 0x0449, "shchcy" },		// small shcha, Cyrillic small shcha, Cyrillic
	{ 0x0429, "SHCHcy" },		// capital SHCHA, Cyrillic capital SHCHA, Cyrillic
	{ 0x044A, "hardcy" },		// small hard sign, Cyrillic small hard sign, Cyrillic
	{ 0x042A, "HARDcy" },		// capital HARD sign, Cyrillic capital HARD sign, Cyrillic
	{ 0x044B, "ycy" },			// small yeru, Cyrillic small yeru, Cyrillic
	{ 0x042B, "Ycy" },			// capital YERU, Cyrillic capital YERU, Cyrillic
	{ 0x044C, "softcy" },		// small soft sign, Cyrillic small soft sign, Cyrillic
	{ 0x042C, "SOFTcy" },		// capital SOFT sign, Cyrillic capital SOFT sign, Cyrillic
	{ 0x044D, "ecy" },			// small e, Cyrillic small e, Cyrillic
	{ 0x042D, "Ecy" },			// capital E, Cyrillic capital E, Cyrillic
	{ 0x044E, "yucy" },			// small yu, Cyrillic small yu, Cyrillic
	{ 0x042E, "YUcy" },			// capital YU, Cyrillic capital YU, Cyrillic
	{ 0x044F, "yacy" },			// small ya, Cyrillic small ya, Cyrillic
	{ 0x042F, "YAcy" },			// capital YA, Cyrillic capital YA, Cyrillic
	{ 0x2116, "numero" },		// numero sign numero sign

//Non-Russian Cyrillic
	{ 0x0452, "djcy" },			// small dje, Serbian small dje, Serbian
	{ 0x0402, "DJcy" },			// capital DJE, Serbian capital DJE, Serbian
	{ 0x0453, "gjcy" },			// small gje, Macedonian small gje, Macedonian
	{ 0x0403, "GJcy" },			// capital GJE Macedonian capital GJE Macedonian
	{ 0x0454, "jukcy" },		// small je, Ukrainian small je, Ukrainian
	{ 0x0404, "Jukcy" },		// capital JE, Ukrainian capital JE, Ukrainian
	{ 0x0455, "dscy" },			// small dse, Macedonian small dse, Macedonian
	{ 0x0405, "DScy" },			// capital DSE, Macedonian capital DSE, Macedonian
	{ 0x0456, "iukcy" },		// small i, Ukrainian small i, Ukrainian
	{ 0x0406, "Iukcy" },		// capital I, Ukrainian capital I, Ukrainian
	{ 0x0457, "yicy" },			// small yi, Ukrainian small yi, Ukrainian
	{ 0x0407, "YIcy" },			// capital YI, Ukrainian capital YI, Ukrainian
	{ 0x0458, "jsercy" },		// small je, Serbian small je, Serbian
	{ 0x0408, "Jsercy" },		// capital JE, Serbian capital JE, Serbian
	{ 0x0459, "ljcy" },			// small lje, Serbian small lje, Serbian
	{ 0x0409, "LJcy" },			// capital LJE, Serbian capital LJE, Serbian
	{ 0x045A, "njcy" },			// small nje, Serbian small nje, Serbian
	{ 0x040A, "NJcy" },			// capital NJE, Serbian capital NJE, Serbian
	{ 0x045B, "tshcy" },		// small tshe, Serbian small tshe, Serbian
	{ 0x040B, "TSHcy" },		// capital TSHE, Serbian capital TSHE, Serbian
	{ 0x045C, "kjcy" },			// small kje Macedonian small kje Macedonian
	{ 0x040C, "KJcy" },			// capital KJE, Macedonian capital KJE, Macedonian
	{ 0x045E, "ubrcy" },		// small u, Byelorussian small u, Byelorussian
	{ 0x040E, "Ubrcy" },		// capital U, Byelorussian capital U, Byelorussian
	{ 0x045F, "dzcy" },			// small dze, Serbian small dze, Serbian
	{ 0x040F, "DZcy" },			// capital dze, Serbian capital dze, Serbian

//Box and Line Drawing
	{ 0x2500, "boxh" },			// horizontal line horizontal line
	{ 0x2502, "boxv" },			// vertical line vertical line
	{ 0x2514, "boxur" },		// upper right quadrant upper right quadrant
	{ 0x2518, "boxul" },		// upper left quadrant upper left quadrant
	{ 0x2510, "boxdl" },		// lower left quadrant lower left quadrant
	{ 0x250C, "boxdr" },		// lower right quadrant lower right quadrant
	{ 0x251C, "boxvr" },		// upper and lower right quadrants upper and lower right quadrants
	{ 0x2534, "boxhu" },		// upper left and right quadrants upper left and right quadrants
	{ 0x2524, "boxvl" },		// upper and lower left quadrants upper and lower left quadrants
	{ 0x252C, "boxhd" },		// lower left and right quadrants lower left and right quadrants
	{ 0x253C, "boxvh" },		// all four quadrants all four quadrants
	{ 0x255E, "boxvR" },		// upper and lower right quadrants upper and lower right quadrants
	{ 0x2568, "boxhU" },		// upper left and right quadrants upper left and right quadrants
	{ 0x2561, "boxvL" },		// upper and lower left quadrants upper and lower left quadrants
	{ 0x2565, "boxhD" },		// lower left and right quadrants lower left and right quadrants
	{ 0x256A, "boxvH" },		// all four quadrants all four quadrants
	{ 0x2550, "boxH" },			// horizontal line horizontal line
	{ 0x2551, "boxV" },			// vertical line vertical line
	{ 0x255A, "boxUR" },		// upper right quadrant upper right quadrant
	{ 0x255D, "boxUL" },		// upper left quadrant upper left quadrant
	{ 0x2557, "boxDL" },		// lower left quadrant lower left quadrant
	{ 0x2554, "boxDR" },		// lower right quadrant lower right quadrant
	{ 0x2560, "boxVR" },		// upper and lower right quadrants upper and lower right quadrants
	{ 0x2569, "boxHU" },		// upper left and right quadrants upper left and right quadrants
	{ 0x2563, "boxVL" },		// upper and lower left quadrants upper and lower left quadrants
	{ 0x2566, "boxHD" },		// lower left and right quadrants lower left and right quadrants
	{ 0x256C, "boxVH" },		// all four quadrants all four quadrants
	{ 0x255F, "boxVr" },		// upper and lower right quadrants upper and lower right quadrants
	{ 0x2567, "boxHu" },		// upper left and right quadrants upper left and right quadrants
	{ 0x2562, "boxVl" },		// upper and lower left quadrants upper and lower left quadrants
	{ 0x2564, "boxHd" },		// lower left and right quadrants lower left and right quadrants
	{ 0x256B, "boxVh" },		// all four quadrants all four quadrants
	{ 0x2558, "boxuR" },		// upper right quadrant upper right quadrant
	{ 0x255C, "boxUl" },		// upper left quadrant upper left quadrant
	{ 0x2555, "boxdL" },		// lower left quadrant lower left quadrant
	{ 0x2553, "boxDr" },		// lower right quadrant lower right quadrant
	{ 0x2559, "boxUr" },		// upper right quadrant upper right quadrant
	{ 0x255B, "boxuL" },		// upper left quadrant upper left quadrant
	{ 0x2556, "boxDl" },		// lower left quadrant lower left quadrant
	{ 0x2552, "boxdR" }			// lower right quadrant lower right quadrant
};




} /* namespace xqp */
#endif /* XQP_CHARACTER_ENTITIES_H */


