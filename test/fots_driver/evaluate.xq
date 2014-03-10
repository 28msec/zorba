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
 : Zorba FOTS driver evaluate
 : @author Sorin Nasoi
 :)

module namespace eval =
  "http://www.zorba-xquery.com/fots-driver/evaluate";

import schema namespace output =
  "http://www.w3.org/2010/xslt-xquery-serialization";

import module namespace zq =
  "http://zorba.io/modules/zorba-query";

import module namespace schema =
  "http://zorba.io/modules/schema";

import module namespace fots-err =
  "http://www.zorba-xquery.com/fots-driver/errors" at "errors.xq";

import module namespace util =
  "http://www.zorba-xquery.com/fots-driver/util" at "util.xq";

import module namespace zorba-xml =
  "http://zorba.io/modules/xml";

declare namespace err =
  "http://www.w3.org/2005/xqt-errors";

declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace ann =
  "http://zorba.io/annotations";


(:~
 : Checks if the result matches the assertions.
 : @param $result actual result.
 : @param $expResult expected result.
 : @param $testSetBaseURI the URI of the directory that contains the file of the
          associated test set.
 : @return the results of assertion evaluations.
 :)
declare %ann:sequential function eval:result(
  $result         as item()*,
  $expResult      as element(),
  $testSetBaseURI as xs:anyURI
) as element()*
{
  let $err := eval:check-assertion($result,
                                   $expResult,
                                   (),
                                   "",
                                   $testSetBaseURI)
  return if (empty($err))
  then ()
  else
    <fots:info>
      <fots:expected-result>{$expResult}</fots:expected-result>
      <fots:result>{$result}</fots:result>
      <fots:errors>{$err}</fots:errors>
    </fots:info>
};


(:~
 : Checks if the error found matches the expected error (if any).
 : @param $result actual result.
 : @param $expResult expected result.
 : @param $code err:code.
 : @param $errorDescription err:description.
 : @param $testSetBaseURI the URI of the directory that contains the file of the
          associated test set.
 : @return the results of error evaluation.
 :)
declare %ann:sequential function eval:error(
  $result           as item()*,
  $expResult        as element(),
  $code             as xs:QName?,
  $errorDescription as xs:string?,
  $testSetBaseURI   as xs:anyURI
) as element()*
{
  if (empty($result))
  then
    let $err := eval:error-code($code,
                                $errorDescription,
                                $expResult,
                                $testSetBaseURI)
    return
      if (empty($err))
      then ()
      else
        <fots:info>
          <fots:expected-result>{$expResult}</fots:expected-result>
          <fots:result>{$result}</fots:result>
          <fots:errors>{$err}</fots:errors>
        </fots:info>
  else
    <fots:info>
      <fots:expected-result>{$expResult}</fots:expected-result>
      <fots:result>{$result}</fots:result>
      <fots:errors>{concat("Expected error [",
                           data($expResult/@code),
                           "], found result.")}</fots:errors>
    </fots:info>
};


declare %private %ann:sequential function eval:error-code(
  $code             as xs:QName?,
  $errorDescription as xs:string?,
  $expResult        as element(),
  $testSetBaseURI   as xs:anyURI
) as xs:string*
{
  let $assertName := local-name($expResult)
  return
  if ( $assertName = "error")
  then
    if (exists($expResult[@code = "*"]) or
        exists($expResult[@code = local-name-from-QName($code)]))
    then ()
    else if (exists($code))
    then concat("Expected error: ",
                data($expResult/@code),
                ". Found error: ",
                local-name-from-QName($code))
    else concat("Expected error: ",
                data($expResult/@code),
                ". Found empty result.")
  else if (($assertName = "any-of") or ($assertName = "all-of"))
  then eval:check-assertion((),
                            $expResult,
                            $code,
                            $errorDescription,
                            $testSetBaseURI)
  else concat("Expected result, found error ",
              local-name-from-QName($code),
              " - ",
              $errorDescription)
};


declare %private %ann:sequential function eval:check-assertion(
  $result           as item()*,
  $expResult        as element(),
  $code             as xs:QName?,
  $errorDescription as xs:string?,
  $testSetBaseURI   as xs:anyURI
) as xs:string*
{
  let $test := local-name($expResult)
  return
    switch($test)
    case 'all-of'
      return eval:assert-all-of($result,
                                $expResult,
                                $code,
                                $errorDescription,
                                $testSetBaseURI)
    case 'any-of'
      return eval:assert-any-of($result,
                                $expResult,
                                $code,
                                $errorDescription,
                                $testSetBaseURI)
    case 'assert'
      return eval:assert($result, $expResult)

    case 'assert-count'
      return eval:assert-count($result, $expResult)

    case 'assert-deep-eq'
      return eval:assert-deep-eq($result, $expResult)

    case 'assert-empty'
      return eval:assert-empty($result)

    case 'assert-eq'
      return eval:assert-eq($result, $expResult)

    case 'assert-false'
      return eval:assert-false($result)

    case 'assert-permutation'
      return eval:assert-permutation($result, $expResult)

    case 'assert-xml'
      return eval:assert-xml($result, $expResult, $testSetBaseURI)

    case 'assert-serialization-error'
      return eval:assert-serialization-error($result, $expResult, $testSetBaseURI)

    case 'assert-string-value'
      return eval:assert-string-value($result, $expResult)

    case 'assert-true'
      return eval:assert-true($result)

    case 'assert-type'
      return eval:assert-type($result, $expResult)

    case 'serialization-matches'
      return eval:serialization-matches($result, $expResult)

    case 'error'
      return eval:error($result,
                        $expResult,
                        $code,
                        $errorDescription,
                        $testSetBaseURI)
    default
      return error($fots-err:errNA,
                   "&#xA;The requested assertion type is not implemented.")
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_any-of
 :)
declare %private %ann:sequential function eval:assert-any-of(
  $result           as item()*,
  $expResult        as element(),
  $code             as xs:QName?,
  $errorDescription as xs:string?,
  $baseURI          as xs:anyURI
) as xs:string?
{
  let $results :=
    for $tmp in $expResult/*
    return <result>{
      for $r in eval:check-assertion($result,
                                     $tmp,
                                     $code,
                                     $errorDescription,
                                     $baseURI)
      return <item>{$r}</item>
    } </result>
  where every $result in $results satisfies $result/item
  return concat("'Assert-any-of' returned: ",
                fn:serialize($results/data(item), $util:serParamXml))
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_all-of
 :)
declare %private %ann:sequential function eval:assert-all-of(
  $result           as item()*,
  $expResult        as element(),
  $code             as xs:QName?,
  $errorDescription as xs:string?,
  $baseURI          as xs:anyURI
) as xs:string*
{
  for $tmp in $expResult/*
  return eval:check-assertion($result,
                              $tmp,
                              $code,
                              $errorDescription,
                              $baseURI)
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert
 :)
declare %private %ann:sequential function eval:assert(
  $result    as item()*,
  $expResult as element()
) as xs:string?
{
  try
  {
  {
    variable $queryText :=
      concat("xquery version '3.0';",
             "declare variable $result external; ",
             xs:string($expResult));

    variable $queryKey := zq:prepare-main-module($queryText);

    variable $queryKeyResult := zq:bind-variable($queryKey,
                                                   xs:QName('result'),
                                                   $result);

    variable $queryResult := zq:evaluate($queryKey);
 
   if ($queryResult)
   then ()
   else concat("Assertion ", $expResult, " failed.")
  }
  }
  catch *
  {
    concat("'assert' returned: fail with error ",
           $err:code, " : ", $err:description)
  }
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-count
 :)
declare %private function eval:assert-count(
  $result    as item()*,
  $expResult as element()
) as xs:string?
{
  if (count($result) eq xs:integer($expResult))
  then ()
  else "'assert-count' returned: actual number of items is different than the expected number of items."
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-deep-eq
 :)
declare %private %ann:sequential function eval:assert-deep-eq(
  $result    as item()*,
  $expResult as element()
) as xs:string?
{
  try {
  {
    variable $queryText := concat(
      "xquery version '3.0';",
      "declare variable $x external;",
      "let $y := (",string(data($expResult)),") return ",
      "every $i in 1 to max((count($x),count($y))) satisfies deep-equal($x[$i],$y[$i])");
    variable $queryKey := zq:prepare-main-module($queryText),
             $queryKeyResult := zq:bind-variable($queryKey,
                                                   xs:QName('x'),
                                                   $result),
             $queryResult := zq:evaluate($queryKey);
    if ($queryResult)
    then ()
    else "'assert-deep-eq' returned: actual result is not deep-equal to expected result."
  }
  } catch * {
    concat("'assert-deep-eq' returned: fail with error ",
            $err:code, " : ", $err:description)
  }
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-empty
 :)
declare %private function eval:assert-empty(
  $result    as item()*
) as xs:string?
{
  if (empty($result))
  then ()
  else "'assert-empty' returned: result is not empty as expected."
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-eq
 :)
declare %private %ann:sequential function eval:assert-eq(
  $result    as item()*,
  $expResult as element()
) as xs:string?
{
  try {
  {
    variable $type := if (empty($result[1]) or (count($result) gt 1))
                      then ()
                      else
                        let $tmp := xs:string(schema:schema-type($result[1]))
(: add exception for the types defined in schemas available in the environment of the tests :)
                        return
                          if (starts-with($tmp, 'xs:'))
                          then $tmp
                          else ();
    variable  $queryText := concat(
      "declare variable $x external;",
      "$x eq ",
      if (starts-with(data($expResult), $type))
      then data($expResult)
      else concat($type,"(",
                  if(ends-with($expResult,'INF') or ends-with($expResult,'NaN'))
                  then concat("'",$expResult,"'")
                  else $expResult,
                  ")"));
    variable  $queryKey := zq:prepare-main-module($queryText);
  
    zq:bind-variable($queryKey,
                      xs:QName('x'),
                      $result);
    variable $queryResult := zq:evaluate($queryKey);
    if ($queryResult)
    then ()
    else "'assert-eq' returned: result doesn't match expected result."
  }
  } catch * {
    concat("'assert-eq' returned: comparison failed with error ",
           $err:code, " : ", $err:description)
  }
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-true
 :)
declare %private function eval:assert-true(
  $result as item()*
) as xs:string?
{
  if ($result eq fn:true())
  then ()
  else "'assert-true' returned: query doesn't evaluate to true."
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-false
 :)
declare %private function eval:assert-false(
  $result as item()*
) as xs:string?
{
  if ($result eq fn:false())
  then ()
  else "'assert-false' returned: query doesn't evaluate to false."
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-permutation
 :)
declare %private %ann:sequential function eval:assert-permutation(
  $result    as item()*,
  $expResult as element()
) as xs:string?
{
  try {
  {
    variable $queryText := concat(
      "declare variable $x external;",
      "declare function local:order-string-values($items){ for $item in $items order by xs:string($item) return $item};",
      "let $y := (",string(data($expResult)),") return ",
      "deep-equal(local:order-string-values($x), local:order-string-values($y)) or
       deep-equal(reverse($x), $y)");
    variable $queryKey := zq:prepare-main-module($queryText),
             $queryKeyResult := zq:bind-variable($queryKey,
                                                  xs:QName('x'),
                                                  $result),
             $queryResult := zq:evaluate($queryKey);
    if ($queryResult)
    then ()
    else "'assert-permutation' returned: result isn't a permutation of expected result."
  }
  } catch * {
    concat("'assert-permutation' returned: fail with error ",
            $err:code, " : ", $err:description)
  }
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-xml
 :)
declare %private function eval:assert-xml(
  $result    as item()*,
  $expResult as element(),
  $baseURI   as xs:anyURI
)
{
  try {
    let $actualResult   := concat('<root>', fn:serialize($result, $util:serParamXml), '</root>')
    let $expectedResult := concat('<root>', util:get-value($expResult, $baseURI, "assert-xml"), '</root>')
    return
    (: first try to see if deep-equal is true:)
    if(deep-equal(parse-xml($actualResult), parse-xml($expectedResult)))
    then ()
    else (: second try to canonicalize :)
    {
      let $canActualResult   := zorba-xml:canonicalize($actualResult)
      let $canExpectedResult := zorba-xml:canonicalize($expectedResult)
      return
        if(empty($expResult[@ignore-prefixes='true']) and
           ($canActualResult eq $canExpectedResult))
        then ()
        else if(exists($expResult[@ignore-prefixes='true']) and
              fn:parse-xml($canActualResult) eq fn:parse-xml($canExpectedResult)) (: the namespace prefixes are ignored in this comparison :)
        then ()
        else concat("'assert-xml' returned: result &#xA;'", $canActualResult, "'&#xA; is different from the expected result &#xA;'", $canExpectedResult,"'&#xA;")
    }
  } catch * {
    concat("'assert-xml' returned: fail with error ",
            $err:code, " : ", $err:description)
  }
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-serialization-error
 :)
declare %private %ann:sequential function eval:assert-serialization-error(
  $result    as item()*,
  $expResult as element(),
  $baseURI   as xs:anyURI
 
) as xs:string?
{
  try {
  let $serializedResult as xs:string := fn:serialize($result, $util:serParamXml)
  return
   "'assert-serialization-error' returned: expected serialization error but got result."
  } catch * {
    eval:error((),
              $expResult,
              $err:code,
              $err:description,
              $baseURI)
  }
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_serialization-matches
 :)
declare %private function eval:serialization-matches(
  $result    as item()*,
  $expResult as element()
) as xs:string?
{
  try {
  let $serResult := fn:serialize($result)
  let $regex := fn:string($expResult)
  let $flags := data($expResult/@flags)
  return
    if (exists($flags))
    then
      if (matches($serResult, $regex, $flags))
      then ()
      else concat("'serialization-matches' returned: result does not match expected result with flags '",
                  $flags,
                  "'.")
    else
      if (matches($serResult, $regex))
      then ()
      else "'serialization-matches' returned: result does not match expected result."
  } catch * {
    concat("'serialization-matches' returned: fail with error ",
            $err:code, " : ", $err:description)
  }
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-string-value
 :)
declare %private function eval:assert-string-value(
  $result    as item()*,
  $expResult as element()
) as xs:string?
{
  try {
    let $serRes := string-join(for $r in $result return string($r), " ")
    let $res := if (empty($expResult[@normalize-space="true"]))
                then $serRes
                else normalize-space($serRes)
    let $expRes :=  if (empty($expResult[@normalize-space="true"]))
                    then xs:string($expResult)
                    else normalize-space(xs:string($expResult))
    return
      if ($res eq $expRes)
      then ()
      else "'assert-string-value' returned: result different from expected result."
  } catch * {
    concat("'assert-string-value' returned: failed with error ",
           $err:code, " : ", $err:description)
  }
};


(:
 : http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-type
 :)
declare %private %ann:sequential function eval:assert-type(
  $result    as item()*,
  $expResult as element()
) as xs:string?
{
  try {
  {
    variable $queryText := concat( "declare variable $x external; $x instance of ",
                                  data($expResult));
    variable $queryKey := zq:prepare-main-module($queryText),
             $queryKeyResult := zq:bind-variable($queryKey,
                                                  xs:QName('x'),
                                                  $result),
             $queryResult := zq:evaluate($queryKey);
    if ($queryResult)
    then ()
    else concat("'assert-type' returned: result doesn't have type '",
                data($expResult), "'")
  }
  } catch * {
    concat("'assert-type' returned: failed with error ",
           $err:code, " : ", $err:description)
  }
};
