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
                           '}'),
                          '')
            else if ($numSignatures eq 2)
            then
              string-join(($name,
                           '(const signature&amp; sig) : ',
                           local:base-class($function),
                           '(sig)',
                           $gen:newline, $gen:indent,
                           '{',
                           $gen:newline, $gen:indent,  $gen:indent,
                           'theKind = (sig.arg_count() == ',
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
                           '}'),
                          '')
            else
              (: User must provide implementation of constructor :)
              string-join(($name,
                           '(const signature&amp; sig);'),
                          ''),
          $gen:newline,

        (: 
           Check whether to generate the signature for the return_type function.
           If true, the user has to provide his own implementation.
        :)
        if($function/@generateReturnTypeDecl = 'true')
        then 
          string-join(($gen:newline, $gen:indent,
                       'xqtref_t return_type(const std::vector&lt;xqtref_t&gt;&amp; arg_types) const;',
                       $gen:newline),
                      '') 
        else
          (),

        (: 
          Check whether to generate the computeAnnotation function.
          If true, the user has to provide his own implementation.
        :)
        if($function/@generateComputeAnnotationDecl = 'true')
        then
          string-join(($gen:indent,
                       'COMPUTE_ANNOTATION_DECL();', 
                       $gen:newline, $gen:newline), '') 
        else 
          (),

        (: 
           Check whether to generate the propagatesInputToOutput function.
           If any of the propagatesInputToOutput or propagesOne attributes is
           present, the function declaration is generated, and the has to provide
           his own implementation.
        :)
        if ( fn:exists($function/@propagatesInputToOutput) or
              fn:exists($function/@propagesOne) )
        then
          string-join(($gen:newline, $gen:indent,
                       'bool propagatesInputToOutput(ulong aProducer) const;',
                       $gen:newline),'')
        else 
          (),

        local:add-annotations($function),
        local:add-isMap($function),
        local:add-specialization($function),
        local:add-unfoldable($function),
        local:add-isDeterministic($function),
        local:add-is-source($function),
        local:add-is-fn-error($function),
        local:add-is-updating($function),
        local:add-is-vacuous($function),
        local:add-is-sequential($function),
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


declare function local:add-is-source($function) as xs:string?
{
  if($function/@isSource = 'true') 
  then
    string-join(($gen:newline, $gen:indent,
                 'virtual bool isSource() const { return true; }',
                 $gen:newline),'')
  else
    ()
};


declare function local:add-is-fn-error($function) as xs:string?
{
  if ($function/@isFnError = 'true')
  then
    string-join(($gen:newline, $gen:indent,
                 'bool isFnError() const { return true; }',
                 $gen:newline),'')
  else 
    ()
};


declare function local:add-is-updating($function) as xs:string?
{
  if ($function/@isUpdating = 'true') 
  then
    string-join(($gen:newline, $gen:indent,
                 'expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }',
                 $gen:newline),'')
  else 
    ()
};


declare function local:add-is-vacuous($function) as xs:string?
{
  if ($function/@isVacuous = 'true') 
  then
    string-join(($gen:newline, $gen:indent,
                 'expr_script_kind_t getUpdateType() const { return VACUOUS_EXPR; }',
                 $gen:newline),'')
  else 
    ()
};


declare function local:add-is-sequential($function) as xs:string?
{
  if ($function/@isSequential = 'true') 
  then
    string-join(($gen:newline, $gen:indent,
                 'expr_script_kind_t getUpdateType() const { return SEQUENTIAL_EXPR; }',
                 $gen:newline),'')
  else 
    ()
};


declare function local:add-isDeterministic($function) as xs:string?
{
  if ($function/@isDeterministic = 'false') 
  then
    string-join(($gen:newline,$gen:indent,
                 'bool isDeterministic() const { return false; }',
                 $gen:newline),'')
  else 
    ()
};


declare function local:add-isMap($function) as xs:string?
{
  let $input := data($function/@isMap)
  return 
    if (empty($input)) then
      ()
    else
      string-join(($gen:newline, 
                   $gen:indent,
                   'bool isMap(ulong input) const { return input == ', $input,  '; }',
                   $gen:newline), '')
};


declare function local:add-unfoldable($function) as xs:string?
{
  if ($function/@requiresDynamicContext = 'true')
  then
    string-join(($gen:newline, $gen:indent,
                 'bool requires_dyn_ctx() const { return true; }',
                 $gen:newline),'')
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


declare function local:add-annotations($function) as xs:string*
{
  if (count($function//zorba:annotation) > 0) 
  then
    for $ann in $function//zorba:annotation
    return
      string-join(($gen:newline, $gen:indent,
                   'FunctionConsts::AnnotationValue ', $ann/@name, '() const ',
                   $gen:newline, $gen:indent, '{',
                   $gen:newline, gen:indent(2),
                   'return FunctionConsts::', $ann/text(), ';', 
                   $gen:newline, $gen:indent,
                   '}', $gen:newline), '')
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
