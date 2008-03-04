/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: ft_options.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */


#include "ft_options.h"

using namespace std;
namespace zorba {

std::ostream& operator<<(std::ostream& os, ft_thesaurus_id const& tid)
{
	os << "ft_thesaurus_id[\n"
		 << "  uri=" << tid.uri << endl
		 << "  rel=" << tid.decode(tid.rel) << endl
		 << "  level=" << tid.level << endl
		 << "]";
	return os;
}

ostream& operator<<(ostream & os, ft_options const& opt) 
{
	os << "ft_options["
		 << "\n  matchopt=" << opt.matchopt;
	os << "\n  thesauri=";
	vector<ft_thesaurus_id>::const_iterator it1 = opt.tid_v.begin();
	for (; it1!=opt.tid_v.end(); ++it1) {
		os << *it1 << endl;
	}
	os << "\n  stopword_uri=" << opt.stopword_uri;
	os << "\n  stopword vector=";
	vector<string>::const_iterator it2 = opt.stopword_v.begin();
	for (; it2!=opt.stopword_v.end(); ++it2) {
		os << *it2 << endl;
	}
	os << "\n  stopword_exclusion_uri=" << opt.stopword_exclusion_uri;
	os << "\n  stopword exclusion vector=";
	vector<string>::const_iterator it3 = opt.stopword_exclusion_v.begin();
	for (; it3!=opt.stopword_exclusion_v.end(); ++it3) {
		os << *it3 << endl;
	}
	os << "\n  language=" << opt.language;
	os << "\n  weight=" << opt.weight;
	os << "]\n";
	return os;
}

} /* namespace zorba */

