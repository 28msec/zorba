/*
 * Copyright 2006-2011 The FLWOR Foundation.
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

#include "json_visitor.h"
#include "json_items.h"

namespace zorba
{

namespace simplestore
{

namespace json
{


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::begin( const JSONObject* o )
{
  os << "{";
  eol();
  inc();
}

/******************************************************************************

*******************************************************************************/

void
JSONPrinterVisitor::end( const JSONObject* o )
{
  dec();
  indent();
  os << "}";
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::begin( const JSONArray* a )
{
  os << "[";
  eol();
  inc();
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::end( const JSONArray* a )
{
  eol();
  dec();
  os << "]";
  eol();
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::begin( const JSONObjectPair* p )
{
  indent();
  visit(p->getName());
  os << " : ";
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::end( const JSONObjectPair* p )
{
  eol();
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::begin( const JSONArrayPair* p )
{
  indent();
  visit(p->getValue());
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::end( const JSONArrayPair* p )
{
  JSONArray* lArray = dynamic_cast<JSONArray*>(p->getContainer());
  if (lArray->size() != p->getPosition()->getIntegerValue())
  {
    os << ", ";
    eol();
  }
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::visit( const zorba::store::Item* i )
{
  if (dynamic_cast<const StringItem*>(i))
  {
    // todo escaping
    os << "\"" << i->getStringValue() << "\"";
  }
  else if (dynamic_cast<const BooleanItem*>(i))
  {
    os << i->getStringValue();
  }
}

} // namespace json
} // namespace simplestore
} // namespace zorba

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */


