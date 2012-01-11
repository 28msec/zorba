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

module namespace zi = "http://www.zorba-xquery.com/internal/gen";

declare namespace zorba="http://www.zorba-xquery.com";

declare variable $zi:backward_compatible as xs:boolean := true();

declare variable $zi:zorba_version as xs:string := '0x000905';

declare variable $zi:indent as xs:string := '  ';

declare variable $zi:newline as xs:string := '
';

declare function zi:indent($i) as xs:string
{
  string-join(for $j in 1 to $i * 2 return ' ', '')
};

declare function zi:indent() as xs:string
{
  zi:indent(1)
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

declare function zi:add-guard-close() as xs:string
{
  '#endif'
};

declare function zi:add-guard-open($name as xs:string) as xs:string
{
  let $guardName := string-join(('ZORBA',upper-case($name),'H'),'_')
  
  return string-join((string-join(('#ifndef',$guardName),' '),
                      string-join(('#define',$guardName),' ')), $zi:newline)  
};

declare function zi:arity($sig) as xs:string
{
  if ($sig[@variadic = "true"]) then "N"
  else xs:string(count($sig/zorba:param))
};

declare function zi:function-kind($sig) as xs:string
{
  upper-case(
    replace(
      fn:concat($sig/@prefix,
                "_",
                if (fn:starts-with($sig/@localname, ":"))
                then fn:substring($sig/@localname, 2)
                else $sig/@localname,
                "_",
                zi:arity($sig)),
      "-", "_")
   )
};

