/**
 * @file zorba_uri_resolver.cpp
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

#include "zorba_uri_resolver.h"
#include "runtime/zorba.h"
#include "util/file.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "util/URI.h"

#include <iostream>

using namespace std;
namespace xqp {

istream* zorba_uri_resolver::file_source::get_input()
{
	file f(get_uri());
	if (!f.exists()) {
		//zorp->set_error(errors::XPDY0002_DYNAMIC_CONTEXT_COMPONENT_MISSING);
		ZorbaErrorAlerts::error_alert(error_messages::XPDY0002_DYNAMIC_CONTEXT_COMPONENT_MISSING,
																	error_messages::RUNTIME_ERROR,
																	NULL,///the location is not known here
																	true///continue execution
																	);
		return NULL;
	}
	unsigned sz = (unsigned)f.get_size();
	size_t n = (sz > (1<<24) ? (1<<24) : (size_t)(sz));
	char* ibuf = new char[n+1];
	int m = 0;
	try {
		m = f.readfile(ibuf,n);
	} catch (xqp_exception& ) {
		//zorp->set_error(errors::XPDY0002_DYNAMIC_CONTEXT_COMPONENT_MISSING);
		ZorbaErrorAlerts::error_alert(error_messages::XPDY0002_DYNAMIC_CONTEXT_COMPONENT_MISSING,
																	error_messages::RUNTIME_ERROR,
																	NULL,///the location is not known here
																	true///continue execution
																	);
		delete[] ibuf;
		return NULL;
	}
	return new istringstream(string(ibuf,0,m));
}
  

rchandle<source> zorba_uri_resolver::resolve(
	const string& base0,
	const string& uri0)
{
	URI base(base0);
	URI uri(uri0);
	return resolve(base, uri);
}

rchandle<source> zorba_uri_resolver::resolve(
	const string& uri0)
{
	URI uri(uri0);
	return resolve(uri);
}

rchandle<source> zorba_uri_resolver::resolve(
	const URI& base,
	const URI& uri)
{
	string res0;
	make_absolute(base,uri,res0);
	URI res(res0);
	string scheme = res.get_scheme();
	if (scheme.length()!=0) {
		cout << "non-file schemes not supported\n";
		return NULL;
	}
	string path = res.get_path();
	return new file_source(path);
}

rchandle<source> zorba_uri_resolver::resolve(
	const URI& uri)
{
	string scheme = uri.get_hostinfo();
	string host = uri.get_hostinfo();
	if (scheme.length()!=0 || host.length()!=0) {
		cout << "non-file schemes not supported\n";
		return NULL;
	}
	string path = uri.get_path();
	return new file_source(path);
}



}	/* namespace xqp */

