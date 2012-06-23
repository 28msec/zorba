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

declare function local:includes($doc) as xs:string
{
  string-join(
    (
      '#include "common/shared_types.h"',
      '#include "functions/function_impl.h"',
      for $include in $doc//zorba:codegen/zorba:h/zorba:include[@form='Angle-bracket']
      return 
        concat('#include <', $include/text(), '>'),

      for $include in $doc//zorba:codegen/zorba:h/zorba:include[@form='Quoted'] 
      return
        concat('#include "', $include/text(), '"')
    ),
    $gen:newline
  )
};


declare function local:add-populate($name as xs:string) as xs:string
{
  concat('void populate_context_', $name, '(static_context* sctx);')
};


declare function local:process-file($doc) as xs:string
{
  string-join(for $iter in $doc//zorba:iterator
              for $function in $iter/zorba:function 
              return local:create-function($iter, $function), $gen:newline)
};

declare function local:create-func-version($signature) as xs:string?
{
  if ($signature/@version eq "1.0")
  then concat($gen:newline, $gen:indent, $gen:indent, "theXQueryVersion = StaticContextConsts::xquery_version_1_0;")
  else 
    if ($signature/@version eq "3.0")
    then concat($gen:newline, $gen:indent, $gen:indent, "theXQueryVersion = StaticContextConsts::xquery_version_3_0;")
    else ()    
};

declare function local:create-function-arity($iter, $function, $funcVersion as xs:string) as xs:string?
{
  let $name := concat(local:function-name($function), 
               if(ends-with($funcVersion,"3_0;")) then "_3_0"
               else ())
  return
    string-join(
    (
    if ( exists($iter/@preprocessorGuard) )
    then
      $iter/@preprocessorGuard
    else
      "",
  
    $gen:newline, $gen:newline,
    local:description($function),
    $gen:newline,
  
    'class ', $name, ' : public ', local:base-class($function),
  
    $gen:newline, '{',  $gen:newline,
  
    'public:', $gen:newline, $gen:indent,
  
    let $setNoneDeterministic := if ($function/@isDeterministic = 'false')
                                 then 
                                   "setDeterministic(false);&#xA;"
                                 else ""
    return 
      concat($name, '(const signature&amp; sig, FunctionConsts::FunctionKind kind)',
             $gen:newline, $gen:indent,
             $gen:indent, ': ',
             $gen:newline, $gen:indent, $gen:indent,
             local:base-class($function), 
             '(sig, kind)',
             $gen:newline, $gen:indent,
             '{&#xA;', $setNoneDeterministic, $funcVersion, '&#xA;', $gen:indent, '}'),
  
  $gen:newline,
        
  local:add-specialization($function),
  local:add-methods($function),
  $gen:newline,
  
  $gen:indent, 'CODEGEN_DECL();', $gen:newline,
  
  '};',
  
  if ( exists($iter/@preprocessorGuard) )
  then
    concat($gen:newline, "#endif")
  else ""
  )
  , '')
};

declare function local:create-function-XQuery-30($iter, $function) as xs:string?
{
  let $xq30 := count($function//zorba:signature[@version eq "3.0"])
  let $sigs := count($function//zorba:signature)
  let $xq10 := ($sigs - $xq30)
  return
    concat(
    if ($xq30 > 0 ) then
       local:create-function-arity( $iter, 
                                    $function,
                                    "theXQueryVersion = StaticContextConsts::xquery_version_3_0;")
    else (),
    if($xq10 >0) then
      local:create-function-arity($iter, 
                                  $function,
                                  "")
    else ()
    )    
};

declare function local:create-function($iter, $function) as xs:string?
{ 
  if (fn:not($iter/@generateCodegen) or $iter/@generateCodegen eq "true") 
  then
    if(count($function/zorba:signature) = 0)
    then
      (: TODO user fn:error :)
      'Error: could not find \"prefix\" and \"localname\" attributes for \"zorba:function\" element'
    else
      local:create-function-XQuery-30($iter, $function)
      (: local:create-function-arity($iter, $function, xs:integer(1)) :)
  else
    ()
};


declare function local:function-name($function) as xs:string
{
  let $sig := ($function//zorba:signature)[1]
  return 
    if($sig/@prefix = 'fn' and starts-with(string($sig/@localname), ':')) 
    then
      string-join(('op',
                   translate(substring(string($sig/@localname),2),'-','_')
                  ),'_')
    else
      string-join((translate($sig/@prefix,'-','_'),
                   translate($sig/@localname,'-','_')
                  ),'_')
};


declare function local:description($function) as xs:string
{
  let $sig := ($function//zorba:signature)[1]
  return 
    if(fn:not($sig/@prefix) or fn:not($sig/@localname))
    then 
      ''
    else
      string-join(('//',
                   if( $sig/@prefix = 'fn' and starts-with(string($sig/@localname),':')) 
                   then 
                     string-join(('op', $sig/@localname), '') 
                   else
                     string-join(($sig/@prefix, ':', $sig/@localname), '')
                  ), '')
};


declare function local:base-class($function)
{
  if(not($function/@baseSig)) then
    'function'
  else
    $function/@baseSig 
};


declare function local:add-methods($function) as xs:string*
{
  if (count($function//zorba:methods) > 0) 
  then
    for $meth in $function//zorba:methods/child::*
    return
      if (name($meth) eq 'zorba:getReturnType')
      then
        string-join(($gen:newline, $gen:indent,
                     'xqtref_t getReturnType(const fo_expr* caller) const;',
                     $gen:newline), '')

      else if (name($meth) eq 'zorba:getScriptingKind')
      then
        string-join(($gen:newline, $gen:indent,
                     'unsigned short getScriptingKind() const ',
                     '{ return ', $meth/@returnValue, '; }',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:specializable')
      then
        string-join(($gen:newline, $gen:indent,
                     'bool serializable() const ',
                     '{ return true; }',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:accessesDynCtx')
      then
        string-join(($gen:newline, $gen:indent,
                     'bool accessesDynCtx() const ',
                     '{ return ', $meth/@returnValue, '; }',
                     $gen:newline),'')

      else if (name($meth) eq 'zorba:isSource')
      then
        string-join(($gen:newline, $gen:indent,
                     'bool isSource() const ',
                     '{ return ', $meth/@returnValue, '; }',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:isMap')
      then
        string-join(($gen:newline, $gen:indent,
                     'bool isMap(csize producer) const ',
                     '{ return producer == ', $meth/@producer, '; }',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:producesDistinctNodes')
      then
        string-join(($gen:newline, $gen:indent,
                     'FunctionConsts::AnnotationValue producesDistinctNodes() const ',
                     $gen:newline, $gen:indent, '{',
                     $gen:newline, gen:indent(2),
                     'return FunctionConsts::', $meth/@returnValue, ';',
                     $gen:newline, $gen:indent, '}',
                     $gen:newline),'')

      else if (name($meth) eq 'zorba:producesSortedNodes')
      then
        string-join(($gen:newline, $gen:indent,
                     'FunctionConsts::AnnotationValue producesSortedNodes() const ',
                     $gen:newline, $gen:indent, '{',
                     $gen:newline, gen:indent(2),
                     'return FunctionConsts::', $meth/@returnValue, ';',
                     $gen:newline, $gen:indent, '}',
                     $gen:newline),'')

      else if (name($meth) eq 'zorba:propagatesDistinctNodes')
      then
        string-join(($gen:newline, $gen:indent,
                     'bool propagatesDistinctNodes(csize producer) const ',
                     '{ return producer == ', $meth/@producer, '; }',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:propagatesSortedNodes')
      then
        string-join(($gen:newline, $gen:indent,
                     'bool propagatesSortedNodes(csize producer) const ',
                     '{ return producer == ', $meth/@producer, '; }',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:ignoresSortedNodes')
      then
        string-join(($gen:newline, $gen:indent,
                     'BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:ignoresDuplicateNodes')
      then
        string-join(($gen:newline, $gen:indent,
                     'BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:propagatesInputNodes')
      then
        if ($meth/@producer)
        then
        string-join(($gen:newline, $gen:indent,
                     'bool propagatesInputNodes(expr* fo, csize producer) const ',
                     '{ return producer == ', $meth/@producer, '; }',
                     $gen:newline),'')
        else if ($meth/@value)
        then
        string-join(($gen:newline, $gen:indent,
                     'bool propagatesInputNodes(expr* fo, csize producer) const ',
                     '{ return ', $meth/@value, '; }',
                     $gen:newline),'')
        else
        string-join(($gen:newline, $gen:indent,
                     'bool propagatesInputNodes(expr* fo, csize producer) const;',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:mustCopyInputNodes')
      then
        if ($meth/@producer)
        then
        string-join(($gen:newline, $gen:indent,
                     'bool mustCopyInputNodes(expr* fo, csize producer) const ',
                     '{ return producer == ', $meth/@producer, '; }',
                     $gen:newline),'')
        else if ($meth/@value)
        then
        string-join(($gen:newline, $gen:indent,
                     'bool mustCopyInputNodes(expr* fo, csize producer) const ',
                     '{ return ', $meth/@value, '; }',
                     $gen:newline),'')
        else
        string-join(($gen:newline, $gen:indent,
                     'bool mustCopyInputNodes(expr* fo, csize producer) const;',
                     $gen:newline),'')
      else
        ()
  else
    ()
};



declare function local:add-specialization($function) as xs:string?
{
  if ($function/@specializable = 'true') 
  then    
    string-join(($gen:newline, $gen:indent,
                 'bool specializable() const { return true; }',
                 $gen:newline, $gen:newline, $gen:indent,
                 'function* specialize( static_context* sctx,',
                 $gen:newline, gen:indent(12),
                 'const std::vector&lt;xqtref_t&gt;&amp; argTypes) const;',
                 $gen:newline),'')
  else 
    ()
};


(:
   Variable $file will be bound to the pathname of the xml file that is to
   be converted to a .h file
:)
declare variable $file as xs:string external;
declare variable $doc := "";


declare variable $files external;


let $pieces as xs:string* := tokenize($file,'/')
let $name := substring($pieces[count($pieces)],1,string-length($pieces[count($pieces)])-4)
return
  {
    variable $doc := fn:parse-xml(file:read-text($file))/zorba:iterators;
    string-join((gen:add-copyright(),
                 $gen:newline,
                 gen:add-guard-open(string-join(('functions_',$name),'')),
                 $gen:newline,
                 local:includes($doc),
                 $gen:newline,
                 'namespace zorba {',
                 $gen:newline,
                 local:add-populate($name),
                 $gen:newline,
                 local:process-file($doc),
                 $gen:newline,
                 '} //namespace zorba',
                 $gen:newline,
                 gen:add-guard-close(),
                 '/*',
                 ' * Local variables:',
                 ' * mode: c++',
                 ' * End:',
                 ' */'),
                $gen:newline),
    $gen:newline
  }
