/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author Markos Zaharioudakis
 * @file runtime/path_iterators.h
 *
 */


#include "util/utf8/xqpString.h"
#include "types/sequence_type_mgr.h"
#include "store/naive/atomic_items.h"


namespace xqp {


SequenceTypeManager::SequenceTypeManager()
{
  const xqp_string xschemaURI = "http://www.w3.org/2001/XMLSchema";

  addQName(xschemaURI, "anyType", xs_anyType);
  addQName(xschemaURI, "untypedAtomic", xs_untypedAtomicValue);

  addQName(xschemaURI, "dateTime", xs_dateTime);
  addQName(xschemaURI, "date", xs_date);
  addQName(xschemaURI, "time", xs_time);
  addQName(xschemaURI, "duration", xs_duration);
  addQName(xschemaURI, "dayTimeDuration", xs_dayTimeDuration);
  addQName(xschemaURI, "yearMonthDuration", xs_yearMonthDuration);

  addQName(xschemaURI, "gYearMonth", xs_gYearMonth);
  addQName(xschemaURI, "gYear", xs_gYear);
  addQName(xschemaURI, "gMonthDay", xs_gMonthDay);
  addQName(xschemaURI, "gDay", xs_gDay);
  addQName(xschemaURI, "gMonth", xs_gMonth);

  addQName(xschemaURI, "double", xs_double);

  addQName(xschemaURI, "decimal", xs_decimal);
  addQName(xschemaURI, "integer", xs_integer);
  addQName(xschemaURI, "nonPositiveInteger", xs_nonPositiveInteger);
  addQName(xschemaURI, "negativeInteger", xs_negativeInteger);
  addQName(xschemaURI, "long", xs_long);
  addQName(xschemaURI, "int", xs_int);
  addQName(xschemaURI, "short", xs_short);
  addQName(xschemaURI, "byte", xs_byte);
  addQName(xschemaURI, "nonNegativeInteger", xs_nonNegativeInteger);
  addQName(xschemaURI, "unsignedLong", xs_unsignedLong);
  addQName(xschemaURI, "unsignedInt", xs_unsignedInt);
  addQName(xschemaURI, "unsignedShort", xs_unsignedShort);
  addQName(xschemaURI, "unsignedByte", xs_unsignedByte);
  addQName(xschemaURI, "positiveInteger", xs_positiveInteger);

  addQName(xschemaURI, "string", xs_string);
  addQName(xschemaURI, "normalizedString", xs_normalizedString);
  addQName(xschemaURI, "token", xs_token);
  addQName(xschemaURI, "language", xs_language);
  addQName(xschemaURI, "nmtoken", xs_nmtoken);
  addQName(xschemaURI, "name", xs_name);
  addQName(xschemaURI, "ncName", xs_ncName);
  addQName(xschemaURI, "id", xs_id);
  addQName(xschemaURI, "idref", xs_idref);
  addQName(xschemaURI, "entity", xs_entity);

  addQName(xschemaURI, "boolean", xs_boolean);

  addQName(xschemaURI, "hexBinary", xs_hexBinary);
  addQName(xschemaURI, "base64Binary", xs_base64Binary);

  addQName(xschemaURI, "anyURI", xs_anyURI);
  addQName(xschemaURI, "qname", xs_qname);
  addQName(xschemaURI, "notation", xs_notation);
}


void SequenceTypeManager::addQName(const xqpString& uri, const xqpString& name, TypeCode code)
{
  xqpString nameString = uri + ":" + name;

  theQNameMap.put(nameString, code);
}


TypeCode SequenceTypeManager::getTypecode(const QNameItem* qname) const
{
  xqpString nameString = qname->getNamespace() + ":" + qname->getLocalName();
  TypeCode code;

  if (theQNameMap.get(nameString, code))
  {
    return code;
  }
  else
  {
    ZorbaErrorAlerts::error_alert(
         error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
         error_messages::SYSTEM_ERROR,
         NULL,
         false,
         "Unknown type name");
    return xs_anyType;
  }
}


} // namespace xqp
