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
 : Zorba FOTS driver execute
 : @author Sorin Nasoi
 :)

module namespace execute =
  "http://www.zorba-xquery.com/fots-driver/execute";

import module namespace zq =
  "http://zorba.io/modules/zorba-query#2.0";

import module namespace eval =
  "http://www.zorba-xquery.com/fots-driver/evaluate" at "evaluate.xq";

declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace err =
  "http://www.w3.org/2005/xqt-errors";

declare namespace ann =
  "http://zorba.io/annotations";


declare namespace op = "http://zorba.io/options/features";
declare namespace f = "http://zorba.io/features";
declare option op:disable "f:trace";

(:~
 : ZQ invoke.
 : @param $zqQueryText the query that will be run.
 : @param $case the test case.
 : @param $verbose if set to TRUE it will also output the actual result.
 : @param $testSetBaseURI the URI of the directory that contains the file of the
          associated test set.
 : @param $usePlanSerializer if true the plan serializer is used.
 : @return the result of running the query with ZQ.
 :)
declare %ann:sequential function execute:zq-invoke(
  $zqQueryText      as xs:string,
  $case               as element(fots:test-case),
  $verbose            as xs:boolean?,
  $testSetBaseURI     as xs:anyURI,
  $usePlanSerializer  as xs:boolean
)
{
  try
  {
    if($usePlanSerializer) then
    {
      variable $queryKey := zq:prepare-main-module($zqQueryText);
      variable $queryPlan := zq:query-plan($queryKey);
      variable $queryPlanKey := zq:load-from-query-plan($queryPlan);
      variable $queryResult := zq:evaluate-sequential($queryPlanKey);

      zq:delete-query($queryPlanKey);
      zq:delete-query($queryKey);

      eval:result($queryResult, $case/fots:result/*, $testSetBaseURI)
    }
    else
    {
      variable $queryKey := zq:prepare-main-module($zqQueryText);
      variable $queryResult := zq:evaluate-sequential($queryKey);

      zq:delete-query($queryKey);

      eval:result($queryResult, $case/fots:result/*, $testSetBaseURI)
    }
  }
  catch *
  {
    eval:error((),
               $case/fots:result/*,
               $err:code,
               $err:description,
               $testSetBaseURI)
  }
};
