# Full Text Tokenizer

## Introduction

The Zorba XQuery processor implements the
<a href="http://www.w3.org/TR/xpath-full-text-10/">XQuery and XPath Full Text 1.0</a>
specification that, among other things,
<a ref="http://www.w3.org/TR/xpath-full-text-10/#TokenizationSec">tokenizes</a>
a string into a sequence of tokens.

## Tokenization

By default,
Zorba uses the
<a href="http://site.icu-project.org/">ICU library</a>
for tokenization.
For Roman alphabets,
Zorba (ICU)
considers only alpha-numeric sequences of characters to be part of a token;
whitespace and punctuation characters are not
and separate tokens.
However, alpha-numeric sequences matching the regular expression
`[0-9][.,][0-9]`
are retained as part of a token, e.g.:
"98.6" and "1,432.58" are tokens.

Alternatively,
you can implement your own tokenizer
by deriving from the `Tokenizer` class.

## The Tokenizer Class

The `Tokenizer` class is:

```cpp
class Tokenizer {
public:
  typedef /* implementation-defined */ ptr;
  typedef /* implementation-defined */ size_type;

  struct State {
    typedef Tokenizer::size_type value_type;

    value_type token;   // Token number.
    value_type sent;    // Sentence number.
    value_type para;    // Paragraph number.

    State();
  };

  class Callback {
  public:
    typedef Tokenizer::size_type size_type;

    virtual ~Callback();

    virtual void token( char const *utf8_s, size_type utf8_len, locale::iso639_1::type lang,
                        size_type token_no, size_type sent_no, size_type para_no,
                        Item const *item = 0 ) = 0;
  };

  struct Properties {
    typedef std::vector<locale::iso639_1::type> languages_type;

    bool comments_separate_tokens;
    bool elements_separate_tokens;
    bool processing_instructions_separate_tokens;
    languages_type languages;
    char const *uri;
  };

  virtual void properties( Properties *result ) const = 0;

  virtual void destroy() const = 0;
  State& state();
  State const& state() const;

  void tokenize_node( Item const &node, locale::iso639_1::type lang, Callback &callback );

  virtual void tokenize_string( char const *utf8_s, size_type utf8_len, locale::iso639_1::type lang,
                                bool wildcards, Callback &callback, Item const *item = 0 ) = 0;

protected:
  Tokenizer( State& );
  virtual ~Tokenizer();

  bool find_lang_attribute( Item const&, locale::iso639_1::type *lang );
  virtual void item( Item const&, bool entering );
  virtual void tokenize_node_impl( Item const&, locale::iso639_1::type, Callback&, bool tokenize_acp );
};
```

For details about the `ptr` type,
the `destroy()` function,
and why the destructor is `protected`,
see the [memory management document](../memory_management.md).

The `State` struct is created by Zorba
and passed to your constructor.
It simply keeps track of the current
token, sentence, and paragraph numbers.

To implement a `Tokenizer`,
you need to implement the \c %tokenize_string() function where:

| Name | Description |
| ---- | ----------- |
| `utf8_s` | A pointer to the UTF-8 byte sequence comprising the string to be tokenized. |
| `utf8_len` | The number of bytes in the string to be tokenized. |
| `lang` | The <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a> of the string. |
| `wildcards` | If `true`, allows XQuery <a href="http://www.w3.org/TR/xpath-full-text-10/#ftwildcardoption">wildcard syntax characters</a> to be part of tokens. |
| `callback` | The `Callback` to call once per token. |
| `item` |  The `Item` whence this token came. If the token occurred within an element, the `Item` is the text node. If the token occurred within an attribute, the `Item` is the attribute node. |

A complete implementation of `tokenize_string()` is non-trivial
and therefore an example is beyond the scope of this API documentation.
However,
the things a tokenizer should take into consideration include:

* Detecting sentence termination ('.', '?', and '!' characters).
* Handling floating-point numbers with possible thousands separators
  in US and European formats, e.g. "98.7", "98,7", "10,000", etc.
* Distinguishing '.' used as a sentence terminator
  from '.' used as a decimal point.
* Handling apostrophies, e.g., "men's".
* Handling acronyms, e.g., "AT&T".

The task of iterating over an XML element's child nodes
is done by `tokenize_node_impl()`.
Its default implementation
treats XML elements, comments, and processing instructions
as token separators.
If you want to change that,
you need to override `tokenize_node_impl()`.

### Paragraphs

By default,
Zorba increments the current paragraph number once
for each XML element encountered.
However,
this doesn't work well for mixed content.
For example, in the XHTML:
`<p>The <em>best</em> thing ever!</p>`
all the tokens are both in the same sentence and paragraph,
but Zorba will consider that 3 paragraphs by default.

Your tokenizer can take control over when the paragraph number is incremented
by overriding the `item()` function.
The `item()` function is passed the `Item` of the current XML element
and whether the item is being entered or exited.

For example,
the `item()` function for tokenizing XHTML
would be along the lines of:
```cpp
void MyTokenizer::item( Item const &item, bool entering ) {
  if ( entering && item.isNode() && item.getNodeKind() == store::StoreConsts::elementNode ) {
    Item qname;
    item.getNodeName( qname );
    if ( /* qname matches an XHTML block-level element's name */ )
      ++state().para;
}
```

### Properties

To implement a `Tokenizer`,
you need also to implement the `properties()` function
that fills in the \c Properties struct where:

| Name | Description |
| ---- | ----------- |
| `comments_separate_tokens` | If `true`, XML comments separate tokens. For example, `net&lt;!-- --&gt;work` would be 2 tokens instead of 1. |
| `elements_separate_tokens` | If `true`, XML elements separate tokens.  For example, `&lt;b&gt;B&lt;/b&gt;old` would be 2 tokens instead of 1. |
| `processing_instructions_separate_tokens` | If `true`, XML processing instructions separate tokens.  For example, `net&lt;?PI pi?&gt;work` would be 2 tokens instead of 1. |
| `languages` | The list of <a href="http://www.w3.org/TR/xmlschema-2/#language">languages</a> supported by the tokenizer. |
| `uri` | The URI that uniquely identifies the `Tokenizer`. | 

## The TokenizerProviderClass

In addition to a `Tokenizer`,
you must also implement a `TokenizerProvider`
that,
given a <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>,
provides a `Tokenizer` for that language:

```cpp
class TokenizerProvider {
public:
  virtual ~TokenizerProvider();
  virtual bool getTokenizer( locale::iso639_1::type lang, Tokenizer::State *state = 0, Tokenizer::ptr* = 0 ) const = 0;
};
```

Specifically, you need to implement the \c getTokenizer() function where:

| Name | Description |
| ---- | ----------- |
| `lang` | The <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a> to tokenize. |
| `state` | The `State` to use. If `null`, `t` is not set. |
| `t` | If not `null`, set to point to a Tokenizer for `lang`. |

A simple `TokenizerProvider` for our tokenizer can be implemented as:

```cpp
class MyTokenizerProvider : public TokenizerProvider {
public:
  getTokenizer( locale::iso639_1::type lang, Tokenizer::State* = 0, Tokenizer::ptr* = 0 ) const;
};

bool MyTokenizerProvider::getTokenizer( locale::iso639_1::type lang, Tokenizer::State *state, Tokenizer::ptr *t ) const {
  switch ( lang ) {
    case iso639_1::en:
      if ( state && t )
        t->reset( new MyTokenizer );
      return true;
    default:
      return false;
  }
}
```

## Using Your Tokenizer

To enable your tokenizer to be used,
you need to register it with the \c XmlDataManager:

```cpp
void *const store = StoreManager::getStore();
Zorba *const zorba = Zorba::getInstance( store );

MyTokenizerProvider provider;
zorba->getXmlDataManager()->registerTokenizerProvider( &provider );
```
