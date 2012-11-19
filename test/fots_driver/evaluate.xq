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

import module namespace xqxq =
  "http://www.zorba-xquery.com/modules/xqxq";
import module namespace schema =
  "http://www.zorba-xquery.com/modules/schema";

import module namespace fots-err =
  "http://www.zorba-xquery.com/fots-driver/errors" at "errors.xq";
import module namespace util =
  "http://www.zorba-xquery.com/fots-driver/util" at "util.xq";

declare namespace err =
  "http://www.w3.org/2005/xqt-errors";
declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace ann =
  "http://www.zorba-xquery.com/annotations";

declare namespace features =
  "http://www.zorba-xquery.com/options/features";
declare option features:enable "hof";

(:~
 : Checks if the result matches the assertions.
 : @param $result actual result.
 : @param $expResult expected result.
 : @param $showResult is true the verbose mode is assumed.
 : @return the results of assertion evaluations.
 :)
declare %ann:sequential function eval:result(
  $result     as item()*,
  $expResult  as element(),
  $showResult as xs:boolean?
) as element()? {
  let $err := eval:check-assertion($result,
                                  $expResult,
                                  (),
                                  "",
                                  $showResult)
  return if(empty($err))
  then ()
  else
    <out>
      <expected-result>{$expResult}</expected-result>
      {
        if($showResult)
        then (<result>{$result}</result>,
              <errors>{$err}</errors>)
        else ()
      }
    </out>
};

(:~
 : Checks if the error found matches the expected error (if any).
 : @param $result actual result.
 : @param $expResult expected result.
 : @param $code err:code.
 : @param $errorDescription err:description.
 : @param $showResult is true the verbose mode is assumed.
 : @return the results of error evaluation.
 :)
declare %ann:sequential function eval:error(
  $result           as item()*,
  $expResult        as element(),
  $code             as xs:QName?,
  $errorDescription as xs:string?,
  $showResult       as xs:boolean?
) as xs:string* {
  if(empty($result)) then
    let $err := eval:error-code($code,
                                $errorDescription,
                                $expResult)
    return $err
  else
    concat("Expected error &#xA;",
          data($expResult/@code),
          ",&#xA; found result ",
          if ($showResult)
          then string-join(util:serialize-result($result),' ')
          else ())
};

declare %private %ann:sequential function eval:error-code(
  $code             as xs:QName?,
  $errorDescription as xs:string?,
  $expResult        as element()
) as xs:string* {
  let $assertName := local-name($expResult)
  return
  if( $assertName = "error")
  then
    if (exists($expResult[@code = "*"]) or
        exists($expResult[@code = local-name-from-QName($code)]))
    then ()
    else concat("Expected error: ",
                data($expResult/@code),
                ". Found error: ",
                local-name-from-QName($code))
  else if (($assertName = "any-of") or ($assertName = "all-of"))
  then eval:check-assertion((),
                            $expResult,
                            $code,
                            $errorDescription,
                            fn:true())
  else concat("Expected result: &#xA;",
              data($expResult),
              ".&#xA; Found error ",
              local-name-from-QName($code),
              " - ",
              $errorDescription)
};

declare %private %ann:sequential function eval:check-assertion(
  $result           as item()*,
  $expResult        as element(),
  $code             as xs:QName?,
  $errorDescription as xs:string?,
  $showResult       as xs:boolean?
) as xs:string* {
  let $test := local-name($expResult)
  return switch($test)
    case 'all-of'
      return eval:assert-all-of($result,
                                $expResult,
                                $code,
                                $errorDescription,
                                $showResult)
    case 'any-of'
      return eval:assert-any-of($result,
                                $expResult,
                                $code,
                                $errorDescription,
                                $showResult)
    case 'assert'
      return eval:assert($result,
                         $expResult)
    case 'assert-count'
      return eval:assert-count($result,
                               $expResult)
    case 'assert-deep-eq'
      return eval:assert-deep-eq($result,
                                 $expResult)
    case 'assert-empty'
      return eval:assert-empty($result)
    case 'assert-eq'
      return eval:assert-eq($result,
                            $expResult)
    case 'assert-false'
      return eval:assert-false($result)
    case 'assert-permutation'
      return eval:assert-permutation($result,
                                     $expResult)
    case 'assert-xml'
      return eval:assert-xml($result,
                             $expResult)
    case 'assert-serialization-error'
      return eval:assert-serialization-error($result,
                                             $expResult)
    case 'assert-string-value'
      return eval:assert-string-value($result,
                                      $expResult)
    case 'assert-true'
      return eval:assert-true($result)
    case 'assert-type'
      return eval:assert-type($result,
                              $expResult)
    case 'serialization-matches'
      return eval:serialization-matches($result,
                                        $expResult)
    case 'error'
      return eval:error($result,
                        $expResult,
                        $code,
                        $errorDescription,
                        $showResult)
    default 
      return error($fots-err:errNA,
                     "&#xA;The requested assertion type is not implemented.")
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_any-of :)
declare %private %ann:sequential function eval:assert-any-of(
  $result           as item()*,
  $expResult        as element(),
  $code             as xs:QName?,
  $errorDescription as xs:string?,
  $showResult       as xs:boolean
) as xs:string? {
  let $results :=
    for $tmp in $expResult/*
    return <result>{
      for $r in eval:check-assertion($result,
                                     $tmp,
                                     $code,
                                     $errorDescription,
                                     $showResult)
      return <item>{$r}</item>
    } </result>
  where every $result in $results satisfies $result/item
  return concat("&#xA;Assert-any-of returned: ",
                string-join(util:serialize-result($results/data(item)), ' '))
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_all-of :)
declare %private %ann:sequential function eval:assert-all-of(
  $result           as item()*,
  $expResult        as element(),
  $code             as xs:QName?,
  $errorDescription as xs:string?,
  $showResult       as xs:boolean
) as xs:string* {
  for $tmp in $expResult/*
  return eval:check-assertion($result,
                              $tmp,
                              $code,
                              $errorDescription,
                              $showResult)
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert :)
declare %private %ann:sequential function eval:assert(
  $result    as item()*,
  $expResult as element()
) as xs:string? {
  try {
  {
    variable $queryText := concat(
      "xquery version '3.0';",
      "declare namespace o = 'http://www.zorba-xquery.com/options/features';",
      "declare option o:enable 'hof';",
      "declare variable $result external; ",
      xs:string($expResult));
    variable $queryKey := xqxq:prepare-main-module($queryText),
             $queryKeyResult := xqxq:bind-variable($queryKey,
                                                  xs:QName('result'),
                                                  $result),
             $queryResult := xqxq:evaluate($queryKey);
   
   if($queryResult)
   then ()
   else concat("Assertion ", $expResult, " failed")
  }
  } catch * {
    concat("&#xA;Assertion '",
           $expResult,
           "'&#xA; failed with error ",
           $err:code, " : ", $err:description)
  }
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-count :)
declare %private function eval:assert-count(
  $result    as item()*,
  $expResult as element()
) as xs:string? {
  if(count($result) eq xs:integer($expResult))
  then ()
  else "Actual number of items is different than the expected number of items."
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-deep-eq :)
declare %private %ann:sequential function eval:assert-deep-eq(
  $result    as item()*,
  $expResult as element()
) as xs:string? {
  try {
  {
    variable $queryText := concat(
      "xquery version '3.0';",
      "declare namespace o = 'http://www.zorba-xquery.com/options/features';",
      "declare option o:enable 'hof';",
      "declare variable $x external;",
      "let $y := (",string(data($expResult)),") return ",
      "every $i in 1 to max((count($x),count($y))) satisfies deep-equal($x[$i],$y[$i])");
    variable $queryKey := xqxq:prepare-main-module($queryText),
             $queryKeyResult := xqxq:bind-variable($queryKey,
                                                   xs:QName('x'),
                                                   $result),
             $queryResult := xqxq:evaluate($queryKey);
    if($queryResult)
    then ()
    else concat("&#xA;Result is not deep-equal to '", $expResult, "'&#xA;")
  }
  } catch * {
    concat("&#xA;Assert-deep-eq '",
          $expResult,
          "'&#xA; failed with error ",
          $err:code,
          " : ",
          $err:description)
  }
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-empty :)
declare %private function eval:assert-empty(
  $result    as item()*
) as xs:string? {
  if(empty($result))
  then ()
  else "&#xA;Result is not empty as expected"
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-eq :)
declare %private %ann:sequential function eval:assert-eq(
  $result    as item()*,
  $expResult as element()
) as xs:string? {
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
      else concat($type,"(", data($expResult), ")"));
    variable  $queryKey := xqxq:prepare-main-module($queryText);
    
    xqxq:bind-variable($queryKey,
                      xs:QName('x'),
                      $result);
    variable $queryResult := xqxq:evaluate($queryKey);
    if($queryResult)
    then ()
    else concat("&#xA;Assert-eq: Result '",
                string-join(util:serialize-result($result),' '),
                "' &#xA;doesn't match expected item '",
                xs:string($expResult),
                "'.")
  }
  } catch * {
    concat("&#xA;Comparison to '",
            $expResult/text(),
            "' failed with error: ",
            $err:code,
            " : ",
            $err:description)
  }
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-true :)
declare %private function eval:assert-true(
  $result as item()*
) as xs:string? {
  if($result eq fn:true())
  then ()
  else "&#xA;Query doesn't evaluate to true."
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-false :)
declare %private function eval:assert-false(
  $result as item()*
) as xs:string? {
  if($result eq fn:false())
  then ()
  else "&#xA;Query doesn't evaluate to false."
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-permutation :)
declare %private %ann:sequential function eval:assert-permutation(
  $result    as item()*,
  $expResult as element()
) as xs:string? {
  try {
  {
    variable $queryText := concat(
      "xquery version '3.0';",
      "declare namespace o = 'http://www.zorba-xquery.com/options/features';",
      "declare option o:enable 'hof';",
      "declare variable $x external;",
      "let $y := (",string(data($expResult)),") return ",
      (: if count(intersection(M1,M2)) = count(union(M1,M2)) = count(M1) then the sequences are identical :)
      "(count(distinct-values($x[ . = $y])) = count(distinct-values(($x, $y)))) = count(distinct-values($x))");
    variable $queryKey := xqxq:prepare-main-module($queryText),
             $queryKeyResult := xqxq:bind-variable($queryKey,
                                                  xs:QName('x'),
                                                  $result),
             $queryResult := xqxq:evaluate($queryKey);
    if($queryResult)
    then ()
    else concat("&#xA;Result isn't a permutation of '",
                $expResult,
                "'&#xA;")
  }
  } catch * {
    concat("&#xA;Assert-permutation failed with error: ",
            $err:code,
            " : ",
            $err:description)
  }
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-xml :)
declare %private function eval:assert-xml(
  $result    as item()*,
  $expResult as element()
) {
(:TODO call xml-canonicalization after bug #1076919 is implemented.:)
  try {
    let $serRes := util:serialize-result($result),
        $result1 as xs:string := string-join($serRes,''),
        $result2 as xs:string := string-join($serRes,' ')
    return
      if((normalize-space($result1) eq normalize-space(string($expResult))) or
         (normalize-space($result2) eq normalize-space(string($expResult))))
      then ()
      else concat("&#xA;Result '",
                  $result1,
                  "'&#xA; is different from the expected result &#xA;'",
                  string($expResult),
                  "'.")
  } catch * {
    concat("&#xA;Assert-xml failed with error:",
            $err:code,
            " : ",
            $err:description)
  }
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-serialization-error :)
declare %private %ann:sequential function eval:assert-serialization-error(
  $result    as item()*,
  $expResult as element()
) as xs:string? {
  try {
    let $serializedResult as xs:string := string-join(
                                            util:serialize-result($result), '')
    return
      concat("&#xA;Expected serialization error but got result: ",
                $serializedResult)
  } catch * {
    eval:error((),
              $expResult,
              $err:code,
              $err:description,
              fn:true())
  }
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_serialization-matches :)
declare %private function eval:serialization-matches(
  $result    as item()*,
  $expResult as element()
) as xs:string? {
  let $serResult := string-join(util:serialize-result($result,
                                                      $util:serParamXml),
                                ''),
      $serExpResult := string-join(util:serialize-result(data($expResult),
                                                        $util:serParamXml),
                                  '')
  let $matchesFlags := data($expResult/@flags)
  return
    if(exists($matchesFlags))
    then
      if(matches($serResult, $serExpResult, $matchesFlags))
      then ()
      else concat("&#xA;Expected '",
                  $serResult,
                  "'&#xA; does not match  &#xA;'",
                  $serExpResult,
                  "' with flags '",
                  $matchesFlags,
                  "'")
    else
      if(matches($serResult, $serExpResult))
      then ()
      else concat("&#xA;Expected ",
                  $serResult,
                  "'&#xA; does not match  &#xA;'",
                  $serExpResult,
                  "'")
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-string-value :)
declare %private function eval:assert-string-value(
  $result    as item()*,
  $expResult as element()
) as xs:string? {
  try {
    let $serRes := string-join(util:serialize-result($result), ' '),
        $res := if (empty($expResult[@normalize-space="true"]))
                then $serRes
                else normalize-space($serRes),
        $expRes :=  if (empty($expResult[@normalize-space="true"]))
                    then xs:string($expResult)
                    else normalize-space(xs:string($expResult))
    return
      if($res eq $expRes)
      then ()
      else concat("&#xA;Expected '",
                  $expRes,
                  "'&#xA; found  &#xA;'",
                  $res,
                  "'")
  } catch * {
    concat("&#xA;String-value failed with error: ",
           $err:code,
           " : ",
           $err:description)
  }
};

(: http://dev.w3.org/2011/QT3-test-suite/catalog-schema.html#elem_assert-type :)
declare %private %ann:sequential function eval:assert-type(
  $result    as item()*,
  $expResult as element()
) as xs:string? {
  try {
  {
    variable $queryText := concat( "declare variable $x external; $x instance of ",
                                  data($expResult));
    variable $queryKey := xqxq:prepare-main-module($queryText),
             $queryKeyResult := xqxq:bind-variable($queryKey,
                                                  xs:QName('x'),
                                                  $result),
             $queryResult := xqxq:evaluate($queryKey);
    if($queryResult)
    then ()
    else concat("&#xA;Result doesn't have type '",
                data($expResult),
                "'")
  }
  } catch * {
    concat("&#xA;Assert-type failed with error: ",
           $err:code,
           " : ",
           $err:description)
  }
};
