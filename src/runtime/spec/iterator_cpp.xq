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

declare function local:get-iterators($XMLdoc) as xs:string
{
  string-join(
  for $iter in $XMLdoc//zorba:iterator 
  return
    if($iter/@name = "") then ()
    else local:process-iterator($iter)
  ,$gen:newline)
};

declare function local:process-iterator($iter) as xs:string
{
  string-join ((
    if ( exists($iter/@preprocessorGuard) )
    then
      concat($iter/@preprocessorGuard, $gen:newline)
    else '',

    '// &lt;',$iter/@name,'&gt;',$gen:newline,
    local:serializable-class-versions($iter/@name),

    (: generate the visitor if requested :)
    if(fn:not($iter/@generateAccept) or $iter/@generateAccept eq "true") 
    then
      concat(local:generate-accept($iter), $gen:newline)
    else
      (),

    (: generate the destructor if requested :)
    if(fn:not($iter/@generateDestructor) or $iter/@generateDestructor eq "true") 
    then 
      local:generate-destructor($iter)
    else (),

    if (exists($iter/zorba:state))
    then
      (
      (: explicitly instantiate the state's con- and destructor to avoid potential memory leaks and
         remove unnecessary includes :)
      if (fn:not($iter/zorba:state/@generateConstructor) or
          $iter/zorba:state/@generateConstructor eq "true")
      then
        local:state-constructor($iter) 
      else (),

      if (fn:not($iter/zorba:state/@generateDestructor) or
          $iter/zorba:state/@generateDestructor eq "true")
      then
        local:state-destructor($iter) 
      else (),

      (: generate the state's init and reset functions if requested :)
      if (fn:not($iter/zorba:state/@generateInit) or $iter/zorba:state/@generateInit eq "true")
      then
        if(exists($iter/zorba:state/@baseClassName)) then
          local:generate-init($iter,string($iter/zorba:state/@baseClassName))
        else
          local:generate-init($iter,'PlanIteratorState')
      else (),

      if (fn:not($iter/zorba:state/@generateReset) or $iter/zorba:state/@generateReset eq "true")
      then
        if(exists($iter/zorba:state/@baseClassName)) then
          local:generate-reset($iter,string($iter/zorba:state/@baseClassName))
        else
          local:generate-reset($iter,'PlanIteratorState')
      else ()
      )
    else (),

    (: finish iterator implementation with a closing comment :)
    '// &lt;/',$iter/@name,'&gt;',$gen:newline,$gen:newline,

    if ( exists($iter/@preprocessorGuard) )
    then
      '#endif'
    else ''),
  '')
};

declare function local:generate-init-values($state) 
{
  for $member in $state//zorba:member
  return 
    if (exists($member/@defaultValue))
    then
      concat($gen:indent, string($member/@name), ' = ', string($member/@defaultValue), ';', $gen:newline)
    else ()
};

declare function local:state-destructor($iter) as xs:string
{
  let $name := fn:concat($iter/@name, "State")
  return fn:concat($name, "::~", $name, "() {}", $gen:newline, $gen:newline)
};

declare function local:state-constructor($iter) as xs:string
{
  let $name := fn:concat($iter/@name, "State")
  return fn:concat($name, "::", $name, "() {}", $gen:newline, $gen:newline)
};

declare function local:generate-destructor($iter) as xs:string
{
  fn:concat($iter/@name, "::~", $iter/@name, "() {}", $gen:newline, $gen:newline)
};

declare function local:generate-reset($iter, $baseClassName as xs:string) as xs:string
{
  string-join(($gen:newline,'void ',string($iter/@name),'State::reset(PlanState&amp; planState) {',$gen:newline,
  $gen:indent,$baseClassName,'::reset(planState);',$gen:newline,
  local:generate-init-values($iter/zorba:state),'}',$gen:newline
  ),'')
};

declare function local:generate-init($iter, $baseClassName as xs:string) as xs:string
{
  string-join(($gen:newline,'void ',string($iter/@name),'State::init(PlanState&amp; planState) {',$gen:newline,
  $gen:indent,$baseClassName,'::init(planState);',$gen:newline,
  local:generate-init-values($iter/zorba:state),'}',$gen:newline
  ),'')
};

declare function local:generate-accept($iter) as xs:string
{
  string-join(( $gen:newline,
    'void ',$iter/@name,'::accept(PlanIterVisitor&amp; v) const {',
    $gen:newline,
    $gen:indent,'v.beginVisit(*this);',
    $gen:newline,$gen:newline,
    $gen:indent,

    let $arity := lower-case($iter/@arity)
    return (
      if ( $arity eq "unary" )
      then
        'theChild->accept(v);'
      else if ( $arity eq "binary" )
      then concat(
        'theChild0->accept(v);',
        $gen:newline,
        'theChild1->accept(v);'
      )
      else if ( $arity eq "noary" )
      then ''
      else concat(
        'std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();',$gen:newline,
        $gen:indent,'std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();',$gen:newline,
        $gen:indent,'for ( ; lIter != lEnd; ++lIter ){',$gen:newline,
        $gen:indent,$gen:indent,'(*lIter)->accept(v);',$gen:newline,
        $gen:indent,'}'
      )
    ),
    $gen:newline, $gen:newline,
    $gen:indent,'v.endVisit(*this);',$gen:newline,'}',
    $gen:newline
  ), '')
};

declare function local:get-include($XMLdoc, $name) as xs:string*
{
  fn:concat(
    '#include "stdafx.h"', $gen:newline, 
    '#include "zorbatypes/rchandle.h"', $gen:newline, 
    '#include "zorbatypes/zstring.h"', $gen:newline, 
    '#include "runtime/visitors/planiter_visitor.h"', $gen:newline, 
    '#include "', $name, '.h"', $gen:newline,
    '#include "system/globalenv.h"',
    string-join(($gen:newline,for $include in $XMLdoc//zorba:source/zorba:include[@form='Angle-bracket']
      return concat($gen:newline,'#include <', $include/text(), '>')), ''
    ),
    string-join(($gen:newline,for $include in $XMLdoc//zorba:source/zorba:include[@form='Quoted'] 
      return concat($gen:newline,'#include "', $include/text(), '"')), ''
    )
  )
};


declare function local:serializable-class-versions($name as xs:string) as xs:string
{
  string-join(
     ($name, '::class_factory<', $name, '>', $gen:newline, $name, '::g_class_factory;',
       $gen:newline, $gen:newline)
      ,'')
};


declare variable $files external;

declare variable $input external;
declare variable $name as xs:string external;

string-join
(
  (
    gen:add-copyright(),
    local:get-include($input, $name),
    'namespace zorba {',
    local:get-iterators($input),
    '}',
    $gen:newline
  ),
  string-join(($gen:newline,$gen:newline),'')
)
