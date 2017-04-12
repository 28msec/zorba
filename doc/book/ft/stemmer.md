# Full Text Stemming

## Introduction

The Zorba XQuery engine implements the
<a href="http://www.w3.org/TR/xpath-full-text-10/">XQuery and XPath Full Text 1.0</a>
specification that, among other things,
adds the ability to use stemming for text-matching
via the <a href="http://www.w3.org/TR/xpath-full-text-10/#ftstemoption">stemming option</a>.
For example, the query:

```xquery
let $x := <msg>Self Improvement</msg>
return $x contains text "improve"
  using stemming
```

returns `true` because `$x contains "Improvment"`
that has the same stem as `improve`.

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

## Providing Your Own Stemmer

Using the Zorba C++ API, you can provide your own stemmer by deriving from two classes: `Stemmer` and `StemmerProvider`.

### The Stemmer Class

The `Stemmer` class is:

```cpp
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
```

For details about the `ptr` type,
the `destroy()` function and why the destructor is `protected`,
see the [memory management document](../memory_management.md).

To implement the `Stemmer`,
you need to implement the `stem()` function where:

| Class | Description |
| ----- | ----------- |
| `word` | The word to be stemmed. |
| `lang` | The language of the word. |
| `result` | The stemmed word goes here. |

Note that `result` should always be set to something.
If your stemmer doesn't know how to stem the given word, you should set `result to `word`.
You also need to implement the `properties()` function and set the identifying URI of your stemmer.

A very simple stemmer
that stems the word "foobar" to "foo"
can be implemented as:

```cpp
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
```

A real stemmer would either use a stemming algorithm or a dictionary look-up to stem many words, of course.
Although not used in this simple example, `lang` can be used to allow a single stemmer instance to stem words in more than one language.

### The StemmerProvider Class

In addition to a `Stemmer`,
you must also implement a `StemmerProvider` that, given a language, provides a `Stemmer` for that language:

```cpp
class StemmerProvider {
public:
  virtual ~StemmerProvider();
  virtual bool getStemmer( locale::iso639_1::type lang, Stemmer::ptr *s = 0 ) const = 0;
};
```

The `getStemmer()` function should return `true` only if it can provide a `Stemmer` for the given language; `false` otherwise.
If the `Stemmer::ptr` argument is `null`, the caller wants to check only whether the provider can provide a stemmer for the given language and doesn't want a `Stemmer` instance created or returned.

A simple `StemmerProvider` for our simple stemmer can be implemented as:

```cpp
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
```

### Using Your Stemmer

To enable your stemmer to be used, you need to register it with the `XmlDataManager`:

```cpp
void *const store = StoreManager::getStore();
Zorba *const zorba = Zorba::getInstance( store );

MyStemmerProvider provider;
zorba->getXmlDataManager()->registerStemmerProvider( &provider );
```