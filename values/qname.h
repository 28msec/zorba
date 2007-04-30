/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_QNAME_H
#define XQP_QNAME_H

#include "values.h"
#include "../context/common.h"
#include <string>

namespace xqp {

class xs_anyURIValue;
class zorba;

class qname : public atomic_value
{
public:
	std::string prefix() const;
	std::string localname() const;
	xs_anyURIValue* uri() const;

public:
	iterator_t atomized_value(zorba*) const;
	iterator_t string_value(zorba*) const;

public:
	qnamekey_t qnamekey() const;
  std::ostream& put(std::ostream& os);

};


} /* namespace xqp */
#endif /* XQP_QNAME_H */

