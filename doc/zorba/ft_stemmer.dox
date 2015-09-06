/** \page ft_stemmer Full Text Stemming

\section ft_stemmer_intro Introduction

The Zorba XQuery engine implements the
<a href="http://www.w3.org/TR/xpath-full-text-10/">XQuery and XPath Full Text 1.0</a>
specification that, among other things,
adds the ability to use stemming for text-matching
via the <a href="http://www.w3.org/TR/xpath-full-text-10/#ftstemoption">stemming option</a>.
For example, the query:

\code
let $x := <msg>Self Improvement</msg>
return $x contains text "improve"
  using stemming
\endcode

returns \c true because \c $x contains "Improvment"
that has the same stem as "improve".

The initial implementation of the stemming option uses the
<a href="http://snowball.tartarus.org/texts/stemmersoverview.html">Snowball stemmers</a>
and therefore can stem words in the following languages:
Danish,
Dutch,
English,
Finnish,
French,
German,
Hungarian,
Italian,
Norwegian,
Portuguese,
Romanian,
Russian,
Spanish,
Swedish,
and
Turkish.

\section ft_stemmer_providing Providing Your Own Stemmer

Using the Zorba C++ API,
you can provide your own stemmer
by deriving from two classes:
\c Stemmer
and
\c StemmerProvider.

\subsection ft_class_stemmer The Stemmer Class

The \c Stemmer class is:

\code
class Stemmer {
public:
  typedef /* implementation-defined */ ptr;

  struct Properties {
    char const *uri;
  };

  virtual void destroy() const = 0;
  virtual void properties( Properties *result ) const = 0;
  virtual void stem( String const &word, locale::iso639_1::type lang, String *result ) const = 0;
protected:
  virtual ~Stemmer();
};
\endcode

For details about the \c ptr type,
the \c destroy() function,
and why the destructor is \c protected,
see the \ref memory_management document.

To implement the \c Stemmer,
you need to implement the \c stem() function where:

<table>
  <tr>
    <td>\c word</td>
    <td>The word to be stemmed.</td>
  </tr>
  <tr>
    <td>\c lang</td>
    <td>The language of the word.</td>
  </tr>
  <tr>
    <td>\c result</td>
    <td>The stemmed word goes here.</td>
  </tr>
</table>

Note that \c result should always be set to something.
If your stemmer doesn't know how to stem the given word,
you should set \c result to \c word.
You also need to implement the \c properties() function
and set the identifying URI of your stemmer.

A very simple stemmer
that stems the word "foobar" to "foo"
can be implemented as:

\code
class MyStemmer : public Stemmer {
public:
  void destroy() const;
  void properties( Properties *result ) const;
  void stem( String const &word, locale::iso639_1::type lang, String *result ) const;
private:
  MyStemmer();
  friend class MyStemmerProvider; // only it can create instances
};

void MyStemmer::destroy() const {
  // Do nothing since we statically allocate a singleton instance of our stemmer.
}

void MyStemmer::properties( Properties *props ) const {
  props->uri = "http://my.example.com/zorba/full-text/stemmer";
}

void MyStemmer::stem( String const &word, locale::iso639_1::type lang, String *result ) const {
  if ( word == "foobar" )
    *result = "foo";
  else
    *result = word; // Don't know how to stem word: set result to word as-is.
}
\endcode

A real stemmer would either use a stemming algorithm
or a dictionary look-up
to stem many words,
of course.
Although not used in this simple example,
\c lang can be used to allow a single stemmer instance
to stem words in more than one language.

\subsection ft_class_stemmer_provider The StemmerProvider Class

In addition to a \c Stemmer,
you must also implement a \c StemmerProvider
that, given a language, provides a \c Stemmer for that language:

\code
class StemmerProvider {
public:
  virtual ~StemmerProvider();
  virtual bool getStemmer( locale::iso639_1::type lang, Stemmer::ptr *s = 0 ) const = 0;
};
\endcode

The \c getStemmer() function should return \c true
only if it can provide a \c Stemmer
for the given language; \c false otherwise.
If the \c Stemmer::ptr argument is \c null,
the caller wants to check only whether the provider
can provide a stemmer for the given language
and doesn't want a \c Stemmer instance created or returned.

A simple \c StemmerProvider for our simple stemmer can be implemented as:

\code
class MyStemmerProvider : public StemmerProvider {
public:
  bool getStemmer( locale::iso639_1::type lang Stemmer::ptr *s = 0 ) const;
};

Stemmer::ptr MyStemmerProvider::getStemmer( locale::iso639_1::type lang ) const {
  static MyStemmer stemmer;
  Stemmer::ptr result;
  switch ( lang ) {
    case iso639_1::en:
    case iso639_1::unknown: // Handle "unknown" language since, in many cases, the language is not known.
      result.reset( &stemmer );
      return true;
    default: 
      //
      // We have no stemmer for the given language: return false.
      // Zorba will then use the built-in stemmer for the given language.
      //
      return false;
  }
}
\endcode

\subsection ft_stemmer_enable Using Your Stemmer

To enable your stemmer to be used,
you need to register it with the \c XmlDataManager:

\code
void *const store = StoreManager::getStore();
Zorba *const zorba = Zorba::getInstance( store );

MyStemmerProvider provider;
zorba->getXmlDataManager()->registerStemmerProvider( &provider );
\endcode

*/
/* vim:set et sw=2 ts=2: */
