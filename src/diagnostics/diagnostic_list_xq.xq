(:
 : Copyright 2006-2011 The FLOWR Foundation.
 :
 : Licensed undre the Apache License, Version 2.0 (the "License");
 : you may not use the file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distruted on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

(:~
 : @author Carlos Lopez
:)

import module namespace util="http://www.zorba-xquery.com/diagnostic/util"
  at "diagnostic_util.xq";

declare function local:err-doc ($err as element(diagnostic),
                    $namespace as xs:string) as xs:string
{
  let $commentline := concat($util:newline, " : ")
  let $commentsec := if(exists($err/comment))
        then concat ($util:newline, " :",
          replace(string($err/comment), '\n[ ]*', $commentline))
        else ""
  (:TODO: The see section could be a lot better and specific:)
  let $seesec := if($namespace = "err")
        then concat($commentline,
            "@see http://www.w3.org/2005/xqt-errors")
        else ""
  return if (exists($err/value))
    then concat ("(:~",
      $commentsec, $seesec,
    $util:newline, ":)")
    else ""
};

declare function local:err-var ($err as element(diagnostic),
                    $namespace as xs:string) as xs:string
{
  let $NSStringVar as xs:string := concat("$", $namespace, ":", "NS")
  let $code := data($err/@code)
  let $qnameArgs := concat('(', $NSStringVar,
    ', "', $namespace, ':', $code, '"',
  ');')
  return concat("declare variable $", $namespace, ":", $code,
    " as xs:QName := fn:QName", $qnameArgs)
};

declare function local:writeErr($err as element(diagnostic),
                    $namespace as xs:string) as xs:string
{
  string-join((
    local:err-doc($err, $namespace), local:err-var($err, $namespace)
  ), $util:newline)
};

declare function local:body($namespace as element(namespace)) as xs:string
{
  string-join((
    let $stringNS := $namespace/@prefix
    for $err in
        $namespace/diagnostic
      return local:writeErr($err, $stringNS)
      ), concat($util:newline, $util:newline))
};

declare function local:getNSURI($namespace as xs:string) as xs:string
{
  if ($namespace = "err")
    then "http://www.w3.org/2005/xqt-errors"
  else if ($namespace = "zerr")
    then "http://www.zorba-xquery.com/errors"
  else if ($namespace = "zwarn")
    then "http://www.zorba-xquery.com/warnings"
  else fn:error()
};

declare function local:header ($namespace as xs:string) as xs:string
{
  concat( fn:replace(fn:replace(fn:replace(util:copyright(),
      "/\*\*?", "(:"),
      "\*/", ":)"),
      "\*", ":"),
    "(:~", $util:newline,
    " : This module contains one declaration of a variable for each", $util:newline,
    " : error of the ", local:getNSURI($namespace), " namespace.", $util:newline,
    " : The variables serves as documentation for the errors but can also", $util:newline,
    " : be used in the code. For example, one useful scenario is to compare", $util:newline,
    " : an error caught in the catch clause of a try-catch expression with one of", $util:newline,
    " : the variables.", $util:newline,
    " :", $util:newline,
    " : @author Carlos Lopez", $util:newline,
    " :)", $util:newline, $util:newline,
    "xquery version '1.0';",
    $util:newline, $util:newline,
    "module namespace ", $namespace, " = '", local:getNSURI($namespace), "';",
    $util:newline, $util:newline,
    "declare variable $", $namespace, ":NS := '", local:getNSURI($namespace), "';"
  )
};

declare function local:writeModule($namespace as element(namespace)) 
                    as xs:string
{
  let $stringNS := $namespace/@prefix
  return string-join((
    local:header($stringNS),
    "",
    local:body($namespace)
  ), $util:newline)
};

declare function local:getFilePath($namespace as xs:string) as xs:string{
  if($namespace = "err")
    then "w3/"
  else if ($namespace = "zerr" or $namespace = "zwarn")
    then "com/zorba-xquery/www/modules/"
  else ""
};

declare variable $input external;
declare variable $ns external;

let $namespace := $input/diagnostic-list/namespace[@prefix=$ns]
let $namestring := $namespace/@prefix
let $filepath := concat("../../modules/", local:getFilePath($namestring),
    $namestring, ".xq")
return local:writeModule($namespace)
