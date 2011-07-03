declare namespace zorba = "http://www.zorba-xquery.com";
declare namespace ann = "http://www.zorba-xquery.com/annotations";

import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";
import module namespace file = "http://expath.org/ns/file";

declare %ann:nondeterministic %ann:sequential function local:get-files($files as xs:string) as xs:string
{
  variable $xml-files as xs:string* := tokenize($files,',');

  variable $temp := for $file in $xml-files return local:process-file($file);

  string-join($temp, $gen:newline)
};

declare %ann:nondeterministic %ann:sequential function local:process-file($file) as xs:string
{
  let $doc := fn:parse-xml(file:read-text($file))/zorba:iterators
  
  return string-join(for $iter in $doc//zorba:iterator return 
  if(fn:not($iter/@generateVisitor) or $iter/@generateVisitor eq "true") then
    if(fn:not($iter/@name = "")) then
      local:process-iter($iter)
    else ()
  else ()
  ,$gen:newline)
};

declare function local:process-iter($iter) as xs:string
{
  local:printer-visitor-definition($iter)
};

declare function local:create-class() as xs:string
{
  string-join((
  'void PrinterVisitor::print() {',$gen:newline,
  $gen:indent,'thePrinter.start();',$gen:newline,
  $gen:indent,'theIterator->accept(*this);',$gen:newline,
  $gen:indent,'thePrinter.stop();',$gen:newline,'}',$gen:newline,$gen:newline,
  'void PrinterVisitor::printCommons(const PlanIterator* aIter, int theId) {',$gen:newline,
  $gen:indent,'if (! Properties::instance()->noTreeIds()) {',$gen:newline,
  gen:indent(2),'std::stringstream lStream;',$gen:newline,
  gen:indent(2),'if (Properties::instance()->stableIteratorIds())',$gen:newline,
  gen:indent(3),'lStream << theId;',$gen:newline,
  gen:indent(2),'else',$gen:newline,
  gen:indent(3),'lStream << aIter;',$gen:newline,
  gen:indent(2),'thePrinter.addAttribute("id", lStream.str());',$gen:newline,
  $gen:indent,'}',$gen:newline,'}',$gen:newline,$gen:newline,
  'void PrinterVisitor::printNameOrKindTest(const AxisIteratorHelper* a) {',$gen:newline,
  $gen:indent,'thePrinter.addAttribute("test kind", toString(a->getTestKind()));',$gen:newline,$gen:newline,
  $gen:indent,'if (a->getDocTestKind() != match_no_test)',$gen:newline,
  gen:indent(2),'thePrinter.addAttribute("doc_test_kind", toString(a->getDocTestKind()));',$gen:newline,$gen:newline,
  $gen:indent,'if (a->getQName() != 0)',$gen:newline,
  gen:indent(2),'thePrinter.addAttribute("qname", a->getQName()->show().str());',$gen:newline,
  $gen:indent,'else',$gen:newline,
  gen:indent(2),'thePrinter.addAttribute("qname","*");',$gen:newline,$gen:newline,
  $gen:indent,'if (a->getType() != 0)',$gen:newline,
  gen:indent(2),'thePrinter.addAttribute("typename", a->getType()->toString());',$gen:newline,
  $gen:indent,'else',$gen:newline,
  gen:indent(2),'thePrinter.addAttribute("typename","*");',$gen:newline,$gen:newline,
  $gen:indent,'std::stringstream lStream;',$gen:newline,
  $gen:indent,'lStream << a->nilledAllowed();',$gen:newline,
  $gen:indent,'thePrinter.addAttribute("nill allowed", lStream.str());',$gen:newline,$gen:newline,
  $gen:indent,'if (a->getTargetPos() >= 0)',$gen:newline,
  gen:indent(2),'thePrinter.addAttribute("target_position", ztd::to_string(a->getTargetPos()));',$gen:newline,'}'
  ),'')
};

declare function local:create-includes($files) as xs:string
{
  (: compute the name of the header file to be included.
     take the substring after src/runtime/spec/ and replace
     .xml by .h
   :)
  fn:concat(
    '#include "stdafx.h"',
    $gen:newline, $gen:newline,
    '#include "runtime/visitors/printer_visitor.h"',
    $gen:newline, $gen:newline,
    '// get forward declarations for all classes from planitervisitor.h',
    $gen:newline, $gen:newline,
    '#include "runtime/visitors/planiter_visitor.h"',
    $gen:newline, $gen:newline,
    '#include "runtime/visitors/iterprinter.h"',
    $gen:newline, $gen:newline,
    '#include "system/properties.h"',
    $gen:newline, $gen:newline,
    '#include "util/string_util.h"',
    $gen:newline, $gen:newline,
    string-join(
      for $i in tokenize($files, ',') 
      let $xml-file := fn:replace($i, ".xml", ".h")
      return fn:concat('#include "runtime/', $xml-file, '"'), $gen:newline
    )
  )
};

declare function local:get-include-quoted($include) as xs:string
{
  if(empty($include/@guard)) then
    string-join(('#include "', $include/text(), '"'),'')
    else string-join(($gen:newline,'#ifdef ',$include/@guard,$gen:newline,
    $gen:indent,'#include "', $include/text(), '"',$gen:newline,
    '#endif'),'')
};

declare function local:printer-visitor-definition($iter) as xs:string
{
  concat (
    if ( exists($iter/@preprocessorGuard) )
    then $iter/@preprocessorGuard
    else '',
    $gen:newline,

    string-join(('// &lt;',$iter/@name,'&gt;',$gen:newline,
    'void PrinterVisitor::beginVisit ( const ',$iter/@name,'&amp; a) {',$gen:newline,
    $gen:indent,'thePrinter.startBeginVisit("',$iter/@name,'", ++theId);',$gen:newline,
    $gen:indent,'printCommons( &amp;a, theId );',$gen:newline,
    $gen:indent,'thePrinter.endBeginVisit( theId );',$gen:newline,'}',$gen:newline,
    $gen:newline,'void PrinterVisitor::endVisit ( const ',$iter/@name,'&amp; ) {',$gen:newline,
    $gen:indent,'thePrinter.startEndVisit();',$gen:newline,
    $gen:indent,'thePrinter.endEndVisit();',$gen:newline,'}',$gen:newline,
    '// &lt;/',$iter/@name,'&gt;',$gen:newline),''),

    if ( exists($iter/@preprocessorGuard) )
    then concat($gen:newline, '#endif')
    else ''
  )
};

declare variable $files as xs:string external;

{
  variable $temp := local:get-files($files);

  string-join((gen:add-copyright(),
               local:create-includes($files),
               'namespace zorba{',
               local:create-class(),
               $temp,
               '}'),
              string-join(($gen:newline,$gen:newline),''))
}

