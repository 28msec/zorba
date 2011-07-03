import module namespace file = "http://expath.org/ns/file";
import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare copy-namespaces preserve, inherit;


(:~
 : This variable contains the modules directory path in the
 : source directory
 :)
declare variable $modulesPath as xs:string external;


(:~
 : This function generates the XQDoc XML for all the modules found in
 : <pre>$modulesPath</pre> and tests it for validity.
 :
 : @param $modulePath where to search for modules recursively.
 :)
declare %ann:nondeterministic %ann:sequential function local:testXQDoc($modulesPath as xs:string)
{
  for $file in file:list($modulesPath, fn:true(), "*.xq")
  let $filePath := fn:concat($modulesPath, "/", $file)
  return
    try {
      let $xqdoc := xqd:xqdoc(file:path-to-uri($filePath))/self::xqdoc:xqdoc
      return (
        local:test-module($xqdoc),
        local:test-functions($xqdoc),
        local:test-variables($xqdoc)
      );
    } catch * ($ec, $em){
      exit returning fn:concat("ERROR: ", $ec, " Message: ", $em, "
processing file: ", $filePath);
    }
};

declare function local:test-module($xqdoc as element(xqdoc:xqdoc)) as xs:string*
{
  let $module := $xqdoc/xqdoc:module/xqdoc:comment
  let $hasDescription := exists($module/xqdoc:description)
  let $hasAuthor := exists($module/xqdoc:author)

  return (
    (: Test for module description :)
    if (not($hasDescription)) then
      concat("ERROR: Missing module description
  Module: ", $xqdoc/xqdoc:module/xqdoc:uri)
    else
      ()
    ,
    (: Test for module author :)
    if (fn:not($hasAuthor) and fn:not($xqdoc/xqdoc:module/xqdoc:uri eq "http://www.functx.com/")) then
      fn:concat("ERROR: Missing module author name
  Module: ", $xqdoc/xqdoc:module/xqdoc:uri)
    else
      ()
  )
};

declare function local:test-functions(
  $xqdoc as element(xqdoc:xqdoc)
)as xs:string* {
    let $module := $xqdoc/xqdoc:module
    for $function in $xqdoc/xqdoc:functions/xqdoc:function
    where (not(exists($function/@isPrivate)) or 
           (exists($function/@isPrivate) and $function/@isPrivate ne "true"))
    return local:test-function($module, $function)
};

declare function local:test-function(
  $module as element(xqdoc:module),
  $function as element(xqdoc:function)
) as xs:string* {
    let $signature := $function/xqdoc:signature
    let $paramCount := count(tokenize($signature, "\$")) - 1
    let $params := $function/xqdoc:comment/xqdoc:param
    let $docParamCount := count($params)
    let $missing := $paramCount - $docParamCount  
    let $hasDescr := exists($function/xqdoc:comment/xqdoc:description)
    let $hasReturn := exists($function/xqdoc:comment/xqdoc:return)
    return (
        (: Test for function description :)
        if (not($hasDescr) and not($module/xqdoc:uri eq "http://www.w3.org/2005/xpath-functions")) then
            concat("ERROR: Missing function description
    Module: ", $module/xqdoc:uri, "
    Function: ", $function/xqdoc:name, "
    Arity: ", $paramCount)
        else
            (),
        (: Test for documented parameters :)
        if ($docParamCount ne $paramCount and not($module/xqdoc:uri eq "http://www.w3.org/2005/xpath-functions")) then
            concat("ERROR: ", $missing, " parameter(s) not documented
    Module: ", $module/xqdoc:uri, "
    Function: ", $function/xqdoc:name, "
    Arity: ", $paramCount)
        else
            (),
        (: Test for documented return value :)
        if (not($hasReturn) and not($module/xqdoc:uri eq "http://www.w3.org/2005/xpath-functions") and not($module/xqdoc:uri eq "http://www.functx.com/")) then
            concat("ERROR: Return value not documented;
    Module: ", $module/xqdoc:uri, "
    Function: ", $function/xqdoc:name, "
    Arity: ", $paramCount)
        else
            ()
    )
};

declare function local:test-variables(
  $xqdoc as element(xqdoc:xqdoc)
) as xs:string* {
    let $module := $xqdoc/xqdoc:module
    for $variable in $xqdoc/xqdoc:variables/xqdoc:variable
    return local:test-variable($module, $variable)
};

declare function local:test-variable(
  $module as element(xqdoc:module),
  $variable as element(xqdoc:variable)
) as xs:string* {
    let $hasDescr := exists($variable/xqdoc:comment/xqdoc:description)
    return
        (: Test for variable description :)
        if (not($hasDescr)) then
            concat("ERROR: Missing variable description
    Module: ", $module/xqdoc:uri, "
    Variable: ", $variable/xqdoc:name)
        else
            ()
};

variable $errors := local:testXQDoc($modulesPath);
if (exists($errors)) then (
        concat("
------------------------------------------------
ERROR COUNT: ", count($errors), "
------------------------------------------------
"),
        for $error in $errors
        return
            concat("
", $error),
        concat("
------------------------------------------------
ERROR COUNT: ", count($errors), "
------------------------------------------------
")
    )
    else "CONGRATULATIONS! You've got a Schnitzel!"
