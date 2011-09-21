import module namespace sys = 'http://www.zorba-xquery.com/modules/system';
import module namespace file = "http://expath.org/ns/file";

declare function local:do($path) {
  fn:concat(file:dir-name($path),"-",file:base-name($path))
};

if (sys:property($sys:os-name) eq "Windows") then
 let $path0 := "C:\a\b\abcd\\\"
 let $path1 := "c:/a/b/c////"
 let $path2 := "D:/a/b/c"
 let $path3 := "d:\a\b\c\\\\"
 let $path4 := "E:\a\b\c"
 let $path5 := "file:///e:/a/b/c////"
 let $path6 := "file:///F:/a/b/c"
 let $path7 := "f:////"
 let $path8 := "G:\\\\\"
 let $path9 := "g:"
 let $path10 := "H:\"
 let $path12 := "file:///I:/"
 let $path13 := "file:///i:///"
 return
 (
   file:base-name($path0, "cd") eq "ab" and 
   local:do($path1) eq "c:\a\b-c" and 
   local:do($path2) eq "D:\a\b-c" and 
   local:do($path3) eq "d:\a\b-c" and 
   local:do($path4) eq "E:\a\b-c" and 
   local:do($path5) eq "e:\a\b-c" and 
   local:do($path6) eq "F:\a\b-c" and 
   local:do($path7) eq "f:\-" and
   local:do($path8) eq "G:\-" and 
   local:do($path9) eq "g:\-" and 
   local:do($path10) eq "H:\-" and 
   local:do($path12) eq "I:\-" and
   local:do($path13) eq "i:\-"
 )
else
 let $path0 := "/a/b/abcd///"
 let $path1 := "/a/b/c////"
 let $path2 := "/a/b/c"
 let $path3 := "\a\b\c\\\\"
 let $path4 := "\a\b\c"
 let $path5 := "file:///a/b/c////"
 let $path6 := "file:///a/b/c"
 let $path7 := "////"
 let $path8 := "\\\\\"
 let $path9 := "/" 
 let $path10 := "file:///"
 return 
 (
   file:base-name($path0, "cd") eq "ab" and 
   local:do($path1) eq "/a/b-c" and 
   local:do($path2) eq "/a/b-c" and 
   local:do($path3) eq "/a/b-c" and 
   local:do($path4) eq "/a/b-c" and 
   local:do($path5) eq "/a/b-c" and 
   local:do($path6) eq "/a/b-c" and 
   local:do($path7) eq "/-"  and
   local:do($path8) eq "/-" and 
   local:do($path9) eq "/-" and 
   local:do($path10) eq "/-"
 )

