(: XQuery main module :)

import module namespace file="http://expath.org/ns/file";
import module namespace proc="http://www.zorba-xquery.com/modules/process";
import module namespace tims="http://www.example.com/timings" at "timings.xq";
import module namespace sys ="http://www.zorba-xquery.com/modules/system";
import module namespace http="http://expath.org/ns/http-client";


declare namespace pdash = "http://www.28msec.com/pdash";

(:
(
    sys:property($sys:os-name),
    sys:property($sys:os-node-name),
    sys:property($sys:os-version),
    sys:property($sys:os-version-build),
    sys:property($sys:os-version-major),
    sys:property($sys:os-version-minor),
    sys:property($sys:os-version-release),
    sys:property($sys:os-version-version),
    sys:property($sys:linux-distributor),
    sys:property($sys:linux-distributor-version),
    sys:property($sys:user-name),
    sys:property($sys:os-arch),
    sys:property($sys:zorba-module-path),
    sys:property($sys:zorba-version),
    sys:property($sys:zorba-version-major),
    sys:property($sys:zorba-version-minor),
    sys:property($sys:zorba-version-patch) 
)
:)

declare %sequential function local:getPlatform()
{    
    <pdash:platform site-osname="Ubuntu" os-version="11.04" os-platform="Linux" 
        hostname="28msec.dyndns.org" is-64bits="true" vendor-id="Cezar" vendor-label="i7" 
        number-of-logical-cpu="{xs:int(12)}" number-of-physical-cpu="1" 
        total-virtual-memory="6117504000" total-physical-memory="0" 
        number-of-logical-cpu-per-physical-cpu="12"/>
}; 


declare %sequential function local:makeDir($svnDir as xs:string)
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
            fn:error(xs:QName("local:ZPERF0001"), fn:concat("Error: ", $svnDir, " is not a dir."));
        }
        else fn:trace("", fn:concat("--- Found ", $svnDir, " directory."));
};


declare %sequential function local:svnCo($svnCmd as xs:string, 
    $svnDir as xs:string, $svnRev as xs:integer)
{
    variable $svnCo := fn:concat($svnCmd, " co -r ", $svnRev, 
        " http://zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba ", $svnDir);
    fn:trace($svnCo, "cmd");

    variable $svnCoResult := proc:exec($svnCmd, 
        ("co", "-r", xs:string($svnRev),
         "http://zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba", $svnDir));
                  
    if( $svnCoResult/exit-code eq "0")
    then 
        fn:trace( fn:data($svnCoResult/stdout), "--- svn co: ");
    else
    {
        fn:trace( fn:data($svnCoResult/stderr), "ERROR: ");
        fn:error(xs:QName("local:ZPERF0003"), fn:concat("Error svn co: ", fn:data($svnCoResult/stderr)));
    } 
    
    fn:data($svnCoResult/exit-code)
};


declare %sequential function local:makeSvnDir($svnCmd as xs:string, 
    $svnDir as xs:string, $svnRevs as xs:integer+)
{    
    if ( file:exists(fn:concat($svnDir, file:directory-separator(), "AUTHORS.txt")) and 
         file:exists(fn:concat($svnDir, file:directory-separator(), "src"))  )
    then
        fn:trace("", fn:concat("--- Assuming ", $svnDir, " is the Zorba svn checkout dir."));
    else
        if ( fn:empty(file:list($svnDir)) )
        then
            local:svnCo($svnCmd, $svnDir, $svnRevs);
        else
        {
            variable $msg := fn:concat("Error: ", $svnDir, " is not empty and it doesn't contain Zorba.");
            fn:error(xs:QName("local:ZPERF0002"), $msg);
        }
};


declare %sequential function local:update($svnCmd as xs:string, 
    $svnDir as xs:string, $svnRev as xs:integer)
{   
    fn:trace("", fn:concat("--- Svn update @rev", $svnRev)); 

    variable $svnUp := fn:concat($svnCmd, " up -r ", $svnRev, " ", $svnDir);
    fn:trace($svnUp, "  - svn up");

    variable $svnUpResult := proc:exec($svnCmd, 
        ("up", "-r", xs:string($svnRev), $svnDir));
                  
    if( $svnUpResult/exit-code eq "0")
    then 
        fn:trace( fn:data($svnUpResult/stdout), "svn up: ");
    else
    {
        fn:trace( fn:data($svnUpResult/stderr), "ERROR: "); 
        fn:trace( $svnUpResult, "svn up: ");
        fn:error(xs:QName("local:ZPERF0004"), fn:concat("Error svn up: ", fn:data($svnUpResult/stderr)));
    } 
    

    fn:trace("", "  - svn info");

    variable $svnInfoResult := proc:exec($svnCmd, 
        ("info", "--xml", $svnDir));
                  
    if( $svnInfoResult/exit-code eq "0")
    then 
    {
        fn:trace( fn:data($svnInfoResult/stdout), "svn info: ");
        
        (: need to find the revision date :)
        variable $strOut := fn:data($svnInfoResult/stdout);
        variable $doc := fn:parse-xml($strOut);
        
        xs:dateTime(fn:data($doc/info/entry/commit/date))
    }
    else
    {
        fn:trace( fn:data($svnInfoResult/stderr), "ERROR: "); 
        fn:trace( $svnInfoResult, "svn info: ");
        fn:error(xs:QName("local:ZPERF0004"), fn:concat("Error svn info: ", fn:data($svnInfoResult/stderr)));
    }
};


declare %sequential function local:build( $buildDir as xs:string, 
    $clean as xs:boolean, $cmakeCmd as xs:string,
    $makeCmd as xs:string, $makeThreads as xs:int)
{
    fn:trace("", fn:concat("--- Start build clean:", $clean));

    if ($clean) 
    then
    {
        variable $res := proc:exec("rm", ("-fR", $buildDir));
        if( $res/exit-code eq "0" )
        then
            fn:trace("", fn:concat("  - rm -fR ", $buildDir) );
        else
        {
            fn:trace($res, fn:concat("ERROR: rm -fR ", $buildDir));
            fn:error(xs:QName("local:ZPERF0005"), fn:concat("Error rm -fR: ", fn:data($res/stderr)));
        }
   
    }
    else {}
    
    if ( fn:not(file:exists($buildDir)) )
    then 
    {
        variable $res := proc:exec("mkdir", ($buildDir));
        if( $res/exit-code eq "0" )
        then
            fn:trace(fn:data($res/stdout), fn:concat("  - mkdir ", $buildDir) );
        else
        {
            fn:trace($res, fn:concat("ERROR: mkdir", $buildDir));
            fn:error(xs:QName("local:ZPERF0006"), fn:concat("Error mkdir: ", fn:data($res/stderr)));
        }
    }
    else {}

    if ( fn:empty(file:list($buildDir)) )
    then
    {    
        fn:trace("---", "--- Starting cmake ... ");
        variable $res := proc:exec("cd", ($buildDir, "&amp;&amp;", $cmakeCmd, ".."));
        if( $res/exit-code eq "0" )
        then
            fn:trace(fn:data($res/stdout), fn:concat("  - cd ", $buildDir, " &amp;&amp; cmake ..") );
        else
        {
            fn:trace($res, fn:concat("ERROR: cd ", $buildDir, " &amp;&amp; cmake .."));
            fn:error(xs:QName("local:ZPERF0007"), fn:concat("Error cd ", $buildDir, " &amp;&amp; cmake ..: ", fn:data($res/stderr)));
        }
    }
    else {}

    fn:trace("---", "--- Starting make ... ");
    variable $res := proc:exec("cd", ($buildDir, "&amp;&amp;", $makeCmd, "-j", fn:string($makeThreads)));
    if( $res/exit-code eq "0" )
    then
        fn:trace(fn:data($res/stdout), fn:concat("  - cd ", $buildDir, " &amp;&amp; make") );
    else
    {
        fn:trace($res, fn:concat("ERROR: cd ", $buildDir, " &amp;&amp; make"));
        fn:error(xs:QName("local:ZPERF0008"), fn:concat("Error cd ", $buildDir, " &amp;&amp; make : ", fn:data($res/stderr)));
    }


    fn:trace("---", " - ls");
    $res := proc:exec("ls", ($buildDir));
    if( $res/exit-code eq "0" )
    then
        fn:trace(fn:data($res/stdout), fn:concat("ls ", $buildDir) );
    else
    {
        fn:trace($res, fn:concat("ERROR: ls ", $buildDir));
        fn:error(xs:QName("local:ZPERF0009"), fn:concat("Error ls: ", fn:data($res/stderr)));
    }
};


declare %sequential function local:runAllTests($zorbaCmd as xs:string, $xmarkDir as xs:string, 
    $initialNoOfRuns as xs:int, $revision as xs:integer, $revDate as xs:dateTime, $inputCtx as xs:string)
{   
    <rez rev="{$revision}" revDate="{$revDate}">
        <pdash:suite id="{fn:concat("xmark-", $inputCtx, "-", $initialNoOfRuns, "x")}">
        {
            local:runTests($zorbaCmd, $xmarkDir, $initialNoOfRuns, $inputCtx)
        }
        </pdash:suite>
    </rez>
};
            

declare %sequential function local:runTests($zorbaCmd as xs:string, $xmarkDir as xs:string, 
    $initialNoOfRuns as xs:int, $inputCtx as xs:string)
{   
    fn:trace("---", "--- Running xmark tests ... ");
    
    for $i in 1 to 20 
    return
    {
        variable $testFile := fn:concat($xmarkDir, file:directory-separator(), "q", $i, ".xq");
        fn:trace($testFile, "test file");
        
        variable $res := proc:exec($zorbaCmd, ("-m", xs:string($initialNoOfRuns), "-e", $inputCtx, 
            "-t", "-f", "-q", $testFile));
        
        if( $res/exit-code eq "0" )
        then
        {
            fn:trace(fn:data($res/stdout), fn:concat("zorba ", $testFile));
            
            variable $t;
            try
            {
                $t := tims:parseTimings(fn:data($res/stdout));
            }
            catch * ($ecode, $desc)
            {
                fn:trace("", fn:concat("  - Test q", $i, " failed, skip submiting it: ", $ecode, "  ", $desc ));
                exit returning ();
            }
            
            fn:trace($t, fn:concat("--- Results for q", $i));
            
            <pdash:test id="{fn:concat("q", $i)}" iterations="{$initialNoOfRuns}">
            {   
                $t, 
                <extra>{$inputCtx}</extra>
            }
            </pdash:test>
        }
        else
        {
            fn:trace($res, fn:concat("ERROR: zorba ", $testFile));
            fn:error(xs:QName("local:ZPERF0010"), fn:concat("Error zorba ", $testFile, " : ", fn:data($res/stderr)));
        }
    }
};


declare %sequential function local:publishResults($allResults, $platform, $buildName as xs:string)
{   
    fn:trace(fn:count($allResults), "--- Publish results ...");
    
    for $rez in $allResults
    return
    {
        variable $msg := local:makeMessage($rez/pdash:suite, $platform, fn:data($rez/@rev), 
            fn:data($rez/@revDate), $buildName);
        
        local:submitMessage($msg);
    }
};


declare %sequential function local:makeMessage($suite, $platform, $revision as xs:string, 
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

declare %sequential function local:submitMessage($msg)
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



let $svnDir := "svndir"
let $buildDir := fn:concat($svnDir, file:directory-separator(),"build")
let $xmarkDir := fn:concat($svnDir, file:directory-separator(),
                    "test", file:directory-separator(), 
                    "rbkt", file:directory-separator(), 
                    "Queries", file:directory-separator(), 
                    "zorba", file:directory-separator(), 
                    "xmark"
                 )
let $svnCmd := "/usr/bin/svn"
let $cmakeCmd := "/usr/bin/cmake"
let $zorbaCmd := fn:concat($buildDir, file:directory-separator(),"bin", file:directory-separator(),"zorba")
let $makeCmd := xs:string("/usr/bin/make") 
let $svnRevs := (8625, 8709, 8852, 9023, 9252, 9496, 9745, 9938, 10069, 10237, 
                10431, 10742, 10766)
let $buildName := "zorba3"
let $initialNoOfRuns := xs:int(100)
let $inputCtx := "input-context:=auction.xml"     
let $platform := local:getPlatform()
return 
{
    fn:trace(fn:current-dateTime(), "----- Starting time");
    
    local:makeDir($svnDir);
    local:makeSvnDir($svnCmd, $svnDir, $svnRevs);
    
    for $i in ($svnRevs)
    return
    {
        variable $revDate as xs:dateTime := local:update($svnCmd, $svnDir, $i);
        local:build($buildDir, fn:false(), $cmakeCmd, $makeCmd, $platform/@number-of-logical-cpu);

        variable $res := local:runAllTests($zorbaCmd, $xmarkDir, $initialNoOfRuns, $i, $revDate, $inputCtx);
        local:publishResults($res, $platform, $buildName);        
    }    
    
    fn:trace(fn:current-dateTime(), "----- Ending time");
    
    "Done."
}
