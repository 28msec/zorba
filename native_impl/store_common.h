/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: store_common.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_STORE_COMMON_H
#define XQP_STORE_COMMON_H

namespace xqp {

#define STRING_CODE 						(uint32_t)1
#define TEXT_CODE   						(uint32_t)2
#define QNAME_CODE							(uint32_t)3
#define ATTR_CODE								(uint32_t)4
#define ELEM_CODE								(uint32_t)5
#define DOC_CODE 								(uint32_t)6
#define COMMENT_CODE 						(uint32_t)7
#define PI_CODE 								(uint32_t)8
#define BINARY_CODE 						(uint32_t)9

#define ERR_BAD_CODE						(uint32_t)-1
#define ERR_OVERRUN							(uint32_t)-2
#define ERR_NODEID_NOT_FOUND		(uint32_t)-3


} /* namespace xqp */
#endif /* XQP_STORE_COMMON_H */

