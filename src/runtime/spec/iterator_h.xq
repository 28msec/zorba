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
    (: preceding comment :)
    '/**', $gen:newline,
    ' * ', fn:normalize-space($iter/zorba:description/text()), $gen:newline,
    ' * ', $gen:newline, 
    ' * ', "Author: ", fn:normalize-space($iter/zorba:description/@author),
    ' * ', $gen:newline,
    ' */', $gen:newline,

    (: generate an explicit state if required :)
    if (exists($iter/zorba:state))
    then
      local:process-state($iter/zorba:state, $stateName)
    else (),

    (: generate the iterator declaration :)
    local:NARY-ITER-STATE($iter, $iter/@name, $stateName)
  ) (: concat :)
};

declare function local:process-state($state, $stateName as xs:string) as xs:string
{
  string-join(('class ',$stateName,' : public PlanIteratorState',$gen:newline, '{', $gen:newline,
  if(exists($state//zorba:member)) then 'public:' else (),
  string-join(($gen:newline,for $member in $state//zorba:member return 
  string-join(($gen:indent,string($member/@type),' ',string($member/@name),'; //',string($member/@brief),$gen:newline),''))
  ,''),$gen:newline,

  (: generate constructor decl only if the user wants to implement it :)
  if ($state/@generateConstructor and $state/@generateConstructor eq "false")
  then
    concat($gen:indent, $stateName, '();', $gen:newline, $gen:newline)
  else (),

  if ($state/@generateDestructor and $state/@generateDestructor eq "false")
  then
    concat($gen:indent, '~', $stateName, '();', $gen:newline, $gen:newline)
  else (),

  (: generate init and reset decl :)
  concat($gen:indent,'void init(PlanState&amp;);',$gen:newline,
         $gen:indent,'void reset(PlanState&amp;);',$gen:newline),
  '};',$gen:newline, $gen:newline),'')
};

declare function local:NARY-ITER-STATE($iter, $name as xs:string, $state as xs:string) as xs:string
{
  if(count($iter/zorba:constructor/zorba:parameter) ne count($iter/zorba:member)) then
    (: TODO user fn:error :)
    'Error: the number of "zorba:parameters" in the "zorba:constructor" is different than the number of "zorba:members"'
  else
    concat ('class ', $name, ': ', 'public NaryBaseIterator <', $name, ', ', $state, '> {', $gen:newline,
    local:add-protected($iter),

    (: serialization code :)
    'public:', $gen:newline, 
    $gen:indent, 'SERIALIZABLE_CLASS(',$name,');', $gen:newline, $gen:newline,
    $gen:indent, 'SERIALIZABLE_CLASS_CONSTRUCTOR2T(', $name,',', $gen:newline,
    $gen:indent, 'NaryBaseIterator<', $name,', ', $state,'>);', $gen:newline, $gen:newline,
    $gen:indent, 'void serialize(::zorba::serialization::Archiver&amp; ar){',$gen:newline,
    gen:indent(2), 'serialize_baseclass(ar,',$gen:newline,
    gen:indent(2),'(NaryBaseIterator<',$name,', ',$state,'>*)this);',$gen:newline,$gen:newline,
    local:add-arch($iter),
    $gen:indent,'}',$gen:newline,$gen:newline,
    $gen:indent,$name,'(static_context* sctx, const QueryLoc&amp; loc,',$gen:newline,
    $gen:indent,'std::vector<PlanIter_t>&amp; aChildren',
    local:add-constructor-param($iter),
    ')',$gen:newline,$gen:indent,':',$gen:newline,
    $gen:indent,'NaryBaseIterator<',$name,', ',$state,'>',$gen:newline,$gen:indent,'(sctx, loc, aChildren',
    local:add-constructor-param-2($iter),
    '{}',$gen:newline,$gen:newline,
    local:add-destructor($iter),
    local:add-accessor($iter),
    $gen:indent,'void accept(PlanIterVisitor&amp; v) const;',$gen:newline,$gen:newline,
    $gen:indent,'bool nextImpl(store::Item_t&amp; result, PlanState&amp; aPlanState) const;',$gen:newline,'};',$gen:newline,$gen:newline
    )
};

declare function local:add-destructor($iter) as xs:string?
{
  fn:concat($gen:indent, "virtual ~", $iter/@name, "();", $gen:newline, $gen:newline)
};

declare function local:add-accessor($iter) as xs:string?
{
  if (count($iter/zorba:member) > 0) then 
  string-join(for $member in $iter/zorba:member return
  if($member/@generateAccessor = true()) then
  string-join(($gen:indent,'virtual bool ',$member/@accessorName,'() const { return ',$member/@name,'; }',$gen:newline,$gen:newline),'')
  else () ,'') else ()
};

declare function local:add-constructor-param-2($iter) as xs:string?
{
  let $member := $iter/zorba:member
  let $param := $iter/zorba:constructor/zorba:parameter
  return if (count($member) > 0) then string-join((')',for $i in (1 to count($member)) return
  string-join((',',$gen:newline,$gen:indent,$member[$i]/@name,'(',$param[$i]/@name,')'),'')),'')
  else ')'
};

declare function local:add-constructor-param($iter) as xs:string?
{
  if(count($iter/zorba:constructor/zorba:parameter > 0)) then
  string-join((for $param in $iter/zorba:constructor/zorba:parameter return 
  string-join((',',$gen:newline,$gen:indent,$param/@type,' ',$param/@name,
  if(exists($param/@defaultValue) and ($param/@defaultValue ne '')) then string-join((' = ',$param/@defaultValue),'') else ()
  ),'')),'')
  else ()
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
  string-join((for $member in $iter/zorba:member return 
  string-join((gen:indent(2),'ar &amp; ', $member/@name,';',$gen:newline),'')),'')
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

declare function local:get-include($XMLdoc) as xs:string*
{
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
            gen:add-guard-open($name),
            local:get-include($input),
            'namespace zorba {',
              local:get-fwd-decl($input),
              local:get-iterators($input),
            '}',
            gen:add-guard-close())
            ,string-join(($gen:newline,$gen:newline),'')), $gen:newline
