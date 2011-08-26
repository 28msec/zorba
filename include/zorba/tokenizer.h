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
   * The only thing you need to do is call the callback's \c operator() once
   * for each token you parse in \c tokenize().
   */
  class Callback {
  public:
    typedef Tokenizer::size_type size_type;

    virtual ~Callback();

    /**
     * This member-function is called once per token.
     *
     * @param utf8_s    The UTF-8 token string.  It is not null-terminated.
     * @param utf8_len  The number of bytes in the token string.
     * @param token_no  The token number.  Token numbers start at 0.
     * @param sent_no   The sentence number.  Sentence numbers start at 1.
     * @param para_no   The paragraph number.  Paragraph numbers start at 1.
     * @param payload   Optional user-defined data.
     */
    virtual void operator()( char const *utf8_s, size_type utf8_len,
                             size_type token_no, size_type sent_no,
                             size_type para_no, void *payload = 0 ) = 0;
  };

  /////////////////////////////////////////////////////////////////////////////

  /**
   * Destroys this %Tokenizer.
   * This function is called by Zorba when the %Tokenizer is no longer needed.
   *
   * If your TokenizerProvider dynamically allocates %Tokenizer objects, then
   * the implementation can (and usually is) simply <code>delete this</code>.
   *
   * If your TokenizerProvider returns a pointer to a static %Tokenizer object,
   * then the implementation should do nothing.
   */
  virtual void destroy() const = 0;

  /**
   * Trace options for XML elements combined via bitwise-or.
   */
  enum ElementTraceOptions {
    trace_none  = 0x0,  ///< Trace no elements.
    trace_begin = 0x1,  ///< Trace the beginning of elements.
    trace_end   = 0x2   ///< Trace the ending of elements.
  };

  /**
   * Gets the trace options.  If the value is \c trace_none, then the paragraph
   * number will be incremented upon entering an XML element; if the value is
   * anything other than \c trace_none, then the tokenizer assumes
   * responsibility for incrementing the paragraph number.
   *
   * @return Returns said options.
   */
  int trace_options() const {
    return trace_options_;
  }

  /**
   * This function is called whenever an XML element is entered during
   * tokenization.  Note that this function is called only if \c
   * trace_options() returns non-zero.
   *
   * @param qname The element's QName.
   * @param trace_options The bitwise-or of the trace option(s) in effect for a
   * particular call.
   * @see trace_options()
   */
  virtual void element( Item const &qname, int trace_options );

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
   * Tokenizes the given string.
   *
   * @param utf8_s    The UTF-8 string to tokenize.  It need not be
   *                  null-terminated.
   * @param utf8_len  The number of bytes in the string to be tokenized.
   * @param lang      The language of the string.
   * @param wildcards If \c true, allows XQuery wildcard syntax characters to
   *                  be part of tokens.
   * @param callback  The Callback to call once per token.
   * @param payload   Optional user-defined data.
   */
  virtual void tokenize( char const *utf8_s, size_type utf8_len,
                         locale::iso639_1::type lang, bool wildcards,
                         Callback &callback, void *payload = 0 ) = 0;

  /////////////////////////////////////////////////////////////////////////////

protected:
  /**
   * Constructs a %Tokenizer.
   *
   * @param numbers the Numbers to use.
   * @param trace_options The bitwise-or of the available trace options, if
   * any.
   */
  Tokenizer( Numbers &numbers, int trace_options = trace_none );

  /**
   * Destroys a %Tokenizer.
   */
  virtual ~Tokenizer() = 0;

private:
  int trace_options_;
  Numbers *no_;
};

inline Tokenizer::Numbers& Tokenizer::numbers() {
  return *no_;
}

inline Tokenizer::Numbers const& Tokenizer::numbers() const {
  return *no_;
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
