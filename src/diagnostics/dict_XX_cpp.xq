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

declare function local:make-dict( $doc ) as xs:string*
{
  for $entry in ( $doc//diagnostic, $doc//entry )
  let $key := 
    typeswitch ( $entry )
      case element(diagnostic)
        return $entry/@code
      case $e as element(entry)
        return
          (
            (: raise an error if sub-message contains $1 as parameter :)
            if ( contains ( $e/value, "$1" ) )
            then
              error(
                fn:QName("http://www.zorba-xquery.com/error", "submessage"),
                concat(
                  "sub-entry must not contain parameter named $1: ", $e/value
                )
              )
            else
              (),
            if ( $e/parent::diagnostic )
            then concat( "~", $e/parent::diagnostic/@code, "_", $entry/@key )
            else concat( "~", $entry/@key )
          )
      default
        return error()
  let $value := replace( $entry/value, '"', '\\"' )
  let $if := $entry/@if
  order by $key
  return (
    if ( $if )
    then concat( "#if ", $if )
    else (),
    concat( '  { "', $key, '", "', $value, '" },' ),
    if ( $if )
    then "#endif"
    else ()
  )
};


declare variable $input external;

let $lang := $input/diagnostic-list/@lang
return string-join(
  ( util:copyright(), 
    '#include "stdafx.h"',
    '#include "diagnostics/dict_impl.h"',
    '',
    'namespace zorba {',
    'namespace diagnostic {',
    'namespace dict {',
    '',
    concat( 'extern entry const dict_', $lang, '[] = {' ),
    local:make-dict( $input ),
    '};',
    concat( 'DEF_DICT_END(', $lang, ');' ),
    '',
    '} // namespace dict',
    '} // namespace diagnostic',
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
