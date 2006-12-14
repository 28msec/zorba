/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_QNAME_H
#define XQP_QNAME_H

#include <ostream>
#include <string>
#include "../util/rchandle.h"

namespace xqp {

class QName : public rcobject
{
public:
	enum qname_type_t {
		qn_attr,	// attribute name
		qn_elem,	// element name
		qn_type,	// type name
		qn_func,	// function name
		qn_optn,	// prolog option name
		qn_prag		// pragma label
	};

protected:
	std::string prefix;
	std::string name;

public:
	QName(
		enum qname_type_t _type,
		std::string const& _prefix,
		std::string const& _name);

	QName(
		enum qname_type_t _type,
		std::string const& _name);

	QName(
		enum qname_type_t _type);

	~QName();

public:
	enum qname_type_t type;
	std::string get_prefix() const { return prefix; }
	std::string get_name() const { return name; }

public:
	std::ostream& put(std::ostream& s) const;

};

}	/* namespace xqp*/
#endif	/* XQP_QNAME_H */
