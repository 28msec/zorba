declare namespace zorba="http://www.zorba-xquery.com";

import module namespace util = "http://www.zorba-xquery.com/zorba/util-functions";
import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";
import module namespace file = "http://www.zorba-xquery.com/modules/file";

declare variable $local:CODEGEN_ERROR as xs:QName := xs:QName("zorba:codegen");

declare function local:create-include($doc) as xs:string
{
  string-join((
  for $include in $doc//zorba:codegen/zorba:cpp/zorba:include[@form='Angle-bracket']
  return 
    concat('#include <', $include/text(), '>'),

  for $include in $doc//zorba:codegen/zorba:cpp/zorba:include[@form='Quoted']
  return
    concat('#include "', $include/text(), '"')),$gen:newline)
};

declare function local:process-file($doc,
                                    $name as xs:string,
                                    $mappings) as xs:string
{
  string-join((
    local:process($doc,'function',$name, $mappings),
    local:process($doc,'context',$name, $mappings)),
    $gen:newline
  )
};

(: $type can be either 'function' or 'context' :)
declare function local:process($doc,
                               $type as xs:string,
                               $name as xs:string,
                               $mappings) as xs:string
{
  let $mapping := $mappings/zorba:mappings
  return 
    if($type = 'function')
    then (
      string-join(
        for $iter in $doc//zorba:iterator 
        return (
          if( fn:not ( $iter/@generateCodegen ) or 
              $iter/@generateCodegen eq "true" ) 
          then (
            local:create-function($iter),
            $gen:newline,
            local:propagateInputToOutput($iter)
          ) else ()
        ),
        $gen:newline
      )
    )
  else (: 'context' :)
    string-join(('void populate_context_',$name,'(static_context* sctx) {',$gen:newline,
    string-join(for $iter in $doc//zorba:iterator return local:create-context($iter,$mapping),''),
    '}'),'')
};

(:
 : Generate the propagatesInputToOutput function
 : @param iter is the iterator for which the function should be generated
 : 
 : The iterator must have a zorba:function child element.
 : This function element can either have a propagatesInputToOutput or
 : propagatesOne attribute. If no such element is present, the default
 : is propagatesInputToOutput="true" is assumed.
 :)
declare function local:propagateInputToOutput($iter) as xs:string
{
  let $name := local:function-name($iter)
  let $func := $iter/zorba:function
  return
    if ( exists ( $func/@propagatesInputToOutput ) and
         exists ( $func/@propagatesOne ) )
    then
      fn:error( $local:CODEGEN_ERROR, concat("Either propagatesInputToOutput or ",
                                        "propagatesOne can be present in a ",
                                        "function specification") )
    else
      let $param := if ( exists ( $func/@propagatesOne ) )
                    then "aProducer" else ""
      let $body  := if ( exists ( $func/@propagatesOne ) )
                    then concat ( 
                      "return aProducer == ",  $func/@propagatesOne, ';'
                    )
                    else concat (
                      "return ", $func/@propagatesInputToOutput,
                      ';'
                    )
      return
        if ( fn:exists ($iter/zorba:function/@propagatesInputToOutput) or
              fn:exists ($iter/zorba:function/@propagesOne) )
        then
          concat (
            'bool ', $name, '::propagatesInputToOutput ( uint32_t ', $param, ') const {',
            $gen:newline,
            $gen:indent, $body,
            $gen:newline,
            '}'
          )
        else "" (: inherit from function class :)
};

declare function local:create-function($iter) as xs:string?
{ 
  let $name := local:function-name($iter)
  return
    if(count($iter/zorba:function/zorba:signature) = 0) then 
      (: TODO user fn:error :)
      'Error: could not find "prefix" and "localname" attributes for "zorba:function" element'
    else
      if ( not ( $iter/zorba:function/@generateCodegen ) or
           $iter/zorba:function/@generateCodegen = 'true' )
      then
        string-join(($gen:newline,'PlanIter_t ',$name,'::codegen(',$gen:newline,
        $gen:indent,'CompilerCB*,',$gen:newline,
        $gen:indent,'static_context* sctx,',$gen:newline,
        $gen:indent,'const QueryLoc&amp; loc,',$gen:newline,
        $gen:indent,'std::vector&lt;PlanIter_t&gt;&amp; argv,',$gen:newline,
        $gen:indent,'AnnotationHolder&amp; ann) const',$gen:newline,'{',$gen:newline,
        $gen:indent,'return new ',local:iterator-call($iter),';',$gen:newline,'}'),'')
      else ""
};

declare function local:description($iter) as xs:string
{
  let $sig := $iter/zorba:function//zorba:signature[1]
  
  return if(fn:not($sig/@prefix) or fn:not($sig/@localname)) then ''
  else
  string-join(('//',if($sig/@prefix = 'fn' and starts-with(string($sig/@localname),':')) 
    then string-join(('op',$sig/@localname),'') 
    else string-join(($sig/@prefix,':',$sig/@localname),'')),'')
};

declare function local:function-name($iter) as xs:string
{
  let $sig := $iter/zorba:function//zorba:signature[1]
  
  return if($sig/@prefix = 'fn' and starts-with(string($sig/@localname),':')) 
  then string-join(('op',translate(substring(string($sig/@localname),2),'-','_')),'_')
  else string-join((translate($sig/@prefix,'-','_'),translate($sig/@localname,'-','_')),'_')
};

declare function local:iterator-call($iter) as xs:string
{
  if($iter/zorba:function/@annIsUpdating = 'true') then
    string-join(($iter/@name,'(sctx,loc,argv,ann.is_updating())'),'')
  else
    string-join(($iter/@name,'(sctx,loc,argv)'),'')
};

declare function local:create-context($iter,$mapping) as xs:string?
{
  if($iter/zorba:function/@generateDECL = 'false') then ()
  else
    string-join(for $sig in $iter//zorba:signature return 
      string-join(($gen:newline,$gen:indent,'DECL(sctx, ',local:function-name($iter),',',$gen:newline,
      gen:indent(3),'(createQName("',local:get-zorba-ns($sig/@prefix,$mapping),'","',$sig/@prefix,'","',$sig/@localname,'")',
      for $param in $sig/zorba:param return local:create-zorba-type($param,$mapping),
      local:create-zorba-type($sig/zorba:output,$mapping),'));',$gen:newline),''),'')
};

declare function local:get-zorba-ns($prefix as xs:string,$mapping) as xs:string
{
  let $tmp := $mapping//zorba:namespace[@prefix=$prefix]
  return if($tmp) then $tmp/@uri
  else  (: TODO user fn:error :)
      'Error: could not find "prefix" and "localname" attributes for "zorba:function" element'  
};

declare function local:create-zorba-type($param,$mapping) as xs:string?
{
  if($param = 'true') then
    string-join((',',$gen:newline,gen:indent(3),$param),'')

  else if ($param eq 'empty-sequence()') then
    string-join((',', $gen:newline, gen:indent(3), 'GENV_TYPESYSTEM.EMPTY_TYPE'), '')

  else if($param) then
    let $suffix := if(ends-with($param,'?')) then 'TYPE_QUESTION' 
                   else if(ends-with($param,'+')) then 'TYPE_PLUS'
                   else if(ends-with($param,'*')) then 'TYPE_STAR'
                   else 'TYPE_ONE'                   
    
    let $prefix as xs:string := string($mapping/zorba:types//zorba:type[starts-with($param, text())][1]/@zorbaType)
    
    return string-join((',',
                        $gen:newline,
                        gen:indent(3),
                        string-join (('GENV_TYPESYSTEM.',
                                      $prefix,
                                      '_',
                                      $suffix),
                                     '')),
                        '')

  else
    ()
};


declare variable $file as xs:string external;
declare variable $mappings as xs:string external;
declare variable $mappings_doc := "";
declare variable $file_doc := "";

let $pieces as xs:string* := tokenize($file,'/')
let $name := substring($pieces[count($pieces)],1,string-length($pieces[count($pieces)])-4)
return
  block {
    set $mappings_doc := file:read-xml($mappings);
    set $file_doc     := file:read-xml($file);
    string-join((gen:add-copyright(),
      local:create-include($file_doc),
      'namespace zorba{',
      local:process-file($file_doc, $name, $mappings_doc),
      '}')
      ,string-join(($gen:newline, $gen:newline),'')
    );
  }
