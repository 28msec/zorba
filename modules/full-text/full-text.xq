xquery version "3.0";

(:
 : Copyright 2006-2011 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
 :)

(:===========================================================================:)

(:~
 : This module provides an XQuery API to full-text functions.
 : For general information about this implementation of the
 : <a href="http://www.w3.org/TR/xpath-full-text-10/">XQuery and XPath Full Text 1.0 specification</a>
 : as well as instructions for building an installing a thesaurus,
 : see the <a href="../zorba/ft_thesaurus.html">Full Text Thesaurus documentation</a>.
 : <h2>Notes on languages</h2>
 : To refer to particular human languages,
 : uses either the
 : <a href="http://en.wikipedia.org/wiki/ISO_639-1">ISO 639-1</a>
 : or
 : <a href="http://en.wikipedia.org/wiki/ISO_639-2">ISO 639-2</a>
 : languages codes.
 : Note that only a subset of the
 : <a href="http://en.wikipedia.org/wiki/List_of_ISO_639-1_codes">complete list of language codes</a>
 : are supported and not every function supports the same subset.
 : <p/>
 : Most functions in this module take a language as a parameter
 : using the
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>
 : XML schema data type.
 : <h2>Notes on stemming</h2>
 : The <code>stem()</code> functions return the
 : <a href="http://en.wikipedia.org/wiki/Word_stem">stem</a>
 : of a word.
 : The stem of a word itself, however, is not guaranteed to be a word.
 : It is best to consider a stem as an opaque byte sequence.
 : All that is guaranteed about a stem is that,
 : for a given word,
 : the stem of that word will always be the same byte sequence.
 : Hence,
 : you should never compare the result of one of the <code>stem()</code>
 : functions against a non-stemmed string,
 : for example:
 : <pre>
 :  if ( ft:stem( "apples" ) eq "apple" )             ** WRONG **
 : </pre>
 : Instead do:
 : <pre>
 :  if ( ft:stem( "apples" ) eq ft:stem( "apple" ) )  ** CORRECT **
 : </pre>
 : <h2>Notes on the thesaurus</h2>
 : The <code>thesaurus-lookup()</code> functions have "levels"
 : and "relationship" parameters.
 : The values for these are implementation-defined.
 : The default implementation uses the
 : <a href="http://wordnet.princeton.edu/">WordNet lexical database</a>,
 : version 3.0.
 : <p/>
 : In WordNet,
 : the number of "levels" that two phrases are apart
 : are how many hierarchical meanings apart they are.
 : For example,
 : "canary" is 5 levels away from "vertebrate"
 : (carary &gt; finch &gt; oscine &gt; passerine &gt; bird &gt; vertebrate).
 : <p/>
 : When using the WordNet implementation,
 : all of the relationships (and their abbreviations)
 : specified by
 : <a href="http://www.iso.org/iso/iso_catalogue/catalogue_tc/catalogue_detail.htm?csnumber=7776">ISO 2788</a>
 : and
 : <a href="http://www.niso.org/kst/reports/standards?step=2&amp;gid=&amp;project_key=7cc9b583cb5a62e8c15d3099e0bb46bbae9cf38a">ANSI/NISO Z39.19-2005</a>
 : with the exceptions of "HN" (history note)
 : and "X SN" (see scope note for) are supported.
 : These relationships are:
 :  <table>
 :    <tr>
 :      <th>Rel.</th>
 :      <th>Meaning</th>
 :      <th>WordNet Rel.</th>
 :    </tr>
 :    <tr>
 :      <td>BT</td>
 :      <td>broader term</td>
 :      <td>hypernym</td>
 :    </tr>
 :    <tr>
 :      <td>BTG</td>
 :      <td>broader term generic</td>
 :      <td>hypernym</td>
 :    </tr>
 :    <tr>
 :      <td>BTI</td>
 :      <td>broader term instance</td>
 :      <td>instance hypernym</td>
 :    </tr>
 :    <tr>
 :      <td>BTP</td>
 :      <td>broader term partitive</td>
 :      <td>part meronym</td>
 :    </tr>
 :    <tr>
 :      <td>NT</td>
 :      <td>narrower term</td>
 :      <td>hyponym</td>
 :    </tr>
 :    <tr>
 :      <td>NTG</td>
 :      <td>narrower term generic</td>
 :      <td>hyponym</td>
 :    </tr>
 :    <tr>
 :      <td>NTI</td>
 :      <td>narrower term instance</td>
 :      <td>instance hyponym</td>
 :    </tr>
 :    <tr>
 :      <td>NTP</td>
 :      <td>narrower term partitive</td>
 :      <td>part holonym</td>
 :    </tr>
 :    <tr>
 :      <td>RT</td>
 :      <td>related term</td>
 :      <td>also see</td>
 :    </tr>
 :    <tr>
 :      <td>SN</td>
 :      <td>scope note</td>
 :      <td>n/a</td>
 :    </tr>
 :    <tr>
 :      <td>TT</td>
 :      <td>top term</td>
 :      <td>hypernym</td>
 :    </tr>
 :    <tr>
 :      <td>UF</td>
 :      <td>non-preferred term</td>
 :      <td>n/a</td>
 :    </tr>
 :    <tr>
 :      <td>USE</td>
 :      <td>preferred term</td>
 :      <td>n/a</td>
 :    </tr>
 :  </table>
 : Note that you can specify relationships
 : either by their abbreviation
 : or their meaning.
 : Relationships are case-insensitive.
 :
 : In addition to the
 : <a href="http://www.iso.org/iso/iso_catalogue/catalogue_tc/catalogue_detail.htm?csnumber=7776">ISO 2788</a>
 : and
 : <a href="http://www.niso.org/kst/reports/standards?step=2&amp;gid=&amp;project_key=7cc9b583cb5a62e8c15d3099e0bb46bbae9cf38a">ANSI/NISO Z39.19-2005</a>
 : relationships,
 : All of the relationships offered by WordNet are also supported.
 : These relationships are:
 :  <table class="ft_rels">
 :    <tr>
 :      <th>Relationship</th>
 :      <th>Meaning</th>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">also see</td>
 :      <td>
 :        A word that is related to another,
 :        e.g., for "varnished" (furniture)
 :        one should <em>also see</em> "finished."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td>antonym</td>
 :      <td>
 :        A word opposite in meaning to another,
 :        e.g., "light" is an <em>antonym</em> for "heavy."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td>attribute</td>
 :      <td>
 :        A noun for which adjectives express values,
 :        e.g., "weight" is an <em>attribute</em>
 :        for which the adjectives "light" and "heavy"
 :        express values.
 :      </td>
 :    </tr>
 :    <tr>
 :      <td>cause</td>
 :      <td>
 :        A verb that causes another,
 :        e.g., "show" is a <em>cause</em> of "see."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">derivationally related form</td>
 :      <td>
 :        A word that is derived from a root word,
 :        e.g., "metric" is a <em>derivationally related form</em> of "meter."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">derived from adjective</td>
 :      <td>
 :        An adverb that is derived from an adjective,
 :        e.g., "correctly" is <em>derived from the adjective</em> "correct."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td>entailment</td>
 :      <td>
 :        A verb that presupposes another,
 :        e.g., "snoring" <em>entails</em> "sleeping."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td>hypernym</td>
 :      <td>
 :        A word with a broad meaning that more specific words fall under,
 :        e.g., "meal" is a <em>hypernym</em> of "breakfast."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td>hyponym</td>
 :      <td>
 :        A word of more specific meaning than a general term applicable to it,
 :        e.g., "breakfast" is a <em>hyponym</em> of "meal."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">instance hypernym</td>
 :      <td>
 :        A word that denotes a category of some specific instance,
 :        e.g., "author" is an <em>instance hypernym</em> of "Asimov."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">instance hyponym</td>
 :      <td>
 :        A term that donotes a specific instance of some general category,
 :        e.g., "Asimov" is an <em>instance hyponym</em> of "author."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">member holonym</td>
 :      <td>
 :        A word that denotes a collection of individuals,
 :        e.g., "faculty" is a <em>member holonym</em> of "professor."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">member meronym</td>
 :      <td>
 :        A word that denotes a member of a larger group,
 :        e.g., a "person" is a <em>member meronym</em> of a "crowd."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">part holonym</td>
 :      <td>
 :        A word that denotes a larger whole comprised of some part,
 :        e.g., "car" is a <em>part holonym</em> of "engine."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">part meronym</td>
 :      <td>
 :        A word that denotes a part of a larger whole,
 :        e.g., an "engine" is <em>part meronym</em> of a "car."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">participle of verb</td>
 :      <td>
 :        An adjective that is the participle of some verb,
 :        e.g., "breaking" is the <em>participle of the verb</em> "break."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td>pertainym</td>
 :      <td>
 :        An adjective that classifies its noun,
 :        e.g., "musical" is a <em>pertainym</em> in "musical instrument."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">similar to</td>
 :      <td>
 :        Similar, though not necessarily interchangeable, adjectives.
 :        For example, "shiny" is <em>similar to</em> "bright",
 :        but they have subtle differences.
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">substance holonym</td>
 :      <td>
 :        A word that denotes a larger whole containing some constituent
 :        substance, e.g., "bread" is a <em>substance holonym</em> of "flour."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">substance meronym</td>
 :      <td>
 :        A word that denotes a constituant substance of some larger whole,
 :        e.g., "flour" is a <em>substance meronym</em> of "bread."
 :      </td>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap">verb group</td>
 :      <td>
 :        A verb that is a member of a group of similar verbs,
 :        e.g., "live" is in the <em>verb group</em>
 :        of "dwell", "live", "inhabit", etc.
 :      </td>
 :    </tr>
 :  </table>
 : <h2>Notes on tokenization</h2>
 : For general information about the implementation of tokenization,
 : including what constitutes a token,
 : see the <a href="../zorba/ft_tokenizer.html">Full Text Tokenizer</a> documentation.
 : @author Paul J. Lucas
 : @project Zorba/Full-Text/Full-Text
 :)

module namespace ft = "http://zorba.io/modules/full-text";

declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace zerr = "http://zorba.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:===========================================================================:)

(:~
 : Predeclared constant for the Danish
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-DA as xs:language := xs:language("da");

(:~
 : Predeclared constant for the German
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-DE as xs:language := xs:language("de");

(:~
 : Predeclared constant for the English
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-EN as xs:language := xs:language("en");

(:~
 : Predeclared constant for the Spanish
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-ES as xs:language := xs:language("es");

(:~
 : Predeclared constant for the Finnish
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-FI as xs:language := xs:language("fi");

(:~
 : Predeclared constant for the French
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-FR as xs:language := xs:language("fr");

(:~
 : Predeclared constant for the Hungarian
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-HU as xs:language := xs:language("hu");

(:~
 : Predeclared constant for the Italian
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-IT as xs:language := xs:language("it");

(:~
 : Predeclared constant for the Dutch
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-NL as xs:language := xs:language("nl");

(:~
 : Predeclared constant for the Norwegian
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-NO as xs:language := xs:language("no");

(:~
 : Predeclared constant for the Portuguese
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-PT as xs:language := xs:language("pt");

(:~
 : Predeclared constant for the Romanian
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-RO as xs:language := xs:language("ro");

(:~
 : Predeclared constant for the Russian
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-RU as xs:language := xs:language("ru");

(:~
 : Predeclared constant for the Swedish
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-SV as xs:language := xs:language("sv");

(:~
 : Predeclared constant for the Turkish
 : <a href="http://www.w3.org/TR/xmlschema-2/#language"><code>xs:language</code></a>.
 :)
declare variable $ft:LANG-TR as xs:language := xs:language("tr");

(:===========================================================================:)

(:~
 : Gets the current compare options.
 :
 : @return said compare options.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-current-compare-options-1.xq
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-current-compare-options-2.xq
 :)
declare function ft:current-compare-options()
  as object() external;

(:~
 : Gets the current
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>:
 : either the language specified by the
 : <code><a href="http://www.w3.org/TR/xpath-full-text-10/#doc-xquery10-FTOptionDecl">declare ft-option using</a>
 : <a href="http://www.w3.org/TR/xpath-full-text-10/#ftlanguageoption">language</a></code>
 : statement (if any)
 : or the one returned by <code>ft:host-lang()</code> (if none).
 :
 : @return said language.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-current-lang-true-1.xq
 :)
declare function ft:current-lang()
  as xs:language external;

(:~
 : Gets the host's current
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>.
 : The "host" is the computer on which the software is running.
 : The host's current language is obtained as follows:
 :  <ul>
 :    <li>
 :      For *nix systems:
 :      <ol>
 :        <li>
 :          If <a ref="http://www.cplusplus.com/reference/clibrary/clocale/setlocale/"><code>setlocale</code>(3)</a> returns non-null,
 :          the language corresponding to that locale is used.
 :        </li>
 :        <li>
 :          Else, if the <code>LANG</code> environment variable is set,
 :          that language is ued.
 :        </li>
 :        <li>
 :          Otherwise, there is no default language.
 :        </li>
 :      </ol>
 :    </li>
 :    <li>
 :      For Windows systems,
 :      the language corresponding to the locale returned by the
 :      <a href="http://msdn.microsoft.com/en-us/library/windows/desktop/dd318101(v=vs.85).aspx"><code>GetLocaleInfo()</code></a>
 :      function is used.
 :    </li>
 :  </ul>
 :
 : @return said language.
 :)
declare function ft:host-lang()
  as xs:language external;

(:~
 : Checks whether the given
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is supported for stemming.
 :
 : @param $lang The language to check.
 : @return <code>true</code> only if the language is supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-is-stem-lang-es-supported-true.xq
 :)
declare function ft:is-stem-lang-supported( $lang as xs:language )
  as xs:boolean external;

(:~
 : Checks whether the given word is a stop-word.
 :
 : @param $word The word to check.
 : @param $lang The
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : of <code>$word</code>.
 : @return <code>true</code> only if <code>$word</code> is a stop-word.
 : @error err:FTST0009 if <code>$lang</code> is not supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-is-stop-word-true-1.xq
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-is-stop-word-true-3.xq
 :)
declare function ft:is-stop-word( $word as xs:string, $lang as xs:language )
  as xs:boolean external;

(:~
 : Checks whether the given word is a stop-word.
 :
 : @param $word The word to check.
 : The word's <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is assumed to be the one returned by <code>ft:current-lang()</code>.
 : @return <code>true</code> only if <code>$word</code> is a stop-word.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-is-stop-word-true-2.xq
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-is-stop-word-true-4.xq
 :)
declare function ft:is-stop-word( $word as xs:string )
  as xs:boolean external;

(:~
 : Checks whether the given
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is supported for stop words.
 :
 : @param $lang The language to check.
 : @return <code>true</code> only if the language is supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-is-stop-word-lang-en-supported-true.xq
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-is-stop-word-lang-supported-false-1.xq
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-is-stop-word-lang-supported-false-2.xq
 :)
declare function ft:is-stop-word-lang-supported( $lang as xs:language )
  as xs:boolean external;

(:~
 : Checks whether the given
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is supported for look-up using the default thesaurus.
 :
 : @param $lang The language to check.
 : @return <code>true</code> only if the language is supported.
 :)
declare function ft:is-thesaurus-lang-supported( $lang as xs:language )
  as xs:boolean external;

(:~
 : Checks whether the given
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is supported for look-up using the thesaurus specified by the given URI.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $lang The language to check.
 : @return <code>true</code> only if the language is supported.
 : @error err:FTST0018 if <code>$uri</code> refers to a thesaurus
 : that is not found in the statically known thesauri.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-is-thesaurus-lang-supported-true-1.xq
 :)
declare function ft:is-thesaurus-lang-supported( $uri as xs:string,
                                                 $lang as xs:language )
  as xs:boolean external;

(:~
 : Checks whether the given
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is supported for tokenization.
 :
 : @param $lang The language to check.
 : @return <code>true</code> only if the language is supported.
 :)
declare function ft:is-tokenizer-lang-supported( $lang as xs:language )
  as xs:boolean external;

(:~
 : Stems the given word.
 :
 : @param $word The word to stem.
 : @param $lang The
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : of <code>$word</code>.
 : @return the stem of <code>$word</code>.
 : @error err:FTST0009 if <code>$lang</code> is not supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-stem-1.xq
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-stem-2.xq
 :)
declare function ft:stem( $word as xs:string, $lang as xs:language )
  as xs:string external;

(:~
 : Stems the given word.
 :
 : @param $word The word to stem.
 : The word's <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is assumed to be the one returned by <code>ft:current-lang()</code>.
 : @return the stem of <code>$word</code>.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-stem-3.xq
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-stem-4.xq
 :)
declare function ft:stem( $word as xs:string )
  as xs:string external;

(:~
 : Strips all diacritical marks from all characters.
 :
 : @param $string The string to strip diacritical marks from.
 : @return <code>$string</code> with diacritical marks stripped.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-strip-diacritics-1.xq
 :)
declare function ft:strip-diacritics( $string as xs:string )
  as xs:string external;

(:~
 : Looks-up the given phrase in the default thesaurus.
 :
 : @param $phrase The phrase to look up.
 : The phrase's
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is assumed to be the one returned by <code>ft:current-lang()</code>.
 : @return the related phrases if <code>$phrase</code> is found in the
 : thesaurus or the empty sequence if not.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported.
 : @error zerr:ZXQP8401 if the thesaurus data file's version is not supported
 : by the currently running version of the software.
 : @error zerr:ZXQP8402 if the thesaurus data file's endianness does not match
 : that of the CPU on which the software is currently running.
 : @error zerr:ZXQP8403 if there was an error reading the thesaurus data.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-thesaurus-lookup-1.xq
 :)
declare function ft:thesaurus-lookup( $phrase as xs:string )
  as xs:string* external;

(:~
 : Looks-up the given phrase in the thesaurus specified by the given URI.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.
 : @param $lang The
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : of <code>$phrase</code>.
 : @return the related phrases if <code>$phrase</code> is found in the
 : thesaurus or the empty sequence if not.
 : @error err:FTST0009 if <code>$lang</code> is not supported.
 : @error err:FTST0018 if <code>$uri</code> refers to a thesaurus
 : that is not found in the statically known thesauri.
 : @error zerr:ZOSE0001 if the thesaurus data file could not be found.
 : @error zerr:ZOSE0002 if the thesaurus data file is not a plain file.
 : @error zerr:ZXQP8401 if the thesaurus data file's version is not supported
 : by the currently running version of the software.
 : @error zerr:ZXQP8402 if the thesaurus data file's endianness does not match
 : that of the CPU on which the software is currently running.
 : @error zerr:ZXQP8403 if there was an error reading the thesaurus data file.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-thesaurus-lookup-2.xq
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string,
                                      $lang as xs:language )
  as xs:string* external;

(:~
 : Looks-up the given phrase in a thesaurus.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.
 : The phrase's
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is assumed to be the one the one returned by <code>ft:current-lang()</code>.
 : @return the related phrases if <code>$phrase</code> is found in the
 : thesaurus or the empty sequence if not.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is unsupported.
 : @error err:FTST0018 if <code>$uri</code> refers to a thesaurus
 : that is not found in the statically known thesauri.
 : @error zerr:ZOSE0001 if the thesaurus data file could not be found.
 : @error zerr:ZOSE0002 if the thesaurus data file is not a plain file.
 : @error zerr:ZXQP8401 if the thesaurus data file's version is not supported
 : by the currently running version of the software.
 : @error zerr:ZXQP8402 if the thesaurus data file's endianness does not match
 : that of the CPU on which the software is currently running.
 : @error zerr:ZXQP8403 if there was an error reading the thesaurus data file.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-thesaurus-lookup-3.xq
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string )
  as xs:string* external;

(:~
 : Looks-up the given phrase in a thesaurus.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.
 : @param $lang The
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : of <code>$phrase</code>.
 : @param $relationship The relationship the results are to have to
 : <code>$phrase</code>.
 : @return the related phrases if <code>$phrase</code> is found in the
 : thesaurus or the empty sequence if not.
 : @error err:FTST0018 if <code>$uri</code> refers to a thesaurus
 : that is not found in the statically known thesauri.
 : @error err:FTST0009 if <code>$lang</code> is not supported.
 : @error zerr:ZOSE0001 if the thesaurus data file could not be found.
 : @error zerr:ZOSE0002 if the thesaurus data file is not a plain file.
 : @error zerr:ZXQP8401 if the thesaurus data file's version is not supported
 : by the currently running version of the software.
 : @error zerr:ZXQP8402 if the thesaurus data file's endianness does not match
 : that of the CPU on which the software is currently running.
 : @error zerr:ZXQP8403 if there was an error reading the thesaurus data file.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-thesaurus-lookup-4.xq
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string,
                                      $lang as xs:language,
                                      $relationship as xs:string )
  as xs:string* external;

(:~
 : Looks-up the given phrase in a thesaurus.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.
 : @param $lang The
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : of <code>$phrase</code>.
 : @param $relationship The relationship the results are to have to
 : <code>$phrase</code>.
 : @param $level-least The minimum number of levels within the thesaurus to be
 : traversed.
 : @param $level-most The maximum number of levels within the thesaurus to be
 : traversed.
 : @return the related phrases if <code>$phrase</code> is found in the
 : thesaurus or the empty sequence if not.
 : @error err:FOCA0003 if either <code>$level-least</code> or
 : <code>$level-most</code> is either negative or too large.
 : @error err:FTST0018 if <code>$uri</code> refers to a thesaurus
 : that is not found in the statically known thesauri.
 : @error err:FTST0009 if <code>$lang</code> is not supported.
 : @error zerr:ZOSE0001 if the thesaurus data file could not be found.
 : @error zerr:ZOSE0002 if the thesaurus data file is not a plain file.
 : @error zerr:ZXQP8401 if the thesaurus data file's version is not supported
 : by the currently running version of the software.
 : @error zerr:ZXQP8402 if the thesaurus data file's endianness does not match
 : that of the CPU on which the software is currently running.
 : @error zerr:ZXQP8403 if there was an error reading the thesaurus data file.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-thesaurus-lookup-5.xq
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string,
                                      $lang as xs:language,
                                      $relationship as xs:string,
                                      $level-least as xs:integer,
                                      $level-most as xs:integer )
  as xs:string* external;

(:~
 : Tokenizes the given node and all of its decendants.
 :
 : @param $node The node to tokenize.
 : @param $lang The default
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : of <code>$node</code>.
 : @return a (possibly empty) sequence of tokens.
 : @error err:FTST0009 if <code>$lang</code> is not supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-tokenize-node-1.xq
 :)
declare function ft:tokenize-node( $node as node(), $lang as xs:language )
  as object()* external;

(:~
 : Tokenizes the given node and all of its descendants.
 :
 : @param $node The node to tokenize.
 : The node's default
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is assumed to be the one returned by <code>ft:current-lang()</code>.
 : @return a (possibly empty) sequence of tokens.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-tokenize-node-2.xq
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-tokenize-node-3.xq
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-tokenize-node-4.xq
 :)
declare function ft:tokenize-node( $node as node() )
  as object()* external;

(:~
 : Tokenizes the set of nodes comprising <code>$includes</code> (and all of its
 : descendants) but excluding <code>$excludes</code> (and all of its
 : descendants), if any.
 :
 : @param $includes The set of nodes (and its descendants) to include.
 : The default
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is assumed to be the one returned by <code>ft:current-lang()</code>.
 : @param $excludes The set of nodes (and its descendants) to exclude.
 : @return a (possibly empty) sequence of tokens.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-tokenize-nodes-1.xq
 :)
declare function ft:tokenize-nodes( $includes as node()+,
                                    $excludes as node()* )
  as object()* external;

(:~
 : Tokenizes the set of nodes comprising <code>$includes</code> (and all of its
 : descendants) but excluding <code>$excludes</code> (and all of its
 : descendants), if any.
 :
 : @param $includes The set of nodes (and its descendants) to include.
 : @param $excludes The set of nodes (and its descendants) to exclude.
 : @param $lang The default
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : for nodes.
 : @return a (possibly empty) sequence of tokens.
 : @error err:FTST0009 if <code>$lang</code> is not supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-tokenize-nodes-1.xq
 :)
declare function ft:tokenize-nodes( $includes as node()+,
                                    $excludes as node()*,
                                    $lang as xs:language )
  as object()* external;

(:~
 : Tokenizes the given string.
 :
 : @param $string The string to tokenize.
 : @param $lang The
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : of <code>$string</code>.
 : @return a (possibly empty) sequence of tokens.
 : @error err:FTST0009 if <code>$lang</code> is not supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-tokenize-string-1.xq
 :)
declare function ft:tokenize-string( $string as xs:string,
                                     $lang as xs:language )
  as xs:string* external;

(:~
 : Tokenizes the given string.
 :
 : @param $string The string to tokenize.
 : The string's
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : is assumed to be the one returned by <code>ft:current-lang()</code>.
 : @return a (possibly empty) sequence of tokens.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported.
 : @example test/rbkt/Queries/zorba/fulltext/ft-module-tokenize-string-2.xq
 :)
declare function ft:tokenize-string( $string as xs:string )
  as xs:string* external;

(:~
 : Gets properties of the tokenizer for the given
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>.
 :
 : @param $lang The language of the tokenizer to get the properties of.
 : @return said properties.
 : @error err:FTST0009 if <code>$lang</code> is not supported.
 : tokenization specifically.
 :)
declare function ft:tokenizer-properties( $lang as xs:language )
  as object() external;

(:~
 : Gets properties of the tokenizer for the
 : <a href="http://www.w3.org/TR/xmlschema-2/#language">language</a>
 : returned by <code>ft:current-lang()</code>.
 :
 : @return said properties.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported.
 :)
declare function ft:tokenizer-properties()
  as object() external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
