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
#pragma once
#ifndef ZORBA_FULL_TEXT_WORDNET_SYNSET_H
#define ZORBA_FULL_TEXT_WORDNET_SYNSET_H

#include "decode_base128.h"
#include "encoded_list.h"
#include "wn_types.h"

namespace zorba {
namespace wordnet {

/**
 * A %synset is a WordNet synonym set.
 */
class synset {
public:
  /**
   * A %synset is constructed by parsing raw memory.  This is the pointer to
   * said memory.
   */
  typedef char const* mem_ptr_type;

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

private:
  typedef unsigned size_type;

  /**
   * A %lemma_id_decoder is-a decoder_function for decoding the lemma ID list
   * portion of a synset.
   */
  struct lemma_id_decoder : decoder_function<lemma_id_t> {
    void operator()( mem_ptr_type *pptr, result_type *result ) const {
      *result = decode_base128( pptr );
    }
  };

  /**
   * A %ptr_decoder is a decoder_function for decoding the ptr list portion of
   * a synset.
   */
  struct ptr_decoder : decoder_function<ptr> {
    void operator()( mem_ptr_type *pptr, result_type *result ) const;
  };

  /**
   * This class is needed as an intermediate object to guarantee a particular
   * order of argument evaluation.
   */
  struct base128_list_args {
    base128_list_args( mem_ptr_type *pptr ) :
      size( decode_base128( pptr ) ),
      begin( *pptr )
    {
    }

    size_type const size;
    mem_ptr_type const begin;
  };

public:

  /**
   * A %lemma_id_list is-an encoded_list of the lemma IDs comprising this
   * synset.
   */
  class lemma_id_list : public encoded_list<lemma_id_decoder> {
    lemma_id_list( base128_list_args const &args ) :
      encoded_list<lemma_id_decoder>( args.size, args.begin )
    {
    }
    friend class synset;
  };

  /**
   * A %ptr_list is-an encoded_list of the ptrs comprigins this synset.
   */
  class ptr_list : public encoded_list<ptr_decoder> {
    ptr_list( base128_list_args const &args ) :
      encoded_list<ptr_decoder>( args.size, args.begin )
    {
    }
    friend class synset;
  };

  /**
   * Constructs a %synset.
   *
   * @param p A pointer to the first byte of a binary %synset entry.
   */
  synset( mem_ptr_type p );

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
  static part_of_speech::type get_pos( mem_ptr_type* );
  static mem_ptr_type* skip_lemmas( size_type, mem_ptr_type* );

  part_of_speech::type const pos_;
  lemma_id_list const lemma_ids_;
  ptr_list const ptrs_;
};

} // namespace wordnet
} // namespace zorba

#endif /* ZORBA_FULL_TEXT_WORDNET_SYNSET_H */
/* vim:set et sw=2 ts=2: */
