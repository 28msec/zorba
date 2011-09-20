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

#ifndef ZORBA_NAIVE_FT_TOKEN_ITERATOR_H
#define ZORBA_NAIVE_FT_TOKEN_ITERATOR_H

#include "store/api/ft_token_iterator.h"
#include "ft_token_store.h"

namespace zorba {

/**
 * A %NaiveFTTokenIterator is-an FTTokenIterator for the naive store.
 */
class ZORBA_DLL_PUBLIC NaiveFTTokenIterator : public FTTokenIterator {
public:
  typedef FTTokenStore::container_type container_type;

  NaiveFTTokenIterator( container_type const&, index_t begin, index_t end );
  NaiveFTTokenIterator( container_type const* );
  ~NaiveFTTokenIterator();

  index_t begin() const;
  index_t end() const;
  bool hasNext() const;
  FTToken const* next();
  Mark_t pos() const;
  void pos( Mark_t const& );
  void reset();

private:
  struct LocalMark : Mark {
    LocalMark( index_t pos ) : pos_( pos ) { }
    index_t const pos_;
  };

  container_type const *tokens_;
  index_t const begin_, end_;
  index_t pos_;
  bool const must_delete_;

  void init();
};

} // namespace zorba
#endif  /* ZORBA_NAIVE_FT_TOKEN_ITERATOR_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
