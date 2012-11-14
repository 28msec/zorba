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
 : Zorba FOTS driver CLI
 : @author Ghislain Fourny, Sorin Nasoi
 :)

import module namespace d =
  "http://www.zorba-xquery.com/fots-driver" at "fots-driver.xq";
import module namespace r =
  "http://www.zorba-xquery.com/fots-driver/reporting" at "reporting.xq";

(:~ path to the place where FOTS can be found :)
declare variable $fotsPath as xs:string external := "";

(:~ path to the place where the FOTS Zorba manifest can be found :)
declare variable $fotsZorbaManifestPath as xs:string external :=
  "FOTSZorbaManifest.xml";

(:~ The path to the results from a previous run :)
declare variable $failuresFilePath as xs:string external := "";

(:~ choose the CLI option you want to run :)
declare variable $mode as xs:string external := "";

(:~ name/criteria for the test sets :)
declare variable $testSetPrefixes as xs:string external := "";

(:~ name/criteria for the test cases :)
declare variable $testCasePrefixes as xs:string external := "";

(:~ Enable or disable verbose output :)
declare variable $verbose as xs:string external := "true";

(:~ 
  Enable or disable showing the actual query result in the output.
  True by default.
:)
declare variable $showResult as xs:string external := "true";

(:~ list of assertion types :)
declare variable $assertType as xs:string external := "";

(:~ regex for the tests in the 'list-matching-test-cases' option :)
declare variable $pattern as xs:string external := "";

(:~ flags for the tests in the 'list-matching-test-cases' option :)
declare variable $flags as xs:string external := "";

(:~ Tokenize comma or empty string :)
declare %private function local:tokenize(
  $input as xs:string
) as xs:string*
{
  let $tokens := tokenize($input, ",")
  return if (exists($tokens)) then $tokens else ""
};

declare function local:usage() as xs:string
{
  string-join((
    "Zorba FOTS driver usage examples:",
    "If you run Zorba from a checkout of the trunk and the build/bin folder,",
    "- /path/to/cli.xq can be set to ../../test/fots_driver/cli.xq",
    "",
    "Always try to output the result back to an XML file with nice indentation:",
    "./zorba -f -q ../../test/fots_driver/cli.xq -e SET_CLI_OPTIONS_HERE -o output.xml --indent",
    "",
    " This way you will see trace information in the CLI window and detailed",
    " results of the test cases in the 'output.xml'.",
    "",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e fotsZorbaManifestPath:=/path/to/Zorba_manifest.xml -e mode:=list-test-sets",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-sets -e verbose:=true",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-sets -e testSetPrefixes:=prod,app",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-cases -e testSetPrefixes:=prod-Literal",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-matching-test-cases -e pattern:=catch",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod-Literal -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod-Literal -e verbose:=false -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-cases -e testSetPrefixes:=prod-Literal -e testCasePrefixes:=Literal -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-cases -e assertType:=assert-count -e testSetPrefixes:=fn-innermost -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-cases -e assertType:=assert-count -o result.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-and-report -o report.xml --indent",
    "zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=report -e failuresFilePath:=failures.xml -e verbose:=false -o report.xml --indent",
    ""
    ), "&#xA;")
};

(:~ The test cases in this list have bugs assigned and should not be run :)
variable $exceptedTestCases := (
"cbcl-subsequence-011", "cbcl-subsequence-012", "cbcl-subsequence-013",
"cbcl-subsequence-014"                                  (:see bug lp:1069794 :)
, "re00975", "re00976", "re00976a"                      (:see bug lp:1070533 :)
, "fn-unparsed-text-lines-052"                          (:see bug lp:1073175 :)
);

(:~  The test in this list have bugs assigned already and should not be run :)
variable $exceptedTestSets := ();

switch ($mode)
case "list-test-sets"
  return
    string-join(
      (d:list-test-sets(trace($fotsPath,
                              "The path to FOTS catalog.xml was set to: "),
       local:tokenize(trace($testSetPrefixes,
                           "'testSetPrefixes' was set to: ")))),
       "&#xA;")
case "list-test-cases"
  return
    string-join((d:list-test-cases(
                            trace($fotsPath,
                                  "The path to FOTS catalog.xml was set to: "),
                 local:tokenize(trace($testSetPrefixes,
                                      "'testSetPrefixes' was set to: "))), ""),
                "&#xA;")
case "list-matching-test-cases"
  return string-join((d:list-matching-test-cases(
                            trace($fotsPath,
                                  "The path to FOTS catalog.xml was set to: "),
                            trace($pattern,
                                  "pattern was set to: "),
                            trace($flags,
                                  "flags were set to: ")), ""),
                     "&#xA;")
case "run-test-sets"
  return d:run-fots($fotsPath,
                    $fotsZorbaManifestPath,
                    d:list-test-sets($fotsPath,
                              local:tokenize(trace($testSetPrefixes,
                                            "'testSetPrefixes' was set to: "))),
                    trace('',"'testCasePrefixes' was set to: "),
                    $exceptedTestCases,
                    $exceptedTestSets,
                    $assertType,
                    xs:boolean($verbose),
                    xs:boolean($showResult))
case "run-test-cases"
  return d:run-fots($fotsPath,
                    $fotsZorbaManifestPath,
                    local:tokenize(trace($testSetPrefixes,
                                        "'testSetPrefixes' was set to: ")),
                    local:tokenize(trace($testCasePrefixes,
                                        "'testCasePrefixes' was set to: ")),
                    $exceptedTestCases,
                    $exceptedTestSets,
                    $assertType,
                    xs:boolean($verbose),
                    xs:boolean($showResult))
case "run-and-report"
  return r:run-and-report($fotsPath,
                          $fotsZorbaManifestPath,
                          d:list-test-sets($fotsPath,
                                          local:tokenize($testSetPrefixes)),
                          '',
                          $exceptedTestCases,
                          $exceptedTestSets,
                          $assertType,
                          fn:false(),   (: the reports to W3C are always generated with verbose set to false:)
                          xs:boolean($showResult))
case "report"
  return r:report($fotsPath,
                  $failuresFilePath,
                  $exceptedTestCases,
                  $exceptedTestSets,
                  xs:boolean($verbose))
default
  return local:usage()
