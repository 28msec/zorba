module namespace zi="http://www.zorba-xquery.com/internal/gen";

declare variable $zi:backward_compatible as xs:boolean := true();

declare variable $zi:zorba_version as xs:string := '0x000905';

declare variable $zi:indent as xs:string := '  ';

declare variable $zi:newline as xs:string := '
';

declare function zi:indent($noTabs as xs:integer) as xs:string
{
  fn:string-join (for $i in (1 to $noTabs) return $zi:indent,'')
};

declare function zi:add-copyright() as xs:string
{
"/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the &quot;License&quot;);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an &quot;AS IS&quot; BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************"
};
