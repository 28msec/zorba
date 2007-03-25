/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: abstract_qname.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_ABSTRACT_QNAME_H
#define XQP_ABSTRACT_QNAME_H

#include "abstract_values.h"
#include "../context/common.h"
#include "../runtime/abstract_iterator.h"
#include <string>

namespace xqp {

class xs_anyURIValue;

class abstract_qname : public abstract_value
{
public:
	std::string prefix() const;
	std::string localname() const;
	xs_anyURIValue* uri() const;
	iterator_t atomized_value() const;
	std::string string_value() const;

};


} /* namespace xqp */
#endif /* XQP_ABSTRACT_QNAME_H */

