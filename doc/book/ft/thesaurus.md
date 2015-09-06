# Full Text Thesaurus

## Introduction

The Zorba XQuery engine implements the <a href="http://www.w3.org/TR/xpath-full-text-10/">XQuery and XPath Full Text 1.0</a> specification that, among other things, adds the ability to use a thesaurus for text-matching via the <a href="http://www.w3.org/TR/xpath-full-text-10/#ftthesaurusoption">thesaurus option</a>. For example, the query:

```xquery
let $x := <msg>affluent man</msg>
return $x contains text "wealthy"
  using thesaurus default
```

returns `true` because `$x contains "wealthy"`
that the thesaurus identified as a synonym of *"affluent"*.

The initial implementation of the thesaurus option uses the <a href="http://wordnet.princeton.edu/">WordNet lexical database</a>, version 3.0.

The stock WordNet database files are plain ASCII text files.
In many ways this is very convenient
for portability, grep-ability, vi-ability, etc.
However, the sum total of the files is approximately 27MB (which is quite large) and accessing the database would be inefficient since the files would have to be parsed for every access.

Instead, the database files are compiled into a single binary file that is 6MB and can be efficiently accessed from Zorba using <a href="http://en.wikipedia.org/wiki/Mmap">mmap(2)</a> with no parsing of the data.
The only caveat of the binary format is that it is <a ref="http://en.wikipedia.org/wiki/Endianness">endian</a>-dependent, i.e., a binary file created on a computer having a little-endian CPU won't work on a computer having a big-endian CPU.

## Downloading & Installing the WordNet Database

To download and install the WordNet database on a Unix-like system,
follow these steps:

* Download the WordNet database from
   <a href="http://wordnet.princeton.edu/wordnet/download/">here</a>.
   All you really need are just the database files
   (`WNdb-3.0.tar.gz`).
* Un-gzip and untar the files.
   This will result in a directory dict containing the database files.
* Move the dict directory somewhere of your choosing,
   e.g., `/usr/local/wordnet-3.0/dict`.
* Compile the `dict` directory into a Zorba-compatible binary thesaurus
   as described below.

To compile the WordNet database files,
use the `zt-wn-compile` script
found in the `scripts` subdirectory of the Zorba distribution.
(Note: this script is written in perl.)
The usage message is:

```bash
zt-wn-compile [-v] wordnet_dict_dir [thesaurus_file]
```

* The \c -v option specifies verbose output.
* The \e wordnet_dict_dir specifies the full path
  of the WordNet \c dict directory.
* The \e thesaurus_file specifies the name of the resulting binary file.
  If none is given, it defaults to \c wordnet-en.zth
  ("en" for English and "zth" for "Zorba Thesaurus file").

For example:

```bash
zt-wn-compile -v /usr/local/wordnet-3.0/dict
```

To install the `wordnet-en.zth` file,
move it onto Zorba's *library path*:

```bash
LIB_PATH/edu/princeton/wordnet/wordnet-en.zth
```

### Downloading a Precompiled WordNet Database

Alternatively, you can download a precompiled, little-endian (Intel) CPU WordNet database from <a href="http://www.zorba.io/downloads/WordNet-3.0/wordnet-en.zip">here</a>.

## Thesaurus Mappings

In order to use thesauri,
you need to specify what symbolic URI(s) <i>map</i>
to what thesauri.
A mapping is of the form:

<i>from_uri</i><code>:=</code><i>implementation-scheme</i><code>:</code><i>to_uri</i>

For example:

```
http://wordnet.princeton.edu:=wordnet://wordnet.princeton.edu
```

says that the symbolic URI `http://wordnet.princeton.edu`
maps to the WordNet implementation
having a database file at the given sub-path `edu/princeton/wordnet`
on Zorba's library path.
Once a mapping is established for a symbolic URI,
it can be used in a query:

```xquery
let $x := <msg>affluent man</msg>
return $x contains text "wealthy"
  using thesaurus at "http://wordnet.princeton.edu"
```

As a special-case,
the `from_uri` can be `default` or `##default`
to allow for specifying the default thesaurus
as was done for the first example on this page.

## Specifying Thesauri Mappings to Zorba

To specify the location of the thesaurus to Zorba from the command-line,
use one or more –thesaurus options:

```bash
zorba --thesaurus default:=wordnet://wordnet.princeton.edu ...
```

## Thesaurus Relationships

Using the WordNet database,
Zorba supports all of the thesaurus relationships
specified by [ISO 2788]
and [ANSI/NISO Z39.19-2005]
with the exceptions of "HN" (history note)
and "X SN" (see scope note for).

### ISO 2788 and ANSI/NISO Z39.19-2005 Relationships

These relationships are:

<center>
  <table class="ft_rels">
    <tr>
      <th>Rel.</th>
      <th>Meaning</th>
      <th>WordNet Rel.</th>
    </tr>
    <tr>
      <td>BT</td>
      <td>broader term</td>
      <td>hypernym</td>
    </tr>
    <tr>
      <td>BTG</td>
      <td>broader term generic</td>
      <td>hypernym</td>
    </tr>
    <tr>
      <td>BTI</td>
      <td>broader term instance</td>
      <td>instance hypernym</td>
    </tr>
    <tr>
      <td>BTP</td>
      <td>broader term partitive</td>
      <td>part meronym</td>
    </tr>
    <tr>
      <td>NT</td>
      <td>narrower term</td>
      <td>hyponym</td>
    </tr>
    <tr>
      <td>NTG</td>
      <td>narrower term generic</td>
      <td>hyponym</td>
    </tr>
    <tr>
      <td>NTI</td>
      <td>narrower term instance</td>
      <td>instance hyponym</td>
    </tr>
    <tr>
      <td>NTP</td>
      <td>narrower term partitive</td>
      <td>part holonym</td>
    </tr>
    <tr>
      <td>RT</td>
      <td>related term</td>
      <td>also see</td>
    </tr>
    <tr>
      <td>SN</td>
      <td>scope note</td>
      <td>n/a</td>
    </tr>
    <tr>
      <td>TT</td>
      <td>top term</td>
      <td>hypernym</td>
    </tr>
    <tr>
      <td>UF</td>
      <td>non-preferred term</td>
      <td>n/a</td>
    </tr>
    <tr>
      <td>USE</td>
      <td>preferred term</td>
      <td>n/a</td>
    </tr>
  </table>
</center>

and can be used in a query like:

```xquery
let $x := <msg>breakfast of champions</msg>
return $x contains text "meal"
  using thesaurus at "http://wordnet.princeton.edu"
  relationship "NT"
```

that returns `true` because `$x contains "breakfast"`
that the thesaurus identified as a "narrower term" (NT)
of "meal."

Note that you can specify relationships
either by their abbreviation
or their meaning.
Relationships are case-insensitive.
The above query is equivalent to:

```xquery
let $x := <msg>breakfast of champions</msg>
return $x contains text "meal"
  using thesaurus at "http://wordnet.princeton.edu"
  relationship "narrower term"
```

Since Zorba's thesaurus is implemented using WordNet,
the [ISO 2788] relationships map to WordNet relationships
that are shown in the "WordNet Rel." column.
WordNet relationships are explained in the next section.

### WordNet Relationships

In addition to the [ISO 2788] and [ANSI/NISO Z39.19-2005] relationships,
Zorba also supports all of the relationships offered by WordNet.
These relationships are:

<center>
  <table class="ft_rels">
    <tr>
      <th>Relationship</th>
      <th>Meaning</th>
    </tr>
    <tr>
      <td>also&nbsp;see</td>
      <td>
        A word that is related to another,
        e.g., for "varnished" (furniture)
        one should <em>also see</em> "finished."
      </td>
    </tr>
    <tr>
      <td>antonym</td>
      <td>
        A word opposite in meaning to another,
        e.g., "light" is an \e antonym for "heavy."
      </td>
    </tr>
    <tr>
      <td>attribute</td>
      <td>
        A noun for which adjectives express values,
        e.g., "weight" is an \e attribute
        for which the adjectives "light" and "heavy"
        express values.
      </td>
    </tr>
    <tr>
      <td>cause</td>
      <td>
        A verb that causes another,
        e.g., "show" is a \e cause of "see."
      </td>
    </tr>
    <tr>
      <td>derivationally&nbsp;related&nbsp;form</td>
      <td>
        A word that is derived from a root word,
        e.g., "metric" is a <em>derivationally related form</em> of "meter."
      </td>
    </tr>
    <tr>
      <td>derived&nbsp;from&nbsp;adjective</td>
      <td>
        An adverb that is derived from an adjective,
        e.g., "correctly" is <em>derived from the adjective</em> "correct."
      </td>
    </tr>
    <tr>
      <td>entailment</td>
      <td>
        A verb that presupposes another,
        e.g., "snoring" \e entails "sleeping."
      </td>
    </tr>
    <tr>
      <td>hypernym</td>
      <td>
        A word with a broad meaning that more specific words fall under,
        e.g., "meal" is a \e hypernym of "breakfast."
      </td>
    </tr>
    <tr>
      <td>hyponym</td>
      <td>
        A word of more specific meaning than a general term applicable to it,
        e.g., "breakfast" is a \e hyponym of "meal."
      </td>
    </tr>
    <tr>
      <td>instance&nbsp;hypernym</td>
      <td>
        A word that denotes a category of some specific instance,
        e.g., "author" is an <em>instance hypernym</em> of "Asimov."
      </td>
    </tr>
    <tr>
      <td>instance&nbsp;hyponym</td>
      <td>
        A term that donotes a specific instance of some general category,
        e.g., "Asimov" is an <em>instance hyponym</em> of "author."
      </td>
    </tr>
    <tr>
      <td>member&nbsp;holonym</td>
      <td>
        A word that denotes a collection of individuals,
        e.g., "faculty" is a <em>member holonym</em> of "professor."
      </td>
    </tr>
    <tr>
      <td>member&nbsp;meronym</td>
      <td>
        A word that denotes a member of a larger group,
        e.g., a "person" is a <em>member meronym</em> of a "crowd."
      </td>
    </tr>
    <tr>
      <td>part&nbsp;holonym</td>
      <td>
        A word that denotes a larger whole comprised of some part,
        e.g., "car" is a <em>part holonym</em> of "engine."
      </td>
    </tr>
    <tr>
      <td>part&nbsp;meronym</td>
      <td>
        A word that denotes a part of a larger whole,
        e.g., an "engine" is <em>part meronym</em> of a "car."
      </td>
    </tr>
    <tr>
      <td>participle&nbsp;of&nbsp;verb</td>
      <td>
        An adjective that is the participle of some verb,
        e.g., "breaking" is the <em>participle of the verb</em> "break."
      </td>
    </tr>
    <tr>
      <td>pertainym</td>
      <td>
        An adjective that classifies its noun,
        e.g., "musical" is a \e pertainym in "musical instrument."
      </td>
    </tr>
    <tr>
      <td>similar&nbsp;to</td>
      <td>
        Similar, though not necessarily interchangeable, adjectives.
        For example, "shiny" is <em>similar to</em> "bright",
        but they have subtle differences.
      </td>
    </tr>
    <tr>
      <td>substance&nbsp;holonym</td>
      <td>
        A word that denotes a larger whole containing some constituent
        substance, e.g., "bread" is a <em>substance holonym</em> of "flour."
      </td>
    </tr>
    <tr>
      <td>substance&nbsp;meronym</td>
      <td>
        A word that denotes a constituant substance of some larger whole,
        e.g., "flour" is a <em>substance meronym</em> of "bread."
      </td>
    </tr>
    <tr>
      <td>verb&nbsp;group</td>
      <td>
        A verb that is a member of a group of similar verbs,
        e.g., "live" is in the <em>verb group</em>
        of "dwell", "live", "inhabit", etc.
      </td>
    </tr>
  </table>
</center>

### WordNet Levels

If no levels are specified in a query,
Zorba defaults the WordNet implementation to be 2 levels.
(The rationale can be found
<a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=11444">here</a>.)

## Providing Your Own Thesaurus

Using the Zorba C++ API,
you can provide your own thesaurus
by deriving from four classes: `Thesaurus`, `Thesaurus::iterator`, `ThesaurusProvider`, and `URLResolver`.

### The Thesaurus Class

The `Thesaurus` class is:

```cpp
class Thesaurus {
public:
  typedef /* implementation-defined */ ptr;
  typedef /* implementation-defined */ range_type;

  class iterator {
  public:
    typedef /* implementation-defined */ ptr;
    virtual void destroy() const = 0;
    virtual bool next( String *synonym ) = 0;
  protected:
    virtual ~iterator();
  };

  virtual iterator::ptr lookup( String const &phrase, String const &relationship, range_type at_least, range_type at_most ) const = 0;

  virtual void destroy() const = 0;
protected:
  virtual ~Thesaurus();
};
```

For details about the `ptr` types,
the `destroy()` functions,
and why the destructors are `protected`,
see the [memory management document](../memory_management.md).

To implement the `Thesaurus` you need to implement the `lookup()` function where:

| Name | Description |
| ---- | ----------- |
| `phrase` | The phrase to be looked-up. |
| `relationship` | The relationship the results are to have to the phrase, if any. |
| `at_least` | The minimum number of levels within the thesaurus to be traversed. |
| `at_most` | The maximum number of levels within the thesaurus to be traversed. |

The `lookup()` function returns a pointer to an `iterator`
that is used to iterate over the phrase's synonyms.
You also need to implement an `iterator`.
A very simple `Thesaurus`
and its `iterator` can be implemented as:

```cpp
class MyThesaurus : public Thesaurus {
public:
  void destroy() const;
  iterator::ptr lookup( String const &phrase, String const &relationship, range_type at_least, range_type at_most ) const;
private:
  //
  // Define a simple thesaurus data structure as a map from a phrase to a list of its synonyms.
  //
  typedef std::list<String> synonyms_type;
  typedef std::map<String,synonyms_type const*> thesaurus_data_type;

  static thesaurus_data_type const& get_thesaurus_data();

  class iterator : public Thesaurus::iterator {
  public:
    iterator( synonyms_type const &s ) : synonyms_( s ), i_( s.begin() ) { }
    void destroy();
    bool next( String *synonym );
  private:
    synonyms_type const &synonyms_;     // synonyms to iterate over
    synonyms_type::const_iterator i_;   // current iterator position
  };
};

void MyThesaurus::destroy() const {
  // Do nothing since we statically allocate a singleton instance of our Thesaurus.
}

MyThesaurus::thesaurus_data_type const& MyThesaurus::get_thesaurus_data() {
  static thesaurus_data_type thesaurus_data;
  if ( thesaurus_data.empty() ) {
    //
    // Construct thesaurus data "by hand" for this example.  A real thesaurus would probably be read from disk.
    // Note that every list of synonyms must always include the original phrase.
    //
    static synonyms_type synonyms;
    synonyms.push_back( "foo" );
    synonyms.push_back( "foobar" );
    thesaurus_data[ "foo"    ] = &synonyms;
    thesaurus_data[ "foobar" ] = &synonyms;
  }
  return thesaurus_data;
}

MyThesaurus::iterator::ptr MyThesaurus::lookup( String const &phrase, String const &relationship,
                                                range_type at_least, range_type at_most ) const {
  static thesaurus_data_type const &thesaurus_data = get_thesaurus_data();
  thesaurus_data_type::const_iterator const entry = thesaurus_data.find( phrase );
  iterator::ptr result;
  if ( entry != thesaurus_data.end() )
    result.reset( new iterator( *entry->second ) );
  return std::move( result );
}

void MyThesaurus::iterator::destroy() const {
  delete this;
}

bool MyThesaurus::iterator::next( String *synonym ) {
  if ( i_ != synonyms_.end() ) {
    *synonym = *i_; // not *i_++ since post-increment is less efficient
    ++i_;
    return true;
  }
  return false;
}
```

A real thesaurus would load a large number of synonyms, of course.

### The ThesaurusProvider Class

The `ThesaurusProvider` class is:

```cpp
class ThesaurusProvider : public Resource {
public:
  typedef /* implementation-defined */ ptr;

  virtual bool getThesaurus( locale::iso639_1::type lang, Thesaurus::ptr *thesaurus = 0 ) const = 0;
  void destroy() const;                 // inherited from Resource
};
```

To implement a `ThesaurusProvider`,
you need to implement the `getThesaurus()` function where:
| Name | Description |
| ---- | ----------- |
| `lang` | The desired language of the thesaurus. |
| `thesaurus` | If not `null`, set to point to a thesaurus for `lang`. |


The `getThesaurus()` function returns `true` only if it can provide a thesaurus for the given language.
Continuing with the example, a very simple `ThesaurusProvider` can be implemented as:

```cpp
class MyThesaurusProvider : pulic ThesaurusProvider {
public:
  void destroy() const;
  bool getThesaurus( iso639_1::type lang, Thesaurus::ptr* = 0 ) const;
};

void MyThesaurusProvider::destroy() const {
  // Do nothing since we statically allocate a singleton instance of our ThesaurusProvider.
}

bool MyThesaurusProvider::getThesaurus( iso639_1::type lang, Thesaurus::ptr *result ) const {
  //
  // Since our tiny thesaurus contains only universally known words, we don't bother checking lang
  // and always return true.
  //
  static MyThesaurus thesaurus;
  if ( result )
    result->reset( &thesaurus );
  return true;
}
```

### A Thesaurus URL Resolver Class

In addition to a `Thesaurus` and `ThesaurusProvider`, you must also implement a "thesaurus resolver" class that, given a URI, provides a `ThesaurusProvider` for that URI.
A simple `ThesaurusURLResolver` for our simple thesaurus can be implemented as:

```cpp
class ThesaurusURLResolver : public URLResolver {
public:
  ThesaurusURLResolver( String const &url ) : url_( url ) { }
  Resource* resolveURL( String const &url, EntityData const* ); // inherited
private:
  String const url_;
};

Resource* ThesaurusURLResolver::resolveURL( String const &url, EntityData const *data ) const {
  if ( data->getKind() == EntityData::THESAURUS )
    static MyThesaurusProvider provider;
    if ( uri == uri_ )
      return &provider;
  }
  return 0;
}
```

For more on `URLResolver`, see [URI resolvers](../uriresolvers.md).

### Using Your Thesaurus

To enable your thesaurus to be used,
you need to add it to a static context:

```cpp
StaticContext_t sctx = zorba->createStaticContext();
ThesaurusURLResolver resolver( "http://www.example.com" );
sctx->registerURLResolver( &resolver );
```

You can then perform a query using your thesaurus:

```xquery
let $x := <msg>foobar</msg>
return $x contains text "foo"
  using thesaurus at "http://www.example.com";
```
