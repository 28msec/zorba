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
#include "../util/rchandle.h"

#include <iostream>
#include <string>
#include <vector>

namespace xqp {

#define ft_lowercase								  0
#define ft_uppercase								  1
#define ft_case_sensitive					    2
#define ft_case_insensitive				    3
#define ft_with_diacritics					  0
#define ft_without_diacritics			    4
#define ft_diacritics_sensitive		    8
#define ft_diacritics_insensitive	   12
#define ft_without_stemming				    0
#define ft_with_stemming						 16
#define ft_without_thesaurus          0
#define ft_default_thesaurus				 32
#define ft_defined_thesaurus				 64
#define ft_without_stopwords				  0
#define ft_default_stopwords				128
#define ft_defined_stopwords				256
#define ft_with_wildcards					  512


struct ft_thesaurus_id
{
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

	std::string uri;
	thesaurus_rel rel;
	uint32_t level;

};


class ft_option_value : public ft_value
{
protected:
	uint16_t matchopt;
	std::vector<ft_thesaurus_id> tid_v;
	std::string stopword_uri;
	std::vector<std::string> stopword_v;
	std::string stopword_exclusion_uri;
	std::vector<std::string> stopword_exclusion_v;
	std::string language;
	float weight;
	
public:
	ft_option_value() {}
	~ft_option_value() {}

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

	std::vector<ft_thesaurus_id>::const_iterator get_thesauri_begin() const
		{ return tid_v.begin(); }
	std::vector<ft_thesaurus_id>::const_iterator get_thesauri_end() const
		{ return tid_v.end(); }
	std::vector<std::string>::const_iterator get_stopword_exclusion_begin() const
		{ return stopword_exclusion_v.begin(); }
	std::vector<std::string>::const_iterator get_stopword_exclusion_end() const
		{ return stopword_exclusion_v.end(); }

	void set_matchopt(uint16_t v) { matchopt = v; }
	void add_thesaurus_id(ft_thesaurus_id const& v)
		{ tid_v.push_back(v); }
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

public:
	friend std::ostream& operator<<(std::ostream& os, ft_option_value const&);

};


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

