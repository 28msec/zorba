declare namespace zorba="http://www.zorba-xquery.com";

import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";

declare function local:get-iterators($XMLdoc) as xs:string
{
  (: generate the declaration for all iterators separated by a newline :)
  string-join (
    for $iter in $XMLdoc//zorba:iterator
    return
      local:process-iterator($iter),
  $gen:newline )
};

declare function local:process-iterator($iter) as xs:string
{
  (: name of the state or PlanIteratorState if no explicit state is required :)
  let $stateName as xs:string := 
    if(exists($iter/zorba:state))
    then
      concat($iter/@name, 'State')
    else
      'PlanIteratorState'
  return concat(
    if ( exists($iter/@preprocessorGuard) )
    then
      concat($iter/@preprocessorGuard, $gen:newline)
    else "",

    (: preceding comment; prefixed with *'s :)
    '/**', $gen:newline,
    ' * ',
    fn:replace($iter/zorba:description/text(), 
               "\n",
               "
 *"),
    $gen:newline, 
    ' * ', "Author: ", fn:normalize-space($iter/zorba:description/@author),
    $gen:newline,
    ' */', $gen:newline,

    (: generate an explicit state if required :)
    if (exists($iter/zorba:state))
    then
      local:process-state($iter/zorba:state, $stateName)
    else (),

    (: generate the iterator declaration :)
    local:iterator($iter, $iter/@name, $stateName),

    if ( exists($iter/@preprocessorGuard) )
    then
      concat("#endif", $gen:newline)
    else ""

  ) (: concat :)
};

declare function local:process-state($state, $stateName as xs:string) as xs:string
{
  string-join(('class ',$stateName,' : public PlanIteratorState',$gen:newline, '{', $gen:newline,
  if(exists($state//zorba:member)) then 'public:' else (),
  string-join(($gen:newline,for $member in $state//zorba:member return 
  string-join(($gen:indent,string($member/@type),' ',string($member/@name),'; //',string($member/@brief),$gen:newline),''))
  ,''),$gen:newline,

  concat($gen:indent, $stateName, '();', $gen:newline, $gen:newline),

  concat($gen:indent, '~', $stateName, '();', $gen:newline, $gen:newline),

  (: generate init and reset decl :)
  concat($gen:indent,'void init(PlanState&amp;);',$gen:newline,
         $gen:indent,'void reset(PlanState&amp;);',$gen:newline),
  '};',$gen:newline, $gen:newline),'')
};

declare function local:arity($iter) as xs:string
{
  let $arity := lower-case($iter/@arity)
  return
    if ( $arity eq "unary" )
    then 'Unary'
    else if ( $arity eq "binary" )
    then 'Binary'
    else if ( $arity eq "noary" )
    then 'Noary'
    else 'Nary'
};

declare function local:children-decl($iter) as xs:string
{
  let $arity := lower-case($iter/@arity)
  return
    if ( $arity eq "unary" )
      then concat(',', $gen:newline, gen:indent(2), 'PlanIter_t&amp; child')
    else if ( $arity eq "binary" )
      then concat(',', $gen:newline, gen:indent(2), 'PlanIter_t&amp; child1, PlanIter_t&amp; child2')
    else if ( $arity eq "noary" )
    then ''
    else concat(',', $gen:newline, gen:indent(2), 'std::vector<PlanIter_t>&amp; children')
  
};

declare function local:children-args($iter) as xs:string
{
  let $arity := lower-case($iter/@arity)
  return
    if ( $arity eq "unary" )
    then ', child'
    else if ( $arity eq "binary" )
    then ', child1, child2'
    else if ( $arity eq "noary" )
    then ''
    else ', children'
  
};
declare function local:constructor($iter, $name as xs:string, $base as xs:string) as xs:string
{
  concat(
    gen:indent(), $name, '(',
    $gen:newline,
    gen:indent(2), 'static_context* sctx,',
    $gen:newline,
    gen:indent(2), 'const QueryLoc&amp; loc',
    local:children-decl($iter),
    local:add-constructor-param($iter),
    ')',
    $gen:newline, gen:indent(2), ': ',
    $gen:newline, gen:indent(2), $base, '(sctx, loc', local:children-args($iter),
    local:add-constructor-param-2($iter),
    $gen:newline, gen:indent(1), '{}',
    $gen:newline, $gen:newline
  )
};


declare function local:iterator($iter, $name as xs:string, $state as xs:string) as xs:string
{
  let $base := concat(local:arity($iter), 'BaseIterator<', $name, ', ', $state, '>')
  return
    concat ( 'class ', $name, ' : ', 'public ', $base,
             $gen:newline, '{ ',
             $gen:newline,

    local:add-protected($iter),

    (: begin serialization, TODO: move implementation to cpp file :)
    'public:',
    $gen:newline, 
    gen:indent(), 'SERIALIZABLE_CLASS(',$name,');',
    $gen:newline, $gen:newline,
    gen:indent(), 'SERIALIZABLE_CLASS_CONSTRUCTOR2T(', $name,',',
    $gen:newline,
    gen:indent(2), $base, ');', $gen:newline, $gen:newline,
    gen:indent(), 'void serialize(::zorba::serialization::Archiver&amp; ar)',
    if ( not(exists($iter/@generateSerialize)) or
         $iter/@generateSerialize eq 'true')
    then concat(
      $gen:newline,
      gen:indent(), '{',
      $gen:newline,
      gen:indent(2), 'serialize_baseclass(ar,',
      $gen:newline,
      gen:indent(2),'(', $base, '*)this);',
      $gen:newline,
      local:add-arch($iter),
      gen:indent(),'}'
    )
    else ";",
    $gen:newline, $gen:newline,
    (: end serialization :)

    local:constructor($iter, $name, $base),

    local:add-destructor($iter),
    local:add-getter($iter),
    local:add-setter($iter),
    $gen:indent,'void accept(PlanIterVisitor&amp; v) const;',$gen:newline,$gen:newline,
    $gen:indent,'bool nextImpl(store::Item_t&amp; result, PlanState&amp; aPlanState) const;',$gen:newline,'};',$gen:newline,$gen:newline
    )
};


declare function local:add-destructor($iter) as xs:string?
{
  fn:concat($gen:indent, "virtual ~", $iter/@name, "();", $gen:newline, $gen:newline)
};

declare function local:add-getter($iter) as xs:string?
{
  if (count($iter/zorba:member) > 0) then 
  string-join(for $member in $iter/zorba:member return
  if(exists($member/@getterName)) then
  string-join(($gen:indent,$member/@type,' ',$member/@getterName,'() const { return ',$member/@name,'; }',$gen:newline,$gen:newline),'')
  else () ,'') else ()
};


declare function local:add-setter($iter) as xs:string?
{
  if (count($iter/zorba:member) > 0)
  then 
    string-join(for $member in $iter/zorba:member 
                return
                  if(exists($member/@setterName)) 
                  then
                    string-join(($gen:indent, 'void ', $member/@setterName,
                                 '(', $member/@type, ' aValue) { ',
                                 $member/@name, '= aValue; }', $gen:newline, 
                                 $gen:newline),'')
                  else
                    () ,
                '')
  else
    ()
};


declare function local:add-constructor-param-2($iter) as xs:string?
{
  let $member := $iter/zorba:member
  let $param := $iter/zorba:constructor/zorba:parameter
  return 
    if (count($member) > 0)
    then
      string-join((')',
                   for $i in (1 to count($member)) 
                   return
                     string-join((',', $gen:newline, gen:indent(2),
                                  $member[$i]/@name, '(', $param[$i]/@name, ')'
                                 ),'')
                  ),'')
  else 
    ')'
};


declare function local:add-constructor-param($iter) as xs:string?
{
  if (count($iter/zorba:constructor/zorba:parameter > 0))
  then
    string-join((for 
                   $param in
                   $iter/zorba:constructor/zorba:parameter
                 return
                   string-join((',', $gen:newline, gen:indent(2),
                                $param/@type, ' ', $param/@name,
                                if (exists($param/@defaultValue) and
                                    $param/@defaultValue ne '')
                                then
                                string-join((' = ',$param/@defaultValue),'')
                                else
                                ()
                               ),'')
                ),'')
  else 
    ()
};


declare function local:add-protected($iter) as xs:string?
{
  if(count($iter/zorba:member) > 0) then
  string-join(('protected:',$gen:newline,for $member in $iter/zorba:member return 
  string-join(($gen:indent,$member/@type,' ',$member/@name,'; //',$member/@brief,$gen:newline),'')),'')
  else ()
};


declare function local:add-arch($iter) as xs:string?
{
  if(count($iter/zorba:member) > 0) then
    string-join(($gen:newline,
                 for $member in $iter/zorba:member
                 return 
                 string-join((gen:indent(2),
                              'ar &amp; ',
                              $member/@name,
                              ';',
                              $gen:newline),'')),
                '')
  else ()
};

declare function local:get-decl($XMLdoc, $ns as xs:string) as xs:string
{
  string-join(for $tmp in $XMLdoc//zorba:fwd-decl[@ns=$ns]
  return string-join((if ($ns ne 'zorba') then $gen:indent else '','class ', $tmp/text(), ';'),''),$gen:newline)
};

declare function local:get-fwd-decl($XMLdoc) as xs:string*
{
  let $namespaces as xs:string* := distinct-values(for $ns in $XMLdoc//zorba:fwd-decl return xs:string($ns/@ns))
  return if(empty($namespaces)) then '' 
  else 
  (for $ns in $namespaces return
  if($ns eq 'zorba') then local:get-decl($XMLdoc, 'zorba')
  else string-join(('namespace ', $ns, '{',$gen:newline, local:get-decl($XMLdoc, $ns) ,$gen:newline,'}'),''))
};

declare function local:includes($XMLdoc) as xs:string*
{
  '#include "common/shared_types.h"',
  if ( exists($XMLdoc/zorba:iterators/zorba:iterator[ @arity eq 'unary' ]) )
  then '#include "runtime/base/unarybase.h"'
  else '',
  if ( exists($XMLdoc/zorba:iterators/zorba:iterator[ @arity eq 'binary' ]) )
  then '#include "runtime/base/binarybase.h"'
  else '',
  if ( exists($XMLdoc/zorba:iterators/zorba:iterator[ @arity eq 'noary' ]) )
  then '#include "runtime/base/noarybase.h"'
  else '',
  if ( not(exists($XMLdoc/zorba:iterators/zorba:iterator/@arity)) or
       exists($XMLdoc/zorba:iterators/zorba:iterator[ @arity eq 'nary' ]) )
  then '#include "runtime/base/narybase.h"'
  else '',

  for $include in $XMLdoc//zorba:header/zorba:include[@form='Angle-bracket']
  return 
    concat('#include <', $include/text(), '>'),

  for $include in $XMLdoc//zorba:header/zorba:include[@form='Quoted'] 
  return
    concat('#include "', $include/text(), '"')
};


declare variable $input external;

declare variable $name  as xs:string external;

string-join((gen:add-copyright(), 
             gen:add-guard-open(replace($name,'/','_')),
             $gen:newline,
             local:includes($input),
             $gen:newline,
             'namespace zorba {',
             local:get-fwd-decl($input),
             local:get-iterators($input),
             '}',
             gen:add-guard-close(),
             '/*',
             ' * Local variables:',
             ' * mode: c++',
             ' * End:',
             ' */'),
            $gen:newline),
$gen:newline
