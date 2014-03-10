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
  "http://www.functx.com";

import module namespace datetime  =
  "http://zorba.io/modules/datetime";

import module namespace eval =
  "http://www.zorba-xquery.com/fots-driver/evaluate" at "evaluate.xq";

import module namespace feedback =
  "http://www.zorba-xquery.com/fots-driver/feedback" at "feedback.xq";

import module namespace execute =
  "http://www.zorba-xquery.com/fots-driver/execute" at "execute.xq";

import module namespace env =
  "http://www.zorba-xquery.com/fots-driver/environment" at "environment.xq";

import module namespace util =
  "http://www.zorba-xquery.com/fots-driver/util" at "util.xq";

import module namespace fots-err =
  "http://www.zorba-xquery.com/fots-driver/errors" at "errors.xq";


declare namespace err =
  "http://www.w3.org/2005/xqt-errors";

declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace ann =
  "http://zorba.io/annotations";

(:~
 : Returns the names of all qualifying test-sets.
 :
 : A test-set qualifies if its name starts with one of the prefixes listed in
 : $testSetPrefixes. Empty sequence means all test-sets qualify.
 :
 : @param $fotsPath path to the FOTS catalog file.
 : @param $testSetPrefixes name criteria for the test-sets
 :        (empty sequence means all).
 : @return names of qualifying FOTS test-sets.
 :)
declare %ann:nondeterministic function driver:list-test-sets(
  $fotsPath         as xs:string,
  $testSetPrefixes  as xs:string*
) as xs:string*
{
  let $doc := doc(resolve-uri($fotsPath))
  return
    if (empty($testSetPrefixes)) then
      for $testSet in $doc/fots:catalog/fots:test-set
      return data($testSet/@name)
    else
      for $prefix in $testSetPrefixes
      for $testSet in $doc/fots:catalog/fots:test-set[starts-with(@name, $prefix)]
      return data($testSet/@name)
};


(:~
 : Returns the names of all qualifying test-cases.
 :
 : A test-case qualifies if (a) it belongs to a qualifying test-set, and (b)
 : its applicable dependencies include a user-provided dependency, or no
 : dependency was provided by the user, and (c) its expected-result assertions
 : include at least one of the assertions in a user-provided set of assertions,
 : or no expected-result assertions were provided by the user.
 :
 : A test-set qualifies if its name is specified in $testSetNames.
 : If $testSetNames is the empty sequence, then all test-sets qualify.
 :
 : The filtering dependency is given as a string, which may be empty (signifying
 : no dependency) or of the form "depValue_depSatisfied" (e.g., "XQ30+_true"),
 : or just "depValue" (in which case "true" is assumed as the value of the
 : satisfied attribute). A test-case qualifies only if it has at least one
 : dependency whose @value and @satisfied attributes are equal to the filtering
 : depValue and depSatisfied.
 :
 : A filtering set of assertions is given as a sequence of strings. A test-case
 : qualifies if there is at least one element node under the <result> node of
 : the <test-case> whose local name is equal to one of the strings in the
 : filtering set.
 :
 : @param $fotsPath path to the FOTS catalog file.
 : @param $testSetNames name criteria for the test-sets
 :        (empty sequence means all test sets).
 : @param $dependency dependency used to filter test-cases.
 :        (empty string means no filtering).
 : @param $assert set of expected-result assertions used to filter test-cases.
 :        (empty sequence means no filtering).
 : @return names of qualifying FOTS test-cases.
 :)
declare %ann:nondeterministic function driver:list-test-cases(
  $fotsPath     as xs:string,
  $testSetNames as xs:string*,
  $dependency   as xs:string,
  $assert       as xs:string*
) as xs:string*
{
  let $doc := doc(resolve-uri($fotsPath))
  let $baseUri:= resolve-uri(util:parent-folder($fotsPath))
  return
    if (empty($testSetNames)) then
      for $testSet in $doc/fots:catalog/fots:test-set
      let $testSetDoc := doc(resolve-uri($testSet/@file, $baseUri))
      return driver:list-test-cases($testSetDoc, $dependency, $assert)
    else
      for $testSet in $doc/fots:catalog/fots:test-set
      let $testSetDoc := doc(resolve-uri($testSet/@file, $baseUri))
      where exists(index-of($testSetNames, $testSet/@name))
      return driver:list-test-cases($testSetDoc, $dependency, $assert)
};


(:~
 : Helper function. Returns the names of all qualifying test-cases within a
 : given test-set. A test-case qualifies if (a) its applicable dependencies
 : include a user-provided dependency, or no dependency was provided by the
 : user, and (b) its expected-result assertions include at least one of the
 : assertions in a user-provided set of assertions, or no expected-result
 : assertions were provided by the user.
 :
 : @param $testSetDoc root node of the xml document the specifies the test-set.
 : @param $dependency dependency used to filter test-cases.
 :        (empty string means no filtering).
 : @param $assert set of expected-result assertions used to filter test-cases.
 :        (empty sequence means no filtering).
 : @return names of qualifying FOTS test-cases.
 :)
declare %private function driver:list-test-cases(
  $testSetDoc as document-node(),
  $dependency as xs:string,
  $assert     as xs:string*
) as xs:string*
{
  if ($dependency eq '' and empty($assert)) then
  {
    $testSetDoc//fots:test-case/@name
  }
  else if ($dependency eq '') then
  {
    for $testCase in $testSetDoc//fots:test-case
    where functx:value-intersect(driver:list-assertions($testCase), $assert)
    return $testCase/@name
  }
  else
  {
    for $testCase in $testSetDoc//fots:test-case
    where
      driver:matches-dependency(($testSetDoc/fots:test-set/fots:dependency,
                                 $testCase/fots:dependency),
                                 $dependency)
      and
      (empty($assert) or
       functx:value-intersect(driver:list-assertions($testCase), $assert))

    return $testCase/@name
  }
};


(:~
 : Helper function to check whether a user-specified dependency (given as an
 : encoded string) "matches" at least one of the dependencies in a given list
 : of dependencies (given as a sequence of <dependency> elements)
 :)
declare %private function driver:matches-dependency(
  $dependencies as element(fots:dependency)*,
  $filter       as xs:string
) as xs:boolean
{
  if ($filter eq '') then
    fn:true()
  else
  {
    let $filter := tokenize($filter, '_')
    let $depValue := $filter[1]
    let $depSatisfied := if ($filter[2] eq 'true' or $filter[2] eq 'false')
                         then $filter[2]
                         else 'true'
    return
      if ($depSatisfied)
      then
        $dependencies[@value eq $depValue and @satisfied eq $depSatisfied] or
        $dependencies[@value eq $depValue and empty(@satisfied)]
      else
        $dependencies[@value eq $depValue and @satisfied eq $depSatisfied]
  }
};


(:~
 : Helper function to return the local names of all the nodes under a <result>
 : child of a given test-case.
 :)
declare %private function driver:list-assertions(
  $case as element(fots:test-case)
) as xs:string*
{
  distinct-values(for $assert in $case/fots:result/descendant-or-self::*
                  return local-name-from-QName(node-name($assert)))
};


(:~
 : For each qualifying test-case, this functions returns a string containing
 : the test-case name and the full file path of its associated test-set file.
 :
 : A test-case qualifies if its <test> node (which contains the query text)
 : matches the given pattern using the given flags.
 :
 : @param $fotsPath path to the FOTS catalog file.
 : @param $pattern pattern.
 : @param $flags flags.
 : @return names of qualifying test-case and the file path of their
 :         containing test-set files.
 :)
declare %ann:nondeterministic function driver:list-matching-test-cases(
  $fotsPath as xs:string,
  $pattern  as xs:string,
  $flags    as xs:string?
) as xs:string*
{
  let $doc := doc(resolve-uri($fotsPath))
  let $baseUri:= resolve-uri(util:parent-folder($fotsPath))
  return
    for $testSet in $doc/fots:catalog/fots:test-set
    let $uri := resolve-uri($testSet/@file, $baseUri)
    let $testSetDoc := doc($uri)
    for $testCase in $testSetDoc//fots:test-case
    where matches(util:get-value($testCase, util:parent-folder($uri), "test"),
                  $pattern,
                  $flags)
    return
      concat(resolve-uri($testSet/@file, $baseUri),
             ", test name:",
             data($testCase/@name))
};


(:~
 : This function is a wrapper over the private function driver:check-FOTS.
 :
 : Processing a test-case results in one of the following outcomes described in
 : http://dev.w3.org/2011/QT3-test-suite/guide/reporting.html:
 :
 : 'pass' The test-case was run and the assertion(s) was(were) satisfied.
 : 'fail' The test-case was run and the assertion(s) was(were) not satisfied.
 : 'wrongError' The test-case was run; the expected results permitted an error
 :              to be reported; the actual result was an error, but not with
 :              the expected error code.
 : 'n/a' The test-case was not run because it is not applicable to this
 :        implementation (for example, because it depends on optional features)
 : 'disputed' The test-case or its results, or the specification they rely on,
 :            are the subject of an unresolved bug report (which should be
 :            identified in the comment field).
 : 'tooBig' The test-case was not run because it exceeds limits imposed by the
 :          implementation or requires excessive resources.
 : 'notRun' The test-case was not run for unspecified reasons (for example
 :          an implementation might omit tests for features
 :          that have not been implemented)
 :
 : The subset of test-cases to process is specified via the $exceptedTestSets,
 : $testSetPrefixes, $testCasePrefixes, $dependency, and assertions parameters.
 : A test-case will be processed only if it satisfies all of the following
 : conditions:
 : (a) it belongs to a test-set whose name is not among the ones listed in the
 :     $exceptedTestSets parameter,
 : (b) $testSetPrefixes is the empty sequence, or the test-case belongs to a
 :     test-set whose name starts with a prefix listed in $testSetPrefixes,
 : (c) $testCasePrefixes is the empty sequence, or the name of the test-case
 :     starts with a prefix listed in $testCaseNames.
 : (d) $dependency is equal to the empty string or the dependencies applicable
 :     to the test-case include a user-provided dependency
 : (e) $assertions is empty or the expected-result assertions of the test-case
 :     include at least one of the assertions in $assertions
 :
 : @param $fotsPath path to the FOTS catalog file.
 : @param $zorbaManifestPath the path to the file that describes optional
 :        features and implementation-defined items in Zorba.
 : @param $testSetPrefixes prefixes to filter the test sets to process
 :        (empty seq means no filtering).
 : @param $exceptedTestSets names of test sets that should NOT be precessed.
 : @param $testCasePrefixes prefixes to filter the test cases to process
 :        (empty seq means no filtering).
 : @param $dependency dependency used to filter test-cases.
 :        (empty string means no filtering).
 : @param $assertions set of expected-result assertions used to filter test-cases.
 :        (empty sequence means no filtering).
 : @param $verbose if true, the resulting XML tree will contain more details
 :        about each processed test-case.
 : @param $expectedFailuresPath the path to the FOTSExpectedFailures.xml.
 : @param $ctestMode true if the known failures are to be reported as 'pass'
 :        instead of 'fail'.
 : @param $cliMode the cli command.
 : @param $usePlanSerializer if true the plan serializer is used.
 : @return an XML tree containing info about all the processed tests-cases
 :)
declare %ann:sequential function driver:run-fots(
  $fotsPath               as xs:string,
  $zorbaManifestPath      as xs:string,
  $testSetPrefixes        as xs:string*,
  $exceptedTestSets       as xs:string*,
  $testCasePrefixes       as xs:string*,
  $dependency             as xs:string,
  $assertions             as xs:string*,
  $verbose                as xs:boolean,
  $expectedFailuresPath   as xs:string,
  $ctestMode              as xs:boolean,
  $cliMode                as xs:string,
  $usePlanSerializer      as xs:boolean
) as element(fots:test-cases)
{
  trace($fotsPath, "Path to FOTS catalog.xml set to:");
  trace($expectedFailuresPath, "Path to FOTSExpectedFailures.xml set to:");
  trace($zorbaManifestPath, "Path to FOTSZorbaManifest set to :"); 
  trace($usePlanSerializer, "'usePlanSerializer' set to:");

  try
  {
    let $FOTSCatalog := doc(resolve-uri($fotsPath))
    let $zorbaManifest := doc(resolve-uri($zorbaManifestPath))
    let $expectedFailures := if($expectedFailuresPath ne '')
                             then doc(resolve-uri($expectedFailuresPath))
                             else ()

    let $testSetNames :=
    if(($cliMode = 'run-test-case') ||
       ($cliMode = 'run-test-set'))
    then $testSetPrefixes
    else
    {
      if (empty($testSetPrefixes) and empty($exceptedTestSets)) then
      {
        ()
      }
      else
      {
        let $testSetNames := driver:list-test-sets($fotsPath, $testSetPrefixes)
        return
          if (empty($testSetNames)) then
          {
            exit returning <fots:test-cases/>;
            ()
          }
          else
          {
            functx:value-except($testSetNames, $exceptedTestSets)
          }
      }
    }

    let $testCaseNames :=
    {
      if (empty($testCasePrefixes) and $dependency eq '' and empty($assertions))
      then
      {
        ()
      }
      else
      {
        let $testCaseNames := driver:list-test-cases($fotsPath,
                                                     $testSetNames,
                                                     $dependency,
                                                     $assertions)
        return
        if (empty($testCaseNames)) then
        {
          exit returning <fots:test-cases/>;
          ()
        }
        else if (empty($testCasePrefixes)) then
        {
          $testCaseNames
        }
        else
        {
          for $name in $testCaseNames
          where some $prefix in $testCasePrefixes satisfies starts-with($name, $prefix)
          return $name
        }
      }
    }

    return driver:check-FOTS($FOTSCatalog,
                             resolve-uri(util:parent-folder($fotsPath)),
                             $zorbaManifest,
                             $testSetNames,
                             $testCaseNames,
                             $expectedFailures,
                             $ctestMode,
                             $verbose,
                             $cliMode,
                             $usePlanSerializer)
  }
  catch err:FODC0002
  {
    error($err:code,
          $err:description)
  }
};


(:~
 : Process a specified test set and report the outcome for each containing
 : test case. This is a wrapper over driver:check-FOTS function.
 :
 : Processing a test-case results in one of the following outcomes described in
 : http://dev.w3.org/2011/QT3-test-suite/guide/reporting.html:
 :
 : 'pass' The test-case was run and the assertion(s) was(were) satisfied.
 : 'fail' The test-case was run and the assertion(s) was(were) not satisfied.
 : 'wrongError' The test-case was run; the expected results permitted an error
 :              to be reported; the actual result was an error, but not with
 :              the expected error code.
 : 'n/a' The test-case was not run because it is not applicable to this
 :        implementation (for example, because it depends on optional features)
 : 'disputed' The test-case or its results, or the specification they rely on,
 :            are the subject of an unresolved bug report (which should be
 :            identified in the comment field).
 : 'tooBig' The test-case was not run because it exceeds limits imposed by the
 :          implementation or requires excessive resources.
 : 'notRun' The test-case was not run for unspecified reasons (for example
 :          an implementation might omit tests for features
 :          that have not been implemented)
 :
 : The subset of test-cases to process is specified via the $exceptedTestSets,
 : $testSetName, $exceptedTestCases, $testCaseName, $dependency,
 : and $assertions parameters.
 : A test-case will be processed only if it satisfies all of the following
 : conditions:
 : (a) it belongs to a test-set whose name is not among the ones listed in the
 :     $exceptedTestSets parameter,
 : (b) the test-case belongs to a test-set whose name is $testSetName,
 : (c) the name of the test-case is $testCaseName.
 : (d) $dependency is equal to the empty string or the dependencies applicable
 :     to the test-case include a user-provided dependency.
 : (e) $assertions is empty or the expected-result assertions of the test-case
 :     include at least one of the assertions in $assertions.
 :
 : @param $fotsPath path to the FOTS catalog file.
 : @param $zorbaManifestPath the path to the file that describes optional
 :        features and implementation-defined items in Zorba.
 : @param $testSetName exact name of the test-set.
 : @param $exceptedTestSets names of test sets that should NOT be precessed.
 : @param $testCasePrefixes prefixes to filter the test cases to process
 :        (empty seq means no filtering).
 : @param $dependency dependency used to filter test-cases.
 :        (empty string means no filtering).
 : @param $assertions set of expected-result assertions used to filter test-cases.
 :        (empty sequence means no filtering).
 : @param $verbose if true, the resulting XML tree will contain more details
 :        about each processed test-case.
 : @param $expectedFailuresPath the path to the FOTSExpectedFailures.xml.
 : @param $ctestMode true if the known failures are to be reported as 'pass'
 :        instead of 'fail'.
 : @param $cliMode the cli command.
 : @param $usePlanSerializer if true the plan serializer is used.
 : @return an XML tree containing info about all the processed tests-cases
 :)
declare %ann:sequential function driver:run-test-set(
  $fotsPath               as xs:string,
  $zorbaManifestPath      as xs:string,
  $testSetName            as xs:string*,
  $exceptedTestSets       as xs:string*,
  $testCasePrefixes       as xs:string*,
  $dependency             as xs:string,
  $assertions             as xs:string*,
  $verbose                as xs:boolean,
  $expectedFailuresPath   as xs:string,
  $ctestMode              as xs:boolean,
  $cliMode                as xs:string,
  $usePlanSerializer      as xs:boolean
) as element(fots:test-cases)
{
  trace($fotsPath, "Path to FOTS catalog.xml set to:");
  trace($expectedFailuresPath, "Path to FOTSExpectedFailures.xml set to:");
  trace($zorbaManifestPath, "Path to FOTSZorbaManifest set to :");
  trace($usePlanSerializer, "'usePlanSerializer' set to:");
 
  try
  {
    let $FOTSCatalog := doc(resolve-uri($fotsPath))
    let $zorbaManifest := doc(resolve-uri($zorbaManifestPath))
    let $expectedFailures := doc(resolve-uri($expectedFailuresPath))
   
    let $testSetNames :=
    if(empty($testSetName)) then
    {
      if(empty($exceptedTestSets))
      then ()
      else for $testSet in $FOTSCatalog//fots:test-set
           where empty(index-of($testSet/@name, $exceptedTestSets))
           return xs:string($testSet/@name)
    }
    else
    {
      if(empty($exceptedTestSets))
      then $testSetName
      else functx:value-except($testSetName, $exceptedTestSets)
    }

    let $testCaseNames :=
    {
      if (empty($testCasePrefixes) and $dependency eq '' and empty($assertions))
      then
      {
        ()
      }
      else
      {
        let $testCaseNames := driver:list-test-cases($fotsPath,
                                                     $testSetNames,
                                                     $dependency,
                                                     $assertions)
        return
          if (empty($testCaseNames)) then
          {
            exit returning <fots:test-cases/>;
            ()
          }
          else if (empty($testCasePrefixes)) then
          {
            $testCaseNames
          }
          else
          {
            for $name in $testCaseNames
            where some $prefix in $testCasePrefixes satisfies starts-with($name, $prefix)
            return $name
          }
      }
    }

    return driver:check-FOTS($FOTSCatalog,
                             resolve-uri(util:parent-folder($fotsPath)),
                             $zorbaManifest,
                             $testSetNames,
                             $testCaseNames,
                             $expectedFailures,
                             $ctestMode,
                             $verbose,
                             $cliMode,
                             $usePlanSerializer)
  }
  catch err:FODC0002
  {
    error($err:code,
          $err:description)
  }
};


(:~
 : A helper function to process a specified subset of all test-cases and
 : report the outcome for each such test-case.
 :
 : The subset of test-cases to process is specified via the $testSetNames
 : and $testCaseNames parameters. A test-case will be processed only if it
 : satisfies all of the following conditions:
 : (a) $testSetNames is the empty sequence, or the test-case belongs to a
 :     test-set whose name is listed in $testSetNames,
 : (b) $testCaseNames is the empty sequence, or the name of the test-case
 :     appears in $testCaseNames.
 :
 : @param $FOTSCatalog the root node of the FOTS catalog document.
 : @param $catalogBaseURI the URI of the directory containing the FOTS catalog.
 : @param $FOTSZorbaManifest the root node of the doc that describes optional
 :        features and implementation-defined items in Zorba.
 : @param $testSetNames names of the test-sets to run (empty seq means all)
 : @param $testCaseNames names of the test-cases to run (empty seq means all)
 : @param $expectedFailures the root node of the ExpectedFailures.xml file.
 : @param $ctestMode true if the known failures are to be reported as 'pass'
 :        instead of 'fail'.
 : @param $verbose if true, the resulting XML tree will contain more details
 :        about each processed test-case.
 : @param $cliMode the cli command.
 : @param $usePlanSerializer if true the plan serializer is used.
 : @return an XML tree containing info about all the processed test-cases.
 :)
declare %private %ann:sequential function driver:check-FOTS(
  $FOTSCatalog        as document-node(),
  $catalogBaseURI     as xs:anyURI,
  $FOTSZorbaManifest  as document-node(),
  $testSetNames       as xs:string*,
  $testCaseNames      as xs:string*,
  $expectedFailures   as document-node()?,
  $ctestMode          as xs:boolean,
  $verbose            as xs:boolean,
  $cliMode            as xs:string,
  $usePlanSerializer  as xs:boolean
) as element(fots:test-cases)
{
  <fots:test-cases>{
  let $testSets := if (empty($testSetNames))
                   then $FOTSCatalog//fots:test-set
                   else $FOTSCatalog//fots:test-set[@name = $testSetNames]

  for $testSet in $testSets
  let $testSetName := $testSet/@name
  let $testSetURI := resolve-uri($testSet/@file, $catalogBaseURI)
  let $tsDoc := doc($testSetURI)
  return
  driver:check-test-set($FOTSCatalog/fots:catalog/fots:environment,
                        $catalogBaseURI,
                        $FOTSZorbaManifest,
                        $tsDoc,
                        $testSetURI,
                        $expectedFailures/failures/TestSet[@name eq $testSetName],
                        $ctestMode,
                        $testCaseNames,
                        $verbose,
                        $cliMode,
                        $usePlanSerializer)
  }</fots:test-cases>
};


(:~
 : Checks a single test-set.
 :
 : @param $catalogEnvironments all the 'environments' defined in the FOTS catalog.
 : @param $catalogBaseURI the URI of the directory that contains the FOTS catalog.
 : @param $FOTSZorbaManifest the root node of the doc that describes optional
 :        features and implementation-defined items in Zorba.
 : @param $tsDoc the root node of the test-set document.
 : @param $tsBaseURI the URI of the directory that contains the file of the
 :        associated test-set.
 : @param $expFailuresTS the 'TestSet' element from FOTSExpectedFailures.xml.
 : @param $ctestMode true if the known failures are to be reported as 'pass'
 :        instead of 'fail'.
 : @param $testCaseNames names of the test-cases to run (empty seq means all).
 : @param $verbose if true, the resulting XML tree will contain more details
 :        about the test-case.
 : @param $cliMode the cli command.
 : @param $usePlanSerializer if true the plan serializer is used.
 : @return an XML tree containing the result of checking/running the test-cases.
 :)
declare %private %ann:sequential function driver:check-test-set(
  $catalogEnvironments  as element(fots:environment)*,
  $catalogBaseURI       as xs:anyURI,
  $FOTSZorbaManifest    as document-node(),
  $tsDoc                as document-node(),
  $tsBaseURI            as xs:anyURI,
  $expFailuresTS        as element(TestSet)?,
  $ctestMode            as xs:boolean,
  $testCaseNames        as xs:string*,
  $verbose              as xs:boolean,
  $cliMode              as xs:string,
  $usePlanSerializer    as xs:boolean
) as element(fots:test-set)
{
let $testSetEnvironments := $tsDoc/fots:test-set//fots:environment/@name
let $tsDepMet := env:check-dependencies($tsDoc/fots:test-set/fots:dependency,
                                        $FOTSZorbaManifest)
let $tsName := $tsDoc/fots:test-set/@name
return
<fots:test-set name="{$tsName}">
{
  for $testCase in $tsDoc/fots:test-set/fots:test-case
  where empty($testCaseNames) or $testCaseNames[. eq $testCase/@name]
  return
  driver:check-test-case($expFailuresTS/Test[@name = $testCase/@name][1],
                        
                         $ctestMode,
                        
                         $testCase,
                        
                         $tsName,
                        
                         $tsBaseURI,
                        
                         $tsDepMet,
                        
                         $tsDoc/fots:test-set/fots:dependency,
                        
                         $FOTSZorbaManifest,
                        
                         if(empty($testCase/fots:environment/@ref))
                         then ()
                         else if (exists($catalogEnvironments/following-sibling::*[@name eq $testCase/fots:environment/@ref]))
                         then $catalogEnvironments/following-sibling::*[@name eq $testCase/fots:environment/@ref]
                         else $tsDoc/fots:test-set/fots:environment[@name eq $testCase/fots:environment/@ref],
                        
                         if(empty($testCase/fots:environment/@ref))
                         then ()
                         else if (exists($catalogEnvironments/following-sibling::*[@name eq $testCase/fots:environment/@ref]))
                         then $catalogBaseURI
                         else $tsBaseURI,
                        
                         $verbose,
                        
                         $cliMode,
                        
                         $usePlanSerializer)
  }
</fots:test-set>
};

(:~
 : Checks a single test-case.
 :
 : @param $expFailuresTC the 'Test' element from FOTSExpectedFailures.xml
 :        for the parent test-set.
 : @param $ctestMode true if the known failures are to be reported as 'pass'
 :        instead of 'fail'.
 : @param $testCase the test-case to run.
 : @param $tsName the name of the parent test-set.
 : @param $tsBaseURI the URI of the directory that contains the file of the
 :        associated test-set.
 : @param $deps the result of checking the test-set level dependencies.
 : @param $tsDependencies  the test-set level dependencies.
 : @param $FOTSZorbaManifest the root node of the doc that describes optional
 :        features and implementation-defined items in Zorba.
 : @param $env the non-local environment to use, if any. It is an environment
 :        specified either at the test-set level or at the catalog level and
 :        is referenced by the test-case.
 : @param $envBaseURI the URI of the directory containing the file where the
 :        environment is specified in. It is used to calculate the full URI
 :        for the different children of the <environment> that have a @file
 :        attribute.
 : @param $verbose if true, the resulting XML tree will contain more details
 :        about the test-case.
 : @param $cliMode the cli command.
 : @param $usePlanSerializer if true the plan serializer is used.
 : @return an XML tree containing the result of checking/running the test-case.
 :)
declare %ann:sequential function driver:check-test-case(
  $expFailureTC         as element(Test)?,
  $ctestMode            as xs:boolean,
  $testCase             as element(fots:test-case),
  $tsName               as xs:string,
  $tsBaseURI            as xs:anyURI,
  $tsDepMet             as xs:string*,
  $tsDependencies       as element(fots:dependency)*,
  $FOTSZorbaManifest    as document-node(),
  $env                  as element(fots:environment)?,
  $envBaseURI           as xs:anyURI?,
  $verbose              as xs:boolean,
  $cliMode              as xs:string,
  $usePlanSerializer    as xs:boolean
) as element(fots:test-case)?
{
  let $tcDepMet := env:check-dependencies($testCase/fots:dependency,
                                          $FOTSZorbaManifest)
  return
  if (exists($expFailureTC[@notRun="true"])) then
  {
    if($ctestMode or $expFailureTC/@finalStatus = "pass") then
      feedback:pass($testCase,
                    (),
                    (),
                    concat("Test case was not run because it is marked as",
                           " EXPECTED_FOTS_FAILURE SLOW in test/fots/CMakeLists.txt.",
                           "For details please check out https://bugs.launchpad.net/zorba/+bug/",
                           $expFailureTC/@bug))
    else
      feedback:too-big($testCase,
                      concat("For details please check out https://bugs.launchpad.net/zorba/+bug/",
                             $expFailureTC/@bug))
  }
  else if (exists($tsDepMet) or exists($tcDepMet)) then
  {
    feedback:not-applicable($testCase,
                            string-join(($tsDepMet, $tcDepMet), ''))
  }
  else
  {
    driver:run-test-case($testCase,
                         $env,
                         $envBaseURI,
                         ($testCase/fots:dependency,
                          $tsDependencies),
                         $tsName,
                         $tsBaseURI,
                         $verbose,
                         $expFailureTC,
                         $ctestMode,
                         $cliMode,
                         $usePlanSerializer)
  }
};

(:~
 : Runs a single test-case.
 :
 : @param $case the test-case to run.
 : @param $env the non-local environment to use, if any. It is an environment
 :        specified either at the test-set level or at the catalog level and
 :        is referenced by the test-case.
 : @param $envBaseURI the URI of the directory containing the file where the
 :        environment is specified in. It is used to calculate the full URI
 :        for the different children of the <environment> that have a @file
 :        attribute.
 : @param $deps the dependencies that should be checked for given test-case.
 :        These may be defined at test-set level and/or test-case level.
 : @param $testSetName the name of the test-set.
 : @param $testSetURI the URI of the directory that contains the file of the
 :        associated test-set.
 : @param $verbose if true, the resulting XML tree will contain more details
 :        about the test-case.
 : @param $expFailureTC the 'Test' element from the ExpectedFailures.xml file.
 : @param $ctestMode true if the known failures are to be reported as 'pass'
 :        instead of 'fail'.
 : @param $cliMode the cli command.
 : @param $usePlanSerializer if true the plan serializer is used.
 : @return an XML tree containing the result of running the test-case.
 :)
declare %private %ann:sequential function driver:run-test-case(
  $case               as element(fots:test-case),
  $env                as element(fots:environment)?,
  $envBaseURI         as xs:anyURI?,
  $deps               as element(fots:dependency)*,
  $testSetName        as xs:string,
  $testSetURI         as xs:anyURI,
  $verbose            as xs:boolean,
  $expFailureTC       as element(Test)?,
  $ctestMode          as xs:boolean,
  $cliMode            as xs:string,
  $usePlanSerializer  as xs:boolean
) as element(fots:test-case)?
{
(:TODO Cover the "(:%VARDECL%:)"when there are tests in FOTS that use it:)
try
{
  {
    variable $trace := concat("processing test case : ", $case/@name,
                              " in test set : ", $testSetName);

    trace($trace,"");

    variable $queryName := $case/@name;

    variable $test as xs:string := util:get-value($case, $testSetURI, "test");

    variable $envCase := $case/fots:environment;

    variable $query :=
      string-join
      (
      (
        env:add-xquery-version-decl(($deps, $case//fots:dependency), $test),

        env:decl-base-uri($env, $envCase, $test, $testSetURI),

        env:decl-def-elem-namespace($env, $envCase),

        env:decl-namespaces($env, $envCase, $test),

        env:decl-decimal-formats(($env/fots:decimal-format,
                                  $envCase/fots:decimal-format),
                                 ($env/fots:namespace,
                                  $envCase/fots:namespace)),

        env:add-var-decl($env, $envCase, $envBaseURI, $testSetURI),

        $test
      ),
      "&#xA;"
      );

    variable $zqQuery := driver:create-ZQ-query($query,
                                                    $case,
                                                    $env,
                                                    $envBaseURI,
                                                    $testSetURI,
                                                    $deps);

    (:if $verbose then print the query to a file:)
    if ($verbose and
        ($cliMode eq "run-test-case"))
    then util:write-query-to-file($zqQuery, $queryName);
    else ();

    variable $startDateTime := datetime:current-dateTime();

    variable $result := execute:zq-invoke($zqQuery,
                                            $case,
                                            $verbose,
                                            $testSetURI,
                                            $usePlanSerializer);

    variable $duration := (datetime:current-dateTime() - $startDateTime);

    variable $checkPass := feedback:check-pass($result, $queryName, $testSetName, $expFailureTC, $ctestMode);

    if ($checkPass) then
      feedback:pass($case,
                    $result,
                    $zqQuery,
                    $env,
                    $duration,
                    $verbose,
                    $expFailureTC,
                    $ctestMode)
    else if ($expFailureTC/@finalStatus = "disputed") then
      feedback:disputed($case,
                        concat("For details please see https://www.w3.org/Bugs/Public/show_bug.cgi?id=",
                               $expFailureTC/@bug))
    else
     feedback:fail($case,
                   $result,
                   $zqQuery,
                   $testSetName,
                   $env,
                   $duration,
                   $verbose,
                   if(not($checkPass) and ($ctestMode and exists($expFailureTC)))
                   then "Test case passed but it is marked with EXPECTED_FOTS_FAILURE in test/fots/CMakeLists.txt"
                   else ())
  }
}
catch *
{
  feedback:fail($case,
                eval:error((),
                           $case/fots:result/*,
                           $err:code,
                           $err:description,
                           $testSetURI),
                "fots-driver.xq:driver:test catch",
                $testSetName,
                $env,
                xs:dayTimeDuration("PT0S"),
                $verbose,
                ())
}
};


(:~
 : Creates the text for the complete query FQ that will be evaluated via ZQ
 : by the fots test driver. The actual test-case query TQ will be evaluated as
 : a nested ZQ query within FQ. FQ may contain additional nested zorba-query queries,
 : for example to compute values for external variables declared in TQ.
 :
 : @param $queryText the text for the test-case query TQ. It is content of
 :        <test-case>/test augmented with all the necessary prolog statements.
 : @param $case the test case.
 : @param $env the environment.
 : @param $envBaseURI URI of the environment.
 : @param $testSetURI the URI of the directory that contains the file of the
 :        associated test set.
 : @param $deps the dependencies that should be checked for given test-case.
 :        These may be defined at test-set level and/or test-case level.
 : @return the query that will be evaluated.
 :)
declare %private function driver:create-ZQ-query(
  $queryText          as xs:string,
  $case               as element(fots:test-case),
  $env                as element(fots:environment)?,
  $envBaseURI         as xs:anyURI?,
  $testSetURI     as xs:anyURI,
  $deps               as element(fots:dependency)*
) as xs:string
{
  let $resolver as xs:string? := env:resolver($case,
                                              $env,
                                              $envBaseURI,
                                              $testSetURI)
  let $mapper as xs:string? := env:mapper($case,
                                          $env,
                                          $envBaseURI,
                                          $testSetURI)
  let $needsDTDValidation := exists($deps[@type="feature" and @value="infoset-dtd"])
  return
    string-join
    (
    (
    "",
    "import module namespace zq = 'http://zorba.io/modules/zorba-query';",
   
    if ($needsDTDValidation) then
      ("import module namespace zorba-xml = 'http://zorba.io/modules/xml';",
       "import schema namespace opt       = 'http://zorba.io/modules/xml-options';")
    else (),
   
    if (exists($resolver))
    then "declare namespace resolver = 'http://zorba.io/modules/zorba-query/url-resolver';"
    else (),

    if (exists($mapper))
    then "declare namespace mapper = 'http://zorba.io/modules/zorba-query/uri-mapper';"
    else (),

    "",

    if (exists($resolver)) then ($resolver, "") else (),

    if (exists($mapper)) then ($mapper, "") else (),

    (:
     : We want to put the input query into a new XQuery as a string literal
     : and compile this new XQuery. In order to do so, we must escape some
     : things. The StringLiteral production in the XQuery grammar reads:
     :
     :  StringLiteral ::=
     :      "'" (PredefinedEntityRef | CharRef | EscapeApos | [^'&])* "'"
     :
     : for string literals delimited by single quotes. Therefore, we need
     : to manipulate the input query in two ways:
     :   1. Replace ' with '' (EscapeApos)
     :   2. Replace & with &amp; (which will block any PredefinedEntityRefs
     :      or CharRefs in the input query from being expanded in the new
     :      XQuery).
     : The replacement happens here. (2) looks weird because there's one
     : level of replacement being done right *here* when fots-driver.xq
     : itself is compiled. Escaping sucks.
     :)
    let $escAposQueryText := replace($queryText,"'","''")
    let $escAmpQueryText  := replace($escAposQueryText, '&amp;', '&amp;amp;')
    return concat(
           "variable $queryID := zq:prepare-main-module&#xA;(",
           "&#xA;",
           "'",
           "&#xA;",
           $escAmpQueryText,
           "&#xA;",
           "'",
           "&#xA;",
           if (exists($resolver))
           then if(exists($mapper))
                then ", resolver:url-resolver#2, mapper:uri-mapper#2&#xA;);"
                else ", resolver:url-resolver#2, ()&#xA;);"
           else if(exists($mapper))
                then ", (), mapper:uri-mapper#2&#xA;);"
                else "&#xA;);"),

    env:set-context-item($env, $envBaseURI, $needsDTDValidation),
    env:set-context-item($case/fots:environment, $testSetURI, $needsDTDValidation),
    env:set-variables($env, $envBaseURI),
    env:set-variables($case/fots:environment, $testSetURI),

    "zq:evaluate($queryID),",
    "",
    "zq:delete-query($queryID)",
    "        "
    ),
    "&#xA;"
    )
};
