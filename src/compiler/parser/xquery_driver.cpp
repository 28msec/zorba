/**
 * @file xquery_driver.cpp
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

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_parser.tab.h"

using namespace std;
namespace xqp {

xquery_driver::xquery_driver(
  ostream& _os,
  uint32_t initial_heapsize)
:
	trace_scanning(false),
	trace_parsing(false),
	symtab(initial_heapsize),
  os(_os),
	rename_bit(false),
	ftcontains_bit(false)
{
}

xquery_driver::~xquery_driver()
{
}
     
void xquery_driver::parse(
	string const& fname)
{
	file = fname;
	scan_begin();
	yy::xquery_parser parser(*this);
	parser.set_debug_level(trace_parsing);
	parser.parse();
	scan_end();
}
     
void xquery_driver::error(
	yy::location const& l,
	string const& m)
{
	cerr << l << ": " << m << endl;
}
     
void xquery_driver::error(
	string const& m)
{
	cerr << m << endl;
}

}	/* namespace xqp */
