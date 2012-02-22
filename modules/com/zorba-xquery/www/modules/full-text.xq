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

(:~
 : This module provides an XQuery API to full-text functions.
 : <h2>Notes on the thesaurus</h2>
 : The <code>ft:thesaurus-lookup</code> function has "levels"
 : and "relationship" parameters.
 : The values for these are implementation-defined.
 : Zorba's default implementation uses the
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
 : Zorba supports all of the relationships (and their abbreviations)
 : specified by ISO 2788 and ANSI/NISO Z39.19-2005
 : with the exceptions of "HN" (history note)
 : and "X SN" (see scope note for).
 : Additionally, Zorba also supports all WordNet relationships.
 : <table>
 :   <tr>
 :     <th>Rel.</th>
 :     <th>Meaning</th>
 :     <th>WordNet Rel.</th>
 :   </tr>
 :   <tr>
 :     <td>BT</td>
 :     <td>broader term</td>
 :     <td>hypernym</td>
 :   </tr>
 :   <tr>
 :     <td>BTG</td>
 :     <td>broader term generic</td>
 :     <td>hypernym</td>
 :   </tr>
 :   <tr>
 :     <td>BTI</td>
 :     <td>broader term instance</td>
 :     <td>instance hypernym</td>
 :   </tr>
 :   <tr>
 :     <td>BTP</td>
 :     <td>broader term partitive</td>
 :     <td>part meronym</td>
 :   </tr>
 :   <tr>
 :     <td>NT</td>
 :     <td>narrower term</td>
 :     <td>hyponym</td>
 :   </tr>
 :   <tr>
 :     <td>NTG</td>
 :     <td>narrower term generic</td>
 :     <td>hyponym</td>
 :   </tr>
 :   <tr>
 :     <td>NTI</td>
 :     <td>narrower term instance</td>
 :     <td>instance hyponym</td>
 :   </tr>
 :   <tr>
 :     <td>NTP</td>
 :     <td>narrower term partitive</td>
 :     <td>part holonym</td>
 :   </tr>
 :   <tr>
 :     <td>RT</td>
 :     <td>related term</td>
 :     <td>also see</td>
 :   </tr>
 :   <tr>
 :     <td>SN</td>
 :     <td>scope note</td>
 :     <td>n/a</td>
 :   </tr>
 :   <tr>
 :     <td>TT</td>
 :     <td>top term</td>
 :     <td>hypernym</td>
 :   </tr>
 :   <tr>
 :     <td>UF</td>
 :     <td>non-preferred term</td>
 :     <td>n/a</td>
 :   </tr>
 :   <tr>
 :     <td>USE</td>
 :     <td>preferred term</td>
 :     <td>n/a</td>
 :   </tr>
 : </table>
 : Relationships are case-insensitive.
 : <h2>Notes on tokens</h2>
 : The <code>ft:tokenize()</code>
 : and <code>ft:tokenize-string()</code> functions
 : return a sequence of &lt;token&gt; elements
 : containing attributes for each token:
 :  <table>
 :    <tr>
 :      <th>Attribute</th>
 :      <th>Type</th>
 :      <th>Meaning</th>
 :    </tr>
 :    <tr>
 :      <td>lang</td>
 :      <td><code>xs:language</code></td>
 :      <td>The language of the token.</td>
 :    </tr>
 :    <tr>
 :      <td>sentence</td>
 :      <td><code>xs:nonNegativeInteger</code></td>
 :      <td>The sentence number.</td>
 :    </tr>
 :    <tr>
 :      <td>paragraph</td>
 :      <td><code>xs:nonNegativeInteger</code></td>
 :      <td>The paragraph number.</td>
 :    </tr>
 :    <tr>
 :      <td>value</td>
 :      <td><code>xs:string</code></td>
 :      <td>The token string value.</td>
 :    </tr>
 :    <tr>
 :      <td>node-ref</td>
 :      <td><code>xs:string</code></td>
 :      <td>A reference to the originating node.</td>
 :    </tr>
 :  </table>
 : <h2>Notes on tokenizer properties</h2>
 : The <code>ft:tokenizer-properties()</code> functions
 : return a single <code>&lt;tokenizer-properties&gt;</code> element
 : containing attributes that describe the tokenizer's properties:
 :  <table>
 :    <tr>
 :      <th>Attribute</th>
 :      <th>Type</th>
 :      <th>Meaning</th>
 :    </tr>
 :    <tr>
 :      <td nowrap="nowrap"><code>elements-separate-tokens</code></td>
 :      <td><code>xs:boolean</code></td>
 :      <td>
 :        If true,
 :        XML elements separate tokens,
 :        for example
 :        &lt;b&gt;B&lt;/b&gt;old
 :        would be 2 tokens instead of 1.
 :      </td>
 :    </tr>
 :  </table>
 :)
module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

import schema namespace ft-schema =
  "http://www.zorba-xquery.com/modules/full-text";

declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace zerr = "http://www.zorba-xquery.com/errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Gets the current language: either the langauge specified by the
 : <code>declare ft-option using language</code> statement (if any)
 : or the one returned by <code>ft:host-lang()</code> (if none).
 :
 : @return said language.
 :)
declare function ft:current-lang()
  as xs:language external;

(:~
 : Gets the host's current language.  The "host" is the computer on which Zorba
 : is running.  The host's current language is obtained as follows:
 :  <ul>
 :    <li>
 :      For *nix systems:
 :      <ol>
 :        <li>
 :          If <code>setlocale</code>(3) returns non-null,
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
 :      For Windows systems, the language corresponding to the locale returned
 :      by the <code>GetLocaleInfoA()</code> function is used.
 :    </li>
 :  </ul>
 : @return said language.
 :)
declare function ft:host-lang()
  as xs:language external;

(:~
 : Checks whether the given language is supported for stemming.
 :
 : @param $lang The language to check.
 : @return <code>true</code> only if the language is supported.
 :)
declare function ft:is-stem-lang-supported( $lang as xs:language )
  as xs:boolean external;

(:~
 : Checks whether the given word is a stop-word.
 :
 : @param $word The word to check.
 : @param $lang The language of <code>$word</code>.
 : @return <code>true</code> only if <code>$word</code> is a stop-word.
 : @error zerr:ZXQP8405 if <code>$lang</code> is not supported for stop-words.
 :)
declare function ft:is-stop-word( $word as xs:string, $lang as xs:language )
  as xs:boolean external;

(:~
 : Checks whether the given word is a stop-word.
 :
 : @param $word The word to check.  The word's language is assumed to be the
 : one returned by <code>ft:current-lang()</code>.
 : @return <code>true</code> only if <code>$word</code> is a stop-word.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported in
 : general.
 : @error zerr:ZXQP8405 if <code>ft:current-lang()</code> is not supported for
 : stop-words specifically.
 :)
declare function ft:is-stop-word( $word as xs:string )
  as xs:boolean
{
  ft:is-stop-word( $word, ft:current-lang() )
};

(:~
 : Checks whether the given language is supported for stop words.
 :
 : @param $lang The language to check.
 : @return <code>true</code> only if the language is supported.
 :)
declare function ft:is-stop-word-lang-supported( $lang as xs:language )
  as xs:boolean external;

(:~
 : Checks whether the given language is supported for look-up using the default
 : thesaurus.
 :
 : @param $lang The language to check.
 : @return <code>true</code> only if the language is supported.
 :)
declare function ft:is-thesaurus-lang-supported( $lang as xs:language )
  as xs:boolean external;

(:~
 : Checks whether the given language is supported for look-up using the
 : thesaurus specified by the given URI.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $lang The language to check.
 : @return <code>true</code> only if the language is supported.
 : @error err:FTST0018 if <code>$uri</code> refers to a thesaurus
 : that is not found in the statically known thesauri.
 :)
declare function ft:is-thesaurus-lang-supported( $uri as xs:string,
                                                 $lang as xs:language )
  as xs:boolean external;

(:~
 : Stems the given word.
 :
 : @param $word The word to stem.
 : @param $lang The language of <code>$word</code>.
 : @return the stem of <code>$word</code>.
 : @error err:FTST0009 if <code>$lang</code> is not supported in general.
 : @error zerr:ZXQP8404 if <code>$lang</code> is not supported for stemming
 : specifically.
 :)
declare function ft:stem( $word as xs:string, $lang as xs:language )
  as xs:string external;

(:~
 : Stems the given word.
 :
 : @param $word The word to stem.  The word's language is assumed to be the
 : one returned by <code>ft:current-lang()</code>.
 : @return the stem of <code>$word</code>.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported in
 : general.
 : @error zerr:ZXQP8404 if <code>ft:current-lang()</code> is not supported for
 : stemming specifically.
 :)
declare function ft:stem( $word as xs:string )
  as xs:string
{
  ft:stem( $word, ft:current-lang() )
};

(:~
 : Strips all diacritical marks from all characters.
 :
 : @param $string The string to strip diacritical marks from.
 : @return <code>$string</code> with diacritical marks stripped.
 :)
declare function ft:strip-diacritics( $string as xs:string )
  as xs:string external;

(:~
 : Looks-up the given phrase in the default thesaurus.
 :
 : @param $phrase The phrase to look up.  The phrase's language is assumed to
 : be the one returned by <code>ft:current-lang()</code>.
 : @return the original and related phrases.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported in
 : general.
 : @error zerr:ZXQP8401 if the thesaurus data file's version is not supported
 : by the currently running version of Zorba.
 : @error zerr:ZXQP8402 if the thesaurus data file's endianness does not match
 : that of the CPU on which Zorba is currently running.
 : @error zerr:ZXQP8403 if there was an error reading the thesaurus data.
 : @error zerr:ZXQP8405 if <code>ft:current-lang()</code> is not supported for
 : thesaurus look-up specifically.
 :)
declare function ft:thesaurus-lookup( $phrase as xs:string )
  as xs:string+ external;

(:~
 : Looks-up the given phrase in the thesaurus specified by the given URI.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.
 : @param $lang The language of <code>$phrase</code>.
 : @return the original and related phrases.
 : @error err:FTST0009 if <code>$lang</code> is not supported in general.
 : @error err:FTST0018 if <code>$uri</code> refers to a thesaurus
 : that is not found in the statically known thesauri.
 : @error zerr:ZOSE0001 if the thesaurus data file could not be found.
 : @error zerr:ZOSE0002 if the thesaurus data file is not a plain file.
 : @error zerr:ZXQP8401 if the thesaurus data file's version is not supported
 : by the currently running version of Zorba.
 : @error zerr:ZXQP8402 if the thesaurus data file's endianness does not match
 : that of the CPU on which Zorba is currently running.
 : @error zerr:ZXQP8403 if there was an error reading the thesaurus data file.
 : @error zerr:ZXQP8405 if <code>$lang</code> is not supported for thesaurus
 : look-up specifically.
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string,
                                      $lang as xs:language )
  as xs:string+ external;

(:~
 : Looks-up the given phrase in a thesaurus.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.  The phrase's language is assumed to
 : be the one the one returned by <code>ft:current-lang()</code>.
 : @return the original and related phrases.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is unsupported in
 : general.
 : @error err:FTST0018 if <code>$uri</code> refers to a thesaurus
 : that is not found in the statically known thesauri.
 : @error zerr:ZOSE0001 if the thesaurus data file could not be found.
 : @error zerr:ZOSE0002 if the thesaurus data file is not a plain file.
 : @error zerr:ZXQP8401 if the thesaurus data file's version is not supported
 : by the currently running version of Zorba.
 : @error zerr:ZXQP8402 if the thesaurus data file's endianness does not match
 : that of the CPU on which Zorba is currently running.
 : @error zerr:ZXQP8403 if there was an error reading the thesaurus data file.
 : @error zerr:ZXQP8405 if <code>ft:current-lang()</code> is not supported for
 : thesaurus look-up specifically.
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string )
  as xs:string+
{
  ft:thesaurus-lookup( $uri, $phrase, ft:current-lang() )
};

(:~
 : Looks-up the given phrase in a thesaurus.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.
 : @param $lang The language of <code>$phrase</code>.
 : @param $relationship The relationship the results are to have to
 : <code>$phrase</code>.
 : @return the original and related phrases.
 : @error err:FTST0018 if <code>$uri</code> refers to a thesaurus
 : that is not found in the statically known thesauri.
 : @error err:FTST0009 if <code>$lang</code> is not supported in general.
 : @error zerr:ZOSE0001 if the thesaurus data file could not be found.
 : @error zerr:ZOSE0002 if the thesaurus data file is not a plain file.
 : @error zerr:ZXQP8401 if the thesaurus data file's version is not supported
 : by the currently running version of Zorba.
 : @error zerr:ZXQP8402 if the thesaurus data file's endianness does not match
 : that of the CPU on which Zorba is currently running.
 : @error zerr:ZXQP8403 if there was an error reading the thesaurus data file.
 : @error zerr:ZXQP8405 if <code>$lang</code> is not supported for thesaurus
 : look-up specifically.
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string,
                                      $lang as xs:language,
                                      $relationship as xs:string )
  as xs:string+ external;

(:~
 : Looks-up the given phrase in a thesaurus.
 :
 : @param $uri The URI specifying the thesaurus to use.
 : @param $phrase The phrase to look up.
 : @param $lang The language of <code>$phrase</code>.
 : @param $relationship The relationship the results are to have to
 : <code>$phrase</code>.
 : @param $level-least The minimum number of levels within the thesaurus to be
 : travers$ed.
 : @param $level-most The maximum number of levels within the thesaurus to be
 : traversed.
 : @return the original and related phrases.
 : @error err:FOCA0003 if either <code>$level-least</code> or
 : <code>$level-most</code> is either negative or too large.
 : @error err:FTST0018 if <code>$uri</code> refers to a thesaurus
 : that is not found in the statically known thesauri.
 : @error err:FTST0009 if <code>$lang</code> is not supported in general.
 : @error zerr:ZOSE0001 if the thesaurus data file could not be found.
 : @error zerr:ZOSE0002 if the thesaurus data file is not a plain file.
 : @error zerr:ZXQP8401 if the thesaurus data file's version is not supported
 : by the currently running version of Zorba.
 : @error zerr:ZXQP8402 if the thesaurus data file's endianness does not match
 : that of the CPU on which Zorba is currently running.
 : @error zerr:ZXQP8403 if there was an error reading the thesaurus data file.
 : @error zerr:ZXQP8405 if <code>$lang</code> is not supported for thesaurus
 : look-up specifically.
 :)
declare function ft:thesaurus-lookup( $uri as xs:string, $phrase as xs:string,
                                      $lang as xs:language,
                                      $relationship as xs:string,
                                      $level-least as xs:integer,
                                      $level-most as xs:integer )
  as xs:string+ external;

(:~
 : Tokenizes the given document.
 :
 : @param $doc The document to tokenize.
 : @param $lang The default language of <code>$doc</code>.
 : @return a (possibly empty) sequence of tokens.
 : @error err:FTST0009 if <code>$lang</code> is not supported in general.
 :)
declare function ft:tokenize( $doc as node(), $lang as xs:language )
  as node()* external;

(:~
 : Tokenizes the given document.
 :
 : @param $doc The XML document to tokenize.  The document's default language
 : is assumed to be the one returned by <code>ft:current-lang()</code>.
 : @return a (possibly empty) sequence of tokens.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported in
 : general.
 :)
declare function ft:tokenize( $doc as node() )
  as node()*
{
  ft:tokenize( $doc, ft:current-lang() )
};

(:~
 : Tokenizes the given string.
 :
 : @param $string The string to tokenize.
 : @param $lang The default language of <code>$string</code>.
 : @return a (possibly empty) sequence of tokens.
 : @error err:FTST0009 if <code>$lang</code> is not supported in general.
 :)
declare function ft:tokenize-string( $string as xs:string,
                                     $lang as xs:language )
  as xs:string*
{
  () (: TODO :)
};

(:~
 : Tokenizes the given string.
 :
 : @param $string The string to tokenize.  The string's default language is
 : assumed to be the one returned by <code>ft:current-lang()</code>.
 : @return a (possibly empty) sequence of tokens.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported in
 : general.
 :)
declare function ft:tokenize-string( $string as xs:string )
  as xs:string*
{
  ft:tokenize-string( $string, ft:current-lang() )
};

(:~
 : Gets properties of the tokenizer for the given language.
 :
 : @param $lang The langauage of the tokenizer to get the properties of.
 : @return said properties.
 : @error err:FTST0009 if <code>$lang</code> is not supported in general.
 :)
declare function ft:tokenizer-properties( $lang as xs:language )
  as node() external;

(:~
 : Gets properties of the tokenizer for the language returned by
 : <code>ft:current-lang()</code>.
 :
 : @return said properties.
 : @error err:FTST0009 if <code>ft:current-lang()</code> is not supported in
 : general.
 :)
declare function ft:tokenizer-properties()
  as node()
{
  ft:tokenizer-properties( ft:current-lang() )
};

(: vim:set et sw=2 ts=2: :)
