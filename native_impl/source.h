/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: source.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_SOURCE_H
#define XQP_SOURCE_H

#include <vector>
#include "../util/rchandle.h"

namespace xqp {

class source : public rcobject
{
protected:
	std::string uri;

public:
	virtual std::string get_uri() const { return uri; }
	virtual void set_uri(std::string _uri) {uri = _uri; }

};


class source_list : public rcobject
{
protected:
	std::vector<rchandle<source> > src_v;

public:
	source_list() {}
	~source_list() {}

public:
	rchandle<source> operator[](int i) const;
	void push_back(rchandle<source>);
	uint32_t size() const;

};


} /* namespace xqp */
#endif /* XQP_SOURCE_H */

