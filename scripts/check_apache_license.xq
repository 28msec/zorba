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

import module namespace file = "http://expath.org/ns/file";
declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace notice = "http://www.zorba-xquery.com/notice";
declare namespace opt = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";

declare variable $path-to-zorba as xs:string external; (:PROJECT_SOURCE_DIR:)
declare variable $path-to-modules as xs:string external; (:ZORBA_MODULES_DIR:)

declare option opt:disable "f:trace";

declare %ann:nondeterministic function local:get-src-dirs() as xs:string*
{
  (: read the CMakeLists.txt from zorba and extract all :)
  
  let $cmakelists := file:read-text(fn:concat($path-to-zorba, "/CMakeLists.txt"))
  let $subdirs := fn:analyze-string($cmakelists, "ADD_SUBDIRECTORY\((.*?)\)")
  return  
    $subdirs/fn:match/fn:group[@nr eq 1]
};

declare %ann:nondeterministic function local:read-notice-file($dirname as xs:string) as xs:string*
{
  let $ftxt := fn:concat($dirname, "/NOTICE.xml")
  return
    if(file:is-file($ftxt)) then
      fn:doc($ftxt)/notice:notice/notice:foreign-files/notice:file
    else
      ()
};

declare function local:match-strings($s1 as xs:string, $slist as xs:string*) as xs:boolean
{
  if(fn:empty($slist)) then
    fn:false()
  else
    if(fn:matches($s1, $slist[1])) then 
      fn:true()
    else
      local:match-strings($s1, fn:tail($slist))
};

declare %ann:nondeterministic function local:check-dir( $reldir as xs:string,
                                                        $parent-path as xs:string, 
                                                        $excepted-files as xs:string*) as xs:string*
{
  (:iterate through dir, all files, recursively:)
  let $complete-dir := fn:concat($parent-path, "/", $reldir)
  for $file in file:list($complete-dir, fn:true())
  let $relpath := 
     if($reldir eq "") then
       fn:replace($file, "[/\\]", "/")
     else
       fn:replace(fn:concat($reldir, "/", $file), "[/\\]", "/")
  let $fullpath := fn:concat($complete-dir, "/", $file)
  return
    if(file:is-file($fullpath) and
       fn:matches($file, "\.cmake$|\.cpp$|\.h$|\.c$|\.tcc$|\.xq$|\.xqlib$|\.xqi$|\.in$|\.xsd$")  and
       fn:not(fn:matches($fullpath, "test/rbkt[/\\].*?[/\\]|test/update[/\\].*?[/\\]|test/parser[/\\].*?[/\\]|test/sax2[/\\].*?[/\\]|[/\\]Queries[/\\]|[/\\]ExpQueryResults[/\\]|\.spec\.in$|\.ini\.in$|doxy\.config\.in$"))) then
      let $filecontent := file:read-text($fullpath)
      return
        if(fn:not(local:match-strings($relpath, $excepted-files)) and
          fn:not(fn:matches($filecontent, "Licensed under the Apache License"))) then
          ($fullpath, 
          "
")
        else
          ()
    else
      ()
};

(
let $excepted-zorba-files := local:read-notice-file(fn:trace($path-to-zorba, "path to zorba"))
for $dir in local:get-src-dirs()
return
  local:check-dir($dir, $path-to-zorba, $excepted-zorba-files)
,
(: check all modules :)

for $module-dir in file:list(fn:trace($path-to-modules, "path to modules"), fn:false())
let $modulepath := fn:concat($path-to-modules, "/", $module-dir)
return
  if(fn:not($module-dir eq ".") and fn:not($module-dir eq "..") and file:is-directory($modulepath)) then
    (local:check-dir("", $modulepath, local:read-notice-file($modulepath)))
  else
    ()
)
