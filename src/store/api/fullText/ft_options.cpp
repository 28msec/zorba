/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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

