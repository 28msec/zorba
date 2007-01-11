/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: ft_values_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "ft_values.h"
#include "../util/rchandle.h"
#include <iostream>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	rchandle<ft_qphrase_value> p1_h = new ft_phrase_value();
	pv.add("to");
	pv.add("be");
	pv.set_opt(ft_qphrase_value::ft_all);

	rchandle<ft_qphrase_value> p2_h = new ft_phrase_value();
	pv.add("or");
	pv.set_opt(ft_qphrase_value::ft_all);

	rchandle<ft_qphrase_value> p3_h = new ft_phrase_value();
	pv.add("not");
	pv.add("to");
	pv.add("be");
	pv.set_opt(ft_qphrase_value::ft_all);

	rchandle<ft_unarynot_value> unot_h =
		new ft_unarynot_value(&*p3_h);

	rchandle<ft_mildnot_value> mnot_h =
		new ft_mildnot_value(&*p1_h, &*p2_h);

	rchandle<ft_and_value> and_h =
		new ft_and_value(&*mnot_h, &*unot_h);

	rchandle<ft_or_value> or_h =
		new ft_or_value(&*mnot_h, &*unot_h);

	ft_option_value opt;

	uint32_t optval = ft_lowercase
									| ft_case_sensitive
									| ft_with_diacritics
									| ft_without_stemming;

	theasurus_id tid = { "mythesaurus URI", ft_thesaurus_id::use, 2 };

	opt.set_matchopt(optval)
	opt.add_thesaurus_id(tid);
	opt.set_stopword_uri("my stopword URI");
	opt.set_language("en");
	opt.set_weight(0.5);
	opt.set_stopword_exclusion_uri("my stopword exclusion URI");

	cout << "ft_or_value = " << *or_h << endl;
	cout << "ft_and_value = " << *and_h << endl;
	cout << "ft_option_value = " << opt << endl;
}

