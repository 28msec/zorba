declare namespace zorba="http://www.zorba-xquery.com";

import module namespace util="http://www.zorba-xquery.com/zorba/util-functions";
import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";
import module namespace file = "http://www.zorba-xquery.com/modules/file";


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


declare function local:create-function($iter, $function) as xs:string?
{ 
  let $name := local:function-name($function)
  return
    if (fn:not($iter/@generateCodegen) or $iter/@generateCodegen eq "true") 
    then
      if(count($function/zorba:signature) = 0)
      then 
        (: TODO user fn:error :)
        'Error: could not find "prefix" and "localname" attributes for "zorba:function" element'
      else 
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

          (:
             Generate the class constructor
          :)
          let $signatures := $function/zorba:signature
          let $argCounts := for $sig in $signatures
                            return count($sig/zorba:param)
          let $numSignatures := count($argCounts)
          let $setNoneDeterministic := if ($function/@isDeterministic = 'false')
                                       then 
                                         ($gen:newline, $gen:indent, $gen:indent,
                                         "setDeterministic(false);")
                                       else ""
          return 
            if ($numSignatures eq 1)
            then
              string-join(($name,
                           '(const signature&amp; sig)',
                           $gen:newline, $gen:indent, $gen:indent,
                           ':',
                           $gen:newline, $gen:indent, $gen:indent,
                           local:base-class($function),
                           '(sig, FunctionConsts::',
                           gen:function-kind($signatures[1]),
                           ')',
                           $gen:newline, $gen:indent,
                           '{',
                           $gen:newline, $gen:indent,
                           $setNoneDeterministic,
                           '}'),
                          '')
            else if ($numSignatures eq 2)
            then
              string-join(($name,
                           '(const signature&amp; sig) : ',
                           local:base-class($function),
                           '(sig, FunctionConsts::FN_UNKNOWN)',
                           $gen:newline, $gen:indent,
                           '{',
                           $gen:newline, $gen:indent,  $gen:indent,
                           'theKind = (sig.paramCount() == ',
                           xs:string($argCounts[1]),
                           ' ?',
                           $gen:newline,
                           '                FunctionConsts::',
                           gen:function-kind($signatures[1]),
                           ' :',
                           $gen:newline,
                           '                FunctionConsts::',
                           gen:function-kind($signatures[2]),
                           ');',
                           $gen:newline, $gen:indent,
                           $setNoneDeterministic,
                           $gen:newline, $gen:indent,
                           '}'),
                          '')
            else
              (: User must provide implementation of constructor :)
              string-join(($name,
                           '(const signature&amp; sig);'),
                          ''),
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
                     'xqtref_t getReturnType(',
                     $gen:newline, $gen:indent, $gen:indent, $gen:indent, $gen:indent,
                     'const TypeManager* tm,',
                     $gen:newline, $gen:indent, $gen:indent, $gen:indent, $gen:indent,
                     'const std::vector&lt;xqtref_t&gt;&amp; arg_types) const;',
                     $gen:newline), '')

      else if (name($meth) eq 'zorba:getUpdateType')
      then
        string-join(($gen:newline, $gen:indent,
                     'expr_script_kind_t getUpdateType() const ',
                     '{ return ', $meth/@returnValue, '; }',
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
                     'bool isMap(ulong producer) const ',
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
                     'bool propagatesDistinctNodes(ulong producer) const ',
                     '{ return producer == ', $meth/@producer, '; }',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:propagatesSortedNodes')
      then
        string-join(($gen:newline, $gen:indent,
                     'bool propagatesSortedNodes(ulong producer) const ',
                     '{ return producer == ', $meth/@producer, '; }',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:ignoresSortedNodes')
      then
        string-join(($gen:newline, $gen:indent,
                     'BoolAnnotationValue ignoresSortedNodes(expr* fo, ulong producer) const;',
                      $gen:newline),'')

      else if (name($meth) eq 'zorba:ignoresDuplicateNodes')
      then
        string-join(($gen:newline, $gen:indent,
                     'BoolAnnotationValue ignoresDuplicateNodes(expr* fo, ulong producer) const;',
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


let $pieces as xs:string* := tokenize($file,'/')
let $name := substring($pieces[count($pieces)],1,string-length($pieces[count($pieces)])-4)
return
  block 
  {
    set $doc := file:read-xml($file)/zorba:iterators;
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
    $gen:newline;
  }
