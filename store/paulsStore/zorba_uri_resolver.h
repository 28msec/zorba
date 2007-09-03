/**
 * @file zorba_uri_resolver.h
 * @author Paul Pedersen
 * @copyright 2006-2007 FLWOR Foundation.
 *
 * =======================================================================
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
 * =======================================================================
 *
 */

#ifndef XQP_ZORBA_URI_RESOLVER_H
#define XQP_ZORBA_URI_RESOLVER_H

#include "source.h"
#include "uri_resolver.h"
#include "runtime/zorba.h"
#include "util/rchandle.h"
#include "util/URI.h"
#include <iostream>
#include <string>

namespace xqp {


class zorba_uri_resolver : public uri_resolver
{
protected:
	class file_source : public source
	{
	public:
		file_source(const std::string& _path) : source(_path) {}
		~file_source() {}

		std::istream* get_input();
	};

public:
	zorba_uri_resolver() {}
	~zorba_uri_resolver() {}

public:
	rchandle<source> resolve(
		const std::string& base,
		const std::string& uri);

	rchandle<source> resolve(
		const std::string& uri);

	rchandle<source> resolve(
		const URI& base,
		const URI& uri);

	rchandle<source> resolve(
		const URI& uri);

};


} /* namespace xqp */
#endif /* XQP_ZORBA_URI_RESOLVER_H */

