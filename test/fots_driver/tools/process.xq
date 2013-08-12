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
 : Run every test case that matches a given criterion in a different process
 : and report every test case that HANGS or ends in a SEG FAULT.
 :
 : @author Sorin Nasoi
 :)


import module namespace proc =
  "http://www.zorba-xquery.com/modules/process#1.0";
import module namespace util =
  "http://www.zorba-xquery.com/fots-driver/util" at "../util.xq";
import module namespace d =
  "http://www.zorba-xquery.com/fots-driver" at "../fots-driver.xq";
import module namespace fots-err =
  "http://www.zorba-xquery.com/fots-driver/errors" at "../errors.xq";
  
declare namespace ann =
  "http://zorba.io/annotations";
declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare variable $fotsPath as xs:string external := "";
declare variable $dependency as xs:string external := "";
declare variable $testSetPrefixes as xs:string external := "";


(:~
 : Return the exit-code after invoking the FOTS driver with given $params.
 :
 : @param $params additional params.
 : @return the exit-code returned by the invoked application.
 :)
declare %ann:sequential function local:exec(
  $params as xs:string*
) as xs:string {
  variable $pathZorba := normalize-space(xs:string(proc:exec("pwd")/proc:stdout));

  proc:exec(string-join(($pathZorba, "/zorba"),''),
            ("-f", "-q", concat($pathZorba, "/../../test/fots_driver/cli.xq"),
             "-e", concat("fotsPath:=", $fotsPath),
             "-e", "verbose:=false",
             $params
            )
           )/proc:exit-code
};

declare %private %ann:sequential function local:invoke-exec(
  $testSets   as element(fots:test-set)*,
  $baseUri    as xs:anyURI,
  $dependency as xs:string*
) as xs:string* {
  for $testSet in $testSets
    let $testSetDoc := doc(resolve-uri($testSet/@file, $baseUri))
    let $testSetName := xs:string($testSet/@name)
    let $testCaseNames as xs:string* := d:list-test-cases($testSetDoc,
                                                          $dependency,
                                                          ())
    return
      for $testCaseName in $testCaseNames
      let $exit-code := 
          trace(local:exec(("-e", "mode:=run-test-case",
                      "-e", concat("testSetName:=",  $testSetName),
                      "-e", concat("testCaseName:=", trace($testCaseName, "processing test case :"))
                     )
                    ),"exit-code")
      where (xs:integer($exit-code) gt xs:integer(134))
      return $testCaseName
};
  
(:~
 : Return the name of the test cases that return an exit-code > 134.
 :
 : @param $fotsPath path to the FOTS catalog file.
 : @param $testSetPrefixes name/criteria for the test sets.
 : @param $dependency defined dependency.
 : @return the exit-codes returned by the invoked applications.
 :)
declare %ann:sequential function local:list-test-cases(
  $fotsPath         as xs:string,
  $testSetPrefixes  as xs:string*,
  $dependency       as xs:string*
) as xs:string* {
  trace($fotsPath, "fotsPath was set to:");
  trace($dependency, "dependency ");
  trace($testSetPrefixes, "testSetPrefixes ");

  variable  $doc := doc(resolve-uri($fotsPath)),
            $baseUri:= resolve-uri(util:parent-folder($fotsPath));
 
  if(string-join($testSetPrefixes,'') = '')
  then local:invoke-exec($doc/fots:catalog/fots:test-set,
                         $baseUri,
                         $dependency)
  else
    for $prefix in $testSetPrefixes
    return
      local:invoke-exec($doc/fots:catalog/fots:test-set[starts-with(@name, $prefix)],
                        $baseUri,
                        $dependency)
};

if( $fotsPath = '')
then fn:error($fots-err:errNA, 
              "please set the external variable $fotsPath to point to FOTS catalog.xml file.")
else
concat("'",
       string-join(local:list-test-cases($fotsPath, $testSetPrefixes, $dependency),"', '"),
       "'")


(:
local:exec(
            ("-e", "mode:=run-test-case",
             "-e", concat("testSetName:=",  "misc-HigherOrderFunctions"),
             "-e", concat("testCaseName:=", "xqhof2")
            )
          )
:)