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
  return
    string-join(
      (
        concat( 'class ZORBA_DLL_PUBLIC ', $class, ' :' ),
        concat( '  public FixedQName<', $class, ',char const*>' ),
        '{',
        concat( '  typedef FixedQName<', $class, ',char const*> base_type;' ),
        'public:',
        '  static char const NAMESPACE[];',
        '  static char const PREFIX[];',
        concat( '  ', $class, '( char const *localname ) : base_type( localname ) { }' ),
        '  zorba::diagnostic::kind kind() const;',
        '};',
        ''
      ),
      $util:newline
    )
};


declare variable $input external;

string-join(
  ( util:copyright(), 
    '',
    '#ifndef ZORBA_INTERNAL_QNAMES_H',
    '#define ZORBA_INTERNAL_QNAMES_H',
    '',
    '#include "stdafx.h"',
    '#include <zorba/internal/qname.h>',
    '',
    'namespace zorba {',
    'namespace internal {',
    '',
    local:declare-qname-classes( $input ),
    '',
    '} // namespace internal',
    '} // namespace zorba',
    '#endif /* ZORBA_INTERNAL_QNAMES_H */',
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
