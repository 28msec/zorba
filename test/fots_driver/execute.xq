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

import module namespace xqxq =
  "http://www.zorba-xquery.com/modules/xqxq#2.0";

import module namespace eval =
  "http://www.zorba-xquery.com/fots-driver/evaluate" at "evaluate.xq";

declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

declare namespace err =
  "http://www.w3.org/2005/xqt-errors";

declare namespace ann =
  "http://www.zorba-xquery.com/annotations";


declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";
declare option op:disable "f:trace";

(:~
 : XQXQ invoke.
 : @param $xqxqQueryText the query that will be run.
 : @param $case the test case.
 : @param $verbose if set to TRUE it will also output the actual result.
 : @param $testSetBaseURI the URI of the directory that contains the file of the
          associated test set.
 : @param $usePlanSerializer if true the plan serializer is used.
 : @return the result of running the query with XQXQ.
 :)
declare %ann:sequential function execute:xqxq-invoke(
  $xqxqQueryText      as xs:string,
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
      variable $queryKey := xqxq:prepare-main-module($xqxqQueryText);
      variable $queryPlan := xqxq:query-plan($queryKey);
      variable $queryPlanKey := xqxq:load-from-query-plan($queryPlan);
      variable $queryResult := xqxq:evaluate-sequential($queryPlanKey);

      xqxq:delete-query($queryPlanKey);
      xqxq:delete-query($queryKey);

      eval:result($queryResult, $case/fots:result/*, $testSetBaseURI)
    }
    else
    {
      variable $queryKey := xqxq:prepare-main-module($xqxqQueryText);
      variable $queryResult := xqxq:evaluate-sequential($queryKey);

      xqxq:delete-query($queryKey);

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
