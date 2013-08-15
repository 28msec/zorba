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
 : Zorba FOTS driver feedback
 : @author Sorin Nasoi
 :)

module namespace feedback =
  "http://www.zorba-xquery.com/fots-driver/feedback";

declare namespace ann =
  "http://zorba.io/annotations";

declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace err =
  "http://www.w3.org/2005/xqt-errors";

declare function feedback:check-pass(
  $result           as item()*,
  $testCaseName     as xs:string?,
  $testSetName      as xs:string?,
  $expFailureTC     as element(Test)?,
  $ctestMode        as xs:boolean
) as xs:boolean
{
(: if the exact error code was not found, report the test as 'Pass'
   with an attribute correctError=false :)
  let $resultTestRun as xs:boolean :=
    (empty($result) or
     (exists($result) and
      contains(string-join($result/fots:errors,''), "Expected error:") and
      contains(string-join($result/fots:errors,''), "Found error:")))

  let $expectedFailure as xs:boolean :=
   if(exists($expFailureTC) and
      $ctestMode)
    then fn:true()
    else fn:false()

(:if test PASSED and was expected to FAIL OR test FAILED and wasn't expected to
  FAIL => report as FAIL, a.k.a. regression;
  otherwise report as PASS:)
  return ($resultTestRun eq not($expectedFailure))
};


declare %ann:sequential function feedback:pass(
  $case             as element(fots:test-case),
  $result           as item()*,
  $zorbaQuery       as xs:string,
  $env              as element(fots:environment)?,
  $duration         as xs:dayTimeDuration,
  $verbose          as xs:boolean,
  $expectedFailure  as element(Test)?,
  $ctestMode        as xs:boolean
) as element(fots:test-case)
{
  if (exists($expectedFailure) and $ctestMode) then
    feedback:pass-expected-FOTS-failure($case,
                                        $result,
                                        $zorbaQuery,
                                        $env,
                                        $verbose,
                                        "Test case failed but it is marked with EXPECTED_FOTS_FAILURE in test/fots/CMakeLists.txt")
  else feedback:pass($case,
                     $result,
                     (),
                     ())
};


(:~
 : Feedback on a test case that failed but is marked as EXPECTED_FOTS_FAILURE.
 :
 : @param $case test case.
 : @return the test case after certain information was added.
 :)
declare  %private %ann:sequential function feedback:pass-expected-FOTS-failure(
  $case             as element(fots:test-case),
  $result           as item()*,
  $zorbaQuery       as xs:string,
  $env              as element(fots:environment)?,
  $verbose          as xs:boolean,
  $info             as xs:string
) as element(fots:test-case)
{
  if ($verbose) then
  {
    {
      (insert node attribute result{'pass'} as last into $case,
       insert node attribute info{$info} as last into $case,
       insert node
         <fots:info>
           {$env}
           <fots:query>{$zorbaQuery}</fots:query>
           {$result/fots:expected-result,
            $result/fots:result,
            $result/fots:errors}
         </fots:info>
      as last into $case,
      delete node $case/fots:created,
      delete node $case/fots:modified);

      $case
    }
  }
  else <fots:test-case  name="{data($case/@name)}"
                        result="pass"
                        info="{$info}"/>
};


(:~
 : Gives feedback on a test case run with success.
 :
 : @param $case test case.
 : @param $result test result of running the test case.
 : @return info about test case that passed.
 :)
declare %ann:sequential function feedback:pass(
  $case     as element(fots:test-case),
  $result   as item()*,
  $comment  as xs:string?,
  $info     as xs:string?
) as element(fots:test-case)
{
  if(exists($result/fots:errors)) then
    <fots:test-case  name="{data($case/@name)}"
                     result="wrongError"
                     comment="{$result/fots:errors}"/>
  else
  {
    variable $ret := <fots:test-case name="{data($case/@name)}"
                                     result="pass"/>;

    (if(exists($comment))
     then insert node attribute comment{$comment} as last into $ret
     else (),
     if(exists($info))
     then insert node attribute info{$info} as last into $ret
     else ());
    
     $ret
  }
};


(:~
 : Gives feedback on a test case run without success.
 :
 : @param $case test case.
 : @return the test case after certain information was added.
 :)
declare %ann:sequential function feedback:fail(
  $case             as element(fots:test-case),
  $result           as item()*,
  $zorbaQuery       as xs:string,
  $testSetName      as xs:string?,
  $env              as element(fots:environment)?,
  $duration         as xs:dayTimeDuration,
  $verbose          as xs:boolean,
  $info             as xs:string?
) as element(fots:test-case)
{
  if ($verbose) then
  {
    {
      (insert node attribute result{'fail'} as last into $case,
       if (exists($info))
       then insert node attribute comment{$info} as last into $case
       else (),
       insert node attribute executionTime{$duration} as last into $case,
       insert node
         <fots:info>
           {$env}
           <fots:query>{$zorbaQuery}</fots:query>
           {$result/fots:expected-result,
            $result/fots:result,
            $result/fots:errors}
         </fots:info>
       as last into $case,
       delete node $case/fots:created,
       delete node $case/fots:modified);

       $case
    }
  }
  else
  {
    variable $ret := <fots:test-case name="{data($case/@name)}"
                                     result="fail"/>;

    (if(exists($info))
     then insert node attribute info{$info} as last into $ret
     else ());
    
     $ret
  }
};


(:~
 : Gives feedback on a test case that is not run (because its name is listed
 : in the $exceptedTestCases global var).
 :
 : @param $case test case.
 : @param $error the reason for which the test case was not run.
 : @return the test case.
 :)
declare function feedback:not-run(
  $case   as element(fots:test-case),
  $error  as xs:string?
) as element(fots:test-case)
{
  if(exists($error))
  then <fots:test-case name="{$case/@name}" result="notRun" comment="{$error}"/>
  else <fots:test-case name="{$case/@name}" result="notRun"/>
};


(:~
 : Gives feedback on a test case that is not run when dependencies are not met.
 :
 : @param $case test case.
 : @param $dependencyError test error returned by the dependency checking.
 : @return the test case.
 :)
declare function feedback:not-applicable(
  $case             as element(fots:test-case),
  $dependencyError  as xs:string
) as element(fots:test-case)
{
  <fots:test-case name="{$case/@name}"
                  result="n/a"
                  comment="{$dependencyError}"/>
};

(:~
 : Gives feedback on a test case that is failing because of an error in FOTS.
 :
 : @param $case test case.
 : @param $comment details about the bug opened on W3C Bugzilla.
 : @return the test case.
 :)
declare function feedback:disputed(
  $case     as element(fots:test-case),
  $comment  as xs:string
) as element(fots:test-case)
{
  <fots:test-case name="{data($case/@name)}"
                  result="disputed"
                  comment="{$comment}"/>
};

(:~
 : Gives feedback on a test case that is not run because it hangs.
 :
 : @param $case test case.
 : @param $comment details about the bug opened on Launchpad.
 : @return the test case.
 :)
declare function feedback:too-big(
  $case     as element(fots:test-case),
  $comment  as xs:string
) as element(fots:test-case)
{
  <fots:test-case name="{data($case/@name)}"
                  result="tooBig"
                  comment="{$comment}"/>
};
