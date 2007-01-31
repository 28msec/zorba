/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: ft_options.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_FTOPTIONS_H
#define XQP_FTOPTIONS_H

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

class ft_thesaurus_id
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

	std::string uri;
	thesaurus_rel rel;
	uint32_t level;

	std::string decode(enum thesaurus_rel rel) const
	{
		switch (rel) {
		case use: return "preferred term";
		case uf: return "non-preferred use";
		case bt: return "broader term";
		case nt: return "narrower term";
		case btg: return "broader term generic";
		case ntg: return "narrower term generic";
		case btp: return "broader term partative";
		case ntp: return "narrower term partative";
		case tt: return "top terms";
		case rt: return "related term";
		default: return "??";
		}
	}

	friend std::ostream& operator<<(std::ostream&, ft_thesaurus_id const&);

};


class ft_options : public rcobject
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
	ft_options() {}
	~ft_options() {}

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

	friend std::ostream& operator<<(std::ostream & os, ft_options const&); 

};



} /* namespace xqp */
#endif /* XQP_FTOPTIONS_H */

