/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: ft_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_FTVALUES_H
#define XQP_FTVALUES_H

#include "values.h"
#include "ft_options.h"
#include "../util/rchandle.h"

#include <iostream>
#include <string>
#include <vector>

namespace xqp {

class ft_or_value : public ft_value
{
protected:
	std::vector<rchandle<ft_value> > and_hv;

public:
	ft_or_value() {}
	~ft_or_value() {}

public:
	void add(rchandle<ft_value> ft_h) { and_hv.push_back(ft_h); }
	uint32_t count() const { return and_hv.size(); }
	std::vector<rchandle<ft_value> >::const_iterator begin()
		{ return and_hv.begin(); }
	std::vector<rchandle<ft_value> >::const_iterator end()
		{ return and_hv.end(); }

public:
	friend std::ostream& operator<<(std::ostream& os, ft_or_value const&);

};


class ft_and_value : public ft_value
{
protected:
	std::vector<rchandle<ft_value> > mildnot_hv;

public:
	ft_and_value() {}
	~ft_and_value() {}

public:
	void add(rchandle<ft_value> ft_h) { mildnot_hv.push_back(ft_h); }
	uint32_t count() const { return mildnot_hv.size(); }
	std::vector<rchandle<ft_value> >::const_iterator begin()
		{ return mildnot_hv.begin(); }
	std::vector<rchandle<ft_value> >::const_iterator end()
		{ return mildnot_hv.end(); }

public:
	friend std::ostream& operator<<(std::ostream& os, ft_and_value const&);

};


class ft_mildnot_value : public ft_value
{
protected:
	rchandle<ft_value> posval_h;
	std::vector<rchandle<ft_value> > negval_hv;

public:
	ft_mildnot_value(
		rchandle<ft_value> pos_h,
		rchandle<ft_value> neg_h);
	ft_mildnot_value() {}
	~ft_mildnot_value() {}

public:
	void add_negval(rchandle<ft_value> ft_h) { negval_hv.push_back(ft_h); }
	uint32_t negval_count() const { return negval_hv.size(); }
	std::vector<rchandle<ft_value> >::const_iterator negval_begin()
		{ return negval_hv.begin(); }
	std::vector<rchandle<ft_value> >::const_iterator negval_end()
		{ return negval_hv.end(); }

public:
	friend std::ostream& operator<<(std::ostream& os, ft_mildnot_value const&);

};


class ft_unarynot_value : public ft_value
{
protected:
	rchandle<ft_value> qphrase_h;

public:
	ft_unarynot_value(rchandle<ft_value> ft_h) : qphrase_h(ft_h) {}
	ft_unarynot_value() {}
	~ft_unarynot_value() {}

public:
	rchandle<ft_value> get_qphrase() const { return qphrase_h; };
	
public:
	friend std::ostream& operator<<(std::ostream& os, ft_unarynot_value const&);

};


// qphrase = 'qualified phrase'
class ft_qphrase_value : public ft_value
{
public:
	enum ft_anyall_option {
		ft_any,
		ft_any_word,
		ft_all,
		ft_all_words,
		ft_phrase
	};

protected:
	std::vector<std::string> word_v;
	enum ft_anyall_option opt;

public:
	ft_qphrase_value() {}
	~ft_qphrase_value() {}

public:
	enum ft_anyall_option get_opt() const { return opt; }
	void add(std::string const& s) { word_v.push_back(s); }
	uint32_t count() const { return word_v.size(); }
	std::vector<std::string>::const_iterator begin()
		{ return word_v.begin(); }
	std::vector<std::string>::const_iterator end()
		{ return word_v.end(); }

public:
	friend std::ostream& operator<<(std::ostream& os, ft_qphrase_value const&);

};



} /* namespace xqp */
#endif /* XQP_FTVALUES_H */

