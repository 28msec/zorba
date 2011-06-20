(: XQuery main module :)

import module namespace file="http://expath.org/ns/file";
import module namespace proc="http://www.zorba-xquery.com/modules/process";
import module namespace tims="http://www.example.com/timings" at "timings.xq";

(:
import module namespace sys="http://www.zorba-xquery.com/modules/system";

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


declare %sequential function local:makeDir($svnCmd as xs:string, 
    $svnDir as xs:string, $svnRevs as xs:integer+)
{    
    if( fn:not( file:exists($svnDir) ) )
    then
    {
        file:create-directory($svnDir);
        fn:trace("", fn:concat("Using new ", $svnDir, " directory."));
    }
    else
        if ( fn:not( file:is-directory($svnDir) ) )
        then 
        {
            fn:trace("", fn:concat("Error: ", $svnDir, " is not a dir."));
            fn:error(xs:QName("local:ZPERF0001"), fn:concat("Error: ", $svnDir, " is not a dir."));
        }
        else fn:trace("", fn:concat("Found ", $svnDir, " director."));
};


declare %sequential function local:svnCo($svnCmd as xs:string, 
    $svnDir as xs:string, $svnRevs as xs:integer+)
{
    variable $svnCo := fn:concat($svnCmd, " co -r ", $svnRevs[1], 
        " http://zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba ", $svnDir);
    fn:trace($svnCo, "cmd");

    variable $svnCoResult := proc:exec($svnCmd, 
        ("co", "-r", xs:string($svnRevs[1]),
         "http://zorba.svn.sourceforge.net/svnroot/zorba/trunk/zorba", $svnDir));
                  
    if( $svnCoResult/exit-code eq "0")
    then 
        fn:trace( fn:data($svnCoResult/stdout), "svn co: ");
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
        fn:trace("", fn:concat("Assuming ", $svnDir, " is the Zorba svn checkout dir."));
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
    fn:trace("", fn:concat("svn update @rev", $svnRev)); 

    variable $svnUp := fn:concat($svnCmd, " up -r ", $svnRev, " ", $svnDir);
    fn:trace($svnUp, "cmd");

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
    

    fn:data($svnUpResult/exit-code)
};


declare %sequential function local:build($svnDir as xs:string, 
    $buildDir as xs:string, $clean as xs:boolean, $cmakeCmd as xs:string,
    $makeCmd as xs:string)
{
    fn:trace("", fn:concat("start build clean:", $clean));
    
    variable $buildDir := fn:concat($svnDir, file:directory-separator(),"build");

    if ($clean) 
    then
    {
        variable $res := proc:exec("rm", ("-fR", $buildDir));
        if( $res/exit-code eq "0" )
        then
            fn:trace("", fn:concat("rm -fR ", $buildDir) );
        else
        {
            fn:trace($res, fn:concat("ERROR: rm -fR ", $buildDir));
            fn:error(xs:QName("local:ZPERF0005"), fn:concat("Error rm -fR: ", fn:data($res/stderr)));
        }
    }
    else {}
    
    variable $res := proc:exec("mkdir", ($buildDir));
    if( $res/exit-code eq "0" )
    then
        fn:trace(fn:data($res/stdout), fn:concat("mkdir ", $buildDir) );
    else
    {
        fn:trace($res, fn:concat("ERROR: mkdir", $buildDir));
        fn:error(xs:QName("local:ZPERF0006"), fn:concat("Error mkdir: ", fn:data($res/stderr)));
    }

    fn:trace("---", "Starting cmake ... ");
    $res := proc:exec("cd", ($buildDir, "&amp;&amp;", $cmakeCmd, ".."));
    if( $res/exit-code eq "0" )
    then
        fn:trace(fn:data($res/stdout), fn:concat("cd ", $buildDir, " &amp;&amp; cmake ..") );
    else
    {
        fn:trace($res, fn:concat("ERROR: cd ", $buildDir, " &amp;&amp; cmake .."));
        fn:error(xs:QName("local:ZPERF0007"), fn:concat("Error cd ", $buildDir, " &amp;&amp; cmake ..: ", fn:data($res/stderr)));
    }

    fn:trace("---", "Starting make ... ");
    $res := proc:exec("cd", ($buildDir, "&amp;&amp;", $makeCmd));
    if( $res/exit-code eq "0" )
    then
        fn:trace(fn:data($res/stdout), fn:concat("cd ", $buildDir, " &amp;&amp; make") );
    else
    {
        fn:trace($res, fn:concat("ERROR: cd ", $buildDir, " &amp;&amp; make"));
        fn:error(xs:QName("local:ZPERF0008"), fn:concat("Error cd ", $buildDir, " &amp;&amp; make : ", fn:data($res/stderr)));
    }



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


declare %sequential function local:runTest($zorbaCmd as xs:string, $xmarkDir as xs:string, 
    $initialNoOfRuns as xs:int)
{   
    fn:trace("---", "Running xmark tests ... ");
    
    for $i in 1 to 20 
    return
    {
        variable $testFile := fn:concat($xmarkDir, file:directory-separator(), "q", $i, ".xq");
        fn:trace($testFile, "test file");
        
        variable $res := proc:exec($zorbaCmd, ("-m", xs:string($initialNoOfRuns), "-e", "input-context:=auction.xml", 
            "-t", "-f", "-q", $testFile));
        
        if( $res/exit-code eq "0" )
        then
        {
            fn:trace(fn:data($res/stdout), fn:concat("zorba ", $testFile));
            variable $t := tims:parseTimings(fn:data($res/stdout));
            fn:trace($t, fn:concat("--- Results for q", $i));
        }
        else
        {
            fn:trace($res, fn:concat("ERROR: zorba ", $testFile));
            fn:error(xs:QName("local:ZPERF0010"), fn:concat("Error zorba ", $testFile, " : ", fn:data($res/stderr)));
        }
    }
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
let $svnRevs := (8625, 8709, 8852, 9023, 9252, 9496, 9745, 9938, 10069, 
                 10237, 10431, 10742, 10766)
let $initialNoOfRuns := xs:int(3) 
return 
{
 
    local:makeDir($svnCmd, $svnDir, $svnRevs);
    local:makeSvnDir($svnCmd, $svnDir, $svnRevs);
    
    for $i in $svnRevs[1]
    return
    {
        local:update($svnCmd, $svnDir, $i);
        local:build($svnDir, $buildDir, fn:false(), $cmakeCmd, $makeCmd);
        local:runTest($zorbaCmd, $xmarkDir, $initialNoOfRuns);
        
        $i
    }

}

(:
let $s := '<?xml version="1.0" encoding="UTF-8"?>
Huei Demke<?xml version="1.0" encoding="UTF-8"?>
Huei Demke<?xml version="1.0" encoding="UTF-8"?>
Huei Demke
Number of executions = 3
Engine Startup Time     : 20 (user: 10.000) milliseconds
Average Compilation Time: 1 (user: 5.000) milliseconds
Average Execution Time  : 0 (user: 0.000) milliseconds
Average Loading Time    : 2 (user: 0.000) milliseconds
Average Unloading Time  : 0 (user: 0.000) milliseconds
Average Total Time      : 4 (user: 5.000) milliseconds

Engine Shutdown Time     : 4 (user: 0.000) milliseconds
'
let $res := tims:parseTimings($s)
let $r := (1.2, 1.3, 1.4)
return 
    $res
:)