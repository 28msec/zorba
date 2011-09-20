(: Copyright 2006-2008 The FLWOR Foundation.   :)
(:    :)
(: Licensed under the Apache License, Version 2.0 (the "License");   :)
(: you may not use this file except in compliance with the License.   :)
(: You may obtain a copy of the License at   :)
(:    :)
(: http://www.apache.org/licenses/LICENSE-2.0   :)
(:    :)
(: Unless required by applicable law or agreed to in writing, software   :)
(: distributed under the License is distributed on an "AS IS" BASIS,   :)
(: WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   :)
(: See the License for the specific language governing permissions and   :)
(: limitations under the License.   :)
(:   :)

(: This query is run by the remote queue and nightlies after a test run. :)
(: It tweaks the CTest-generated Test.xml to pass tests which crashed    :)
(: but are marked as EXPECTED_FAILURE().                                 :)
declare namespace l = "http://zorba-xquery.com";
declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $exps as document-node() external;
declare variable $tests as document-node() external;

declare %ann:sequential function l:xform($a) {
  for $exp in $exps/ExpectedFailures/Test
  for $segfault in
     $a/Site/Testing/Test/Results/NamedMeasurement/Value[text() eq "SEGFAULT" or text() eq "OTHER_FAULT"]
  let $failure := $segfault/../../..
  where data($exp/@name) eq data($failure/Name)
  return replace node $failure/@Status with attribute Status { "passed" };

  $a
};

l:xform($tests)
