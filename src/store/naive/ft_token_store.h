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

#ifndef ZORBA_FT_TOKEN_STORE_H
#define ZORBA_FT_TOKEN_STORE_H

#include <map>
#include <utility>                      /* for pair */
#include <vector>

#include "util/cxx_util.h"
#include "zorbatypes/ft_token.h"

namespace zorba { 

/**
 * A %FTTokenStore stores all the full-text tokens for an XML document.
 */
class FTTokenStore {
public:
  typedef std::vector<FTToken> container_type;
  typedef container_type::size_type size_type;

  typedef void const* key_type;
  typedef std::pair<size_type,size_type> range_type;
private:
  typedef std::map<key_type,range_type> doc_map_type;
  typedef std::map<key_type,container_type> att_map_type;
public:

  ////////// document tokens //////////////////////////////////////////////////

  /**
   * Gets all the XML document's tokens.
   *
   * @return Returns said tokens.
   */
  container_type& getDocumentTokens() {
    return doc_tokens_;
  }

  /**
   * Gets all the XML document's tokens.
   *
   * @return Returns said tokens.
   */
  container_type const& getDocumentTokens() const {
    return doc_tokens_;
  }

  /**
   * Gets the [begin,end) range of document tokens for the given key.
   *
   * @param key The key to get the range for.
   * @return Returns said range.
   */
  range_type const& getRange( key_type key ) const {
    doc_map_type::const_iterator const i = doc_map_.find( key );
    return i != doc_map_.end() ? i->second : empty_range();
  }

  /**
   * Associates the token range [begin,end) with the given key.
   *
   * @param key The key to associate the token range with.
   * @param begin The beginning index of the range.
   * @param end One past the ending index of the range.
   */
  void putRange( key_type key, size_type begin, size_type end ) {
    doc_map_[ key ] = std::make_pair( begin, end );
  }

  ////////// attribute tokens /////////////////////////////////////////////////

  /**
   * Gets the attribute tokens for the given key.
   *
   * @param key The key to get the tokens for.
   * @return Returns said tokens or \c nullptr if \a key has no associated
   * tokens.
   */
  container_type const* getAttr( key_type key ) const {
    att_map_type::const_iterator const i = att_map_.find( key );
    return i != att_map_.end() ? &i->second : nullptr;
  }

  /**
   * Stores the given tokens associated with the given key.
   *
   * @param key The key to associate the tokens with.
   * @param att_tokens The tokens to store.
   */
  void putAttr( key_type key, container_type &att_tokens ) {
    att_map_[ key ].swap( att_tokens );
  }

  ////////// miscellaneous ////////////////////////////////////////////////////

  /**
   * Removes all tokens.
   */
  void clear() {
    doc_tokens_.clear();
    doc_map_.clear();
    att_map_.clear();
  }

  /////////////////////////////////////////////////////////////////////////////

private:
  static range_type const& empty_range();

  container_type doc_tokens_;
  doc_map_type doc_map_;
  att_map_type att_map_;
};

} // namespace zorba

#endif /* ZORBA_FT_TOKEN_STORE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
