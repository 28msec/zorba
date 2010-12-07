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

#ifndef ZORBA_FULL_TEXT_WORDNET_SYNSET_H
#define ZORBA_FULL_TEXT_WORDNET_SYNSET_H

#include <vector>

#include "wn_types.h"

namespace zorba {
namespace wordnet {

/**
 * A %synset is a WordNet synonym set.
 */
class synset {
public:

  /**
   * A %ptr is a pointer from one synset to another.
   */
  struct ptr {
    pointer::type type_;
    part_of_speech::type pos_;
    synset_id_t synset_id_;
    uint8_t source_;
    uint8_t target_;
  };

  typedef std::vector<lemma_id_t> lemma_id_list;
  typedef std::vector<ptr> ptr_list;

  /**
   * Constructs a %synset.
   *
   * @param p A pointer to the first byte of a binary %synset entry.
   */
  synset( char const *p );

  /**
   * Gets this %synset's part-of-speech.
   *
   * @return Returns said part-of-speech.
   */
  part_of_speech::type pos() const {
    return pos_;
  }

  /**
   * Gets this %synset's lemma IDs.
   *
   * @return Returns said lemma IDs.
   */
  lemma_id_list const& lemma_ids() const {
    return lemma_ids_;
  }

  /**
   * Gets this %synset's ptrs.
   *
   * @return Returns said ptrs.
   */
  ptr_list const& ptrs() const {
    return ptrs_;
  }

private:
  part_of_speech::type pos_;
  lemma_id_list lemma_ids_;
  ptr_list ptrs_;
};

} // namespace wordnet
} // namespace zorba

#endif /* ZORBA_FULL_TEXT_WORDNET_SYNSET_H */
/* vim:set et sw=2 ts=2: */
