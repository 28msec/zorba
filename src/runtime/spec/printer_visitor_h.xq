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

declare namespace zorba = "http://www.zorba-xquery.com";
declare namespace ann = "http://zorba.io/annotations";

import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";
import module namespace file = "http://expath.org/ns/file";

declare %ann:nondeterministic function local:get-files($files as xs:string) as xs:string
{
  variable $xml-files as xs:string* := tokenize($files,',');
  variable $temp := for $file in $xml-files
                   return local:process-file($file);

  string-join($temp, concat($gen:newline, $gen:newline))
};


declare %ann:nondeterministic function local:process-file($file) as xs:string
{
  let $doc := fn:parse-xml(file:read-text($file))/zorba:iterators
  return
    string-join (
      for $iter in $doc//zorba:iterator
      return 
          if(fn:not($iter/@name = "")) then
            local:process-iter($iter)
          else (),
    concat($gen:newline, $gen:newline))
};

declare function local:process-iter($iter) as xs:string
{
  concat (
    if ( exists($iter/@preprocessorGuard) )
    then concat($iter/@preprocessorGuard, $gen:newline)
    else '',

    string-join((gen:indent(2),'void beginVisit( const ',$iter/@name,'&amp; );',$gen:newline,
    gen:indent(2),'void endVisit  ( const ',$iter/@name,'&amp; );'),''),

    if ( exists($iter/@preprocessorGuard) )
    then concat($gen:newline, '#endif')
    else ''
  )
};

declare function local:create-class() as xs:string
{
  concat(
    $gen:indent, "class PrinterVisitor : public PlanIterVisitor {", $gen:newline,
    $gen:indent, 'private:', $gen:newline,
    gen:indent(2),'IterPrinter&amp; thePrinter;',$gen:newline,
    gen:indent(2),'PlanIterator* theIterator;',$gen:newline,
    gen:indent(2),'PlanState* thePlanState;',$gen:newline,
    gen:indent(2),'int theId;',$gen:newline,
    $gen:indent,'public:',$gen:newline,
    gen:indent(2),'PrinterVisitor(IterPrinter&amp; aPrinter, PlanIterator* aIter, PlanState *state = 0 )',$gen:newline,
    gen:indent(2),':',
    gen:indent(2),'thePrinter(aPrinter), theIterator(aIter), thePlanState( state ), theId(0) {}',$gen:newline,$gen:newline,
    gen:indent(2),'PlanState* getPlanState() const { return thePlanState; }',$gen:newline,
    gen:indent(2),'void setPlanState( PlanState *s ) { thePlanState = s; }',$gen:newline,
    gen:indent(2),'void print();',$gen:newline,
    gen:indent(2),'bool hasToVisit(PlanIterator const *pi);',$gen:newline,
    $gen:indent,'private:',$gen:newline,
    gen:indent(2),'void printCommons(const PlanIterator* aIter, int theId);',$gen:newline,
    gen:indent(2),'template<class T>', $gen:newline,
    gen:indent(2),'void printVarRefs( const char* name, std::vector<T> const &amp;values );', $gen:newline, $gen:newline,
    $gen:indent,'public:',$gen:newline, $gen:newline,
    (: temporarily included until all iterators are generated :)
    '#include "runtime/visitors/plan_iter_visitor_impl.h"'
  )
};

declare function local:create-fwd-decl() as xs:string
{
  concat(
    $gen:indent, 'class PlanIterator;', $gen:newline,
    $gen:indent, 'class PlanState;',    $gen:newline,
    $gen:indent, 'class IterPrinter;',  $gen:newline
  )
};

(: list all files that need to be included :)
declare function local:create-includes() as xs:string
{
  fn:concat(
    '#include "runtime/visitors/planiter_visitor.h"', $gen:newline, 
    '#include "common/common.h"', $gen:newline,
    '#include "zorba/function.h"', $gen:newline, $gen:newline
  )
};

declare variable $files as xs:string external;

{
  variable $temp := local:get-files($files);

  string-join((gen:add-copyright(),
               gen:add-guard-open('runtime_printer_visitor'),
               local:create-includes(),
               'namespace zorba {',
                 local:create-fwd-decl(),
                 local:create-class(),
                 $temp,
                 string-join(($gen:indent,
                 '}; //class PrinterVisitor',
               $gen:newline,
               '} //namespace zorba',$gen:newline),''),
              gen:add-guard-close()),
              string-join(($gen:newline,$gen:newline),''))
}

(: vim:set et sw=2 ts=2: :)
