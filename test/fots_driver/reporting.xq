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
declare namespace results =
  "http://www.w3.org/2012/08/qt-fots-results";

declare default element namespace
  "http://www.w3.org/2012/08/qt-fots-results";

declare namespace ann =
  "http://www.zorba-xquery.com/annotations";


(:~
 : Loops through the test-sets, executes them and reports results.
 : @param $FOTSCatalogFilePath path to the FOTS catalog file.
 : @param $FOTSZorbaManifestPath path to the FOTS Zorba manifest file.
 : @param $expectedFailuresPath the path to the FOTSExpectedFailures.xml.
 : @param $exceptedTestSets lists of test sets that are not run(empty sequence
 : means all test sets will be run).
 : @return a report of tests that were executed.
 :)
declare %ann:sequential function reporting:run-and-report(
  $FOTSCatalogFilePath    as xs:string,
  $FOTSZorbaManifestPath  as xs:string,
  $expectedFailuresPath   as xs:string,
  $exceptedTestSets       as xs:string*
) as document-node()
{
  {
    variable $results := driver:run-fots($FOTSCatalogFilePath,
                                         $FOTSZorbaManifestPath,
                                         (),
                                         $exceptedTestSets,
                                         (),
                                         '',
                                         (),
                                         fn:false(),
                                         $expectedFailuresPath,
                                         fn:false(),
                                         'run-test-sets',
                                         fn:false());

    file:write("results.xml",
               $results,
               $util:writeXML);

    reporting:W3C-reporting($results,
                            $FOTSZorbaManifestPath)
  }
};

(:~
 : Loops through the test sets, executes them and reports results.
 : @param $FOTSZorbaManifestPath path to the FOTS Zorba manifest file.
 : @param $resultsFilePath path to the FOTS results file.
 : @return The W3C conformance submission file.
 :)
declare %ann:sequential function reporting:report(
  $FOTSZorbaManifestPath  as xs:string,
  $resultsFilePath        as xs:string
) as document-node()
{
  try
  {
    {
      reporting:W3C-reporting(parse-xml(file:read-text($resultsFilePath))/fots:test-cases,
                              $FOTSZorbaManifestPath)
    }
  }
  catch *
  {
    error($err:code, $err:description)
  }
};

(:~
 : Format the W3C conformance report.
 : @param $results FOTS results file.
 : @param $FOTSZorbaManifestPath  path to the FOTS Zorba manifest file.
 : @return The W3C conformance submission file.
 :)
declare %ann:sequential function reporting:W3C-reporting(
  $results                as element(fots:test-cases)?,
  $FOTSZorbaManifestPath  as xs:string
) as document-node()
{
  try
  {
    {
      if (not(file:is-file(resolve-uri($FOTSZorbaManifestPath))))
      then
      {
        error($fots-err:errNA,
              "The 'FOTSZorbaManifest.xml' was not found.");
      }
      else ();
     
      variable $FOTSZorbaManifest := parse-xml(file:read-text(resolve-uri($FOTSZorbaManifestPath)));

      variable $CLIBaseURI := resolve-uri(util:parent-folder($FOTSZorbaManifestPath));

      variable $W3CTemplatePath := resolve-uri("W3C_submission_template.xml", $CLIBaseURI);

      if (not(file:is-file($W3CTemplatePath)))
      then
      {
        error($fots-err:errNA,
              "'W3C_submission_template.xml' file was not found.");
      }
      else ();
     
      variable $W3CTemplate := parse-xml(file:read-text($W3CTemplatePath));
     
      (: add dependencies:)
     (insert nodes
      for $dependency in $FOTSZorbaManifest/fots:test-suite-result/fots:dependency
      return <dependency type="{$dependency/@type}"
                         value="{$dependency/@value}"
                         satisfied="{$dependency/@satisfied}"/>
      as last into $W3CTemplate/results:test-suite-result/results:product,

      (: add test set results:)
      insert nodes
      for $testSet in $results/fots:test-set
      return
      <test-set name="{$testSet/@name}">
        {
          for $testCase in $testSet/fots:test-case
          return
          if(exists($testCase/@comment))
          then
            <test-case name="{$testCase/@name}"
                       result="{$testCase/@result}"
                       comment="{$testCase/@comment}" />
          else
            <test-case name="{$testCase/@name}"
                       result="{$testCase/@result}" />
        }
      </test-set>
      as last into $W3CTemplate/results:test-suite-result);
      
      $W3CTemplate
    }
  }
  catch err:FODC0002
  {
    error($err:code,
          $err:description,
          concat("&#xA;Please make sure there is a 'W3C_submission_template.xml'",
                 " file in the same folder as cli.xq"))
  }
};

(:~
 : Loops through the test-sets and creates statistics.
 : @param $FOTSCatalogFilePath  Path to the FOTS catalog file.
 : @param $failures Path to the results fo the FOTS.
 : @return a report of tests run.
 :)
declare %ann:nondeterministic function reporting:wiki-report(
  $FOTSCatalogFilePath  as xs:string,
  $resultsFilePath      as xs:string
) as element(fots:report)
{
try
{
  {
    variable $FOTSCatalog := doc(resolve-uri($FOTSCatalogFilePath));

    variable $catalogBaseURI := resolve-uri(util:parent-folder($FOTSCatalogFilePath));

    variable $results := parse-xml(file:read-text($resultsFilePath));

  <fots:report>
  {
    let $totalNoTests := count($results//fots:test-set//fots:test-case),
        $totalPass := sum(for $testSet in $results//fots:test-set
                          return count($testSet//fots:test-case[@result ='pass'])),
        $totalFail := sum(for $testSet in $results//fots:test-set
                          return count($testSet//fots:test-case[@result ='fail'])),
        $totalNotApplicable := sum(for $testSet in $results//fots:test-set
                                   return count($testSet//fots:test-case[@result ='n/a'])),
        $totalNotRun := sum(for $testSet in $results//fots:test-set
                            return count($testSet//fots:test-case[@result ='notRun']))
    return
    <fots:brief totalTests="{$totalNoTests}"
                totalPass="{$totalPass}"
                totalFail="{$totalFail}"
                totalNotApplicable="{$totalNotApplicable}"
                totalNotRun="{$totalNotRun}"/>
  }
  {
    for $testSetFile in $FOTSCatalog//fots:test-set
    let $testSetURI := resolve-uri($testSetFile/@file,
                                   $catalogBaseURI),
        $testSetDoc := doc($testSetURI),
        $testSetName := data($testSetDoc/fots:test-set/@name),
        $totalNoTestCases := count($testSetDoc//fots:test-case),
        $totalFailures := for $testCase in $results//fots:test-set[@name = $testSetName]//fots:test-case[@result ="fail"]
                          return $testCase,
        $percent := round((1 - (count($totalFailures) div $totalNoTestCases))*100,2),
        $executionTime := sum(for $testCase in $results//fots:test-set[@name = $testSetName]//fots:test-case
                              return xs:dayTimeDuration($testCase/@executionTime))
    where count($totalFailures) gt 0
    order by count($totalFailures) descending, $testSetName
    return
    <fots:test-set  name="{$testSetName}"
                    noFailures="{count($totalFailures)}"
                    noTestCases="{$totalNoTestCases}"
                    percent="{$percent}"
                  failedTestNames="{string-join(for $failure in $totalFailures
                                                order by data($failure/@name)
                                                return data($failure/@name)
                                              ,",")}">
    </fots:test-set>
   }
  </fots:report>
 
  }
}
catch err:FODC0002
{
  error($err:code,
        $err:description,
        concat("&#xA;Please make sure the passed 'fotsPath' points to the ",
               "exact location of the FOTS catalog.xml:&#xA;",
               resolve-uri($FOTSCatalogFilePath)))
}
};

(:~
 : Loops through the results and creates ExpectedFailures.xml.
 : @param $pathResults path to the FOTS results.
 : @return ExpectedFailures.xml.
 :)
declare %ann:nondeterministic function reporting:generate-expected-failures(
  $pathResults  as xs:string
)
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
    
      {
        for $testSet in $results//fots:test-set
        let $countFailures := count($testSet//fots:test-case[@result ="fail"])
        let $testSetName := xs:string($testSet/@name)
        order by $testSetName
        where $countFailures gt xs:integer(0)
        return
        for $testCase in $testSet//fots:test-case[@result ="fail"]
        return
          concat('EXPECTED_FOTS_FAILURE (',
                $testSetName,
                ' ',
                $testCase/@name,
                ' 0)&#xA;')
      }
    }
  }
  catch *
  {
    error($err:code, $err:description)
  }
};
