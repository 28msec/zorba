/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_typecodes.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#ifndef XQP_XML_TYPECODES_H
#define XQP_XML_TYPECODES_H

namespace xqp {

#define     bool_code		0x00
#define    int16_code		0x10
#define   uint16_code		0x20
#define    int32_code		0x30
#define   uint32_code		0x40
#define    int64_code		0x50
#define   uint64_code		0x60
#define  float32_code		0x70
#define double64_code		0x80
#define   qname0_code		0x90
#define   qname1_code		0xa0
#define   pcdata_code		0xc0

}	/* namespace xqp */
#endif	/* XQP_XML_TYPECODES_H */
