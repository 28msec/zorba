/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: value.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_VALUE_H
#define XQP_VALUE_H

#include <string>
#include <vector>
#include <../functions/function_impl.h"

namespace xqp {

/*______________________________________________________________________
|  
|	Base class for the value hierarchy
|_______________________________________________________________________*/

class object	: public rchandle
{
public:
	object() {}
	~object() {}

};



/*______________________________________________________________________
|  
|	'primitive_update' encapsulates an xquery update action.
|	Refer to "XQuery Update Facility'
|	[http://http://www.w3.org/TR/xqupdate/]
|_______________________________________________________________________*/
class primitive_update : public object
{
public:
	primitive_update() {}
	~primitive_update() {}

};


/*______________________________________________________________________
|  
|	'exception' encapsulates an xquery exception.
|_______________________________________________________________________*/

class xqp_exception : public object
{
public:
	xqp_exception() {}
	~xqp_exception() {}

};


/*______________________________________________________________________
|  
|	'ft_selection' encapsulates an xquery full-text search constraint.
|	Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|	[http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

#define lowercase								    0
#define uppercase								    1
#define case_sensitive					    2
#define case_insensitive				    3

#define with_diacritics					    0
#define without_diacritics			    4
#define diacritics_sensitive		    8
#define diacritics_insensitive	   12

#define without_stemming				    0
#define with_stemming						   16

#define without_thesaurus           0
#define default_thesaurus				   32
#define defined_thesaurus				   64

#define without_stopwords				    0
#define default_stopwords				  128
#define defined_stopwords				  256

#define with_wildcards					  512


class thesaurus_id
{
public:
	enum thesaurus_rel {
		use,			// preferred term
		uf,				// non-preferred use
		bt,				// broader term
		nt,				// narrower term
		btg,			// broader term generic
		ntg,			// narrower term generic
		btp,			// broader term partative
		ntp,			// narrower term partative
		tt,				// top terms
		rt				// related term
	};

public:
	std::string uri;
	thesaurus_rel rel;
	uint32_t level;

};


class ft_selection : public object
{
protected:
	uint16_t matchopt;
	std::vector<thesaurus_id> thesaurus_id_v;
	std::string stopword_uri;
	std::vector<std::string> stopword_v;
	std::string stopword_exclusion_uri;
	std::vector<std::string> stopword_exclusion_v;
	std::string language;
	float weight;
	
public:
	ft_selection() {}
	~ft_selection() {}

public:
	uint16_t get_matchopt() const
		{ return matchopt; }
	std::string get_stopword_uri() const
		{ return stopword_uri; }
	std::vector<std::string> get_stopword_v() const
		{ return stopword_v; }
	std::string get_stopword_exclusion_uri() const
		{ return stopword_exclusion_uri; }
	std::string get_language() const
		{ return language; }
	float get_weight() const
		{ return weight; }

	std::vector<thesaurus_id>::const_iterator get_thesauri_begin() const
		{ return thesaurus_id_v.begin(); }
	std::vector<thesaurus_id>::const_iterator get_thesauri_end() const
		{ return thesaurus_id_v.end(); }
	std::vector<std::string>::const_iterator get_stopword_exclusion_begin() const
		{ return stopword_exclusion_v.begin(); }
	std::vector<std::string>::const_iterator get_stopword_exclusion_end() const
		{ return stopword_exclusion_v.end(); }

	void set_matchopt(uint16_t v) { matchopt = v; }
	void add_thesaurus_id(thesaurus_id const& v)
		{ thesaurus_id_v.push_back(v); }
	void set_stopword_uri(std::string const& v)
		{ stopword_uri = v; }
	void add_stopword(std::string const& v)
		{ stopword_v.push_back(v); }
	void set_language(std::string const& v)
		{ language = v; }
	void set_weight(float v)
		{ weight = v; }
	void set_stopword_exclusion_uri(std::string v)
		{ stopword_exclusion_uri = v; }
	void add_stopword_exclusion(std::string const& v)
		{ stopword_exclusion_v.push_back(v); }

};


/*______________________________________________________________________
|  
|	'function' encapsulates an xquery function object
|_______________________________________________________________________*/

class function : public object
{
protected:
	function_impl const* func_p;

public:
	function(function_impl const* _func_p) : func_p(_func_p) {}
	function() {}
	~function() {}

public:
	function_impl const* get_func() const { return func_p; }

};


/*______________________________________________________________________
|  
|	'value' encapsulates an xquery 'item()' value
|_______________________________________________________________________*/

class value	: public object
{
public:
	value() {}
	~value() {}

public:
	

};


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates an xquery 'xs_anyAtomicType' value
|_______________________________________________________________________*/

class atomic_value : public value;
{
public:
	atomic_value() {}
	~atomic_value() {}

};


} /* namespace xqp */
#endif /* XQP_VALUE_H */

