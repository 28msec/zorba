/**
 * @file source.h
 * @author Paul Pedersen
 * @copyright 2006-2007 FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef XQP_SOURCE_H
#define XQP_SOURCE_H

#include "util/rchandle.h"

#ifdef WIN32
	#include "win32/compatib_defs.h"
#endif

#include <vector>
#include <iostream>

namespace xqp {

class zorba;

class source : public rcobject
{
protected:
	std::string uri;

public:
	source(const std::string& _uri) : uri(_uri) {}
	virtual ~source() {}

public:
	std::string get_uri() const { return uri; }
	void set_uri(std::string _uri) {uri = _uri; }

	virtual std::istream* get_input(zorba*) = 0;

};


class source_list : public rcobject
{
protected:
	std::vector<rchandle<source> > src_v;

public:
	source_list() {}
	~source_list() {}

public:
	rchandle<source> operator[](int i) const { return src_v[i]; }
	void push_back(rchandle<source> s_h) { src_v.push_back(s_h); }
	uint32_t size() const { return src_v.size(); }

};





} /* namespace xqp */
#endif /* XQP_SOURCE_H */

