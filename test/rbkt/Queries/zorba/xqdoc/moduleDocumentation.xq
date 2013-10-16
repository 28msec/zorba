xquery version "3.0";

import module namespace file = "http://expath.org/ns/file";
import module namespace xqd = "http://zorba.io/modules/xqdoc";
import module namespace fetch = "http://zorba.io/modules/fetch";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";

declare namespace ann = "http://zorba.io/annotations";
declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace zm = "http://zorba.io/manifest";

declare copy-namespaces preserve, inherit;


(:~
 : This variable contains the path to ZorbaManifestPath.xml
 :)
declare variable $ZorbaManifestPath as xs:string external;


declare %private %ann:nondeterministic function local:load-manifest()
{
  try 
  {
    fn:parse-xml(file:read-text($ZorbaManifestPath)) 
  }
  catch *
  {
    fn:error(fn:concat("The file <",$ZorbaManifestPath,"> does not have the correct structure."))
  }
};


(:~
 : This function generates the XQDoc XML for all correctly configured in Zorba 
 : (in other words all modules present in ZorbaManifest.xml) and checks if the modules are correctly documented.
 :
 :)
declare %ann:sequential function local:testXQDoc() as xs:string?
{
  if(not(file:is-file($ZorbaManifestPath))) then
  {
    variable $message := fn:concat("The file <ZorbaManifest.xml> was not found: <", $ZorbaManifestPath, ">. Suggestion: run 'cmake' in your build folder such that ZorbaManifest.xml is regenerated.");
    fn:error($message)
  }
  else
  {
    variable $manifestXML := local:load-manifest();
    variable $moduleManifests := $manifestXML/zm:manifest/zm:module;
    variable $res :=
    if(count($moduleManifests) eq xs:integer(0)) then ()
    else
    {
      for $module in $moduleManifests
      let $moduleURI := if(ends-with(data($module/zm:uri),".xq")) then substring-before(data($module/zm:uri),".xq") else data($module/zm:uri)
      let $moduleFetched := fetch:content($moduleURI, "MODULE")
      return
      try {
          let $xqdoc := xqd:xqdoc-content($moduleFetched)/self::xqdoc:xqdoc
          let $moduleUri := data($xqdoc/xqdoc:module/xqdoc:uri)
          return string-join(
             if(($moduleUri = "http://www.w3.org/2005/xpath-functions") or
                ($moduleUri = "http://www.w3.org/2005/xpath-functions/math") or
                ($moduleUri = "http://www.functx.com") or
                ($moduleUri = "http://www.w3.org/2005/xqt-errors") or
                ($moduleUri = "http://zorba.io/errors") or
                ($moduleUri = "http://zorba.io/warnings") or
                ($moduleUri = "http://jsoniq.org/errors") or
                ($moduleUri = "http://www.zorba-xquery.com/modules/xqdoc/batch") or
                ($moduleUri = "http://www.zorba-xquery.com/modules/xqdoc/menu") or
                ($moduleUri = "http://www.zorba-xquery.com/modules/xqdoc/html")) then ()
            else(
            local:test-module($xqdoc),
            local:test-functions($xqdoc),
            local:test-variables($xqdoc)
          ),"")
      }
      catch *
      {
        fn:concat("ERROR: ", $err:code,
                  " Message: ", $err:description,
                  " Line: ", $err:line-number, "
processing module: ", $moduleURI)
      }
    };
     
    fn:string-join($res,"")
  }
};


declare function local:test-module($xqdoc as element(xqdoc:xqdoc)) as xs:string?
{
  let $module := $xqdoc/xqdoc:module/xqdoc:comment
  let $moduleUri := $xqdoc/xqdoc:module/xqdoc:uri
  let $hasDescription := exists($module/xqdoc:description)
  let $hasAuthor := exists($module/xqdoc:author)
  let $hasLanguageVersion := 
    (exists($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:custom[@tag="version"]) and
     exists($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:custom[@tag="language"]))

  return string-join((
    (: Test for module description :)
    if (not($hasDescription)) then
      concat("
    ERROR: Missing module description
    Module: ", $xqdoc/xqdoc:module/xqdoc:uri)
    else
      ()
    ,
    (: Test for module author :)
    if (fn:not($hasAuthor)) then
      fn:concat("
    ERROR: Missing module author name
    Module: ", $xqdoc/xqdoc:module/xqdoc:uri)
    else
      ()
      ,
    (: Test for explicit XQuery Version :)
    if(($moduleUri = "http://www.w3.org/2005/xpath-functions") or
       ($moduleUri = "http://www.w3.org/2005/xpath-functions/math") or
       ($moduleUri = "http://www.functx.com")) then ()
    else
      if (fn:not($hasLanguageVersion)) then
      fn:concat("
    ERROR: Missing explicit XQuery version declaration in prolog
    Module: ", $xqdoc/xqdoc:module/xqdoc:uri)
    else
      ()  
  ),"")  
};


declare function local:test-functions(
  $xqdoc as element(xqdoc:xqdoc)
)as xs:string? 
{
    let $module := $xqdoc/xqdoc:module
    return
      string-join(for $function in $xqdoc/xqdoc:functions/xqdoc:function
      where not(exists($function//xqdoc:annotation[@localname = 'private']))
      return local:test-function($module, $function),"")
};


declare function local:test-function(
  $module as element(xqdoc:module),
  $function as element(xqdoc:function)
) as xs:string {
    let $signature := $function/xqdoc:signature
    let $paramCount := count(tokenize($signature, "\$")) - 1
    let $params := $function/xqdoc:comment/xqdoc:param
    let $docParamCount := count($params)
    let $missing := $paramCount - $docParamCount  
    let $hasDescr := exists($function/xqdoc:comment/xqdoc:description)
    let $hasReturn := exists($function/xqdoc:return)
    let $isUpdating := contains($signature, "updating")
    let $isReturnDocumented := exists($function/xqdoc:comment/xqdoc:return)
    return string-join((
        (: Test for function description :)
        if (not($hasDescr)) then
            concat("
    ERROR: Missing function description
    Module: ", $module/xqdoc:uri, "
    Function: ", $function/xqdoc:name, "
    Arity: ", $paramCount)
        else
            (),
        (: Test for documented parameters :)
        if ($docParamCount ne $paramCount) then
            concat("
    ERROR: ", $missing, " parameter(s) not documented
    Module: ", $module/xqdoc:uri, "
    Function: ", $function/xqdoc:name, "
    Arity: ", $paramCount)
        else
            (),
        (: Test for existing return value in function signature:)
        if (not($hasReturn) and not($isUpdating)) then
            concat("
    ERROR: Return value for the function not stated explicitly in the function signature;
    Module: ", $module/xqdoc:uri, "
    Function: ", $function/xqdoc:name, "
    Arity: ", $paramCount)
        else
            (),
        (: Test for documented return value :)
        if (not($isReturnDocumented)) then
            concat("
    ERROR: Return value not documented;
    Module: ", $module/xqdoc:uri, "
    Function: ", $function/xqdoc:name, "
    Arity: ", $paramCount)
        else
            ()
    ),"")
};


declare function local:test-variables(
  $xqdoc as element(xqdoc:xqdoc)
) as xs:string?
{
    let $module := $xqdoc/xqdoc:module
    let $moduleUri := $module/xqdoc:uri
    return
      string-join(for $variable in $xqdoc/xqdoc:variables/xqdoc:variable
      where not(exists($variable//xqdoc:annotation[@localname = 'private']))
      return local:test-variable($module, $variable),"")
};


declare function local:test-variable(
  $module as element(xqdoc:module),
  $variable as element(xqdoc:variable)
) as xs:string?
{
    let $hasDescr := exists($variable/xqdoc:comment/xqdoc:description)
    return
        (: Test for variable description :)
       (if (not($hasDescr)) then
            concat("
    ERROR: Missing variable description
    Module: ", $module/xqdoc:uri, "
    Variable: ", $variable/xqdoc:uri)
        else
            ())
};


variable $errors as xs:string := local:testXQDoc();

variable $errorsCount := count(fn:analyze-string($errors,"ERROR:")//fn:match);

if ($errorsCount = 0) then
"CONGRATULATIONS! You've got a Schnitzel!"
else
        concat("
------------------------------------------------
ERROR COUNT: ", xs:string($errorsCount), "
------------------------------------------------
",$errors) 
