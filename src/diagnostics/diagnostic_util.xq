module namespace util = "http://www.zorba-xquery.com/diagnostic/util";


declare variable $util:newline as xs:string := "
";

declare function util:copyright() as xs:string
{
'/**
 * Copyright 2006-2011 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
 /*
  * THIS FILE IS GENERATED.
  * PLEASE DO NOT EDIT.
  */
 '
};

declare function util:begin_guard( $diagnostic ) as xs:string
{
  concat(
    if ( $diagnostic/@enable_if and
         not($diagnostic/preceding-sibling::diagnostic[1]/@enable_if ) )
    then
     concat( "#ifdef ", data($diagnostic/@enable_if), $util:newline )
    else
      "",
    if ( $diagnostic/@disable_if and
         not($diagnostic/preceding-sibling::diagnostic[1]/@disable_if ) )
    then
     concat( "#ifndef ", data($diagnostic/@disable_if), $util:newline )
    else
      ""
  )
};

declare function util:end_guard( $diagnostic ) as xs:string
{
  concat(
    if ( $diagnostic/@enable_if and
         not($diagnostic/following-sibling::diagnostic[1]/@enable_if ) )
    then
      concat( "#endif", $util:newline )
    else
      "",
    if ( $diagnostic/@disable_if and
         not($diagnostic/following-sibling::diagnostic[1]/@disable_if ) )
    then
      concat( "#endif", $util:newline )
    else
      ""
  )
};

