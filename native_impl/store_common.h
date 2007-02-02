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

#define STRING_CODE 						1
#define TEXT_CODE   						2
#define QNAME_CODE							3
#define ATTR_CODE								4
#define ELEM_CODE								5
#define DOC_CODE 								6

#define ERR_BAD_CODE						-1
#define ERR_OVERRUN							-2
#define ERR_NODEID_NOT_FOUND		-3


} /* namespace xqp */
#endif /* XQP_STORE_COMMON_H */

