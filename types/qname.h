/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_QNAME_H
#define XQP_QNAME_H

#include <string>
#include "../util/rchandle.h"

namespace xqp {

class QName : public rcobject
{
protected:
	std::string prefix;
	std::string name;

public:
	QName(
		std::string const& _prefix,
		std::string const& _name)
	:
		prefix(_prefix),
		name(_name)
	{ }

	QName(
		std::string const& _name)
	:
		prefix(""),
		name(_name)
	{ }

	QName()
	:
		prefix(""),
		name("")
	{ }

	~QName() {}

public:
	std::string get_prefix() const { return prefix; }
	std::string get_name() const { return name; }

};

}	/* namespace xqp*/
#endif	/* XQP_QNAME_H */
