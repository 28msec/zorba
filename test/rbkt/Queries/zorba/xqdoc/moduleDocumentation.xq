xquery version "3.0";

import module namespace file = "http://expath.org/ns/file";
import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare copy-namespaces preserve, inherit;


(:~
 : This variable contains the path to Zorba directory
 :)
declare variable $ZorbaPath as xs:string external;

(:~
 : This variable contains the path to Zorba directory
 :)
declare variable $ZorbaBuildPath as xs:string external;

(: 
 : This function returns a sequence of valid PATHS where modules can be found:
 : this includes the Zorba core modules path and also all the paths to the external modules that are checked out
 :)
declare %ann:nondeterministic function local:get-src-dirs() as xs:string*
{
  (: set the path to the Zorba core modules :)
  let $ZorbaCoreModules := fn:resolve-uri(concat($ZorbaPath,"modules"))
  
  (: read from CMakeCache.txt the path where the external modules are checked out (if any) :)
  let $ZorbaCMakeCache := fn:resolve-uri(concat($ZorbaBuildPath, file:directory-separator(), "CMakeCache.txt"))
  let $ZorbaModulesDir := substring-before(tokenize(file:read-text($ZorbaCMakeCache),"ZORBA_MODULES_DIR:PATH=")[2],"
")
  let $dirs := file:list(fn:resolve-uri($ZorbaModulesDir))
  return( $ZorbaCoreModules,
          for $dir in $dirs
          let $file := fn:resolve-uri(concat($ZorbaModulesDir,file:directory-separator(),$dir,file:directory-separator(),"CMakeLists.txt"))
          let $text := file:read-text($file)
          let $as := fn:analyze-string($text, "ADD_SUBDIRECTORY\((.*?)\)")
          let $match := replace($as/fn:match/fn:group[@nr eq 1],'"',"")
          return fn:resolve-uri(concat($ZorbaModulesDir,file:directory-separator(),$dir,file:directory-separator(),$match)))
};

(:~
 : This function generates the XQDoc XML for all the modules found in
 : <pre>$modulesPath</pre> and tests it for validity.
 :
 : @param $modulePath where to search for modules recursively.
 :)
declare %ann:nondeterministic function local:testXQDoc($modulesPath as xs:string) as xs:string?
{
  variable $res := 
  for $file in file:list(fn:resolve-uri($modulesPath), fn:true(), "*.xq")
  let $filePath := fn:concat($modulesPath, file:directory-separator(), $file)
  return
    try {
      let $xqdoc := xqd:xqdoc(file:path-to-uri($filePath))/self::xqdoc:xqdoc
      let $moduleUri := data($xqdoc/xqdoc:module/xqdoc:uri)
      return string-join(
         if(($moduleUri = "http://www.w3.org/2005/xpath-functions") or
            ($moduleUri = "http://www.w3.org/2005/xpath-functions/math") or
            ($moduleUri = "http://www.functx.com/") or
            ($moduleUri = "http://www.w3.org/2005/xqt-errors") or
            ($moduleUri = "http://www.zorba-xquery.com/errors") or
            ($moduleUri = "http://www.zorba-xquery.com/warnings")) then ()
        else(
        local:test-module($xqdoc),
        local:test-functions($xqdoc),
        local:test-variables($xqdoc)
      ),"")
    } catch * {
    fn:concat("ERROR: ", $err:code, " Message: ", $err:description, "
processing file: ", $filePath)
    };
    string-join($res,"")
};

declare function local:test-module($xqdoc as element(xqdoc:xqdoc)) as xs:string?
{
  let $module := $xqdoc/xqdoc:module/xqdoc:comment
  let $moduleUri := $xqdoc/xqdoc:module/xqdoc:uri
  let $hasDescription := exists($module/xqdoc:description)
  let $hasAuthor := exists($module/xqdoc:author)
  let $hasXQueryVersion := exists($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:custom[@tag="XQuery version"])

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
       ($moduleUri = "http://www.functx.com/")) then ()
    else
      if (fn:not($hasXQueryVersion)) then
      fn:concat("
    ERROR: Missing explicit XQuery version declaration in prolog
    Module: ", $xqdoc/xqdoc:module/xqdoc:uri)
    else
      ()  
  ),"")  
};

declare function local:test-functions(
  $xqdoc as element(xqdoc:xqdoc)
)as xs:string? {
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
    let $hasReturn := exists($function/xqdoc:comment/xqdoc:return)
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
        (: Test for documented return value :)
        if (not($hasReturn)) then
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
) as xs:string? {
    let $module := $xqdoc/xqdoc:module
    let $moduleUri := $module/xqdoc:uri
    return
      string-join(for $variable in $xqdoc/xqdoc:variables/xqdoc:variable
      return local:test-variable($module, $variable),"")
};

declare function local:test-variable(
  $module as element(xqdoc:module),
  $variable as element(xqdoc:variable)
) as xs:string? {
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


variable $errors as xs:string :=  string-join(for $complete-dir in local:get-src-dirs()
                                              return local:testXQDoc($complete-dir),"");

variable $errorsCount := count(fn:analyze-string($errors,"ERROR:")//fn:match);

if ($errorsCount = 0) then
"CONGRATULATIONS! You've got a Schnitzel!"
else
        concat("
------------------------------------------------
ERROR COUNT: ", xs:string($errorsCount), "
------------------------------------------------
",$errors) 
