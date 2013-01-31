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
 : Zorba FOTS driver reporting
 : @author Sorin Nasoi
 :)

module namespace reporting =
  "http://www.zorba-xquery.com/fots-driver/reporting";

import module namespace file =
  "http://expath.org/ns/file";

import module namespace driver =
  "http://www.zorba-xquery.com/fots-driver" at "fots-driver.xq";
import module namespace util =
  "http://www.zorba-xquery.com/fots-driver/util" at "util.xq";
import module namespace fots-err =
  "http://www.zorba-xquery.com/fots-driver/errors" at "errors.xq";
import module namespace functx =
  "http://www.functx.com/";

declare namespace err =
  "http://www.w3.org/2005/xqt-errors";
declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace ann =
  "http://www.zorba-xquery.com/annotations";

(:~
 : Loops through the test-sets, runs then and creates statistics.
 : @param $FOTSCatalogFilePath path to the FOTS catalog file.
 : @param $FOTSZorbaManifestPath path to the FOTS Zorba manifest file.
 : @param $testSetPrefixes name/criteria for the test sets( empty string means
 : all).
 : @param $testCasePrefixes name/criteria for the test cases(empty string means
 : all).
 : @param $exceptedTestCases lists of test cases that are not run( empty string
 : means all tests will be run).
 : @param $exceptedTestSets lists of test sets that are not run(empty string
 : means all tests will be run).
 : @param $verbose if set to TRUE it will also output the actual failures.
 : @return a report of tests run.
 :)
declare %ann:sequential function reporting:run-and-report(
  $FOTSCatalogFilePath    as xs:string,
  $FOTSZorbaManifestPath  as xs:string,
  $exceptedTestCases      as xs:string*,
  $exceptedTestSets       as xs:string*,
  $verbose                as xs:boolean
) {
try {
  {
    variable $FOTSCatalog := doc(trace(resolve-uri($FOTSCatalogFilePath), 
                                "Path to FOTS catalog.xml set to: "));

    variable $catalogBaseURI := resolve-uri(util:parent-folder($FOTSCatalogFilePath));

    variable $FOTSZorbaManifest := doc(trace(resolve-uri($FOTSZorbaManifestPath),
                                      "Path to FOTSZorbaManifest set to:"));

    variable $failures := <fots:FOTS-test-suite-result>{
                          ( $FOTSZorbaManifest//fots:implementation,
                            $FOTSZorbaManifest//fots:dependencies-satisfied,
                            driver:run-fots($FOTSCatalogFilePath,
                                            $FOTSZorbaManifestPath,
                                            (),
                                            $exceptedTestSets,
                                            (),
                                            $exceptedTestCases,
                                            '',
                                            (),
                                            $verbose,
                                            '',
                                            'run-test-sets')
                             )
                             }</fots:FOTS-test-suite-result>;

    file:write("failures.xml",
              $failures,
              $util:writeXML);

    reporting:do-reporting($FOTSCatalog,
                           $catalogBaseURI,
                           $failures,
                           $exceptedTestCases,
                           $exceptedTestSets,
                           $verbose)
  }
}
catch *
{
  error($err:code,
        $err:description,
        concat("&#xA;Please make sure the passed 'fotsPath' points to the ",
               "exact location of the FOTS catalog.xml:&#xA;",
               resolve-uri($FOTSCatalogFilePath),
               "&#xA;and that the passed 'fotsZorbaManifestPath' points to",
               " a file in the same folder as cli.xq:&#xA;",
               resolve-uri($FOTSZorbaManifestPath)))
}
};

(:~
 : Loops through the test cases report and creates statistics.
 : @param $pathFOTSCatalog path to the FOTS catalog file.
 : @param $pathResults path to the FOTS results.
 : @param $exceptedTestCases lists of test cases that are not run( empty string
 : means all tests will be run).
 : @param $exceptedTestSets lists of test sets that are not run(empty string
 : means all tests will be run).
 : @param $verbose if set to TRUE it will also output the actual failures.
 : @param $showResult if set to TRUE it will also show the actual result of the
 : Query run.
 : @return a report of tests run.
 :)
declare %ann:nondeterministic function reporting:report(
  $FOTSCatalogFilePath  as xs:string,
  $pathResults          as xs:string,
  $exceptedTestCases    as xs:string*,
  $exceptedTestSets     as xs:string*,
  $verbose              as xs:boolean
) as element(fots:report) {
  try {
    {
      if(not(file:is-file($pathResults)))
      then
      {
        error($fots-err:errNA, 
              "The file results file was not found. Suggestion: use driver:run-fots to generate it or use reporting:run-and-report function.");
      }
      else ();

      variable $results := parse-xml(file:read-text($pathResults));

      variable $FOTSCatalog := doc(trace(resolve-uri($FOTSCatalogFilePath),
                                  "Path to FOTS catalog.xml set to: "));

      variable $catalogBaseURI := resolve-uri(util:parent-folder($FOTSCatalogFilePath));

      reporting:do-reporting($FOTSCatalog,
                             $catalogBaseURI,
                             $results,
                             $exceptedTestCases,
                             $exceptedTestSets,
                             $verbose)
    }
  }
  catch *
  {
    error($err:code, $err:description)
  }
};


(:~
 : Loops through the test-sets and creates statistics.
 : @param $FOTSCatalog  FOTS catalog file.
 : @param $failures the test reported by Zorba as failed.
 : @param $exceptedTestCases lists of test cases that are not run(empty string
 : means all tests will be run).
 : @param $exceptedTestSets lists of test sets that are not run(empty string
 : means all tests will be run).
 : @param $verbose is set to TRUE it will also output the actual failures.
 : @return a report of tests run.
 :)
declare %ann:nondeterministic function reporting:do-reporting(
  $FOTSCatalog        as document-node(),
  $catalogBaseURI     as xs:anyURI,
  $failures,
  $exceptedTestCases  as xs:string*,
  $exceptedTestSets   as xs:string*,
  $verbose            as xs:boolean
) as element(fots:report) {
  let $excepted := count($exceptedTestCases)
  return
  <fots:report>
  {
    let $totalNoTests := count($failures//fots:test-set//fots:test-case),
        $totalPass := sum(for $testSet in $failures//fots:test-set
                          return count($testSet//fots:test-case[@result ='pass'])),
        $totalFail := sum(for $testSet in $failures//fots:test-set
                          return count($testSet//fots:test-case[@result ='fail'])),
        $totalNotApplicable := sum(for $testSet in $failures//fots:test-set
                                   return count($testSet//fots:test-case[@result ='not applicable'])),
        $totalNotRun := sum(for $testSet in $failures//fots:test-set
                            return count($testSet//fots:test-case[@result ='notRun'])),
        $executionTime := sum(for $testCase in $failures//fots:test-set//fots:test-case return xs:dayTimeDuration($testCase/@executionTime))
    return
    <fots:brief totalTests="{$totalNoTests}"
                totalPass="{$totalPass}"
                totalFail="{$totalFail}"
                totalNotApplicable="{$totalNotApplicable}"
                totalNotRun="{$totalNotRun}"
                totalExecutionTime="{$executionTime}"/>
  }
  { 
    for $testSetFile in $FOTSCatalog//fots:test-set
    let $testSetURI := resolve-uri($testSetFile/@file,
                                   $catalogBaseURI),
        $testSetDoc := doc($testSetURI),
        $testSetName := data($testSetDoc/fots:test-set/@name),
        $totalNoTestCases := count($testSetDoc//fots:test-case),
        $totalFailures := for $testCase in $failures//fots:test-set[@name = $testSetName]//fots:test-case[@result ="fail"]
                          return $testCase,
        $percent := round((1 - (count($totalFailures) div $totalNoTestCases))*100,2),
        $executionTime := sum(for $testCase in $failures//fots:test-set[@name = $testSetName]//fots:test-case
                              return xs:dayTimeDuration($testCase/@executionTime))
    order by count($totalFailures) descending
    return
    <fots:test-set  name="{$testSetName}"
                    executionTime="{$executionTime}"
                    noFailures="{count($totalFailures)}"
                    noTestCases="{$totalNoTestCases}"
                    percent="{$percent}"
                  failedTestNames="{string-join(for $failure in $totalFailures
                                                order by data($failure/@name)
                                                return data($failure/@name)
                                              ,",")}">
   {if (not($verbose)) then $totalFailures else ()}
    </fots:test-set>
   }
   </fots:report>
};

(:~
 : Loops through the results and creates ExpectedFailures.xml.
 : @param $pathResults path to the FOTS results.
 : @return ExpectedFailures.xml.
 :)
declare %ann:nondeterministic function reporting:generate-expected-failures(
  $pathResults  as xs:string
) as element(failures)
{
  try
  {
    {
      if (not(file:is-file($pathResults)))
      then
      {
        error($fots-err:errNA, 
              "The file results file was not found. Suggestion: use driver:run-fots to generate it.");
      }
      else ();

      variable $results := parse-xml(file:read-text($pathResults));
      
      <failures>{
      for $testSet in $results//fots:test-set
      let $countFailures := count($testSet//fots:test-case[@result ="fail"])
      let $countNotRun := count($testSet//fots:test-case[@result ="notRun"])
      let $testSetName := xs:string($testSet/@name)
      where ($countFailures gt xs:integer(0)) or
            ($countNotRun gt xs:integer(0))
      return
        <TestSet name="{$testSetName}"> {
          (for $testCase in $testSet//fots:test-case[@result ="fail"]
           return
             <Test name="{xs:string($testCase/@name)}"
                   bug="0" />
          ,
           for $testCase in $testSet//fots:test-case[@result ="notRun"]
           return
             <Test name="{xs:string($testCase/@name)}"
                   notRun="true"
                   bug="0" />
          )}</TestSet>}</failures>
    }
  }
  catch *
  {
    error($err:code, $err:description)
  }
};

declare function reporting:regressions(
) as xs:string* {
  let $old_report:=fn:parse-xml(file:read-text('/home/spungi/work/zorba/repo/fots-ctest/build/bin/report_04_Dec.xml'))
  let $new_report:=fn:parse-xml(file:read-text('/home/spungi/work/zorba/repo/fots-ctest/build/bin/report_18_Dec.xml'))
  
  for $testSetOld in $old_report/*:report/*:test-set
  let $testSetNew := $new_report/*:report/*:test-set[@name = data($testSetOld/@name)]
  let $regression := if (exists($testSetNew))
                     then xs:decimal(data($testSetOld/@noFailures)) - xs:decimal(data($testSetNew/@noFailures))
                     else xs:decimal(0)
  let $testsOld as xs:string* := tokenize(data($testSetOld/@failedTestNames),",")
  let $testsNew as xs:string* := tokenize(data($testSetNew/@failedTestNames),",")
  where $regression < xs:decimal(0)
  order by $regression ascending
  return
    concat(data($testSetOld/@name),
           " ",
           $regression,
           " ",
           string-join((functx:value-except($testsNew, $testsOld)),","),
           "&#xA;")
};

