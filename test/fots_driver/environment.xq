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

declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";
declare option op:disable "f:trace";

(:
declare variable $env:hof as xs:string :=
  string-join(
    ( "declare namespace op = 'http://www.zorba-xquery.com/options/features';",
      "declare namespace f = 'http://www.zorba-xquery.com/features';",
      "declare option op:enable 'f:hof';"),
    "&#xA;");
:)


(:~
 : If there is a dependency on the HOF feature, return the text for enabling
 : the HOF feature within a query.
 :
 : @param $deps the dependencies of the test set and test case
 : @param $test the raw query text.
 : @return the text for enabling the HOF feature
declare function env:enable-HOF-feature(
  $deps as element(fots:dependency)*,
  $test as xs:string
) as xs:string?
{
  let $check :=
    some $dep in $deps
    satisfies $dep[@type eq "feature" and contains(@value, "higherOrderFunctions")]
  return
    if ($check)
    then $env:hof
    else ()
};
 :)


(:~
 : Create the text for an XQuery version declaration that must be added
 : to a test-case query.
 :
 : @param $deps the dependencies of the test set and test case.
 : @param $test the raw query text.
 : @return the text for the XQuery version declaration, if necessary; otherwise,
 :         the empty sequence.
 :)
declare function env:add-xquery-version-decl(
  $deps as element(fots:dependency)*,
  $test as xs:string
) as xs:string?
{
  let $deps := $deps[@type eq "spec"]

  let $v30 :=
    some $dep in $deps
    satisfies $dep[contains(@value, "XQ30") or contains(@value, "XP30")]

  return
    if ($v30 and not(contains($test, "xquery version")))
    then
    {
      'xquery version "3.0";'
    }
    else
    {
      let $v10 :=
        some $dep in $deps
        satisfies $dep[contains(@value, "XQ10")]
      return
        if ($v10 and not(contains($test, "xquery version ")))
        then 'xquery version "1.0";'
        else ()
    }
};


(:~
 : Retruns the text for the static-base-uri declaration that must be added
 : to a test-case query.
 :
 : NOTE: at least one of $end and $envCase is the empty sequence.
 :
 : @param $env the non-local environment of the test-case, if any. It is an
 :        enviroment specified either at the test-set level or at the catalog
 :        level and is referenced by the test-case.
 : @param $envCase the local environment of the test-case, if any.
 : @return the declare base-uri prolog statement.
 :)
declare function env:decl-base-uri(
  $env      as element(fots:environment)?,
  $envCase  as element(fots:environment)?
) as xs:string?
{
  for $baseURI in ($env/fots:static-base-uri, $envCase/fots:static-base-uri)
  return concat("declare base-uri '", $baseURI/@uri, "';")
};


(:~
 : Create the text for the default-element-namespace declaration that must be
 : added to a test-case query.
 :
 : NOTE: at least one of $end and $envCase is the empty sequence.
 :
 : @param $env the non-local environment of the test-case, if any. It is an
 :        enviroment specified either at the test-set level or at the catalog
 :        level and is referenced by the test-case.
 : @param $envCase the local environment of the test-case, if any.
 : @return the text for the default element namespace declaration.
 :)
declare function env:decl-def-elem-namespace(
  $env      as element(fots:environment)?,
  $envCase  as element(fots:environment)?
) as xs:string?
{
  for $ns in ($env/fots:namespace, $envCase/fots:namespace)
  where $ns[@prefix eq ""]
  return concat('declare default element namespace "', $ns/@uri, '";')
};


(:~
 : Create the text for the necessary namespace declarations that must be added
 : to a test-case query.
 :
 : NOTE: at least one of $end and $envCase is the empty sequence.
 :
 : @param $env the non-local environment of the test-case, if any. It is an
 :        enviroment specified either at the test-set level or at the catalog
 :        level and is referenced by the test-case.
 : @param $envCase the local environment of the test-case, if any.
 : @param $test the raw query text
 : @return the text for the namespace declarations.
 :)
declare %ann:nondeterministic function env:decl-namespaces(
  $env     as element(fots:environment)?,
  $envCase as element(fots:environment)?,
  $test    as xs:string
) as xs:string?
{
  if (($env/fots:namespace, $envCase/fots:namespace))
  then
    string-join
    (
      for $ns in ($env/fots:namespace, $envCase/fots:namespace)
      where not($ns[@prefix eq ""]) and
            not(env:is-schema-prefix-bound($ns/@prefix, $test))
      return concat('declare namespace ', $ns/@prefix, ' = "', $ns/@uri, '";')
    ,
    "&#xA;"
    )
  else
    ()
};


(:~
 : Return true if the prefix will be bound to a schema in the Query
 : It's a bug in the FOTS if this function returns true: TODO report to W3C
 :)
declare %private %ann:nondeterministic function env:is-schema-prefix-bound(
  $prefix as xs:string,
  $test   as xs:string
) as xs:boolean
{
  contains($test, concat("import schema namespace ", $prefix))
};


(:~
 : Create the text for the decimal format declarations that must be added
 : to a test-case query.
 :
 : @param $decimal-formats decimal formats.
 : @return the decimal formats declarations.
 :)
declare function env:decl-decimal-formats(
  $decimal-formats as element(fots:decimal-format)*
) as xs:string*
{
  if (empty($decimal-formats))
  then 
    ()
  else
    for $tmp in $decimal-formats
    let $default := if ($tmp/@name)
                    then ()
                    else "default"
    let $name := if ($tmp/@name)
                 then data($tmp/@name)
                 else ()
    return
      string-join
      (
      (
        "declare",
        $default,
        "decimal-format",
        $name,
        env:set-properties($tmp),
        ";"
      ),
      ' '
      )
};


declare %private function env:set-properties(
  $decimal-format as element(fots:decimal-format)
) as xs:string*
{
  for $att in $decimal-format/attribute::*
  let $name := node-name($att)
  let $value := data($att)
  return
    if (exists(index-of(("decimal-separator", "grouping-separator", "infinity",
                         "minus-sign", "NaN", "percent", "per-mille",
                         "zero-digit", "digit", "pattern-separator"),
                         xs:string($name))))
    then concat($name, '="' , $value, '"')
    else ()
};


(:~
 : Create the text for all of the variable declarations that must be added to
 : the text of a test-case query. The required declarations are specified by
 : the <param> and <source> subelements of the applicable <environment>.
 :
 : NOTE: at least one of $end and $envCase is the empty sequence.
 :
 : @param $env the non-local environment of the test-case, if any. It is an
 :        enviroment specified either at the test-set level or at the catalog
 :        level and is referenced by the test-case.
 : @param $envCase the local environment of the test-case, if any.
 : @param $envBaseURI The absolute pathname of the directory containing the
 :        file that defines the non-local environment.
 : @param $testSetBaseURI The absolute pathname of the directory containing the
 :        test-set file.
 : @return the text for the variable declarations.
 :)
declare %ann:nondeterministic function env:add-var-decl(
  $env            as element(fots:environment)?,
  $envCase        as element(fots:environment)?,
  $envBaseURI     as xs:anyURI,
  $testSetBaseURI as xs:anyURI
) as xs:string?
{
  if ($env)
  then env:add-var-decls($env, $envBaseURI)
  else env:add-var-decls($envCase, $testSetBaseURI)
};


declare %private function env:add-var-decls(
  $env         as element(fots:environment)?,
  $envBaseURI  as xs:anyURI
) as xs:string?
{
  let $result :=
    string-join
    (
    (
    for $param in $env/fots:param
    where empty($param[@declared eq "true"])
    return
    {
      let $type := $param/@as
      let $select := $param/@select
      return
      {
        if ($select)
        then
        {
          let $file := $env/fots:source[@uri = translate($select, "'", "")]/@file

          let $varValue := if (starts-with($select, "'") and
                               ends-with($select, "'") and
                               exists($file))
                           then
                             concat('"', resolve-uri($file, $envBaseURI), '"')
                           else
                             $select
          return
            concat("declare variable $",
                   $param/@name,
                   if ($type)
                   then concat(" as ", $type)
                   else (),
                   " := ",
                   $varValue,
                   ";")
        }
        else
        {
          concat("declare variable $",
                 $param/@name,
                 if ($type)
                 then concat(" as ", $type)
                 else (),
                 " external;")
        }
      }
    }
    ,
    for $source in $env/fots:source
    let $role := $source/@role
    where starts-with($role,"$")
    return concat("declare variable ", $role, " external;")
    )
    ,
    " "
    )
  return
    if ($result eq "")
    then ()
    else $result
};


(:~
 : If a test-case query TQ references a source doc via the context item, this
 : function creates and returns the xquery code for computing a value for the
 : context item and binding this value inside TQ. The result of this function
 : is added to the query FQ that will be evaluated via XQXQ by the fots test
 : driver. The function assumes that TQ will appear as a nested XQXQ query
 : within FQ, and that $queryID is the FQ variable storing the XQXQ query id
 : of TQ.
 :
 : If the source doc needs to be validated, the code created by this function
 : looks like this:
 :
 :  variable $contextItemQuery := xqxq:prepare-main-module
 :  (
 :  '
 :  import schema some-prefix = "some-URI";
 :
 :  validate { doc("some-xml-file") }
 :  ',
 :  (), mapper:uri-mapper#2
 :  );
 :
 : variable $contextItem := xqxq:evaluate($contextItemQuery);
 :
 : xqxq:bind-context-item($queryID, $contextItem);
 :
 : If no validation is required, the code created by this function looks like
 : this:
 :
 : variable $contextItem := doc("some-xml-file");
 :
 : xqxq:bind-context-item($queryID, $contextItem);
 :
 : @param $env The environment (local or non-local) that applies to the current
 :             test case.
 : @param $envBaseURI The absolute pathname of the directory containing the
 :        file that defines the environment.
 : @return the string for setting the context item if needed.
 :)
declare function env:set-context-item(
  $env        as element(fots:environment)?,
  $envBaseURI as xs:anyURI?
) as xs:string?
{
  if (exists($env/fots:source[@role = "."]))
  then 
    string-join
    (
    (
    env:compute-context-item($env, $envBaseURI),
    "",
    'xqxq:bind-context-item($queryID, $contextItem);'
    )
    ,
    "&#xA;"
    )
  else
    ()
};


declare %private function env:compute-context-item(
  $env        as element(fots:environment)?,
  $envBaseURI as xs:anyURI?
) as xs:string
{
  let $ciURI := resolve-uri($env/fots:source[@role = "."]/@file, $envBaseURI)
  return
  if (empty($env/fots:source[@validation = "strict"]))
  then
    concat('variable $contextItem := doc("', $ciURI, '");')
  else 
    string-join
    (
    (
    "&#xA;",

    "variable $contextItemQuery := xqxq:prepare-main-module",
    "(",
    "'",
    env:get-schema-import($env),
    concat('validate { doc("', $ciURI, '")', " }"),
    "',",
    "(), mapper:uri-mapper#2",
    ");",
    "",
    "variable $contextItem := xqxq:evaluate($contextItemQuery);"
    )
    ,
    "&#xA;"
    )
};


declare %private function env:get-schema-import(
  $env  as element(fots:environment)?
) as xs:string
{
  if (empty($env))
  then
    ""
  else
    let $namespace := $env/fots:namespace[@uri eq $env/fots:schema/@uri]
    let $prefix as xs:string := if (exists($namespace))
                                then xs:string($namespace/@prefix)
                                else ""
    return
      if ($prefix ne "")
      then concat('import schema namespace ',
                  $prefix,
                  ' = "',
                  $env/fots:schema/@uri,
                  '";&#xA;')
      else concat('import schema default element namespace "',
                  $env/fots:schema/@uri,
                  '";&#xA;')
};


(:~
 : Creates the xquery code for assigning values to the external variables of
 : a nested XQXQ query. The nested XQXQ query is a test-case query TQ, and the
 : result of this function is added to the query FQ that will be evaluated via
 : XQXQ by the fots test driver. The function assumes that TQ will appear as a
 : nested XQXQ query within FQ, and that $queryID is the FQ variable storing
 : the XQXQ query id of TQ.
 :
 : @param $env The environment (local or non-local) that applies to the current
 :        test case 
 : @param $envBaseURI The absolute pathname of the directory containing the
 :        file that defines the environment.
 : @return the strings for variable binding in XQXQ.
 :)
declare function env:set-variables(
  $env        as element(fots:environment)?,
  $envBaseURI as xs:anyURI
) as xs:string?
{
  if (empty($env))
  then
    ()
  else
    string-join
    (
    (
      for $src in $env/fots:source[starts-with(@role, "$")]
      return
        concat('xqxq:bind-variable($queryID, xs:QName("',
               substring-after($src/@role, "$"),
               '"), ',
               'doc("',
               resolve-uri($src/@file, $envBaseURI),
               '"));')
      ,
      for $param in $env/fots:param
      let $select:= $param/@select
      let $file := $env/fots:source[@uri eq translate($select, "'", "")]/@file
      let $varValue := if (starts-with($select, "'") and
                           ends-with($select, "'") and
                           exists($file))
                       then  concat('"', resolve-uri($file, $envBaseURI), '"')
                       else $select
      let $varName := $param/@name
      where (exists($select) and exists($param[@declared eq "true"]))
      return
        concat('xqxq:bind-variable( $queryID, xs:QName("',
               $param/@name,
               '"), ',
               $varValue,
               ');') 
    )
    ,
    "&#xA;"
    )
};


(:~
 : Returns the XQXQ URL resolver declaration.
 :
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
  let $modules := $case/fots:module
  let $resources := $env/fots:resource
  return
    if (empty($modules) and empty($resources))
    then
    { 
      ()
    }
    else
    {
      string-join
      (
      (
      "declare function resolver:url-resolver($namespace as xs:string, $entity as xs:string)",
      "{",
      "switch($entity)",

      if (exists($modules))
      then
      {
        string-join
        (
        (
        "case 'module'",
        "  return switch($namespace)",

        for $module in $modules
        return concat("    case '",
                      data($module/@uri),
                      "' return unparsed-text('",
                      resolve-uri($module/@file, $testSetBaseURI),
                      "') "),

        "    default return ()"
        )
        ,"&#xA;"
        )
      }
      else
      {
        ()
      },

      if (exists($resources))
      then
      {
        string-join
        (
        (
        "case ''",
        "  return switch($namespace)",

        for $resource in $resources
        return concat("    case '",
                      data($resource/@uri),
                      "' return unparsed-text('",
                      resolve-uri($resource/@file, $envBaseURI),
                      "'",
                      if (exists($resource/@encoding))
                      then concat (",'", data($resource/@encoding), "'")
                      else (),
                      ") "),

        "         default return ()"
        )
        ,"&#xA;"
        )
      }
      else
      {
        ()
      },

      "default return ()","};"
      )
      ,"&#xA;"
      )
    }
};


(:~
 : Returns the XQXQ URL mapper declaration.
 : @param $case the test case.
 : @param $env the environment.
 : @param $envBaseURI URI of the environment.
 : @param $testSetBaseURI URI to the test set that defines the test case.
 : @return the XQXQ URL mapper declaration.
 :)
declare function env:mapper(
  $case           as element(fots:test-case),
  $env            as element(fots:environment)?,
  $envBaseURI     as xs:anyURI?,
  $testSetBaseURI as xs:anyURI
) as xs:string?
{
  let $envSchema := $env/fots:schema,
      $tcSchema := $case/fots:environment/fots:schema,
      $schemas := ($envSchema, $tcSchema)
  return
    if (empty($schemas))
    then ()
    else string-join(
            ("declare function mapper:uri-mapper($namespace as xs:string, $entity as xs:string) {",
            "switch($entity)",
    if (exists($schemas))
    then string-join(("case 'schema'",
                     "  return switch($namespace)",
                    (for $schema in $envSchema
                     return concat("    case '",
                                   data($schema/@uri),
                                   "' return '",
                                   resolve-uri($schema/@file, $envBaseURI),
                                   "'"),
                      for $schema in $tcSchema
                      return concat("    case '",
                                   data($schema/@uri),
                                   "' return '",
                                   resolve-uri($schema/@file, $testSetBaseURI),
                                   "'"),
                      "    default return ()")),
                      "&#xA;")
    else (),
    "default return ()","};"),
    "&#xA;")
};


(:~
 : Checks that a set of dependencies (associated with some test-set or test-case)
 : are met by Zorba's capabilities and implementation-defined features (as
 : specified in the Zorba manifest).
 :
 : @param $deps the dependencies of the test set or test case
 : @param $zorbaManifest Zorba manifest document.
 : @return a sequence of strings containing one string for each dependency
 :         that was not met, describing the dependency. If all dependencies
 :         are met, the empty sequence is returned.
 :)
declare function env:check-dependencies(
  $deps           as element(fots:dependency)*,
  $zorbaManifest  as node()
) as xs:string*
{
  if (empty($deps))
  then
  {
    ()
  }
  else
  {
    for $dep in $deps

    let $satisfied := if ($dep/@satisfied)
                      then data($dep/@satisfied)
                      else "true"

    let $zorbaDep := $zorbaManifest//fots:dependency[@type eq $dep/@type and
                                                     @value eq $dep/@value and
                                                     @satisfied eq $satisfied]
    return
      if (empty($zorbaDep))
      then
        concat("Dependency (type=", $dep/@type, ", value=", $dep/@value,
               ", satisfied=", $satisfied, ") was not met. ")
      else ()
  }
};
