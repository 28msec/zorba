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
declare namespace ann = "http://www.zorba-xquery.com/annotations";

import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";
import module namespace file = "http://expath.org/ns/file";


declare function local:create-include() as xs:string
{
  string-join((
  '#include <vector>',$gen:newline,
  '#include "common/common.h"',$gen:newline,
  '#include "zorbatypes/zorbatypes_decl.h"',$gen:newline,
  '#include "types/typeconstants.h"',$gen:newline,
  '#include "zorbatypes/rchandle.h"',$gen:newline,
  '#include "zorbatypes/zstring.h"',$gen:newline
  ),'')
};


declare function local:create-class() as xs:string
{
  string-join(('/**',$gen:newline,
  ' * Visitor to visit a PlanIterator tree.',$gen:newline,
  ' */',$gen:newline,
  'class PlanIterVisitor {',$gen:newline,
  'public:',$gen:newline,
  '  virtual ~PlanIterVisitor() {}',$gen:newline,$gen:newline,
  '#include "runtime/visitors/planiter_visitor_impl_code.h"'),'')
};
 

(:type can be 'fwd-decl' or 'class' :)
declare %ann:nondeterministic %ann:sequential function local:process-files(
    $files as xs:string, 
    $type as xs:string) as xs:string
{
  variable $xml-files as xs:string* := tokenize($files,',');

  variable $temp := for $file in $xml-files return local:process-file($file, $type);

  string-join($temp, $gen:newline)
};


declare %ann:nondeterministic %ann:sequential function local:process-file($file, $type as xs:string) as xs:string
{
  let $doc := fn:parse-xml(file:read-text($file))/zorba:iterators

  return string-join(for $iter in $doc//zorba:iterator return 
  if(fn:not($iter/@generateVisitor) or $iter/@generateVisitor eq "true") then
    if(fn:not($iter/@name = "")) then
      local:process-iter($iter, $type)
    else ()
  else ()
  ,$gen:newline)
};


declare function local:process-iter($iter, $type as xs:string) as xs:string
{
  concat (
    if ( exists($iter/@preprocessorGuard) )
    then concat($iter/@preprocessorGuard, $gen:newline)
    else '',

    if($type = 'class') then
      string-join((gen:indent(2),'virtual void beginVisit ( const ',$iter/@name,'&amp; ) = 0;',$gen:newline,
      gen:indent(2),'virtual void endVisit   ( const ',$iter/@name,'&amp; ) = 0;'),'')
    else
      string-join((gen:indent(2),'class ',$iter/@name,';'),''),

    $gen:newline,
    if ( exists($iter/@preprocessorGuard) )
    then '#endif'
    else ''
  )
};

declare %ann:nondeterministic %ann:sequential function local:create-fwd-decl($files as xs:string) as xs:string
{
  variable $temp := local:process-files($files,'fwd-decl');

  string-join(($temp, $gen:newline, $gen:newline,
               '#include "runtime/visitors/planiter_visitor_impl_include.h"'),'')
};


declare variable $files as xs:string external;

{
  variable $temp1 := local:create-fwd-decl($files);

  variable $temp2 := local:process-files($files,'class');

  string-join
  (
    (
      gen:add-copyright(),
      gen:add-guard-open('runtime_visitors_plan_iter_visitor'),
      local:create-include(),
      'namespace zorba{',
      $temp1,
      local:create-class(),
      $temp2,
      string-join
      (
        (
          $gen:indent,
          '}; //class PlanIterVisitor',
          $gen:newline,
          '} //namespace zorba', 
          $gen:newline
        ),
        ''
      ),
      gen:add-guard-close(),
      $gen:newline
    ),
    string-join(($gen:newline),'
  ')
  )
}

