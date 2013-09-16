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

import module namespace util = "http://zorba.io/diagnostic/util"
  at "diagnostic_util.xq";

declare function local:declare-qname-classes( $doc ) as xs:string*
{
  for $namespace in $doc//namespace
  let $class := concat( $namespace/@class-prefix, "QName" )
  let $uri :=
    if ( starts-with( $namespace/@uri, "http:" ) )
    then concat( '"', $namespace/@uri, '"' )
    else $namespace/@uri
  let $kind-function :=
    switch ( $namespace/@kind-function )
    case "override" return ()
    case "standard" return
      (
        concat( 'zorba::diagnostic::kind ', $class, '::kind() const {' ),
        '  return get_standard_error_kind( localname() );',
        '}'
      )
    case "unknown" return
      (
        concat( 'zorba::diagnostic::kind ', $class, '::kind() const {' ),
        '  return zorba::diagnostic::UNKNOWN_KIND;',
        '}'
      )
    default return error()
  return
    string-join(
      (
        concat( 'char const ', $class, '::NAMESPACE[] = ', $uri, ';' ),
        concat( 'char const ', $class, '::PREFIX[] = "', $namespace/@prefix, '";' ),
        '',
        $kind-function,
        ''
      ),
      $util:newline
    )
};

declare variable $input external;

string-join(
  ( util:copyright(), 
    '',
    '#include <zorba/diagnostic.h>',
    '#include "zorbamisc/ns_consts.h"',
    '',
    'namespace zorba {',
    '',
    'extern diagnostic::kind get_standard_error_kind( char const* );',
    '',
    'namespace internal {',
    '',
    local:declare-qname-classes( $input ),
    '} // namespace internal',
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
