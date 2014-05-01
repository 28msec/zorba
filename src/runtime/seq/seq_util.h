/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

#ifndef ZORBA_SEQ_UTIL_H
#define ZORBA_SEQ_UTIL_H

#include <functional>

#include "runtime/booleans/BooleanImpl.h"
#include "util/hash/hash.h"
#include "util/unordered_set.h"
#include "zorbautils/specializations.h"

namespace zorba {

class TypeManager;
class XQPCollator;

///////////////////////////////////////////////////////////////////////////////

struct Item_value_equal : std::binary_function<store::Item*,store::Item*,bool> {
  Item_value_equal( TypeManager const *tm, long tz, XQPCollator *coll,
                    QueryLoc const &loc ) :
    tm_( tm ),
    tz_( tz ),
    coll_( coll ),
    loc_( loc )
  {
  }

  bool operator()( store::Item *i, store::Item *j ) const {
    store::Item_t it( i ), jt( j );
    return CompareIterator::valueEqual( loc_, it, jt, tm_, tz_, coll_, true );
  }

private:
  TypeManager const *const tm_;
  long const tz_;
  XQPCollator *const coll_;
  QueryLoc const loc_;
};

typedef std::unordered_set<store::Item*,ztd::hash<store::Item*>,Item_value_equal
                          > Item_set_type;

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_SEQ_UTIL_H */
/* vim:set et sw=2 ts=2: */
