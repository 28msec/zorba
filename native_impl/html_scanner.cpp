/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: html_scanner.cpp,v 1.1.1.1 2006/10/09 06:58:31 Paul Pedersen Exp $
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


#include "html_scanner.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>

#include "../util/hashmap.h"

using namespace std;

namespace xqp {
/*
static int theWinMap[] = {     // Windows chars map
    0x20AC, 0xFFFD, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
    0x02C6, 0x2030, 0x0160, 0x2039, 0x0152, 0xFFFD, 0x017D, 0xFFFD,
    0xFFFD, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
    0x02DC, 0x2122, 0x0161, 0x203A, 0x0153, 0xFFFD, 0x017E, 0x0178
  };
*/

static int stateTable[34][22] = {
/*EOF  WS  DEF   CR   LF   LT   GT   SL   EQ DASH  AMP APOS QUOT BANG HOOK  PER    C    D    A    T LBRA RBRA */
{ 34,  13,   0,   0,   0,   0,  16,  24,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },//ANAME      0
{ 34,   1,   1,   1,   1,   1,   1,   1,   1,   1,  12,  23,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1 },//APOS       1
{ 34,   2,  21,  21,  21,  21,  16,  21,  21,  21,  21,   1,  20,  21,  21,  21,  21,  21,  21,  21,  21,  21 },//AVAL       2
{ 34,   3,   3,   9,   3,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3 },//CDATA      3
{ 34,   3,   3,   3,   3,   3,   3,  14,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3 },//CDATA2     4
{ 34,   5,   5,   6,   5,   5,   5,   5,   5,   7,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5 },//COM        5
{ 34,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5 },//COMCRLF    6
{ 34,   5,   5,   6,   5,   5,  16,   5,   5,   7,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5 },//COMD       7
{ 34,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16 },//CRLF       8
{ 34,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3 },//CCRLF      9
{ 34,  11,  11,  11,  11,  11,  16,  11,  11,   5,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  25,  11 },//DECL       10
{ 34,  11,  11,  11,  11,  11,  16,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11 },//DECL2      11
{ 34,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12 },//ENT        12
{ 34,  13,   0,   0,   0,   0,  16,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },//EQ         13
{ 34,  14,  14,  14,  14,  14,  16,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14 },//ETAG       14
{ 34,  23,  15,  15,  15,  15,  16,  24,  15,  15,  15,  15,  15,  15,  15,  15,  15,  15,  15,  15,  15,  15 },//GI         15
{ 34,  16,  16,   8,  16,  22,  16,  16,  16,  16,  12,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16 },//PCDATA     16
{ 34,  17,  17,  18,  17,  17,  16,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17 },//PI         17
{ 34,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17 },//PICRLF     18
{ 34,  17,  19,  19,  19,  19,  16,  19,  19,  19,  19,  19,  19,  19,  19,  19,  19,  19,  19,  19,  19,  19 },//PITARGET   19
{ 34,  20,  20,  20,  20,  20,  20,  20,  20,  20,  12,  20,  23,  20,  20,  20,  20,  20,  20,  20,  20,  20 },//QUOT       20
{ 34,  23,  21,  21,  21,  21,  16,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21 },//STAGC      21
{ 34,  16,  15,  15,  15,  15,  15,  14,  15,  15,  15,  15,  15,  10,  19,  15,  15,  15,  15,  15,  15,  15 },//TAG        22
{ 34,  23,   0,   0,   0,   0,  16,  24,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },//TAGWS      23
{  0,  23,   0,   0,   0,   0,  16,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },//EMPTYTAG   24
{ 34,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  26,  10,  10,  10,  10,  10 },//BB         25
{ 34,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  27,  10,  10,  10,  10 },//BBC        26
{ 34,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  28,  10,  10,  10 },//BBCD       27
{ 34,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  29,  10,  10 },//BBCDA      28
{ 34,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  30,  10,  10,  10 },//BBCDAT     29
{ 34,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,  31,  10 },//BBCDATA    30
{ 34,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  32 },//CDSECT     31
{ 34,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  33 },//CDSECT1    32
{ 34,  31,  31,  31,  31,  31,  16,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31,  31 } //CDSECT2    33
};


static int actionTable[34][22] = {
/*EOF  WS  DEF   CR   LF   LT   GT   SL   EQ DASH  AMP APOS QUOT BANG HOOK  PER    C    D    A    T LBRA RBRA */
{  4,   3,  23,  23,  23,  23,   4,  12,   3,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//ANAME      0
{  6,  26,  23,  23,  23,  23,  23,  23,  23,  23,  24,   5,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//APOS       1
{  6,  25,  23,  23,  23,  23,   6,  23,  23,  23,  23,  25,  25,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//AVAL       2
{ 18,  23,  23,  15,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//CDATA      3
{ 29,  23,  23,  23,  23,  23,  23,  29,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//CDATA2     4
{  8,  23,  23,  15,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//COM        5
{  8,  28,  28,  28,  25,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28 },//COMCRLF    6
{  8,  23,  23,  15,  23,  23,   8,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//COMD       7
{ 25,  28,  28,  28,  25,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28 },//CRLF       8
{ 25,  28,  28,  28,  25,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28 },//CCRLF      9
{ 25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25 },//DECL       10
{ 25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25 },//DECL2      11
{  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9 },//ENT        12
{  2,  25,   1,   1,   1,   1,   2,   1,  25,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1 },//EQ         13
{ 10,  25,  23,  23,  23,  23,  10,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//ETAG       14
{ 25,  13,  23,  23,  23,  23,  14,  25,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//GI         15
{ 18,  23,  23,  15,  23,  18,  23,  23,  23,  23,  19,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//PCDATA     16
{ 20,  23,  23,  15,  23,  23,  20,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//PI         17
{ 20,  28,  28,  28,  25,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28 },//PICRLF     18
{ 22,  21,  23,  23,  23,  23,  22,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//PITARGET   19
{  6,  26,  23,  23,  23,  23,  23,  23,  23,  23,  24,  23,   5,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//QUOT       20
{  6,   5,  23,  23,  23,  23,   6,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//STAGC      21
{ 17,  16,  23,  23,  23,  23,  23,  25,  23,  23,  23,  23,  23,  25,  25,  23,  23,  23,  23,  23,  23,  23 },//TAG        22
{ 27,  25,  23,  23,  23,  23,  27,  25,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//TAGWS      23
{ 23,  25,  23,  23,  23,  23,  11,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//EMPTYTAG   24
{ 25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25 },//BB         25
{ 25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25 },//BBC        26
{ 25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25 },//BBCD       27
{ 25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25 },//BBCDA      28
{ 25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25 },//BBCDAT     29
{ 25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25,  25 },//BBCDATA    30
{ 25,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//CDSECT     31
{ 25,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 },//CDSECT1    32
{ 25,  23,  23,  23,  23,  23,   7,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23 } //CDSECT2    33
};

static int lexTable[128] = {
/*0x00-0x07*/   -1,   -1,   -1,   -1,   -1,   -1,   -1,   WS,
/*0x08-0x0f*/   WS,   WS,   LF,   WS,   WS,   CR,   -1,   -1,
/*0x10-0x17*/   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
/*0x18-0x1f*/   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
/*0x20-0x27*/   WS, BANG, QUOT,  DEF,  DEF,  PER,  AMP, APOS,
/*0x28-0x2f*/  DEF,  DEF,  DEF,  DEF,  DEF, DASH,  DEF,   SL,
/*0x30-0x37*/  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,
/*0x38-0x3f*/  DEF,  DEF,  DEF,  DEF,   LT,   EQ,   GT, HOOK,
/*0x40-0x47*/  DEF,    A,  DEF,    C,    D,  DEF,  DEF,  DEF,
/*0x48-0x4f*/  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,
/*0x50-0x57*/  DEF,  DEF,  DEF,  DEF,    T,  DEF,  DEF,  DEF,
/*0x58-0x5f*/  DEF,  DEF,  DEF, LBRA,  DEF, RBRA,  DEF,  DEF,
/*0x60-0x67*/  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,
/*0x68-0x6f*/  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,
/*0x70-0x77*/  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,
/*0x78-0x7f*/  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,  DEF,   -1
};


const char* decodeTok(int tok)
{
	switch (tok) {
	case EOF_:	return "EOF_";
	case WS:		return "WS";
	case DEF:		return "DEF";
	case CR:		return "CR";
	case LF:		return "LF";
	case LT:		return "LT";
	case GT:		return "GT";
	case SL:		return "SL";
	case EQ:		return "EQ";
	case DASH:	return "DASH";
	case AMP:		return "AMP";
	case APOS:	return "APOS";
	case QUOT:	return "QUOT";
	case BANG:	return "BANG";
	case HOOK:	return "HOOK";
	case PER:		return "PER";
	case C:			return "C";
	case D:			return "D";
	case A:			return "A";
	case T:			return "T";
	case LBRA:	return "LBRA";
	case RBRA:	return "RBRA";
	default: return "CH_UNRECOGNIZED";
	}
}

const char* decodeState(int state)
{
	switch (state) {
	case  S_ANAME:   	return "S_ANAME";
	case  S_APOS:     return "S_APOS";
	case  S_AVAL:    	return "S_AVAL";
	case  S_CDATA:    return "S_CDATA";
	case  S_CDATA2:  	return "S_CDATA2";
	case  S_COM:     	return "S_COM";
	case  S_COMCRLF: 	return "S_COMCRLF";
	case  S_COMD:    	return "S_COMD";
	case  S_CRLF:    	return "S_CRLF";
	case  S_CCRLF:   	return "S_CCRLF";
	case  S_DECL:    	return "S_DECL";
	case  S_DECL2:    return "S_DECL2";
	case  S_ENT:     	return "S_ENT";
	case  S_EQ:      	return "S_EQ";
	case  S_ETAG:    	return "S_ETAG";
	case  S_GI:      	return "S_GI";
	case  S_PCDATA:  	return "S_PCDATA";
	case  S_PI:      	return "S_PI";
	case  S_PITARGET:	return "S_PITARGET";
	case  S_QUOT:    	return "S_QUOT";
	case  S_STAGC:   	return "S_STAGC";
	case  S_TAG:     	return "S_TAG";
	case  S_TAGWS:   	return "S_TAGWS";
	case  S_EMPTYTAG:	return "S_EMPTYTAG";
	case  S_BB:      	return "S_BB";
	case  S_BBC:     	return "S_BBC";
	case  S_BBCD:    	return "S_BBCD";
	case  S_BBCDA:   	return "S_BBCDA";
	case  S_BBCDAT:  	return "S_BBCDAT";
	case  S_BBCDATA: 	return "S_BBCDATA";
	case  S_CDSECT:  	return "S_CDSECT";
	case  S_CDSECT1: 	return "S_CDSECT1";
	case  S_CDSECT2: 	return "S_CDSECT2";
	case  S_DONE:    	return "S_DONE";
	default: 					return "S_UNRECOGNIZED";
	}
}

const char* decodeAction(int action)
{
	switch (action) {
	case A_ADUP:							return"A_ADUP";
	case A_ADUP_SAVE:					return"A_ADUP_SAVE";
	case A_ADUP_STAGC:				return"A_ADUP_STAGC";
	case A_ANAME:							return"A_ANAME";
	case A_ANAME_ADUP_STAGC:	return"A_ANAME_ADUP_STAGC";
	case A_AVAL:							return"A_AVAL";
	case A_AVAL_STAGC:				return"A_AVAL_STAGC";
	case A_CDATA:							return"A_CDATA";
	case A_CMNT:							return"A_CMNT";
	case A_ENTITY:						return"A_ENTITY";
	case A_ETAG:							return"A_ETAG";
	case A_EMPTYTAG:					return"A_EMPTYTAG";
	case A_ANAME_ADUP:				return"A_ANAME_ADUP";
	case A_GI:								return"A_GI";
	case A_GI_STAGC:					return"A_GI_STAGC";
	case A_LF:								return"A_LF";
	case A_LT:								return"A_LT";
	case A_LT_PCDATA:					return"A_LT_PCDATA";
	case A_PCDATA:						return"A_PCDATA";
	case A_PCDATA_SAVE_PUSH:	return"A_PCDATA_SAVE_PUSH";
	case A_PI:								return"A_PI";
	case A_PITARGET:					return"A_PITARGET";
	case A_PITARGET_PI:				return"A_PITARGET_PI";
	case A_SAVE:							return"A_SAVE";
	case A_SAVE_PUSH:					return"A_SAVE_PUSH";
	case A_SKIP:							return"A_SKIP";
	case A_SP:								return"A_SP";
	case A_STAGC:							return"A_STAGC";
	case A_UNGET:		 					return"A_UNGET";
	case A_UNSAVE_PCDATA:			return"A_UNSAVE_PCDATA";
	default: return "A_UNRECOGNIZED";
	}
}


html_scanner::html_scanner()
:
	theOutputBuffer(new char[1<<20]),
	theSize(0)
{
}

html_scanner::~html_scanner()
{
	delete[] theOutputBuffer;
}


void html_scanner::scan(const char* r, unsigned len, scan_handler* h)
{
	theState = S_PCDATA;
	theSize = 0;
	int savedState = 0;
	int savedSize  = 0;
	char* p = const_cast<char *>(r);	// begin pointer
	char* e = (p+len);								// end pointer
	unicode_decompositions ud;

	while (theState!=S_DONE && p<e) {
		int ch = *p++;
		if (ch==EOF) break;
		if (ch < 0x20 && ch != '\n' && ch != '\r' && ch != '\t' && ch != -1) continue;
		int tok = (ch < 0x80) ? lexTable[ch] : DEF;
		if (tok==-1) continue;

		int action = 0;
		theNextState = stateTable[theState][tok];
		action       = actionTable[theState][tok];

		if (theNextState==-1) {
			cerr	<< "html_scanner can't cope with '"<< decodeTok(tok)
						<< "' in state " << decodeState(theState) << endl;
			continue;
		}

  /*
		cout << decodeState(theState) << '(' << (char)ch << ")[ " << decodeTok(tok) << " ] -> "
				 << decodeAction(action) << ", " << decodeState(theNextState) << endl;
	*/
  
		switch (action) {
		case A_ADUP:							// attr(=)
			h->adup(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
   	case A_ADUP_SAVE:					// attr(=)
			h->adup(theOutputBuffer, 0, theSize);
			theSize = 0;
			if (theSize >= ((1<<20)-20)) flush(h);
			theOutputBuffer[theSize++] = (char)ch;
			break;
   	case A_ADUP_STAGC:				// attr>
			h->adup(theOutputBuffer, 0, theSize);
			theSize = 0;
			h->stagc(theOutputBuffer, 0, theSize);
			break;
   	case A_ANAME:							// attr=
			h->aname(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
   	case A_ANAME_ADUP:				// attr= attr
			h->aname(theOutputBuffer, 0, theSize);
			theSize = 0;
			h->adup(theOutputBuffer, 0, theSize);
			break;
   	case A_ANAME_ADUP_STAGC:	// attr= attr>
			h->aname(theOutputBuffer, 0, theSize);
			theSize = 0;
			h->adup(theOutputBuffer, 0, theSize);
			h->stagc(theOutputBuffer, 0, theSize);
			break;
   	case A_AVAL:							// (attribute=)val
			h->aval(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
   	case A_AVAL_STAGC:				// (attr=)val>
			h->aval(theOutputBuffer, 0, theSize);
			theSize = 0;
			h->stagc(theOutputBuffer, 0, theSize);
			break;
		case A_CDATA:							// <[[CDATA[
			// suppress the final "]]" in the buffer
			if (theSize > 1) theSize -= 2;
			h->pcdata(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
		case A_ENTITY:						// &ent;
			char ch1 = (char)ch;
			if (ch1=='\0') ch1 = ' ';
			if (isalnum(ch1) || ch1 == '#') {
				if (theSize >= ((1<<20)-20)) flush(h);
				theOutputBuffer[theSize++] = ch1;
				break;
			}
			if (ch1 != ';') {
				if (theSize >= ((1<<20)-20)) flush(h);
				theNextState = savedState;
				--p;
				break;
			}
			h->entity(theOutputBuffer, savedSize + 1, theSize - savedSize - 1);
			int ent = h->getEntity();
			if (ent != 0) {
				theSize = savedSize;
				if (ent < 0x20) ent = 0x20;
				if (ent < 0x7F) {
					if (theSize >= ((1<<20)-20)) flush(h);
					theOutputBuffer[theSize++] = (char)ent;
				}
				else {
					vector<unsigned short> decomposition;
					if (ud.decompose(ent,decomposition)) {
						if (theSize >= ((1<<20)-20)) flush(h);
						vector<unsigned short>::const_iterator it =decomposition.begin();
						for (; it!=decomposition.end(); ++it) {
							theOutputBuffer[theSize++] = (char)*it;
						}
					}
					else {
						if (theSize >= ((1<<20)-20)) flush(h);
						theOutputBuffer[theSize++] = '?';
					}
				}
			}
			else {
				theSize = savedSize;
				if (theSize >= ((1<<20)-20)) flush(h);
				theOutputBuffer[theSize++] = '?';
			}
			theNextState = savedState;
			break;
   	case A_ETAG:							// <tag/>
			h->etag(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
   	case A_GI:								// (<)tag
			h->gi(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
		case A_GI_STAGC:					// (<tag attr=aaa attr=bbb ...)>
			h->gi(theOutputBuffer, 0, theSize);
			theSize = 0;
			h->stagc(theOutputBuffer, 0, theSize);
			break;
   	case A_LF:								// LF
			if (theSize >= ((1<<20)-20)) flush(h);
			theOutputBuffer[theSize++] = '\n';
			break;
   	case A_LT:								// <
			if (theSize >= ((1<<20)-20)) flush(h);
			theOutputBuffer[theSize++] = '<';
			break;
		case A_LT_PCDATA:					// 
			if (theSize >= ((1<<20)-20)) flush(h);
			theOutputBuffer[theSize++] = '<';
			h->pcdata(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
   	case A_PCDATA:						// (>)...text...(<)
			h->pcdata(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
		case A_CMNT:							// <!
			h->cmnt(theOutputBuffer, 1, theSize - 3);
			theSize = 0;
			break;
   	case A_PI:								// <?
			h->pi(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
   	case A_PITARGET:					// (<?)target
			h->pitarget(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
   	case A_PITARGET_PI:				// (<?target ) pi
			h->pitarget(theOutputBuffer, 0, theSize);
			theSize = 0;
			h->pi(theOutputBuffer, 0, theSize);
			break;
		case A_PCDATA_SAVE_PUSH:	// 
			h->pcdata(theOutputBuffer, 0, theSize);
			theSize = 0;
			// fall through into A_SAVE_PUSH
   	case A_SAVE_PUSH:					//
			savedState = theState;
			savedSize = theSize;
			if (theSize >= ((1<<20)-20)) flush(h);
			theOutputBuffer[theSize++] = (char)ch;
			break;
   	case A_SAVE:
			if (theSize >= ((1<<20)-20)) flush(h);
			theOutputBuffer[theSize++] = (char)ch;
			break;
   	case A_SKIP:
			break;
   	case A_SP:
			if (theSize >= ((1<<20)-20)) flush(h);
			theOutputBuffer[theSize++] = ' ';
			break;
   	case A_STAGC:
			h->stagc(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
		case A_EMPTYTAG:
			if (theSize > 0) h->gi(theOutputBuffer, 0, theSize);
			theSize = 0;
			h->stagc(theOutputBuffer, 0, theSize);
			h->etag(theOutputBuffer, 0, theSize);
			break;
		case A_UNGET:
			if (ch != ';') p--;
			break;
   	case A_UNSAVE_PCDATA:
			if (theSize > 0) theSize--;
			h->pcdata(theOutputBuffer, 0, theSize);
			theSize = 0;
			break;
		default: {
			ostringstream oss;
			oss << "Can't process state " + action;
			cerr << "html_scanner: " << oss.str() << endl; }
		}
		theState = theNextState;

	}	/* end while */

	h->eof(theOutputBuffer, 0, 0);
}



void html_scanner::startCDATA()
{
	theNextState = S_CDATA;
}


}	/* namespace xqp */
