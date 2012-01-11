(:
 : Copyright 2006-2009 The FLWOR Foundation.
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

(: XQuery main module :)

import module namespace file="http://expath.org/ns/file";
import module namespace proc="http://www.zorba-xquery.com/modules/process";
import module namespace tims="http://www.example.com/timings" at "timings.xq";
import module namespace sys ="http://www.zorba-xquery.com/modules/system";
import module namespace http="http://expath.org/ns/http-client";

declare namespace pdash = "http://www.28msec.com/pdash";
declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace err = "http://www.w3.org/2005/xqt-errors";


declare %ann:sequential 
function local:getPlatform()
{    
    <pdash:platform site-osname="Ubuntu" os-version="11.04" os-platform="Linux" 
        hostname="28msec.dyndns.org" is-64bits="true" vendor-id="Cezar" 
        vendor-label="santacruz" 
        number-of-logical-cpu="{xs:int(8)}" number-of-physical-cpu="1" 
        total-virtual-memory="12389692000" total-physical-memory="0" 
        number-of-logical-cpu-per-physical-cpu="8"/>
}; 


declare %ann:sequential %ann:nondeterministic 
function local:makeDir($svnDir as xs:string)
{    
    if( fn:not( file:exists($svnDir) ) )
    then
    {
        file:create-directory($svnDir);
        fn:trace("", fn:concat("--- Using new ", $svnDir, " directory."));
    }
    else
        if ( fn:not( file:is-directory($svnDir) ) )
        then 
        {
            fn:trace("", fn:concat("Error: ", $svnDir, " is not a dir."));
            fn:error(xs:QName("local:ZPERF0001"), fn:concat("Error: ", $svnDir, 
                " is not a dir."));
        }
        else fn:trace("", fn:concat("--- Found ", $svnDir, " directory."));
};


declare %ann:sequential 
function local:svnCo($svnCmd as xs:string, 
    $svnDir as xs:string, $svnRev as xs:string)
{
    variable $svnCo := fn:concat($svnCmd, " co -r ", $svnRev, 
        " http://zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba ", $svnDir);
    fn:trace($svnCo, "cmd");

    variable $svnCoResult := proc:exec($svnCmd, 
        ("co", "-r", $svnRev,
         "http://zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba", $svnDir));
                  
    if( fn:data($svnCoResult/proc:exit-code) eq "0")
    then 
        fn:trace( fn:data($svnCoResult/proc:stdout), "--- svn co: ");
    else
    {
        fn:trace( fn:data($svnCoResult/proc:stderr), "ERROR: ");
        fn:error(xs:QName("local:ZPERF0003"), fn:concat("Error svn co: ", 
            fn:data($svnCoResult/proc:stderr)));
    } 
    
    fn:data($svnCoResult/proc:exit-code)
};


declare %ann:sequential %ann:nondeterministic 
function local:makeSvnDir($svnCmd as xs:string, 
    $svnDir as xs:string, $svnRev as xs:string)
{    
    if ( file:exists(fn:concat($svnDir, file:directory-separator(), "AUTHORS.txt")) and 
         file:exists(fn:concat($svnDir, file:directory-separator(), "src"))  )
    then
        fn:trace("", fn:concat("--- Assuming ", $svnDir, 
            " is the Zorba svn checkout dir."));
    else
        if ( fn:empty(file:list($svnDir)) )
        then
            local:svnCo($svnCmd, $svnDir, $svnRev);
        else
        {
            variable $msg := fn:concat("Error: ", $svnDir, 
                " is not empty and it doesn't contain Zorba.");
            fn:error(xs:QName("local:ZPERF0002"), $msg);
        }
};


declare %ann:sequential 
function local:update($svnCmd as xs:string, 
    $svnDir as xs:string, $svnRev as xs:string)
{   
    fn:trace("", fn:concat("--- Svn update @rev", $svnRev)); 

    variable $svnUp := fn:concat($svnCmd, " up -r ", $svnRev, " ", $svnDir);
    fn:trace($svnUp, "  - svn up");

    variable $svnUpResult := proc:exec($svnCmd, 
        ("up", "-r", xs:string($svnRev), "--accept", "theirs-full", $svnDir));

    if( fn:data($svnUpResult/proc:exit-code) eq "0")
    then 
        fn:trace( fn:data($svnUpResult/proc:stdout), "svn up: ");
    else
    {
        fn:trace( fn:data($svnUpResult/proc:stderr), "ERROR: "); 
        fn:trace( $svnUpResult, "svn up: ");
        fn:error(xs:QName("local:ZPERF0004"), fn:concat("Error svn up: ", 
            fn:data($svnUpResult/proc:stderr)));
    } 
    

    fn:trace("", "  - svn info");

    variable $svnInfoResult := proc:exec($svnCmd, 
        ("info", "--xml", $svnDir));
                  
    if( fn:data($svnInfoResult/proc:exit-code) eq "0")
    then 
    {
        fn:trace( fn:data($svnInfoResult/proc:stdout), "svn info: ");
        
        (: need to find the revision date :)
        variable $strOut := fn:data($svnInfoResult/proc:stdout);
        variable $doc := fn:parse-xml($strOut);
        
        xs:dateTime(fn:data($doc/info/entry/commit/date))
    }
    else
    {
        fn:trace( fn:data($svnInfoResult/proc:stderr), "ERROR: "); 
        fn:trace( $svnInfoResult, "svn info: ");
        fn:error(xs:QName("local:ZPERF0004"), fn:concat("Error svn info: ", 
            fn:data($svnInfoResult/proc:stderr)));
    }
};


declare %ann:sequential %ann:nondeterministic 
function local:build( $buildDir as xs:string, 
    $clean as xs:boolean, $cmakeCmd as xs:string,
    $makeCmd as xs:string, $makeThreads as xs:int)
{
    fn:trace("", fn:concat("--- Start build clean:", $clean));

    if ($clean) 
    then
    {
        variable $res := proc:exec("rm", ("-fR", $buildDir));
        if( fn:data($res/proc:exit-code) eq "0" )
        then
            fn:trace("", fn:concat("  - rm -fR ", $buildDir) );
        else
        {
            fn:trace($res, fn:concat("ERROR: rm -fR ", $buildDir));
            fn:error(xs:QName("local:ZPERF0005"), fn:concat("Error rm -fR: ", 
                fn:data($res/proc:stderr)));
        }
   
    }
    else {}
    
    if ( fn:not(file:exists($buildDir)) )
    then 
    {
        variable $res := proc:exec("mkdir", ($buildDir));
        if( fn:data($res/proc:exit-code) eq "0" )
        then
            fn:trace(fn:data($res/proc:stdout), fn:concat("  - mkdir ", $buildDir) );
        else
        {
            fn:trace($res, fn:concat("ERROR: mkdir", $buildDir));
            fn:error(xs:QName("local:ZPERF0006"), fn:concat("Error mkdir: ", 
                fn:data($res/proc:stderr)));
        }
    }
    else {}

    if ( fn:empty(file:list($buildDir)) )
    then
    {    
        fn:trace("---", "--- Starting cmake ... ");
        variable $res := proc:exec("cd", ($buildDir, "&amp;&amp;", $cmakeCmd, ".."));

        if( fn:data($res/proc:exit-code) eq "0" )
        then
            fn:trace(fn:data($res/proc:stdout), fn:concat("  - cd ", $buildDir, 
            " &amp;&amp; cmake ..") );
        else
        {
            fn:trace($res, fn:concat("ERROR: cd ", $buildDir, " &amp;&amp; cmake .."));
            fn:error(xs:QName("local:ZPERF0007"), 
                fn:concat("Error cd ", $buildDir, 
                    " &amp;&amp; cmake ..: ", fn:data($res/proc:stderr)));
        }
    }
    else {}

    fn:trace("---", "--- Starting make ... ");
    variable $res := proc:exec("cd", ($buildDir, "&amp;&amp;", $makeCmd, "-j", 
        fn:string($makeThreads)));

    if( fn:data($res/proc:exit-code) eq "0" )
    then
        fn:trace(fn:data($res/proc:stdout), fn:concat("  - cd ", $buildDir, 
            " &amp;&amp; make") );
    else
    {
        fn:trace($res, fn:concat("ERROR: cd ", $buildDir, " &amp;&amp; make"));
        fn:error(xs:QName("local:ZPERF0008"), fn:concat("Error cd ", $buildDir, 
            " &amp;&amp; make : ", fn:data($res/proc:stderr)));
    }


    fn:trace("---", " - ls");
    $res := proc:exec("ls", ($buildDir));
    if( fn:data($res/proc:exit-code) eq "0" )
    then
        fn:trace(fn:data($res/proc:stdout), fn:concat("ls ", $buildDir) );
    else
    {
        fn:trace($res, fn:concat("ERROR: ls ", $buildDir));
        fn:error(xs:QName("local:ZPERF0009"), fn:concat("Error ls: ", 
            fn:data($res/proc:stderr)));
    }
};


declare %ann:sequential 
function local:runXMarkTestSuits($zorbaCmd as xs:string, $xmarkDir as xs:string, 
    $initialNoOfRuns as xs:int, $revision as xs:string, $revDate as xs:dateTime)
{   
    fn:trace("---", "--- Running xmark tests ... ");

    let $inputNames := ("f0.01-1MB.xml", "f0.1-11MB.xml", "f1-116MB.xml")
    let $inputTimes := (20, 3, 1)
    for $name at $pos in $inputNames
    return
    {
        variable $inputCtx as xs:string := fn:concat("input-context:=", $name);
        variable $noOfRuns := $inputTimes[$pos];
        
        <rez rev="{$revision}" revDate="{$revDate}">
            <pdash:suite id="{fn:concat("xmark-", $inputCtx, "-", 
                xs:string($noOfRuns), "x")}">
            {
                local:runXMarkTests($zorbaCmd, $xmarkDir, $noOfRuns, $inputCtx)
            }
            </pdash:suite>
        </rez>
    }
};


declare %ann:sequential 
function local:runXMarkTests($zorbaCmd as xs:string, $xmarkDir as xs:string, 
    $noOfRuns as xs:integer, $inputCtx as xs:string)
{   
    fn:trace("---", fn:concat(" -- xmark tests ", $noOfRuns, " ", $inputCtx));

    for $i in 1 to 20   (: for all q1.xq to q20.xq tests :)
    return
    {
        variable $testName := fn:concat("q", $i);
        variable $testFile := fn:concat($xmarkDir, file:directory-separator(), 
            "q", $i, ".xq");
        fn:trace($testFile, "test file");
        fn:trace( fn:concat($zorbaCmd, "-m", xs:string($noOfRuns), "-e", $inputCtx, 
            "-t", "-f", "-q", $testFile), "  - cmd: ");
        variable $res := proc:exec($zorbaCmd, ("-m", xs:string($noOfRuns), "-e", 
            $inputCtx, "-t", "-f", "-q", $testFile));
        
        if( fn:data($res/proc:exit-code) eq "0" )
        then
        {
            (: fn:trace(fn:data($res/proc:stdout), fn:concat("zorba ", $testFile)); :)
            variable $times := tims:substring-after-last( fn:data($res/proc:stdout),  
                                                          'Number of executions'); 
            fn:trace( $times, fn:concat("zorba ", $testFile));
            
            variable $t;
            try
            {
                $t := tims:parseTimings($times);
            }
            catch *
            {
                fn:trace("", fn:concat("  - Test ", $testName, 
                    " failed, skip submiting it: ", $err:code, "  ", 
                    $err:description ));

                exit returning 
                    <pdash:test id="{$testName}" iterations="{$noOfRuns}">
                      <pdash:measurements><pdash:error>1</pdash:error>
                      </pdash:measurements>
                      <error>
                      {   
                        fn:concat("  - Test ", $testName, " failed: erorcode=", 
                            $err:code, 
                            "  desc=", $err:description, " exit-code=", 
                            fn:data($res/proc:exit-code), 
                            " stdout=", fn:data($res/proc:stdout), " stderr=", 
                            fn:data($res/proc:stderr) )
                      }
                      </error>
                    </pdash:test>                        
                ;
            }
            
            fn:trace($t, fn:concat("--- Results for q", $i));
            
            <pdash:test id="{$testName}" iterations="{$noOfRuns}">
            {   
                $t, 
                <extra>{$inputCtx}</extra>
            }
            </pdash:test>
        }
        else
        {
            fn:trace($res, fn:concat("ERROR: zorba ", $testFile));
            fn:error(xs:QName("local:ZPERF0010"), fn:concat("Error zorba ", 
                $testFile, " : ", fn:data($res/proc:stderr)));

            exit returning 
                <pdash:test id="{$testName}" iterations="{$noOfRuns}">
                  <pdash:measurements><pdash:error>1</pdash:error></pdash:measurements>
                  <error>
                  {   
                    fn:concat("  - Test ", $testName, " failed: ", 
                        " exit-code=", fn:data($res/proc:exit-code), " stdout=", 
                        fn:data($res/proc:stdout), 
                        " stderr=", fn:data($res/proc:stderr) )
                  }
                  </error>
                </pdash:test>                        
            ;
        }
    }
};


declare %ann:sequential 
function local:publishResults($allResults, $platform, $buildName as xs:string)
{   
    fn:trace(fn:count($allResults), "--- Publish results ...");
    
    for $rez in $allResults
    return
    {
        variable $msg := local:makeMessage($rez/pdash:suite, $platform, 
            fn:data($rez/@rev), 
            fn:data($rez/@revDate), $buildName);
        
        local:submitMessage($msg);
    }
};


declare %ann:sequential 
function local:makeMessage($suite, $platform, $revision as xs:string, 
    $revDate as xs:string, $buildName as xs:string)
{   
    fn:trace("", "  - makeMessage");
    
    <pdash:submission build-id="{$buildName}" revision-number="{$revision}" 
                      date="{$revDate}" id="zorba-xmark-test1">
    {
        (   
            $platform,
            $suite
        )
    }
    </pdash:submission>
};


declare %ann:sequential 
function local:submitMessage($msg)
{   
    fn:trace(fn:serialize($msg), "  - submitMessage");
    
    variable $url:="http://pdash-zorba.my28msec.com/api/submissions";
    
    fn:trace(fn:serialize(
        http:send-request( 
          <http:request method="post" href="{$url}">
            <http:body media-type="application/xml">
              {$msg}
            </http:body>
          </http:request>)),
          "  - submitResponse")
};


declare %ann:sequential 
function local:runXRayTestSuits($zorbaCmd as xs:string, $xrayDir as xs:string, 
    $initialNoOfRuns as xs:int, $revision as xs:string, $revDate as xs:dateTime)
{   
    fn:trace("---", "--- Running xray tests ... ");

    variable $noOfRuns := $initialNoOfRuns;
        
    variable $resXRay := local:runXRayTests($zorbaCmd, $xrayDir, $noOfRuns);
    
    if ( fn:exists($resXRay) )
    then 
        <rez rev="{$revision}" revDate="{$revDate}">
            <pdash:suite id="{fn:concat('xray-320x240-', xs:string($noOfRuns), 'x')}">
            {
               $resXRay 
            }
            </pdash:suite>
        </rez>
    else
        ()
};


declare %ann:sequential function 
local:runXRayTests($zorbaCmd as xs:string, 
    $xrayDir as xs:string, $noOfRuns as xs:integer)
{   
    fn:trace("---", fn:concat(" -- xray test  ", $noOfRuns, "x"));

    variable $testFile := fn:concat($xrayDir, file:directory-separator(), "ppm_10.xq");
    fn:trace($testFile, "test file");
    
    variable $res := proc:exec($zorbaCmd, ("-m", xs:string($noOfRuns), 
        "-t", "-f", "-q", $testFile));
    fn:trace(fn:data($res/proc:exit-code), "  - xray execution exit-code - ");    
    variable $times := tims:substring-after-last( fn:data($res/proc:stdout),  
                                                  'Number of executions');

    if( fn:data($res/proc:exit-code) eq "0" )
    then
    {
        fn:trace($times, fn:concat("zorba ", $testFile));
        
        variable $t;
        try
        {
            $t := tims:parseTimings($times);
        }
        catch *
        {
            fn:trace("", fn:concat("  - Test xray failed, skip submiting it: ", 
                $err:code, "  ", $err:description ));
            
            exit returning 
                <pdash:test id="xray" iterations="{$noOfRuns}">
                  <pdash:measurements><pdash:error>1</pdash:error></pdash:measurements>
                  <error>
                  {   
                    fn:concat("  - Test xray failed, skip submiting it: erorcode=", 
                        $err:code, "  desc=", $err:description, 
                        " exit-code=", fn:data($res/proc:exit-code), " stdout=", 
                        fn:data($res/proc:stdout), " stderr=", 
                        fn:data($res/proc:stderr) )
                  }
                  </error>
                </pdash:test>                        
            ;
        }
        
        fn:trace($t, "--- Results for xray ");
        
        <pdash:test id="xray" iterations="{$noOfRuns}">
        {   
            $t
        }
        </pdash:test>
    }
    else
    {
        fn:trace($res, fn:concat("ERROR: zorba ", $testFile));
        fn:error(xs:QName("local:ZPERF0010"), fn:concat("Error zorba ", 
            $testFile, " : ", fn:data($res/proc:stderr)));

        exit returning 
            <pdash:test id="xray" iterations="{$noOfRuns}">
                <pdash:measurements><pdash:error>1</pdash:error></pdash:measurements>
                <error>
                {   
                    fn:concat("Error zorba ", $testFile, " : ",  
                    " exit-code=", fn:data($res/proc:exit-code), " stdout=", 
                    fn:data($res/proc:stdout), " stderr=", fn:data($res/proc:stderr) )
                }
                </error>
            </pdash:test>                        
        ;
    }
};


let $svnDir := "svndir"
let $buildDir := fn:concat($svnDir, file:directory-separator(),"build")
let $xmarkDir := "xmark"
                 (:fn:concat(
                     $svnDir, file:directory-separator(),
                    "test", file:directory-separator(), 
                    "rbkt", file:directory-separator(), 
                    "Queries", file:directory-separator(), 
                    "zorba", file:directory-separator(), 
                    "xmark"
                 ):) 
let $xrayDir := "xray"                    
let $svnCmd := "/usr/bin/svn"
let $cmakeCmd := "/usr/bin/cmake"
let $zorbaCmd := fn:concat($buildDir, file:directory-separator(),
                           "bin", file:directory-separator(), "zorba")
let $makeCmd := xs:string("/usr/bin/make") 
let $svnRevs := ("HEAD")

let $buildName := "santacruz"
let $initialNoOfRuns := xs:int(100)
let $platform := local:getPlatform()
return 
{
    fn:trace(fn:current-dateTime(), "----- Starting time");

    (:
    local:makeDir($svnDir);
    local:makeSvnDir($svnCmd, $svnDir, $svnRevs[1]);
    :)

    for $i in ($svnRevs)
    return
    {
        variable $revDate as xs:dateTime := fn:current-dateTime();
        
        (: 
        local:update($svnCmd, $svnDir, $i);
        :)
        local:build($buildDir, fn:false(), $cmakeCmd, $makeCmd, 
            $platform/@number-of-logical-cpu);
        

        variable $resXRay := local:runXRayTestSuits($zorbaCmd, $xrayDir, 
            xs:int(3), $i, $revDate);
        local:publishResults($resXRay, $platform, $buildName);


        variable $resXMark := local:runXMarkTestSuits($zorbaCmd, $xmarkDir, 
            $initialNoOfRuns, $i, $revDate);
        local:publishResults($resXMark, $platform, $buildName);         
        
    }
    
    fn:trace(fn:current-dateTime(), "----- Ending time");
    
    "Done."
}
