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
  concat (
    'void populate_context_', $name, '(static_context* sctx);'
  )
};


declare function local:process-file($doc) as xs:string
{
  string-join(for $iter in $doc//zorba:iterator return local:create-function($iter),$gen:newline)
};


declare function local:create-function($iter) as xs:string?
{ 
  let $name := local:function-name($iter)
  return
  if(fn:not($iter/@generateCodegen) or $iter/@generateCodegen eq "true") 
  then
    if(count($iter/zorba:function/zorba:signature) = 0) then 
      (: TODO user fn:error :)
      'Error: could not find "prefix" and "localname" attributes for "zorba:function" element'
    else (
      string-join (
       (
        if ( exists($iter/@preprocessorGuard) )
        then
          $iter/@preprocessorGuard
        else "",

        $gen:newline, $gen:newline,
        local:description($iter),
        $gen:newline,

        'class ', $name, ' : public ', local:base-class($iter),
        $gen:newline,
        '{',
        $gen:newline,
        'public:',
        $gen:newline, $gen:indent,

        (: Generate the class constructor :)
        let $signatures := $iter/zorba:function/zorba:signature
        let $argCounts := for $sig in $signatures
                          return count($sig/zorba:param)
        let $numSignatures := count($argCounts)
        return 
        if ($numSignatures eq 1)
        then
          string-join(($name,
                       '(const signature&amp; sig)',
                       $gen:newline, $gen:indent,  $gen:indent,
                       ':',
                       $gen:newline, $gen:indent,  $gen:indent,
                       local:base-class($iter),
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
                       local:base-class($iter),
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
        local:add-annotations($iter),
        local:add-specialization($iter),
        local:add-unfoldable($iter),
        local:add-is-source($iter),
        local:add-is-fn-error($iter),
        local:add-is-updating($iter),
        local:add-is-vacuous($iter),
        local:add-is-sequential($iter),
        $gen:newline,$gen:indent,'CODEGEN_DECL();',$gen:newline,

        (: generate the return type function or not 
         : if true, the user has to provide his own implementation
         :)
        if($iter/zorba:function/@generateReturnTypeDecl = 'true') then 
          string-join(($gen:newline,$gen:indent,
          'xqtref_t return_type(const std::vector&lt;xqtref_t&gt;&amp; arg_types) const;',
          $gen:newline),'') 
        else (),

        (: generate the computeAnnotation function
         : if true, the user has to provide his own implementation
         :)
        if($iter/zorba:function/@generateComputeAnnotationDecl = 'true') then 
          string-join(($gen:newline,$gen:indent,
          'void compute_annotation(AnnotationHolder* parent,',$gen:newline,
          gen:indent(13),'std::vector&lt;AnnotationHolder *&gt;&amp; kids,',$gen:newline,
          gen:indent(13),'Annotations::Key k) const;',$gen:newline),'') 
        else (),

        (: generate a declaration for propagatesInputToOutput if
           any of the propagatesInputToOutput or propagesOne
           attributes is present :)
        if ( fn:exists ($iter/zorba:function/@propagatesInputToOutput) or
              fn:exists ($iter/zorba:function/@propagesOne) )
        then
          string-join(($gen:newline,$gen:indent,
          'bool propagatesInputToOutput(uint32_t aProducer) const;',$gen:newline),'')
        else (),

        if ($iter/zorba:function/@generateProducesDuplicateDecl = 'true') then
          string-join(($gen:newline,$gen:indent,
          'zorba::FunctionConsts::AnnotationValue producesDuplicates() const;',$gen:newline),'') 
        else (),

        if ($iter/zorba:function/@generateProducesNodeIdSortedDecl = 'true') then
          string-join(($gen:newline,$gen:indent,
          'zorba::FunctionConsts::AnnotationValue producesNodeIdSorted() const;',$gen:newline),'') 
        else (),
             
      '};',
      if ( exists($iter/@preprocessorGuard) )
      then
        concat($gen:newline, "#endif")
      else ""
      )
     , ''))
  else ()
};


declare function local:base-class($iter)
{
  if(not($iter/zorba:function/@baseSig)) then
    'function'
  else
    $iter/zorba:function/@baseSig 
};


declare function local:add-is-source($iter) as xs:string?
{
  if($iter/zorba:function/@isSource = 'true') then
    string-join(($gen:newline,$gen:indent,
    'virtual bool isSource() const { return true; }',$gen:newline),'')
  else ()
};

declare function local:add-is-fn-error($iter) as xs:string?
{
  if($iter/zorba:function/@isFnError = 'true') then
    string-join(($gen:newline,$gen:indent,
    'bool isFnError() const { return true; }',$gen:newline),'')
  else ()
};

declare function local:add-is-updating($iter) as xs:string?
{
  if($iter/zorba:function/@isUpdating = 'true') then
    string-join(($gen:newline,$gen:indent,
    'expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }',$gen:newline),'')
  else ()
};

declare function local:add-is-vacuous($iter) as xs:string?
{
  if($iter/zorba:function/@isVacuous = 'true') then
    string-join(($gen:newline,$gen:indent,
    'expr_script_kind_t getUpdateType() const { return VACUOUS_EXPR; }',$gen:newline),'')
  else ()
};

declare function local:add-is-sequential($iter) as xs:string?
{
  if($iter/zorba:function/@isSequential = 'true') then
    string-join(($gen:newline,$gen:indent,
    'expr_script_kind_t getUpdateType() const { return SEQUENTIAL_EXPR; }',$gen:newline),'')
  else ()
};


declare function local:add-unfoldable($iter) as xs:string?
{
  if($iter/zorba:function/@requiresDynamicContext = 'true') then
    string-join(($gen:newline,$gen:indent,
    'bool requires_dyn_ctx() const { return true; }',$gen:newline),'')
  else ()
};


declare function local:add-specialization($iter) as xs:string?
{
  if($iter/zorba:function/@specializable = 'true') then    
    string-join(($gen:newline,$gen:indent,
    'bool specializable() const { return true; }',$gen:newline,
    $gen:newline,$gen:indent,
    'function* specialize( static_context* sctx,',$gen:newline,
    gen:indent(12),'const std::vector&lt;xqtref_t&gt;&amp; argTypes) const;',$gen:newline),'')
  else ()
};


declare function local:add-annotations($iter) as xs:string?
{
  if(count($iter/zorba:function//zorba:annotation) > 0) then
    for $ann in $iter/zorba:function//zorba:annotation return
      string-join(($gen:newline,$gen:indent,
      'FunctionConsts::AnnotationValue ',$ann/@name,'() const {',$gen:newline,
      gen:indent(2),'return FunctionConsts::',$ann/text(),';',$gen:newline,
      $gen:indent,'}',$gen:newline),'')
  else ()
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


(:
   Variable $file will be bound to the pathname of the xml file that is to
   be converted to a .h file
:)
declare variable $file as xs:string external;
declare variable $doc := "";


let $pieces as xs:string* := tokenize($file,'/')
let $name := substring($pieces[count($pieces)],1,string-length($pieces[count($pieces)])-4)
return
  block {
    set $doc := file:read-xml($file)/zorba:iterators;
    string-join((gen:add-copyright(),
          $gen:newline,
          gen:add-guard-open(string-join(('functions_',$name),'')),
          $gen:newline,
          local:includes($doc),
          $gen:newline,
          'namespace zorba{',
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
             ' */'
          ),
          $gen:newline),
          $gen:newline;
    }
