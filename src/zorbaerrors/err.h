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

#ifndef ZORBA_ERR_H
#define ZORBA_ERR_H

#include <zorba/err.h>
#include "store/api/item.h"
#include "compiler/parser/query_loc.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

namespace err {

/**
 * Given a store::Item_t that represents a QName, creates an instance of
 * QNameType having the same QName.
 *
 * @tparam QNameType The type of QName to create.
 * @param qname The QName item.
 * @return Returns said QNameType.
 */
template<class QNameType> inline
QNameType to_QName( store::Item_t const &qname ) {
  return QNameType(
    qname->getNamespace().c_str(),
    qname->getPrefix().c_str(),
    qname->getLocalName().c_str()
  );
}

} // namespace err

///////////////////////////////////////////////////////////////////////////////

namespace internal {
namespace err {

inline location make_location( QueryLoc const &loc ) {
  return location( loc.getFilename(), loc.getLineno(), loc.getColumnBegin() );
}

inline location make_location( QueryLoc const *loc ) {
  return loc ? make_location( *loc ) : location::empty;
}

} // namespace err
} // namespace internal

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_ERR_H */
/* vim:set et sw=2 ts=2: */
