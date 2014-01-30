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
  variable $temp :=
    for $file in $xml-files
    return local:process-file($file);

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
          if ( fn:not( $iter/@name = "" ) )
          then local:process-iter( $iter )
          else ()
        else (),
      $gen:newline
    )
};

declare function local:process-iter( $iter )
  as xs:string
{
  concat (
    if ( exists( $iter/@preprocessorGuard ) )
    then concat( $iter/@preprocessorGuard, $gen:newline )
    else '',

    concat(
      gen:indent(2), 'void beginVisit( const ', $iter/@name, '&amp; );', $gen:newline,
      gen:indent(2), 'void endVisit  ( const ', $iter/@name, '&amp; );'
    ),

    if ( exists( $iter/@preprocessorGuard ) )
    then concat( $gen:newline, '#endif' )
    else ''
  )
};

declare function local:create-class()
  as xs:string
{
  concat(
    "class ProfileVisitor : public PlanIterVisitor {", $gen:newline,
    'private:', $gen:newline,
    $gen:indent, 'PlanIterator *iter_;', $gen:newline,
    'public:', $gen:newline,
    $gen:indent, 'ProfileVisitor( PlanIterator *iter ) :', $gen:newline,
    $gen:indent, 'iter_( iter ) { }', $gen:newline, $gen:newline,
    $gen:indent, 'void do_something() const;',$gen:newline
  )
};

declare function local:create-fwd-decl() as xs:string
{
  concat(
    'class PlanIterator;', $gen:newline
  )
};

(: list all files that need to be included :)
declare function local:create-includes() as xs:string
{
  fn:concat(
    '#include "common/common.h"', $gen:newline,
    '#include "runtime/visitors/planiter_visitor.h"', $gen:newline
  )
};

declare variable $files as xs:string external;

{
  variable $temp := local:get-files( $files );

  concat(
    gen:add-copyright(),
    gen:add-guard-open( 'runtime_profile_visitor' ), $gen:newline,
    local:create-includes(),
    'namespace zorba {', $gen:newline,
    local:create-fwd-decl(),
    local:create-class(),
    $temp, $gen:newline,
    '};', $gen:newline,
    '} // namespace zorba', $gen:newline,
    gen:add-guard-close(), $gen:newline
  )
}

(: vim:set et sw=2 ts=2: :)
