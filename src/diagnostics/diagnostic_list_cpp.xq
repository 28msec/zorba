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

import module namespace util = "http://www.zorba-xquery.com/diagnostic/util" at "diagnostic_util.xq";

declare function local:declare-diagnostics( $doc ) as xs:string*
{
  for $namespace in $doc/diagnostic-list/namespace
  let $class :=
    switch ( data( $namespace/@prefix ) )
    case "err" return "XQueryErrorCode"
    case "zerr" return "ZorbaErrorCode"
    case "zwarn" return "ZorbaWarningCode"
    default return error()
  return
      string-join(
        (
          concat( $util:newline, "namespace ", $namespace/@prefix, " {" ),
          for $diagnostic in $namespace/diagnostic
          return 
            concat (
               util:begin_guard( $diagnostic ),
               $class, " ", $diagnostic/@code,
               if ( $diagnostic/@name )
               then concat( "_", $diagnostic/@name )
               else "",
               '( "', $diagnostic/@code, '" );',
               $util:newline,
               util:end_guard( $diagnostic )
            ),
          concat( "} // namespace ", $namespace/@prefix )
        ),
        concat( $util:newline, $util:newline )
      )
};


declare variable $input external;

string-join(
  ( util:copyright(), 
    '',
    '#include "stdafx.h"',
    '#include &lt;zorba/diagnostic_list.h>',
    '',
    'namespace zorba {',
    '',
    local:declare-diagnostics( $input ),
    '',
    '} // namespace zorba',
    '/*',
    ' * Local variables:',
    ' * mode: c++',
    ' * End:',
    ' */'
  ),
  $util:newline
),
$util:newline

(: vim:set syntax=xquery et sw=2 ts=2: :)
