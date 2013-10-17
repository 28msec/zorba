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

(:
 : author Sorin Nasoi
 :)

module namespace z = "http://www.zorba-xquery.com/module-dependencies";

declare namespace an = "http://zorba.io/annotations";
declare namespace zm = "http://zorba.io/manifest";

import module namespace file        = "http://expath.org/ns/file";
import module namespace functx      = "http://www.functx.com";

import module namespace dot   = "http://www.zorba-xquery.com/modules/image/graphviz";
import module namespace xqd   = "http://zorba.io/modules/xqdoc";
import module namespace fetch = "http://zorba.io/modules/fetch";
import module namespace dml   = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ddl   = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace menu  = "http://www.zorba-xquery.com/modules/xqdoc/menu";
import module namespace xqdoc-html  = "http://www.zorba-xquery.com/xqdoc-html" at "xqdoc-html.xqy";

declare namespace werr = "http://www.w3.org/2005/xqt-errors";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";

declare variable $z:nodesCollector := <modules/>;

declare variable $z:edgesCollector := <edges/>;

declare variable $z:typeModule          := 'module';
declare variable $z:typeExternalLibrary := 'library';
declare variable $z:typeSchema          := 'schema';

declare variable $z:colors      as xs:string* := ('red'       , 'green');
declare variable $z:moduleTypes as xs:string* := ('Zorba-core', 'External module');

(:~
 :  Collector for the Zorba manifest
 :)
declare %private variable $z:ZorbaManifest := <manifest/>;

declare %private variable $z:batchModules := <modules/>;

(:=========================================================================================================:)
declare variable $z:level1Weight as xs:string* := 
("JSONiq", "W3C", "FunctX", "EXPath", "DB Drivers",
 "Zorba");
 
declare variable $z:level1Colors as xs:string* :=
( "lime", "red", "tan", "OrangeRed", "LimeGreen",
  "lightsteelblue");

declare variable $z:collection as xs:QName := xs:QName("z:collection");
declare collection z:collection as node()*;

declare %an:nondeterministic function z:load-manifest(
  $zorbaManifestPath as xs:string) as document-node()?
{
  try 
  {
    fn:parse-xml(file:read-text($zorbaManifestPath)) 
  }
  catch *
  {
    fn:error(fn:concat("The file <",$zorbaManifestPath,"> does not have the correct structure."))
  }
};

declare %private function z:get-is-core(
  $moduleUri) as xs:boolean
{
  if(fn:string(data($z:ZorbaManifest/module[@uri= $moduleUri]/@isCore)) = "true") then fn:true()
  else fn:false()
};

declare %an:sequential function z:create-collections($ZorbaBuildFolder as xs:string)
{
  ddl:create($z:collection);

  variable $zorbaManifestPath := concat($ZorbaBuildFolder,
                                        file:directory-separator(),
                                        "ZorbaManifest.xml");

  variable $manifestXML := z:load-manifest($zorbaManifestPath);
  
  insert nodes xqdoc-html:modules($manifestXML)/*
  as last into $z:batchModules;
  
  variable $moduleManifests := $manifestXML/zm:manifest/zm:module;
  if(count($moduleManifests) eq xs:integer(0)) then ();
  else
  {
    try 
    {
      for $module in $moduleManifests
      let $moduleURI := data($module/zm:uri)
      let $moduleFetched := fetch:content($moduleURI, "MODULE")
      let $xqdoc := xqd:xqdoc-content($moduleFetched)
      return
      {
        insert node <module uri="{$moduleURI}"
                            isCore="{data($module/@isCore)}"/> as last into $z:ZorbaManifest;
        
        dml:apply-insert($z:collection, $xqdoc);
        
      }
    }
    catch *
    {
      fn:error(concat("Error processing module ",
                      $werr:code,
                      " - ",
                      $werr:description));
    }
  }
  
  z:fill-nodesCollector();
  
  z:fill_edgesCollector();
};

declare %an:sequential function z:delete-collections()
{ 
  dml:delete(dml:collection(xs:QName("z:collection")));
  ddl:delete(xs:QName("z:collection"));
};

declare %private function z:getModuleProject(
    $moduleUri as xs:string) as xs:string {
    
    for $docNode in dml:collection(xs:QName("z:collection"))
    let $lModuleUri := data($docNode/xqdoc:module/xqdoc:uri),
        $lModuleProject := $docNode/xqdoc:module/xqdoc:comment/xqdoc:custom[@tag="project"]/text(),
        $lTmp := substring-after($lModuleUri,'http://'),
        $lTmpTok := tokenize($lTmp,'/'),
        $lTmp2 := if(ends-with($lTmp,'/')) then substring($lTmp,1,string-length($lTmp)-1) else string-join(functx:value-except($lTmpTok,$lTmpTok[last()]),'/'),
        $lModuleName    := if(ends-with($lModuleUri,'/')) then $lTmpTok[last()-1] else $lTmpTok[last()],
        $structure      := if(exists($lModuleProject)) then $lModuleProject else $lTmp2
    where fn:string($lModuleUri) eq $moduleUri
    return $structure
};

(:~
 : Fill the $z:nodesCollector with all the available modules.
 :)
declare %an:sequential function z:fill-nodesCollector()
{
  for $docNode in dml:collection(xs:QName("z:collection"))
  let $lModuleUri := data($docNode/xqdoc:module/xqdoc:uri)
  let $structure := z:getModuleProject(fn:string($lModuleUri))
  return
    z:collect-node ($lModuleUri,
                    $structure,
                    fn:string(index-of(dml:collection(xs:QName("z:collection")), $docNode))
                    )
};

declare %private %an:sequential function z:collect-node (
  $moduleURI        as xs:string,
  $lModuleProject   as xs:string,
  $index            as xs:string)
{
  insert node <module uri="{$moduleURI}"
                      moduleProject="{$lModuleProject}"
                      index="{$index}" />
  as last into $z:nodesCollector;
};

declare %private function z:get_subgraphs() as xs:string*
{
    let $subgraphs as xs:string* := distinct-values(
                        for $module in $z:nodesCollector//module
                        return fn:string(data($module/@moduleProject))
                      )
    (: Order the subgraphs based on the Level1Weight :)
    return for $str in $z:level1Weight
           return
             for $tmp in $subgraphs
             where starts-with($tmp, $str)
             order by $tmp
             return $tmp
};


(:~
 : Fill $z:edgesCollector with all the edges (the links between the nodes) for both modules and eternal library dependencies.
 :)
declare %an:sequential function z:fill_edgesCollector()
{  
  for $xqdoc in dml:collection(xs:QName("z:collection"))
  return
    (
    (: add imported modules :)
    if (fn:count($xqdoc/xqdoc:imports//xqdoc:import[@type = "library"]) > 0) then
      for $import in $xqdoc/xqdoc:imports//xqdoc:import[@type = "library"]
      let $tmpTo := if(contains(string($import/xqdoc:uri/text()),"#"))
                    then substring-before(string($import/xqdoc:uri/text()),"#")
                    else string($import/xqdoc:uri/text())
      let $from := $z:nodesCollector//module[@uri=data($xqdoc/xqdoc:module/xqdoc:uri)]
      let $to := $z:nodesCollector//module[@uri=$tmpTo]
      return
        z:collect-edge(data($z:nodesCollector//module[@uri = data($xqdoc/xqdoc:module/xqdoc:uri)]/@catUri),
                       fn:string(data($from/@index)),
                       data($xqdoc/xqdoc:module/xqdoc:uri),
                       fn:string(data($to/@index)),
                       $tmpTo,
                       $z:typeModule)
    else
      (),
    (: add external c++ libraries dependencies :)
    
    if (fn:count($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:custom[@tag="library"]) > 0) then
      for $libraryDependency in $xqdoc/xqdoc:module/xqdoc:comment/xqdoc:custom[@tag="library"]
      let $from := $z:nodesCollector//module[@uri=data($xqdoc/xqdoc:module/xqdoc:uri)]
      let $to := $libraryDependency/*:a
      return
        z:collect-edge(fn:string(data($from/@moduleProject)),
                       fn:string(data($from/@index)),
                       fn:string(data($from/@uri)),
                       concat(fn:data($to),'|',data($to/@href) ),
                       "",
                       $z:typeExternalLibrary)
    else
      ())
};

declare %private %an:sequential function z:collect-edge (
  $catUri   as xs:string?,
  $nameFrom as xs:string?,
  $uriFrom  as xs:string?,
  $nameTo   as xs:string?,
  $uriTo    as xs:string?,
  $type     as xs:string?)
{
  insert node <edge catUri  ="{$catUri}"
                    nameFrom="{$nameFrom}"
                    uriFrom ="{$uriFrom}"
                    nameTo  ="{$nameTo}"
                    uriTo   ="{$uriTo}"
                    type    ="{$type}" />
  as last into $z:edgesCollector;
};

declare function z:test() as xs:string
{
(:
  string-join(
  for $edge in $z:edgesCollector//edge
  return fn:concat($edge/@catUri,"|", $edge/@nameFrom, "|",  $edge/@uriFrom, "|", $edge/@nameTo),"
")
 :)
 (:
  string-join(
  for $module in $z:nodesCollector//module
  return fn:concat($module/@uri,"|", $module/@moduleProject, "|", $module/@catUi),"
")
:)
};

(:~
 : This function returns the module type (see $z:moduleType)
 : based on the existance of the externals functions withing the module and also
 : it takes into account the imported modules.
 :)
declare function z:get_module_type($moduleUri as xs:string) as xs:integer
{
  if(z:get-is-core($moduleUri)) then xs:integer(1)
  else xs:integer(2)
};

declare %private function z:filename-from-uri($uri as xs:string) as xs:string
{
  let $tmp := substring-after($uri, "http://")
  let $tmp := replace($tmp, "/", "_")
  return concat($tmp, ".html")
};

(:~
 : Format the properties of a module dot shape (link to a file, tooltip, color of the text showing the module name).
 :)
declare function z:get_shape_properties( 
  $ModuleUri as xs:string,
  $lLabel as xs:string) as xs:string
{
  let $file as xs:string := z:filename-from-uri($ModuleUri)
  let $type := z:get_module_type($ModuleUri)
  return
    fn:concat('[URL="../',$file,'" tooltip="(',$z:moduleTypes[$type],') module uri=', $ModuleUri,'" label="',$lLabel,'" fontcolor="', $z:colors[$type] ,'"]')
};

(:~
 : Get the nodes that represent modules based on a provided category URI.
 :)
declare function z:nodes_modules(
  $category as xs:string) as xs:string
{
  let $nodes :=
  string-join(
  for $module in $z:nodesCollector//module
    let $lModuleUri := data($module/@uri)
    let $tok := tokenize($lModuleUri,"/")
    let $lLabel := if(ends-with($lModuleUri,'/')) then $tok[last()-1] else $tok[last()]
    let $lName := concat(data($module/@index),z:get_shape_properties($lModuleUri, $lLabel))
    where fn:string(data($module/@moduleProject)) = $category
    order by $lModuleUri
    return
      $lName,";
    ")
  return
    if($nodes eq '') then ''
    else concat($nodes,';')
    
};

(:~
 : Get the nodes that represent external library dependencies.
 :)
declare function z:nodes_external_libraries() as xs:string
{
  let $nodes :=
  string-join(
  for $edge in $z:edgesCollector//edge
  let $tok := tokenize(data($edge/@nameTo),'\|')
  let $nodeLabel := replace(replace(tokenize($tok[1],' ')[1],'\+',''),'-','')
  let $link := $tok[2]
  let $node := data($edge/@nameTo)
  let $lName := concat($nodeLabel,'[URL="',$link,'" tooltip="', $tok[1],'" label="',$nodeLabel,'"]')
  where data($edge/@type) eq $z:typeExternalLibrary
  group by $nodeLabel
    return
      $lName,";
    ")
  return
    if($nodes eq '') then ''
    else concat($nodes,';')
};

(:~
 : Get all the edges (the links between the nodes) between modules.
 :)
declare function z:edges_modules() as xs:string
{
let $edges :=
  string-join(
    for $edge in $z:edgesCollector//edge
    where data($edge/@type) eq $z:typeModule
    return concat('    ',$edge/@nameFrom,'->',$edge/@nameTo,'[tooltip="FROM: ',concat($edge/@uriFrom,', TO: ',$edge/@uriTo),'"]')
,';
')
return
  if($edges eq '') then ''
  else concat($edges,';')
};

(:~
 : Get all the edges (the links between the nodes) between modules and externall c++ libraries.
 :)
declare function z:edges_libraries() as xs:string
{
let $edges :=
  string-join(
    for $edge in $z:edgesCollector//edge
    let $tok := tokenize(data($edge/@nameTo),'\|')
    let $nodeLabel := replace(replace(tokenize($tok[1],' ')[1],'\+',''),"-","")
    where data($edge/@type) eq $z:typeExternalLibrary
    return concat('    ',$edge/@nameFrom,'->',$nodeLabel,'[tooltip="FROM: ', 
    concat($edge/@uriFrom,', TO: ',$nodeLabel) 
    ,'" color="red"]'),
  ';
')
return
  if($edges eq '') then ''
  else concat($edges,';')
};

(:~
 : Generate the cluster for the external c++ libraries.
 :)
declare function z:create_subgraph_libraries() as xs:string
{
  concat('
  
    subgraph clusterExternalCPPLibs  { style=filled; color=darksalmon; node [shape=box3d, color=red];
    ',
    z:nodes_external_libraries(),'

',
    z:edges_libraries(),'
    label="External C++ Library dependencies"; }')
};

(:~
 : Generate the cluster for a specific category.
 :)
declare function z:create_subgraph(
  $category   as xs:string,
  $subGraphs  as xs:string*,
  $level1     as xs:string*) as xs:string
{
  concat('
    subgraph cluster',
      index-of($level1, $category),
      ' { style=filled; color=',$z:level1Colors[index-of($level1,$category)],'; node [style="filled", color=white];
    ',
    z:create_subgraph-rec($category,
                          for $tmp in $subGraphs
                          where (starts-with($tmp, $category) and (contains($tmp,"/")))
                          return $tmp),'
    ',
z:nodes_modules($category),'
',
'    label="',$category,'"; tooltip="',$category,'"}')
};

declare %private function z:create_subgraph-rec(
  $category   as xs:string,
  $subGraphs  as xs:string*
  ) as xs:string
{
let $lSubGraphs := distinct-values( for $tmp in $subGraphs
                                    return tokenize(substring-after($tmp, concat($category,"/")),"/")[1]
                                    )
return
string-join(
for $sg in $lSubGraphs
let $newSg := concat($category,"/",$sg)
return
concat('
    subgraph cluster',
        translate($newSg," -./",""),'{ style=filled;
    ',
        z:create_subgraph-rec($newSg,
                          for $tmp in $subGraphs
                          where starts-with($tmp, $newSg)
                          return $tmp),'
    ',
z:nodes_modules($newSg),'
',
'    label="',$sg,'"; tooltip="',$newSg,'"}'),'
')
};

(:~
 : Generate the BIG cluster.
 :)
declare function z:create_graph() as xs:string
{
let $subgraphs := z:get_subgraphs()
let $l1 := distinct-values(for $str in $subgraphs return tokenize($str,'/')[1])
return
    concat('digraph G { penwidth=1; pencolor=black; label="Zorba modules dependency graph"; tooltip="Zorba modules dependency graph"
' ,
            string-join(
              for $cat1 in $l1
              return z:create_subgraph( $cat1, 
                                        for $val in $subgraphs
                                        where starts-with($val, $cat1)
                                        return $val,
                                        $l1
                                       )
              ,('
  ')), z:create_subgraph_libraries()
    ,"
  
",
  z:edges_modules(),"
  }"
  )
};
