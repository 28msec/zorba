jsoniq version "1.0";

(:
 : Copyright 2006-2009 The FLWOR Foundation.
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
 : <p>This module provides string related functions.</p>
 :
 : <p>Mostly, the functions in this module provide primitives
 : to work with streamable strings. For example, it allows to
 : check whether a given string is streamable or seekable.</p>
 :
 : @author Matthias Brantner
 : @project Zorba/XML and JSON Data Model/Atomic/String
 :
 :)
module namespace string = "http://zorba.io/modules/string";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Analyzes a string using a regular expression, returning sequence of JSON
 : objects that identify which parts of the input string matched or failed to
 : match the regular expression; and in the case of matched substrings, which
 : substrings matched each capturing group in the regular expression.
 : <p/>
 : This function behaves like
 : <a href="http://www.w3.org/TR/xpath-functions-30/#func-analyze-string"><code>fn:analyze-string</code></a>
 : but returns a JSON array rather than an XML element.
 :
 : @param $input The string to analyze.  If the empty sequence, the function
 : behaves as if <code>$input</code> were a zero-length string.
 : @param $pattern The regular expression.
 : @param $flags The $flags argument is interpreted in the same way as for the
 : <a href="http://www.w3.org/TR/xpath-functions-30/#func-matches"><code>fn:matches</code></a>
 : function.
 : @return a JSON array of objects where each object contains a single
 : key/value pair.
 : Each key is either <code>match</code> or <code>non-match</code>.
 : For <code>non-match</code>,
 : the value is a string that is the part of <code>$input</code>
 : that did not match;
 : for <code>match</code>,
 : the value is either
 : a string that is the part of <code>$input</code> that matched
 : (when <code>$pattern</code> contains no capturing groups)
 : or an array containing values for both capturing groups
 : and other matches.
 : <p/>
 : Capturing group matches are themselves arrays
 : where the first element is the group number (1-based)
 : and subsequent elements are either
 : a string that is the part of <code>$input</code> that matched
 : or sub-arrays for nested capturing groups.
 :)
declare function string:analyze-string( $input as xs:string?,
                                        $pattern as xs:string,
                                        $flags as xs:string )
  as array() external;

(:~
 : Analyzes a string using a regular expression, returning sequence of JSON
 : objects that identify which parts of the input string matched or failed to
 : match the regular expression; and in the case of matched substrings, which
 : substrings matched each capturing group in the regular expression.
 : <p/>
 : This function behaves like
 : <a href="http://www.w3.org/TR/xpath-functions-30/#func-analyze-string"><code>fn:analyze-string</code></a>
 : but returns a JSON array rather than an XML element.
 :
 : @param $input The string to analyze.  If the empty sequence, the function
 : behaves as if <code>$input</code> were a zero-length string.
 : @param $pattern The regular expression.
 : @return a JSON array of objects where each object contains a single
 : key/value pair.
 : Each key is either <code>match</code> or <code>non-match</code>.
 : For <code>non-match</code>,
 : the value is a string that is the part of <code>$input</code>
 : that did not match;
 : for <code>match</code>,
 : the value is either
 : a string that is the part of <code>$input</code> that matched
 : (when <code>$pattern</code> contains no capturing groups)
 : or an array containing values for both capturing groups
 : and other matches.
 : <p/>
 : Capturing group matches are themselves arrays
 : where the first element is the group number (1-based)
 : and subsequent elements are either
 : a string that is the part of <code>$input</code> that matched
 : or sub-arrays for nested capturing groups.
 :)
declare function string:analyze-string( $input as xs:string?,
                                        $pattern as xs:string )
  as array()
{
  string:analyze-string( $input, $pattern, "" )
};

(:~
 : <p>This function materializes a streamable string.</p>
 :
 : <p>The drawback of a streamable (non-seekable) string is that
 : its value can only be consumed once. That is, only one function
 : can access the value of astreamable string item.</p>
 :
 : <p>In order to remedy this situation, this function can be used to 
 : convert a streamable string into its non-streamable counterpart. As a
 : result, the string returned by this function has the same value as its
 : input but is materialized and, hence, can be consumed multiple times.</p>
 :
 : @param $s the streamable string item to materialize
 : @return a materialized string of its input or the input if the input
 :         item was not a streamable string.
 :
 : @see <a href="www.zorba-xquery.com_modules_string.html#is-streamable-1">string:is-streamable</a>
 : @see <a href="expath.org_ns_file.html#read-text-1">file:read-text#1</a>
 : @see <a href="expath.org_ns_file.html#read-text-2">file:read-text#2</a>
 :)
declare function string:materialize($s as string) as string external;

(:~
 : <p>This function checks whether a given string item is implemented by a
 : streamable string.</p>
 :
 : <p>A streamable string is produced by some functions of a module.
 : It's an optimized implementation of an string to handle arbitrary
 : sized data. The drawback is that its value can only be consumed once.
 : That is, only one function can access the value of a streamable string
 : item.</p>
 :
 : @param $s the string to check
 :
 : @return true if the given item is implemented using a streamable string
 :         or false otherwise.
 :)
declare function string:is-streamable($s as string) as boolean external;

(:~
 : <p>This function checks whether a given string item is a
 : seekable stream string.</p>
 :
 : <p>For example, a seekable streamable string is returned by the
 : file module.</p>
 :
 : @param $s the string to check
 :
 : @return true if the given item is a seekable stream string
 :         or false otherwise.
 :)
declare function string:is-seekable($s as string) as boolean external;

(:~
 : <p>Returns a sequence of strings constructed by splitting the input wherever
 : the given separator is found.</p>
 :
 : <p>The function is different from tokenize. It doesn't allow
 : the separator to be a regular expression. This restriction allows for more
 : performant implementation. Specifically, the function processes
 : streamable strings as input in a streamable way which is particularly useful
 : to tokenize huge strings.</p>
 :
 : @param $s the input string to split
 : @param $separator the separator used for splitting the input string $s
 :
 : @return a sequence of strings constructed by splitting the input
 :)
declare function string:split(
  $s as string,
  $separator as string) as string* external;

(: vim:set et sw=2 ts=2: :)
