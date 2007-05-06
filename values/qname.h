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

class qname : virtual public atomic_value
{
public:
	virtual std::string prefix() const = 0;
	virtual std::string localname() const = 0;
	virtual std::string uri() const = 0;

public:
	virtual iterator_t atomized_value(zorba*) const = 0;
	virtual iterator_t string_value(zorba*) const = 0;

public:
	virtual qnamekey_t qnamekey() const = 0;
  virtual std::ostream& put(zorba*,std::ostream& os) const = 0;

};


} /* namespace xqp */
#endif /* XQP_QNAME_H */

