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
 : This library module provides XQDoc utility functions.
 :
 : @see <a href="http://xqdoc.org/" target="_blank">http://xqdoc.org/</a>
 : @author Gabriel Petrovay
 : @version 1.0
 :)
module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";

(:~
 : Generated the an XQDoc XML document for the provided module.
 :
 : @param $module The module file for which to generate XQDoc.
 : @return The xqdoc element as specified by www.xqdoc.org.
 : @error An error is thrown if an IO problem occurs.
 :)
declare sequential function xqd:xqdoc($module as xs:string) as element() external;
