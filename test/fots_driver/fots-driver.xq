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
 : Zorba FOTS driver
 : @author Sorin Nasoi
 :)

module namespace driver =
  "http://www.zorba-xquery.com/fots-driver";

import module namespace functx =
  "http://www.functx.com/";

import module namespace xqxq =
  "http://www.zorba-xquery.com/modules/xqxq";
import module namespace datetime  =
  "http://www.zorba-xquery.com/modules/datetime";

import module namespace eval =
  "http://www.zorba-xquery.com/fots-driver/evaluate" at "evaluate.xq";
import module namespace env =
  "http://www.zorba-xquery.com/fots-driver/environment" at "environment.xq";
import module namespace util =
  "http://www.zorba-xquery.com/fots-driver/util" at "util.xq";
import module namespace fots-err =
  "http://www.zorba-xquery.com/fots-driver/errors" at "errors.xq";

declare default element namespace "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace err =
  "http://www.w3.org/2005/xqt-errors";
declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace ann =
  "http://www.zorba-xquery.com/annotations";

(:~
 : Loops through the FOTS catalog and returns all available test set names.
 : @param $fotsPath path to the FOTS catalog file.
 : @param $testSetPrefixes name/criteria for the test sets
 : (empty string means all).
 : @return available FOTS test sets.
 :)
declare %ann:nondeterministic function driver:list-test-sets(
  $fotsPath         as xs:string,
  $testSetPrefixes  as xs:string*
) as xs:string* {
  let $doc := doc(resolve-uri($fotsPath))
  return
    if(string-join($testSetPrefixes,'') = '')
    then
      for $testSet in $doc/fots:catalog/fots:test-set
      return data($testSet/@name)
    else
      for $prefix in $testSetPrefixes
        for $testSet in $doc/fots:catalog/fots:test-set[starts-with(@name, $prefix)]
        return data($testSet/@name)
};

(:~
 : Loops through the given test sets and returns the corresponding test cases.
 : @param $fotsPath path to the FOTS catalog file.
 : @param $testSetPrefixes name/criteria for the test sets
 : (empty string means all).
 : @return available FOTS test cases.
 :)
declare %ann:nondeterministic function driver:list-test-cases(
  $fotsPath         as xs:string,
  $testSetPrefixes  as xs:string*
) as xs:string* {
  let $doc := doc(resolve-uri($fotsPath)),
      $baseUri:= resolve-uri(util:parent-folder($fotsPath))
  return
    if(string-join($testSetPrefixes,'') = '')
    then
      for $testSet in $doc/fots:catalog/fots:test-set
      let $testSetDoc := doc(resolve-uri($testSet/@file, $baseUri))
      return data($testSetDoc//fots:test-case/@name)
    else
      for $prefix in $testSetPrefixes
        for $testSet in $doc/fots:catalog/fots:test-set[starts-with(@name, $prefix)]
        let $testSetDoc := doc(resolve-uri($testSet/@file, $baseUri))
        return data($testSetDoc//fots:test-case/@name)
};

(:~
 : Loops through the given test sets and returns the corresponding test cases.
 : @param $fotsPath path to the FOTS catalog file.
 : @param $testSetPrefixes name/criteria for the test sets
 : (empty string means all).
 : @param $testCasePrefixes name/criteria for the test cases
 : (empty string means all).
 : @return available FOTS test cases.
 :)
declare %ann:nondeterministic function driver:list-test-cases(
  $fotsPath         as xs:string,
  $testSetPrefixes  as xs:string*,
  $testCasePrefixes as xs:string*
) as xs:string* {
  let $doc := doc(resolve-uri($fotsPath)),
      $baseUri:= resolve-uri(util:parent-folder($fotsPath)),
      $testCaseNames := driver:list-test-cases($fotsPath, $testSetPrefixes)
  return
    for $prefix in $testCasePrefixes
    return
      for $name in $testCaseNames
      where starts-with($name,
                        $prefix)
      return $name
};

(:~
 : Loops through all the test cases and returns those that have a 'test' node
 : that matches given pattern using given flags.
 : @param $fotsPath path to the FOTS catalog file.
 : @param $pattern pattern.
 : @param $flags flags.
 : @return available FOTS test cases matching given pattern and flags.
 :)
declare %ann:nondeterministic function driver:list-matching-test-cases(
  $fotsPath as xs:string,
  $pattern  as xs:string,
  $flags    as xs:string?
) as xs:string* {
  let $doc := doc(resolve-uri($fotsPath)),
      $baseUri:= resolve-uri(util:parent-folder($fotsPath))
  return
    for $testSet in $doc/fots:catalog/fots:test-set
    let $uri := resolve-uri($testSet/@file, $baseUri),
        $testSetDoc := doc($uri)
      for $testCase in $testSetDoc//test-case
      where matches(util:get-value($testCase, 
                                  util:parent-folder($uri),
                                  "test"),
                   $pattern,
                   $flags)
      return
        concat(resolve-uri($testSet/@file, $baseUri),
              ", test name:",
              data($testCase/@name))
};

declare %private function driver:list-assertions(
  $case as element(fots:test-case)
) as xs:string* {
  distinct-values(for $assert in $case/result/descendant-or-self::*
                  return local-name-from-QName(node-name($assert)))
};

(:~
 : Loops through the FOTS catalog and evaluates all test cases that have
 : a certain assert-type.
 : This is useful for testing the implementation of a certain assert type.
 : @param $FOTSCatalogFilePath path to the FOTS catalog file.
 : @param $FOTSZorbaManifestPath the path to the file that describes optional
 : features and implementation defined items in Zorba.
 : @param $testSetPrefixes name/criteria for the test sets (empty string
 : means all).
 : @param $testCasePrefixes name/criteria for the test cases (empty string
 : means all).
 : @param $exceptedTestCases lists of test cases that should not be run(empty
 : string means all tests will be run).
 : @param $exceptedTestSets lists of test sets that should not be run(empty 
 : string means all tests will be run).
 : @param $assert lists of tests that contain a certain assert-type(empty
 : string means all tests will be run).
 : @param $verbose if set to TRUE it will also output the actual failures.
 : @param $showResult if set to TRUE it will also show the actual result of the
 : Query run.
 : @return an element containing all failed tests
 :)
declare %ann:sequential function driver:run-fots(
  $FOTSCatalogFilePath    as xs:string,
  $FOTSZorbaManifestPath  as xs:string,
  $testSetPrefixes        as xs:string*,
  $testCasePrefixes       as xs:string*,
  $exceptedTestCases      as xs:string*,
  $exceptedTestSets       as xs:string*,
  $assert                 as xs:string*,
  $verbose                as xs:boolean,
  $showResult             as xs:boolean
) as element(fots:test-cases) {
  try {
  let $FOTSCatalog := doc(trace(resolve-uri($FOTSCatalogFilePath), 
                              "The path to FOTS catalog.xml was set to: ")),
      $FOTSZorbaManifest := doc(trace(resolve-uri($FOTSZorbaManifestPath),
                                    "The path to FOTSZorbaManifest was set to:"))
  return driver:run($FOTSCatalog,
                    resolve-uri(util:parent-folder($FOTSCatalogFilePath)),
                    $FOTSZorbaManifest,
                    $testSetPrefixes,
                    $testCasePrefixes,
                    $exceptedTestCases,
                    $exceptedTestSets,
                    trace($assert,          "The filter for 'assert name' was set to: "),
                    trace($verbose,         "'Verbose' parameter was set to: "),
                    $showResult)
  }
  catch * {
    error($err:code,
          concat("&#xA;Please make sure the passed 'fotsPath' points to the",
                 "exact location of the FOTS catalog.xml:&#xA;",
                 resolve-uri($FOTSCatalogFilePath),
                 "&#xA;and that the passed 'fotsZorbaManifestPath' points to",
                 "a file in the same folder as cli.xq:&#xA;",
                 resolve-uri($FOTSZorbaManifestPath)))
  }
};

(:~
 : Loops through the FOTS catalog and evaluates all test cases
 :
 : @param $FOTSCatalog the FOTS catalog.xml file.
 : @param $FOTSZorbaManifest the file that describes optional features and
 : implementation defined items in Zorba.
 : @param $testSetPrefixes name/criteria for the test sets (empty string means
 : all).
 : @param $testCasePrefixes name/criteria for the test cases (empty string
 : means all).
 : @param $exceptedTestCases lists of test cases that should not be run(empty
 : string means all tests will be run).
 : @param $exceptedTestSets lists of test sets that should not be run(empty
 : string means all tests will be run).
 : @param $assert lists of tests that contain a certain assert-type(empty 
 : string means all tests will be run).
 : @param $verbose if set to TRUE it will also output the actual failures.
 : @param $showResult if set to TRUE it will also show the actual result of the
 : Query run.
 : @return an element containing all failed tests
 :)
declare %ann:sequential function driver:run(
  $FOTSCatalog        as document-node(),
  $catalogBaseURI     as xs:anyURI,
  $FOTSZorbaManifest  as document-node(),
  $testSetPrefixes    as xs:string*,
  $testCasePrefixes   as xs:string*,
  $exceptedTestCases  as xs:string*,
  $exceptedTestSets   as xs:string*,
  $assert             as xs:string*,
  $verbose            as xs:boolean,
  $showResult         as xs:boolean
) as element(fots:test-cases) {
    <test-cases>{
      let $catalogTestSetNames := $FOTSCatalog//fots:test-set/@name,
          $testSetNames :=  if ($testSetPrefixes = '')
                            then functx:value-except($catalogTestSetNames,
                                                     $exceptedTestSets)
                            else functx:value-except(
                                  functx:value-intersect($testSetPrefixes,
                                                         $catalogTestSetNames),
                                  $exceptedTestSets)
      for $testSetName in $testSetNames
      let $testSet := $FOTSCatalog//fots:test-set[@name=$testSetName],
          $testSetURI := resolve-uri($testSet/@file,
                                     $catalogBaseURI),
          $testSetDoc := doc($testSetURI),
          $depMet as xs:string*:= env:check-dependencies($testSetDoc/fots:test-set/fots:dependency,
                                                         $FOTSZorbaManifest)
      return
      if(exists($depMet))
      then <test-set name="{$testSetName}">
      {
        for $testCase in $testSetDoc/fots:test-set/fots:test-case
        let $envName := data($testCase/fots:environment/@ref),
            $envTestSet := $testSetDoc/fots:test-set/fots:environment[@name = $envName],
            $envCatalog := $FOTSCatalog/fots:catalog/fots:environment[@name = $envName],
            $shouldRun  := if ($testCasePrefixes = '')
                           then functx:value-except(xs:string(data($testCase/@name)),
                                                    $exceptedTestCases)
                           else functx:value-except(
                                  functx:value-intersect(data($testCase/@name),
                                                         $testCasePrefixes),
                                  $exceptedTestCases),
            (:true if the tests-case has an assertion type that is requested :)
            $hasReqAssert := (($assert = '') or
                              exists(functx:value-intersect(
                                      driver:list-assertions($testCase),
                                                             $assert)))
          where $shouldRun and $hasReqAssert
          return
            driver:not-applicable($testCase,
                                  $envTestSet,
                                  string-join($depMet,''),
                                  $verbose)
        }</test-set>
        else <test-set name="{$testSetName}">
        {
          for $testCase in $testSetDoc/fots:test-set/fots:test-case
          let $envName := data($testCase/fots:environment/@ref),
              $envTestSet := $testSetDoc/fots:test-set/fots:environment[@name = $envName],
              $envCatalog := $FOTSCatalog/fots:catalog/fots:environment[@name = $envName],
              $shouldRun  := if ($testCasePrefixes = '')
                             then functx:value-except(xs:string(data($testCase/@name)),
                                                      $exceptedTestCases)
                              else functx:value-except(
                                     functx:value-intersect(data($testCase/@name),
                                                            $testCasePrefixes),
                                     $exceptedTestCases),
            (:true if the tests-case has an assertion type that is requested :)
              $hasReqAssert := (($assert = '') or
                              exists(functx:value-intersect(driver:list-assertions($testCase),
                                                            $assert)))
          where $shouldRun and $hasReqAssert
          return
            if(exists(env:check-dependencies($testCase/fots:dependency,
                                             $FOTSZorbaManifest)))
            then driver:not-applicable( $testCase,
                                        $envTestSet,
                                        string-join(distinct-values(env:check-dependencies($testCase/fots:dependency,
                                                                                           $FOTSZorbaManifest)),
                                                   ''),
                                        $verbose)
            else if(empty($envTestSet))
            then driver:test( $FOTSZorbaManifest,
                              $testCase,
                              $envCatalog,
                              $catalogBaseURI,
                              ($testCase/fots:dependency,
                               $testSetDoc/fots:test-set/fots:dependency),
                              $testSetName,
                              $testSetURI,
                              $verbose,
                              $showResult)
            else driver:test( $FOTSZorbaManifest,
                              $testCase,
                              $envTestSet,
                              $testSetURI,
                              ($testCase/fots:dependency,
                               $testSetDoc/fots:test-set/fots:dependency),
                              $testSetName,
                              $testSetURI,
                              $verbose,
                              $showResult)
        }</test-set>
    }</test-cases>
};

(:~
 : Creates the complete query that will be evaluated by adding the necessary
 : XQXQ URL resolvers.
 : @param $queryText the test-case/test after all the additional prolog
 : statements were added.
 : @param $case the test case.
 : @param $env the environment.
 : @param $envBaseURI URI of the environment.
 : @param $testSetBaseURI URI of the test set that defines the test case.
 : @return the query that will be evaluated.
 :)
declare %private function driver:create-XQXQ-query(
  $queryText      as xs:string,
  $case           as element(fots:test-case),
  $env            as element(fots:environment)?,
  $envBaseURI     as xs:anyURI?,
  $testSetBaseURI as xs:anyURI
) as xs:string {
  let $resolver as xs:string? := env:resolver($case,
                                              $env,
                                              $envBaseURI,
                                              $testSetBaseURI)
  return string-join(
  ("import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';",
  if (exists($resolver))
  then $resolver
  else (),
  (concat("variable $queryID := xqxq:prepare-main-module('",
          "&#xA;",
          replace($queryText,"'","''"),
          "'",
          "&#xA;",
          if (exists($resolver)) 
          then ", resolver:url-resolver#2, ());"
          else ");")),
          env:set-context-item($env, $envBaseURI),
          env:set-context-item($case/fots:environment,
                               $testSetBaseURI),
          env:set-variables($env,
                            $envBaseURI),
          env:set-variables($case/environment,
                            $testSetBaseURI),
          "xqxq:evaluate($queryID)"
   ),
  "&#xA;")
};

(:~
 : XQXQ invoke.
 : @param $xqxqQueryText the query that will be run.
 : @param $case the test case.
 : @return the result of running the query with XQXQ.
 :)
declare %private %ann:sequential function driver:xqxq-invoke(
  $xqxqQueryText  as xs:string,
  $case           as element(fots:test-case),
  $showResult     as xs:boolean?,
  $testSetBaseURI as xs:anyURI
) {
  try {
    {
      variable $queryKey := xqxq:prepare-main-module($xqxqQueryText);
      variable $queryResult := xqxq:evaluate-sequential($queryKey);
      (:TODO check if this works:)
      (:variable $expResult := util:get-value($case, $testSetBaseURI, "result");:) 
      eval:result($queryResult,
                  $case/fots:result/*,
                  $showResult)
    }
  } catch * {
    eval:error((),
               $case/fots:result/*,
               $err:code,
               $err:description,
               $showResult)
  }
};

(:~
 : Runs a single test case.
 :
 : @param $FOTSZorbaManifest the file that describes optional features and
 : implementation defined items in Zorba.
 : @param $case test case.
 : @param $env the environment.
 : @param $envBaseURI the relative URI used to calculate the full URI for the
 : different children of the environment that have a "file" attribute.
 : @param $deps the dependencies that should be checked for given test case.
 : @param $testSetName the name of the test set.
 : @param $testSetBaseURI the URI of the test set.
 : @param $verbose xs:boolean indicating if a result should be returned in case
 : of success or not.
 : @return the result of running the test case depending on $verbose.
 :)
declare %ann:sequential function driver:test(
  $FOTSZorbaManifest  as document-node(),
  $case               as element(fots:test-case),
  $env                as element(fots:environment)?,
  $envBaseURI         as xs:anyURI?,
  $deps               as element(fots:dependency)*,
  $testSetName        as xs:string?,
  $testSetBaseURI     as xs:anyURI,
  $verbose            as xs:boolean,
  $showResult         as xs:boolean?
) as element(fots:test-case)? {
(:TODO Cover the "(:%VARDECL%:)"when there are tests in FOTS that use it:)
try {
{
  variable $queryName := trace(data($case/@name),
                              "processing test case :");
 
  variable $test := util:get-value($case,
                                   $testSetBaseURI,
                                   "test");
  variable $enableHOF := env:enable-HOF-feature(($deps, $case//fots:dependency),
                                                $test);
  variable $query := string-join((env:add-xquery-30(($deps, $case//fots:dependency),
                                                   $test),
                                  env:decl-def-elem-namespace($env,
                                                              $case/fots:environment),
                                  env:decl-base-uri($env,
                                                    $case/fots:environment),
                                  env:decl-namespaces($env,
                                                      $case,
                                                      $testSetBaseURI),
                                  $enableHOF,
                                  env:decl-decimal-formats(($env/fots:decimal-format,
                                                           $case/fots:environment/fots:decimal-format)),
                                  env:add-var-decl($env,
                                                   $case),
                                  $test
                                  ),"&#xA;"),
           $xqxqQuery := driver:create-XQXQ-query($query,
                                                  $case,
                                                  $env,
                                                  $envBaseURI,
                                                  $testSetBaseURI),
           $startDateTime := datetime:current-dateTime (),
           $result := driver:xqxq-invoke($xqxqQuery,
                                         $case,
                                         $showResult,
                                         $testSetBaseURI),
           $duration := (datetime:current-dateTime () - $startDateTime);

           if(empty($result))
           then driver:pass($case,
                            $result,
                            $xqxqQuery,
                            $env,
                            (),
                            $duration,
                            $verbose)

(: if the exact error code was not found, report the test as 'Pass' 
   with an attribute correctError=false :)
           else if(exists($result) and
                   contains(string-join($result,''), "Expected error:") and
                   contains(string-join($result,''), "Found error:"))
           then driver:pass($case,
                            $result,
                            $xqxqQuery,
                            $env,
                            $result,
                            $duration,
                            $verbose)
           else
             driver:fail($case,
                         $result,
                         $xqxqQuery,
                         $testSetName,
                         $env,
                         $duration,
                         $verbose)
}
} catch * {
  driver:fail($case, 
              <result>{$err:description}</result>,
              "",
              $testSetName,
              $env,
              xs:dayTimeDuration("PT0S"),
              $verbose)
}
};

(:~
 : Gives feedback on a test case that is not run when dependencies are not met.
 :
 : @param $case test case.
 : @param $dependencyError test error returned by the dependency checking.
 : @return the test case.
 :)
declare  %private %ann:sequential function driver:not-applicable(
  $case             as element(fots:test-case),
  $env              as element(fots:environment)?,
  $dependencyError  as xs:string,
  $verbose          as xs:boolean
) as element(fots:test-case)? {
  trace(data($case/@name), "processing test case :");
  trace($dependencyError, "Dependency error :");
  if($verbose)
  then
  {
    let $tmp := $case
    return {
      insert node
      attribute result{'not applicable'}
      as last into $tmp;
      
      insert node
      attribute comment{$dependencyError}
      as last into $tmp;
      
      insert node
        <info>
          { $env }
        </info>
      as last into $tmp;
      
      delete node $tmp/description;
      delete node $tmp/created;
      
      $tmp
      }
  }
  else
    <test-case  name="{data($case/@name)}"
                result="not applicable"
                comment="{$dependencyError}" />
};

(:~
 : Gives feedback on a test case run with success.
 :
 : @param $case test case.
 : @return the test case after certain information was added.
 :)
declare  %private %ann:sequential function driver:pass(
  $case         as element(fots:test-case),
  $result       as item()*,
  $zorbaQuery   as xs:string,
  $env          as element(fots:environment)?,
  $comment      as xs:string?,
  $duration     as xs:dayTimeDuration,
  $verbose      as xs:boolean
) as element(fots:test-case)? {
  if($verbose)
  then
  {
    let $tmp := $case
    return {
      insert node
      attribute result{'pass'}
      as last into $tmp;

      if(exists($comment)) then
        insert node
        attribute correctError{'false'}
        as last into $tmp;
      else ();

      if(exists($comment)) then
        insert node
        attribute comment{$comment}
        as last into $tmp;
      else ();
      
      insert node
      attribute executionTime{$duration}
      as last into $tmp;

      insert node
        <info>
          { $env }
          <query>{ $zorbaQuery }</query>
          {$result}
        </info>
      as last into $tmp;

      delete node $tmp/description;
      delete node $tmp/created;

      $tmp
    }
  }
  else if(empty($comment))
  then <test-case name="{data($case/@name)}"
                  result="pass"
                  executionTime="{$duration}" />
  else <test-case name="{data($case/@name)}"
                  result="pass"
                  correctError="{empty($comment)}"
                  executionTime="{$duration}" />
};

(:~
 : Gives feedback on a test case run without success.
 :
 : @param $case test case.
 : @return the test case after certain information was added.
 :)
declare %private %ann:sequential function driver:fail(
  $case         as element(fots:test-case),
  $result       as item()*,
  $zorbaQuery   as xs:string,
  $testSetName  as xs:string?,
  $env          as element(fots:environment)?,
  $duration     as xs:dayTimeDuration,
  $verbose      as xs:boolean
) as element(fots:test-case)? {
  trace($testSetName, "test set name");
  trace("above test case failed", "result");

  if($verbose)
  then
  {
    let $tmp := $case
    return {
      insert node
      attribute result{'fail'}
      as last into $tmp;
      
      insert node
      attribute executionTime{$duration}
      as last into $tmp;
      
      insert node
        <info>
          { $env }
          <query>{ $zorbaQuery }</query>
          {$result}
        </info>
      as last into $tmp;
      
      delete node $tmp/description;
      delete node $tmp/created;
      
      $tmp
    }
  }
  else <test-case name="{data($case/@name)}"
                  result="fail"
                  executionTime="{$duration}"/>
};
