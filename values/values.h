/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_VALUES_H
#define XQP_VALUES_H

#include "../datamodel/qname.h"
#include "../datamodel/types.h"
#include "../util/rchandle.h"

#include <string>
#include <vector>
 
namespace xqp {

class context;

/*______________________________________________________________________
|  
|	Base class for the value hierarchy
|_______________________________________________________________________*/

class object : public rcobject
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

class xquery_exception : public object
{
public:
	xquery_exception() {}
	~xquery_exception() {}

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
|	'value' - top of the XQuery value hierarchy
|
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class value	: public object
{
public:
	value() {}
	~value() {}

public:
  virtual void put(std::ostream&, context const&) const;
  virtual void describe(std::ostream&,  context const&) const;

	virtual bool is_sequence() const;
	virtual bool is_empty() const;

};


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class item : public value
{
public:
	item() {}
	~item() {}

public:
  virtual void put(std::ostream&, context const&) const;
  virtual void describe(std::ostream&,  context const&) const;

	virtual bool is_node() const;
	virtual bool is_atomic() const;

};


/*______________________________________________________________________
|  
|	'item_iterator' - coin of the realm in XQuery: all
|	expressions return some form of item_iterator, often
|	a singleton iterator, sometimes an empty sequence.
|
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class item_iterator : public value
{
protected:
  context const* ctx_p;
  
public:
	// aquire resources
	virtual void open();

	// release resources
	virtual void close();

	// return handle to next value (or NULL)
	virtual rchandle<item> next();

	// return true <=> iterator has no more items
	virtual bool done();

	// rewind the iterator, equivalent to {close();open()}
	virtual void rewind();

};


class empty_sequence : public item_iterator
{
public:
	empty_sequence() {}
	~empty_sequence() {}
	
public:
	void open() {}
	rchandle<item> next() { return NULL; }
	bool done() { return true; }
	void close() {}
	
};


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates value of primitive or derived types
|_______________________________________________________________________*/

class atomic_value : public item
{
protected:
	// declared or annonymous type
	qnameid type_annotation;

public:
	atomic_value() {}
	~atomic_value() {}

public:
  virtual void put(std::ostream&, context const&) const;
  virtual void describe(std::ostream&, context const&) const;
	virtual enum type::typecode get_typecode() const;

};


/*______________________________________________________________________
|  
|	'node' values (defined in 'nodes.h')
|_______________________________________________________________________*/


/*______________________________________________________________________
|  
|	'function' encapsulates an xquery function object
|_______________________________________________________________________*/

struct signature : public rcobject
{
	QName fname;
	std::vector<item_type> arg_v;
	item_type ret_type;
	signature(QName const& q) : fname(q) {}
};


class function_impl : public rcobject
{
protected:
  rchandle<item_iterator> val; 

};


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


} /* namespace xqp */
#endif /* XQP_VALUES_H */

