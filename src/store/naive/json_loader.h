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
#ifndef ZORBA_SIMPLE_STORE_JSON_LOADER_H
#define ZORBA_SIMPLE_STORE_JSON_LOADER_H

#include "common/common.h"
#include "shared_types.h"
#include "store/api/item.h"
#include "util/json_parser.h"

namespace zorba
{

namespace simplestore
{

namespace json
{

class JSONLoader
{
public:
  typedef zorba::json::location location;

  JSONLoader( std::istream& s,
              location* relative_error_loc,
              bool strip_array = false );

  ~JSONLoader();

  store::Item_t
  next( );

protected:
  std::istream  & in;
  location      * theRelativeLoc;
  bool          strip_array_;

private:
  template<typename T>
  static T*
  cast(const JSONItem_t&);

  void
  addValue(std::vector<store::Item_t>&, const store::Item_t&);

}; /* class JSONLoader */


} /* namespace json */

} /* namespace simplestore */

} /* namespace zorba */

#endif /* ZORBA_SIMPLE_STORE_JSON_LOADER_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
