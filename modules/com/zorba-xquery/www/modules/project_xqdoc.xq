xquery version "3.0";

(:
 : Copyright 2006-2010 The FLWOR Foundation.
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
 : Function library provides functions for generating the XQDoc XML's for a project.
 :
 : @author Sorin Nasoi
 : @project xqdoc
 :)

module namespace pxqdoc  = "http://www.zorba-xquery.com/modules/project_xqdoc";

(:~ needed for generating the XML's :)
import module namespace xqd  = "http://www.zorba-xquery.com/modules/xqdoc";
(:~ needed for writing the XML's to disk:)
import module namespace file = "http://expath.org/ns/file";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";
import schema namespace output = "http://www.w3.org/2010/xslt-xquery-serialization";

declare namespace an = "http://www.zorba-xquery.com/annotations";
declare namespace zm = "http://www.zorba-xquery.com/manifest";
import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";

import module namespace err  = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/error";
declare namespace werr = "http://www.w3.org/2005/xqt-errors";
declare option ver:module-version "2.0";

(:~
 : The serialization parameters for XML serialization.
 :)
declare variable $pxqdoc:serParamXml :=
  <output:serialization-parameters>
    <output:method value="xml"/>
    <output:indent value="yes"/>
  </output:serialization-parameters>;

(:~
 : Delete the intermediary xml dir
 :
 : @param $xqdocPath where to generate the XQDoc XML documents.
 : @return empty sequence.
 :)
declare %an:sequential function pxqdoc:delete-XML-dir(
  $xqdocPath as xs:string) as empty-sequence()
{
  variable $xqdocXMLPath  := fn:concat( $xqdocPath,
                                        file:directory-separator(),
                                        "xml");
  (: clear the XML folder :)
  if(file:exists($xqdocXMLPath)) then
    file:delete($xqdocXMLPath);
  else ();
};

(:~
 : This function loads the ZorbaManifest.xml
 :
 : @param $zorbaManifestPath location of ZorbaManifest.xml.
 : @return the manifest.
 :)
declare %an:nondeterministic function pxqdoc:load-manifest(
  $zorbaManifestPath as xs:string) as document-node()?
{
  try 
  {
    fn:parse-xml(file:read-text($zorbaManifestPath)) 
  }
  catch *
  {
    fn:error($err:UE004,fn:concat("The file <",$zorbaManifestPath,"> does not have the correct structure."))
  }
};

(:~
 : This function generates the XQDoc XML for all the modules found in build/ZorbaManifest.xml
 :
 : @param $zorbaManifestPath location of ZorbaManifest.xml.
 : @param $xqdocPath where to generate the XQDoc XML documents.
 : @return empty sequence.
 :)
declare %an:sequential function pxqdoc:generate-xqdoc-XML(
  $zorbaManifestPath as xs:string,
  $xqdocPath as xs:string) as empty-sequence()
{
  (: Note: only the modules that are configured in the Zorba version you are using will be build :)                                      
  variable $xqdocXMLPath := concat($xqdocPath, file:directory-separator(), "xml");
  
  (: create the XML folder if it does not exist already :)
  file:create-directory($xqdocXMLPath);
      
  if(not(file:is-file($zorbaManifestPath))) then
  {
    variable $message := fn:concat("The file <ZorbaManifest.xml> was not found: <", $zorbaManifestPath, ">. Suggestion: run 'cmake' in your build folder such that ZorbaManifest.xml is regenerated.");
    fn:error($err:UE004, $message);
  }
  else  
  {
    variable $manifestXML := pxqdoc:load-manifest($zorbaManifestPath);
    variable $moduleManifests := $manifestXML/zm:manifest/zm:module;
    if(count($moduleManifests) eq xs:integer(0)) then ();
    else
    {
      try 
      {
      for $module in $moduleManifests
      (: note the module version is not supported because of a bug in the fetch for the module URI ending with / :)
      (:let $moduleURI := if(ends-with(data($module/zm:uri),'/')) then data($module/zm:uri) 
                       else if(exists($module/@version)) then concat(data($module/zm:uri),"#",data($module/@version))
                       else data($module/zm:uri):)
      (:let $moduleFetched := fetch:content(trace($moduleURI,"fetch module URI version.."), "MODULE"):)
      let $moduleURI := data($module/zm:uri)
      let $moduleFetched := fetch:content($moduleURI, "MODULE")
      let $moduleFetched := fn:replace($moduleFetched, '&amp;(nbsp|#160);' , codepoints-to-string(160))
      let $xqdoc := xqd:xqdoc-content($moduleFetched)
      let $xqdocRelFileName  := pxqdoc:get-filename($moduleURI)
      let $xqdocFileName := concat($xqdocXMLPath, file:directory-separator(), $xqdocRelFileName, ".xml")
      return
        file:write($xqdocFileName,
                   $xqdoc, 
                   $pxqdoc:serParamXml)
      }
      catch *
      {
        fn:error($err:UE004,
                 concat("Error processing module ",
                        $werr:code,
                        " - ",
                        $werr:description))
      }
    };
  }  
};

(:~ 
 : Returns the string resulting from replacing the directory-separators (i.e. / ) with '_'
 :
 : @param $moduleURI the path to the module URI.
 : @return the string resulting from replacing the directory-separators (i.e. / ) with '_'. 
 :
 :)
declare function pxqdoc:get-filename(
  $moduleURI as xs:string) as xs:string {
  let $lmodule := if(fn:ends-with($moduleURI,"/")) then fn:concat($moduleURI,"index") else $moduleURI
  return
    replace(
      replace($lmodule, "/", "_"),
      "http:__",
      ""
  )
};
