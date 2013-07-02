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
 : @author Matthias Brantner
 : @project Zorba/XQuery Data Model/Atomic/String
 :
 :)
module namespace string = "http://zorba.io/modules/string";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

(:~
 : <p>This function materializes a streamable string.
 : The drawback of a streamable string is that its value can only
 : be consumed once. That is, only one function can access the value
 : of a streamable string item.</p>
 : <p/>
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
 : <p>A streamable string is produced by some functions of a module
 : (e.g. file:read-text()). It's an optimized implementation of an
 : string to handle arbitrary sized data. The drawback is that
 : its value can only be consumed once. That is, only one function
 : can access the value of a streamable string item.</p>
 :
 : @param $s the string to check
 : @return true if the given item is implemented using a streamable string
 :         or false otherwise.
 :
 :)
declare function string:is-streamable($s as string) as boolean external;

(:~
 : <p>Returns a sequence of strings constructed by splitting the input wherever the given
 : separator is found.</p>
 : <p/>
 : <p>The function is different from fn:tokenize. It doesn't allow
 : the separator to be a regular expression. This restriction allows for more
 : performant implementation. Specifically, the function processes
 : streamable strings as input in a streamable way which is particularly useful
 : to tokenize huge strings (e.g. if returned by the file module's read-text
 : function).</p>
 :
 : @param $s the input string to split
 : @param $separator the separator used for splitting the input string $s
 :
 : @return a sequence of strings constructed by splitting the input
 :)
declare function string:split(
  $s as string,
  $separator as string) as string* external;
