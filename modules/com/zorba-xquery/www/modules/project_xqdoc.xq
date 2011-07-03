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
 : Function library provides functions for generatring the XQDoc XML's for a project.
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

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
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
declare %nondeterministic %sequential function pxqdoc:delete-XML-dir(
  $xqdocPath as xs:string)
{
  variable $xqdocXMLPath  := fn:concat( $xqdocPath,
                                        file:directory-separator(),
                                        "xml");
  (: clear the XML folder :)
  if(file:exists($xqdocXMLPath)) then
    file:delete(fn:trace($xqdocXMLPath, " delete XML folder :"));
  else ();
};

(:~
 : This function generates the XQDoc XML for all the modules found in $modulesPath 
 : and writes the resulting XML documents in $xqdocXmlPath. 
 : The hierarchy is not preserved.
 :
 : @param $modulesPath where to search for modules recursively.
 : @param $xqdocPath where to generate the XQDoc XML documents.
 : @return empty sequence.
 :)
declare %nondeterministic %sequential function pxqdoc:generate-xqdoc-XML(
  $modulesPath as xs:string,
  $xqdocPath as xs:string,
  $isInsideZorbaCore as xs:boolean) as element()*
{
  variable $xqdocXMLPath  := fn:concat( $xqdocPath,
                                        file:directory-separator(),
                                        "xml");
                                        
  variable $xqdocXMLConfigPath  := fn:concat( $xqdocPath,
                                              file:directory-separator(),
                                              "config"); 
 
  (: create the XML folder if it does not exist already :)
  file:create-directory($xqdocXMLPath);
  
  (: create the XML config folder if it does not exist already :)
  file:create-directory($xqdocXMLConfigPath);
  
  (: make sure all the passed paths point to existing folders :)
  variable $lPaths := tokenize($modulesPath, ";");
  variable $lModulePaths as xs:string* := distinct-values(for $lPath in $lPaths return if (file:is-directory($lPath)) then $lPath else () );
  variable $src_dir as xs:string := fn:concat("/", "src");

  for $filedirs in $lModulePaths
  for $file in file:list($filedirs, fn:true(), "*.xq")
  return
  {
    if(fn:ends-with($file,"xxx.xq")) then
      ();
    else
    {        
      variable $filePath          := fn:concat($filedirs, file:directory-separator(), $file); 
      variable $xqdoc             := xqd:xqdoc(file:path-to-uri($filePath));
      variable $xqdocRelFileName  := pxqdoc:get-filename($xqdoc/xqdoc:module/xqdoc:uri);
      variable $xqdocFileName     := fn:concat( $xqdocXMLPath,
                                                file:directory-separator(),
                                                $xqdocRelFileName, 
                                                ".xml");
      variable $xqdocConfigFileName := fn:concat( $xqdocXMLConfigPath,
                                                  file:directory-separator(),
                                                  $xqdocRelFileName, 
                                                  ".xml"); 
      (: Write the XQDoc XML's :)
      file:write( trace($xqdocFileName," write XQDoc XML"),
                  $xqdoc, 
                  $pxqdoc:serParamXml);

      (: Write the additional information needed by the XQDoc generator:)                                                
      file:write( $xqdocConfigFileName, 
                  <module modulePath="{$filePath}" 
                          moduleURI="{$xqdoc/xqdoc:module/xqdoc:uri}"
                          examplePath="{fn:substring-before($filePath,$src_dir)}"
                          moduleRelLocation="{fn:substring-before($filePath,$src_dir)}"
                          isCore="{$isInsideZorbaCore}" />,
                  $pxqdoc:serParamXml);
      
    }
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