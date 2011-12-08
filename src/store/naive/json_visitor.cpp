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
  dec();
  eol();
  indent();
  os << "]";
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::begin( const JSONObjectPair* p, bool /*aLast*/ )
{
  indent();
  visit(p->getName());
  os << " : ";
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::end( const JSONObjectPair* p, bool aLast )
{
  if (!aLast)
  {
    os << ", ";
  }
  eol();
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::begin( const JSONArrayPair* p, bool /* aLast */ )
{
  indent();
  visit(p->getValue());
}


/******************************************************************************

*******************************************************************************/
void
JSONPrinterVisitor::end( const JSONArrayPair* p, bool aLast )
{
  if (!aLast)
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
  const AtomicItem* a = dynamic_cast<const AtomicItem*>(i);
  switch (a->getTypeCode())
  {
    case XS_STRING:
    case XS_NORMALIZED_STRING:
    case XS_TOKEN:
    case XS_NMTOKEN:
    case XS_LANGUAGE:
    case XS_NAME:
    case XS_NCNAME:
    case XS_ID:
    case XS_IDREF:
    case XS_ENTITY:
    case XS_ANY_URI:
    case XS_QNAME:
    case XS_NOTATION:
    case XS_DATETIME:
    case XS_DATE:
    case XS_TIME:
    case XS_GYEAR_MONTH:
    case XS_GYEAR:
    case XS_GMONTH_DAY:
    case XS_GDAY:
    case XS_GMONTH:
    case XS_DURATION:
    case XS_DT_DURATION:
    case XS_YM_DURATION:
    case XS_BASE64BINARY:
    case XS_HEXBINARY:
    case XS_UNSIGNED_BYTE:
      // todo escaping
      os << "\"" << i->getStringValue() << "\"";
      break;
    case XS_FLOAT:
    case XS_DOUBLE:
    case XS_DECIMAL:
    case XS_INTEGER:
    case XS_NON_POSITIVE_INTEGER:
    case XS_NON_NEGATIVE_INTEGER:
    case XS_NEGATIVE_INTEGER:
    case XS_POSITIVE_INTEGER:
    case XS_LONG:
    case XS_INT:
    case XS_SHORT:
    case XS_BYTE:
    case XS_UNSIGNED_LONG:
    case XS_UNSIGNED_INT:
    case XS_UNSIGNED_SHORT:
    case XS_BOOLEAN:
    default:
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


