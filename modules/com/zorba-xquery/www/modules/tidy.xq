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
 : <p>
 : This module provides functions to tidy HTML. The functions in this module
 : take an HTML document (a string) as parameter, tidy it in order to result in
 : valid XHTML, and return this XHTML document as a document-node.
 : </p>
 :
 :
 : @author Sorin Nasoi
 : @see <a href="http://tidy.sourceforge.net/">Tidy Library Project</a>
 :
 :)
module namespace tidy = "http://www.zorba-xquery.com/modules/tidy";

(:~
 : This function tidies the given HTML string and returns
 : a valid XHTML document node.
 :
 : @param $html the HTML string to tidy
 : @return the tidied XHTML document node 
 :)
declare function tidy:tidy (
  $html as xs:string
) as document-node() external;

(:~
 : <p>This function tidies the given HTML string and returns
 : a valid XHTML document node.</p>
 : 
 : <p>The second parameter allows to specify options that
 : configure the tidy process. This parameter is a sequence
 : of name=value pairs. Allowed parameter names and values
 : are documented at <a href="http://tidy.sourceforge.net/docs/quickref.html">
 : http://tidy.sourceforge.net/docs/quickref.html</a>.</p>
 :
 : @param $html the HTML string to tidy
 : @param $options a sequence of name=value pairs that provide options
 :        to configure the tidy process.
 : @return the tidied XHTML document node 
 :)
declare function tidy:tidy (
  $html as xs:string,
  $options as xs:string?
) as document-node() external;
