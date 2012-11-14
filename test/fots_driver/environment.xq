(:
 : Copyright 2006-2011 The FLWOR Foundation.
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

(:~
 : Zorba FOTS driver environment
 : @author Sorin Nasoi
 :)

module namespace env =
  "http://www.zorba-xquery.com/fots-driver/environment";

import module namespace xqxq =
  "http://www.zorba-xquery.com/modules/xqxq";
import module namespace util =
  "http://www.zorba-xquery.com/fots-driver/util" at "util.xq";

declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace ann =
  "http://www.zorba-xquery.com/annotations";


declare variable $env:hof as xs:string :=
  string-join(
    ( "declare namespace op = 'http://www.zorba-xquery.com/options/features';",
      "declare namespace f = 'http://www.zorba-xquery.com/features';",
      "declare option op:enable 'f:hof';"),
    "&#xA;");

(:~
 : Retrieves the environment from a test-set/catalog given an environment name.
 : @param $catalog FOTS catalog file.
 : @param $testSet test set.
 : @param $envName name of the environment.
 : @return the environment with the given name.
 :)
declare function env:get-environment (
  $catalog,
  $testSet  as element (fots:test-set),
  $envName  as xs:string
) as element(fots:environment)? {
  let $envTestSet := $testSet/test-set//environment[@name = $envName]
  return
    if (empty($envTestSet))
    then $catalog/catalog//environment[@name = $envName]
    else $envTestSet
};

(:~
 : Adds the variable declarations.
 : @param $env environment.
 : @param $case test case.
 : @return the variable declarations.
 :)
declare %ann:nondeterministic function env:add-var-decl(
  $env      as element(fots:environment)?,
  $case     as element(fots:test-case)
) as xs:string? {
  concat( env:var-decl-with-value($env,
                                  $case/fots:environment),
          env:var-decl-without-value($env,
                                     $case/fots:environment))
};

(:~
 : Returns the string for setting the context item if needed.
 : @param $env environment.
 : @param $envBaseURI test base URI of the environment.
 : @return the string for setting the context item if needed.
 :)
declare function env:set-context-item(
  $env        as element(fots:environment)?,
  $envBaseURI as xs:anyURI?
) as xs:string? {
  if(empty($env))
  then ()
  else if(data($env/@name) = 'empty')
  then ()
  else if (exists($env/fots:source[@role = "."]))
  then string-join((env:declare-context-item($env, $envBaseURI),
                   'xqxq:bind-context-item($queryID, $contextItem);')
                   ,"&#xA;")
  else ()
};

(:~
 : Returns the strings for variable binding in XQXQ.
 :
 : @param $env the environment of the catalog/test-set (given with 'ref').
 : @param $envBaseURI the relative URI for the environment.
 : @return the strings for variable binding in XQXQ.
 :)
declare function env:set-variables(
  $env        as element(fots:environment)?,
  $envBaseURI as xs:anyURI
) as xs:string? {
  if(empty($env))
  then ()
  else
    let $srcNames := for $source in $env/fots:source
                     where starts-with(data($source/@role),"$")
                     return substring-after(data($source/@role),"$"),
        $srcValues := for $srcName in $srcNames
                      return concat('doc("',
                                  resolve-uri($env/fots:source[@role = concat("$",$srcName)]/@file, $envBaseURI),
                                  '")')
  return
  string-join(
    (for $srcName in $srcNames
     let $index := index-of($srcNames, $srcName)
     return
      concat('xqxq:bind-variable( $queryID, xs:QName("', $srcName, '")', ', ',
             $srcValues[$index], ');'),
      for $param in $env/fots:param
      let $select:= data($param/@select)
      let $varValue := if(starts-with($select, "'") and ends-with($select, "'"))
                      then  concat('"',
                                  resolve-uri($env/fots:source[@uri = translate($param/@select, "'", "")]/@file, $envBaseURI),
                                  '"')
                      else $select
      let $varName := data($param/@name)
      return
        concat('xqxq:bind-variable( $queryID, xs:QName("', data($param/@name),
                '")', ', ', $varValue, ');'))
    , "&#xA;")
};

(:~
 : Adds the declare namespace statements.
 :
 : @param $env the environment of the catalog/test-set (given with 'ref').
 : @param $case the test-case.
 : @param $testSetBaseURI the URI of the test set file.
 : @return the declare namespace statements.
 :)
declare %ann:nondeterministic function env:decl-namespaces(
  $env            as element(fots:environment)?,
  $case           as element(fots:test-case),
  $testSetBaseURI as xs:anyURI
) as xs:string? {
  string-join(
    for $ns in ($env/fots:namespace, $case/fots:environment/fots:namespace)
    where not($ns[@prefix=""]) and 
          not(env:is-schema-prefix-bound(data($ns/@prefix),
                                        $case,
                                        $testSetBaseURI))
    return concat('declare namespace ',
                  data($ns/@prefix),
                  ' = "',
                  data($ns/@uri),
                  '";')
              ," ")
};

(:~
 : Sets the declared default element namespace.
 :
 : @param $env the environment of the catalog/test-set (given with 'ref').
 : @param $envCase the environment of the test-case.
 : @return the declare default element namespace.
 :)
declare function env:decl-def-elem-namespace(
  $env      as element(fots:environment)?,
  $envCase  as element(fots:environment)?
) as xs:string? {
  for $ns in ($env/fots:namespace, $envCase/fots:namespace)
  where $ns[@prefix=""]
  return concat('declare default element namespace "',
                 data($ns/@uri),
                '";')
};

(:~
 : Returns the the declare base-uri prolog statement.
 :
 : @param $env the environment of the catalog/test-set (given with 'ref').
 : @param $envCase the environment of the test-case.
 : @return the declare base-uri prolog statement.
 :)
declare function env:decl-base-uri(
  $env      as element(fots:environment)?,
  $envCase  as element(fots:environment)?
) as xs:string? {
  for $baseURI in ($env/fots:static-base-uri, $envCase/fots:static-base-uri)
  return concat("declare base-uri '",
                 data($baseURI/@uri),
                "';")
};
(:~
 : Return true if the prefix will be bound to a schema in the Query
 : It's a bug in the FOTS if this function returns true: TODO report to W3C
 :)
declare %private %ann:nondeterministic function env:is-schema-prefix-bound(
  $prefix         as xs:string,
  $case           as element(fots:test-case),
  $testSetBaseURI as xs:anyURI
) as xs:boolean {
  contains(util:get-value($case,
                          $testSetBaseURI,
                          "test"),
            concat("import schema namespace ",
                  $prefix))
};

declare %private function env:get-schema-import (
  $env  as element(fots:environment)?
) as xs:string {
  if (empty($env))
  then ""
  else
    let $namespace := $env/fots:namespace[@uri = data($env/fots:schema/@uri)]
    let $prefix as xs:string := if(exists($namespace))
                                then xs:string(data($namespace/@prefix))
                                else "p"
    return
      if($prefix = "")
      then concat('import schema default element namespace "',
                  $env/fots:schema/@uri,
                  '";&#xA;')
      else concat('import schema namespace ',
                  $prefix,
                  ' = "',
                  $env/fots:schema/@uri,
                  '";&#xA;')
};

declare %private function env:var-decl-with-value(
  $env      as element(fots:environment)?,
  $envCase  as element(fots:environment)?
) as xs:string? {
  string-join(
    for $param in ($env/fots:param, $envCase/fots:param)
    where exists(data($param/@select)) and
                not(starts-with(data($param/@select),"'"))
                and empty(data($param[@declared="true"]))
    return concat("declare variable $",
                  data($param/@name),
                  " := ",
                  data($param/@select),";")
   ," ")
};

declare %private function env:var-decl-without-value(
  $env      as element(fots:environment)?,
  $envCase  as element(fots:environment)?
) as xs:string? {
  string-join(
    (for $param in ($env/fots:param, $envCase/fots:param)
     where (empty(data($param/@select)) or
            (exists(data($param/@select)) and 
            starts-with(data($param/@select),"'")))
            and empty(data($param[@declared="true"]))
     return concat("declare variable $",
                   data($param/@name),
                   " external;"),
     for $source in ($env/fots:source, $envCase/fots:source)
     where starts-with(data($source/@role),"$")
     return concat("declare variable ",
                   data($source/@role),
                   " external;"))
   ," ")
};

declare %private function env:declare-context-item(
  $env        as element(fots:environment)?,
  $envBaseURI as xs:anyURI?
) as xs:string {
  let $ciURI := resolve-uri($env/fots:source[@role = "."]/@file, $envBaseURI)
  return
  if(empty($env/fots:source[@validation = "strict"]))
  then concat('variable $contextItem := doc("', $ciURI, '");')
  else string-join(
    ("&#xA;",
     "variable $contextItemQuery := xqxq:prepare-main-module('",
     env:get-schema-import($env),
     concat('validate { doc("', $ciURI, '")', "}',", " "),
           "resolver:url-resolver#2, ());",
           "variable $contextItem := xqxq:evaluate($contextItemQuery);")
   ,"&#xA;")
};

(:~
 : Returns the XQXQ URL resolver declaration.
 : @param $case the test case.
 : @param $env the environment.
 : @param $envBaseURI URI of the environment.
 : @param $testSetBaseURI URI to the test set that defines the test case.
 : @return the XQXQ URL resolver declaration.
 :)
declare function env:resolver(
  $case           as element(fots:test-case),
  $env            as element(fots:environment)?,
  $envBaseURI     as xs:anyURI?,
  $testSetBaseURI as xs:anyURI
) as xs:string?
{
  let $envSchema := $env/fots:schema,
      $tcSchema := $case/fots:environment/fots:schema,
      $schemas := ($envSchema, $tcSchema),
      $modules := $case/fots:module,
      $resources := ($env/fots:resource, $case/fots:environment/fots:schema)
  return
    if (empty($schemas) and empty($modules) and empty($resources))
    then ()
    else string-join(
            ("declare namespace resolver = 'http://www.zorba-xquery.com/modules/xqxq/url-resolver';",
             $env:hof,
            "declare function resolver:url-resolver($namespace as xs:string, $entity as xs:string) {",
            "switch($entity)",
    if (exists($schemas))
    then string-join(("case 'schema'",
                     "  return switch($namespace)",
                    (for $schema in $envSchema
                     return concat("    case '",
                                  data($schema/@uri),
                                   "' return doc('",
                                   resolve-uri($schema/@file, $envBaseURI),
                                   "')"),
                      for $schema in $tcSchema
                      return concat("    case '",
                                   data($schema/@uri),
                                   "' return doc('",
                                   resolve-uri($schema/@file, $testSetBaseURI),
                                   "')")),
                      "    default return ()"),
                      "&#xA;")
    else (),
    if (exists($modules))
    then string-join(("case 'module'",
                      "  return switch($namespace)",
                      for $module in $modules
                      return concat("    case '",
                                   data($module/@uri),
                                   "' return unparsed-text('",
                                   resolve-uri($module/@file, $testSetBaseURI),
                                   "') "),
                    "    default return ()"),
                    "&#xA;")
    else (),
    if (exists($resources)) then
    string-join(("case ''",
                 "  return switch($namespace)",
                  for $resource in $resources
                  return concat("    case '",
                                 data($resource/@uri),
                                 "' return unparsed-text('",
                                 resolve-uri($resource/@file, $envBaseURI),
                                 "'",
                                 if(exists($resource/@encoding))
                                 then concat (",'",
                                              data($resource/@encoding),
                                              "'")
                                 else (),
                                 ") "),
                 "         default return ()")
                ,"&#xA;")
    else ()
    , "default return ()","};"),
    "&#xA;")
};

(:~
 : Check if an XQuery version declaration needs to be added.
 :
 : @param $deps the dependencies of the test set and test case.
 : @param $test the Query test.
 : @return the XQuery version declaration.
 :)
declare function env:add-xquery-30(
  $deps as element(fots:dependency)*,
  $test as xs:string
) as xs:string? {
  let $dependencies := string-join(distinct-values(for $dep in $deps
                                                   where $dep[@type="spec"]
                                                   return data($dep/@value)),"")
  return
    if ((contains($dependencies,"XQ30") or contains($dependencies,"XP30")) and
        not(contains($test, "xquery version ")))
    then 'xquery version "3.0";'
    else ()
};

(:~
 : If there is a dependency on XQuery 3.0 and there is at least one HOF
 : function in the test, return the strings for enabling the HOF feature.
 :
 : @param $deps the dependencies of the test set and test case
 : @param $test the Query test.
 : @return the strings for enabling the HOF feature
 :)
declare function env:enable-HOF-feature(
  $deps as element(fots:dependency)*,
  $test as xs:string
) as xs:string? {
  let $depSpec := string-join(distinct-values( for $dep in $deps
                                               where $dep[@type="spec"]
                                               return data($dep/@value)),""),
      $depFeature := string-join(distinct-values(for $dep in $deps
                                                 where $dep[@type="feature"]
                                                 return data($dep/@value)),"")
  return
    if ((contains($depSpec,"XQ30") or contains($depSpec,"XP30")) and
         contains($depFeature,"higherOrderFunctions"))
    then $env:hof else ()
};

(:~
 : Checks the dependencies according to the Zorba manifest.
 :
 : @param $deps the dependencies of the test set and test case
 : @param $zorbaManifest Zorba manifest document.
 : @return if true empty string, otherwise returns a string with the
 : dependencies that were not matched.
 :)
declare function env:check-dependencies(
  $deps           as element(fots:dependency)*,
  $zorbaManifest
) as xs:string* {
  if(empty($deps))
  then ()
  else
    for $dep in $deps
    let $satisfied := if(exists($dep/@satisfied))
                      then data($dep/@satisfied)
                      else "true"
    let $zorbaDep := $zorbaManifest//fots:dependency[ @type = $dep/@type and
                                                      @value = $dep/@value and
                                                      @satisfied = $satisfied]
    return
      if(empty($zorbaDep))
      then concat("Dependency (type=",
                  $dep/@type,
                  ", value=",
                  $dep/@value,
                  ", satisfied=",
                  $satisfied,
                  ") was not met. ")
      else ()
};

declare %private function env:set-properties(
  $decimal-format as element(fots:decimal-format)
) as xs:string* {
  for $att in $decimal-format/attribute::*
  let $name := node-name($att)
  let $value := data($att)
  return
    if(exists(index-of(("decimal-separator", "grouping-separator", "infinity",
                        "minus-sign", "NaN", "percent", "per-mille",
                        "zero-digit", "digit", "pattern-separator"),
                        xs:string($name))))
    then concat($name, '="' , $value, '"')
    else ()
};

(:~
 : Add the decimal format declarations.
 :
 : @param $decimal-formats decimal formats.
 : @return the decimal formats declarations.
 :)
declare function env:decl-decimal-formats(
  $decimal-formats as element(fots:decimal-format)*
) as xs:string* {
  if(empty($decimal-formats))
  then ()
  else
    for $tmp in $decimal-formats
    let $default := if(exists($tmp/@name))
                    then ()
                    else "default"
    let $name :=  if(exists($tmp/@name))
                  then data($tmp/@name)
                  else ()
    return
      string-join(("declare", 
                    $default,
                    "decimal-format",
                    $name,
                    env:set-properties($tmp),
                    ";"),' ')
};
