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
#ifndef ZORBA_TOKENIZER_API_H
#define ZORBA_TOKENIZER_API_H

#include <vector>

#include <zorba/config.h>
#include <zorba/locale.h>
#include <zorba/internal/unique_ptr.h>
#include <zorba/internal/ztd.h>

namespace zorba {

class Item;

///////////////////////////////////////////////////////////////////////////////

/**
 * A %Tokenizer breaks a string into a stream of word tokens.  Each token is
 * assigned a token, sentence, and paragraph number.
 *
 * A %Tokenizer determines word and sentence boundaries automatically, but must
 * be told when to increment the paragraph number.
 */
class ZORBA_DLL_PUBLIC Tokenizer {
public:
  typedef std::unique_ptr<Tokenizer,internal::ztd::destroy_delete<Tokenizer> >
          ptr;

  typedef unsigned size_type;

  /////////////////////////////////////////////////////////////////////////////

  /**
   * A %Numbers contains the current token, sentence, and paragraph numbers.
   */
  struct Numbers {
    typedef Tokenizer::size_type value_type;

    value_type token; ///< Token number.
    value_type sent;  ///< Sentence number.
    value_type para;  ///< Paragraph number.

    /**
     * Default constructor.
     */
    Numbers();
  };

  /////////////////////////////////////////////////////////////////////////////

  /**
   * A %Callback is called once per token.
   * This is only internally by Zorba.
   * You do not need to derive from this class.
   */
  class Callback {
  public:
    typedef Tokenizer::size_type size_type;

    virtual ~Callback();

    /**
     * This member-function is called whenever an item that is being tokenized
     * is entered or exited.
     *
     * @param item The item being entered or exited.
     * @param entering If \c true, the item is being entered; if \c false, the
     * item is being exited.
     */
    virtual void item( Item const &item, bool entering );

    /**
     * This member-function is called once per token.
     *
     * @param utf8_s    The UTF-8 token string.  It is not null-terminated.
     * @param utf8_len  The number of bytes in the token string.
     * @param lang      The language of the token.
     * @param token_no  The token number.  Token numbers start at 0.
     * @param sent_no   The sentence number.  Sentence numbers start at 1.
     * @param para_no   The paragraph number.  Paragraph numbers start at 1.
     * @param item      The Item this token is from, if any.
     */
    virtual void token( char const *utf8_s, size_type utf8_len,
                        locale::iso639_1::type lang,
                        size_type token_no, size_type sent_no,
                        size_type para_no, Item const *item = 0 ) = 0;
  };

  /////////////////////////////////////////////////////////////////////////////

  /**
   * Various properties of this %Tokenizer.
   */
  struct Properties {
    typedef std::vector<locale::iso639_1::type> languages_type;

    /**
     * If \c true, XML elements separate tokens.
     */
    bool elements_separate_tokens;

    /**
     * The set of languages supported.
     */
    languages_type languages;

    /**
     * The URI that uniquely identifies this %Tokenizer.
     */
    char const* uri;
  };

  /**
   * Gets the Properties of this %Tokenizer.
   *
   * @param result The Properties to populate.
   */
  virtual void properties( Properties *result ) const = 0;

  /////////////////////////////////////////////////////////////////////////////

  /**
   * Destroys this %Tokenizer.
   * This function is called by Zorba when the %Tokenizer is no longer needed.
   *
   * If your TokenizerProvider dynamically allocates %Tokenizer objects, then
   * the implementation can simply be (and usually is) <code>delete this</code>.
   *
   * If your TokenizerProvider returns a pointer to a static %Tokenizer object,
   * then the implementation should do nothing.
   */
  virtual void destroy() const = 0;

  /**
   * Gets this %Tokenizer's associated Numbers.
   *
   * @return Returns said Numbers.
   */
  Numbers& numbers();

  /**
   * Gets this %Tokenizer's associated Numbers.
   *
   * @return Returns said Numbers.
   */
  Numbers const& numbers() const;

  /**
   * Tokenizes the given node.
   *
   * @param node      The node to tokenize.
   * @param lang      The default language to use.
   * @param callback  The Callback to call once per token.
   */
  void tokenize_node( Item const &node, locale::iso639_1::type lang,
                      Callback &callback );

  /**
   * Tokenizes the given string.
   *
   * @param utf8_s    The UTF-8 string to tokenize.  It need not be
   *                  null-terminated.
   * @param utf8_len  The number of bytes in the string to be tokenized.
   * @param lang      The language of the string.
   * @param wildcards If \c true, allows XQuery wildcard syntax characters to
   *                  be part of tokens.
   * @param callback  The Callback to call once per token.
   * @param item      The Item this string is from, if any.
   */
  virtual void tokenize_string( char const *utf8_s, size_type utf8_len,
                                locale::iso639_1::type lang, bool wildcards,
                                Callback &callback, Item const *item = 0 ) = 0;

  /////////////////////////////////////////////////////////////////////////////

protected:
  /**
   * Constructs a %Tokenizer.
   *
   * @param numbers the Numbers to use.
   */
  Tokenizer( Numbers &numbers );

  /**
   * Destroys a %Tokenizer.
   */
  virtual ~Tokenizer() = 0;

  /**
   * Given an element, finds its \c xml:lang attribute, if any, and gets its
   * value.
   *
   * @param element The element to check.
   * @param lang A pointer to where to put the found language, if any.
   * @return Returns \c true only if an \c xml:lang attribute is found and the
   * value is a known language.
   */
  bool find_lang_attribute( Item const &element, locale::iso639_1::type *lang );

  /**
   * This member-function is called whenever an item that is being tokenized is
   * entered or exited.
   *
   * @param item      The item being entered or exited.
   * @param entering  If \c true, the item is being entered; if \c false, the
   *                  item is being exited.
   */
  virtual void item( Item const &item, bool entering );

  /**
   * Tokenizes the given node and all of its child nodes, if any.  For each
   * node, it is required that this function call the item() member function of
   * both this %Tokenizer and of the Callback twice, once each for entrance and
   * exit.
   *
   * @param node          The node to tokenize.
   * @param lang          The default language to use.
   * @param callback      The Callback to call per token.
   * @param tokenize_acp  If \c true, additionally tokenize all attribute,
   *                      comment, and processing-instruction nodes encountered;
   *                      if \c false, skip them.
   */
  void tokenize_node_impl( Item const &node, locale::iso639_1::type lang,
                           Callback &callback, bool tokenize_acp );

private:
  Numbers *numbers_;
};

inline Tokenizer::Tokenizer( Numbers &numbers ) : numbers_( &numbers ) {
}

inline Tokenizer::Numbers& Tokenizer::numbers() {
  return *numbers_;
}

inline Tokenizer::Numbers const& Tokenizer::numbers() const {
  return *numbers_;
}

inline void Tokenizer::tokenize_node( Item const &item,
                                      locale::iso639_1::type lang,
                                      Callback &callback ) {
  tokenize_node_impl( item, lang, callback, true );
}

///////////////////////////////////////////////////////////////////////////////

/**
 * A %TokenizerProvider provides a Tokenizer for a given language.
 */
class ZORBA_DLL_PUBLIC TokenizerProvider {
public:
  virtual ~TokenizerProvider();

  /**
   * Creates a new %Tokenizer.
   *
   * @param lang The language of the text that the tokenizer will tokenize.
   * @param numbers The Numbers to use.
   * @return Returns said %Tokenizer.
   */
  virtual Tokenizer::ptr getTokenizer( locale::iso639_1::type lang,
                                       Tokenizer::Numbers &numbers ) const = 0;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_TOKENIZER_API_H */
/* vim:set et sw=2 ts=2: */
