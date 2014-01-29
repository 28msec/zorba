(:
 : Copyright 2006-2014 The FLWOR Foundation.
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

declare namespace zorba = "http://www.zorba-xquery.com";
declare namespace ann = "http://zorba.io/annotations";

import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";
import module namespace file = "http://expath.org/ns/file";

declare %ann:nondeterministic function local:get-files( $files as xs:string )
  as xs:string
{
  variable $xml-files as xs:string* := tokenize( $files, ',' );
  variable $temp := for $file in $xml-files return local:process-file( $file );

  string-join( $temp, $gen:newline )
};

declare %ann:nondeterministic function local:process-file( $file )
  as xs:string
{
  let $doc := fn:parse-xml( file:read-text( $file ) )/zorba:iterators
  return
    string-join(
      for $iter in $doc//zorba:iterator
      return 
        if ( fn:not($iter/@generateVisitor) or $iter/@generateVisitor eq "true")
        then
          if ( fn:not( $iter/@name = "") )
          then local:process-iter( $iter )
          else ()
        else (),
      $gen:newline
    )
};

declare function local:process-iter( $iter )
  as xs:string
{
  local:profile-visitor-definition( $iter )
};

declare function local:create-class()
  as xs:string
{
  concat(
    'void Profile::do_something() {', $gen:newline,
    $gen:indent, '// TODO', $gen:newline,
    '}, $gen:newline,
    $gen:newline
  )
};

declare function local:create-includes( $files )
  as xs:string
{
  (: compute the name of the header file to be included.
     take the substring after src/runtime/spec/ and replace
     .xml by .h
   :)
  fn:concat(
    '#include "stdafx.h"', $gen:newline,
    '#include "runtime/visitors/profile_visitor.h"', $gen:newline,
    '#include "runtime/visitors/planiter_visitor.h"', $gen:newline,
    '#include "system/properties.h"', $gen:newline,
    '#include "util/string_util.h"', $gen:newline,
    string-join(
      for $i in tokenize( $files, ',' )
      let $xml-file := fn:replace( $i, ".xml", ".h" )
      return fn:concat( '#include "runtime/', $xml-file, '"' ),
      $gen:newline
    )
  )
};

declare function local:get-include-quoted( $include )
  as xs:string
{
  if ( empty( $include/@guard ) )
  then
    concat( '#include "', $include/text(), '"' )
  else
    concat(
      '#ifdef ', $include/@guard, $gen:newline,
      '#include "', $include/text(), '"', $gen:newline,
      '#endif'
    )
};

declare function local:profile-visitor-definition( $iter )
  as xs:string
{
  concat(
    if ( exists( $iter/@preprocessorGuard ) )
    then $iter/@preprocessorGuard
    else '',
    $gen:newline,

    '// &lt;',$iter/@name,'&gt;',$gen:newline,

    'void ProfileVisitor::beginVisit( const ', $iter/@name, '&amp; a) {', $gen:newline,
    '}',$gen:newline,
    $gen:newline,
    'void PrinterVisitor::endVisit( const ',$iter/@name,'&amp; ) {',$gen:newline,
    '}',$gen:newline,
    '// &lt;/',$iter/@name,'&gt;',$gen:newline),''),

    if ( exists( $iter/@preprocessorGuard ) )
    then concat( $gen:newline, '#endif' )
    else ''
  )
};

declare variable $files as xs:string external;

{
  variable $temp := local:get-files( $files );

  concat(
    gen:add-copyright(),
    local:create-includes( $files ),
    'namespace zorba {',
    local:create-class(),
    $temp,
    '} // namespace zorba', $gen:newline
  )
}

(: vim:set et sw=2 ts=2: :)
