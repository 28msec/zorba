/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
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

#include "character_entities.h"
#include <string>
#include "../util/hashmap.h"

namespace xqp {

//tokens
#define T_EOF								 0		// 	eof
#define T_WS								 1		// 	whitespace
#define T_DEF								 2		//	default
#define T_CR								 3		// 	cr  = 0xa
#define T_LF								 4		// 	lf  = 0xd
#define T_LT								 5		//	'<' = 0x3c
#define T_GT								 6		//	'>' = 0x3e
#define T_SL								 7		//	'/' 
#define T_EQ								 8		//	'=' 
#define T_DASH							 9		//	'-' 
#define T_AMP								10		//	'&' 
#define T_APOS							11		//	''' 
#define T_QUOT							12		//	'"' 
#define T_BANG							13		//	'!' 
#define T_HOOK							14		//	'?' 
#define T_PER 							15		//	'%' 
#define T_C									16		//	'C' 
#define T_D									17		//	'D' 
#define T_A									18		//	'A' 
#define T_T									19		//	'T' 
#define T_LBRA							20		//	'[' 
#define T_RBRA							21		//	']' 

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
	virtual unsigned short getEntity();

};


}	/* namespace xqp */
#endif	/* XQP_SCANHANDLER_H */
