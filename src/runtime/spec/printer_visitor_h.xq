declare namespace zorba="http://www.zorba-xquery.com";

import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";

declare function local:get-files($files as xs:string) as xs:string
{
  let $xml-files as xs:string* := tokenize($files,';') 
  return string-join(for $file in $xml-files return local:process-file($file),$gen:newline)
};

declare function local:process-file($file) as xs:string
{
  let $doc := fn:doc($file)/zorba:iterators
  
  return string-join(for $iter in $doc//zorba:iterator return 
  if(fn:not($iter/@generateVisitor) or $iter/@generateVisitor eq "true") then
    local:process-iter($iter)
  else ()
  ,string-join(($gen:newline,$gen:newline),''))
};

declare function local:process-iter($iter) as xs:string
{
  string-join((gen:indent(2),'void beginVisit( const ',$iter/@name,'&amp; );',$gen:newline,
  gen:indent(2),'void endVisit  ( const ',$iter/@name,'&amp; );'),'')
};

declare function local:create-class() as xs:string
{
  concat(
    $gen:indent, "class PrinterVisitor : public PlanIterVisitor {", $gen:newline,
    $gen:indent, 'private:', $gen:newline,
    gen:indent(2),'IterPrinter&amp; thePrinter;',$gen:newline,
    gen:indent(2),'PlanIterator* theIterator;',$gen:newline,
    gen:indent(2),'int theId;',$gen:newline,
    $gen:indent,'public:',$gen:newline,
    gen:indent(2),'PrinterVisitor(IterPrinter&amp; aPrinter, PlanIterator* aIter)',$gen:newline,
    gen:indent(2),':',
    gen:indent(2),'thePrinter(aPrinter), theIterator(aIter), theId(0) {}',$gen:newline,$gen:newline,
    gen:indent(2),'void print();',$gen:newline,
    gen:indent(2),'void printCommons(const PlanIterator* aIter, int theId);',$gen:newline, $gen:newline,
    (: temporarily included until all iterators are generated :)
    '#include "runtime/visitors/printer_visitor_impl.h"'
  )
};

declare function local:create-fwd-decl() as xs:string
{
  string-join(($gen:indent, 'class PlanIterator;', $gen:newline,
  $gen:indent,'class IterPrinter;'),'')
};

(: list all files that need to be included :)
declare function local:create-includes() as xs:string
{
  fn:concat(
    '#include "runtime/visitors/planiter_visitor.h"',
    $gen:newline, $gen:newline,
    '#include "common/common.h"'
  )
};

declare variable $files as xs:string external;

string-join((gen:add-copyright(),
             gen:add-guard-open('runtime_printer_visitor'),
             local:create-includes(),
             'namespace zorba {',
               local:create-fwd-decl(),
               local:create-class(),
               local:get-files($files),
               string-join(($gen:indent,
               '}; //class PrinterVisitor',
             $gen:newline,
             '} //namespace zorba',$gen:newline),''),
            gen:add-guard-close()),
            string-join(($gen:newline,$gen:newline),''))
