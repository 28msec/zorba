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

declare function local:make-zed-defines( $doc ) as xs:string*
{
  for $entry in ( $doc//entry )
  let $key := $entry/@key
  return
    if ( contains( $key, ' ' ) )
    then ()
    else
      let $full_key := 
        if ( $entry/parent::diagnostic )
        then concat( $entry/parent::diagnostic/@code, "_", $key )
        else $key
      return concat( "#define ZED_", $full_key, ' "~', $full_key, '"' )
};

declare variable $input external;

string-join(
  ( util:copyright(), 
    '#ifndef ZORBA_DIAGNOSTICS_ZED_KEYS',
    '#define ZORBA_DIAGNOSTICS_ZED_KEYS',
    '',
    local:make-zed-defines( $input ),
    '',
    '#endif /* ZORBA_DIAGNOSTICS_ZED_KEYS */',
    '/*',
    ' * Local variables:',
    ' * mode: c++',
    ' * End:',
    ' */',
    '/* vim:set et sw=2 ts=2: */'
  ),
  $util:newline
),
$util:newline

(: vim:set syntax=xquery et sw=2 ts=2: :)
