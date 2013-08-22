(:
 : Copyright 2006-2011 The FLOWR Foundation.
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

(:~
 : @author Carlos Lopez
:)

import module namespace util = "http://zorba.io/diagnostic/util"
  at "diagnostic_util.xq";

declare function local:err-doc( $err as element(diagnostic),
                                $namespace as xs:string )
  as xs:string
{
  let $comment_line := concat($util:newline, " : ")
  let $comment_sec :=
    if ( exists( $err/comment ) )
    then
      concat(
        $util:newline, " :",
        replace( string( $err/comment ), '\n[ ]*', $comment_line )
      )
    else ""
  (:TODO: The see section could be a lot better and specific:)
  let $see_sec :=
    if ( $namespace = "err" )
    then concat( $comment_line, "@see http://www.w3.org/2005/xqt-errors" )
    else ""
  return
    if ( exists( $err/value ) )
    then concat( "(:~", $comment_sec, $see_sec, $util:newline, ":)" )
    else ""
};

declare function local:err-var( $err as element(diagnostic),
                                $namespace as xs:string )
  as xs:string
{
  let $ns_var as xs:string := concat( "$", $namespace, ":", "NS" )
  let $code := data( $err/@code )
  let $qnameArgs := concat( '(', $ns_var, ', "', $namespace, ':', $code, '");' )
  return
    concat(
      "declare variable $", $namespace, ":", $code, " as xs:QName := fn:QName",
      $qnameArgs
    )
};

declare function local:writeErr( $err as element(diagnostic),
                                 $namespace as xs:string )
  as xs:string
{
  string-join(
    (
      local:err-doc( $err, $namespace ), local:err-var( $err, $namespace )
    ),
    $util:newline
  )
};

declare function local:body( $namespace as element(namespace) )
  as xs:string
{
  string-join(
    (
      let $stringNS := $namespace/@prefix
      for $err in $namespace/diagnostic
      return local:writeErr( $err, $stringNS )
    ),
    concat( $util:newline, $util:newline )
  )
};

declare function local:getNSURI( $namespace as xs:string )
  as xs:string
{
  if ( $namespace = "err" )
    then "http://www.w3.org/2005/xqt-errors"
  else if ( $namespace = "jerr" )
    then "http://jsoniq.org/errors"
  else if ( $namespace = "zerr" )
    then "http://zorba.io/errors"
  else if ( $namespace = "zwarn" )
    then "http://zorba.io/warnings"
  else
    fn:error()
};

declare function local:header( $namespace as xs:string )
  as xs:string
{
  let $uri := local:getNSURI($namespace)
  return concat(
    fn:replace( fn:replace( fn:replace( util:copyright(),
      "/\*\*?", "(:" ),
      "\*/", ":)" ),
      "\*", ":" ),
    $util:newline,
    "(:~", $util:newline,
    " : This module contains one variable declaration for each diagnostic of the", $util:newline,
    " : ", $uri, " namespace.", $util:newline,
    " : The variables serves as documentation for the errors but can also", $util:newline,
    " : be used in the code. For example, one useful scenario is to compare", $util:newline,
    " : an error caught in the catch clause of a try-catch expression with one of", $util:newline,
    " : the variables.", $util:newline,
    " :", $util:newline,
    " : @author Carlos Lopez", $util:newline,
    " :", $util:newline,
    " :)", $util:newline, $util:newline,
    "xquery version '1.0';",
    $util:newline, $util:newline,
    "module namespace ", $namespace, " = '", $uri, "';",
    $util:newline, $util:newline,
    "declare variable $", $namespace, ":NS := '", $uri, "';"
  )
};

declare function local:writeModule( $namespace as element(namespace) )
  as xs:string
{
  let $stringNS := $namespace/@prefix
  return string-join(
    (
      local:header($stringNS),
      "",
      local:body($namespace)
    ),
    $util:newline
  )
};

declare variable $input external;
declare variable $ns external;

let $namespace := $input/diagnostic-list/namespace[@prefix=$ns]
let $namestring := $namespace/@prefix
return local:writeModule( $namespace )

(: vim:set et sw=2 ts=2: :)
