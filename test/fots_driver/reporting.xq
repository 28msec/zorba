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
  "http://www.functx.com";

declare namespace err =
  "http://www.w3.org/2005/xqt-errors";
declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";
declare namespace results =
  "http://www.w3.org/2012/08/qt-fots-results";

declare default element namespace
  "http://www.w3.org/2012/08/qt-fots-results";

declare namespace ann =
  "http://zorba.io/annotations";


(:~
 : Loops through the test-sets, executes them and reports results.
 : @param $FOTSCatalogFilePath path to the FOTS catalog file.
 : @param $FOTSZorbaManifestPath path to the FOTS Zorba manifest file.
 : @param $SubmissionTemplatePath path to the SubmissionTemplate file.
 : @param $expectedFailuresPath the path to the FOTSExpectedFailures.xml.
 : @param $exceptedTestSets lists of test sets that are not run(empty sequence
 : means all test sets will be run).
 : @return a report of tests that were executed.
 :)
declare %ann:sequential function reporting:run-and-report(
  $FOTSCatalogFilePath    as xs:string,
  $FOTSZorbaManifestPath  as xs:string,
  $SubmissionTemplatePath as xs:string,
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

    file:write-text(if(contains($FOTSZorbaManifestPath,"XQ30"))
                    then "results_XQ30.xml"
                    else "results_XQ10.xml",
                    serialize($results),
                    $util:writeXML);

    reporting:W3C-reporting($results,
                            $FOTSZorbaManifestPath,
                            $SubmissionTemplatePath)
  }
};

(:~
 : Loops through the test sets, executes them and reports results.
 : @param $FOTSZorbaManifestPath path to the FOTS Zorba manifest file.
 : @param $SubmissionTemplatePath path to the SubmissionTemplate file.
 : @param $resultsFilePath path to the FOTS results file.
 : @return The W3C conformance submission file.
 :)
declare %ann:sequential function reporting:report(
  $FOTSZorbaManifestPath  as xs:string,
  $SubmissionTemplatePath as xs:string,
  $resultsFilePath        as xs:string
) as document-node()
{
  try
  {
    {
      reporting:W3C-reporting(parse-xml(file:read-text($resultsFilePath))/fots:test-cases,
                              $FOTSZorbaManifestPath,
                              $SubmissionTemplatePath)
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
 : @param $SubmissionTemplatePath path to the SubmissionTemplate file.
 : @return The W3C conformance submission file.
 :)
declare %ann:sequential function reporting:W3C-reporting(
  $results                as element(fots:test-cases)?,
  $FOTSZorbaManifestPath  as xs:string,
  $SubmissionTemplatePath as xs:string
) as document-node()
{
  try
  {
    {
      if (not(file:is-file(resolve-uri($FOTSZorbaManifestPath))))
      then
      {
        error($fots-err:errNA,
              "'FOTSZorbaManifest.xml' file was not found.");
      }
      else ();
     
      variable $FOTSZorbaManifest := parse-xml(file:read-text(resolve-uri($FOTSZorbaManifestPath)));

      if (not(file:is-file(resolve-uri($SubmissionTemplatePath))))
      then
      {
        error($fots-err:errNA,
              "'W3C_submission_template.xml' file was not found.");
      }
      else ();
     
      variable $W3CTemplate := parse-xml(file:read-text(resolve-uri($SubmissionTemplatePath)));
     
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
 : @param $failures Path to the results fo the FOTS.
 : @return a report of tests run.
 :)
declare %ann:nondeterministic function reporting:wiki-report(
  $resultsFilePath      as xs:string
) as element(fots:report)
{
try
{
  {
    variable $results := parse-xml(file:read-text($resultsFilePath));

  <fots:report>
  {
    comment {(concat('total=',count($results//fots:test-set//fots:test-case)),
             for $res in ('pass', 'fail', 'n/a', 'notRun', 'wrongError', 'disputed', 'tooBig')
             return concat(" ", $res, "=", count($results//fots:test-set//fots:test-case[@result = $res])))}
  }
  {
    for $ts in $results//fots:test-set
    let $noTC := count($ts//fots:test-case)
    let $totalFailures := $ts//fots:test-case[@result = "fail"]
    let $percent := round((1 - (count($totalFailures) div $noTC))*100,2)
    where count($totalFailures) gt 0
    order by count($totalFailures) descending, $ts/@name
    return
    <fots:test-set  name="{$ts/@name}"
                    noFailures="{count($totalFailures)}"
                    noTestCases="{$noTC}"
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
               resolve-uri($resultsFilePath)))
}
};
