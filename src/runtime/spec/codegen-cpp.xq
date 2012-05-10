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

declare namespace zorba="http://www.zorba-xquery.com";

import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";
import module namespace file = "http://expath.org/ns/file";

declare variable $local:CODEGEN_ERROR as xs:QName := xs:QName("zorba:codegen");
declare variable $file as xs:string external;
declare variable $mappings as xs:string external;
declare variable $mappings_doc := "";
declare variable $file_doc := "";

declare variable $files external;

declare function local:includes($doc) as xs:string
{
  let $dir-name := fn:replace(fn:string-join(fn:tokenize($file, "/")[position() gt last() - 2], "/"),
                     ".xml", ".h")
  return
  string-join(
    (
      '#include "stdafx.h"',
      concat('#include "runtime/', $dir-name, '"'),
      concat('#include "functions/func_', fn:tokenize($dir-name, "/")[last()], '"'),
      for $include in $doc//zorba:codegen/zorba:cpp/zorba:include[@form='Angle-bracket']
      return 
        concat('#include <', $include/text(), '>'),

      for $include in $doc//zorba:codegen/zorba:cpp/zorba:include[@form='Quoted']
      return
        concat('#include "', $include/text(), '"')
    ),
    $gen:newline
  )
};


declare function local:process-file(
    $doc,
    $name as xs:string,
    $mappings) as xs:string
{
  string-join((
    local:process($doc,'function', $name, $mappings),
    local:process($doc,'context', $name, $mappings)),
    $gen:newline
  )
};


(:
   $type can be either 'function' or 'context'
:)
declare function local:process($doc,
                               $type as xs:string,
                               $name as xs:string,
                               $mappings) as xs:string
{
  let $mapping := $mappings/zorba:mappings
  return 
    if($type = 'function')
    then 
      string-join(
        for $iter in $doc//zorba:iterator
        for $function in $iter/zorba:function
        return 
          if (fn:not($iter/@generateCodegen) or $iter/@generateCodegen eq "true") 
          then 
            (
            if (exists($iter/@preprocessorGuard))
            then
              $iter/@preprocessorGuard
            else
              "",

            local:create-functions($iter, $function),
            $gen:newline,

            if (exists($iter/@preprocessorGuard))
            then
              concat($gen:newline, "#endif", $gen:newline)
            else 
              ""
            )
          else
            ()
        ,
        ""
      )
    else (: 'context' :)
      string-join(('void populate_context_', $name, '(static_context* sctx)',
                   $gen:newline, '{',
                   string-join(for $iter in $doc//zorba:iterator
                               for $function in $iter/zorba:function
                               return 
                                 local:create-context($iter, $function, $mapping),
                               ''),
                   '}'),
                  '')
};

declare function local:propagate($function) as xs:string?
{
  let $xq30 := count($function//zorba:signature[@version eq "3.0"])
  let $xq11 := count($function//zorba:signature[@version eq "1.1"])
  let $sigs := count($function//zorba:signature)
  let $xq10 := ($sigs - $xq30) - $xq11  
  return
    concat(
    if(($xq30 > 0 ) or ($xq11 > 0)) then 
      local:propagateInputToOutput($function,"_3_0") else (),
    if($xq10 >0) then 
      local:propagateInputToOutput($function,"") else ()
    )    
};

(:
 : Generate the propagatesInputToOutput method
 : @param function is the root element for the function whose 
 :        propagatesInputToOutput method is to be generated.
 : @param suffix is "_3_0" is this is a XQuery 3.0 function, "" otherwise
 :
 : This function element can either have a propagatesInputToOutput or
 : propagatesOne attribute. If no such element is present, the default
 : is propagatesInputToOutput="true" is assumed.
 :)
declare function local:propagateInputToOutput($function, $suffix as xs:string) as xs:string
{
  let $name := concat(local:function-name($function), $suffix)
  return
    if (exists($function/@propagatesInputToOutput) and
        exists($function/@propagatesOne))
    then
      fn:error($local:CODEGEN_ERROR, concat("Either propagatesInputToOutput or ",
                                        "propagatesOne can be present in a ",
                                        "function specification") )
    else
      let $param := if (exists($function/@propagatesOne))
                    then "aProducer" else ""
      let $body  := if (exists($function/@propagatesOne))
                    then 
                      concat("return aProducer == ",  $function/@propagatesOne, ';')
                    else 
                      concat("return ", $function/@propagatesInputToOutput, ';')
      return
        if (fn:exists($function/@propagatesInputToOutput) or
            fn:exists($function/@propagesOne))
        then
          concat (
            'bool ', $name, '::propagatesInputToOutput ( ulong ', $param, ') const {',
            $gen:newline,
            $gen:indent, $body,
            $gen:newline,
            '}'
          )
        else
          "" (: inherit from function class :)
};

declare function local:create-functions($iter, $function) as xs:string?
{
  let $xq30 := count($function//zorba:signature[@version eq "3.0"])
  let $xq11 := count($function//zorba:signature[@version eq "1.1"])
  let $sigs := count($function//zorba:signature)
  let $xq10 := ($sigs - $xq30) - $xq11  
  return
    concat(
    if(($xq30 > 0 ) or ($xq11 > 0)) then local:create-function($iter, $function,"_3_0") else (),
    if($xq10 >0) then local:create-function($iter, $function,"") else ()
    )    
};

declare function local:create-function($iter, $function, $suffix as xs:string) as xs:string?
{ 
  if (not($function/@generateCodegen) or $function/@generateCodegen = 'true')
  then
    if (count($function/zorba:signature) = 0)
    then 
      (: TODO user fn:error :)
      'Error: could not find \"prefix\" and \"localname\" attributes for \"zorba:function\" element'
    else
      let $name := concat(local:function-name($function), $suffix)
      let $ret := if($iter/@name = "") then "return NULL;"
                  else string-join(( 'return new ',
                                      local:iterator-call($iter, $function), ';'),'')
      return
        string-join(($gen:newline, 'PlanIter_t ', $name, '::codegen(',
                     $gen:newline, $gen:indent, 'CompilerCB*,',
                     $gen:newline, $gen:indent, 'static_context* sctx,',
                     $gen:newline, $gen:indent, 'const QueryLoc&amp; loc,',
                     $gen:newline, $gen:indent, 'std::vector&lt;PlanIter_t&gt;&amp; argv,',
                     $gen:newline, $gen:indent, 'expr&amp; ann) const',
                     $gen:newline,'{', $gen:newline, $gen:indent, $ret, $gen:newline,'}'), '')
  else
    ''
};


declare function local:function-name($function) as xs:string
{
  let $sig := ($function//zorba:signature)[1]
  return 
    string-join((translate($sig/@prefix, '-', '_'),
                 translate($sig/@localname, '-', '_')),'_')
};


declare function local:iterator-call($iter, $function) as xs:string
{
  concat (
    $iter/@name,

    '(sctx, loc',

    let $arity := lower-case($iter/@arity)
    return
      if ( $arity eq "unary" )
      then
        ', argv[0]'
      else if ( $arity eq "binary" )
      then 
        ', argv[0], argv[1]'
      else if ( $arity eq "noary" )
      then
        ''
      else 
        ', argv',

    if($function/@annIsUpdating = 'true')
    then 
      ', ann.is_updating() )'
    else
      ')'
  )
};

declare function local:createSuffix($signature) as xs:string?
{
  if ($signature/@version eq "1.0") then ""
  else 
    if (($signature/@version eq "3.0") or
        ($signature/@version eq "1.1"))
    then "_3_0"
    else ""
};

declare function local:create-context($iter, $function, $mapping) as xs:string?
{
  if($function/@generateDECL = 'false')
  then
    ()
  else
    string-join(
      for $sig in $function//zorba:signature
      let $is-variadic := exists($sig[@variadic = "true"])
      return 
        string-join(
          ($gen:newline,
           if (exists($iter/@preprocessorGuard))
           then
             concat($gen:newline, $iter/@preprocessorGuard, $gen:newline)
           else 
             "",
           $gen:newline, $gen:newline, gen:indent(2),
           if (exists($sig/@preprocessorGuard))
           then
            concat($gen:newline, $sig/@preprocessorGuard, $gen:newline)
           else
             "",
           $gen:indent,
           '{', $gen:newline, $gen:indent, $gen:indent,

           if ($is-variadic)
           then
             concat (
              'std::vector&lt;xqtref_t> lParamTypes;',
              $gen:newline, gen:indent(2),
              string-join(
                for $param in $sig/zorba:param
                return
                  concat('lParamTypes.push_back(', local:create-zorba-type($param, $mapping), ');'),
                concat($gen:newline, gen:indent(2))
              )
            )
           else
             ""
           ,
           'DECL_WITH_KIND(sctx, ',
             concat(
              local:function-name($function),

              local:createSuffix($sig)), ',',
              $gen:newline, gen:indent(4),

              '(createQName("',
                local:get-zorba-ns($sig/@prefix, $mapping),
                '","","', $sig/@localname,
              '"), ',
              $gen:newline, gen:indent(4),

              if ($is-variadic)
              then
                concat (
                  'lParamTypes, ',
                  local:create-zorba-type($sig/zorba:output, $mapping),
                  ', true'
                )
              else
                string-join ((
                  for $param at $i in $sig/zorba:param
                  return
                    concat(
                      local:create-zorba-type($param, $mapping),
                      if ($i <= count($sig/zorba:param))
                      then
                        ', '
                      else
                        '',
                      $gen:newline, gen:indent(4)
                    ),
                  local:create-zorba-type($sig/zorba:output, $mapping)
                ), ''),
              '),', $gen:newline, gen:indent(4), 
              'FunctionConsts::', gen:function-kind($sig) ,');',
              $gen:newline, $gen:newline, $gen:indent,
            '}', $gen:newline, $gen:newline,
            if (exists($sig/@preprocessorGuard))
            then
             concat($gen:newline, "#endif", $gen:newline)
            else
              "",

             if (exists($iter/@preprocessorGuard))
             then
               concat($gen:newline, "#endif", $gen:newline)
             else 
               ""
            ),
        ''),
      '')
};


declare function local:get-zorba-ns($prefix as xs:string, $mapping) as xs:string
{
  let $tmp := $mapping//zorba:namespace[@prefix=$prefix]
  return 
    if ($tmp)
    then 
      $tmp/@uri
    else  (: TODO user fn:error :)
      'Error: could not find \"prefix\" and \"localname\" attributes for \"zorba:function\" element'  
};


declare function local:create-zorba-type($param, $mapping) as xs:string?
{
  if($param = 'true') then 'true'

  else if ($param eq 'empty-sequence()') then
    'GENV_TYPESYSTEM.EMPTY_TYPE'
    
  else if ($param eq 'none') then
    'GENV_TYPESYSTEM.NONE_TYPE'

  else if($param) then
    let $suffix := if(ends-with($param,'?')) then 'TYPE_QUESTION' 
                   else if(ends-with($param,'+')) then 'TYPE_PLUS'
                   else if(ends-with($param,'*')) then 'TYPE_STAR'
                   else 'TYPE_ONE'                   
    
    let $prefix as xs:string := string($mapping/zorba:types//zorba:type[starts-with($param, text())][1]/@zorbaType)
    
    return string-join (('GENV_TYPESYSTEM.', $prefix, '_', $suffix), '')
  else
    ""
};


let $pieces as xs:string* := tokenize($file,'/')
let $name := substring($pieces[count($pieces)],
                       1,
                       string-length($pieces[count($pieces)])-4)
return
  {
    variable $mappings_doc := fn:parse-xml(file:read-text($mappings));
    variable $file_doc := fn:parse-xml(file:read-text($file));

    string-join((gen:add-copyright(),
                 local:includes($file_doc),
                 'namespace zorba{',
                 local:process-file($file_doc, $name, $mappings_doc),
                 '}',
                 $gen:newline
                ),
                string-join(($gen:newline, $gen:newline),'
')
    )
  }
