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

#ifndef XQP_SEQUENCE_TYPE_MGR_H
#define XQP_SEQUENCE_TYPE_MGR_H

#include "util/hashmap.h"
#include "types/sequence_type.h"

namespace xqp {

class QNameItem;
class xqpString;

/*******************************************************************************

  SequenceTypeManager is used to map type names (represented as qnames) to type
  codes.
  
********************************************************************************/
class SequenceTypeManager : public rcobject
{
private:
  hashmap<TypeCode> theQNameMap;

public:
  SequenceTypeManager();

  void addQName(const xqpString& uri, const xqpString& name, TypeCode code);

  TypeCode getTypecode(const QNameItem* qname) const;
};

} // namespace xqp

#endif // XQP_SEQUENCE_TYPE_MGR_H
