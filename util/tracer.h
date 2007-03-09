/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: tracer.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_TRACER_H
#define XQP_TRACER_H

namespace xqp {

#define TRACE __FILE__<<':'<<__LINE__<<"::"<<__FUNCTION__
#define LOCATION	(__oss.str(""), \
										__oss<<__FILE__<<":"<<__LINE__<<"::"<<__FUNCTION__, \
										__oss.str())


} /* namespace xqp */
#endif /* XQP_TRACER_H */

