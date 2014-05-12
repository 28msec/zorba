# Copyright 2006-2008 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# This script transforms the current CTest .xml results to a JUnit-
# compatible form. It is assumed that it is run in the build directory.

# Arguments - all are required:
#   zorba: Full path to Zorba executable

# First figure out which Test.xml to run
file (STRINGS "./Testing/TAG" _tag_content)
list (GET _tag_content 0 _ctest_tag)
message ("tag is ${_ctest_tag}")

# This is the query

set (_query "
declare variable $ctest_results as xs:string external;

declare function local:classname-for($testname as xs:string) as xs:string {
  if (fn:starts-with($testname, 'test/rbkt/zorba/'))
  then fn:replace($testname, '^test/rbkt/zorba/([^/]*)/.*$', 'RBKT.$1')
  else if (fn:starts-with($testname, 'FOTS/'))
  then fn:replace($testname, '^FOTS/([^-]*)-.*$', 'FOTS.$1')
  else 'OTHER.All Other Tests'
};

let $ctest_doc := doc($ctest_results)
let $ctest_site := $ctest_doc/Site
return
  <testsuite>
    <properties>
      <property name='BuildName' value='{$ctest_site/@BuildName}'/>
      <property name='BuildStamp' value='{$ctest_site/@BuildStamp}'/>
      <property name='Name' value='{$ctest_site/@Name}'/>
      <property name='Generator' value='{$ctest_site/@Generator}'/>
      <property name='CompilerName' value='{$ctest_site/@CompilerName}'/>
      <property name='OSName' value='{$ctest_site/@OSName}'/>
      <property name='Hostname' value='{$ctest_site/@Hostname}'/>
      <property name='OSRelease' value='{$ctest_site/@OSRelease}'/>
      <property name='OSVersion' value='{$ctest_site/@OSVersion}'/>
      <property name='OSPlatform' value='{$ctest_site/@OSPlatform}'/>
      <property name='Is64Bits' value='1'/>
      <property name='VendorString' value='{$ctest_site/@VendorString}'/>
      <property name='VendorID' value='{$ctest_site/@VendorID}'/>
      <property name='FamilyID' value='{$ctest_site/@FamilyID}'/>
      <property name='ModelID' value='{$ctest_site/@ModelID}'/>
      <property name='ProcessorCacheSize'
                value='{$ctest_site/@ProcessorCacheSize}'/>
      <property name='NumberOfLogicalCPU'
                value='{$ctest_site/@NumberOfLogicalCPU}'/>
      <property name='NumberOfPhysicalCPU'
                value='{$ctest_site/@NumberOfPhysicalCPU}'/>
      <property name='TotalVirtualMemory'
                value='{$ctest_site/@TotalVirtualMemory}'/>
      <property name='TotalPhysicalMemory'
                value='{$ctest_site/@TotalPhysicalMemory}'/>
      <property name='LogicalProcessorsPerPhysical'
                value='{$ctest_site/@LogicalProcessorsPerPhysical}'/>
      <property name='ProcessorClockFrequency'
                value='{$ctest_site/@ProcessorClockFrequency}'/>
    </properties>
    {
      for $ctest_test in $ctest_site/Testing/Test
      let $measures := $ctest_test/Results/NamedMeasurement
      let $cmdline := data($ctest_test/FullCommandLine)
      let $testname := data($ctest_test/Name)
      return
        <testcase name='{$testname}'
                  classname='{local:classname-for($testname)}'
                  time='{data($measures[@name='Execution Time']/Value)}'
                  status='hello world' assertions='fred was here'>
          {
            let $status := $ctest_test/@Status
            return
              if ($status eq 'failed')
              then
                let $exit_code := data($measures[@name='Exit Code']/Value)
                let $exit_val := data($measures[@name='Exit Value']/Value)
                return
                  <failure message='{$exit_code} (exit value: {$exit_val})'/>
              else if ($status eq 'notrun')
              then
                <skipped/>
              else '{$cmdline}'
          }
          <system-out>{data($ctest_test/Results/Measurement/Value)}</system-out>
          <system-err>Test Command:
=============
{$cmdline}
            {
              let $pass_reason := $measures[@name='Pass Reason']
              return
                if (exists($pass_reason))
                then
                  ('

CTest Pass Reason:
==================
',
                    data($pass_reason))
                else ()
             }
          </system-err>
        </testcase>
    }
  </testsuite>
")

execute_process (
  COMMAND ${zorba}
  -e ctest_results:=Testing/${_ctest_tag}/Test.xml
  -q "${_query}" --indent
  OUTPUT_FILE JUnitTestResults.xml
)
