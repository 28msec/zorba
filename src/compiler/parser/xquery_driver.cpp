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
#include "compiler/parser/xquery_parser.hpp"
#include "compiler/parser/location.hh"
#include "errors/Error.h"

using namespace std;
namespace xqp {


xquery_driver::xquery_driver(
  uint32_t initial_heapsize)
  :
	symtab(initial_heapsize),
  expr_p (NULL),
	rename_bit(false),
	ftcontains_bit(false)
{
}

xquery_driver::~xquery_driver()
{
}

void xquery_driver::error(
	yy::location const& l,
	string const& m)
{
  ZORBA_ERROR_ALERT (error_messages::XPST0003, &l, false, m);
}
     
void xquery_driver::error(
	string const& m)
{
  ZORBA_ERROR_ALERT (error_messages::XPST0003, NULL, false, m); 
}

}	/* namespace xqp */
